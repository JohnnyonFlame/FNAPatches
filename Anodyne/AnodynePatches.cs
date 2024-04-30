using System;
using System.Reflection;
using System.Runtime.CompilerServices;
using HarmonyLib;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Content;
using AnodyneSharp;
using AnodyneSharp.Drawing;
using AnodyneSharp.Registry;

[assembly: IgnoresAccessChecksTo("AnodyneSharp")]
[assembly: IgnoresAccessChecksTo("Microsoft.Xna.Framework")]
[ModEntryPoint]
public static class AnodynePatches
{
    public static void Main()
    {
        Console.Out.WriteLine("Found AnodynePatches, running...");
        try
        {
            new Harmony("com.github.johnnyonflame.AnodynePatches").PatchAll(Assembly.GetExecutingAssembly());
        }
        catch (Exception e) 
        {
            Console.Out.WriteLine($"Failed: {e.ToString()}");
            throw e;
        }
    }

    [HarmonyPatch(typeof(SpriteDrawer), nameof(SpriteDrawer.Load))]
    public static class SpriteDrawer_Load
    {
        public static Effect bilinear_sharp;
        public static bool Prefix(ContentManager c)
        {
            bilinear_sharp = c.Load<Effect>("effects/bilinear-sharp");
            return true;
        }
    }

    [HarmonyPatch(typeof(SpriteDrawer), nameof(SpriteDrawer.Render))]
    public static class SpriteDrawer_Render
    {
        public static bool Prefix(Effect effect)
        {
            // We only override the behavior of Resolution.Stretch
            if (GlobalState.settings.resolution != Resolution.Stretch)
                return true;

            Rectangle r = new Rectangle();
            r.Width = SpriteDrawer._graphicsDevice.PresentationParameters.BackBufferWidth;
            r.Height = SpriteDrawer._graphicsDevice.PresentationParameters.BackBufferHeight;
            float aspectBackbuffer = (float)r.Width / (float)r.Height;
            float aspectGameBuffer = 160.0f / 180.0f;

            if (aspectBackbuffer > aspectGameBuffer) {
                r.Width = (int)((float)r.Height * aspectGameBuffer);
            } else {
                r.Height = (int)((float)r.Width / aspectGameBuffer);
            }

            r.X = SpriteDrawer._graphicsDevice.PresentationParameters.BackBufferWidth / 2 - r.Width / 2;
            r.Y = SpriteDrawer._graphicsDevice.PresentationParameters.BackBufferHeight / 2 - r.Height / 2;

            SpriteDrawer_Load.bilinear_sharp.Parameters["TexSize"].SetValue(new Vector2(160.0f, 180.0f));
            SpriteDrawer_Load.bilinear_sharp.Parameters["Scale"].SetValue(new Vector2(r.Width / 160.0f, r.Height / 180.0f));

            SpriteDrawer._graphicsDevice.SetRenderTarget(null);
            SpriteDrawer._graphicsDevice.Clear(Color.Black);
            SpriteDrawer._spriteBatch.Begin(SpriteSortMode.Texture, BlendState.AlphaBlend, SpriteDrawer.SamplerState, null, null, SpriteDrawer_Load.bilinear_sharp, null);
            SpriteDrawer._spriteBatch.Draw(SpriteDrawer._render, r, SpriteDrawer.FullScreenFade);
            SpriteDrawer._spriteBatch.End();
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
