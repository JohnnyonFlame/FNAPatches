using System;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using System.Threading;
using HarmonyLib;
using Microsoft.Xna.Framework;
using SteelAssaultCs.Engine;
using SteelAssaultCs.Engine.Objects.Background;
using SteelAssaultCs.Engine.Objects.Effects;
using SteelAssaultCs.Graphics.DrawCalls;

[assembly: IgnoresAccessChecksTo("SteelAssaultCs")]
[assembly: IgnoresAccessChecksTo("Microsoft.Xna.Framework")]
[ModEntryPoint]
public static class SteelAssaultCsPatches
{
    public static void Main()
    {
        Console.Out.WriteLine("Found SteelAssaultCsPatches, running...");
        try
        {
            new Harmony("com.github.johnnyonflame.SteelAssaultCsPatches").PatchAll(Assembly.GetExecutingAssembly());
        }
        catch (Exception e) 
        {
            Console.Out.WriteLine($"Failed: {e.ToString()}");
            throw e;
        }
    }

    // Lower the water droplets from overhangs significantly
    [HarmonyPatch("DripSurface", "init_delayed")]
    private class DripSurface_init_delayed
    {
        private static void Prefix(ref DripSurface __instance, out int __state)
        {
            __state = __instance.width;
            __instance.width = Math.Max(4, __state / 7);
        }

        private static void Postfix(ref DripSurface __instance, int __state)
        {
            __instance.width = __state;
        }
    }
    
    // Cap the maximum water droplet splat effects to 1 every 20 frames 
    [HarmonyPatch("RainSurface", "update")]
    private class RainSurface_update
    {
        static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
        {
            var codes = new List<CodeInstruction>(instructions);
            for (int i = 0; i < codes.Count; i++)
            {
                if (codes[i].opcode == OpCodes.Ldc_R8 && (double)codes[i].operand == 2.0)
                {
                    if (codes[i-3].opcode != OpCodes.Ldc_R8 || (double)codes[i-3].operand != 50.0)
                        continue;

                    // Limit droplets to 1 every 20 frames.
                    List<CodeInstruction> newCodes = new List<CodeInstruction>();
                    newCodes.Add(new CodeInstruction(OpCodes.Ldloc_2));
                    newCodes.Add(new CodeInstruction(OpCodes.Ldc_R8, 20.0));
                    newCodes.Add(new CodeInstruction(OpCodes.Call, ((Func<double, double, double>) Math.Max).Method));
                    newCodes.Add(new CodeInstruction(OpCodes.Stloc_2));
                    codes.InsertRange(i+4, newCodes);
                    System.Console.WriteLine($"Patched RainSurface at RainSurface:update+{i}!");
                    break;
                }
            }
            /*
            for (int i = 0; i < codes.Count; i++)
            {
                System.Console.WriteLine($"RainSurface:update+{i:000}: {codes[i].ToString()}");
            }
            */
            return codes.AsEnumerable();
        }
    }

    // Lower the rain intensity globally
    [HarmonyPatch("RainEffect", "regenerateCalls")]
    private class RainEffect_regenerateCalls
    {
        private static void Prefix(ref RainEffect __instance, out double __state)
        {
            __state = __instance.intensity;
            __instance.intensity = __state * 0.125;
        }

        private static void Postfix(ref RainEffect __instance, double __state)
        {
            __instance.intensity = __state;
        }
    }

    // Lower the Mecha Agni attack particles by more than half
    [HarmonyPatch("FireballAttack", "update")]
    private class FireballAttack_update
    {
        static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
        {
            var codes = new List<CodeInstruction>(instructions);
            for (int i = 0; i < codes.Count; i++)
            {
                if (codes[i].opcode == OpCodes.Call && 
                    codes[i].operand.ToString().Contains(
                    "Void Flamethrower(SteelAssaultCs.Geometry.Position, Double, Double, Int32, Double, Boolean, Boolean, Boolean, Int32)"))
                {
                    if (codes[i-11].opcode != OpCodes.Ldc_I4_6)
                        continue;

                    codes[i-11].opcode = OpCodes.Ldc_I4_2;
                    codes[i-5].opcode = OpCodes.Ldc_I4_8;
                    System.Console.WriteLine($"Patched Flamethrower at FireballAttack:update+{i}!");
                    break;
                }
            }

            return codes.AsEnumerable();
        }
    }

    // Lower the Mecha Agni attack particles by more than half
    [HarmonyPatch("SpitFlame", "update")]
    private class SpitFlame_update
    {
        static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
        {
            var codes = new List<CodeInstruction>(instructions);
            for (int i = 0; i < codes.Count; i++)
            {
                if (codes[i].opcode == OpCodes.Call && 
                    codes[i].operand.ToString().Contains(
                    "Void Flamethrower(SteelAssaultCs.Geometry.Position, Double, Double, Int32, Double, Boolean, Boolean, Boolean, Int32)"))
                {
                    if (codes[i-12].opcode != OpCodes.Ldc_I4_8)
                        continue;

                    codes[i-12].opcode = OpCodes.Ldc_I4_3;
                    codes[i-5].opcode = OpCodes.Ldc_I4_8;
                    System.Console.WriteLine($"Patched Flamethrower at SpitFlame:update+{i}!");
                    break;
                }
            }

            return codes.AsEnumerable();
        }
    }

