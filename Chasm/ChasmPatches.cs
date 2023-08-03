using System;
using System.Linq;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.Reflection;
using System.Reflection.Emit;
using HarmonyLib;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Chasm;
using Chasm.Platforms;
using Chasm.Menus;


[assembly: IgnoresAccessChecksTo("Chasm")]
[assembly: IgnoresAccessChecksTo("Microsoft.Xna.Framework")]
[ModEntryPoint]
public static class ChasmPatches
{
    public static void Main()
    {
        Console.Out.WriteLine("Found ChasmPatches, running...");
        try
        {
            new Harmony("com.github.johnnyonflame.ChasmPatches").PatchAll(Assembly.GetExecutingAssembly());
        }
        catch (Exception e) 
        {
            Console.Out.WriteLine($"Failed: {e.ToString()}");
            throw e;
        }
    }

    [HarmonyPatch(typeof(ChasmGame), nameof(ChasmGame.CalculateUpscaleResolution))]
    static class ChasmGame_CalculateUpscaleResolution
    {
        public static bool Prefix(ref ChasmGame __instance, ref Point __result)
        {
            int x, y;
            //Point result = new Point((int)((float)GlobalShare.NativeResolution.X * GlobalShare.Scaling), (int)((float)GlobalShare.NativeResolution.Y * GlobalShare.Scaling));
            Point result = new Point(GlobalShare.DeviceResolution.X, GlobalShare.DeviceResolution.Y);
            if (GlobalShare.FitToScreen)
            {
                __result = result;
                return false;
            }
            
            double scaleX = (double)GlobalShare.DeviceResolution.X / (double)GlobalShare.NativeResolution.X;
            double scaleY = (double)GlobalShare.DeviceResolution.Y / (double)GlobalShare.NativeResolution.Y;
            double scale = Math.Min(scaleX, scaleY);
            if (scaleX < scaleY)
            {
                x = GlobalShare.DeviceResolution.X;
                y = (int)Math.Round((double)GlobalShare.NativeResolution.Y * scale, MidpointRounding.AwayFromZero);
            }
            else
            {
                x = (int)Math.Round((double)GlobalShare.NativeResolution.X * scale, MidpointRounding.AwayFromZero);
                y = GlobalShare.DeviceResolution.Y;
            }
            __result = new Point(x, y);
            return false;
        }
    }

    // Fullscreen/Windowed logic is inverted
    // We remove the limitations that led low-resolution devices to not scale to the whole screen
    [HarmonyPatch(typeof(ChasmGame), nameof(ChasmGame.SetFullScreen))]
    static class ChasmGame_SetFullScreen
    {
        public static bool Prefix(ref ChasmGame __instance)
        {
            __instance._settingFullscreen = true;
            int num = ConfigReader.ReadInt("Scaling");
            Point deviceResolution = GlobalShare.DeviceResolution;
            if (!GlobalShare.FitToScreen)
            {
                double val = (double)deviceResolution.X / (double)GlobalShare.NativeResolution.X;
                double val2 = (double)deviceResolution.Y / (double)GlobalShare.NativeResolution.Y;
                int num2 = (int)Math.Min(val, val2);
                GlobalShare.Scaling = (float)num2;
            }
            else
            {
                GlobalShare.Scaling = (float)num;
            }
            GlobalShare.UpscaleResolution = __instance.CalculateUpscaleResolution();
            GlobalShare.UpscaleRenderTarget = new RenderTarget2D(__instance.GraphicsDevice, GlobalShare.UpscaleResolution.X, GlobalShare.UpscaleResolution.Y);

            __instance._graphics.IsFullScreen = GlobalShare.Fullscreen;
            __instance._graphics.PreferredBackBufferWidth = deviceResolution.X;
            __instance._graphics.PreferredBackBufferHeight = deviceResolution.Y;
            __instance._graphics.ApplyChanges();
            __instance._settingFullscreen = false;
            __instance.SetShaderResolution();

            // Don't fall-through, we're overriding this method's behavior
            return false;
        }
    }

    [HarmonyPatch(typeof(ChasmGame), nameof(ChasmGame.Draw))]
    static class ChasmGame_Draw
    {
        static bool keepFs = false;
        static bool keepFit = false;
        //protected override void Draw(GameTime gameTime)

        // Fake the video mode so that we can always have the bilinear path, otherwise
        // text is unreadable
        private static bool Prefix(ChasmGame __instance)
        {
            keepFs = GlobalShare.Fullscreen;
            keepFit = GlobalShare.FitToScreen;
            GlobalShare.Fullscreen = true;
            GlobalShare.FitToScreen = true;
            return true;
        }

        private static void Postfix(ChasmGame __instance)
        {
            GlobalShare.Fullscreen = keepFs;
            GlobalShare.FitToScreen = keepFit;
        }
    }

    [HarmonyPatch(typeof(ChasmGame), nameof(ChasmGame.StartupInit))]
    static class ChasmGame_StartupInit
    {
        static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
        {
            Console.WriteLine($"Patching ChasmGame at ChasmGame:StartupInit...");
            var codes = new List<CodeInstruction>(instructions);
            for (int i = 0; i < codes.Count-2; i++)
            {

                if (
                    codes[i].opcode   == OpCodes.Newobj && codes[i].operand.ToString().Contains("Void .ctor") && // 2	000A	newobj	instance void Chasm.Platforms.Steam.SteamPlatform::.ctor()
                    codes[i+1].opcode == OpCodes.Stsfld && codes[i+1].operand.ToString().Contains("Platform")    // 3	000F	stsfld	class Chasm.Platforms.IPlatform Chasm.ChasmGame::Platform
                )
                {
                    codes[i] = new CodeInstruction(OpCodes.Newobj, AccessTools.Constructor(typeof(PCPlatform), new Type[] {}));
                    Console.WriteLine($"Patched ChasmGame at ChasmGame:StartupInit+{i}");
                    break;
                }
            }
            
            return codes.AsEnumerable();
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
