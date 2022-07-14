using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;
using MonoMod;
using Paris.Engine.Context;
using Paris.Engine.Data;
using Paris.Engine.Graphics;
using Paris.Engine.Scene;
using Paris.Engine.System;
using Paris.Engine;
using Paris.System.Helper;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO.MemoryMappedFiles;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Threading;
using System;

#pragma warning disable 1591
#pragma warning disable CS0649
#pragma warning disable CS0626

namespace Paris.Engine.Save
{
    public class patch_SaveSystem: SaveSystem
    {
        public static string GetModConfigPath()
        {
            SaveSystemBase saveBase = SaveSystemBase.Singleton;
            return Path.Combine(SaveSystem.GetOSPath(), "Tribute Games", "TMNT", "ModSettings.dat");
        }
    }
}

namespace Paris.System.Context
{
    public class patch_ContextManager: ContextManager
    {
        patch_ContextManager(Microsoft.Xna.Framework.Game game): base(game) { }
        new public virtual void Init()
		{
			Vector2 gameResolution = EngineSettings.Singleton.GameResolution;
			ContextManager._postRenderTarget = new RenderTarget2D(
                Renderer.Singleton.GraphicsDevice,
                (int)gameResolution.X,
                (int)gameResolution.Y,
                false,
                SurfaceFormat.Color,
                DepthFormat.Depth16,
                0,
                RenderTargetUsage.DiscardContents);
			ContextManager._displayRenderTarget = new RenderTarget2D(
                Renderer.Singleton.GraphicsDevice,
                (int)gameResolution.X,
                (int)gameResolution.Y,
                false,
                SurfaceFormat.Color,
                DepthFormat.None,
                0,
                RenderTargetUsage.DiscardContents);
			ContextManager._contextRenderViewport = new Viewport(0, 0, (int)gameResolution.X, (int)gameResolution.Y);
			ContextManager._contextRenderProjection = Matrix.CreateOrthographicOffCenter(0f, gameResolution.X, gameResolution.Y, 0f, 0f, 1f) * Matrix.CreateScale(1f, 1f, -1f);
			this._loadingState = ContextManager.LoadingState.FadeOut;
			this._savingIconHUD = this.LoadContent<GameMenu>("Menu\\Project\\SavingHUD");
			this._savingIconHUD.Init();
			this._savingIconHUD.Reset();
			this._loadingAnimation.SetPosition(gameResolution / 2f);
			this._loadingAnimation.Visible = false;
			this._shouldRenderLoading = false;
			this._loadingAnimType = ContextManager.LoadingAnimType.Normal;
			this._popup = new Popup();
			this._popup.Init();
			this._popup.Reset();
		}
    }
}

namespace Paris.System.Helper
{
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

namespace Paris.Engine.System.Networking
{
    // Fix story mode crash in earlier versions
    class patch_NetworkManager: NetworkManager
    {
        public extern virtual void orig_Disconnect(bool transition = false);
        new public virtual void Disconnect(bool transition = false)
        {
            try
            {
                orig_Disconnect(transition);
            }
            catch (Exception){ }
        }
    }
}

namespace Paris.Engine {
    public class patch_ParisEngine: ParisEngine
    {
        public patch_ParisEngine() { }
        public static Thread frameworkDispatchWorker { get; private set; } = null;
#if false
        static double elapsedAccum = 0.0f;
        static int elapsedCounter = 0;
        const int bufferFrames = 15;
#endif
        public static void frameworkUpdateWork()
        {
            while (true)
            {
                FrameworkDispatcher.Update();
                Thread.Sleep(16);
            }
        }

        new void Update(GameTime gameTime)
		{
			lock (this.updateableComponents)
			{
				for (int i = 0; i < this.updateableComponents.Count; i++)
				{
					this.currentlyUpdatingComponents.Add(this.updateableComponents[i]);
				}
			}

			foreach (IUpdateable updateable in this.currentlyUpdatingComponents)
			{
				if (updateable.Enabled)
				{
					updateable.Update(gameTime);
				}
			}

            // Big ugly.
            if (frameworkDispatchWorker == null)
            {
                frameworkDispatchWorker = new Thread(frameworkUpdateWork);
                frameworkDispatchWorker.Start();
            }

			this.currentlyUpdatingComponents.Clear();
#if false
            elapsedAccum += gameTime.ElapsedGameTime.TotalSeconds;
            elapsedCounter += 1;
            if (elapsedCounter % bufferFrames == 0)
            {
                double deltaTimeAvg = (elapsedAccum * 1000.0f) / (float)bufferFrames;
                Console.Out.WriteLine($"{deltaTimeAvg}ms {1000.0f / deltaTimeAvg}fps");
                elapsedAccum = 0.0f;
            }
#endif
			base.IsFixedTimeStep = !Renderer.Singleton.VSync;
		}
    }

