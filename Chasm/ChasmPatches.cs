using System;
using System.Runtime.CompilerServices;
using System.Reflection;
using HarmonyLib;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Chasm;
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

    // Fullscreen/Windowed logic is inverted
    // We remove the limitations that led low-resolution devices to not scale to the whole screen
    [HarmonyPatch(typeof(ChasmGame), nameof(ChasmGame.SetFullScreen))]
    static class ChasmGame_SetFullScreen
    {
        public static bool Prefix(ref ChasmGame __instance)
        {
			__instance._settingFullscreen = true;
			int num = ConfigReader.ReadInt("Scaling");
			Point desktopResolution = GlobalShare.DesktopResolution;
			int num2 = (int)Math.Floor((double)desktopResolution.X / (double)GlobalShare.NativeResolution.X);
			if (num > num2)
			{
				num = num2;
			}
			if (GlobalShare.FullscreenAutoscale && !GlobalShare.Fullscreen)
			{
				double val = (double)desktopResolution.X / (double)GlobalShare.NativeResolution.X;
				double val2 = (double)desktopResolution.Y / (double)GlobalShare.NativeResolution.Y;
				GlobalShare.Scaling = (float)Math.Min(val, val2);
			}
			else
			{
				GlobalShare.Scaling = (float)num;
			}
			GlobalShare.DisplayResolution = new Point((int)((float)GlobalShare.NativeResolution.X * GlobalShare.Scaling), (int)((float)GlobalShare.NativeResolution.Y * GlobalShare.Scaling));
			GlobalShare.DisplayRenderTarget = new RenderTarget2D(__instance.GraphicsDevice, GlobalShare.DisplayResolution.X, GlobalShare.DisplayResolution.Y);
			if (!GlobalShare.Fullscreen)
			{
				__instance._graphics.IsFullScreen = false;
				__instance._graphics.PreferredBackBufferWidth = desktopResolution.X;
				__instance._graphics.PreferredBackBufferHeight = desktopResolution.Y;
			}
			else
			{
				__instance._graphics.IsFullScreen = true;
				__instance._graphics.PreferredBackBufferWidth = GlobalShare.DisplayResolution.X;
				__instance._graphics.PreferredBackBufferHeight = GlobalShare.DisplayResolution.Y;
			}
			__instance._graphics.ApplyChanges();
			__instance._settingFullscreen = false;
			__instance.SetShaderResolution();

            // Don't fall-through, we're overriding this method's behavior
            return false;
        }
    }

    // Reflect logic above
    [HarmonyPatch(typeof(OptionsScreen), nameof(OptionsScreen.Show))]
    static class OptionsScreen_Show
    {
        public static void Postfix(OptionsScreen __instance, bool isMainMenu)
        {
            __instance.Scale.ValueChanged = delegate()
            {
                int num = (int)__instance.Scale.Value;
                if (ConfigReader.ReadInt("Scaling") != num)
                {
                    ConfigReader.WriteInt("Scaling", num);
                    GlobalShare.Game.SetFullScreen();
                }
            };
        }
    }

    [HarmonyPatch(typeof(ChasmGame), nameof(ChasmGame.LoadContent))]
    static class ChasmGame_LoadContent
    {
        public static void Postfix(ref ChasmGame __instance)
        {
            // Reflect the altered resolution logic...
            ChasmGame_SetFullScreen.Prefix(ref __instance);
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
