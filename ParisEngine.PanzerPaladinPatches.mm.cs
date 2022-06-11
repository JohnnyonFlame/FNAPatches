using System;
using System.Diagnostics;
using System.Linq;
using System.Threading;
using MonoMod;
using Paris.Engine.Context;
using Paris.System.Helper;
using Paris.Engine.Graphics;

#pragma warning disable 1591
#pragma warning disable CS0649
#pragma warning disable CS0626

namespace Paris.System.Helper {
    static class patch_PathManager
    {
        public extern static string orig_NormalizePath(string path);
        public static string NormalizePath(string path)
        {
            // Normalize paths by replacing backslashes.
            // This fixes failures to find assets on Linux when Steam isn't running.
            return path.Replace("\\", "/");
        }
    }
}

namespace Paris.Engine {
    class patch_GameAnalytics : GameAnalytics
    {
        public extern void orig_Init();
        new public void Init()
        {
            // Disable GameAnalytics
        }
    }

    class patch_ParisContentManager: ParisContentManager
    {
        public patch_ParisContentManager(IServiceProvider i_service, string i_sRoot) : base(i_service, i_sRoot)
        {
        }

        // Can't call double-inherited base functions... so we need this to call the original ContentManager Load method
        [MonoModLinkTo("Microsoft.Xna.Framework.Content.ContentManager", "Load")]
        [MonoModForceCall]
        [MonoModRemove]
        public extern T ContentManager_Load<T>(string i_assetName);

        public extern T orig_Load<T>(string i_assetName);
        public override T Load<T>(string i_assetName)
		{
            bool isLockAcquired = false;
			T result;
			try
			{
                // We're changing how this lock works:
                // only the main thread can upload textures (see: ForceToMainThread in FNA3D_Driver_OpenGL.c), 
                // if we let the entire method lock, then we basically get deadlocked by the main thread, or starve it 
                // from this lock, since we'll be waiting for the main thread to consume the requests for texture uploads.
                // This change fixes deadlocks on preloading caused by using newer FNA builds.
				this.EnsureLock();
                isLockAcquired = true;
				string text = i_assetName.ToLower();
				if (typeof(T) == typeof(ReloadableTexture))
				{
					text += "Reloadable";
				}
				ParisContentManager.ObjectCacheItem objectCacheItem = null;
				if (!ContextManager.Singleton.Serializing && this.mloadedAssets.TryGetValue(text, out objectCacheItem))
				{
					T t = (T)((object)objectCacheItem.Obj);
					if (t != null)
					{
						return t;
					}
					this.mloadedAssets.TryRemove(text, out objectCacheItem);
				}
				Stopwatch stopwatch = Stopwatch.StartNew();
				i_assetName = PathManager.GetPlatformFilename(i_assetName);
				string text2 = i_assetName.Substring(i_assetName.LastIndexOf('\\') + 1);
				T t2 = default(T);
				if (!ContextManager.Singleton.Serializing)
				{
					objectCacheItem = new ParisContentManager.ObjectCacheItem();
					objectCacheItem.Name = text2;
					ParisContentManager.ObjectCacheItem objectCacheItem2 = this.mLoadingStack.LastOrDefault<ParisContentManager.ObjectCacheItem>();
					if (objectCacheItem2 != null)
					{
						objectCacheItem2.Children.Add(new WeakReference(objectCacheItem));
					}
					this.mLoadingStack.Add(objectCacheItem);
					objectCacheItem.Parent = new WeakReference(objectCacheItem2);
				}

                Monitor.Exit(ParisContentManager.mLock);
                isLockAcquired = false;

				if (t2 == null)
				{
					t2 = this.LoadFromDLC<T>(i_assetName);
				}
				if (t2 == null && typeof(T) == typeof(ReloadableTexture))
				{
					t2 = (T)((object)new ReloadableTexture(i_assetName));
				}
				if (t2 == null)
				{
					t2 = (T)((object)this.LoadParisBinary(i_assetName));
				}
				if (t2 == null)
				{
					t2 = this.LoadRawData<T>(i_assetName);
				}
				if (t2 == null)
				{
					t2 = (T)((object)this.LoadCompressedJson(i_assetName));
				}
				if (t2 == null)
				{
				    t2 = ContentManager_Load<T>(i_assetName);
				}

                this.EnsureLock();
                isLockAcquired = true;
				if (objectCacheItem != null && t2 != null && typeof(T) != typeof(GameMenu))
				{
					objectCacheItem.Obj = t2;
					objectCacheItem.Children = (
                        from x in objectCacheItem.Children
					    where x.IsAlive
					    select x).ToList<WeakReference>();
					this.mloadedAssets.TryAdd(text, objectCacheItem);
					objectCacheItem.Time = (double)stopwatch.ElapsedMilliseconds;
				}
				result = t2;
			}
			finally
			{
                if (isLockAcquired)
				    Monitor.Exit(ParisContentManager.mLock);
			}
			return result;
		}
    }
}

namespace Paris.Engine.Audio
{
    class patch_Song: Song
    {
        public patch_Song(string filename, string introFilename): base(filename, introFilename)
        {

        }

        private extern void orig_LoadMainSong();
        private void LoadMainSong()
        {
            // First call the original function
            orig_LoadMainSong();

            // Now let's make the decoded buffer size per request a bit more forgiving...
            // 1000.0ms is too much and causes periodic stuttering
            this.bufferSize = soundEffect.GetSampleSizeInBytes(TimeSpan.FromMilliseconds(66.4));
        }
    }
}