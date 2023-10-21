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

            AttackList.Load();
            PowerLevelList.Load();
            SurvivalDimensionList.Load();
            SurvivalWaveList.Load();
            SurvivalPowerLevelList.Load();
            CharacterManager.Singleton.Init();

            // Those can be loaded async, since they have no texture data
            int i = 0;
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
    class patch_AudioManager: AudioManager
    {
        private MemoryMappedFile mMapSFXBank;
        private MemoryMappedViewStream bankStream; // Losing the ref. to bankStream causes munmap??

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
                        MemoryMappedFileAccess.Read);

                    bankStream = mMapSFXBank.CreateViewStream(0, 0, MemoryMappedFileAccess.Read);
                    IntPtr basePtr = bankStream.SafeMemoryMappedViewHandle.DangerousGetHandle();
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
                                IntPtr sfxPtr = new IntPtr((Int64)basePtr + bankStream.Position);

                                // Keep a couple pages of audio resident on memory, for hot-starting.
                                // pinSfxPages((byte*)sfxPtr, sndSize);

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