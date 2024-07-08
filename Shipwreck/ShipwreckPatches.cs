using System;
using System.Runtime.CompilerServices;
using System.Reflection;
using HarmonyLib;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Content;
using Shipwreck;
using Shipwreck.Layers;

[assembly: IgnoresAccessChecksTo("Shipwreck")]
[assembly: IgnoresAccessChecksTo("Microsoft.Xna.Framework")]
[ModEntryPoint]
public static class ShipwreckPatches
{
    private static Effect effect_scaler = null;

    public static void Main()
    {
        Console.Out.WriteLine("Found ShipwreckPatches, running...");
        try
        {
            new Harmony("com.github.johnnyonflame.ShipwreckPatches").PatchAll(Assembly.GetExecutingAssembly());
        }
        catch (Exception e) 
        {
            Console.Out.WriteLine($"Failed: {e.ToString()}");
            throw e;
        }
    }

    // Disable this, causes a feedback loop of going fullscreen and back due to SDL2 behavior
    [HarmonyPatch(typeof(ShipwreckGame), nameof(ShipwreckGame.Window_ClientSizeChanged))]
    internal static class internalShipwreckGame_Window_ClientSizeChanged
    {
        static bool Prefix(ref ShipwreckGame __instance, object sender, EventArgs e)
        {
            return false;
        }
    }

    // We're changing the fullscreen behavior, don't let resize happen.
    [HarmonyPatch(typeof(ShipwreckGame), nameof(ShipwreckGame.Resize))]
    internal static class ShipwreckGame_Resize
    {
        static bool Prefix(ref ShipwreckGame __instance)
        {
            return false;
        }
    }

    [HarmonyPatch(typeof(ShipwreckGame), nameof(ShipwreckGame.ChangeFullScreen))]
    internal static class ShipwreckGame_ChangeFullScreen
    {
        static bool Prefix(ref ShipwreckGame __instance)
        {
            // Always fullscreen, use the draw override for this.
            __instance._graphics.PreferredBackBufferWidth = GraphicsAdapter.DefaultAdapter.CurrentDisplayMode.Width;
            __instance._graphics.PreferredBackBufferHeight = GraphicsAdapter.DefaultAdapter.CurrentDisplayMode.Height;
            __instance._graphics.ApplyChanges();
            return false;
        }
    }


    [HarmonyPatch]
    public class GameBase
    {
        [HarmonyReversePatch]
        [HarmonyPatch(typeof(Game), nameof(Game.Draw))]
        public static void Draw(Game instance, GameTime gameTime) => throw new NotImplementedException("stub");

    }

    [HarmonyPatch(typeof(ShipwreckGame), nameof(ShipwreckGame.Draw))]
    internal class ShipwreckGame_Draw
    {

        static bool Prefix(ref ShipwreckGame __instance, GameTime gameTime)
        {
            ContentManager cm = (__instance as Game).Content;
            // Windowed mode means we're just using the default behavior
            if (!Settings.FullScreen)
                return true;

            LayerManager.PreDraw();
            __instance.GraphicsDevice.SetRenderTarget(__instance._gameTarget);
            __instance.GraphicsDevice.Clear(__instance.ClearColor);
            
            __instance.Drawer.Begin();
            LayerManager.Draw(__instance.Drawer);
            __instance.Drawer.End();
            GameBase.Draw(__instance, gameTime);

            __instance.GraphicsDevice.SetRenderTarget(null);
            __instance.GraphicsDevice.Clear(Color.Black);

            if (ShipwreckPatches.effect_scaler == null)
            {
                ShipwreckPatches.effect_scaler = cm.Load<Effect>("shimmerless");
            }

            Rectangle r = new Rectangle();
            r.Width = __instance._graphics.PreferredBackBufferWidth;
            r.Height = __instance._graphics.PreferredBackBufferHeight;
            float aspectBackbuffer = (float)r.Width / (float)r.Height;
            float aspectGameBuffer = __instance._gameTarget.Width / __instance._gameTarget.Height;

            if (aspectBackbuffer > aspectGameBuffer) {
                r.Width = (int)((float)r.Height * aspectGameBuffer);
            } else {
                r.Height = (int)((float)r.Width / aspectGameBuffer);
            }

            r.X = __instance._graphics.PreferredBackBufferWidth / 2 - r.Width / 2;
            r.Y = __instance._graphics.PreferredBackBufferHeight / 2 - r.Height / 2;

            ShipwreckPatches.effect_scaler.Parameters["TexSize"].SetValue(new Vector2(__instance._gameTarget.Width, __instance._gameTarget.Height));
            ShipwreckPatches.effect_scaler.Parameters["InputSize"].SetValue(new Vector2(__instance._gameTarget.Width, __instance._gameTarget.Height));
            ShipwreckPatches.effect_scaler.Parameters["OutputSize"].SetValue(new Vector2(r.Width, r.Height));

            __instance.Drawer.SpriteBatch.Begin(SpriteSortMode.Immediate, BlendState.Opaque, SamplerState.PointClamp, null, null, effect_scaler);
            __instance.Drawer.SpriteBatch.Draw(__instance._gameTarget, r, Color.White);
            __instance.Drawer.SpriteBatch.End();

            return false;
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
