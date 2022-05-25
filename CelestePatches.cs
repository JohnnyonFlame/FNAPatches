using System;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.Linq;
using System.IO;
using System.Reflection;
using System.Reflection.Emit;
using System.Threading;
using HarmonyLib;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Celeste;
using Monocle;

[assembly: IgnoresAccessChecksTo("Celeste")]
[assembly: IgnoresAccessChecksTo("Microsoft.Xna.Framework")]
[ModEntryPoint]
public static class CelestePatches
{
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

        Console.Out.WriteLine("Done.");
    }

    // [HarmonyPatch("VirtualTexture", "Reload")]
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