    public class patch_Stat: Stat
    {
        patch_Stat(string id, StatType type): base(id, type) { }

        // Fix story mode crash in earlier versions
        extern private bool orig_StoreSteam();
        private bool StoreSteam()
        {
            return false;
        }
    }

    class patch_GameAnalytics: GameAnalytics
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
                        // Lock is released by the 'finally' block.
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

                // See this.EnsureLock() notes
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

                // See this.EnsureLock() notes
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
                // See this.EnsureLock() notes
                if (isLockAcquired)
                    Monitor.Exit(ParisContentManager.mLock);
            }
            return result;
        }
    }
}

namespace Paris.Engine.Graphics.Playfield
{
    class patch_GameObjectLayer: GameObjectLayer
    {
        [MonoModLinkTo("Microsoft.Xna.Framework.Content.ContentManager", "Load")]
        [MonoModForceCall]
        [MonoModRemove]
        public extern T ContentManager_Load<T>(string i_assetName);

        static private Type patch_Options_t;
        static private FieldInfo info;

        new public void Render(float startPriority, float endPriority, Vector2 layerPosRatio)
		{
            if (patch_Options_t == null)
            {
                patch_Options_t = Type.GetType("Paris.Game.Menu.Options, TMNT", true);
                info = patch_Options_t.GetField("shadowPreset", BindingFlags.Static | BindingFlags.Public);
            }

            int shadowPreset = (int)info.GetValue(null);

			//base.Render(startPriority, endPriority, layerPosRatio);
			this._translucentObjectsToRender.Clear();
			bool editorMode = ContextManager.Singleton.EditorMode;
			if ((!ContextManager.Singleton.EditorMode || !base.Hidden) && !ContextManager.Singleton.Serializing)
			{
				Renderer singleton = Renderer.Singleton;
				Vector2 position2D = Scene2d.Active.CurrentCamera.Position2D;
				Scene2d active = Scene2d.Active;
				bool is3D = active.Is3D;
				this._objectsToRender.Clear();
				for (int i = 0; i < this.GameObject2dList.Count; i++)
				{
					GameObject2d gameObject = this.GameObject2dList[i].GameObject;
					if (gameObject.Active && gameObject.Initialized && this.ShouldRenderGameObject(gameObject, active, startPriority, endPriority))
					{
						this._objectsToRender.Add(gameObject);
					}
				}
				EngineSettings singleton2 = EngineSettings.Singleton;
				float num = is3D ? Renderer.Singleton.PriorityManager.GetRenderPriority(singleton2.ShadowPriority) : 1f;
				if (is3D)
				{
					foreach (GameObject2d gameObject2d in this._objectsToRender)
					{
						if (gameObject2d.GetRenderPriority() >= num)
						{
							if (gameObject2d.IsTranslucent)
							{
								this._translucentObjectsToRender.Add(gameObject2d);
							}
							else
							{
								gameObject2d.Render();
							}
						}
					}
					if (!editorMode && this._shadowRenderTarget != null && this.ShadowsEnabled && shadowPreset >= 1)
					{
                        Color clearColor = singleton.ClearColor;
                        if (shadowPreset >= 2)
                        {
						    singleton.ClearColor = Color.Transparent;
						    singleton.Push(true, singleton.CurrentPos, singleton.CurrentViewport, singleton.CurrentScale, singleton.CurrentDepthEnabled, this._shadowRenderTarget, new Matrix?(singleton.CurrentProjection), null);
                        }
						foreach (GameObject2d gameObject2d2 in this._objectsToRender)
						{
							gameObject2d2.RenderShadow();
						}
                        if (shadowPreset >= 2)
                        {
                            singleton.Pop();
                            singleton.ClearColor = clearColor;
                            Renderer.Singleton.DrawTexture(this._shadowRenderTarget, Vector2.Zero, Vector2.Zero, position2D, Vector2.Zero, Color.White.WithAlpha(singleton2.ShadowOpacity), num);
                        }
                    }
					foreach (GameObject2d gameObject2d3 in this._objectsToRender)
					{
						if (editorMode || this._shadowRenderTarget == null)
						{
							gameObject2d3.RenderShadow();
						}
						gameObject2d3.RenderFlat();
					}
				}
				foreach (GameObject2d gameObject2d4 in this._objectsToRender)
				{
					if (!is3D || gameObject2d4.GetRenderPriority() < num)
					{
						if (gameObject2d4.IsTranslucent)
						{
							this._translucentObjectsToRender.Add(gameObject2d4);
						}
						else
						{
							gameObject2d4.Render();
						}
					}
				}
				foreach (GameObject2d gameObject2d5 in this._translucentObjectsToRender)
				{
					gameObject2d5.Render();
				}
			}
		}
    }
}

