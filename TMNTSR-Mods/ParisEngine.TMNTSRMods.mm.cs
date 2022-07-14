using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework;
using Mono.Cecil;
using MonoMod.InlineRT;
using Paris.Engine.Context;
using Paris.Engine.Data;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System;

#pragma warning disable 1591
#pragma warning disable CS0649
#pragma warning disable CS0626

namespace MonoMod
{
    public static class MonoModRules
    {
        static MonoModRules()
        {
            // Forcefully disable the access checks by creating the following:
            // [assembly: IgnoresAccessChecksTo("ParisEngine")]
            // [assembly: IgnoresAccessChecksTo("TMNT")]
            // [assembly: IgnoresAccessChecksTo("FNA")]

            CustomAttribute attribute;
            var mod = MonoModRule.Modder.Module;
            var ctor = typeof(IgnoresAccessChecksToAttribute).GetConstructor(new Type[] { typeof(string) });
            var attribConstructor = mod.ImportReference(ctor);

            attribute = new CustomAttribute(attribConstructor);
            attribute.ConstructorArguments.Add(new CustomAttributeArgument(mod.ImportReference(typeof(string)), (object)"ParisEngine"));
            mod.Assembly.CustomAttributes.Add(attribute);

            attribute = new CustomAttribute(attribConstructor);
            attribute.ConstructorArguments.Add(new CustomAttributeArgument(mod.ImportReference(typeof(string)), (object)"TMNT"));
            mod.Assembly.CustomAttributes.Add(attribute);

            attribute = new CustomAttribute(attribConstructor);
            attribute.ConstructorArguments.Add(new CustomAttributeArgument(mod.ImportReference(typeof(string)), (object)"FNA"));
            mod.Assembly.CustomAttributes.Add(attribute);
        }
    }
}

namespace TMNTMods
{
    static class Mods
    {
        private static string[] _SearchPath = null;
        public static string[] SearchPath {
            get { 
                if (_SearchPath == null)
                {
                    string searchPathEnv = Environment.GetEnvironmentVariable("MONOMOD_MODS");
                    if (searchPathEnv != null)
                        _SearchPath = searchPathEnv.Split(new char [] { Path.PathSeparator });
                    else
                    {
                        string searchPathGlob = Path.Combine(new string[] { TitleLocation.Path, "Mods" }); 
                        _SearchPath = Directory.GetDirectories(searchPathGlob, "*");
                    }
                }

                return _SearchPath;
            }
            set { _SearchPath = value; }
        }
    }
}

namespace Paris.Engine
{
    class patch_ParisContentManager: ParisContentManager
    {
        patch_ParisContentManager(IServiceProvider i_service, string i_sRoot) : base(i_service, i_sRoot) { }
        public extern T orig_Load<T>(string i_assetName);
        public override T Load<T>(string i_assetName)
        {
            foreach (var path in TMNTMods.Mods.SearchPath)
            {
                try
                {
                    return orig_Load<T>(Path.Combine(new string[] { path, i_assetName }));
                }
                catch (Exception) { }
            }

            return orig_Load<T>(i_assetName);
        }
    }
}

namespace Paris.Engine.Audio
{
    class patch_AudioManager: AudioManager
    {
        new unsafe public virtual void Init()
        {
            // Just standard AudioManager.Init()...
            if (this._initialized || AudioManager.NoSound)
                return;

            this._initialized = true;

            // Load metadata...
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
                using (FileStream bankStream = File.OpenRead(path))
                using (BinaryReader bankReader = new BinaryReader(bankStream))
                {
                    for (int i = 0; i < soundSettings.Sounds.Count; i++)
                    {
                        SoundSettings.SoundInfo soundInfo = soundSettings.Sounds[i];
                        Console.Out.WriteLine($"Loading Tim Allen for {soundInfo.SoundID}");
                        try
                        {
                            int sndSize = bankReader.ReadInt32();
                            if (sndSize < 0)
                                throw new Exception("sndSize < 0");
                            
                            var list =
                                from channelName in soundInfo.PlaybackChannels
                                from sfxChannel  in this._soundChannels where sfxChannel.Name == channelName
                                select sfxChannel;

                            byte[] data = null;
                            foreach (string searchPath in TMNTMods.Mods.SearchPath)
                            {
                                string wavPath = Path.Combine(new string[] { searchPath, "Audio", soundInfo.SoundID} ) + ".wav";
                                if (File.Exists(wavPath))
                                {
                                    data = File.ReadAllBytes(wavPath);
                                    bankStream.Seek(sndSize, SeekOrigin.Current);
                                }
                            }

                            if (data == null)
                                data = bankReader.ReadBytes(sndSize);

                            this._sounds.Add(new SFX(
                                soundInfo.SoundID,
                                data,
                                soundInfo.Volume / 100f,
                                soundInfo.PoolSize,
                                soundInfo.LoopType,
                                Enumerable.ToArray<SFXChannel>(list),
                                soundInfo.CutOffType,
                                new Types.Range(soundInfo.PitchMin, soundInfo.PitchMax),
                                soundInfo.IsVO,
                                soundInfo.Cooldown));
                        }
                        catch (Exception ex)
                        {
                            this._sounds.Clear();
                            throw new Exception(ex.ToString());
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

namespace System.Runtime.CompilerServices
{
    [AttributeUsage(AttributeTargets.Assembly, AllowMultiple = true)]
    public class IgnoresAccessChecksToAttribute : Attribute
    {
        public IgnoresAccessChecksToAttribute(string assemblyName)
        {
            AssemblyName = assemblyName;
        }

        public string AssemblyName { get; }
    }
}