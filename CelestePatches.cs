using System;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using HarmonyLib;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using FMOD.Studio;
using Celeste;
using Monocle;

[assembly: IgnoresAccessChecksTo("Celeste")]
[assembly: IgnoresAccessChecksTo("Microsoft.Xna.Framework")]
[ModEntryPoint]
public static class CelestePatches
{
    public static bool distortEnabled = false;
    public static bool bloomEnabled = false;
    public static byte lightingPreset = 0;
    public static bool particlesEnabled = false;
    public static bool dustEdgesEnabled = false;
    public static byte gaussianBlurPreset = 0;

    public static int gfxPreset = 1;
    public static void Main()
    {
        Console.Out.WriteLine("Found CelestePatches, running...");
        try
        {
            new Harmony("com.github.johnnyonflame.CelestePatches").PatchAll(Assembly.GetExecutingAssembly());
        }
        catch (Exception e) 
        {
            Console.Out.WriteLine($"Failed: {e.ToString()}");
            throw e;
        }

        loadPreferences();
        Console.Out.WriteLine("Done.");
    }

    public static string GetCfgFilename()
    {
        return Path.Combine(UserIO.SavePath, "CelestePatches.dat");
    }

    public static void savePreferences()
    {
        using (FileStream fs = File.OpenWrite(GetCfgFilename()))
        {
            BinaryWriter wr = new BinaryWriter(fs);
            wr.Write(distortEnabled);
            wr.Write(bloomEnabled);
            wr.Write(lightingPreset);
            wr.Write(particlesEnabled);
            wr.Write(dustEdgesEnabled);
            wr.Write(gaussianBlurPreset);
            wr.Write(gfxPreset);
        }
    }

    public static void loadPreferences()
    {
        try
        {
            using (FileStream fs = File.OpenRead(GetCfgFilename()))
            {
                BinaryReader rd = new BinaryReader(fs);
                distortEnabled = rd.ReadBoolean();
                bloomEnabled = rd.ReadBoolean();
                lightingPreset = rd.ReadByte();
                particlesEnabled = rd.ReadBoolean();
                dustEdgesEnabled = rd.ReadBoolean();
                gaussianBlurPreset = rd.ReadByte();
                gfxPreset = rd.ReadInt32();
            }
        }
        catch (Exception e)
        {
            System.Console.WriteLine($"Unable to load mod config, {e.ToString()}");
        };
    }

    [HarmonyPatch(typeof(MenuOptions), nameof(MenuOptions.Create))]
    static class MenuOptions_Create
    {
        private static TextMenu.Option<int> gfxPresetItem;
        private static TextMenu.Option<bool> distortItem;
        private static TextMenu.Option<bool> bloomItem;
        private static TextMenu.Option<int> lightingItem;
        private static TextMenu.Option<bool> particlesItem;
        private static TextMenu.Option<bool> dustEdgesItem;
        private static TextMenu.Option<int> gaussianBlurItem;

        private static void setGfxPreset(int preset)
        {
            gfxPreset = preset;
            switch (gfxPreset) {
                case 0: //return "Custom";
                    break;
                case 1: //return "Very Low";
                    distortEnabled = false;
                    bloomEnabled = false;
                    lightingPreset = 0;
                    particlesEnabled = false;
                    dustEdgesEnabled = false;
                    gaussianBlurPreset = 0;
                    break;
                case 2: //return "Low";
                    distortEnabled = false;
                    bloomEnabled = false;
                    lightingPreset = 1;
                    particlesEnabled = true;
                    dustEdgesEnabled = false;
                    gaussianBlurPreset = 1;
                    break;
                case 3: //return "Normal";
                    distortEnabled = true;
                    bloomEnabled = true;
                    lightingPreset = 3;
                    particlesEnabled = true;
                    dustEdgesEnabled = true;
                    gaussianBlurPreset = 3;
                    break;
            }

            distortItem.Index = distortEnabled ? 1 : 0;
            bloomItem.Index = bloomEnabled ? 1 : 0;
            lightingItem.Index = lightingPreset;
            particlesItem.Index = particlesEnabled ? 1 : 0;
            dustEdgesItem.Index = dustEdgesEnabled ? 1 : 0;
            gaussianBlurItem.Index = gaussianBlurPreset;
            savePreferences();
        }

