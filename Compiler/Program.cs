// Visibility-free Patch Compiler
// Based off of the work presented in https://www.strathweb.com/2018/10/no-internalvisibleto-no-problem-bypassing-c-visibility-rules-with-roslyn/ 

using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Threading;
using System.Collections.Generic;

namespace Compiler
{
    public class Program
    {
        public static string PathToAssembly(string p)
        {
            try {
                return Assembly.Load(new AssemblyName(p)).Location;
            } catch (Exception e) {}
            return p;
        }

        public static int Main(string[] args)
        {
            if (args.Count() < 1)
            {
                Console.WriteLine("Usage: source.cs [references...]");
                return 1;
            }

            // For clarity
            string sourceFile = args[0];
            string sourceFileNoExt = Path.GetFileNameWithoutExtension(sourceFile);
            string sourceFilePathNoExt = Path.Combine(Path.GetDirectoryName(sourceFile), sourceFileNoExt);

            // Load all the referenced assemblies
            List<MetadataReference> metadataReferences = new List<MetadataReference>();
            metadataReferences.AddRange(
                args.Skip(1).Select(
                    x => MetadataReference.CreateFromFile(PathToAssembly(x))
                )
            );

            // Compilation options
            var compilationOptions = new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary)
                .WithMetadataImportOptions(MetadataImportOptions.All)
                .WithAllowUnsafe(true) // Necessary to use protected methods and fields
                .WithOptimizationLevel(OptimizationLevel.Release);

            var topLevelBinderFlagsProperty = typeof(CSharpCompilationOptions).GetProperty("TopLevelBinderFlags", BindingFlags.Instance | BindingFlags.NonPublic);
            topLevelBinderFlagsProperty.SetValue(compilationOptions, (uint)1 << 22);

            // Create compiler
            var code = File.ReadAllText(args[0]);
            var compilation = CSharpCompilation.Create(Path.GetFileNameWithoutExtension(args[0]), new[] {
                CSharpSyntaxTree.ParseText(code) }, metadataReferences, compilationOptions);

            // Start compilation
            string finalAssemblyFilePath = $"{sourceFilePathNoExt}.dll";
            Console.WriteLine($"Saving assembly to {finalAssemblyFilePath}...");
            using (var ms = File.Open(finalAssemblyFilePath, FileMode.Create))
            {
                var compileResults = compilation.Emit(ms);
                foreach (var diag in compileResults.Diagnostics)
                {
                    if (diag.ToString().Contains("Assuming assembly reference 'mscorlib"))
                        continue;
                    Console.WriteLine(diag.ToString());
                }

                if (!compileResults.Success)
                {
                    Console.WriteLine("Failed to compile assembly:");
                    return 1;
                } else {
                    Console.WriteLine("Compilation successful.");
                }
            }

            return 0;
        }
    }
}