namespace Paris.Engine.Audio
{
    class patch_AudioManager: AudioManager
    {
        private MemoryMappedFile mMapSFXBank;

        // Keep a few resident memory pages per sound effect for hot starting...
        [MethodImpl(MethodImplOptions.NoOptimization | MethodImplOptions.NoInlining)]
        private static unsafe void pinSfxPages(byte *ptr, int size)
        {
            long nPages = Math.Max(1, 32768 / Environment.SystemPageSize);
            long curPtr = (Int64)ptr;
            long limit = ((Int64)ptr + size);

            for (int i = 0; i < nPages; i++)
            {
                if (curPtr >= limit)
                    break;
                
                byte *xored = (byte*)curPtr;
                *xored ^= 0x33;
                *xored ^= 0x33;
                curPtr += Environment.SystemPageSize;
            }
        }

        // This patch implements Memory Mapped SFX support, SFXPack.pbn is a 300mb file that gets loaded in it's entirety
        // to ram, this patch allows said file to remain resident in virtual memory as a memory mapped file, but not take
        // so much physical memory. 
        new unsafe public virtual void Init()
        {
            // Just standard AudioManager.Init()...
            if (!this._initialized && !AudioManager.NoSound)
            {
                SoundSettings soundSettings = ContextManager.Singleton.LoadContent<SoundSettings>(EngineSettings.Singleton.SoundsSettings, true, false);
                float num = soundSettings.Settings.MasterVolume / 100f;
                this._masterMusicVolume = num * (soundSettings.Settings.MasterMusicVolume / 100f);
                this._masterSFXVolume = num * (soundSettings.Settings.MasterSoundVolume / 100f);
                this.CurrentMusicName = "";
                foreach (SoundSettings.SoundChannel soundChannel in soundSettings.Channels)
                {
                    this._soundChannels.Add(new SFXChannel(soundChannel.Name, soundChannel.MaxSounds, soundChannel.Volume, soundChannel.PlayType));
                }
                string path = string.Empty;
                if (ParisContentManager.RawDataMode)
                {
                    path = Path.Combine(ContextManager.Singleton.GlobalContentManager.RootDirectory, "Audio", "SFXPack.pbn");
                }
                else
                {
                    path = ContextManager.Singleton.GlobalContentManager.GetFilePath(Path.Combine("Audio", "SFXPack")) + ".pbn";
                }
                if (File.Exists(path) && !this.EditorMode)
                {
                    // Here's where we differ, we're going to Memory Map the SFX Bank instead of
                    // straight up loading it and keeping it always resident on physical ram.
                    // This is 300mb+ of RAM we're not wasting for the price of possibly running
                    // into pagefaults every now and then.
                    // Still better than swap, by a mile. This helps save the game from stuttering
                    // limbo on memory starved devices. (e.g. 1GByte shared ram)
                    mMapSFXBank = MemoryMappedFile.CreateFromFile(
                        path,
                        FileMode.Open,
                        Path.Combine("Audio", "SFXPack"),
                        0,
                        MemoryMappedFileAccess.CopyOnWrite);

                    MemoryMappedViewStream bankStream = mMapSFXBank.CreateViewStream();
                    BinaryReader bankReader = new BinaryReader(bankStream);
                    for (int i = 0; i < soundSettings.Sounds.Count; i++)
                    {
                        SoundSettings.SoundInfo soundInfo = soundSettings.Sounds[i];
                        try
                        {
                            int sndSize = bankReader.ReadInt32();
                            if (sndSize < 0)
                                throw new Exception("sndSize < 0");
                            
                            // Use the simplified constructor so we can poke directly at the fields and instanciate
                            // a memory mapped version instead.
                            SFX sfx = new SFX(soundInfo.SoundID, soundInfo.Cooldown);
                            Console.Out.WriteLine($"Instanciating \"{soundInfo.SoundID}\" SFX ({sndSize} bytes)");

                            List<SFXChannel> list = (
                                from channelName in soundInfo.PlaybackChannels
                                from sfxChannel  in this._soundChannels where sfxChannel.Name == channelName
                                select sfxChannel
                                ).ToList();

                            /* 
                                Replacement for SFX..ctor "public SFX(string assetName, byte[] data, float volume,
                                    int poolSize, SoundLoopType loopType, SFXChannel[] channels, SoundCutOffType cutOffType, 
                                    Range randomPitch, bool isVO, float cooldown) : this(assetName, cooldown)"

                                We're doing this instead of providing an extended version for simplicity's sake.
                            */

                            try
                            {
                                // Get pointer to sound effect from the bankStream, can't use bankStream.PositionPointer
                                // since that causes a runtime error.
                                byte *basePtr = null;
                                mMapSFXBank.CreateViewAccessor().SafeMemoryMappedViewHandle.AcquirePointer(ref basePtr);
                                IntPtr sfxPtr = new IntPtr((Int64)basePtr + bankStream.Position);

                                // Keep a couple pages of audio resident on memory, for hot-starting.
                                pinSfxPages((byte*)sfxPtr, sndSize);

                                // Requires FNA SoundEffect..ctor IntPtr extensions
                                sfx._soundEffect = new SoundEffect(sfxPtr, false, sndSize, 48000, AudioChannels.Stereo);
                            }
                            catch (Exception ex)
                            {
                                Console.Out.WriteLine($"Failed to load {soundInfo.SoundID}, {ex.ToString()}");
                                sfx._soundEffect = null;
                            }
                            
                            // Standard SFX constructor affair...
                            var randomPitch = new Types.Range(soundInfo.PitchMin, soundInfo.PitchMax);
                            sfx._playVolume = soundInfo.Volume / 100f;
                            sfx.IsVO = soundInfo.IsVO;
                            int numLoop = (soundInfo.LoopType == SoundLoopType.NoLoop) ? soundInfo.PoolSize : 1;
                            sfx._soundEffectInstance = new SoundEffectInstance[numLoop];

                            for (int j = 0; j < numLoop; j++)
                            {
                                if (sfx._soundEffect != null)
                                {
                                    sfx._soundEffectInstance[j] = sfx._soundEffect.CreateInstance();
                                    sfx._soundEffectInstance[j].IsLooped = (soundInfo.LoopType > SoundLoopType.NoLoop);
                                }
                            }

                            sfx._channels = list.ToArray();
                            sfx._cutOffType = soundInfo.CutOffType;
                            sfx._loopType = soundInfo.LoopType;
                            if (randomPitch.Min != 0f || randomPitch.Max != 0f)
                            {
                                sfx._pitch = new Types.Range?(randomPitch);
                            }
                            sfx.Volume = 1f;

                            /* SFX..ctor Replacement done */
                            bankStream.Seek(sndSize, SeekOrigin.Current);
                            this._sounds.Add(sfx);
                        }
                        catch (Exception ex)
                        {
                            Console.Out.WriteLine("Invalid data being read in SFXPack using list of sounds from SoundsSettings; SoundsSettings & SFXPack are out of sync! Error message: " + ex.ToString());
                            this._sounds.Clear();
                            break;
                        }
                    }
                }
                if (this._voiceChat != null)
                {
                    this._voiceChat.Play();
                }
                for (int k = 0; k < this._voiceBuffer.Length; k++)
                {
                    this._voiceBuffer[k] = 0;
                }
                for (int l = 0; l < EngineSettings.Singleton.MaxPlayers; l++)
                {
                    this._voicePlayerMuted[l] = false;
                }
                this._initialized = true;
            }
        }
    }
}