        public static void SetAndForceCustom<T>(ref T _out, T value)
        {
            _out = value;

            // Set preset to "Custom"
            gfxPreset = 0;
            gfxPresetItem.Index = 0;
            savePreferences();
        }

        public static void Postfix(bool inGame, EventInstance snapshot, ref TextMenu __result)
        {
            // Create a shallow list, then depopulate
            List<TextMenu.Item> kept = MenuOptions.menu.items.ToList();
            MenuOptions.menu.Clear();

            // We're ridding ourselves of the header, so recreate it
            MenuOptions.menu.Add(new TextMenu.Header(Dialog.Clean("options_title", null)));

            // Create our options first
            MenuOptions.menu.Add(new TextMenu.SubHeader("CelestePatches Options", true));
            MenuOptions.menu.Add(gfxPresetItem = new TextMenu.Slider("Graphics Preset", i => {
                switch (i) {
                    case 0: return "Custom";
                    case 1: return "Very Low";
                    case 2: return "Low";
                    case 3: return "Normal";
                    default: return "???";
                }
            }, 0, 3, gfxPreset).Change(i => { setGfxPreset(i); }));

            MenuOptions.menu.Add(distortItem   = new TextMenu.OnOff("Distort", distortEnabled).Change(i => { SetAndForceCustom(ref distortEnabled, i); }));
            MenuOptions.menu.Add(bloomItem     = new TextMenu.OnOff("Bloom", bloomEnabled).Change(i => { SetAndForceCustom(ref bloomEnabled, i); }));
            MenuOptions.menu.Add(lightingItem  = new TextMenu.Slider("Lighting", i => {
                switch (i) {
                    case 0: return "Off";
                    case 1: return "Very Low";
                    case 2: return "Low";
                    case 3: return "Normal";
                    default: return "???";
                };
            }, 0, 3, (int)lightingPreset).Change(i => { SetAndForceCustom(ref lightingPreset, (byte)i); }));
            MenuOptions.menu.Add(particlesItem = new TextMenu.OnOff("Particles", particlesEnabled).Change(i => { SetAndForceCustom(ref particlesEnabled, i); }));
            MenuOptions.menu.Add(dustEdgesItem = new TextMenu.OnOff("Dust Edges", dustEdgesEnabled).Change(i => { SetAndForceCustom(ref dustEdgesEnabled, i); }));
            MenuOptions.menu.Add(gaussianBlurItem = new TextMenu.Slider("Max. Gaussian Blur", i => {
                switch (i) {
                    case 0: return "Off";
                    case 1: return "3 Samples";
                    case 2: return "5 Samples";
                    case 3: return "9 Samples";
                    default: return "???";
                };
            }, 0, 3, (int)gaussianBlurPreset).Change(i => { SetAndForceCustom(ref gaussianBlurPreset, (byte)i); }));

            // Copy the previous items back
            foreach (var item in kept.Skip(1))
            {
                MenuOptions.menu.Add(item);
            }
        }
    }

    [HarmonyPatch(typeof(ParticleSystem), nameof(ParticleSystem.Simulate))]
    static class ParticleSystem_Simulate
    {
        public static bool Prefix(ref ParticleSystem __instance, float duration, float interval, Action<ParticleSystem> emitter)
        {
            return particlesEnabled;
        }
    }

    [HarmonyPatch(typeof(ParticleSystem), nameof(ParticleSystem.Render))]
    [HarmonyPatch(new Type[] { })]
    static class ParticleSystem_Render1
    {
        public static bool Prefix(ref ParticleSystem __instance)
        {
            return particlesEnabled;
        }
    }

