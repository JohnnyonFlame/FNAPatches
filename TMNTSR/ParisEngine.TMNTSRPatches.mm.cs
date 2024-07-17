using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;
using MonoMod;
using Paris.Engine.Graphics.Animations;
using Paris.Engine.Context;
using Paris.Engine.Data;
using Paris.Engine.Graphics;
using Paris.Engine.Scene;
using Paris.Engine.System;
using Paris.Engine;
using Paris.System.Helper;
using Paris.Game.System;
using Paris.Game.System.Progression;
using Paris.Engine.System.Helper;
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

namespace Paris.Engine.System.AssetPacks
{
    // Fix issues with Alt VO fails to be applied on Linux when using the Windows builds
    public class patch_AssetPack : AssetPack
    {
        private void PopulateReplacementCache()
        {
            this._contentPathCache.Clear();
            string sfxFolder = Path.Combine(this.SourcePath, "Audio\\SFX\\");
            sfxFolder = sfxFolder.Replace("/", "\\");
            foreach (AssetPackItem assetPackItem in this.Items)
            {
                string originalPath = assetPackItem.OriginalPath;
                string replacementPath = assetPackItem.ReplacementPath;
                this._contentPathCache[originalPath] = replacementPath;
                if (originalPath.StartsWith("Audio\\SFX\\"))
                {
                    string originalSfxPath = originalPath.Remove(0, "Audio\\SFX\\".Length);
                    string replacementSfxPath = replacementPath;
                    if (replacementPath.StartsWith("Audio\\SFX\\"))
                    {
                        replacementSfxPath = replacementPath.Remove(0, "Audio\\SFX\\".Length);
                    }
                    else if (replacementPath.StartsWith(sfxFolder))
                    {
                        replacementSfxPath = replacementPath.Remove(0, sfxFolder.Length);
                    }
                    this._sfxPathCache[originalSfxPath] = replacementSfxPath;
                }
            }
        }
    }
}

namespace Paris.Engine.Context
{
    public class patch_ContextManager: ContextManager
    {
        patch_ContextManager(Microsoft.Xna.Framework.Game game): base(game) { }

        // Due to issues with loading assets async, we will be loading quite a few of these in the main thread,
        // otherwise, we _will_ cause deadlocks.
        new public void StartPreLoadingGlobalAssets()
        {
            if (EditorMode || _preloadingState != 0)
            {
                return;
            }

            // Those can be loaded async, since they have no texture data
            Action[] array = new Action[4] { PreloadAudio, CacheJsonFiles, CacheReflectionInfo, PreloadPoolObjects };
            foreach (Action action in array)
            {
                Thread thread = new Thread(action.Invoke);
                thread.Priority = ThreadPriority.BelowNormal;
                thread.IsBackground = true;
                thread.Name = string.Format("Preload : {0}", action.Method.Name);
                mGlobalLoadingThreads.Add(thread);
                thread.Start();
            }

            // These resources contain texture data, we need to load them synchronously
            AttackList.Load();
            PowerLevelList.Load();
            SurvivalDimensionList.Load();
            SurvivalWaveList.Load();
            SurvivalPowerLevelList.Load();
            CharacterManager.Singleton.Init();

            // This has to be loaded by the main thread.
            LoadGlobalContent();

            // These might have texture data, so they have to be loaded by the
            // main thread. 
            foreach (Type loadableType in Assembly.GetCallingAssembly().GetLoadableTypes())
            {
                if (typeof(IPreloadable).IsAssignableFrom(loadableType))
                {
                    IPreloadable parameter = (IPreloadable)Activator.CreateInstance(loadableType);
                    PreloadCustom(parameter);
                }
            }

            _preloadingState |= PreloadingState.CustomPreloaders;
        }
    }
}

namespace Paris.Engine.System.Networking
{
    // Fix story mode crashes
    class patch_NetworkManager: NetworkManager
    {
        public extern virtual void orig_Disconnect(bool transition = false);
        new public virtual void Disconnect(bool transition = false)
        {
            // try
            // {
            //     orig_Disconnect(transition);
            // }
            // catch (Exception){ }
        }

        public extern virtual void orig_ChangeLobbyLocked(bool isLocked);
        new public virtual void ChangeLobbyLocked(bool isLocked)
        {
            // try
            // {
            //     orig_ChangeLobbyLocked(isLocked);
            // }
            // catch (Exception){ }
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
}

namespace Paris.Engine.Audio
{
    public class MMappedSFXBank {
        public string assetPath;
        public MemoryMappedFile mmapFile;
        public MemoryMappedViewStream mvStream;
        public IntPtr basePtr;

        public MMappedSFXBank(string assetPath)
        {
            this.assetPath = assetPath;
            mmapFile = MemoryMappedFile.CreateFromFile(assetPath, FileMode.Open, assetPath, 0, MemoryMappedFileAccess.Read);
            mvStream = mmapFile.CreateViewStream(0, 0, MemoryMappedFileAccess.Read);
            basePtr = mvStream.SafeMemoryMappedViewHandle.DangerousGetHandle();
        }

        public void RewindStream()
        {
            mvStream.Seek(0, SeekOrigin.Begin);
        }
    };

    class patch_AudioManager: AudioManager
    {
        public static List<MMappedSFXBank> loadedBanks = new List<MMappedSFXBank>{};