    // Lower the flameturret attack particles by half
    [HarmonyPatch("WaitAndFire", "update")]
    private class BCFlameTurret_WaitAndFire_update
    {
        static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
        {
            var codes = new List<CodeInstruction>(instructions);
            for (int i = 0; i < codes.Count; i++)
            {
                if (codes[i].opcode == OpCodes.Call && 
                    codes[i].operand.ToString().Contains(
                    "Void Flamethrower(SteelAssaultCs.Geometry.Position, Double, Double, Int32, Double, Boolean, Boolean, Boolean, Int32)"))
                {
                    if (codes[i-12].opcode != OpCodes.Ldc_I4_6)
                        continue;

                    codes[i-12].opcode = OpCodes.Ldc_I4_2;
                    System.Console.WriteLine($"Patched BCFlameTurret at WaitAndFire:update+{i}!");
                    break;
                }
            }

            return codes.AsEnumerable();
        }
    }

    // Lower the Flame Spider's front gun particles considerably
    [HarmonyPatch("FSGun", "update")]
    private class FlameSpider_FSGun_update
    {
        static IEnumerable<CodeInstruction> Transpiler(IEnumerable<CodeInstruction> instructions)
        {
            var codes = new List<CodeInstruction>(instructions);
            for (int i = 0; i < codes.Count; i++)
            {
                if (codes[i].opcode == OpCodes.Call && 
                    codes[i].operand.ToString().Contains(
                    "Void Flamethrower(SteelAssaultCs.Geometry.Position, Double, Double, Int32, Double, Boolean, Boolean, Boolean, Int32)"))
                {
                    if (codes[i-11].opcode != OpCodes.Ldc_I4_6)
                        continue;

                    codes[i-11].opcode = OpCodes.Ldc_I4_2;
                    System.Console.WriteLine($"Patched FlameSpider at FSGun:update+{i}!");
                    break;
                }
            }

            return codes.AsEnumerable();
        }
    }

    [HarmonyPatch("TSBillboard", "draw")]
    static class TSBillboard_draw
    {
        static bool Prefix(ref TSBillboard __instance, ICollection<DrawCall> ret)
        {
            if (!GameManager.Camera.onscreen(__instance, 320))
                return false;

            __instance.calls.Clear();
            switch (__instance.type)
            {
            case TSBillboard.AdType.NUMELTA:
                __instance.numelta(__instance.calls);
                break;
            case TSBillboard.AdType.NERIO:
                __instance.nerio(__instance.calls);
                break;
            case TSBillboard.AdType.METROGRAPH:
                __instance.metrograph(__instance.calls);
                break;
            case TSBillboard.AdType.BROADWAY:
                __instance.broadway(__instance.calls);
                break;
            case TSBillboard.AdType.DIRAC:
                __instance.dirac(__instance.calls);
                break;
            case TSBillboard.AdType.RENT:
                __instance.rent(__instance.calls);
                break;
            case TSBillboard.AdType.AVALYN:
                __instance.avalyn(__instance.calls);
                break;
            case TSBillboard.AdType.SOPHIE:
                __instance.sophie(__instance.calls);
                break;
            case TSBillboard.AdType.STONKS:
                __instance.stocks(__instance.calls);
                break;
            case TSBillboard.AdType.NEWS:
                __instance.news(__instance.calls);
                break;
            case TSBillboard.AdType.SOROBAN:
                __instance.soroban(__instance.calls);
                break;
            case TSBillboard.AdType.BOND:
                __instance.bond(__instance.calls);
                break;
            case TSBillboard.AdType.AXON:
                __instance.axon(__instance.calls);
                break;
            case TSBillboard.AdType.PLAY:
                __instance.play(__instance.calls);
                break;
            case TSBillboard.AdType.CAMPAIGN:
                __instance.campaign(__instance.calls);
                break;
            case TSBillboard.AdType.ZENOVIA:
                __instance.zenovia(__instance.calls);
                break;
            case TSBillboard.AdType.TRIBUTE:
                __instance.tribute(__instance.calls);
                break;
            }

            __instance.calls.ForEach(x => ret.Add(x));
            return false;
        }
    }

    // Simplify the displaceSingleCall effect.
    [HarmonyPatch("TSBillboard", "displaceSingleCall")]
    static class TSBillboard_displaceSingleCall
    {
        static bool Prefix(ref TSBillboard __instance, List<DrawCall> ret, TexturedDrawCall t)
        {
            ret.Add(t);
            return false;
        }
    }

    // Disabled on TIMES_SQUARE since that level has performance woes.
    [HarmonyPatch("MetroLightbeam", "draw")]
    static class MetroLightbeam_draw
    {
        static bool Prefix(ref MetroLightbeam __instance, ICollection<DrawCall> ret)
        {
            Level level = GameManager.Level;
			if (level != null && level.currArea == Level.Area.TIMES_SQUARE)
                return false;

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