    [HarmonyPatch(typeof(ParticleSystem), nameof(ParticleSystem.Render))]
    [HarmonyPatch(new Type[] { typeof(float) })]
    static class ParticleSystem_Render2
    {
        public static bool Prefix(ref ParticleSystem __instance, float alpha)
        {
            return particlesEnabled;
        }
    }

    [HarmonyPatch(typeof(ParticleSystem), nameof(ParticleSystem.Update))]
    static class ParticleSystem_Update
    {
        public static bool Prefix(ref ParticleSystem __instance)
        {
            return particlesEnabled;
        }
    }

    [HarmonyPatch(typeof(LightingRenderer), nameof(LightingRenderer.BeforeRender))]
    static class LightingRenderer_BeforeRender
    {
        public static bool Prefix(ref LightingRenderer __instance, Scene scene)
        {
            return lightingPreset > 0;
        }

        public static void ApplyBlurPreset()
        {
            // Off: This isn't called
            // Very Low Preset: No blur
            // Low Preset: 3 samples
            // Normal Preset: 9 samples

            switch (lightingPreset)
            {
            case 3:
                GaussianBlur.Blur(GameplayBuffers.Light, GameplayBuffers.TempA, GameplayBuffers.Light, 0f, true, GaussianBlur.Samples.Nine, 1f, GaussianBlur.Direction.Both, 1f);
                break;
            case 2:
                GaussianBlur.Blur(GameplayBuffers.Light, GameplayBuffers.TempA, GameplayBuffers.Light, 0f, true, GaussianBlur.Samples.Three, 1f, GaussianBlur.Direction.Both, 1f);
                break;
            }
        }

        static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
        {
            var codes = new List<CodeInstruction>(instructions);
            for (int i = 0; i < codes.Count; i++)
            {
                if (codes[i].opcode == OpCodes.Call &&
                    codes[i].operand.ToString().Contains(
                    "Microsoft.Xna.Framework.Graphics.Texture2D Blur(Microsoft.Xna.Framework.Graphics.Texture2D, Monocle.VirtualRenderTarget, Monocle.VirtualRenderTarget, Single, Boolean, Samples, Single, Direction, Single)"))
                {
                    for (int j = 0; j < 11; j++)
                        codes[i-j].opcode = OpCodes.Nop;
                    codes[i+1].opcode = OpCodes.Nop;
                    codes[i-10].opcode = OpCodes.Call;
                    codes[i-10].operand = AccessTools.Method(typeof(LightingRenderer_BeforeRender), "ApplyBlurPreset", new Type[] {  });
                    break;
                }
            }

            return codes.AsEnumerable();
        }
    }

    [HarmonyPatch(typeof(LightingRenderer), nameof(LightingRenderer.Render))]
    static class LightingRenderer_Render
    {
        public static bool Prefix(ref LightingRenderer __instance, Scene scene)
        {
            return lightingPreset > 0;
        }
    }

    [HarmonyPatch(typeof(LightingRenderer), nameof(LightingRenderer.Update))]
    static class LightingRenderer_Update
    {
        public static bool Prefix(ref LightingRenderer __instance, Scene scene)
        {
            __instance.Visible = lightingPreset > 0;
            return lightingPreset > 0;
        }
    }

    [HarmonyPatch(typeof(BloomRenderer), nameof(BloomRenderer.Apply))]
    static class BloomRenderer_Apply
    {
        public static bool Prefix(ref BloomRenderer __instance, VirtualRenderTarget target, Scene scene)
        {
            return bloomEnabled;
        }
    }

