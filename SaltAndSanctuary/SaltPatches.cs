using System;
using System.Collections.Generic;
using System.Collections.Concurrent;
using System.Runtime.CompilerServices;
using System.Text;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using HarmonyLib;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Input;

using System.Threading.Tasks;
using System.Threading;

using ProjectTower;
using ProjectTower.audio;
using ProjectTower.config;
using ProjectTower.game;
using ProjectTower.character;
using ProjectTower.debug;
using ProjectTower.director;
using ProjectTower.director.bloom;
using ProjectTower.gameservices.charSequence;
using ProjectTower.gameservices.messages;
using ProjectTower.gamestate;
using ProjectTower.hud;
using ProjectTower.map;
using ProjectTower.map.pickups;
using ProjectTower.particles;
using ProjectTower.player;
using ProjectTower.player.dialog;
using ProjectTower.player.dialog.levels;
using ProjectTower.sanctuary;
using ProjectTower.smash;
using ProjectTower.texturesheet;
using ProjectTower.menu.levels;
using DialogEdit;
using SkillTreeEdit.skilltree;
using MonsterEdit.monsters;
using MapEdit;
using MapEdit.glows;
using LootEdit;
using LootEdit.loot;
using SheetEdit.TextureSheet;

[assembly: IgnoresAccessChecksTo("Salt")]
[assembly: IgnoresAccessChecksTo("FNA")]
[ModEntryPoint]
public static class SaltPatches
{
	public static void RecurseTypes(HashSet<Type> objects_jit, Type type)
	{
		objects_jit.Add(type);
		foreach (var t in type.GetNestedTypes())
		{
			RecurseTypes(objects_jit, t);
		}
	}
	
	public static void Main()
	{
		Console.Out.WriteLine("Found SaltPatches, running...");
		try
		{
			new Harmony("com.github.johnnyonflame.SaltPatches").PatchAll(Assembly.GetExecutingAssembly());
		}
		catch (Exception e) 
		{
			Console.Out.WriteLine($"Failed: {e.ToString()}");
			throw e;
		}

		void ForceLoadAll(Assembly assembly, HashSet<Assembly> loadedAssmblies)
		{
			bool alreadyLoaded = !loadedAssmblies.Add(assembly);
			if (alreadyLoaded)
				return;

			AssemblyName[] refrencedAssemblies =
				assembly.GetReferencedAssemblies();

			foreach (AssemblyName curAssemblyName in refrencedAssemblies)
			{
				Assembly nextAssembly = Assembly.Load(curAssemblyName);
				if (nextAssembly.GlobalAssemblyCache)
					continue;

				ForceLoadAll(nextAssembly, loadedAssmblies);
			}
		}

		HashSet<Assembly> loadedAsm = new HashSet<Assembly>();
		foreach (var asm in AppDomain.CurrentDomain.GetAssemblies())
		{
			ForceLoadAll(asm, loadedAsm);
		}

		HashSet<Type> objects_jit = new HashSet<Type>();
		foreach (var asm in loadedAsm)
		{
			foreach (var type in asm.GetTypes())
			{
				RecurseTypes(objects_jit, type);
			}
		}

		objects_jit.AsParallel().ForAll(type => {
				foreach (var method in type.GetMethods(
					BindingFlags.Static |
					BindingFlags.Instance |
					BindingFlags.Public |
					BindingFlags.NonPublic))
				{
					// Console.WriteLine($"JITing {type.ToString()}:{method.Name}...");
					System.Runtime.CompilerServices.RuntimeHelpers.PrepareMethod(method.MethodHandle);
				}
			}
		);

		//Process.GetCurrentProcess().Kill();
		Console.Out.WriteLine($"Done.");
	}

	//[HarmonyPatch(typeof(ScrollManager), nameof(ScrollManager.UpdateCannedValues))]
	//public static class ScrollManager_UpdateCannedValues
	//{
	//	public static bool Prefix()
	//	{
	//		ScrollManager.zoom *= 0.45f + VideoOptions__ctor.zoomLevel * 0.05f;
	//		return true;
	//	}
	//}

	// In-game camera zoom option logic - needed for smaller displays
	[HarmonyPatch(typeof(CamMgr), nameof(CamMgr.Update))]
	public static class CamMgr_Update
	{
		public static float GetZoomLevelModifier()
		{
			return 0.45f + VideoOptions__ctor.zoomLevel * 0.05f;
		}

		public static float GetArenaCorrection()
		{
			float origAspect = 1280f / 720f; //16:9
			float curAspect = ScrollManager.screenSize.X / ScrollManager.screenSize.Y;
			float correction = origAspect / curAspect;
			return correction / GetZoomLevelModifier();
		}

		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			Console.WriteLine($"Patching CamMgr at CamMgr:Update...");
			var codes = new List<CodeInstruction>(instructions);
			for (int i = 0; i < codes.Count-5; i++)
			{
				// Changes:
				// Vector2 arenaLoc = MapMgr.map.triggerMgr.GetArenaLoc(activeArenaIdx);
				// Vector2 arenaScale = MapMgr.map.triggerMgr.GetArenaScale(activeArenaIdx);
				// - arenaScale.X -= 500f;
				// + arenaScale.X -= 500f * GetArenaCorrection();
				// arenaScale.Y -= 100f;
				if (
					codes[i].opcode   == OpCodes.Ldloca_S &&
					codes[i+1].opcode == OpCodes.Ldflda && codes[i+1].operand.ToString().Contains("X") &&
					codes[i+2].opcode == OpCodes.Dup &&
					codes[i+3].opcode == OpCodes.Ldind_R4 &&
					codes[i+4].opcode == OpCodes.Ldc_R4 &&
					codes[i+5].opcode == OpCodes.Sub &&
					codes[i+6].opcode == OpCodes.Stind_R4
				)
				{
					List<CodeInstruction> newCodes = new List<CodeInstruction>();
					newCodes.Add(new CodeInstruction(OpCodes.Call, ((Func<float>) CamMgr_Update.GetArenaCorrection).Method));
					newCodes.Add(new CodeInstruction(OpCodes.Div));
					Console.WriteLine($"[aspect 1/2] Patched CamMgr at CamMgr:Update+{i+3}!");
					codes.InsertRange(i+5, newCodes);
					break;
				}
			}

			for (int i = 0; i < codes.Count-5; i++)
			{
				// Changes:
				// Vector2 loc = MapMgr.sanctuaryMgr.sanctuaries[sanctuaryIn].loc;
				// Vector2 vector8 = new Vector2(400f * GetArenaCorrection(), 0f);
				if (
					codes[i].opcode   == OpCodes.Ldloca_S &&
					codes[i+1].opcode == OpCodes.Ldc_R4 &&
					codes[i+2].opcode == OpCodes.Ldc_R4 &&
					codes[i+3].opcode == OpCodes.Call && codes[i+3].operand.ToString().Contains(".ctor") &&
					codes[i+4].opcode == OpCodes.Ldarg_0
				)
				{
					List<CodeInstruction> newCodes = new List<CodeInstruction>();
					newCodes.Add(new CodeInstruction(OpCodes.Call, ((Func<float>) CamMgr_Update.GetArenaCorrection).Method));
					newCodes.Add(new CodeInstruction(OpCodes.Mul));
					Console.WriteLine($"[aspect 2/2] Patched CamMgr at CamMgr:Update+{i+3}!");
					codes.InsertRange(i+2, newCodes);
					break;
				}
			}

			for (int i = 0; i < codes.Count-5; i++)
			{
				// Changes:
				// ScrollManager.candleAlpha = this.candleAlpha;
				// ScrollManager.scroll = this.scroll;
				// - ScrollManager.zoom = this.zoom;
				// + ScrollManager.zoom = this.zoom * CamMgr_Update.GetZoomLevelModifier();
				// if (BossToast.active)
				// {
				if (
					codes[i].opcode   == OpCodes.Ldarg_0   &&
					codes[i+1].opcode == OpCodes.Ldfld     && codes[i+1].operand.ToString().Contains("zoom")   &&
					codes[i+2].opcode == OpCodes.Stsfld    && codes[i+2].operand.ToString().Contains("zoom")   &&
					codes[i+3].opcode == OpCodes.Ldsfld    && codes[i+3].operand.ToString().Contains("active") &&
					codes[i+4].opcode == OpCodes.Brfalse_S &&
					codes[i+5].opcode == OpCodes.Ldsfld    && codes[i+5].operand.ToString().Contains("active") &&
					codes[i+6].opcode == OpCodes.Brfalse_S
				)
				{
					List<CodeInstruction> newCodes = new List<CodeInstruction>();
					newCodes.Add(new CodeInstruction(OpCodes.Call, ((Func<float>) CamMgr_Update.GetZoomLevelModifier).Method));
					newCodes.Add(new CodeInstruction(OpCodes.Mul));
					Console.WriteLine($"Patched CamMgr at CamMgr:Update+{i+2}!");
					codes.InsertRange(i+2, newCodes);
					break;
				}
			}
			
