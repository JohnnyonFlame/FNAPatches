using Microsoft.Xna.Framework;
using Paris.Engine.Menu.Control;
using Paris.Engine.Scene;
using Paris.Game.System.Pathfinding;
using Paris.Game;
using System.IO;
using System.Linq;
using System.Reflection;
using System;

#pragma warning disable 1591
#pragma warning disable CS0649
#pragma warning disable CS0626

namespace Paris.Game.Menu
{
    public class patch_Options: Options
    {
        public static int shadowPreset = 1;
        public static int reducedRats = 1;
        private Control.OptionSelectionItem _shadowController;
        private Control.OptionSelectionItem _reducedRatsController;
        static private Type SaveSystem_t;
        static private MethodInfo SaveSystem_GetModConfigPath_m;

        private static string GetExtraConfigPath()
        {
            if (SaveSystem_t == null)
            {
                SaveSystem_t = Type.GetType("Paris.Engine.Save.SaveSystem, ParisEngine", true);
                SaveSystem_GetModConfigPath_m = SaveSystem_t.GetMethod("GetModConfigPath", BindingFlags.Static | BindingFlags.Public);
            }

            return (string)SaveSystem_GetModConfigPath_m.Invoke(null, new object[] {});
        }

        public static void LoadModConfig()
        {
            string cfg_path = GetExtraConfigPath();
            try
            {
                using (FileStream cfg = new FileStream(cfg_path, FileMode.Open))
                using (BinaryReader cfg_reader = new BinaryReader(cfg))
                {
                    shadowPreset = cfg_reader.ReadInt32();
                    reducedRats = cfg_reader.ReadInt32();
                }
            }
            catch(Exception e)
            {
                Console.Error.WriteLine(e.ToString());
            }
        }

        public static void SaveModConfig()
        {
            try
            {
                using (FileStream cfg = new FileStream(GetExtraConfigPath(), FileMode.Create))
                using (BinaryWriter cfg_writer = new BinaryWriter(cfg))
                {
                    cfg_writer.Write(shadowPreset);
                    cfg_writer.Write(reducedRats);
                }
            }
            catch(Exception e)
            {
                Console.Error.WriteLine(e.ToString());
            }
        }

        private Control.OptionSelectionItem InsertOptionsItemString(SelectionMenuControl selectionControl, string option)
		{
			int count = selectionControl.Items.Count;
			return (Control.OptionSelectionItem)selectionControl.Add(new Control.OptionSelectionItem(option, 340)
			{
				UnselectedFont = MainMenu.MENU_UNSELECTED_FONT,
				DisabledFont = MainMenu.MENU_DISABLED_FONT,
				ArrowLeftTexture = this._arrowLeftTexture,
				ArrowRightTexture = this._arrowRightTexture,
				ArrowLeftColor = GameColors.ArrowLeftColor,
				ArrowRightColor = GameColors.ArrowRightColor,
				OutlineSelectedColor = Color.Black,
				OutlineUnselectedColor = Color.Black,
				OutlineDisabledColor = Color.Black
			}, 0);
		}

        extern void orig_SetupOptions(Options.MenuSchemes menuScheme, SelectionMenuControl selectionControl);
        new public void SetupOptions(Options.MenuSchemes menuScheme, SelectionMenuControl selectionControl)
        {
            orig_SetupOptions(menuScheme, selectionControl);

            this._shadowController = InsertOptionsItemString(selectionControl, "Shadows");
            this._shadowController.AddOption("Off");    // 0
            this._shadowController.AddOption("Low");    // 1
            this._shadowController.AddOption("Normal"); // 2
            this._shadowController.Value = patch_Options.shadowPreset;
            this._shadowController.OptionChangedCallback = new SelectionItem.SelectionCallback((sel) => {
                patch_Options.shadowPreset = ((Control.OptionSelectionItem)sel).Value;
                SaveModConfig();
                this.HaveChanged = true;
            });

            this._reducedRatsController = InsertOptionsItemString(selectionControl, "Rat Count");
            this._reducedRatsController.AddOption("Normal");
            this._reducedRatsController.AddOption("Low");
            this._reducedRatsController.AddOption("Very Low");
            this._reducedRatsController.Value = patch_Options.reducedRats;
            this._reducedRatsController.OptionChangedCallback = new SelectionItem.SelectionCallback((sel) => {
                patch_Options.reducedRats = ((Control.OptionSelectionItem)sel).Value;
                SaveModConfig();
                this.HaveChanged = true;
            });
        }
    }
}

namespace Paris
{
    class patch_Paris: Paris
    {
        protected override void Uninit()
		{
			base.Uninit();
			GameInfo.Singleton.Uninit();
			NetworkMessageSystem.Singleton.Uninit();
			this.UninitLeaderboards();
			this.UninitPlatform();
            if (PathfindingManager.Singleton != null)
			    PathfindingManager.Singleton.Uninit();
		}
    }

    static class patch_ParamManager
    {
        public extern static ParamFlag orig_ParseParams(String[] args);
        public static ParamFlag ParseParams(String[] args)
        {
            Game.Menu.patch_Options.LoadModConfig();
            Console.Out.WriteLine("Params Set:");
            ParamFlag flags = orig_ParseParams(args);
            if (flags == ParamFlag.None)
            {
                Console.Out.WriteLine("> None");
            }
            else
            {
                foreach (var param in Enum.GetValues(typeof(ParamFlag)).Cast<ParamFlag>())
                {
                    if (param == 0)
                        continue;

                    if ((flags & param) == param)
                    {
                        Console.Out.WriteLine($"> {param}");
                    }
                }
            }

            Console.Out.WriteLine("Removing Program.CrashHandler handler...");
            AppDomain.CurrentDomain.UnhandledException -= Program.CrashHandler;

            return flags;
        }
    }
}

// Lower the rat count a tiny bit on slower devices...
namespace Paris.Game.Actor
{
    public class patch_RatKing: RatKing
    {
		private void SpawnPiedPiperRatsAtPos(Vector3 position, int count, bool horizontalFlipped)
		{
            int reducedRats = 1 + Menu.patch_Options.reducedRats;
			for (int i = 0; i < count; i += reducedRats)
			{
				Rat rat = GameObjectPoolManager.Singleton.SpawnObject(this.RatPiedPiperTemplatePath, position, false, false, true) as Rat;
				rat.Owner = this;
				rat.HorizontalFlipped = horizontalFlipped;
				rat.SetupRatInStampede();
				rat.Position += new Vector3(0f, ((float)i - (float)count / 2f) * 10f, 0f);
				rat.Position += new Vector3(((float)ParisMath.GetRandom() * 10f - 5f) * reducedRats, ((float)ParisMath.GetRandom() * 10f - 5f) * reducedRats, 0f);
				rat.Animator.CurrentFrameID = ParisMath.GetRandomInt() % rat.Animator.CurrentAnimation.Frames.Count;
				rat.Animator.Scale = 1f + ((float)ParisMath.GetRandom() - 0.5f) * 0.1f;
				rat.LocallyControlled = true;
				this._piedPiperRats.Add(rat);
			}
		}
    }
}