                            /* 
                                Replacement for SFX..ctor "public SFX(string assetName, byte[] data, float volume,
                                    int poolSize, SoundLoopType loopType, SFXChannel[] channels, SoundCutOffType cutOffType, 
                                    Range randomPitch, bool isVO, float cooldown) : this(assetName, cooldown)"
        */
        public static SFX SFXFromIntPtr(string assetName, IntPtr data, int length, float volume, int poolSize, SoundLoopType loopType, SFXChannel[] channels, SoundCutOffType cutOffType, Types.Range randomPitch, bool isVO, float cooldown)
        {
            SFX sfx = new SFX(assetName, cooldown);
            sfx._soundEffectInstance = new SoundEffectInstance[poolSize];
			try
			{
				sfx._soundEffect = new SoundEffect(data, false, length, 48000, AudioChannels.Stereo);
                            }
			catch (Exception)
                            {
                                sfx._soundEffect = null;
                            }
			sfx._playVolume = volume;
			sfx.IsVO = isVO;
			int finalPoolSize = (loopType == SoundLoopType.NoLoop) ? poolSize : 1;
			for (int i = 0; i < finalPoolSize; i++)
                            {
                                if (sfx._soundEffect != null)
                                {
					sfx._soundEffectInstance[i] = sfx._soundEffect.CreateInstance();
					sfx._soundEffectInstance[i].IsLooped = (loopType > SoundLoopType.NoLoop);
                                }
                            }
			sfx._channels = channels;
			sfx._cutOffType = cutOffType;
			sfx._loopType = loopType;
                            if (randomPitch.Min != 0f || randomPitch.Max != 0f)
                            {
                                sfx._pitch = new Types.Range?(randomPitch);
                            }
                            sfx.Volume = 1f;
            return sfx;
        }

        /*
          This patch implements Memory Mapped SFX support, SFXPack.pbn is a 300mb file that gets loaded
          in it's entirety to ram, this patch allows said file to remain resident in virtual memory as a
          memory mapped file, while not taking as much physical memory. 
        */
        new unsafe public void LoadSFXPack(List<SFX> sounds, string packPath, AssetPackEnableFlags flags)
        {
            try
            {
                // Memory map the Voice Bank or reuse an already mapped one
                MMappedSFXBank bank = loadedBanks.Find(b => b.assetPath == packPath);
                if (bank == null)
                {
                    bank = new MMappedSFXBank(packPath);
                    loadedBanks.Add(bank);
                }
                else
                {
                    bank.RewindStream();
                }
    
                BinaryReader bankReader = new BinaryReader(bank.mvStream);

                foreach (SoundSettings.SoundInfo soundInfo in this._settings.Sounds)
                {
                    int sndSize = bankReader.ReadInt32();
                    if (sndSize < 0)
                        throw new Exception("sndSize < 0");

                    if (sndSize > 0)
                    {
                        // We'd usually read the entire sound effect into memory, here we just take the offset
                        // then we move the reading head forwards.
                        long offset = bank.mvStream.Position;
                        bank.mvStream.Seek(sndSize, SeekOrigin.Current);

                        IEnumerable<SFXChannel> channels = (
                            from channelName in soundInfo.PlaybackChannels
                            from sfxChannel  in this._soundChannels
                            where sfxChannel.Name == channelName
                            select sfxChannel
                        );

                        if ((((flags & AssetPackEnableFlags.Voice) != (AssetPackEnableFlags)0) || !soundInfo.IsVO) &&
                            (((flags & AssetPackEnableFlags.Sound) != (AssetPackEnableFlags)0) ||  soundInfo.IsVO))
                        {
                            IntPtr sfxPtr = new IntPtr((Int64)bank.basePtr + offset);
                            sounds.Add(SFXFromIntPtr(
                                soundInfo.SoundID,
                                sfxPtr,
                                sndSize,
                                soundInfo.Volume / 100f,
                                soundInfo.PoolSize,
                                soundInfo.LoopType,
                                Enumerable.ToArray(channels),
                                soundInfo.CutOffType,
                                new Types.Range(soundInfo.PitchMin, soundInfo.PitchMax),
                                soundInfo.IsVO,
                                soundInfo.Cooldown));
                        }
                    }
                }
            }
                        catch (Exception ex)
                        {
                            Console.Out.WriteLine("Invalid data being read in SFXPack using list of sounds from SoundsSettings; SoundsSettings & SFXPack are out of sync! Error message: " + ex.ToString());
                sounds.Clear();
            }
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

// We don't have Steam present, and we want to be sure users aren't freeloading
// on DLCs they did not purchase, we'll have to perform some silly heuristics
// to check.
namespace Paris.Engine.System.DLC
{
    public class patch_DLCInfo: DLCInfo {
        public bool CheckOwnsShellshock()
        {
            // Having the "Aftermath" animation is a good smell to sniff out the
            // Shellshock DLC ownership status.
            try {
                ContextManager.Singleton.LoadContent<AnimatedObject2dData>("2d\\Animations\\BG\\Survival\\Aftermath\\Aftermath", true);
                State = LockState.Unlocked;
                return true;
            } catch (Exception) { }

            return false;
        }

        public patch_DLCInfo(int id) : base(id) {
            
        }

        public extern void orig_SetAppID(uint appid);
        new public void SetAppID(uint appid)
        {
            // AppID = new AppId_t(appid);
            orig_SetAppID(appid);
            switch (appid) {
                case 2348930: //Shellshock
                    Console.Out.WriteLine($"Owns {appid}? {CheckOwnsShellshock()}");
                    break;
                default:
                    Console.Out.WriteLine($"Unknown DLC {appid}");
                    break;
            }
        }

        new public bool IsInstalled() {
            CheckOwnsShellshock();
            return State == LockState.Unlocked;
        }

        new public void UpdateState()
        {
            CheckOwnsShellshock();
        }
    };
}