			return codes.AsEnumerable();
		}
	}

	// Load new Effects for overhauled renderer, setup lowered targets, etc
	[HarmonyPatch(typeof(Game1), nameof(Game1.CreateTargs))]
	public static class Game1_CreateTargs
	{
		public static bool isLoaded = false;
		public static RenderTarget2D menuItemsTarg;
		public static Texture2D bayerTex;
		public static Effect simplifiedTintBloomEffect;
		public static Effect mainEffect;
		public static Effect mainEffectLightsBloom;
		public static Effect mainEffectLightsNoBloom;
		public static Effect mainEffectNoLightsBloom;
		public static Effect mainEffectNoLightsNoBloom;
		public static Effect clearAlphaEffect;
		public static Effect mapBloodEffect;
		public static float ditherMinPixel = 1.0f / 256.0f;

		public static void Postfix()
		{
			Glow_DrawForLightMode.GlowRatio = new Vector2(1f / 4f, 1f / 4f);

			//sceneTarg needs RenderTargetUsage.PreserveContents for Medium/Low graphics settings
			GameDraw.sceneTarg.Dispose();
			GameDraw.sceneTarg = new RenderTarget2D(Game1.graphics.GraphicsDevice, (int)ScrollManager.screenSize.X, (int)ScrollManager.screenSize.Y);
			GameDraw.lightTarg.Dispose();
			GameDraw.lightTarg = new RenderTarget2D(Game1.graphics.GraphicsDevice, (int)(ScrollManager.screenSize.X * Glow_DrawForLightMode.GlowRatio.X), (int)(ScrollManager.screenSize.Y * Glow_DrawForLightMode.GlowRatio.Y));

			float scaleX = 960f / ScrollManager.screenSize.X;
			float scaleY = 544f / ScrollManager.screenSize.Y;
			int width, height;
			if (scaleY > scaleX) {
				width = (int)(ScrollManager.screenSize.X * scaleY);
				height = (int)(ScrollManager.screenSize.Y * scaleY);
			} else {
				width = (int)(ScrollManager.screenSize.X * scaleX);
				height = (int)(ScrollManager.screenSize.Y * scaleX);
			}

			Game1_CreateTargs.menuItemsTarg = new RenderTarget2D(Game1.graphics.GraphicsDevice, width, height);

			if (isLoaded)
				return;

			// 8x8 Bayer Matrix used for the dithering during color correction post processing
			// done in mainEffect shader variants. Helps lower color banding significantly, specially
			// on the OGA/RG351P screens.
			byte[] bayer = new byte[]{
				0,   128,  32, 160,   8, 136,  40, 168,
				192,  64, 224,  96, 200,  72, 232, 104,
				48,  176,  16, 144,  56, 184,  24, 152,
				240, 112, 208,  80, 248, 120, 216,  88,
				12,  140,  44, 172,   4, 132,  36, 164,
				204,  76, 236, 108, 196,  68, 228,  10, 
				60,  188,  28, 156,  52, 180,  20, 148,
				252, 124, 220,  92, 244, 116, 212,   8
			};
	
			bayerTex = new Texture2D( Game1.graphics.GraphicsDevice, 8, 8, false, SurfaceFormat.Alpha8 );
			bayerTex.SetData<byte>(bayer);

			bool use16bpp = Environment.GetEnvironmentVariable("SALT_USE_16BPP_DITHER") == "1";
			if (use16bpp)
			{
				ditherMinPixel = 8.0f / 256.0f;
			}


			simplifiedTintBloomEffect = (Game1_Initialize.game as Game).Content.Load<Effect>("fx/SimplifiedTintBloom.fxb");
			mainEffectLightsBloom = (Game1_Initialize.game as Game).Content.Load<Effect>("fx/MainEffectLightsBlur.fxb");
			mainEffectLightsNoBloom = (Game1_Initialize.game as Game).Content.Load<Effect>("fx/MainEffectLightsNoBlur.fxb");
			mainEffectNoLightsBloom = (Game1_Initialize.game as Game).Content.Load<Effect>("fx/MainEffectNoLightsBlur.fxb");
			mainEffectNoLightsNoBloom = (Game1_Initialize.game as Game).Content.Load<Effect>("fx/MainEffectNoLightsNoBlur.fxb");
			clearAlphaEffect = (Game1_Initialize.game as Game).Content.Load<Effect>("fx/ClearAlpha.fxb");
			mapBloodEffect = (Game1_Initialize.game as Game).Content.Load<Effect>("fx/MapBlood.fxb");
			mainEffect = mainEffectNoLightsBloom;	
			isLoaded = true;
		}
	}

	// This is necessary since we altered the size of GameDraw.lightTarg
	[HarmonyPatch(typeof(Glow), nameof(Glow.DrawForLightMode))]
	public class Glow_DrawForLightMode
	{
		public static Vector2 GlowRatio;
		public static bool Prefix(Glow __instance, XTexture xt, int idx)
		{
			xt.Draw(__instance.loc * GlowRatio, 144, __instance.size * GlowRatio * 0.6f, MapMgr.map.delta / 10f, __instance.r, __instance.g, __instance.b, 1f);
			return false;
		}
	}

	// Lower the size of refractTarg
	[HarmonyPatch(typeof(RefractDraw), nameof(RefractDraw.CreateTarg))]
	public static class RefractDraw_CreateTarg
	{
		public static bool Prefix(GraphicsDevice GraphicsDevice)
		{
			RefractDraw.refractTarg = new RenderTarget2D(GraphicsDevice, (int)ScrollManager.screenSize.X / 4, (int)ScrollManager.screenSize.Y / 4);
			return false;
		}
	}

	// Lower the size of the water target a bit.
	[HarmonyPatch(typeof(Water), nameof(Water.CreateTarg))]
	public static class Water_CreateTarg
	{
		public static bool Prefix(GraphicsDevice dev)
		{
			Water.waterTarg = new RenderTarget2D(dev, (int)ScrollManager.screenSize.X / 2, (int)ScrollManager.screenSize.Y / 2);
			return false;
		}	
	}

	// Lower the size the bloom components.
	[HarmonyPatch(typeof(BloomComponent), nameof(BloomComponent.CreateTargs))]
	public static class BloomComponent_CreateTargs
	{
		public static bool Prefix(GraphicsDevice dev)
		{
			BloomComponent.renderTarget1 = new RenderTarget2D(dev, (int)ScrollManager.screenSize.X / 2, (int)ScrollManager.screenSize.Y / 2);
			BloomComponent.renderTarget2 = new RenderTarget2D(dev, (int)ScrollManager.screenSize.X / 2, (int)ScrollManager.screenSize.Y / 2);
			return false;
		}
	}

	[HarmonyPatch(typeof(GameDraw), nameof(GameDraw.DrawMenu))]
	public static class GameDraw_DrawMenu
	{
		public static bool Prefix(Player p, bool logo, GraphicsDevice GraphicsDevice)
		{
			// Use the simplified effect on the menus
			Effect bloomTintEffect = Game1_CreateTargs.simplifiedTintBloomEffect;
			float num = 0f;
			if (p.menuMgr.curLev == 3 || p.menuMgr.menuLevel[p.menuMgr.curLev].showParent == 3)
			{
				p.menuMgr.PrepareCreateCharacter(p, GraphicsDevice);
			}
			if (logo)
			{
				LogoRender.Prepare(p, GraphicsDevice, GameDraw.auxTarg);
			}

			// Draw menu on a separate layer so we can scale it down
			GraphicsDevice.SetRenderTarget(Game1_CreateTargs.menuItemsTarg);
			GraphicsDevice.Clear(new Color(0f, 0f, 0f, 0f));
			// Copy screenSize and force it to 960x544
			Vector2 screenSize = ScrollManager.screenSize;
			ScrollManager.screenSize = new Vector2(Game1_CreateTargs.menuItemsTarg.Width, Game1_CreateTargs.menuItemsTarg.Height);
			ScrollManager.UpdateCannedValues();
			SpriteTools.BeginAlpha();
			p.menuMgr.Draw(1f, default(Rectangle));
			p.menuMgr.DrawVersionInfo();
			SpriteTools.End();
			// Reset screenSize
			ScrollManager.screenSize = screenSize;
			ScrollManager.UpdateCannedValues();

			GraphicsDevice.SetRenderTarget(GameDraw.backTarg);
			GraphicsDevice.Clear(Color.Black);
			SpriteTools.BeginPMAlpha();
			MapMgr.DrawBack(bloomTintEffect, 1f - num, null);
			SpriteTools.End();
			SpriteTools.BeginAlpha();
			float num2 = 0.2f + LogoRender.logoAlpha;
			num2 = 0.2f;
			SpriteTools.sprite.Draw(Game1.nullTex, new Rectangle(0, 0, (int)ScrollManager.screenSize.X, (int)ScrollManager.screenSize.Y), new Color(num2, num2, num2, 0.7f));
			SpriteTools.End();

			// Draw the menu layer onto the world (e.g. for the water reflection effect) 
			SpriteTools.BeginPMAlpha();
			SpriteTools.sprite.Draw(Game1_CreateTargs.menuItemsTarg,
				new Rectangle(0, 0, (int)ScrollManager.screenSize.X, (int)ScrollManager.screenSize.Y),
				new Rectangle(0, 0, Game1_CreateTargs.menuItemsTarg.Width, Game1_CreateTargs.menuItemsTarg.Height),
				Color.White);
			SpriteTools.End();
			
			SpriteTools.BeginAlpha();
			ParticleManager.Draw(1);
			p.camMgr.dotsMgr.DrawBack();
			SpriteTools.End();
			SpriteTools.BeginSubtractive();
			ParticleManager.Draw(0);
			SpriteTools.End();
			SpriteTools.BeginAdditive();
			ParticleManager.Draw(2);
			SpriteTools.End();
			SpriteTools.BeginAlpha();
			ParticleManager.Draw(4);
			SpriteTools.End();
			SpriteTools.BeginSubtractive();
			ParticleManager.Draw(3);
			SpriteTools.End();
			SpriteTools.BeginAdditive();
			ParticleManager.Draw(5);
			SpriteTools.End();
			// Just reference the map field directly... needed for 1.0.0.8
			//Water.Update(MapMgr.GetMap().layer[5], 5, MapMgr.map, p);
			Water.Update(MapMgr.map.layer[5], 5, MapMgr.map, p);
			Water.Prepare(GameDraw.backTarg);
			GraphicsDevice.SetRenderTarget(GameDraw.mainTarg);
			GraphicsDevice.Clear(new Color(0f, 0f, 0f, 1f));
			SpriteTools.BeginOpaque();
			SpriteTools.sprite.Draw(GameDraw.backTarg, new Rectangle(0, 0, (int)ScrollManager.screenSize.X, (int)ScrollManager.screenSize.Y), Color.White);
			SpriteTools.End();
			Water.Draw();
			SpriteTools.BeginPMAlpha();
			if (num < 1f)
			{
				MapMgr.DrawFore(bloomTintEffect, 1f - num, null);
			}
			if (num > 0f)
			{
				MapMgr.DrawIndoorFore(bloomTintEffect, num, null);
			}
			SpriteTools.End();
			SpriteTools.BeginAlpha();
			p.camMgr.dotsMgr.DrawFore();
			SpriteTools.End();
			GraphicsDevice.SetRenderTarget(GameDraw.sceneTarg);
			GraphicsDevice.Clear(new Color(0f, 0f, 0f, 1f));

			LayerTintCatalog.PrepareMenuEffect(GameDraw.mainEffect);
			SpriteTools.BeginAlpha(GameDraw.mainEffect);

			SpriteTools.sprite.Draw(GameDraw.mainTarg, new Rectangle(0, 0, (int)ScrollManager.screenSize.X, (int)ScrollManager.screenSize.Y), Color.White);
			SpriteTools.End();
			LayerTintCatalog.Finalize(1, 1, 1f, null);

			if (logo)
			{
				LogoRender.Draw(GameDraw.auxTarg);
			}
			BloomComponent.Draw(null, GameDraw.sceneTarg, GameDraw.lightTarg);

			// Draw the menu layer onto the final image
			SpriteTools.BeginPMAlpha();
			SpriteTools.sprite.Draw(Game1_CreateTargs.menuItemsTarg,
				new Rectangle(0, 0, (int)ScrollManager.screenSize.X, (int)ScrollManager.screenSize.Y),
				new Rectangle(0, 0, Game1_CreateTargs.menuItemsTarg.Width, Game1_CreateTargs.menuItemsTarg.Height),
				Color.White);
			SpriteTools.End();
			SpriteTools.BeginAlpha();

			if (GameStateManager.quitFrame > 0f)
			{
				SpriteTools.sprite.Draw(Game1.nullTex, new Rectangle(0, 0, (int)ScrollManager.screenSize.X, (int)ScrollManager.screenSize.Y), new Color(0f, 0f, 0f, 1f - GameStateManager.quitFrame));
			}
			SpriteTools.End();

			// Don't fallthrough
			return false;
		}
	}

	// Broad-phase PVS has hardcoded resolutions...?
	public class PatchVisCommon
	{
		public static float getScreenWidthOff()
		{
			return ScrollManager.screenSize.X * 1.35f;
		}

		public static float getScreenHeightOff()
		{
			return ScrollManager.screenSize.Y * 1.35f;
		}

		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions, ILGenerator il, string nameType, string nameFunc)
		{
			Console.WriteLine($"Patching {nameType} at {nameType}:{nameFunc}...");

			// Inject PVS fix
			var codes = new List<CodeInstruction>(instructions);
			for (int i = 0; i < codes.Count-4; i++)
			{
				if (
					codes[i].opcode   == OpCodes.Ldc_R4           && (float)codes[i].operand == 1200 &&  // 0	0000	ldc.r4	1200
					codes[i+1].opcode == OpCodes.Stloc_0          &&                                     // 1	0005	stloc.0
					codes[i+2].opcode == OpCodes.Ldc_R4	          && (float)codes[i+2].operand == 600 && // 2	0006	ldc.r4	600
					codes[i+3].opcode == OpCodes.Stloc_1                                                 // 3	000B	stloc.1
				)
				{
					List<CodeInstruction> newCodes = new List<CodeInstruction>();
					MethodInfo getScreenWidthMethod = typeof(PatchVisCommon).GetMethod("getScreenWidthOff", BindingFlags.Public | BindingFlags.Static);
					MethodInfo getScreenHeightMethod = typeof(PatchVisCommon).GetMethod("getScreenHeightOff", BindingFlags.Public | BindingFlags.Static);

					newCodes.Add(new CodeInstruction(OpCodes.Call, getScreenWidthMethod));
					newCodes.Add(new CodeInstruction(OpCodes.Stloc_0));
					newCodes.Add(new CodeInstruction(OpCodes.Call, getScreenHeightMethod));
					newCodes.Add(new CodeInstruction(OpCodes.Stloc_1));

					Console.WriteLine($"Patched {nameType} at {nameType}:{nameFunc}+{i}");
					codes.RemoveRange(i, 4);
					codes.InsertRange(i, newCodes);
					break;
				}
			}

			return codes.AsEnumerable();
		}
	}
	
	[HarmonyPatch(typeof(MapMgr), nameof(MapMgr.DrawBack))]
	public class MapMgr_DrawBack
	{
		// Used to disable background rendering on Decimated preset
		public static bool shouldDrawBg()
		{
			return (VideoOptions__ctor.gfxPreset < 4);
		}

		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions, ILGenerator il)
		{
			Console.WriteLine($"Patching MapMgr at MapMgr:DrawBack...");

			var codes = new List<CodeInstruction>(instructions);
			for (var i = 0; i < codes.Count - 7; i++)
			{
				if (
					codes[i].opcode   == OpCodes.Ldsfld   && codes[i].operand.ToString().Contains("map")       && // 288 03AB ldsfld class MapEdit.map.Map ProjectTower.map.MapMgr::map
					codes[i+1].opcode == OpCodes.Ldc_I4_0 &&                                                      // 289 03B0 ldc.i4.0
					codes[i+2].opcode == OpCodes.Ldc_I4_4 &&                                                      // 290 03B1 ldc.i4.4
					codes[i+3].opcode == OpCodes.Ldsfld   && codes[i+3].operand.ToString().Contains("glowMgr") && // 291 03B2 ldsfld class MapEdit.glows.GlowMgr ProjectTower.map.MapMgr::glowMgr
					codes[i+4].opcode == OpCodes.Ldarg_0  &&                                                      // 292 03B7 ldarg.0
					codes[i+5].opcode == OpCodes.Ldarg_1  &&                                                      // 293 03B8 ldarg.1
					codes[i+6].opcode == OpCodes.Ldarg_2  &&                                                      // 294 03B9 ldarg.2
					codes[i+7].opcode == OpCodes.Callvirt && codes[i+7].operand.ToString().Contains("Draw")       // 295 03BA callvirt instance void MapEdit.map.Map::Draw(int32, int32, class MapEdit.glows.GlowMgr, class [FNA]Microsoft.Xna.Framework.Graphics.Effect, float32, class ProjectTower.player.Player)
				)
				{
					MethodInfo shouldDrawBgMethod = typeof(MapMgr_DrawBack).GetMethod("shouldDrawBg", BindingFlags.Public | BindingFlags.Static);

					// First define the jump to get rid of the background rendering
					Label ret = il.DefineLabel();
					if (codes[i+8].labels == null)
						codes[i+8].labels = new List<Label>();
					codes[i+8].labels.Add(ret);

					// Now unlink the previous jumps to the start of the Map::Draw call, this will be relinked in the shouldDrawBg Call
					List<Label> previousJump = codes[i].labels;
					codes[i].labels = null;

					List<CodeInstruction> newCodes = new List<CodeInstruction>();
					newCodes.Add(new CodeInstruction(OpCodes.Call, shouldDrawBgMethod) { labels = previousJump });
					newCodes.Add(new CodeInstruction(OpCodes.Brfalse_S, ret));
					codes.InsertRange(i, newCodes);
					Console.WriteLine($"Patched MapMgr at MapMgr:DrawBack+{i}");
					break;
				}
			}

			return codes.AsEnumerable();
		}
	}

	[HarmonyPatch(typeof(SanctuaryMgr), nameof(SanctuaryMgr.Draw))]
	public class SanctuaryMgr_Draw
	{
		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions, ILGenerator il)
		{
			return PatchVisCommon.Transpiler(instructions, il, "SanctuaryMgr", "Draw");
		}
	}

	[HarmonyPatch(typeof(SanctuaryMgr), nameof(SanctuaryMgr.DrawFore))]
	public class SanctuaryMgr_DrawFore
	{
		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions, ILGenerator il)
		{
			return PatchVisCommon.Transpiler(instructions, il, "SanctuaryMgr", "DrawFore");
		}
	}

	[HarmonyPatch(typeof(SanctuaryMgr), nameof(SanctuaryMgr.DrawBack))]
	public class SanctuaryMgr_DrawBack
	{
		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions, ILGenerator il)
		{
			return PatchVisCommon.Transpiler(instructions, il, "SanctuaryMgr", "DrawBack");
		}
	}

	[HarmonyPatch(typeof(SanctuaryMgr), nameof(SanctuaryMgr.DrawMapBack))]
	public class SanctuaryMgr_DrawMapBack
	{
		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions, ILGenerator il)
		{
			return PatchVisCommon.Transpiler(instructions, il, "SanctuaryMgr", "DrawMapBack");
		}
	}

	// Overhauled renderer with graphical presets for different device classes
	[HarmonyPatch(typeof(GameDraw), nameof(GameDraw.DrawGame))]
	public class GameDraw_DrawGame
	{
		public static Effect lastEffect = null;
		public static EffectParameter me_alpha;
		public static EffectParameter me_lightFac;
		public static EffectParameter me_BloomVignette;
		public static EffectParameter me_floorVal;
		public static EffectParameter me_lightFacBloom;
		public static EffectParameter me_BaseIntensity;
		public static EffectParameter me_BaseSaturation;
		public static EffectParameter me_lightRedBlue;
		public static EffectParameter me_lightThresh;
		public static EffectParameter me_lightDesat;
		public static EffectParameter me_darkBlur;
		public static EffectParameter me_Dimensions;
		public static EffectParameter me_ditherMinPixel;
		public static Effect PrepareLayerTintSimplified(Player p, bool hasBloom, bool hasLight)
		{
			// No bloom has extra color correction
			Effect mainEffect;
			if (hasLight)
			{
				if (hasBloom)
					mainEffect = Game1_CreateTargs.mainEffectLightsBloom;
				else
					mainEffect = Game1_CreateTargs.mainEffectLightsNoBloom;
			}
			else
			{
				if (hasBloom)
					mainEffect = Game1_CreateTargs.mainEffectNoLightsBloom;
				else
					mainEffect = Game1_CreateTargs.mainEffectNoLightsNoBloom;
			}

			if (mainEffect != lastEffect)
			{
				lastEffect = mainEffect;
				me_alpha = mainEffect.Parameters["alpha"];
				me_lightFac = mainEffect.Parameters["lightFac"];
				me_BloomVignette = mainEffect.Parameters["BloomVignette"];
				me_floorVal = mainEffect.Parameters["floorVal"];
				me_lightFacBloom = mainEffect.Parameters["lightFacBloom"];
				me_BaseIntensity = mainEffect.Parameters["BaseIntensity"];
				me_BaseSaturation = mainEffect.Parameters["BaseSaturation"];
				me_lightRedBlue = mainEffect.Parameters["lightRedBlue"];
				me_lightThresh = mainEffect.Parameters["lightThresh"];
				me_lightDesat = mainEffect.Parameters["lightDesat"];
				me_darkBlur = mainEffect.Parameters["darkBlur"];
				me_Dimensions = mainEffect.Parameters["Dimensions"];
				me_ditherMinPixel = mainEffect.Parameters["ditherMinPixel"];
			}

			LayerTintCatalog.PrepareMainEffect(mainEffect, p.camMgr.curLayer, p.camMgr.prevLayer, p.camMgr.layerTransitionFrame, p);			
			me_alpha.SetValue(MapMgr.glowMgr.alpha);
			me_lightFac.SetValue(MapMgr.glowMgr.lightFac);
			me_BloomVignette.SetValue(BloomComponent.bloomVignette);
			me_floorVal.SetValue(BloomComponent.floorValue);
			me_lightFacBloom.SetValue(Math.Max(0.0f, BloomComponent.lightFac));
			me_BaseIntensity.SetValue(BloomComponent.bloomBase);
			me_BaseSaturation.SetValue(BloomComponent.baseSat);
			me_lightRedBlue.SetValue(new Vector2(BloomComponent.lightRed, -BloomComponent.lightBlue));
			me_lightThresh.SetValue(BloomComponent.lightThresh);
			me_lightDesat.SetValue(BloomComponent.lightDesat);
			me_darkBlur.SetValue(BloomComponent.darkBlur);
			me_Dimensions.SetValue(ScrollManager.screenSize / 8.0f);
			me_ditherMinPixel.SetValue(Game1_CreateTargs.ditherMinPixel);

			return mainEffect;
		}

		public static BlendState blendStateClearAlpha = null;
		public static BlendState blendStateBlood = null;
		public static void clearBloodDecalMask()
		{
			// On lowest graphical mode, disable blood
			if (VideoOptions__ctor.gfxPreset >= 4)
				return;

			if (blendStateClearAlpha == null)
			{
				blendStateClearAlpha = new BlendState
				{
					ColorSourceBlend = Blend.Zero,
					AlphaSourceBlend = Blend.Zero,
					ColorDestinationBlend = Blend.One,
					AlphaDestinationBlend = Blend.Zero
				};
			}

			SpriteTools.sprite.Begin(SpriteSortMode.Deferred, blendStateClearAlpha, null, null, null, Game1_CreateTargs.clearAlphaEffect);
			SpriteTools.sprite.Draw(Game1.nullTex, new Rectangle(0, 0, (int)ScrollManager.screenSize.X, (int)ScrollManager.screenSize.Y), Color.White);
			SpriteTools.End();
		}

		public static void drawBloodDecals(Player p, int i, int layer, int pLayer, float layerProg, int bloodLayer)
		{
			// On lowest graphical mode, disable blood
			if (VideoOptions__ctor.gfxPreset >= 4)
				return;

			if (blendStateBlood == null)
			{	
				blendStateBlood = new BlendState
				{
					ColorSourceBlend = Blend.DestinationAlpha,
					AlphaSourceBlend = Blend.Zero,
					ColorDestinationBlend = Blend.One,
					AlphaDestinationBlend = Blend.One,
					ColorBlendFunction = BlendFunction.ReverseSubtract
				};
			}

			Effect effect = Game1_CreateTargs.mapBloodEffect;
			effect.Parameters["bloodSat"].SetValue(LayerTintCatalog.layerTintData[pLayer].bloodSat + (LayerTintCatalog.layerTintData[layer].bloodSat - LayerTintCatalog.layerTintData[pLayer].bloodSat) * layerProg);
			if (bloodLayer == 0)
			{
				effect.Parameters["bloodAlpha"].SetValue(1f);
			}
			else
			{
				effect.Parameters["bloodAlpha"].SetValue(LayerTintCatalog.layerTintData[pLayer].bloodAlpha + (LayerTintCatalog.layerTintData[layer].bloodAlpha - LayerTintCatalog.layerTintData[pLayer].bloodAlpha) * layerProg);
			}

			SpriteTools.sprite.Begin(SpriteSortMode.Deferred, blendStateBlood, null, null, null, effect);
			for (int j = 0; j < MapBlood.bloodDrop.Length; j++)
			{
				// Skip a few blood droplets...
				if ((VideoOptions__ctor.gfxPreset >= 2) && ((j % 3) == 0))
					continue;

				if (MapBlood.bloodDrop[j].exists)
				{
					MapBlood.bloodDrop[j].Draw((i == 0) ? 0 : 1);
				}
			}
			SpriteTools.End();
		}

		public static void doSimpler(Player p, RenderTarget2D goalTarg, bool coopMode, GraphicsDevice GraphicsDevice)
		{
			Effect bloomTintEffect = Game1_CreateTargs.simplifiedTintBloomEffect;

			long ticks = DateTime.UtcNow.Ticks;
			GraphicsDevice.SetRenderTarget(GameDraw.sceneTarg);
			GraphicsDevice.Clear(Color.Black);

			// Check if our coop parter is indoors or not
			if (coopMode)
			{
				if (LayerTintCatalog.layerTintData[GameStateManager.GetMainPlayer().camMgr.curLayer].indoors)
				{
					p.camMgr.indoors = 0f;
				}
				else
				{
					p.camMgr.indoors = 1f;
				}
			}			

			// Flatten background passes into a single one, but gets rid of blood splatters of background.
			if (p.camMgr.indoors < 1f)
			{
				SpriteTools.BeginPMAlpha();
				// Instead of disabling entirely, we lower the amount of drawn background on the DrawBack patch.
				MapMgr.DrawBack(bloomTintEffect, 1f - p.camMgr.indoors, p);
				SpriteTools.End();

				// This layer gets coated in blood!
				clearBloodDecalMask();
				SpriteTools.BeginPMAlpha();
				MapMgr.DrawBloodBack(4, 1f - p.camMgr.indoors, bloomTintEffect, p);
				SpriteTools.End();
				
				drawBloodDecals(p, 1, p.camMgr.curLayer, p.camMgr.prevLayer, p.camMgr.layerTransitionFrame, 1);
				if (VideoOptions__ctor.gfxPreset < 3)
					MapMgr.DrawBackAdditives(p.camMgr.indoors, p.camMgr.prevLayer, p.camMgr.curLayer, p.camMgr.layerTransitionFrame);
			}
			if (p.camMgr.indoors > 0f)
			{
				SpriteTools.BeginPMAlpha();
				if (VideoOptions__ctor.gfxPreset < 4)
					MapMgr.DrawIndoorBack(bloomTintEffect, p.camMgr.indoors, p);
				SpriteTools.End();

				// This layer gets coated in blood!
				clearBloodDecalMask();
				SpriteTools.BeginPMAlpha();
				MapMgr.DrawBloodBack(14, p.camMgr.indoors, bloomTintEffect, p);
				SpriteTools.End();

				drawBloodDecals(p, 1, p.camMgr.curLayer, p.camMgr.prevLayer, p.camMgr.layerTransitionFrame, 1);
				if (VideoOptions__ctor.gfxPreset < 3)
					MapMgr.DrawBackAdditives(p.camMgr.indoors, p.camMgr.prevLayer, p.camMgr.curLayer, p.camMgr.layerTransitionFrame);
			}

			// Foreground rendering
			SpriteTools.BeginAlpha();
			MapMgr.sanctuaryMgr.DrawMapBack(p.camMgr.indoors);
			if (VideoOptions__ctor.gfxPreset < 3)
				p.camMgr.dotsMgr.DrawBack();
			SpriteTools.End();

			// Prepare for blood rendering
			clearBloodDecalMask();

			SpriteTools.BeginAlpha();
			if (p.camMgr.indoors < 1f)
			{
				MapMgr.map.Draw(5, 6, MapMgr.glowMgr, bloomTintEffect, 1f - p.camMgr.indoors, p);
			}
			if (p.camMgr.indoors > 0f)
			{
				MapMgr.map.Draw(15, 16, MapMgr.glowMgr, bloomTintEffect, p.camMgr.indoors, p);
			}
			SpriteTools.End();
			
			drawBloodDecals(p, 0, p.camMgr.curLayer, p.camMgr.prevLayer, p.camMgr.layerTransitionFrame, 0);

			MapMgr.DrawForeAdditives(p.camMgr.indoors, p.camMgr.curLayer, p.camMgr.prevLayer, p.camMgr.layerTransitionFrame);
			
			SpriteTools.BeginAlpha();
			ParticleManager.indoors = (p.camMgr.indoors > 0.9f);
			if (p.camMgr.indoors < 1f)
			{
				MapMgr.entityMgr.Draw(MapMgr.map, 5, 1f - p.camMgr.indoors);
			}
			if (p.camMgr.indoors > 0f)
			{
				MapMgr.entityMgr.Draw(MapMgr.map, 15, p.camMgr.indoors);
			}
			if (VideoOptions__ctor.gfxPreset < 3)
			{
				ParticleManager.Draw(1);
			}
			SmashMgr.Draw();
			MapMgr.sanctuaryMgr.Draw(p.camMgr.indoors);
			SpriteTools.End();
			if (VideoOptions__ctor.gfxPreset < 3)
			{
				SpriteTools.BeginSubtractive();
				ParticleManager.Draw(0);
				SpriteTools.End();
				SpriteTools.BeginAdditive();
				ParticleManager.Draw(2);
				SpriteTools.End();
			}
			SpriteTools.BeginAlpha();
			CharMgr.DrawSanctuaryChars();
			MapMgr.sanctuaryMgr.DrawFore(p.camMgr.indoors);
			CharMgr.Draw();
			ParticleManager.Draw(4);
			SpriteTools.End();
			SpriteTools.BeginSubtractive();
			ParticleManager.Draw(3);
			SpriteTools.End();
			SpriteTools.BeginAdditive();
			ParticleManager.Draw(5);
			SpriteTools.End();
			MapMgr.DrawPortals(p);
			Water.Draw();
			SpriteTools.BeginPMAlpha();
			if (p.camMgr.indoors < 1f)
			{
				MapMgr.DrawFore(bloomTintEffect, 1f - p.camMgr.indoors, p);
			}
			if (p.camMgr.indoors > 0f)
			{
				MapMgr.DrawIndoorFore(bloomTintEffect, p.camMgr.indoors, p);
			}
			SpriteTools.End();

			if (VideoOptions__ctor.gfxPreset < 3)
			{
				SpriteTools.BeginAlpha();
				p.camMgr.dotsMgr.DrawFore();
				SpriteTools.End();
			}

			// Choose and prepare the desired mainEffect
			Effect mainEffect = PrepareLayerTintSimplified(p, VideoOptions__ctor.gfxPreset == 1, MapMgr.glowMgr.alpha > 0f);

			// finalSceneTarg keeps track of where the final scene target ended up, we need this to create toastTarg.
			RenderTarget2D finalSceneTarg = GameDraw.sceneTarg;
			if (VideoOptions__ctor.gfxPreset == 1)
			{
				// We need an extra buffer if we want to perform the bloom pass...
				finalSceneTarg = GameDraw.auxTarg;
				GraphicsDevice.SetRenderTarget(finalSceneTarg);
			}
			else
			{
				GraphicsDevice.SetRenderTarget(goalTarg);
			}

			// Call the coalesced mainEffect + Light Combine pass, optionally applying color correction when blur pass is disabled
			// This choice happens on PrepareLayerTintSimplified
			SpriteTools.sprite.GraphicsDevice.Textures[1] = GameDraw.lightTarg;
			SpriteTools.sprite.GraphicsDevice.SamplerStates[1] = SamplerState.LinearClamp;
			SpriteTools.sprite.GraphicsDevice.Textures[2] = Game1_CreateTargs.bayerTex;
			SpriteTools.sprite.GraphicsDevice.SamplerStates[2] = SamplerState.PointWrap;
			SpriteTools.BeginOpaque(mainEffect);
			SpriteTools.sprite.Draw(GameDraw.sceneTarg, new Rectangle(0, 0, (int)ScrollManager.screenSize.X, (int)ScrollManager.screenSize.Y), Color.White);
			SpriteTools.End();
			SpriteTools.sprite.GraphicsDevice.Textures[1] = null;
			SpriteTools.sprite.GraphicsDevice.Textures[2] = null;

			// Do we really need the parchment effect???
			if (VideoOptions__ctor.gfxPreset < 3)
				LayerTintCatalog.Finalize(p.camMgr.curLayer, p.camMgr.prevLayer, p.camMgr.layerTransitionFrame, p);

			// If we need bossToast, prepare it.
			if (BossToast.needsTarg && BossToast.frame < 4f)
			{
				BloomComponent.Draw(BossToast.toastTarg, finalSceneTarg, GameDraw.lightTarg);
				if (MapMgr.glowMgr.alpha > 0f)
				{
					MapMgr.glowMgr.Draw(GameDraw.lightTarg);
				}
				BossToast.needsTarg = false;
			}

			// BloomComponent.Draw set our RenderTarget, we need to go back to goalTarg now.
			GraphicsDevice.SetRenderTarget(goalTarg);

			// Do blur pass if necessary
			// Draw boss death effects
			if (CharEffects.dyingBossMode)
			{
				GraphicsDevice.SetRenderTarget(GameDraw.backTarg);
				GraphicsDevice.Clear(new Color(0f, 0f, 0f, 1f));
				SpriteTools.BeginAlpha();
				CharMgr.DrawDyingBosses();
				SpriteTools.End();
				GraphicsDevice.SetRenderTarget(finalSceneTarg);
				CharEffects.DrawBlastTarg(CharEffects.dyingBossVal, GameDraw.sceneTarg, GameDraw.backTarg);
				BloomComponent.Draw(goalTarg, finalSceneTarg, GameDraw.lightTarg);
			}
			else if (VideoOptions__ctor.gfxPreset == 1)
			{
				BloomComponent.Draw(goalTarg, finalSceneTarg, GameDraw.lightTarg);
			}
			
			// Draw HUD
			SpriteTools.BeginAlpha();
			HUD.Draw(p);
			SpriteTools.End();

			// Draw boss toast if needed
			if (!BossToast.needsTarg && BossToast.active)
			{
				BossToast.Draw();
			}

			GameDraw.drawTicks = DateTime.UtcNow.Ticks - ticks;
		}
		

		public static bool Prefix(Player p, RenderTarget2D goalTarg, bool coopMode, GraphicsDevice GraphicsDevice)
		{
			// Normal rendering mode
			if (VideoOptions__ctor.gfxPreset == 0)
			{
				return true;
			}

			// Handle MenuSkillTree rendertargets
			if (p.dialog.menuMgr.active && (p.dialog.menuMgr.curLev == 6 || p.dialog.menuMgr.curLev == 7))
			{
				((MenuSkillTree)p.dialog.menuMgr.menuLevel[6]).Prepare(GraphicsDevice, p);
			}
			if (GameStateManager.coopPlayerIdx > -1 && !GameStateManager.splitScreenCoopMode)
			{
				Player coopPlayer = PlayerMgr.GetCoopPlayer();
				((MenuSkillTree)coopPlayer.dialog.menuMgr.menuLevel[6]).Prepare(GraphicsDevice, coopPlayer);
			}

			// Handle extra rendertargets
			if (SaltStatueMgr.needsSaltStatue)
			{
				SaltStatueMgr.ProcessSaltStatues(GraphicsDevice);
			}
			CharSequenceMgr.Prepare(GraphicsDevice);

			// We'll just use the previous frame... :)
			//Water.Update(MapMgr.GetMap().layer[5], 5, MapMgr.map, p);
			Water.Update(MapMgr.map.layer[5], 5, MapMgr.map, p);
			Water.Prepare(GameDraw.sceneTarg);

			// Prepare lightmaps
			MapMgr.glowMgr.alpha = LayerTintCatalog.layerTintData[p.camMgr.prevLayer].lightMap + (LayerTintCatalog.layerTintData[p.camMgr.curLayer].lightMap - LayerTintCatalog.layerTintData[p.camMgr.prevLayer].lightMap) * p.camMgr.layerTransitionFrame;
			if (MapMgr.glowMgr.alpha > 0f)
			{
				MapMgr.glowMgr.Prepare(Textures.tex[ParticleManager.spritesTexIdx], GameDraw.lightTarg);
			}
			else
			{
				GraphicsDevice.SetRenderTarget(GameDraw.lightTarg);
				GraphicsDevice.Clear(new Color(1f, 1f, 1f, 1f));
			}

			doSimpler(p, goalTarg, coopMode, GraphicsDevice);
			return false;
		}
		
		public static StringBuilder fpsStr;
		public static void Postfix(Player p, RenderTarget2D goalTarg, bool coopMode, GraphicsDevice GraphicsDevice)
		{
			if (fpsStr == null)
			{
				fpsStr = new StringBuilder("FPS: ");
			}
			SpriteTools.BeginAlpha();
			Text.DrawText(fpsStr, new Vector2(0, 16f), Color.White, 0.55f, 0);
			Text.DrawScore(DebugMgr.fps, new Vector2(0 + 100f, 16f), Color.White, 0.55f, 0);
			SpriteTools.End();
		}
	}

	// We want to scale the BossToast effect to actually fill the screen on any resolution
	[HarmonyPatch(typeof(BossToast), nameof(BossToast.Draw))]
	public class BossToast_Draw
	{
		public static bool Prefix()
		{
			float scaleX = ScrollManager.screenSize.X / 1280f;
			float scaleY = ScrollManager.screenSize.Y / 720f;
			float scale = (scaleX < scaleY) ? scaleX : scaleY;

			Effect mainEffect = GameDraw.mainEffect;

			float textHeight = 200f * scale;

			if (!BossToast.needsTarg && BossToast.toastTarg != null)
			{
				if (BossToast.frame <= 1f && BossToast.frame > 0.5f)
				{
					SpriteTools.BeginAdditive();
					float num = 1f;
					SpriteTools.sprite.Draw(BossToast.toastTarg, ScrollManager.screenSize / 2f, new Rectangle?(new Rectangle(0, 0, BossToast.toastTarg.Width, BossToast.toastTarg.Height)), new Color(1f, 1f, 1f, (BossToast.frame - 0.5f) * 2f), (4f - BossToast.frame) * 0.01f, new Vector2((float)BossToast.toastTarg.Width, (float)BossToast.toastTarg.Height) / 2f, (1.1f + (5f - BossToast.frame) * 0.03f) * num, SpriteEffects.None, 1f);
					SpriteTools.End();
				}
				if (BossToast.frame < 4f && BossToast.frame > 1f)
				{
					mainEffect.Parameters["tR"].SetValue(1f);
					mainEffect.Parameters["tG"].SetValue(0.95f);
					mainEffect.Parameters["tB"].SetValue(0.9f);
					mainEffect.Parameters["bR"].SetValue(0.8f);
					mainEffect.Parameters["bG"].SetValue(0.75f);
					mainEffect.Parameters["bB"].SetValue(0.7f);
					mainEffect.Parameters["brite"].SetValue(1.4f);
					mainEffect.Parameters["burnR"].SetValue(-1.4f);
					mainEffect.Parameters["burnG"].SetValue(-1.2f);
					mainEffect.Parameters["burnB"].SetValue(-1f);
					mainEffect.Parameters["gamma"].SetValue(-0.1f);
					float num2 = 1f;
					if (BossToast.frame < 1.5f)
					{
						num2 += Rand.GetRandomFloat(0f, 1.5f - BossToast.frame) * 0.1f;
					}
					SpriteTools.sprite.GraphicsDevice.Textures[1] = LayerTintCatalog.parchmentTex;
					SpriteTools.BeginAlpha(mainEffect);
					SpriteTools.sprite.Draw(BossToast.toastTarg, ScrollManager.screenSize / 2f, new Rectangle?(new Rectangle(0, 0, BossToast.toastTarg.Width, BossToast.toastTarg.Height)), new Color(1f, 1f, 1f, 1f), (4f - BossToast.frame) * 0.01f, new Vector2((float)BossToast.toastTarg.Width, (float)BossToast.toastTarg.Height) / 2f, (1.1f + (5f - BossToast.frame) * 0.03f) * num2, SpriteEffects.None, 1f);
					SpriteTools.End();
					SpriteTools.BeginSubtractive();
					Textures.tex[ParticleManager.spritesTexIdx].Draw(new Vector2(ScrollManager.screenSize.X / 2f, ScrollManager.screenSize.Y / 2f + textHeight), 0, new Vector2(16f, 2f) * scale, 0f, 1f, 1f, 1f, 0.5f);
					SpriteTools.End();
					SpriteTools.BeginAdditive();
					float num3 = (BossToast.frame - 3.5f) * 2f;
					if (num3 < 0.3f)
					{
						num3 = 0.3f;
					}
					num3 += Rand.GetRandomFloat(0f, 0.05f);
					if (BossToast.frame < 1.5f)
					{
						num3 += (1.5f - BossToast.frame) * 2f;
					}
					SpriteTools.End();
					LayerTintCatalog.DrawParchmentOnly();
					SpriteTools.BeginSubtractive();
					Textures.tex[LogoDraw.logoTexIdx].Draw(ScrollManager.screenSize / 2f + new Vector2(0f, textHeight), 14, new Vector2(1f, 1f) * 1.4f * num2 * scale, 3.1415927f, 1f, 1f, 1f, num3 * 0.4f);
					Textures.tex[LogoDraw.logoTexIdx].Draw(ScrollManager.screenSize / 2f + new Vector2(0f, textHeight), 13, new Vector2(1f, 1f) * num2 * scale, 0f, 1f, 1f, 1f, num3 * 0.4f);
					BossToast.DrawWisps();
					Vector2 vector = new Vector2(ScrollManager.screenSize.X / 2f, ScrollManager.screenSize.Y / 2f + textHeight);
					if (BossToast.title != null)
					{
						Text.DrawBigText(BossToast.title, vector, new Color(1f, 1f, 1f, 0.4f), 1f, 1);
					}
					SpriteTools.End();
					SpriteTools.BeginAdditive();
					SpriteTools.sprite.Draw(BossToast.toastTarg, ScrollManager.screenSize / 2f, new Rectangle?(new Rectangle(0, 0, BossToast.toastTarg.Width, BossToast.toastTarg.Height)), new Color(1f, 1f, 1f, num3), (4f - BossToast.frame) * 0.01f, new Vector2((float)BossToast.toastTarg.Width, (float)BossToast.toastTarg.Height) / 2f, 1.1f + (5f - BossToast.frame) * 0.03f, SpriteEffects.None, 1f);
					Textures.tex[LogoDraw.logoTexIdx].Draw(ScrollManager.screenSize / 2f + new Vector2(0f, 0f), 18, new Vector2(1f, 1f) * (1f + (4f - BossToast.frame) * 0.01f), BossToast.frame, 1f, 1f, 1f, num3 * 0.4f);
					Textures.tex[LogoDraw.logoTexIdx].Draw(ScrollManager.screenSize / 2f + new Vector2(0f, 0f), 10, new Vector2(1f, 1f) * (1f + (4f - BossToast.frame) * 0.01f), -BossToast.frame, 1f, 1f, 1f, num3 * 0.8f);
					Textures.tex[LogoDraw.logoTexIdx].Draw(ScrollManager.screenSize / 2f + new Vector2(0f, 0f), 11, new Vector2(1f, 1f) * (1f + (4f - BossToast.frame) * 0.01f), BossToast.frame / 2f, 1f, 1f, 1f, num3 * 0.5f);
					Textures.tex[LogoDraw.logoTexIdx].Draw(ScrollManager.screenSize / 2f + new Vector2(0f, 0f), 12, new Vector2(1f, 1f) * (1f + (4f - BossToast.frame) * 0.01f), 3.1415927f, 1f, 1f, 1f, num3 * 0.4f);
					Textures.tex[LogoDraw.logoTexIdx].Draw(ScrollManager.screenSize / 2f + new Vector2(0f, 0f), 12, new Vector2(1f, 1f) * (1f + (4f - BossToast.frame) * 0.01f), 3.1415927f + BossToast.frame * 0.1f, 1f, 1f, 1f, num3 * 0.4f);
					Textures.tex[LogoDraw.logoTexIdx].Draw(ScrollManager.screenSize / 2f + new Vector2(0f, textHeight), 13, new Vector2(1f, 1f) * scale, 0f, 1f, 1f, 1f, num3 * 2f);
					vector = new Vector2(ScrollManager.screenSize.X / 2f, ScrollManager.screenSize.Y / 2f + textHeight);
					if (Game1.language != 0)
					{
						vector.Y -= 32f;
						SpriteTools.sprite.Draw(InterfaceRender.interfaceTex, vector + new Vector2(0f, 35f), new Rectangle?(new Rectangle(640, 160, 128, 32)), new Color(0.6f, 0.6f, 0.6f, num3), 0f, new Vector2(60f, 16f) * scale, new Vector2(4f, 0.7f) * scale, SpriteEffects.None, 1f);
						Text.DrawText(BossToast.locTitle, vector + new Vector2(0f, 55f) * scale, new Color(1f, 1f, 1f, num3 * 1.2f), 0.7f * scale, 1);
					}
					Text.DrawText(BossToast.title, vector + new Vector2(-8f, -6f) * scale, new Color(1f, 1f, 1f, Rand.GetRandomFloat(0.3f, 0.4f)), 2f * scale, 1);
					Text.DrawBigText(BossToast.title, vector, new Color(1f, 1f, 1f, Rand.GetRandomFloat(0.3f, 0.4f)), 1f * scale, 1);
					SpriteTools.End();
				}
			}

			return false;
		}
	}

	// We want the obliterated words to be readable on all screen sizes, even the 480x320 OGA screens...
	[HarmonyPatch(typeof(GameStateManager), nameof(GameStateManager.DrawObliteratedWords))]
	public class GameStateManager_DrawObliteratedWords
	{
		public static bool Prefix(float frame)
		{
			float scaleX = ScrollManager.screenSize.X / 1280f;
			float scaleY = ScrollManager.screenSize.Y / 720f;
			float scale = (scaleX < scaleY) ? scaleX : scaleY;
			//float scale = ScrollManager.screenSize.Y / 720f;
			float prescale = 1.50f;
			float shiftY = (180f + (float)GameStateManager.obliteratedStr.Length * 40f) * prescale * scale;
			shiftY += 20f * prescale * scale;
			shiftY = shiftY - ScrollManager.screenSize.Y;
			if (shiftY < 0.0f)
				shiftY = 0.0f;

			if (GameStateManager.obliteratedStr != null)
			{
				for (int i = 0; i < GameStateManager.obliteratedStr.Length; i++)
				{
					float num = frame - ((float)i * 0.5f + 2.5f);
					if (i == GameStateManager.obliteratedStr.Length - 1 && i > 2)
					{
						num = frame - 4.5f;
					}
					num *= 2f;
					float num2 = num;
					if (num > 1f)
					{
						num = 1f;
					}
					if (frame > 8f)
					{
						num -= frame - 8f;
					}
					if (num2 > 5f)
					{
						num -= (num2 - 5f) * 0.25f;
					}
					if (num > 0f && GameStateManager.obliteratedStr[i] != null)
					{
						Vector2 loc = ScrollManager.totalScreenSize / 2f + new Vector2(0f, 180f - shiftY + (float)i * 40f) * scale;
						Textures.tex[ParticleManager.spritesTexIdx].Draw(loc, 0, new Vector2(5f, 0.7f) * scale, 0f, 0f, 0f, 0f, num * 0.5f);
						float num6 = 1f;
						if (i == 0 && GameStateManager.obliteratedStr.Length == 5)
						{
							num6 = 0f;
						}
						Text.DrawText(GameStateManager.obliteratedStr[i], loc, new Color(1f, num6, num6, num), 0.55f * prescale * scale, 1, ScrollManager.screenSize.X);
					}
				}
			}

			return false;
		}
	}

	// We want the game's intro ("Failing this mission would surely plunge us into darker days" etc)
	[HarmonyPatch(typeof(GameStateManager), nameof(GameStateManager.DrawWords))]
	public class GameStateManager_DrawWords
	{
		public static bool Prefix(int type, StringBuilder[][] wordsIntro1, int lines, float totalTime)
		{
			float num = ScrollManager.screenSize.X / 960f;
			float num2 = ScrollManager.screenSize.Y / 544f;
			float num3 = (num < num2) ? num : num2;
			float num4 = 1f;
			if (type == 0)
			{
				float num5 = GameStateManager.wordsFrame - (totalTime - 1f);
				if (num5 < 0f)
				{
					num5 = 0f;
				}
				float num6 = GameStateManager.wordsFrame / 4f;
				if (num6 > 1f)
				{
					num6 = 1f;
				}
				SpriteTools.sprite.Draw(Game1.nullTex, new Rectangle(0, 0, (int)ScrollManager.totalScreenSize.X, (int)ScrollManager.totalScreenSize.Y), new Color(num5, num5, num5, num6));
			}
			if (type == 1)
			{
				float num7 = GameStateManager.wordsFrame / 4f;
				if (num7 > 1f)
				{
					num7 = 1f;
					float num8 = (totalTime - GameStateManager.wordsFrame) / 4f;
					if (num8 < 0f)
					{
						num8 = 0f;
					}
					num7 *= num8;
				}
				num4 = 0f;
				SpriteTools.sprite.Draw(Game1.nullTex, new Rectangle(0, 0, (int)ScrollManager.totalScreenSize.X, (int)ScrollManager.totalScreenSize.Y), new Color(1f, 1f, 1f, num7));
			}
			float num9 = totalTime - GameStateManager.wordsFrame;
			if (num9 > 1f)
			{
				float num10 = (float)lines + 0.5f;
				for (int i = 0; i < lines; i++)
				{
					num10 += (float)wordsIntro1[i].Length;
				}
				float num11 = 0f;
				for (int j = 0; j < lines; j++)
				{
					float num12 = (num9 - 1f - (float)j * 4f) * 0.35f;
					if (num12 > 0f)
					{
						if (j == lines - 1 && GameStateManager.wordsMode == 0)
						{
							if (GameStateManager.wordsFrame < 5f)
							{
								num12 = GameStateManager.wordsFrame / 5f;
							}
						}
						else if (num12 > 2f)
						{
							num12 = 3f - num12;
						}
						if (num12 > 1f)
						{
							num12 = 1f;
						}
						float num13 = 1f;
						for (int k = 0; k < wordsIntro1[j].Length; k++)
						{
							if (num12 > 0f)
							{
								Text.DrawText(wordsIntro1[j][k], new Vector2(16f, (1.5f + num11) * 32f) * num3, new Color(num4, num4, num4, num12), 1f * num13 * num3, 0);
							}
							num11 += 1f;
						}
						num11 += 2f;
					}
				}
			}
			if (GameStateManager.wordsExitFrame > 1f && GameStateManager.wordsExitFrame < 4f)
			{
				float num14 = 0f;
				if (GameStateManager.wordsExitFrame < 2f)
				{
					num14 = GameStateManager.wordsExitFrame - 1f;
				}
				else if (GameStateManager.wordsExitFrame == 2f)
				{
					num14 = 1f;
				}
				else if (GameStateManager.wordsExitFrame < 4f)
				{
					num14 = 4f - GameStateManager.wordsExitFrame;
				}
				if (num14 > 0f)
				{
					Text.DrawText(GameStateManager.wordsExitStr[1], ScrollManager.screenSize - new Vector2(80f, 80f) * num3, new Color(num4, num4, num4, num14), 0.6f * num3, 2, null, 1);
					Text.DrawText(GameStateManager.wordsExitStr[0], ScrollManager.screenSize - new Vector2(80f + Text.GetStringSpace(GameStateManager.wordsExitStr[1], 0.48000002f, null, 1) + 12f, 80f) * num3, new Color(1f, 1f, 1f, num14), 0.6f * num3, 2, null, 1);
				}
			}

			return false;
		}
	}

	// Make the boss HUD and stuff consistent across screen resolutions
	[HarmonyPatch(typeof(HUD), nameof(HUD.DrawBossHUD))]
	public class HUD_DrawBossHUD
	{
		public static bool Prefix()
		{
			if (!DebugMgr.hudMode)
			{
				return false;
			}
			if (GameStateManager.wordsFrame > 0f)
			{
				return false;
			}
			if (GameStateManager.uberDeadFrame <= 0f && BossToast.confirmedOkay)
			{
				Character mainCharacter = GameStateManager.GetMainCharacter();
				if (mainCharacter != null)
				{
					int arenaIdx = MapMgr.map.triggerMgr.GetArenaIdx(mainCharacter);
					if (arenaIdx < 0 && GameStateManager.coopPlayerIdx > -1)
					{
						Player coopPlayer = PlayerMgr.GetCoopPlayer();
						if (coopPlayer != null)
						{
							Character playerCharacter = CharMgr.GetPlayerCharacter(coopPlayer);
							if (playerCharacter != null)
							{
								arenaIdx = MapMgr.map.triggerMgr.GetArenaIdx(playerCharacter);
							}
						}
					}
					if (arenaIdx > -1)
					{
						int arenaBossCount = MapMgr.map.triggerMgr.GetArenaBossCount(arenaIdx);
						int num = 0;
						for (int i = 0; i < arenaBossCount; i++)
						{
							int arenaBossIdx = MapMgr.map.triggerMgr.GetArenaBossIdx(arenaIdx, i);
							if (arenaBossIdx > -1 && !BossToast.active)
							{
								Character boss = CharMgr.character[arenaBossIdx];
								if (MonsterCatalog.catalog[boss.monsterIdx].ai != 32 && (num <= 0 || (MonsterCatalog.catalog[boss.monsterIdx].ai != 34 && MonsterCatalog.catalog[boss.monsterIdx].ai != 32 && MonsterCatalog.catalog[boss.monsterIdx].ai != 33)))
								{
									if (!boss.aggrod)
									{
										boss.Aggro(false);
									}

									float scale = ScrollManager.screenSize.Y / 720f;

									float arrowSep = 10f * scale;
									float arrowSepVert = 85f * scale;

									float hpWidth = 800f * scale;
									float bossHp = boss.hp;
									float bossgHP = boss.update.gHP;
									float maxHP = boss.stats.GetMaxHP();
									float barHeight = 14f * scale;
									float barY = 80f * scale;

									if (!boss.boss)
									{
										bossHp = 0f;
										bossgHP = 0f;
									}
									
									float posY = ScrollManager.totalScreenSize.Y - 260f * scale;
									posY -= (float)num * 30f * scale;

									InterfaceRender.DrawArrow(new Vector2(ScrollManager.totalScreenSize.X / 2f - hpWidth / 2f - arrowSep, posY + arrowSepVert), 0, 0.5f, 1.5f * scale);
									InterfaceRender.DrawArrow(new Vector2(ScrollManager.totalScreenSize.X / 2f + hpWidth / 2f + arrowSep, posY + arrowSepVert), 1, 0.5f, 1.5f * scale);
									InterfaceRender.DrawStatusBar(new Vector2(ScrollManager.totalScreenSize.X / 2f - hpWidth / 2f, posY + barY), new Vector2(hpWidth, barHeight), bossHp / maxHP * hpWidth, bossgHP / maxHP * hpWidth, 0.9f, 0.2f, 0.2f, 1f, 1f, true);
									MonsterDef monsterDef = MonsterCatalog.catalog[boss.monsterIdx];
									if (monsterDef.titleStr == null)
									{
										monsterDef.titleStr = new StringBuilder(monsterDef.title[0]);
									}
									if (PlayerMgr.IsSaltCharacter(boss))
									{
										InterfaceRender.DrawArrow(new Vector2(ScrollManager.totalScreenSize.X / 2f - hpWidth / 2f, posY + barY) + new Vector2(hpWidth * 0.75f, 26f), 2, 1f);
										InterfaceRender.DrawArrow(new Vector2(ScrollManager.totalScreenSize.X / 2f - hpWidth / 2f, posY + barY) + new Vector2(hpWidth * 0.75f, -12f), 3, 1f);
									}
									num++;
								}
							}
						}
					}
				}
			}

			return false;
		}
	}

	// Be cheeky and make all bounded text become as large as can be
	[HarmonyPatch(typeof(Text), nameof(Text.DrawText))]
	[HarmonyPatch(new Type[] { typeof(StringBuilder), typeof(Vector2), typeof(Color), typeof(float), typeof(int), typeof(float), typeof(Player), typeof(int) })]
	public class Text_DrawText
	{
		public static bool Prefix(StringBuilder s, Vector2 loc, Color color, ref float size, int align, float maxLen, Player p, int replaceIcons)
		{
			size *= 1.20f;
			return true;
		}
	}

	// We want to give an upper bound to the RG552 screen resolution since we don't
	// have enough fillrate for full 1920x1152. Ooof
	[HarmonyPatch(typeof(VideoOptions), nameof(VideoOptions.GetResolutions))]
	public class VideoOptions_GetResolutions
	{
		public static bool Prefix(GraphicsDevice dev, ref List<Point> __result)
		{
			List<Point> list = new List<Point>();
			foreach (DisplayMode displayMode in dev.Adapter.SupportedDisplayModes)
			{
				// Ensure no silly modes, we only guarantee 480x320 and above.
				if (displayMode.Width < 480 || displayMode.Height < 320)
					continue;

				// RG552 won't handle this game at full-res, force half-res instead
				if (displayMode.Width == 1920 && displayMode.Height == 1152)
				{
					list.Add(new Point(960, 576));
				}
				else
				{
					list.Add(new Point(displayMode.Width, displayMode.Height));
				}
			}

			// We somehow failed to get _ANY_ video mode, add the smallest mode
			// we know that is okay.
			if (list.Count == 0)
			{
				list.Add(new Point(480, 320));
			}

			__result = list;
			return false;
		}
	}

	// On smaller displays, we want to use less words per dialogue to make the
	// text considerably bigger, otherwise it can be hard to read. This is
	// one part of the complete process.
	[HarmonyPatch(typeof(PlayerDialog), nameof(PlayerDialog.SetDialog))]
	public class PlayerDialog_SetDialog
	{
		public static bool Prefix(PlayerDialog __instance, string[] dialog)
		{
			int words = 70;
			if (ScrollManager.screenSize.Y <= 480f)
			{
				words = 50;
			}

			__instance.dialogStr = new StringBuilder[dialog.Length][];
			for (int i = 0; i < dialog.Length; i++)
			{
				__instance.dialogStr[i] = WordWrap.Wrap(__instance.p, dialog[i], words, 1);
			}
			__instance.dialogTextIdx = 0;
			__instance.dialogFrame = 0f;

			return false;
		}
	}

	// We want to actually scale the dialogue to fit the entire display. This is
	// the second part of the patch started on PlayerDialog_SetDialog
	[HarmonyPatch(typeof(PlayerDialog), nameof(PlayerDialog.Draw))]
	public class PlayerDialog_Draw
	{
		public static bool Prefix(PlayerDialog __instance, float scale)
		{
			float textScale = 1f;
			float textScaleSpace = 0.48000002f;
			if (ScrollManager.screenSize.Y <= 480f)
			{
				float scaleX = ScrollManager.screenSize.X / 736f;
				float scaleY = ScrollManager.screenSize.Y / 414f;
				scale = ((scaleX < scaleY) ? scaleX : scaleY);
				textScale = 1.25f;
				textScaleSpace *= textScale;
			}

			if (__instance.dialogStr != null && __instance.dialogStr.Length > __instance.dialogTextIdx)
			{
				float num;
				if (__instance.dialogFrame < 0.2f)
				{
					num = __instance.dialogFrame * 5f;
				}
				else if (__instance.dialogFrame < 4.8f)
				{
					num = 1f;
				}
				else
				{
					num = (5f - __instance.dialogFrame) * 5f;
				}
				float num2 = 0f;
				for (int i = 0; i < __instance.dialogStr[__instance.dialogTextIdx].Length; i++)
				{
					float stringSpace = Text.GetStringSpace(__instance.dialogStr[__instance.dialogTextIdx][i], textScaleSpace, __instance.p, 0);
					if (stringSpace > num2)
					{
						num2 = stringSpace;
					}
				}
				int y = (int)(ScrollManager.screenSize.Y * 0.35f - (float)__instance.dialogStr[__instance.dialogTextIdx].Length * 32f * scale);
				Rectangle rectangle = new Rectangle((int)ScrollManager.screenSize.X / 2 - (int)((num2 / 2f - 24f) * scale), y, (int)((num2 + 48f) * scale), (int)(((float)__instance.dialogStr[__instance.dialogTextIdx].Length * 32f + 32f) * scale));
				int num3 = 0;
				if (GameStateManager.coopPlayerIdx > -1 && !GameStateManager.splitScreenCoopMode)
				{
					if (__instance.p.ID == GameStateManager.mainPlayerIdx)
					{
						num3 -= (int)(ScrollManager.screenSize.X / 4f);
					}
					else
					{
						num3 += (int)(ScrollManager.screenSize.X / 4f);
					}
				}
				rectangle.X += num3;
				if (ScrollManager.screenSize.X <= 960f)
				{
					rectangle.X = (int)(ScrollManager.screenSize.X / 2f) - rectangle.Width / 2;
				}
				else
				{
					if (rectangle.X < 80)
					{
						num3 -= rectangle.X - 80;
						rectangle.X = 80;
					}
					if ((float)rectangle.Right > ScrollManager.screenSize.X - 80f)
					{
						num3 -= rectangle.Right - ((int)ScrollManager.screenSize.X - 80);
						rectangle.X -= rectangle.Right - ((int)ScrollManager.screenSize.X - 80);
					}
				}
				InterfaceRender.DrawRect(rectangle, num * 0.5f);
				for (int j = 0; j < __instance.dialogStr[__instance.dialogTextIdx].Length; j++)
				{
					Text.DrawText(__instance.dialogStr[__instance.dialogTextIdx][j], new Vector2((float)rectangle.Center.X, (float)rectangle.Y + ((float)j * 32f + 28f) * scale), new Color(1f, 1f, 1f, num), 0.6f * textScale * scale, 1);
				}
				Text.DrawText(InterfaceRender.CHAR_A, new Vector2((float)rectangle.Right - 32f * scale, (float)rectangle.Bottom), new Color(1f, 1f, 1f, num), 0.6f * textScale * scale, 1, __instance.p, 4);
			}
			if (__instance.menuMgr.active)
			{
				__instance.menuMgr.Draw(scale);
			}
			if (GameStateManager.coopPlayerIdx == __instance.p.ID)
			{
				Player mainPlayer = PlayerMgr.GetMainPlayer();
				if (mainPlayer.dialog.menuMgr.active && mainPlayer.dialog.menuMgr.curLev == 19)
				{
					((HireMenu)mainPlayer.dialog.menuMgr.menuLevel[19]).Draw(__instance.p, scale);
				}
			}

			return false;
		}
	}

	// Pre-scale HUD size to limit height to 544p
	[HarmonyPatch(typeof(PlayerDraw), nameof(PlayerDraw.Update))]
	public class PlayerDraw_Update
	{
		public static float GetScale()
		{
			return (float)ScrollManager.screenSize.Y / 544f;
		}

		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			var codes = new List<CodeInstruction>(instructions);
			int p = 0;
			for (int i = 0; i < codes.Count-4; i++)
			{
				if (
					codes[i].opcode   == OpCodes.Ldc_R4  && (float)codes[i].operand == 1.0 &&
					codes[i+1].opcode == OpCodes.Ldsfld  && codes[i+1].operand.ToString().Contains("hudSize") &&
					codes[i+2].opcode == OpCodes.Conv_R4 &&
					codes[i+3].opcode == OpCodes.Ldc_R4
				)
				{
					List<CodeInstruction> newCodes = new List<CodeInstruction>();
					newCodes.Add(new CodeInstruction(OpCodes.Ldloc_0));
					newCodes.Add(new CodeInstruction(OpCodes.Call, ((Func<float>) PlayerDraw_Update.GetScale).Method));
					newCodes.Add(new CodeInstruction(OpCodes.Mul));
					newCodes.Add(new CodeInstruction(OpCodes.Stloc_0));
					Console.WriteLine($"Patched PlayerDraw at PlayerDraw:Update+{i+8}!");
					p = i - 5;
					codes.InsertRange(i+8, newCodes);
					break;
				}
			}
			
			//for (int i = p; i < p+20; i++)
			//{
			//    Console.WriteLine($"PlayerDraw:Update+{i:000}: {codes[i].ToString()}");
			//}
			
			return codes.AsEnumerable();
		}
	}

	// Make the area title transitions display size consistent across all display resolutions 
	[HarmonyPatch(typeof(PlayerDrawOverlays), nameof(PlayerDrawOverlays.DrawZoneTransition))]
	public class PlayerDrawOverlays_DrawZoneTransition 
	{
		public static bool Prefix(PlayerDrawOverlays __instance, Vector2 bR)
		{
			float scaleX = ScrollManager.screenSize.X / 1280f;
			float scaleY = ScrollManager.screenSize.Y / 720f;
			float scale = (scaleX < scaleY) ? scaleX : scaleY;
			float areaTextY = 200f * scale;
			float areaTextY2 = 300f * scale;

			if (__instance.p.zoneEnterFrame > 0f)
			{
				float num;
				if (__instance.p.zoneEnterFrame > 2.5f)
				{
					num = (3f - __instance.p.zoneEnterFrame) * 2f;
				}
				else if (__instance.p.zoneEnterFrame > 1f)
				{
					num = 1f;
				}
				else
				{
					num = __instance.p.zoneEnterFrame;
				}
				Vector2 vector = new Vector2(ScrollManager.screenSize.X / 2f, bR.Y - areaTextY);
				float num2 = 1f * scale;
				int areaIndexFromSpriteFlags = AreaCatalog.GetAreaIndexFromSpriteFlags(__instance.p.zoneEnter);
				if (__instance.p.zoneEnterFirstTime)
				{
					vector.Y = areaTextY2;
					Textures.tex[ParticleManager.spritesTexIdx].Draw(vector, 0, new Vector2(8f, 1.5f) * scale, 0f, 0f, 0f, 0f, num * 0.25f);
					Textures.tex[LogoDraw.logoTexIdx].DrawFlipped(vector, 14, new Vector2(1f, 1f) * (1f + (3f - __instance.p.zoneEnterFrame) * 0.06f) * 0.5f * num2, 0f, 0f, 0f, 0f, num * 0.1f);
					SpriteTools.End();
					SpriteTools.BeginAdditive();
					Textures.tex[LogoDraw.logoTexIdx].Draw(vector, 13, new Vector2(1f, 1f) * (1f + (3f - __instance.p.zoneEnterFrame) * 0.05f) * 0.8f * num2, 0f, 1f, 1f, 1f, num * 0.45f);
					Textures.tex[LogoDraw.logoTexIdx].Draw(vector, 14, new Vector2(1f, 1f) * (1f + (3f - __instance.p.zoneEnterFrame) * 0.06f) * 0.5f * num2, 3.1415927f, 1f, 1f, 1f, num * 0.125f);
					if (Game1.language != 0)
					{
						vector.Y -= 32f;
						SpriteTools.sprite.Draw(InterfaceRender.interfaceTex, vector + new Vector2(0f, 40f) * scale, new Rectangle?(new Rectangle(640, 160, 128, 32)), new Color(0.6f, 0.6f, 0.6f, num), 0f, new Vector2(60f, 16f), new Vector2(4f, 0.7f) * num2, SpriteEffects.None, 1f);
						Text.DrawText(AreaCatalog.parenAreaStr[areaIndexFromSpriteFlags], vector + new Vector2(0f, 60f) * scale, new Color(0.9f, 0.9f, 0.9f, num), 0.75f * num2, 1);
					}
					Text.DrawBigText(AreaCatalog.engStr[areaIndexFromSpriteFlags], vector, new Color(1f, 1f, 1f, num), 1f * num2, 1);
					SpriteTools.End();
					SpriteTools.BeginAlpha();
					return false;
				}
				Textures.tex[LogoDraw.logoTexIdx].Draw(vector, 13, new Vector2(1f, 1f) * (1f + (3f - __instance.p.zoneEnterFrame) * 0.05f) * 0.8f * num2, 0f, 1f, 1f, 1f, num * 0.5f);
				SpriteTools.End();
				SpriteTools.BeginAdditive();
				if (Game1.language != 0)
				{
					vector.Y -= 32f;
					SpriteTools.sprite.Draw(InterfaceRender.interfaceTex, vector + new Vector2(0f, 35f) * scale, new Rectangle?(new Rectangle(640, 160, 128, 32)), new Color(0.6f, 0.6f, 0.6f, num), 0f, new Vector2(60f, 16f), new Vector2(4f, 0.7f) * num2, SpriteEffects.None, 1f);
					Text.DrawText(AreaCatalog.parenAreaStr[areaIndexFromSpriteFlags], vector + new Vector2(0f, 55f) * scale, new Color(0.9f, 0.9f, 0.9f, num), 0.7f * num2, 1);
				}
				Text.DrawBigText(AreaCatalog.engStr[areaIndexFromSpriteFlags], vector, new Color(1f, 1f, 1f, num), 0.8f * num2, 1);
				SpriteTools.End();
				SpriteTools.BeginAlpha();
			}

			return false;
		}
	}

	// Rework player inventory to fill the screen as much as possible 
	[HarmonyPatch(typeof(PlayerInv), nameof(PlayerInv.Draw))]
	public class PlayerInv_Draw
	{
		public static bool Prefix(PlayerInv __instance, float scale)
		{
			float WidthTotal = 280f + 520f;
			float HeightTotal = 450f;
			float offsX = 140f;
			if (PlayerStats_Draw.isBestiary(__instance.p))
			{
				float alphaN = 1f - __instance.alpha;
				WidthTotal -= 280f * alphaN;
				HeightTotal -= 60f * alphaN;
				offsX += 120f * alphaN;
			}

			Character playerCharacter = CharMgr.GetPlayerCharacter(__instance.p);
			float scaleX = ScrollManager.screenSize.X / WidthTotal;
			float scaleY = ScrollManager.screenSize.Y / 480f;
			scale = (scaleX < scaleY) ? scaleX : scaleY;

			if (playerCharacter != null)
			{
				if (__instance.invPicker.category != 7 && __instance.invPicker.category != 21 && __instance.invPicker.category != 8 && __instance.invPicker.category != 18 && __instance.invPicker.category != 23 && __instance.invPicker.category != 24 && __instance.invPicker.category != 27)
				{
					int category3 = __instance.invPicker.category;
				}
				Rectangle rectangle = new Rectangle((int)(ScrollManager.screenSize.X / 2f - offsX * scale), (int)ScrollManager.screenSize.Y / 2 - (int)(225f * scale), 520, 400);
				if (GameStateManager.coopPlayerIdx > -1)
				{
					if (GameStateManager.splitScreenCoopMode)
					{
						rectangle.X -= 140;
					}
					else
					{
						if (__instance.p.ID == GameStateManager.mainPlayerIdx)
						{
							rectangle.X -= (int)(ScrollManager.totalScreenSize.X * 0.5f);
						}
						rectangle.X += (int)(ScrollManager.totalScreenSize.X * 0.19f);
						if (__instance.p.ID == GameStateManager.coopPlayerIdx)
						{
							rectangle.X -= (int)(ScrollManager.totalScreenSize.X * 0.03f);
						}
					}
				}
				rectangle.Width = (int)((float)rectangle.Width * scale);
				rectangle.Height = (int)((float)rectangle.Height * scale);
				InterfaceRender.DrawRect(new Rectangle(rectangle.X, rectangle.Bottom + (int)(5f * scale), rectangle.Width, (int)(50f * scale)), __instance.alpha * 0.7f, 4);
				if (!__instance.invPicker.active)
				{
					int num = 79;
					int category2 = __instance.selItem;
					if (category2 - 26 > 2)
					{
						num = 160;
					}
					Text.DrawText(InvPicker.strs[num], new Vector2((float)rectangle.X + 20f * scale, (float)rectangle.Bottom + 30f * scale), new Color(1f, 1f, 1f, __instance.alpha), 0.45f * scale, 0, 160f * scale, __instance.p, 1);
					if (!__instance.invPicker.active && __instance.selCategory == 0)
					{
						__instance.invPicker.category = 0;
					}
					category2 = __instance.invPicker.category;
					if (category2 - 7 > 1)
					{
						switch (category2)
						{
						case 18:
						case 21:
						case 25:
							goto IL_4C8;
						case 23:
						case 24:
						case 27:
							Text.DrawText(InvPicker.strs[81], new Vector2((float)rectangle.X + 190f * scale, (float)rectangle.Bottom + 30f * scale), new Color(1f, 1f, 1f, __instance.alpha), 0.45f * scale, 0, 160f * scale, __instance.p, 1);
							goto IL_4C8;
						}
						int num2 = (__instance.catAlpha[0] > 0f) ? 80 : 81;
						if (__instance.selCategory == 0)
						{
							if (__instance.selItem == 5 || __instance.selItem == 8)
							{
								if (playerCharacter.equipment.loadout[(__instance.selItem == 5) ? 0 : 1, 1].catalogIdx > -1)
								{
									if (playerCharacter.equipment.loadout[(__instance.selItem == 5) ? 0 : 1, 1].catalogIdx < 128 && playerCharacter.equipment.loadout[(__instance.selItem == 5) ? 0 : 1, 1].catalogIdx < LootCatalog.category[1].loot.Length && playerCharacter.equipment.loadout[(__instance.selItem == 5) ? 0 : 1, 1].category == 1 && LootCatalog.category[1].loot[playerCharacter.equipment.loadout[(__instance.selItem == 5) ? 0 : 1, 1].catalogIdx].type == 4)
									{
										num2 = 155;
									}
								}
								else
								{
									num2 = 155;
								}
							}
							if (num2 != 155 && __instance.invEquip.GetLootFromEquipItem(playerCharacter, __instance.selItem) == null)
							{
								num2 = -1;
							}
						}
						if (num2 > -1)
						{
							Text.DrawText(InvPicker.strs[num2], new Vector2((float)rectangle.X + 190f * scale, (float)rectangle.Bottom + 30f * scale), new Color(1f, 1f, 1f, __instance.alpha), 0.45f * scale, 0, 160f * scale, __instance.p, 1);
						}
					}
					IL_4C8:
					Text.DrawText(InvPicker.strs[82], new Vector2((float)rectangle.X + 360f * scale, (float)rectangle.Bottom + 30f * scale), new Color(1f, 1f, 1f, __instance.alpha), 0.45f * scale, 0, 160f * scale, __instance.p, 1);
				}
				InterfaceRender.DrawRect(rectangle, __instance.alpha * 0.7f, 4);
				if (__instance.selCategory == 0)
				{
					__instance.invEquip.DrawEquipCategory(playerCharacter, rectangle, __instance.alpha, scale);
				}
				if (__instance.invPicker.alpha > 0f)
				{
					__instance.invPicker.Draw(scale, rectangle);
				}
				if (__instance.p.stats.alpha > 0f)
				{
					float num3 = __instance.p.stats.alpha;
					if (GameStateManager.coopPlayerIdx > -1)
					{
						if (__instance.p.playerInv.invPicker.category == 26)
						{
							if (__instance.p.menuMgr.curLev == 35)
							{
								num3 -= __instance.p.menuMgr.menuLevel[__instance.p.menuMgr.curLev].alpha;
							}
							if (__instance.p.menuMgr.curLev == 36 || __instance.p.menuMgr.curLev == 38 || __instance.p.menuMgr.curLev == 39)
							{
								num3 = 0f;
							}
						}
					}
					else if (__instance.p.playerInv.invPicker.category == 26 && __instance.p.menuMgr.curLev == 31)
					{
						num3 -= __instance.p.menuMgr.menuLevel[__instance.p.menuMgr.curLev].alpha;
					}
					rectangle.X += (int)(__instance.invPicker.alpha * 10f) - 5;
					__instance.p.stats.Draw(num3, scale, rectangle, 0);
				}
			}

			return false;
		}
	}

	public class LimitRectangle
	{
		public static void MakeInsideLeft(ref Rectangle r)
		{
			if (r.X < 0)
				r.X = 0;
		}

		public static void MakeInsideRight(ref Rectangle r)
		{
			int offscreenX = r.X + r.Width - (int)ScrollManager.screenSize.X;
			offscreenX += 10;
			if (offscreenX > 0)
			{
				r.X -= offscreenX;
			}
		}

		public static int makeDescriptionSize()
		{
			if (ScrollManager.screenSize.Y <= 480f)
			{
				return 16;
			}

			return 22;
		}

		public static float makeDescriptionDimensions()
		{
			if (ScrollManager.screenSize.Y <= 480f)
			{
				return 0.60f;
			}

			return 0.50f;
		}

		public static void makeNewScale(ref float scale)
		{
			if (ScrollManager.screenSize.Y <= 480f)
			{
				scale *= 1.25f;
			}
		}
	}

	// Fix for out-of-bounds Stats screen during Skill Point Allocation
	[HarmonyPatch(typeof(PlayerStats), nameof(PlayerStats.Draw))]
	public class PlayerStats_Draw
	{
		public static bool wasBestiary = false;
		public static bool isBestiary(Player p)
		{
			bool wasBestiaryBefore = wasBestiary;
			bool isBestiaryNow = p.playerInv.invPicker.category == 26;
			wasBestiary = isBestiaryNow;
			return wasBestiaryBefore || isBestiaryNow;
		}

		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions, ILGenerator il)
		{
			var codes = new List<CodeInstruction>(instructions);
			for (int i = 0; i < codes.Count-4; i++)
			{
				if (
					codes[i].opcode    == OpCodes.Ldloca_S  &&                                                        // PlayerStats:Draw+037: ldloca.s 1 (Microsoft.Xna.Framework.Rectangle)
					codes[i+1].opcode  == OpCodes.Ldloc_1   &&                                                        // PlayerStats:Draw+038: ldloc.1 NULL
					codes[i+2].opcode  == OpCodes.Ldfld     && codes[i+2].operand.ToString().Contains("Width") &&     // PlayerStats:Draw+039: ldfld System.Int32 Microsoft.Xna.Framework.Rectangle::Width
					codes[i+3].opcode  == OpCodes.Conv_R4   &&                                                        // PlayerStats:Draw+040: conv.r4 NULL
					codes[i+4].opcode  == OpCodes.Ldarg_2   &&                                                        // PlayerStats:Draw+041: ldarg.2 NULL
					codes[i+5].opcode  == OpCodes.Mul       &&                                                        // PlayerStats:Draw+042: mul NULL
					codes[i+6].opcode  == OpCodes.Conv_I4   &&                                                        // PlayerStats:Draw+043: conv.i4 NULL
					codes[i+7].opcode  == OpCodes.Stfld     && codes[i+7].operand.ToString().Contains("Width") &&     // PlayerStats:Draw+044: stfld System.Int32 Microsoft.Xna.Framework.Rectangle::Width
					codes[i+8].opcode  == OpCodes.Ldloca_S  &&                                                        // PlayerStats:Draw+045: ldloca.s 1 (Microsoft.Xna.Framework.Rectangle)
					codes[i+9].opcode  == OpCodes.Ldloc_1   &&                                                        // PlayerStats:Draw+046: ldloc.1 NULL
					codes[i+10].opcode == OpCodes.Ldfld     && codes[i+10].operand.ToString().Contains("Height") &&   // PlayerStats:Draw+047: ldfld System.Int32 Microsoft.Xna.Framework.Rectangle::Height
					codes[i+11].opcode == OpCodes.Conv_R4   &&                                                        // PlayerStats:Draw+048: conv.r4 NULL
					codes[i+12].opcode == OpCodes.Ldarg_2   &&                                                        // PlayerStats:Draw+049: ldarg.2 NULL
					codes[i+13].opcode == OpCodes.Mul       &&                                                        // PlayerStats:Draw+050: mul NULL
					codes[i+14].opcode == OpCodes.Conv_I4   &&                                                        // PlayerStats:Draw+051: conv.i4 NULL
					codes[i+15].opcode == OpCodes.Stfld     && codes[i+15].operand.ToString().Contains("Height")      // PlayerStats:Draw+052: stfld System.Int32 Microsoft.Xna.Framework.Rectangle::Height
				)
				{
					MethodInfo makeInsideLeftMethod = typeof(LimitRectangle).GetMethod("MakeInsideLeft", BindingFlags.Public | BindingFlags.Static);
					List<CodeInstruction> newCodes = new List<CodeInstruction>();
					newCodes.Add(new CodeInstruction(OpCodes.Ldloca_S, 1));
					newCodes.Add(new CodeInstruction(OpCodes.Call, makeInsideLeftMethod));
					Console.WriteLine($"Patched PlayerStats at PlayerStats:Draw+{i+16}!");
					codes.InsertRange(i+16, newCodes);
					break;
				}
			}
			
			Label ret = il.DefineLabel();
			List<CodeInstruction> newCodes2 = new List<CodeInstruction>();
			// newCodes2.Add(new CodeInstruction(OpCodes.Ldarg_0));                                   // ldarg.0
			// newCodes2.Add(new CodeInstruction(OpCodes.Ldfld, typeof(PlayerStats).GetField("p", BindingFlags.Instance | BindingFlags.NonPublic)));  // ldfld   class ProjectTower.player.Player ProjectTower.player.PlayerStats::p
			// newCodes2.Add(new CodeInstruction(OpCodes.Ldfld, typeof(Player).GetField("menuMgr"))); // ldfld   class ProjectTower.menu.MenuMgr ProjectTower.player.Player::menuMgr
			// newCodes2.Add(new CodeInstruction(OpCodes.Ldfld, typeof(MenuMgr).GetField("curLev"))); // ldfld   int32 ProjectTower.menu.MenuMgr::curLev
			// newCodes2.Add(new CodeInstruction(OpCodes.Ldc_I4_S, 24));                              // ldc.i4.s    0x1B
			// newCodes2.Add(new CodeInstruction(OpCodes.Bne_Un_S, ret));                             // bne.un.s    7 (0015) ldsfld valuetype [FNA]Microsoft.Xna.Framework.Vector2 MapEdit.ScrollManager::screenSize
			// newCodes2.Add(new CodeInstruction(OpCodes.Ret) );                                      // ret
			// newCodes2.Add(new CodeInstruction(OpCodes.Nop) { labels = new List<Label>() { ret } } );
			MethodInfo isBestiaryMethod = typeof(PlayerStats_Draw).GetMethod("isBestiary", BindingFlags.Public | BindingFlags.Static);
			newCodes2.Add(new CodeInstruction(OpCodes.Ldarg_0)); // ldarg.0
			newCodes2.Add(new CodeInstruction(OpCodes.Ldfld, typeof(PlayerStats).GetField("p", BindingFlags.Instance | BindingFlags.NonPublic))); // ldfld	class ProjectTower.player.Player ProjectTower.player.PlayerStats::p
			newCodes2.Add(new CodeInstruction(OpCodes.Call, isBestiaryMethod)); // call	instance bool ProjectTower.player.PlayerStats::isBeast(class ProjectTower.player.Player)
			newCodes2.Add(new CodeInstruction(OpCodes.Brfalse_S, ret)); // brfalse.s	6 (000F) ldsfld valuetype [FNA]Microsoft.Xna.Framework.Vector2 MapEdit.ScrollManager::screenSize
			newCodes2.Add(new CodeInstruction(OpCodes.Ret)); // ret
			newCodes2.Add(new CodeInstruction(OpCodes.Nop) { labels = new List<Label>() { ret } } );

			codes.InsertRange(0, newCodes2);

			return codes.AsEnumerable();
		}
	}

	// Keep choices inside the visible area of the screen
	[HarmonyPatch(typeof(DialogMenuLevel), nameof(DialogMenuLevel.Draw))]
	public class DialogMenuLevel_Draw
	{
		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			List<CodeInstruction> newCodes;
			var codes = new List<CodeInstruction>(instructions);
			for (int i = 0; i < codes.Count-10; i++)
			{
				if (
					codes[i].opcode   == OpCodes.Ldc_I4_S  && (SByte)codes[i].operand == 100 &&              // 160	017A	ldc.i4.s	100
					codes[i+1].opcode == OpCodes.Sub       &&                                                // 161	017C	sub
					codes[i+2].opcode == OpCodes.Stind_I4  &&                                                // 162	017D	stind.i4
					codes[i+3].opcode == OpCodes.Ldloca_S  &&                                                // 163	017E	ldloca.s	V_3 (3)
					codes[i+4].opcode == OpCodes.Ldflda    && codes[i+4].operand.ToString().Contains("X") && // 164	0180	ldflda	int32 [FNA]Microsoft.Xna.Framework.Rectangle::X
					codes[i+5].opcode == OpCodes.Dup       &&                                                // 165	0185	dup
					codes[i+6].opcode == OpCodes.Ldind_I4  &&                                                // 166	0186	ldind.i4
					codes[i+7].opcode == OpCodes.Ldloc_0   &&                                                // 167	0187	ldloc.0
					codes[i+8].opcode == OpCodes.Add       &&                                                // 168	0188	add
					codes[i+9].opcode == OpCodes.Stind_I4                                                    // 169	0189	stind.i4
				)
				{
					LocalBuilder reloc = codes[i+3].operand as LocalBuilder;
					MethodInfo MakeInsideRightMethod = typeof(LimitRectangle).GetMethod("MakeInsideRight", BindingFlags.Public | BindingFlags.Static);
					newCodes = new List<CodeInstruction>();
					newCodes.Add(new CodeInstruction(OpCodes.Ldloca_S, reloc.LocalIndex));
					newCodes.Add(new CodeInstruction(OpCodes.Call, MakeInsideRightMethod));
					Console.WriteLine($"Patched DialogMenuLevel at DialogMenuLevel:Draw+{i+10}!");
					codes.InsertRange(i+10, newCodes);
					break;
				}
			}

			MethodInfo makeNewScale = typeof(LimitRectangle).GetMethod("makeNewScale", BindingFlags.Public | BindingFlags.Static);
			newCodes = new List<CodeInstruction>();
			newCodes.Add(new CodeInstruction(OpCodes.Ldarga_S, (byte)2));
			newCodes.Add(new CodeInstruction(OpCodes.Call, makeNewScale));
			codes.InsertRange(0, newCodes);

			return codes.AsEnumerable();
		}
	}

	// Common patcher to fix the scale of different menu boxes
	public class PatchMenuCommon
	{
		public static Rectangle makeRectangleCentered(float offsX, float offsY, float Width, float Height, float scaleAdjust, ref float scale)
		{
			if (ScrollManager.screenSize.Y <= 480f)
			{
				scale = ScrollManager.screenSize.Y / scaleAdjust;
			}

			return new Rectangle((int)(ScrollManager.screenSize.X / 2f - offsX * scale), (int)(ScrollManager.screenSize.Y / 2f - offsY * scale), (int)(Width * scale), (int)(Height * scale));
		}

		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions, string nameType, string nameFunc)
		{
			Console.WriteLine($"Patching {nameType} at {nameType}:{nameFunc}...");

			var codes = new List<CodeInstruction>(instructions);            
			for (int i = 0; i < codes.Count-30; i++)
			{
				if (
					codes[i].opcode   == OpCodes.Ldloca_S &&                                                         // 9 	001E	ldloca.s	V_1 (1)
					codes[i+1].opcode == OpCodes.Ldsflda  && codes[i+1].operand.ToString().Contains("screenSize") && // 10	0020	ldsflda	valuetype [FNA]Microsoft.Xna.Framework.Vector2 MapEdit.ScrollManager::screenSize
					codes[i+2].opcode == OpCodes.Ldfld    && codes[i+2].operand.ToString().Contains("X")          && // 11	0025	ldfld	float32 [FNA]Microsoft.Xna.Framework.Vector2::X
					codes[i+3].opcode == OpCodes.Ldc_R4   && (float)codes[i+3].operand == 2                       && // 12	002A	ldc.r4	2
					codes[i+4].opcode == OpCodes.Div      &&                                                         // 13	002F	div
					codes[i+5].opcode == OpCodes.Ldarg_0  &&                                                         // 14	0030	ldarg.0
					codes[i+6].opcode == OpCodes.Ldfld    && codes[i+6].operand.ToString().Contains("alpha") &&      // 15	0031	ldfld	float32 ProjectTower.player.dialog.DialogMenuLevel::alpha
					codes[i+7].opcode == OpCodes.Ldc_R4   && (float)codes[i+7].operand == 10                         // 16	0036	ldc.r4	10
				)
				{
					MethodInfo makeRectangleCentered = typeof(PatchMenuCommon).GetMethod("makeRectangleCentered", BindingFlags.Public | BindingFlags.Static);
					List<CodeInstruction> newCodes = new List<CodeInstruction>();

					newCodes.Add(new CodeInstruction(OpCodes.Ldc_R4, (float)260));
					newCodes.Add(new CodeInstruction(OpCodes.Ldc_R4, (float)220));
					newCodes.Add(new CodeInstruction(OpCodes.Ldc_R4, (float)520));
					newCodes.Add(new CodeInstruction(OpCodes.Ldc_R4, (float)370));
					newCodes.Add(new CodeInstruction(OpCodes.Ldc_R4, (float)490));
					newCodes.Add(new CodeInstruction(OpCodes.Ldarga_S, (byte)2));
					newCodes.Add(new CodeInstruction(OpCodes.Call, makeRectangleCentered));
					newCodes.Add(new CodeInstruction(OpCodes.Stloc_S, (byte)0)); // < MUST BE RELINKED >

					if (
						codes[i+26].opcode == OpCodes.Call && codes[i+26].operand.ToString().Contains("CoopAdjustRect") &&
						codes[i+43].opcode == OpCodes.Stfld && codes[i+43].operand.ToString().Contains("Height")
					)
					{
						Console.WriteLine($"Patched (v1) {nameType} at {nameType}:{nameFunc}+{i} (op: {codes[i+27].opcode})!");
						// Relink the store local opcode using the CoopAdjustRect store.
						newCodes[7].operand = (byte)(codes[i+27].opcode.Value - OpCodes.Stloc_0.Value);
						codes.RemoveRange(i, 44);
					}
					else if (codes[i+34].opcode == OpCodes.Call && codes[i+34].operand.ToString().Contains("CoopAdjustRect"))
					{
						Console.WriteLine($"Patched (v2) {nameType} at {nameType}:{nameFunc}+{i} (op: {codes[i+35].opcode})!");
						// Relink the store local opcode using the CoopAdjustRect store.
						newCodes[7].operand = (byte)(codes[i+35].opcode.Value - OpCodes.Stloc_0.Value);
						codes.RemoveRange(i, 31);
					}
					else if (codes[i+32].opcode == OpCodes.Call && codes[i+32].operand.ToString().Contains("CoopAdjustRect"))
					{
						Console.WriteLine($"Patched (v3) {nameType} at {nameType}:{nameFunc}+{i} (op: {codes[i+33].opcode})!");
						// Relink the store local opcode using the CoopAdjustRect store.
						newCodes[7].operand = (byte)(codes[i+33].opcode.Value - OpCodes.Stloc_0.Value);
						codes.RemoveRange(i, 29);
					}
					else
					{
						throw new Exception("Unknown patch type.");
					}

					codes.InsertRange(i, newCodes);
					break;
				}
			}

			return codes.AsEnumerable();
		}
	}

	[HarmonyPatch(typeof(FastTravel), nameof(FastTravel.Draw))]
	public class FastTravel_Draw
	{
		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			return PatchMenuCommon.Transpiler(instructions, "FastTravel", "Draw");
		}
	}

	[HarmonyPatch(typeof(HireMenu), nameof(HireMenu.Draw))]
	public class HireMenu_Draw
	{
		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			return PatchMenuCommon.Transpiler(instructions, "HireMenu", "Draw");
		}
	}

	[HarmonyPatch(typeof(IconOffer), nameof(IconOffer.Draw))]
	public class IconOffer_Draw
	{
		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			return PatchMenuCommon.Transpiler(instructions, "IconOffer", "Draw");
		}
	}

	[HarmonyPatch(typeof(Storefront), nameof(Storefront.Draw))]
	public class Storefront_Draw
	{
		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			return PatchMenuCommon.Transpiler(instructions, "Storefront", "Draw");
		}
	}

	[HarmonyPatch(typeof(Upgrades), nameof(Upgrades.Draw))]
	public class Upgrades_Draw
	{
		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			return PatchMenuCommon.Transpiler(instructions, "Upgrades", "Draw");
		}
	}

	[HarmonyPatch(typeof(WorkMenu), nameof(WorkMenu.Draw))]
	public class WorkMenu_Draw
	{
		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			return PatchMenuCommon.Transpiler(instructions, "WorkMenu", "Draw");
		}
	}

	[HarmonyPatch(typeof(WorkUpgrade), nameof(WorkUpgrade.Draw))]
	public class WorkUpgrade_Draw
	{
		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			return PatchMenuCommon.Transpiler(instructions, "WorkUpgrade", "Draw");
		}
	}

	// Fit the bottle message writing dialogue to the screen pt. 1
	[HarmonyPatch(typeof(ViewMessage), nameof(ViewMessage.SelectedDraw))]
	public class ViewMessage_SelectedDraw
	{
		public static bool Prefix(ViewMessage __instance, ref float scale, float alpha, int xOffset, Player p)
		{
			float scaleX = ScrollManager.screenSize.X / 960f;
			float scaleY = ScrollManager.screenSize.Y / 544f;
			scale = ((scaleX < scaleY) ? scaleX : scaleY);

			return true;
		}
	}

	// Fit the bottle message writing dialogue to the screen pt. 2
	[HarmonyPatch(typeof(WriteMessage), nameof(WriteMessage.SelectedDraw))]
	public class WriteMessage_SelectedDraw
	{
		public static bool Prefix(WriteMessage __instance, ref float scale, float alpha, int xOffset, Player p)
		{
			float scaleX = ScrollManager.screenSize.X / 960f;
			float scaleY = ScrollManager.screenSize.Y / 544f;
			scale = ((scaleX < scaleY) ? scaleX : scaleY);

			return true;
		}
	}

	[HarmonyPatch(typeof(MenuSkillTree), nameof(MenuSkillTree.SelectedUpdate))]
	public class MenuSkillTree_SelectedUpdate
	{
		public static void Postfix(MenuSkillTree __instance, Player p)
		{
			if (!MenuSkillTree_Draw.CurrentDisplays.ContainsKey(p.ID))
				MenuSkillTree_Draw.CurrentDisplays.Add(p.ID, 0);

			if (p.keyCatLeft) {
				MenuSkillTree_Draw.CurrentDisplays[p.ID] = (MenuSkillTree_Draw.CurrentDisplays[p.ID]+1) % 2;
			}
		}
	}

	// Rework the Skill Tree Menu to make it easier to read on smaller displays
	[HarmonyPatch(typeof(MenuSkillTree), nameof(MenuSkillTree.Draw))]
	public class MenuSkillTree_Draw
	{
		static Action<MenuSkillTree, Player, float> DialogMenuLevelDrawDelegate;
		public static Dictionary<int, int> CurrentDisplays;
		public static void Prepare()
		{
			CurrentDisplays = new Dictionary<int, int>();
			var m = typeof(DialogMenuLevel).GetMethod("Draw");
			var dm = new DynamicMethod("", typeof(void), new[] { typeof(MenuSkillTree), typeof(Player), typeof(float) }, typeof(MenuSkillTree));
			var il = dm.GetILGenerator();
			il.Emit(OpCodes.Ldarg_0);
			il.Emit(OpCodes.Ldarg_1);
			il.Emit(OpCodes.Ldarg_2);
			il.Emit(OpCodes.Call, m);
			il.Emit(OpCodes.Ret);
			DialogMenuLevelDrawDelegate = (Action<MenuSkillTree, Player, float>)dm.CreateDelegate(typeof(Action<MenuSkillTree, Player, float>));
		}

		public static bool Prefix(MenuSkillTree __instance, Player p, float scale)
		{
			// Calculate the ratio necessary to fill the screen with the menu.
			const float infoScale = 580f / 424f; 
			float scaleX = ScrollManager.screenSize.X / (30f + 590f + 260f * infoScale);
			float scaleY = ScrollManager.screenSize.Y / (660f);
			scale = (scaleX < scaleY) ? scaleX : scaleY;

			int blackPearlCount = p.playerInv.GetBlackPearlCount();
			int grayPearlCount = p.playerInv.GetGrayPearlCount();
			if (GameStateManager.coopPlayerIdx == -1)
			{
				__instance.coopInfoAlpha = __instance.alpha;
			}

			// Calculate where our skill tree will be
			float treeWidth = 590;
			float treeHeight = 520;
			Rectangle rectangle = new Rectangle(
				(int)(15f * scale), 
				(int)(45f * scale),
				(int)(treeWidth * scale),
				(int)(treeHeight * scale));

			rectangle.Y = ((int)ScrollManager.screenSize.Y - (rectangle.Y + rectangle.Height)) / 2;

			// Draw the skill tree itself
			RenderTarget2D rTarg = __instance.rTarg;
			float alpha = __instance.alpha;
			InterfaceRender.DrawRect(rectangle, alpha * 0.7f);
			SpriteTools.sprite.Draw(rTarg, rectangle, new Rectangle?(new Rectangle(0, 0, rTarg.Width, rTarg.Height)), new Color(1f, 1f, 1f, alpha), 0f, default(Vector2), SpriteEffects.None, 1f);
			for (int i = 0; i < 4; i++)
			{
				SpriteTools.sprite.Draw(InterfaceRender.interfaceTex, new Vector2((float)((i % 2 == 0) ? rectangle.X : rectangle.Right), (float)((i / 2 == 0) ? rectangle.Y : rectangle.Bottom)), new Rectangle?(new Rectangle(128, 128, 448, 384)), new Color(1f, 1f, 1f, __instance.alpha * 0.45f), 0f, new Vector2(64f + ((i % 2 != 0) ? 320f : 0f), 64f + ((i / 2 > 0) ? 256f : 0f)), 0.65f * scale, ((i % 2 != 0) ? SpriteEffects.FlipHorizontally : SpriteEffects.None) | ((i / 2 > 0) ? SpriteEffects.FlipVertically : SpriteEffects.None), 1f);
			}

			// Draw the button prompts
			InterfaceRender.DrawRect(new Rectangle(rectangle.X, rectangle.Y, (int)(260f * scale), (int)(52f * scale)), __instance.alpha);
			Text.DrawText(InterfaceRender.CHAR_LB, new Vector2((float)rectangle.X + 5f * scale, rectangle.Y + 26f * scale), new Color(1f, 1f, 1f, __instance.alpha), 0.80f * scale, 0, 170f * scale, p, Text.ALIGN_LEFT);
			if (CurrentDisplays[p.ID] == 0)
				Text.DrawText(new StringBuilder("Stats"), new Vector2((float)rectangle.X + 70f * scale, rectangle.Y + 24 * scale), new Color(1f, 1f, 1f, __instance.alpha), 0.65f * scale, 0, 170f * scale, p, Text.ALIGN_LEFT);
			else	
				Text.DrawText(new StringBuilder("Description"), new Vector2((float)rectangle.X + 70f * scale, rectangle.Y + 24 * scale), new Color(1f, 1f, 1f, __instance.alpha), 0.65f * scale, 0, 170f * scale, p, Text.ALIGN_LEFT);

			InterfaceRender.DrawRect(new Rectangle(rectangle.X, (int)((float)rectangle.Bottom + 5f * scale), rectangle.Width, (int)(50f * scale)), __instance.alpha);
			Text.DrawText(InvPicker.strs[InvPicker.STRING_PEARL_UPGRADE], new Vector2((float)rectangle.X + 20f * scale, (float)rectangle.Bottom + 30f * scale), new Color(1f, 1f, 1f, __instance.alpha), 0.60f * scale, 0, 190f * scale, p, 1);
			Text.DrawText(InvPicker.strs[InvPicker.STRING_REMOVE], new Vector2((float)rectangle.X + 220f * scale, (float)rectangle.Bottom + 30f * scale), new Color(1f, 1f, 1f, __instance.alpha), 0.60f * scale, 0, 190f * scale, p, 1);
			Text.DrawText(InvPicker.strs[InvPicker.STRING_CLOSE], new Vector2((float)rectangle.X + 420f * scale, (float)rectangle.Bottom + 30f * scale), new Color(1f, 1f, 1f, __instance.alpha), 0.60f * scale, 0, 190f * scale, p, 1);
			
			// Draw the Pearl counts
			Vector2 pearlsPos = new Vector2((float)rectangle.Right - 260f * scale + 22f * scale, (float)rectangle.Top + 22f * scale);
			InterfaceRender.DrawRect(new Rectangle((int)(pearlsPos.X - 22f * scale), (int)(pearlsPos.Y - 22f * scale), (int)(260f * scale), (int)(52f * scale)), __instance.alpha * 0.95f, 0);
			pearlsPos.X += 8f * scale;
			pearlsPos.Y += 4f * scale;
			InterfaceRender.DrawItem(pearlsPos, MenuSkillTree.GRAY_PEARL_IMG, 1f, __instance.alpha, 0.45f * scale);
			Text.DrawScore(grayPearlCount, pearlsPos + new Vector2(24f, 0f) * scale, new Color(1f, 1f, 1f, __instance.alpha), 1.0f * scale, 0);
			pearlsPos.X += 110f * scale;
			InterfaceRender.DrawItem(pearlsPos, MenuSkillTree.BLACK_PEARL_IMG, 1f, __instance.alpha, 0.45f * scale);
			Text.DrawScore(blackPearlCount, pearlsPos + new Vector2(28f, 0f) * scale, new Color(1f, 1f, 1f, __instance.alpha), 1.0f * scale, 0);

			// X toggles the current display mode for the menu
			if (!CurrentDisplays.ContainsKey(p.ID))
				CurrentDisplays.Add(p.ID, 0);

			Rectangle infoRect = new Rectangle();
			infoRect.Width = (int)(260f * infoScale * scale);
			infoRect.Height = (int)(424f * infoScale * scale);
			infoRect.X = (int)(ScrollManager.screenSize.X - 15f * scale);
			infoRect.Y = rectangle.Y - (int)(2f * scale);

			if (CurrentDisplays[p.ID] == 1)
			{
				// We want this element to touch the right side of the screen... 
				p.stats.Draw(alpha, scale * infoScale, infoRect, 0);
			}
			else
			{
				infoRect.X -= infoRect.Width;
				InterfaceRender.DrawRect(infoRect, __instance.alpha * 0.75f, 4);

				SkillNode skillNode = SkillTree.nodes[__instance.selItem];
				int descSize = LimitRectangle.makeDescriptionSize() + 3;
				float descScale = LimitRectangle.makeDescriptionDimensions();

				if (skillNode.descStr == null || p.keyXInfo)
				{
					skillNode.descStr = WordWrap.Wrap(p, skillNode.desc[Game1.language], descSize, 4);
				}
				if (skillNode.baseDescStr == null || p.keyXInfo)
				{
					skillNode.baseDescStr = WordWrap.Wrap(p, skillNode.baseDesc[Game1.language], descSize, 4);
				}

				float curAlpha = __instance.alpha;
				float descOffsY = 130f;
				float descHeight = 90f;
				float charHeight = 28f * (descScale / 0.45f);
				Vector2 descVec = new Vector2(infoRect.X, infoRect.Y);

				bool hasPoints = p.stats.treeUnlocks[__instance.selItem] <= 0 && p.stats.classUnlocks[0] != __instance.selItem && p.stats.classUnlocks[1] != __instance.selItem;
				if (!hasPoints && p.stats.treeUnlocks[__instance.selItem] < SkillTree.nodes[__instance.selItem].max)
				{
					hasPoints = true;
				}

				Text.DrawText(skillNode.titleStr, descVec + new Vector2(8f, 20f) * scale * infoScale, new Color(1f, 1f, 1f, curAlpha * 0.8f), descScale * scale * infoScale, 0, infoRect.Width - 60f * scale);
				Vector2 pointLoc = new Vector2(26f, 54f);
				if (hasPoints)
				{
					float num14 = (skillNode.cost > blackPearlCount) ? 0f : 1f;
					InterfaceRender.DrawItem(descVec + (pointLoc) * scale * infoScale, 294, 1f, curAlpha, 0.35f * scale * infoScale);
					Text.DrawScore(skillNode.cost, descVec + (pointLoc + new Vector2(20f, 0f)) * scale * infoScale, new Color(1f, num14, num14, curAlpha), 0.55f * scale * infoScale, 0);
				}
				else
				{
					InterfaceRender.DrawIcon(51, descVec + (pointLoc) * scale * infoScale, 0.35f * scale * infoScale, curAlpha);
					Text.DrawText(InvPicker.strs[158], descVec + (pointLoc + new Vector2(16f, 0f)) * scale * infoScale, new Color(1f, 1f, 1f, curAlpha * 0.8f), descScale * scale * infoScale, 0);
				}

				float offsTextYOrig = (float)(skillNode.baseDescStr.Length + skillNode.descStr.Length) * 28f - 250f;
				float offsTextYNew = (float)(skillNode.baseDescStr.Length + skillNode.descStr.Length) * charHeight - 250f;
				float offsTextY = offsTextYNew * (__instance.descScroll / offsTextYOrig);

				int k = 0;
				for (int i = 0; i < 2; i++, k++) {
					StringBuilder[] builderList = skillNode.baseDescStr;
					Color builderListColor = new Color(1f, 1f, 1f, curAlpha);
					if (i == 1) {
						builderList = skillNode.descStr;
						builderListColor = new Color(0.7f, 1f, 0.7f, curAlpha);
					}

					for (int j = 0; j < builderList.Length; j++, k++)
					{
						Vector2 lineVec = new Vector2(8f, descHeight + (float)k * charHeight);
						lineVec.Y -= offsTextY;

						float fadeOut = 1f;
						if (lineVec.Y < descHeight)
						{
							fadeOut -= (descHeight - lineVec.Y) / 18f;
						}
						if (lineVec.Y > descHeight + ((float)435f - descOffsY))
						{
							fadeOut -= (lineVec.Y - (descHeight + ((float)435f - descOffsY))) / 18f;
						}
						if (fadeOut > 0f)
						{
							Color col = builderListColor;
							col.A = (byte)(col.A * fadeOut);
							Text.DrawText(builderList[j], descVec + lineVec * scale * infoScale, col, descScale * scale * infoScale, 0, infoRect.Width - 30f * scale);
						}
					}
				}
			}

			/* Removed the description drawing code from here */
			DialogMenuLevelDrawDelegate(__instance, p, scale);
			return false;
		}
	}

	// Make item descriptions larger on smaller displays
	[HarmonyPatch(typeof(InvPicker), nameof(InvPicker.DrawLootDesc))]
	public class InvPicker_DrawLootDesc
	{
		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			Console.WriteLine($"Patching InvPicker at InvPicker:DrawLootDesc...");

			var codes = new List<CodeInstruction>(instructions);
			for (int i = 0; i < codes.Count-10; i++)
			{
				if (
					codes[i].opcode == OpCodes.Ldarg_1      &&                                                       // 3	0008	ldarg.1
					codes[i+1].opcode == OpCodes.Ldarg_0    &&                                                       // 4	0009	ldarg.0
					codes[i+2].opcode == OpCodes.Ldarg_1    &&                                                       // 5	000A	ldarg.1
					codes[i+3].opcode == OpCodes.Ldfld      && codes[i+3].operand.ToString().Contains("desc") &&     // 6	000B	ldfld	string[] LootEdit.LootDef::desc
					codes[i+4].opcode == OpCodes.Ldsfld     && codes[i+4].operand.ToString().Contains("language") && // 7	0010	ldsfld	int32 ProjectTower.Game1::language
					codes[i+5].opcode == OpCodes.Ldelem_Ref &&                                                       // 8	0015	ldelem.ref
					codes[i+6].opcode == OpCodes.Ldc_I4_S   && (SByte)codes[i+6].operand == 0x1A &&                  // 9	0016	ldc.i4.s	0x1A
					codes[i+7].opcode == OpCodes.Ldc_I4_2   &&                                                       // 10	0018	ldc.i4.2
					codes[i+8].opcode == OpCodes.Call       && codes[i+8].operand.ToString().Contains("Wrap") &&     // 11	0019	call	class [mscorlib]System.Text.StringBuilder[] ProjectTower.hud.WordWrap::Wrap(class ProjectTower.player.Player, string, int32, int32)
					codes[i+9].opcode == OpCodes.Stfld                                                               // 12	001E	stfld	class [mscorlib]System.Text.StringBuilder[] LootEdit.LootDef::descStr
				)
				{
					MethodInfo makeDescriptionSize = typeof(LimitRectangle).GetMethod("makeDescriptionSize", BindingFlags.Public | BindingFlags.Static);
					codes[i+6] = new CodeInstruction(OpCodes.Call, makeDescriptionSize);
					Console.WriteLine($"Patched InvPicker at InvPicker:DrawLootDesc+{i+6}!");
					break;
				}
			}

			MethodInfo makeDescriptionDimensions = typeof(LimitRectangle).GetMethod("makeDescriptionDimensions", BindingFlags.Public | BindingFlags.Static);
			List<CodeInstruction> newCodes = new List<CodeInstruction>();
			newCodes.Add(new CodeInstruction(OpCodes.Call, makeDescriptionDimensions));
			newCodes.Add(new CodeInstruction(OpCodes.Starg_S, 5));
			newCodes.Add(new CodeInstruction(OpCodes.Ldarg_3));
			newCodes.Add(new CodeInstruction(OpCodes.Ldarg_S, 5));
			newCodes.Add(new CodeInstruction(OpCodes.Ldc_R4, (float)0.45f));
			newCodes.Add(new CodeInstruction(OpCodes.Div));
			newCodes.Add(new CodeInstruction(OpCodes.Mul));
			newCodes.Add(new CodeInstruction(OpCodes.Starg_S, 3));
			codes.InsertRange(0, newCodes);

			return codes.AsEnumerable();
		}
	}

	// Make item descriptions larger on smaller displays, for consumables
	[HarmonyPatch(typeof(InvPicker), nameof(InvPicker.DrawItemInfo))]
	[HarmonyPatch(new Type[] { typeof(Rectangle), typeof(int), typeof(float), typeof(float), typeof(Player), typeof(List<int>), typeof(int), typeof(Character), typeof(LootDef[]), typeof(InvLoot[]), typeof(InvLoot), typeof(float), typeof(int), typeof(int), typeof(float) })]
	public class InvPicker_DrawItemInfo
	{
		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			Console.WriteLine($"Patching InvPicker at InvPicker:DrawItemInfo...");

			var codes = new List<CodeInstruction>(instructions);
			for (int i = 0; i < codes.Count-10; i++)
			{
				if (
					codes[i].opcode   == OpCodes.Ldloc_S    &&                                                         // 155	0193	ldloc.s	V_5 (5)
					codes[i+1].opcode == OpCodes.Ldarg_S    &&                                                         // 156	0195	ldarg.s	p (4)
					codes[i+2].opcode == OpCodes.Ldloc_S    &&                                                         // 157	0197	ldloc.s	V_5 (5)
					codes[i+3].opcode == OpCodes.Ldfld      && codes[i+3].operand.ToString().Contains("desc")      &&  // 158	0199	ldfld	string[] LootEdit.LootDef::desc
					codes[i+4].opcode == OpCodes.Ldsfld     && codes[i+4].operand.ToString().Contains("language")  &&  // 159	019E	ldsfld	int32 ProjectTower.Game1::language
					codes[i+5].opcode == OpCodes.Ldelem_Ref &&                                                         // 160	01A3	ldelem.ref
					codes[i+6].opcode == OpCodes.Ldc_I4_S   && (SByte)codes[i+6].operand == 0x1A                   &&  // 161	01A4	ldc.i4.s	0x1A
					codes[i+7].opcode == OpCodes.Ldc_I4_2   &&                                                         // 162	01A6	ldc.i4.2
					codes[i+8].opcode == OpCodes.Call       && codes[i+8].operand.ToString().Contains("Wrap")      &&  // 163	01A7	call	class [mscorlib]System.Text.StringBuilder[] ProjectTower.hud.WordWrap::Wrap(class ProjectTower.player.Player, string, int32, int32)
					codes[i+9].opcode == OpCodes.Stfld      && codes[i+9].operand.ToString().Contains("descStr")       // 164	01AC	stfld	class [mscorlib]System.Text.StringBuilder[] LootEdit.LootDef::descStr
				)
				{
					MethodInfo makeDescriptionSize = typeof(LimitRectangle).GetMethod("makeDescriptionSize", BindingFlags.Public | BindingFlags.Static);
					codes[i+6] = new CodeInstruction(OpCodes.Call, makeDescriptionSize);
					Console.WriteLine($"Patched InvPicker at InvPicker:DrawItemInfo+{i+6}!");
					break;
				}
			}

			return codes.AsEnumerable();
		}
	}

	// Make header in Inventory a tad bit bigger
	[HarmonyPatch(typeof(PlayerInvEquip), nameof(PlayerInvEquip.DrawEquipCategory))]
	public class PlayerInvEquip_DrawEquipCategory
	{
		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			Console.WriteLine($"Patching PlayerInvEquip at PlayerInvEquip:DrawEquipCategory...");

			var codes = new List<CodeInstruction>(instructions);
			for (int i = 0; i < codes.Count-10; i++)
			{
				if (
					codes[i].opcode == OpCodes.Newobj     &&                                                        // 1220	0D3B	newobj	instance void [FNA]Microsoft.Xna.Framework.Color::.ctor(float32, float32, float32, float32)
					codes[i+1].opcode == OpCodes.Ldc_R4   && (float)codes[i+1].operand == 0.55f                  && // 1221	0D40	ldc.r4	0.55
					codes[i+2].opcode == OpCodes.Ldarg_S  &&                                                        // 1222	0D45	ldarg.s	scale (4)
					codes[i+3].opcode == OpCodes.Mul      &&                                                        // 1223	0D47	mul
					codes[i+4].opcode == OpCodes.Ldc_I4_1 &&                                                        // 1224	0D48	ldc.i4.1
					codes[i+5].opcode == OpCodes.Call     && codes[i+5].operand.ToString().Contains("DrawText")     // 1225	0D49	call	void ProjectTower.hud.Text::DrawText(class [mscorlib]System.Text.StringBuilder, valuetype [FNA]Microsoft.Xna.Framework.Vector2, valuetype [FNA]Microsoft.Xna.Framework.Color, float32, int32)
				)
				{
					MethodInfo makeDescriptionSize = typeof(LimitRectangle).GetMethod("makeDescriptionSize", BindingFlags.Public | BindingFlags.Static);
					codes[i+1] = new CodeInstruction(OpCodes.Ldc_R4, (float)0.70f);
					Console.WriteLine($"Patched PlayerInvEquip at PlayerInvEquip:DrawEquipCategory+{i+6}!");
					// We patch three different places here, let the function do it's thing.
				}
			}

			return codes.AsEnumerable();
		}
	}

	// Rework the bestiary to make it easier to read on smaller displays
	[HarmonyPatch(typeof(BestiaryBeast), nameof(BestiaryBeast.Init))]
	public class BestiaryBeast_Init
	{
		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			Console.WriteLine($"Patching BestiaryBeast at BestiaryBeast:Init...");

			var codes = new List<CodeInstruction>(instructions);
			for (int i = 0; i < codes.Count-10; i++)
			{
				if (
					codes[i].opcode == OpCodes.Ldarg_0      &&                                                       // 139	01AD	ldarg.0
					codes[i+1].opcode == OpCodes.Ldarg_1    &&                                                       // 140	01AE	ldarg.1
					codes[i+2].opcode == OpCodes.Ldloc_0    &&                                                       // 141	01AF	ldloc.0
					codes[i+3].opcode == OpCodes.Ldfld      && codes[i+3].operand.ToString().Contains("desc")     && // 142	01B0	ldfld	string[] MonsterEdit.monsters.MonsterDef::desc
					codes[i+4].opcode == OpCodes.Ldsfld     && codes[i+4].operand.ToString().Contains("language") && // 143	01B5	ldsfld	int32 ProjectTower.Game1::language
					codes[i+5].opcode == OpCodes.Ldelem_Ref &&                                                       // 144	01BA	ldelem.ref
					codes[i+6].opcode == OpCodes.Ldc_I4_S   && (SByte)codes[i+6].operand == 0x32                  && // 145	01BB	ldc.i4.s	0x32
					codes[i+7].opcode == OpCodes.Ldc_I4_5   &&                                                       // 146	01BD	ldc.i4.5
					codes[i+8].opcode == OpCodes.Call       && codes[i+8].operand.ToString().Contains("Wrap")     && // 147	01BE	call	class [mscorlib]System.Text.StringBuilder[] ProjectTower.hud.WordWrap::Wrap(class ProjectTower.player.Player, string, int32, int32)
					codes[i+9].opcode == OpCodes.Stfld      && codes[i+9].operand.ToString().Contains("desc")        // 148	01C3	stfld	class [mscorlib]System.Text.StringBuilder[] ProjectTower.menu.levels.BestiaryBeast::desc
				)
				{
					MethodInfo makeDescriptionSize = typeof(LimitRectangle).GetMethod("makeDescriptionSize", BindingFlags.Public | BindingFlags.Static);
					codes[i+6] = new CodeInstruction(OpCodes.Ldc_I4_S, (SByte)40);
					Console.WriteLine($"Patched BestiaryBeast at BestiaryBeast:Init+{i+6}!");
					break;
				}
			}

			return codes.AsEnumerable();
		}
	}

	[HarmonyPatch(typeof(BestiaryBeast), nameof(BestiaryBeast.SelectedDraw))]
	public class BestiaryBeast_SelectedDraw
	{
		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			Console.WriteLine($"Patching BestiaryBeast at BestiaryBeast:SelectedDraw...");

			// We patch three different places here, so no break on the end.
			var codes = new List<CodeInstruction>(instructions);
			for (int i = 0; i < codes.Count-10; i++)
			{
				if (
					codes[i].opcode   == OpCodes.Newobj  && codes[i].operand.ToString().Contains("Void .ctor") && // 251	02BF	newobj	instance void [FNA]Microsoft.Xna.Framework.Color::.ctor(float32, float32, float32, float32)
					codes[i+1].opcode == OpCodes.Ldc_R4  && (float)codes[i+1].operand == 0.45f                 && // 252	02C4	ldc.r4	0.45    <----- we patch this (0.45 -> 0.52f)
					codes[i+2].opcode == OpCodes.Ldarg_3 &&                                                       // 253	02C9	ldarg.3
					codes[i+3].opcode == OpCodes.Mul                                                              // 254	02CA	mul
				)
				{
					// Ignore loot listing...
					if (codes[i+5].opcode == OpCodes.Ldc_R4 && (float)codes[i+5].operand == 240f)
						continue;

					codes[i+1] = new CodeInstruction(OpCodes.Ldc_R4, (float)0.52f);
					Console.WriteLine($"Patched BestiaryBeast at BestiaryBeast:SelectedDraw+{i+6}!");
				}
			}

			for (int i = 0; i < codes.Count-10; i++)
			{
				if (codes[i].opcode == OpCodes.Ldc_R4  && (float)codes[i].operand == 24f && codes[i+1].opcode == OpCodes.Stloc_S)
					Console.WriteLine($"{codes[i+1].operand.ToString()}");
				
				if (
					codes[i].opcode   == OpCodes.Ldc_R4  && (float)codes[i].operand == 24f &&        // 370	041B	ldc.r4	24
					codes[i+1].opcode == OpCodes.Stloc_S // 371	0420	stloc.s	V_10 (10)
				)
				{
					codes[i] = new CodeInstruction(OpCodes.Ldc_R4, (float)28f);
					Console.WriteLine($"Patched BestiaryBeast at BestiaryBeast:SelectedDraw+{i+6}!");
					break;
				}
			}

			return codes.AsEnumerable();
		}
	}

	// Make the Rune Messaage boxes actually readable.
	[HarmonyPatch(typeof(RuneMessage), nameof(RuneMessage.Draw))]
	public class RuneMessage_Draw
	{
		public static bool Prefix(RuneMessage __instance, Player p, Rectangle dRect, int tL, float alpha, float messageAlpha, float scale)
		{
			float num = 0f;
			float num2 = 0f;
			float num3 = 50f;
			bool flag = false;
			if (Game1.language == 10)
			{
				flag = true;
			}
			for (int i = 0; i < __instance.messageCurrentWord; i++)
			{
				StringBuilder s = (__instance.messageStr[i] != null) ? __instance.messageStr[i] : (flag ? RuneMessage.words[__instance.messageLetter[i]][__instance.messageWord[i]].bracketedLocText : ((i == 0) ? RuneMessage.words[__instance.messageLetter[i]][__instance.messageWord[i]].firstWordLocText : RuneMessage.words[__instance.messageLetter[i]][__instance.messageWord[i]].locText));
				float num4 = Math.Max(Text.GetRuneSpace(s, 0.55f), Text.GetStringSpace(s, 0.85f, p, 2));
				if (tL == 2 && i >= __instance.messageCurrentWord / 2)
				{
					num2 += num4 * scale;
					num2 += num3 * scale;
				}
				else
				{
					num += num4 * scale;
					num += num3 * scale;
				}
			}
			float num5 = 1f;
			if (num > 950f * scale)
			{
				num5 = 950f * scale / num;
				num = 0f;
				for (int j = 0; j < __instance.messageCurrentWord; j++)
				{
					StringBuilder s2 = (__instance.messageStr[j] != null) ? __instance.messageStr[j] : (flag ? RuneMessage.words[__instance.messageLetter[j]][__instance.messageWord[j]].bracketedLocText : ((j == 0) ? RuneMessage.words[__instance.messageLetter[j]][__instance.messageWord[j]].firstWordLocText : RuneMessage.words[__instance.messageLetter[j]][__instance.messageWord[j]].locText));
					float num6 = Math.Max(Text.GetRuneSpace(s2, 0.55f), Text.GetStringSpace(s2, 0.85f, p, 2));
					num += num6 * num5 * scale;
					num += num3 * num5 * scale;
				}
			}
			for (int k = 0; k < tL; k++)
			{
				Vector2 vector = new Vector2((float)dRect.Center.X, (float)dRect.Y + 130f * scale);
				int num7 = 0;
				int num8 = __instance.messageCurrentWord;
				if (tL == 2)
				{
					vector.Y += 5f * scale;
				}
				if (k == 0)
				{
					vector.X -= (num - num3) / 2f;
					if (tL == 2)
					{
						num8 = __instance.messageCurrentWord / 2;
					}
				}
				else
				{
					vector.Y += 32f * scale;
					vector.X -= (num2 - num3) / 2f;
					if (tL == 2)
					{
						num7 = __instance.messageCurrentWord / 2;
					}
				}
				for (int l = num7; l < num8; l++)
				{
					bool flag2 = l == 0;
					if (l > 0)
					{
						char c = RuneMessage.words[__instance.messageLetter[l - 1]][__instance.messageWord[l - 1]].locText[0];
						if (c == '!' || c == '.' || c == '?')
						{
							flag2 = true;
						}
					}
					int language = Game1.language;
					if (language != 3)
					{
						if (language == 7 || language == 11)
						{
							flag2 = true;
						}
					}
					else if (RuneMessage.ucaseGermanWords.Contains(RuneMessage.words[__instance.messageLetter[l]][__instance.messageWord[l]].locTextStr))
					{
						flag2 = true;
					}
					StringBuilder s3 = (__instance.messageStr[l] != null) ? __instance.messageStr[l] : (flag ? RuneMessage.words[__instance.messageLetter[l]][__instance.messageWord[l]].bracketedLocText : (flag2 ? RuneMessage.words[__instance.messageLetter[l]][__instance.messageWord[l]].firstWordLocText : RuneMessage.words[__instance.messageLetter[l]][__instance.messageWord[l]].locText));
					StringBuilder s4 = (__instance.messageStr[l] != null) ? __instance.messageStr[l] : RuneMessage.words[__instance.messageLetter[l]][__instance.messageWord[l]].englistText;
					Text.DrawText(s3, vector, new Color(1f, 1f, 1f, alpha * messageAlpha), 0.85f * num5 * scale, 0, p, 2);
					Text.DrawRunes(s4, vector + new Vector2(Text.GetStringSpace(s3, 0.60f, p, 0) * scale / 2f, ((tL == 2) ? -85f : -35f) * scale + ((k == 1) ? 10f : 0f) * scale), new Color(1f, 1f, 1f, alpha * messageAlpha), ((tL == 2) ? 0.65f : 0.65f) * num5 * scale, 1);
					vector.X += Math.Max(Text.GetRuneSpace(s3, 0.55f), Text.GetStringSpace(s3, 0.85f, p, 2)) * num5 * scale;
					vector.X += num3 * num5 * scale;
				}
			}

			return false;
		}
	}

	// Add aditional video settings (e.g. Graphics Presets, Zoom Level, ...)
	[HarmonyPatch(typeof(VideoOptions))]
	[HarmonyPatch(MethodType.Constructor)]
	public class VideoOptions__ctor
	{
		public static int ITEM_GFX_PRESET;
		public static int ITEM_ZOOM_LEVEL;
		public static int ITEM_MAX_LEVEL;
		public static int ITEM_ADDED;

		public static int gfxPreset = 1;
		public static int zoomLevel = 4;

		static void Postfix(VideoOptions __instance)
		{
			MenuItem[] array = __instance.item;
			MenuItem[] arrayBigger = new MenuItem[array.Length + 2];

			// Original stuff
			Array.Copy(array, arrayBigger, array.Length - 2);

			int i = array.Length - 2;
			arrayBigger[ITEM_GFX_PRESET = i++] = new MenuItem(1, new string[] {
				"Preset: High",
				"Preset: Medium",
				"Preset: Low",
				"Preset: Performance",
				"Preset: Decimated"
			});
			arrayBigger[ITEM_ZOOM_LEVEL = i++] = new MenuItem(1, new string[] {
				"Zoom Level: 45%",
				"Zoom Level: 50%",
				"Zoom Level: 55%",
				"Zoom Level: 60%",
				"Zoom Level: 65%",
				"Zoom Level: 70%",
				"Zoom Level: 75%",
				"Zoom Level: 80%",
				"Zoom Level: 85%",
				"Zoom Level: 90%",
				"Zoom Level: 95%",
				"Zoom Level: 100%"
			});

			ITEM_MAX_LEVEL = i;
			ITEM_ADDED = i - ITEM_GFX_PRESET;

			// Back & Apply
			arrayBigger[i++] = array[array.Length - 2];
			arrayBigger[i++] = array[array.Length - 1];

			__instance.item = arrayBigger;
		}
	}

	// Default values for the new video options!
	[HarmonyPatch(typeof(VideoOptions), nameof(VideoOptions.Init))]
	public class VideoOptions_Init
	{
		static void Postfix(VideoOptions __instance)
		{
			__instance.item[VideoOptions__ctor.ITEM_GFX_PRESET].selX = VideoOptions__ctor.gfxPreset;
			__instance.item[VideoOptions__ctor.ITEM_ZOOM_LEVEL].selX = VideoOptions__ctor.zoomLevel;
		}
	}

	// Apply changes to the new video options and save them as soon as the user
	// interacts with them.
	[HarmonyPatch(typeof(VideoOptions), nameof(VideoOptions.Select))]
	public class VideoOptions_Select
	{
		static bool Prefix(VideoOptions __instance, Player p, int o)
		{
			if (
				__instance.selected >= VideoOptions__ctor.ITEM_GFX_PRESET &&
				__instance.selected <  VideoOptions__ctor.ITEM_MAX_LEVEL
			)
			{
				return false;
			}
			else
			{
				if (__instance.selected >= VideoOptions__ctor.ITEM_MAX_LEVEL) {
					__instance.selected -= VideoOptions__ctor.ITEM_ADDED;
				}
				
				return true;
			}
		}
	}

	[HarmonyPatch(typeof(VideoOptions), nameof(VideoOptions.SelectedUpdate))]
	public class VideoOptions_SelectedUpdate
	{
		static bool Prefix(VideoOptions __instance, Player p)
		{
			// User changed something? save.
			if (
				VideoOptions__ctor.gfxPreset != __instance.item[VideoOptions__ctor.ITEM_GFX_PRESET].selX ||
				VideoOptions__ctor.zoomLevel != __instance.item[VideoOptions__ctor.ITEM_ZOOM_LEVEL].selX
			)
			{
				VideoOptions__ctor.gfxPreset = __instance.item[VideoOptions__ctor.ITEM_GFX_PRESET].selX;
				VideoOptions__ctor.zoomLevel = __instance.item[VideoOptions__ctor.ITEM_ZOOM_LEVEL].selX;
				ConfigMgr.WriteData();
			}

			return true;
		}
	}

	// Make the Skill Tree selector significantly larger, otherwise it's impossible to read the icons on
	// the OGA and RG351P screens, which are tiny 3.5' 480x320 displays.
	[HarmonyPatch(typeof(SkillTreeDraw), nameof(SkillTreeDraw.Draw))]
	public class SkillTreeDraw_Draw
	{
		public static bool Prefix(SkillTreeDraw __instance, Texture2D interfaceTex, XTexture logoSegsTex, int selItem, PlayerStats pStats, int pearlCount, bool[] nodeCanUnlock, out float __state)
		{
			__state = __instance.zoom;
			__instance.zoom *= 1.50f;
			return true;
		}

		public static void Postfix(SkillTreeDraw __instance, Texture2D interfaceTex, XTexture logoSegsTex, int selItem, PlayerStats pStats, int pearlCount, bool[] nodeCanUnlock, float __state)
		{
			__instance.zoom = __state;
		}
	}

	// Change the default lightmap effect to require less fillrate
	[HarmonyPatch(typeof(GlowMgr), MethodType.Constructor, new Type[] { typeof(ContentManager) })]
	public class GlowMgr__ctor
	{
		public static void Postfix(GlowMgr __instance, ContentManager Content)
		{
			__instance.lightEffect = Content.Load<Effect>("fx/SimplifiedLight.fxb");
			Console.WriteLine("Loaded reduced Light Map Effect.");
		}
	}

	// Change the default gaussian blur effect to require less fillrate
	[HarmonyPatch(typeof(BloomComponent), nameof(BloomComponent.Init))]
	public class BloomComponent_Init
	{
		public static void Postfix(GraphicsDevice _dev, ContentManager Content)
		{
			BloomComponent.gaussianBlurEffect = Content.Load<Effect>("fx/SimplifiedGaussianBlur.fxb");
			Console.WriteLine("Loaded reduced Gaussian Blur Effect.");
		}
	}

	[HarmonyPatch(typeof(LayerTintCatalog), nameof(LayerTintCatalog.SetBloomTint))]
	public class LayerTintCatalog_SetBloomTint
	{
		public static Effect lastEffect = null;
		public static EffectParameter sat;
		public static EffectParameter tintColor;
		public static EffectParameter tint;

		public static bool Prefix(Effect bloomTintEffect, Player p, int l, int layer, int pLayer, float layerProg, float detailFac)
		{
			if ((bloomTintEffect == GameDraw.detailBloomTintEffect) || (bloomTintEffect == GameDraw.pmaEffect))
				return true;

			if (bloomTintEffect != lastEffect)
			{
				lastEffect = bloomTintEffect;
				sat = bloomTintEffect.Parameters["sat"];
				tintColor = bloomTintEffect.Parameters["tintColor"];
				tint = bloomTintEffect.Parameters["tint"];
			}

			if (layer == -1 || pLayer == -1)
			{
				return false;
			}
			float num = LayerTintCatalog.layerTintData[pLayer].layerTintLayer[l].r + (LayerTintCatalog.layerTintData[layer].layerTintLayer[l].r - LayerTintCatalog.layerTintData[pLayer].layerTintLayer[l].r) * layerProg;
			float num2 = LayerTintCatalog.layerTintData[pLayer].layerTintLayer[l].g + (LayerTintCatalog.layerTintData[layer].layerTintLayer[l].g - LayerTintCatalog.layerTintData[pLayer].layerTintLayer[l].g) * layerProg;
			float num3 = LayerTintCatalog.layerTintData[pLayer].layerTintLayer[l].b + (LayerTintCatalog.layerTintData[layer].layerTintLayer[l].b - LayerTintCatalog.layerTintData[pLayer].layerTintLayer[l].b) * layerProg;
			float num4 = LayerTintCatalog.layerTintData[pLayer].layerTintLayer[l].sat + (LayerTintCatalog.layerTintData[layer].layerTintLayer[l].sat - LayerTintCatalog.layerTintData[pLayer].layerTintLayer[l].sat) * layerProg;
			float value = LayerTintCatalog.layerTintData[pLayer].layerTintLayer[l].tint + (LayerTintCatalog.layerTintData[layer].layerTintLayer[l].tint - LayerTintCatalog.layerTintData[pLayer].layerTintLayer[l].tint) * layerProg;
			bool flag = false;
			if (layer == 7 || layer == 12)
			{
				flag = true;
			}
			if (flag)
			{
				float num5 = MapMgr.lightningFrame;
				if (num5 < 0.3f)
				{
					if (num5 < 0.1f)
					{
						num5 *= 10f;
					}
					else if (num5 < 0.25f)
					{
						num5 = 1f;
					}
					else if (num5 < 0.3f)
					{
						num5 = (0.3f - num5) * 20f;
					}
					else
					{
						num5 = 0f;
					}
					if (num5 > 0f)
					{
						switch (l)
						{
						case 0:
							num5 *= 0.5f;
							break;
						case 1:
							num5 *= 0.4f;
							break;
						case 2:
							num5 *= 0.3f;
							break;
						case 3:
							num5 *= 0.2f;
							break;
						case 4:
							num5 *= 0.1f;
							break;
						}
						num5 *= 0.5f;
						num += num5;
						num2 += num5;
						num3 += num5;
						num4 *= num5;
					}
				}
			}
			if (p != null && p.camMgr.scarecrowfreak > 0f)
			{
				float num6 = 1f;
				switch (l)
				{
				case 0:
				case 12:
					num6 = 1f;
					break;
				case 1:
				case 13:
					num6 = 0.95f;
					break;
				case 2:
					num6 = 0.9f;
					break;
				case 3:
				case 14:
					num6 = 0.8f;
					break;
				case 4:
					num6 = 0.7f;
					break;
				}
				num6 *= p.camMgr.scarecrowfreak;
				num *= 1f - num6;
				num2 *= 1f - num6;
				num3 *= 1f - num6;
			}
			tintColor.SetValue(new Vector3(num, num2, num3));
			sat.SetValue(num4);
			tint.SetValue(value);
			return false;
		}
	}

	// Correct the color packing... Saves a few instructions for fullscreen effects...
	[HarmonyPatch(typeof(LayerTintCatalog), nameof(LayerTintCatalog.PrepareMainEffect))]
	public class LayerTintCatalog_PrepareMainEffect
	{
		public static bool Prefix(Effect mainEffect, int layer, int pLayer, float layerProg, Player p)
		{
			// Ooops... not one of the new effects! Use the original function.
			if (mainEffect == GameDraw.mainEffect)
				return true;

			if (layer == -1 || pLayer == -1)
			{
				return false;
			}
			LayerTintCatalog.LayerTintData[] array = LayerTintCatalog.layerTintData;
			LayerTintCatalog.LayerTintData[] array2 = LayerTintCatalog.layerTintData;
			LayerTintCatalog.LayerTintData[] array3 = LayerTintCatalog.layerTintData;
			LayerTintCatalog.dev.Textures[1] = LayerTintCatalog.parchmentTex;
			MapMgr.glowMgr.alpha = LayerTintCatalog.layerTintData[pLayer].lightMap + (LayerTintCatalog.layerTintData[layer].lightMap - LayerTintCatalog.layerTintData[pLayer].lightMap) * layerProg;
			mainEffect.Parameters["tColor"].SetValue(new Vector3(
					LayerTintCatalog.layerTintData[pLayer].tR + (LayerTintCatalog.layerTintData[layer].tR - LayerTintCatalog.layerTintData[pLayer].tR) * layerProg,
					LayerTintCatalog.layerTintData[pLayer].tG + (LayerTintCatalog.layerTintData[layer].tG - LayerTintCatalog.layerTintData[pLayer].tG) * layerProg,
					LayerTintCatalog.layerTintData[pLayer].tB + (LayerTintCatalog.layerTintData[layer].tB - LayerTintCatalog.layerTintData[pLayer].tB) * layerProg)
			);

			mainEffect.Parameters["bColor"].SetValue(new Vector3(
				LayerTintCatalog.layerTintData[pLayer].bR + (LayerTintCatalog.layerTintData[layer].bR - LayerTintCatalog.layerTintData[pLayer].bR) * layerProg,
				LayerTintCatalog.layerTintData[pLayer].bG + (LayerTintCatalog.layerTintData[layer].bG - LayerTintCatalog.layerTintData[pLayer].bG) * layerProg,
				LayerTintCatalog.layerTintData[pLayer].bB + (LayerTintCatalog.layerTintData[layer].bB - LayerTintCatalog.layerTintData[pLayer].bB) * layerProg)
			);

			mainEffect.Parameters["k"].SetValue(0f);
			mainEffect.Parameters["kcube"].SetValue(0.03f);
			float num = (LayerTintCatalog.layerTintData[pLayer].brite + (LayerTintCatalog.layerTintData[layer].brite - LayerTintCatalog.layerTintData[pLayer].brite) * layerProg) * 0.75f;
			BloomComponent.bloomBase = LayerTintCatalog.layerTintData[pLayer].bloomBase + (LayerTintCatalog.layerTintData[layer].bloomBase - LayerTintCatalog.layerTintData[pLayer].bloomBase) * layerProg;
			BloomComponent.bloomIntensity = LayerTintCatalog.layerTintData[pLayer].bloomIntensity + (LayerTintCatalog.layerTintData[layer].bloomIntensity - LayerTintCatalog.layerTintData[pLayer].bloomIntensity) * layerProg;
			BloomComponent.bloomSat = LayerTintCatalog.layerTintData[pLayer].bloomSat + (LayerTintCatalog.layerTintData[layer].bloomSat - LayerTintCatalog.layerTintData[pLayer].bloomSat) * layerProg;
			BloomComponent.bloomThreshhold = LayerTintCatalog.layerTintData[pLayer].bloomThreshhold + (LayerTintCatalog.layerTintData[layer].bloomThreshhold - LayerTintCatalog.layerTintData[pLayer].bloomThreshhold) * layerProg;
			BloomComponent.floorValue = LayerTintCatalog.layerTintData[pLayer].floorVal + (LayerTintCatalog.layerTintData[layer].floorVal - LayerTintCatalog.layerTintData[pLayer].floorVal) * layerProg;
			float num2 = LayerTintCatalog.layerTintData[pLayer].sat + (LayerTintCatalog.layerTintData[layer].sat - LayerTintCatalog.layerTintData[pLayer].sat) * layerProg;
			float num3 = LayerTintCatalog.layerTintData[pLayer].gamma + (LayerTintCatalog.layerTintData[layer].gamma - LayerTintCatalog.layerTintData[pLayer].gamma) * layerProg;
			float num4 = LayerTintCatalog.layerTintData[pLayer].burnR + (LayerTintCatalog.layerTintData[layer].burnR - LayerTintCatalog.layerTintData[pLayer].burnR) * layerProg;
			float num5 = LayerTintCatalog.layerTintData[pLayer].burnG + (LayerTintCatalog.layerTintData[layer].burnG - LayerTintCatalog.layerTintData[pLayer].burnG) * layerProg;
			float num6 = LayerTintCatalog.layerTintData[pLayer].burnB + (LayerTintCatalog.layerTintData[layer].burnB - LayerTintCatalog.layerTintData[pLayer].burnB) * layerProg;
			if (GameStateManager.flashingEndFrame > 2f)
			{
				num3 += (GameStateManager.flashingEndFrame - 2f) * 0.3f;
				num += (GameStateManager.flashingEndFrame - 2f) * 0.5f;
			}
			if (p.respawnFrame > 0f)
			{
				BloomComponent.bloomBase = 1f - p.respawnFrame;
				if (BloomComponent.bloomBase < 0.2f)
				{
					BloomComponent.bloomBase = 0.2f;
				}
				BloomComponent.bloomThreshhold -= p.respawnFrame;
				if (BloomComponent.bloomThreshhold < 0.2f)
				{
					BloomComponent.bloomThreshhold = 0.2f;
				}
				num3 -= p.respawnFrame * 0.2f;
				if (num3 < -0.1f)
				{
					num3 = -0.1f;
				}
				num2 -= p.respawnFrame * 0.2f;
				if (num2 < 0.3f)
				{
					num2 = 0.3f;
				}
			}
			if (p.fastTravelFrame > 1f && p.fastTravelFrame < 3f)
			{
				float num7 = 3f - p.fastTravelFrame;
				if (p.fastTravelFrame < 2f)
				{
					num7 = p.fastTravelFrame - 1f;
				}
				BloomComponent.bloomBase = 1f - num7;
				if (BloomComponent.bloomBase < 0.2f)
				{
					BloomComponent.bloomBase = 0.2f;
				}
				num3 -= num7 * 0.2f;
				if (num3 < -0.1f)
				{
					num3 = -0.1f;
				}
				num2 -= num7 * 0.2f;
				if (num2 < 0.3f)
				{
					num2 = 0.3f;
				}
			}
			MapMgr.glowMgr.lightFac = LayerTintCatalog.layerTintData[pLayer].lightFac + (LayerTintCatalog.layerTintData[layer].lightFac - LayerTintCatalog.layerTintData[pLayer].lightFac) * layerProg;
			BloomComponent.lightThresh = LayerTintCatalog.layerTintData[pLayer].lightThresh + (LayerTintCatalog.layerTintData[layer].lightThresh - LayerTintCatalog.layerTintData[pLayer].lightThresh) * layerProg;
			BloomComponent.lightBlue = LayerTintCatalog.layerTintData[pLayer].lightBlue + (LayerTintCatalog.layerTintData[layer].lightBlue - LayerTintCatalog.layerTintData[pLayer].lightBlue) * layerProg;
			BloomComponent.lightRed = LayerTintCatalog.layerTintData[pLayer].lightRed + (LayerTintCatalog.layerTintData[layer].lightRed - LayerTintCatalog.layerTintData[pLayer].lightRed) * layerProg;
			BloomComponent.lightFac = ((LayerTintCatalog.layerTintData[pLayer].lightMap > 0f) ? 1f : 0f) + (((LayerTintCatalog.layerTintData[layer].lightMap > 0f) ? 1f : 0f) - ((LayerTintCatalog.layerTintData[pLayer].lightMap > 0f) ? 1f : 0f)) * layerProg;
			BloomComponent.lightDesat = LayerTintCatalog.layerTintData[pLayer].lightDesat + (LayerTintCatalog.layerTintData[layer].lightDesat - LayerTintCatalog.layerTintData[pLayer].lightDesat) * layerProg;
			BloomComponent.darkBlur = LayerTintCatalog.layerTintData[pLayer].darkBlur + (LayerTintCatalog.layerTintData[layer].darkBlur - LayerTintCatalog.layerTintData[pLayer].darkBlur) * layerProg;
			Character playerCharacter = CharMgr.GetPlayerCharacter(p);
			if (p.levelupFrame > 0f)
			{
				float num8 = 0f;
				if (p.levelupFrame > 2f && p.levelupFrame < 4f)
				{
					num8 = (4f - p.levelupFrame) / 4f;
				}
				if (p.levelupFrame < 2.1f)
				{
					num8 = p.levelupFrame / 1.5f;
				}
				BloomComponent.bloomIntensity += num8;
				BloomComponent.bloomSat += num8;
			}
			float runeGetFrame = p.runeGetFrame;
			if (playerCharacter != null)
			{
				float num9 = playerCharacter.buffs.GetLight();
				if (num9 > 0f)
				{
					float num10 = LayerTintCatalog.layerTintData[pLayer].lightMap + (LayerTintCatalog.layerTintData[layer].lightMap - LayerTintCatalog.layerTintData[pLayer].lightMap) * layerProg;
					if (num10 > 0f)
					{
						if (num10 < 0.2f)
						{
							num9 *= num10 * 5f;
						}
						BloomComponent.bloomIntensity += num9;
						BloomComponent.bloomSat -= num9 * 0.5f;
						if (BloomComponent.bloomSat < 0f)
						{
							BloomComponent.bloomSat = 0f;
						}
					}
				}
			}
			if (GameStateManager.coopPlayerIdx > -1)
			{
				BloomComponent.bloomVignette = 0f;
			}
			else
			{
				BloomComponent.bloomVignette = 0.5f;
			}
			p.camMgr.dotsMgr.dotsAlpha = LayerTintCatalog.layerTintData[pLayer].dotsAlpha + (LayerTintCatalog.layerTintData[layer].dotsAlpha - LayerTintCatalog.layerTintData[pLayer].dotsAlpha) * layerProg;
			p.camMgr.dotsMgr.snowAlpha = LayerTintCatalog.layerTintData[pLayer].snowAlpha + (LayerTintCatalog.layerTintData[layer].snowAlpha - LayerTintCatalog.layerTintData[pLayer].snowAlpha) * layerProg;
			p.camMgr.dotsMgr.rainAlpha = LayerTintCatalog.layerTintData[pLayer].rainAlpha + (LayerTintCatalog.layerTintData[layer].rainAlpha - LayerTintCatalog.layerTintData[pLayer].rainAlpha) * layerProg;
			p.camMgr.dotsMgr.leavesAlpha = LayerTintCatalog.layerTintData[pLayer].leavesAlpha + (LayerTintCatalog.layerTintData[layer].leavesAlpha - LayerTintCatalog.layerTintData[pLayer].leavesAlpha) * layerProg;
			Character playerCharacter2 = CharMgr.GetPlayerCharacter(p);
			if (playerCharacter2 != null)
			{
				int sanctuaryIn = MapMgr.sanctuaryMgr.GetSanctuaryIn(playerCharacter2);
				if (sanctuaryIn > -1)
				{
					float num11 = MapMgr.sanctuaryMgr.sanctuaries[sanctuaryIn].claimFrame;
					float num12 = 1f;
					if (layer != pLayer)
					{
						num12 = layerProg;
					}
					num11 = 0.25f + num11 * 0.75f;
					if (num11 > 1f)
					{
						num11 = 1f;
					}
					if (MapMgr.sanctuaryMgr.sanctuaries[sanctuaryIn].shrine)
					{
						num4 -= num11 * 2f * num12;
						num5 -= num11 * 2f * num12;
						num6 -= num11 * 2f * num12;
						num += num11 * 0.1f * num12;
						num11 *= 0.75f;
					}
					num2 += (num2 * num11 - num2) * num12;
					num11 -= 1f;
					num11 *= 0.3f;
					num3 += num11 * num12;
					if (MapMgr.sanctuaryMgr.sanctuaries[sanctuaryIn].desecrationAlpha > 0f)
					{
						float desecrationAlpha = MapMgr.sanctuaryMgr.sanctuaries[sanctuaryIn].desecrationAlpha;
						num5 -= desecrationAlpha * num12;
						num6 -= desecrationAlpha * num12;
					}
					if (MapMgr.sanctuaryMgr.sanctuaries[sanctuaryIn].creed == 4)
					{
						p.camMgr.dotsMgr.leavesAlpha += (1f - num11) * num12;
					}
				}
				else if (p.pSanctIn > -1 && layer != pLayer)
				{
					float num13 = MapMgr.sanctuaryMgr.sanctuaries[p.pSanctIn].claimFrame;
					float num14 = 1f - layerProg;
					num13 = 0.25f + num13 * 0.75f;
					if (num13 > 1f)
					{
						num13 = 1f;
					}
					if (MapMgr.sanctuaryMgr.sanctuaries[p.pSanctIn].shrine)
					{
						num4 -= num13 * 2f * num14;
						num5 -= num13 * 2f * num14;
						num6 -= num13 * 2f * num14;
						num += num13 * 0.1f * num14;
						num13 *= 0.75f;
					}
					num2 += (num2 * num13 - num2) * num14;
					num13 -= 1f;
					num13 *= 0.3f;
					num3 += num13 * num14;
					if (MapMgr.sanctuaryMgr.sanctuaries[p.pSanctIn].desecrationAlpha > 0f)
					{
						float desecrationAlpha2 = MapMgr.sanctuaryMgr.sanctuaries[p.pSanctIn].desecrationAlpha;
						num5 -= desecrationAlpha2 * num14;
						num6 -= desecrationAlpha2 * num14;
					}
					if (MapMgr.sanctuaryMgr.sanctuaries[p.pSanctIn].creed == 4)
					{
						p.camMgr.dotsMgr.leavesAlpha += (1f - num13) * num14;
					}
				}
				if (layer == pLayer)
				{
					p.pSanctIn = sanctuaryIn;
				}
			}
			if (p != null && p.camMgr.scarecrowfreak > 0f)
			{
				num2 *= 1f - p.camMgr.scarecrowfreak;
				num4 -= p.camMgr.scarecrowfreak * 2f;
				num5 -= p.camMgr.scarecrowfreak * 2f;
				num6 -= p.camMgr.scarecrowfreak * 2f;
			}
			if (layer != 7)
			{
				if (layer == 12)
				{
					float num15 = MapMgr.lightningFrame;
					if (num15 < 0.3f)
					{
						if (num15 < 0.1f)
						{
							num15 *= 10f;
						}
						else if (num15 < 0.25f)
						{
							num15 = 1f;
						}
						else if (num15 < 0.3f)
						{
							num15 = (0.3f - num15) * 20f;
						}
						else
						{
							num15 = 0f;
						}
						if (num15 > 0f)
						{
							num4 += num15 * 2f;
							num5 += num15 * 2f;
							num6 += num15 * 2f;
							num += num15 * 0.1f;
						}
						num15 = MapMgr.lightningFrame;
						if (num15 < 0.1f)
						{
							if (num15 > 0.05f)
							{
								num15 = 0.1f - num15;
							}
							num15 *= 10f;
							num += num15;
						}
					}
				}
			}
			else
			{
				float num16 = MapMgr.lightningFrame;
				if (num16 < 0.3f)
				{
					if (num16 < 0.1f)
					{
						num16 *= 10f;
					}
					else if (num16 < 0.25f)
					{
						num16 = 1f;
					}
					else if (num16 < 0.3f)
					{
						num16 = (0.3f - num16) * 20f;
					}
					else
					{
						num16 = 0f;
					}
					if (num16 > 0f)
					{
						num += num16 * 4f;
						num2 *= 1f - num16 * 0.8f;
						num3 -= num16 * 0.2f;
					}
				}
			}
			mainEffect.Parameters["burnColor"].SetValue(new Vector3(num4, num5, num6));
			mainEffect.Parameters["brite"].SetValue(num);
			if (GameStateManager.newGameFrame > 0f)
			{
				num3 += GameStateManager.newGameFrame * 1.2f;
				num2 -= GameStateManager.newGameFrame;
				if (num2 < 0f)
				{
					num2 = 0f;
				}
			}
			mainEffect.Parameters["gamma"].SetValue(num3);
			BloomComponent.baseSat = num2;
			return false;
		}
	}

	// Change the default parchment effects to be a bit less fillrate intensive
	[HarmonyPatch(typeof(LayerTintCatalog), nameof(LayerTintCatalog.Init))]
	public class LayerTintCatalog_Init
	{
		public static void Postfix(ContentManager Content, GraphicsDevice device)
		{
			LayerTintCatalog.parchmentEffect = Content.Load<Effect>("fx/SimplifiedParchment.fxb");
			LayerTintCatalog.gameParchEffect = Content.Load<Effect>("fx/SimplifiedGameParchment.fxb");
			Console.WriteLine("Loaded optimized Parchment Effects.");
		}
	}

	// Save the new options back to the config file
	[HarmonyPatch(typeof(ConfigMgr), nameof(ConfigMgr.WriteData))]
	public static class ConfigMgr_WriteData
	{
		public static void AddMissingOptions(List<string> list)
		{
			list.Add("gfxpreset=" + VideoOptions__ctor.gfxPreset.ToString());
			list.Add("zoomlevel=" + VideoOptions__ctor.zoomLevel.ToString());
		}

		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			Console.WriteLine($"Patching ConfigMgr at ConfigMgr:WriteData...");
			var codes = new List<CodeInstruction>(instructions);
			for (int i = 0; i < codes.Count-5; i++)
			{

				if (
					codes[i].opcode   == OpCodes.Ldsfld   &&                                                            // 144    0266    ldsfld     string ProjectTower.config.ConfigMgr::OSConfigDir
					codes[i+1].opcode == OpCodes.Ldstr    && (string)codes[i+1].operand == "config.ini"              && // 145    026B    ldstr      "config.ini"
					codes[i+2].opcode == OpCodes.Call     && codes[i+2].operand.ToString().Contains("Combine")       && // 146    0270    call       string [mscorlib]System.IO.Path::Combine(string, string)
					/* codes[i+3].opcode == OpCodes.Ldloc_0  &&                                                     */  // 147    0275    ldloc.0
					codes[i+4].opcode == OpCodes.Callvirt && codes[i+4].operand.ToString().Contains("ToArray")       && // 148    0276    callvirt   instance !0[] class [mscorlib]System.Collections.Generic.List`1<string>::ToArray()
					codes[i+5].opcode == OpCodes.Call     && codes[i+5].operand.ToString().Contains("WriteAllLines")    // 149    027B    call       void [mscorlib]System.IO.File::WriteAllLines(string, string[])
				)
				{
					// unlink label so we can set it at our new jump point
					var lbl = codes[i].labels;
					codes[i].labels = null;
					MethodInfo AddMissingOptionsMethod = typeof(ConfigMgr_WriteData).GetMethod("AddMissingOptions", BindingFlags.Public | BindingFlags.Static);
					List<CodeInstruction> newCodes = new List<CodeInstruction>();
					newCodes.Add(new CodeInstruction(codes[i+3])  { labels = lbl } );
					newCodes.Add(new CodeInstruction(OpCodes.Call, AddMissingOptionsMethod));
					Console.WriteLine($"Patched ConfigMgr at ConfigMgr:WriteData+{i}!");
					codes.InsertRange(i, newCodes);
					break;
				}
			}
			
			return codes.AsEnumerable();
		}
	}

	// Parse the new options from the config file
	[HarmonyPatch(typeof(ConfigMgr), nameof(ConfigMgr.Read))]
	public static class ConfigMgr_Read
	{
		public static void AddMissingOptions(string[] list)
		{
			if (list != null && list[0] != null)
			{
				switch(list[0])
				{
					case "gfxpreset":
						VideoOptions__ctor.gfxPreset = Convert.ToInt32(list[1]);
						break;
					case "zoomlevel":
						VideoOptions__ctor.zoomLevel = Convert.ToInt32(list[1]);
						break;
					default:
						break;
				}
			}
		}

		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			Console.WriteLine($"Patching ConfigMgr at ConfigMgr:Read...");
			var codes = new List<CodeInstruction>(instructions);
			for (int i = 0; i < codes.Count-8; i++)
			{
				// 75    00E7    ldloc.s   V_5 (5)
				// 76    00E9    ldc.i4.1  
				// 77    00EA    newarr    [mscorlib]System.Char
				// 78    00EF    dup       
				// 79    00F0    ldc.i4.0  
				// 80    00F1    ldc.i4.s  0x3D
				// 81    00F3    stelem.i2 
				// 82    00F4    callvirt  instance string[] [mscorlib]System.String::Split(char[])
				// 83    00F9    stloc.s   V_6 (6) <--- what we want

				if (
					codes[i].opcode   == OpCodes.Ldloc_S   &&                                                    // 75    00E7    ldloc.s   V_5 (5)
					codes[i+1].opcode == OpCodes.Ldc_I4_1  &&                                                    // 76    00E9    ldc.i4.1  
					codes[i+2].opcode == OpCodes.Newarr    && codes[i+2].operand.ToString().Contains("Char")  && // 77    00EA    newarr    [mscorlib]System.Char
					codes[i+3].opcode == OpCodes.Dup       &&                                                    // 78    00EF    dup       
					codes[i+4].opcode == OpCodes.Ldc_I4_0  &&                                                    // 79    00F0    ldc.i4.0  
					codes[i+5].opcode == OpCodes.Ldc_I4_S  && (SByte)codes[i+5].operand == 0x3D               && // 80    00F1    ldc.i4.s  0x3D
					codes[i+6].opcode == OpCodes.Stelem_I2 &&                                                    // 81    00F3    stelem.i2 
					codes[i+7].opcode == OpCodes.Callvirt  && codes[i+7].operand.ToString().Contains("Split") && // 82    00F4    callvirt  instance string[] [mscorlib]System.String::Split(char[])
					codes[i+8].opcode == OpCodes.Stloc_S                                                         // 83    00F9    stloc.s   V_6 (6)
				)
				{
					LocalBuilder reloc = codes[i+8].operand as LocalBuilder;
					Console.WriteLine($"{codes[i+8].operand.GetType().Name}");
					MethodInfo AddMissingOptionsMethod = typeof(ConfigMgr_Read).GetMethod("AddMissingOptions", BindingFlags.Public | BindingFlags.Static);
					List<CodeInstruction> newCodes = new List<CodeInstruction>();
					newCodes.Add(new CodeInstruction(OpCodes.Ldloc_S, reloc.LocalIndex));
					newCodes.Add(new CodeInstruction(OpCodes.Call, AddMissingOptionsMethod));
					Console.WriteLine($"Patched ConfigMgr at ConfigMgr:Read+{i+9}! (reloc: {reloc.LocalIndex})");
					codes.InsertRange(i+9, newCodes);
					break;
				}
			}
			
			return codes.AsEnumerable();
		}
	}

	[HarmonyPatch(typeof(Game1), nameof(Game1.Initialize))]
	public static class Game1_Initialize
	{
		public static Game1 game = null;
		public static void changeDefaults(Game1 gameInstance)
		{
			List<Point> modes = VideoOptions.GetResolutions(Game1.graphics.GraphicsDevice);
			ConfigMgr.displayWidth = modes[0].X;
			ConfigMgr.displayHeight = modes[0].Y;
			ConfigMgr.hudVis = 1;
			ConfigMgr.hudSize = 3;
			Game1_Initialize.game = gameInstance;
			Console.WriteLine($"Choosing default resolution {ConfigMgr.displayWidth}x{ConfigMgr.displayHeight}.");
		}

		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			Console.WriteLine($"Patching Game1 at Game1:Initialize...");
			var codes = new List<CodeInstruction>(instructions);
			for (int i = 0; i < codes.Count-8; i++)
			{
				if (
					codes[i].opcode   == OpCodes.Ldc_I4 && (int)codes[i].operand   == 1920                         && // 8	0018	ldc.i4	0x780
					codes[i+1].opcode == OpCodes.Stsfld && codes[i+1].operand.ToString().Contains("displayWidth")  && // 9	001D	stsfld	int32 ProjectTower.config.ConfigMgr::displayWidth
					codes[i+2].opcode == OpCodes.Ldc_I4 && (int)codes[i+2].operand == 1080                         && // 10	0022	ldc.i4	0x438
					codes[i+3].opcode == OpCodes.Stsfld && codes[i+3].operand.ToString().Contains("displayHeight")    // 11	0027	stsfld	int32 ProjectTower.config.ConfigMgr::displayHeight
				)
				{
					MethodInfo changeDefaultsMethod = typeof(Game1_Initialize).GetMethod("changeDefaults", BindingFlags.Public | BindingFlags.Static);
					List<CodeInstruction> newCodes = new List<CodeInstruction>();
					newCodes.Add(new CodeInstruction(OpCodes.Ldarg_0));
					newCodes.Add(new CodeInstruction(OpCodes.Call, changeDefaultsMethod));
					Console.WriteLine($"Patched Game1 at Game1:Initialize+{i}!");
					codes.RemoveRange(i, 4);
					codes.InsertRange(i, newCodes);
					break;
				}
			}
			
			return codes.AsEnumerable();
		}
	}

	// Move the HUD up by 30pt (pre-scaled size)
	[HarmonyPatch(typeof(PlayerDraw), nameof(PlayerDraw.DrawStatusBars))]
	public static class PlayerDraw_DrawStatusBars
	{
		public static bool Prefix(PlayerDraw __instance, float scale, Character c, ref Vector2 tL, ref Vector2 bR, float w, float alpha, bool flip)
		{
			tL.Y -= 30f * scale;
			tL.X -= 30f * scale;
			bR.Y += 30f * scale;
			return true;
		}
	}

	[HarmonyPatch(typeof(Prompt), nameof(Prompt.Draw))]
	public class Prompt_Draw
	{
		public static float GetPromptScale()
		{
			float scaleX = ScrollManager.screenSize.X / 960f;
			float scaleY = ScrollManager.screenSize.Y / 544f;
			float scale = (scaleX < scaleY) ? scaleX : scaleY;

			// We don't want this to be toooo small...
			if (ScrollManager.screenSize.Y <= 480f)
			{
				scale *= 1.40f;
			}

			return scale;
		}

		public static Rectangle GetTextRect(Player p, StringBuilder s, float scale)
		{
			Rectangle rectangle = new Rectangle(0, 0, (int)Text.GetStringSpace(s, 0.55f, p, 0) + 50, 70);
			rectangle.X = (int)(rectangle.X * scale);
			rectangle.Y = (int)(rectangle.Y * scale);
			rectangle.Width = (int)(rectangle.Width * scale);
			rectangle.Height = (int)(rectangle.Height * scale);

			rectangle.X = (int)ScrollManager.screenSize.X / 2 - rectangle.Width / 2;
			rectangle.Y = (int)ScrollManager.screenSize.Y - (int)(180f * scale);
			if (GameStateManager.coopPlayerIdx > -1)
			{
				rectangle.X += (int)ScrollManager.screenSize.X / 4 * ((p.ID == GameStateManager.mainPlayerIdx) ? -1 : 1);
			}
			return rectangle;
		}


		public static bool Prefix(Prompt __instance, Player p)
		{
			float scale = Prompt_Draw.GetPromptScale();
			int num = __instance.prompt;
			if (num <= 1 || num == 4)
			{
				Text.DrawText(InterfaceRender.CHAR_B, ScrollManager.GetScreenLoc(__instance.loc, 0), new Color(1f, 1f, 1f, __instance.alpha), 0.65f * scale, 1, p, 2);
				return false;
			}
			if (__instance.prompt == 3 && __instance.msgIdx == 5)
			{
				Text.DrawText(InterfaceRender.CHAR_B, ScrollManager.GetScreenLoc(__instance.loc, 0), new Color(1f, 1f, 1f, __instance.alpha), 0.65f * scale, 1, p, 2);
				return false;
			}
			Rectangle textRect = Prompt_Draw.GetTextRect(p, __instance.msg[__instance.msgIdx], scale);
			InterfaceRender.DrawRect(textRect, __instance.alpha * 0.7f, 4);
			Text.DrawText(__instance.msg[__instance.msgIdx], new Vector2((float)textRect.Center.X, (float)textRect.Center.Y), new Color(1f, 1f, 1f, __instance.alpha), 0.55f * scale, 1, p, 2);
			return false;
		}
	}


	// This seems to affect only the non-interactive HUD stuff, for interactions like
	// "[RB] To Claim Sanctuary", see the Prompt.Draw patch.
	[HarmonyPatch(typeof(PlayerPrompts), nameof(PlayerPrompts.Draw))]
	public class PlayerPrompts_Draw
	{
		public static bool Prefix(PlayerPrompts __instance)
		{
			float scale = Prompt_Draw.GetPromptScale();
			if (__instance.messageFrame > 0f && __instance.message != null)
			{
				float num;
				if (__instance.messageFrame < 0.5f)
				{
					num = __instance.messageFrame * 2f;
				}
				else if (__instance.messageFrame < 2.5f)
				{
					num = 1f;
				}
				else
				{
					num = (3f - __instance.messageFrame) * 2f;
				}
				Rectangle textRect = Prompt_Draw.GetTextRect(__instance.p, __instance.message, scale);
				textRect.Y -= (int)(100f * scale);
				InterfaceRender.DrawRect(textRect, num * 0.7f, 4);
				Text.DrawText(__instance.message, new Vector2((float)textRect.Center.X, (float)textRect.Center.Y), new Color(1f, 1f, 1f, num), 0.55f * scale, 1, __instance.p, 2);
			}
			for (int i = 0; i < __instance.prompt.Length; i++)
			{
				if (__instance.prompt[i].alpha > 0f)
				{
					__instance.prompt[i].Draw(__instance.p);
				}
			}

			return false;
		}
	}

	// This function handles patching the Gold and Salt drop notifications, making it closer to the bottom of the screen
	// and pushed further to the outer area of the screen.
	[HarmonyPatch(typeof(PlayerDrawPickups), nameof(PlayerDrawPickups.DrawGoldAndSalt))]
	internal class PlayerDrawPickups_DrawGoldAndSalt
	{
		static void goldAndSaltVecMethod(float scale, ref Vector2 vec, ref Rectangle saltRect)
		{
			vec.X -= 35.0f * scale;
			vec.Y += 115.0f * scale;
		}

		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			Console.WriteLine($"Patching PlayerDrawPickups at PlayerDrawPickups:DrawGoldAndSalt...");
			var codes = new List<CodeInstruction>(instructions);
			for (int i = 0; i < codes.Count-8; i++)
			{
				if (
					codes[i].opcode   == OpCodes.Ldloca_S &&                                                // 17	0037	ldloca.s	V_1 (1)
					codes[i+1].opcode == OpCodes.Ldc_R4   && (float)codes[i+1].operand == 80.0f          && // 18	0039	ldc.r4	80
					codes[i+2].opcode == OpCodes.Ldarg_1  &&                                                // 19	003E	ldarg.1
					codes[i+3].opcode == OpCodes.Mul      &&                                                // 20	003F	mul
					codes[i+4].opcode == OpCodes.Stfld    && codes[i+4].operand.ToString().Contains("X")    // 21	0040	stfld	float32 [FNA]Microsoft.Xna.Framework.Vector2::X
				)
				{
					MethodInfo goldAndSaltVecMethod = typeof(PlayerDrawPickups_DrawGoldAndSalt).GetMethod("goldAndSaltVecMethod", BindingFlags.NonPublic | BindingFlags.Static);
					// Grab where the Vector local is.

					LocalBuilder reloc = codes[i].operand as LocalBuilder;
					List<CodeInstruction> newCodes = new List<CodeInstruction>();
					newCodes.Add(new CodeInstruction(OpCodes.Ldarg_S, 1));
					newCodes.Add(new CodeInstruction(OpCodes.Ldloca_S, reloc.LocalIndex));
					newCodes.Add(new CodeInstruction(OpCodes.Ldarga_S, 2));
					newCodes.Add(new CodeInstruction(OpCodes.Call, goldAndSaltVecMethod));

					Console.WriteLine($"Patched PlayerDrawPickups at PlayerDrawPickups:DrawGoldAndSalt+{i+5}!");
					codes.InsertRange(i+5, newCodes);
					break;
				}
			}

			return codes.AsEnumerable();
		}
	}

	[HarmonyPatch(typeof(PlayerDrawPickups), nameof(PlayerDrawPickups.DrawPickup))]
	internal class PlayerDrawPickups_DrawPickup
	{
		static bool Prefix(PlayerDrawPickups __instance, int p, float alpha, float scale, bool flip)
		{
			// Annoying internal crap...
			LootDef lootDef = LootCatalog.category[__instance.p.pickup[p].category].loot[__instance.p.pickup[p].catalogIdx];
			Vector2 value;
			bool flag = __instance.p.ID == GameStateManager.coopPlayerIdx;
			float num = Text.GetStringSpace(lootDef.titleStr, 0.44000003f, __instance.p, 0) * scale;
			value.Y = ScrollManager.screenSize.Y - 135f * scale;
			if (GameStateManager.coopPlayerIdx == __instance.p.ID)
			{
				value.X = ScrollManager.screenSize.X - 45f * scale;
			}
			else
			{
				value.X = 45f * scale;
			}
			float num2 = (float)(p + 1);
			float num3 = 1f - __instance.p.pickup[p].inFrame;
			if (num3 > 1f)
			{
				num3 = 1f;
			}
			num2 *= (float)Math.Sin((double)(1.5707964f * num3));
			Textures.tex[ParticleManager.spritesTexIdx].Draw(value + new Vector2(num / 2f, num2 * -40f * scale), 0, new Vector2(3f, 0.8f) * scale, 0f, 0f, 0f, 0f, alpha * 0.3f);
			InterfaceRender.DrawItem(value + new Vector2(0f, num2 * -40f * scale), (__instance.p.pickup[p].invIdx > -1) ? __instance.p.playerInv.inventory[__instance.p.pickup[p].invIdx] : null, alpha, 0.45f * scale, __instance.p, CharMgr.GetPlayerCharacter(__instance.p), false, __instance.p.pickup[p].count);
			Text.DrawText(lootDef.titleStr, value + new Vector2((flag ? -28f : 20f) * scale, num2 * -40f * scale), new Color(1f, 1f, 1f, alpha), 0.55f * scale, flag ? 2 : 0);
			if (__instance.p.pickup[p].inFrame > 0f)
			{
				float num4 = (float)Math.Sin((double)(__instance.p.pickup[p].inFrame * 3.1415927f));
				Textures.tex[ParticleManager.spritesTexIdx].Draw(value + new Vector2((flag ? -1f : 1f) * num / 2f, num2 * -40f * scale), 0, new Vector2(3f, 0.8f) * scale, 0f, 1f, 1f, 1f, num4 * 0.25f);
				for (int i = 0; i < 4; i++)
				{
					Textures.tex[ParticleManager.spritesTexIdx].Draw(value + new Vector2(num * ((float)i / 4f) * (flag ? -1f : 1f), num2 * -40f * scale), 41 + (p + i) % 9, new Vector2(1f, 1f) * scale, __instance.p.pickup[p].inFrame * ((float)(i % 2) - 0.5f), 1f, 1f, 1f, num4 * 0.35f);
				}
			}

			return false;
		}
	}

	// Adjust the locations of the torch to the top right.
	[HarmonyPatch(typeof(PlayerDraw), nameof(PlayerDraw.DrawTorches))]
	public static class PlayerDraw_DrawTorches
	{
		public static bool Prefix(PlayerDraw __instance, float scale, Character c, ref Vector2 tL, float w, float alpha)
		{
			tL.X = ScrollManager.screenSize.X - 270.0f * scale;
			tL.Y = 13.5f * scale;
			tL.Y -= (ScrollManager.screenSize.Y - (w + 144f) * scale);
			return true;
		}
	}

	// Move the Modifiers down by 15pt (pre-scaled size)
	[HarmonyPatch(typeof(PlayerDraw), nameof(PlayerDraw.DrawMods))]
	public static class PlayerDraw_DrawMods
	{
		public static bool Prefix(PlayerDraw __instance, float scale, Character c, Vector2 tL, Vector2 bR, ref float xAdd, float w, float iconY, ref float yAdd, bool flip)
		{
			yAdd += 15f * scale;
			xAdd -= scale;
			return true;
		}
	}

	// We moved the HUD up by 30pt, so we want to move the Gold and Salt displays 
	// down by 30pt to fix this, and then an extra 30pt to make more of the
	// screen area usable.
	[HarmonyPatch(typeof(PlayerDraw), nameof(PlayerDraw.DrawGoldAndSalt))]
	public static class PlayerDraw_DrawGoldAndSalt
	{
		public static void getNewBarsRect(float scale, ref float num, ref Rectangle rect, ref Vector2 tL)
		{
			num += 45f * scale;
			rect.Y += (int)(45f * scale);
			tL.Y += (int)(75f * scale);
		} 

		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			Console.WriteLine($"Patching PlayerDraw at PlayerDraw:DrawGoldAndSalt...");
			var codes = new List<CodeInstruction>(instructions);
			for (int i = 0; i < codes.Count-5; i++)
			{
				if (
					codes[i].opcode   == OpCodes.Conv_I4 && 
					codes[i+1].opcode == OpCodes.Ldc_R4	 && (float)codes[i+1].operand == 32.0f &&
					codes[i+2].opcode == OpCodes.Ldarg_2 && 
					codes[i+3].opcode == OpCodes.Mul     && 
					codes[i+4].opcode == OpCodes.Conv_I4 && 
					codes[i+5].opcode == OpCodes.Call
				)
				{
					MethodInfo getNewBarsRectMethod = typeof(PlayerDraw_DrawGoldAndSalt).GetMethod("getNewBarsRect", BindingFlags.Public | BindingFlags.Static);
					List<CodeInstruction> newCodes = new List<CodeInstruction>();
					newCodes.Add(new CodeInstruction(OpCodes.Ldarg_2));
					newCodes.Add(new CodeInstruction(OpCodes.Ldloca_S, 0));
					newCodes.Add(new CodeInstruction(OpCodes.Ldloca_S, 1));
					newCodes.Add(new CodeInstruction(OpCodes.Ldarga_S, 3));
					newCodes.Add(new CodeInstruction(OpCodes.Call, getNewBarsRectMethod));
					Console.WriteLine($"Patched PlayerDraw at PlayerDraw:DrawGoldAndSalt+{i+6}!");
					codes.InsertRange(i+6, newCodes);
					break;
				}
			}

			return codes.AsEnumerable();
		}
	}

	// We want to move a few things around the screen. The belt should be moved
	// to the bottom right
	[HarmonyPatch(typeof(PlayerDraw), nameof(PlayerDraw.DrawSpellsAndUsables))]
	public static class PlayerDraw_DrawSpellsAndUsables
	{
		public static Rectangle getNewConsumablesRect(float w, float scale)
		{
			float offsLength = (ConfigMgr.hudVis < 2) ? 3.5f : 1.5f;
			return new Rectangle(
				(int)(ScrollManager.screenSize.X - (offsLength * 60f * scale)),
				(int)(ScrollManager.screenSize.Y - (w * scale + (70f - 50f) * scale)),
				(int)(60f * scale),
				(int)(60f * scale));
		}

		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			Console.WriteLine($"Patching PlayerDraw at PlayerDraw:DrawSpellsAndUsables...");
			var codes = new List<CodeInstruction>(instructions);

			for (int i = 0; i < codes.Count-2; i++)
			{
				if (
					codes[i].opcode == OpCodes.Ldloca_S && (codes[i].operand as LocalBuilder).LocalIndex == 1 &&
					codes[i+1].opcode == OpCodes.Initobj && codes[i+1].operand.ToString().Contains("Vector2")
				)
				{
					List<CodeInstruction> newCodes = new List<CodeInstruction>();
					newCodes.Add(new CodeInstruction(OpCodes.Ldloca_S, 1));
					newCodes.Add(new CodeInstruction(OpCodes.Ldsflda, AccessTools.Field(typeof(ScrollManager), nameof(ScrollManager.screenSize))));
					newCodes.Add(new CodeInstruction(OpCodes.Ldfld, AccessTools.Field(typeof(Vector2), nameof(Vector2.X))));
					newCodes.Add(new CodeInstruction(OpCodes.Ldc_R4, (float)(260 - 30)));
					newCodes.Add(new CodeInstruction(OpCodes.Ldarg_1));
					newCodes.Add(new CodeInstruction(OpCodes.Mul));
					newCodes.Add(new CodeInstruction(OpCodes.Sub));                 // screenSize.X - 260.0f * scale
					newCodes.Add(new CodeInstruction(OpCodes.Ldc_R4, (float)-(60 + 45)));
					newCodes.Add(new CodeInstruction(OpCodes.Ldarg_1));
					newCodes.Add(new CodeInstruction(OpCodes.Mul));                 // -(60+30) * scale
					newCodes.Add(new CodeInstruction(OpCodes.Call, AccessTools.Constructor(typeof(Vector2), new [] { typeof(float), typeof(float) })));
					Console.WriteLine($"Patched PlayerDraw at PlayerDraw:DrawSpellsAndUsables+{i}! [1]");
					codes.RemoveRange(i, 2);
					codes.InsertRange(i, newCodes);
					break;
				}
			}

			for (int i = 0; i < codes.Count-40; i++)
			{
				if (
					codes[i].opcode    == OpCodes.Ldloc_1 &&
					codes[i+1].opcode  == OpCodes.Ldfld   &&
					codes[i+2].opcode  == OpCodes.Ldc_R4  && (float)codes[i+2].operand == 184.0f &&
					codes[i+40].opcode == OpCodes.Call    && codes[i+40].operand.ToString().Contains("DrawConsumableRowMinimal")
				)
				{
					MethodInfo getNewConsumablesRectMethod = typeof(PlayerDraw_DrawSpellsAndUsables).GetMethod("getNewConsumablesRect", BindingFlags.Public | BindingFlags.Static);
					List<CodeInstruction> newCodes = new List<CodeInstruction>();
					newCodes.Add(new CodeInstruction(OpCodes.Ldarg_S, 4));
					newCodes.Add(new CodeInstruction(OpCodes.Ldarg_S, 1));
					newCodes.Add(new CodeInstruction(OpCodes.Call, getNewConsumablesRectMethod));
					Console.WriteLine($"Patched PlayerDraw at PlayerDraw:DrawSpellsAndUsables+{i}! [2]");
					codes.RemoveRange(i, 40);
					codes.InsertRange(i, newCodes);
					break;
				}
			}
			
			return codes.AsEnumerable();
		}
	}

	// Disable the belt text
	[HarmonyPatch(typeof(PlayerDraw), nameof(PlayerDraw.DrawConsumableRowMinimal))]
	public static class PlayerDraw_DrawConsumableRowMinimal
	{
		static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
		{
			Console.WriteLine($"Patching PlayerDraw at PlayerDraw:DrawConsumableRowMinimal...");
			var codes = new List<CodeInstruction>(instructions);
			for (int i = 0; i < codes.Count-3; i++)
			{
				if (
					codes[i].opcode   == OpCodes.Ldsfld   && codes[i].operand.ToString().Contains("hudVis") && // 295	0323	ldsfld	int32 ProjectTower.config.ConfigMgr::hudVis
					codes[i+1].opcode == OpCodes.Ldc_I4_2 &&                                                   // 296	0328	ldc.i4.2
					codes[i+2].opcode == OpCodes.Bge                                                           // 297	0329	bge	374 (03FC) ldarg.3 
				)
				{
					// Always branch.
					codes[i+1] = new CodeInstruction(OpCodes.Ldc_I4_0);
					Console.WriteLine($"Patched PlayerDraw at PlayerDraw:DrawConsumableRowMinimal+{i+1}!");
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
