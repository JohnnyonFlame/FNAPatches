using System;
using System.Collections.Generic;
using System.Security.Policy;
using System.IO;
using System.Runtime.CompilerServices;
using System.Reflection;
using System.Linq;
using System.Threading;
using System.Runtime.InteropServices;

public class MMLoader {
    public static void Main(string[] args)
    {
        if (args.Length < 1)
        {
            Console.Error.WriteLine("Syntax: MMLoader.exe <assembly> [appBasePath] [-- appArgs...]");
            Console.Error.WriteLine("     asssembly: Assembly to be loaded.");
            Console.Error.WriteLine("   appBasePath: Optionally Override AppDomain.CurrentDomain.BaseDirectory.");
            Console.Error.WriteLine("          '--': Anything afterwards is passed as arguments to the Assembly.");
            System.Environment.Exit(-1);
        }

        if (!File.Exists(args[0]))
        {
            Console.Error.WriteLine($"Unable to find assembly \"{args[0]}\"!");
            System.Environment.Exit(-1);
        }

        // Gather Arguments
        string assemblyFilePath = Path.GetDirectoryName(Path.GetFullPath(args[0]));
        AssemblyName assemblyName = Assembly.ReflectionOnlyLoadFrom(args[0]).GetName();
        string appBasePath = assemblyFilePath;
        string[] appArgs = new string[] { }; 
        try
        {
            int i = 1;
            if ((string)args.GetValue(i)?.ToString() != "--")
                appBasePath = (string)args?.GetValue(i++);

            if ((string)args?.GetValue(i) == "--")
                appArgs = args?.Skip(i+1).ToArray();
        }
        catch (Exception e) { }

        Console.Out.WriteLine($"assemblyName: {assemblyName.Name}");
        Console.Out.WriteLine($"appBasePath: {appBasePath}");
        Console.Out.WriteLine($"appArgs: {{{string.Join(",", appArgs)}}}");

        // Create domain and load the base assembly
        Evidence evidence = new Evidence(AppDomain.CurrentDomain.Evidence);
        AppDomain domain = AppDomain.CreateDomain(assemblyName.Name, evidence, appBasePath, appBasePath, false);       
        Assembly assembly = domain.Load(assemblyName);

        // See if we have MONOMODDED versions to load first...
        foreach (var asm in assembly.GetReferencedAssemblies())
        {
            string asmFileName = $"MONOMODDED_{asm.Name}.dll";
            if (File.Exists(asmFileName))
            {
                Console.Out.WriteLine($"Redirecting {asm.Name} to {asmFileName}");
                domain.Load(File.ReadAllBytes(Path.GetFullPath(asmFileName)));
            }
        }

        // Change current directory and jump into the assembly
        Directory.SetCurrentDirectory(appBasePath);
        domain.ExecuteAssemblyByName(assemblyName.Name, appArgs);
    }
}