    [HarmonyPatch(typeof(Distort), nameof(Distort.Render))]
    static class Distort_Render
    {
        public static bool Prefix(Texture2D source, Texture2D map, bool hasDistortion)
        {
            if (!distortEnabled) {
                Draw.SpriteBatch.Begin(SpriteSortMode.Deferred, BlendState.AlphaBlend, SamplerState.PointClamp, DepthStencilState.Default, RasterizerState.CullNone, null);
                Draw.SpriteBatch.Draw(source, Vector2.Zero, Color.White);
                Draw.SpriteBatch.End();
            }

            return distortEnabled;
        }
    }

    [HarmonyPatch(typeof(DustEdges), nameof(DustEdges.BeforeRender))]
    static class DustEdges_BeforeRender
    {
        public static bool Prefix(ref DustEdges __instance)
        {
            return dustEdgesEnabled;
        }
    }

    [HarmonyPatch(typeof(DustEdges), nameof(LightingRenderer.Render))]
    static class DustEdges_Render
    {
        public static bool Prefix(ref DustEdges __instance)
        {
            return dustEdgesEnabled;
        }
    }

    [HarmonyPatch(typeof(DustEdges), nameof(DustEdges.Update))]
    static class DustEdges_Update
    {
        public static bool Prefix(ref DustEdges __instance)
        {
            __instance.Visible = dustEdgesEnabled;
            return dustEdgesEnabled;
        }
    }

    [HarmonyPatch(typeof(GaussianBlur), nameof(GaussianBlur.Blur))]
    static class GaussianBlur_Blur
    {
        public static bool Prefix(Texture2D texture, VirtualRenderTarget temp, VirtualRenderTarget output, float fade, bool clear,
            ref GaussianBlur.Samples samples, float sampleScale, GaussianBlur.Direction direction, float alpha, ref Texture2D __result)
        {
            samples = (GaussianBlur.Samples)Math.Min((int)gaussianBlurPreset - 1, (int)samples);
            if (samples < 0)
            {
                __result = texture;
                return false;
            }

            return true;
        }
    }

    [HarmonyPatch(typeof(VirtualTexture), nameof(VirtualTexture.Reload))]
    static class VirtualTexture_Reload
    {
        static bool Prefix(ref VirtualTexture __instance)
        {
            string ext = System.IO.Path.GetExtension(__instance.Path);
            if (ext == ".data")
            {
                string astcEncodedFile = System.IO.Path.ChangeExtension(__instance.Path, ".astc");
                string astcEncodedFilePath = System.IO.Path.Combine(Engine.ContentDirectory, astcEncodedFile);

                if (System.IO.File.Exists(astcEncodedFilePath))
                {
                    // usual flow won't be called, so we need to unload here.
                    __instance.Unload();

                    using (FileStream stream = File.OpenRead(astcEncodedFilePath))
                    {
                        byte[] astc_header = new byte[16];
                        stream.Read(astc_header, 0, 16);

                        int block_x = astc_header[4];
                        int block_y = astc_header[5];
                        int width = astc_header[7] | astc_header[8] << 8 | astc_header[9] << 16;
                        int height = astc_header[10] | astc_header[11] << 8 | astc_header[12] << 16;

                        int bytes = (((width + block_x - 1) / block_x) * ((height + block_y - 1) / block_y)) * 16;
                        if (stream.Read(VirtualTexture.buffer, 0, bytes) != bytes)
                        {
                            System.Console.WriteLine($"Unexpected end of ASTC stream.");
                        }

                        System.Console.WriteLine($"ASTC image \"{astcEncodedFile}\", {width}x{height} total bytes {bytes}...");
                        __instance.Texture = new Texture2D(Engine.Graphics.GraphicsDevice, width, height, false, SurfaceFormat.Astc4x4EXT);
                        __instance.Texture.SetData<byte>(VirtualTexture.buffer, 0, bytes);

                        __instance.Texture.Width = width;
                        __instance.Texture.Height = height;
                        __instance.Width = width;
                        __instance.Height = height;

                        // Texturee successfully loaded, don't alllow the usual execution flow to proceed.
                        return false;
                    }
                }
            }

            // Fall-through to the usual execution flow to proceed.
            return true;
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

