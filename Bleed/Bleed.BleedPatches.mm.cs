using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework;
using Mono.Cecil.Cil;
using MonoMod.Cil;

#pragma warning disable CS0626

namespace TimeGuy
{
    class patch_Program
    {
        // We're going to apply some Runtime Hooks before the init, so let's change the behavior of Program.Main:
        extern static void orig_Main(string[] args);
        private static void Main(string[] args)
        {
            // For this, you need to create the MMHOOK_Bleed.dll and reference it during build time.
            // Refer to the MonoMod.RuntimeDetour.HookGen.exe documentation.
            IL.TimeGuy.Game1.ctor += Hook_Game1_ctor;

            // Give execution back to the game
            orig_Main(args);
        }

        private static void Hook_Game1_ctor(ILContext il)
        {
            /* 
                Consider the following line on Bleed's code:

                > ResolutionHelper.SetResolution(
                    this.graphics.GraphicsDevice.DisplayMode.Width,
                    this.graphics.GraphicsDevice.DisplayMode.Height,
                    true);

                The `This.graphics.GraphicsDevice` member is NULL at this point on certain FNA+SDL2 configs, 
                so to ensure it won't crash, we're going to use GraphicsAdapter.DefaultAdapter to query the
                default adapter's current display mode instead, so we need to patch the IL to do the following:

                > ResolutionHelper.SetResolution(
                    GraphicsAdapter.DefaultAdapter.CurrentDisplayMode.Width,
                    GraphicsAdapter.DefaultAdapter.CurrentDisplayMode.Width,
                    true);
            */
            ILCursor ilCursor = new ILCursor(il);
            if (ilCursor.TryGotoNext(MoveType.Before,
                i => i.MatchLdarg(0),
                i => i.MatchLdfld(typeof(TimeGuy.Game1), "graphics"),
                i => i.MatchCallvirt(typeof(GraphicsDeviceManager), "get_GraphicsDevice"),
                i => i.MatchCallvirt(typeof(GraphicsDevice), "get_DisplayMode"),
                i => i.MatchCallvirt(typeof(DisplayMode), "get_Width"),
                i => i.MatchLdarg(0),
                i => i.MatchLdfld(typeof(TimeGuy.Game1), "graphics"),
                i => i.MatchCallvirt(typeof(GraphicsDeviceManager), "get_GraphicsDevice"),
                i => i.MatchCallvirt(typeof(GraphicsDevice), "get_DisplayMode"),
                i => i.MatchCallvirt(typeof(DisplayMode), "get_Height")
            ))
            {
                // Remove the above instructions
                ilCursor = ilCursor.RemoveRange(10);

                // Patch our new behavior in.
                ilCursor.Emit(OpCodes.Call, typeof(GraphicsAdapter).GetMethod("get_DefaultAdapter"));
                ilCursor.Emit(OpCodes.Callvirt, typeof(GraphicsAdapter).GetMethod("get_CurrentDisplayMode"));
                ilCursor.Emit(OpCodes.Callvirt, typeof(DisplayMode).GetMethod("get_Width"));
                ilCursor.Emit(OpCodes.Call, typeof(GraphicsAdapter).GetMethod("get_DefaultAdapter"));
                ilCursor.Emit(OpCodes.Callvirt, typeof(GraphicsAdapter).GetMethod("get_CurrentDisplayMode"));
                ilCursor.Emit(OpCodes.Callvirt, typeof(DisplayMode).GetMethod("get_Height"));
            }
        }
    }
}