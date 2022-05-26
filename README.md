### What is in this repository?
-------------

This repository contains game-specific hacks and patches for Mono/FNA games on low power SBCs and handhelds, and the
required tooling to comfortably develop and deploy said patches are provided here.

- **CelestePatches**: Extensions to allow loading ASTC4x4 textures and Graphical Settings.
- **SteelAssaultCsPatches**: A series of optimizations targeting low-power devices.
- **Compiler**: A patch compiler that ignores any and all visibility checks, for close usage with Harmony. Reference
    internal classes, mess with private methods and members, nobody can stop you now.

### Dependencies:
-------------

- **For runtime usage**: Mono, `0Harmony.dll`, and and a custom [FNA build](https://github.com/JohnnyonFlame/FNAHacks).
- **For development**: .NET v5.0, Mono, `0Harmony.dll` and a custom [FNA build](https://github.com/JohnnyonFlame/FNAHacks).

### Usage:
-------------

Please refer to your prefered packaging system, such as [PortMaster](https://github.com/christianhaitian/PortMaster).

### Developing:
-------------

What follows is a non-exhaustive guide on how to first build the patch, it won't go into details on how to actually
work with Harmony or how to approach the patch development. If you're looking for those, read [Harmony's documentation](https://harmony.pardeike.net/articles/intro.html)
and check out [ILSpy](https://github.com/icsharpcode/ILSpy).

#### Building Steps:
- In the Compiler folder, first build the compiler:
```bash
dotnet restore
dotnet build
```
- For convenience, create both `build` and `redist` folders.
- Download a release of [Harmony](https://github.com/pardeike/Harmony/releases).
- Extract `net45/0Harmony.dll` into the `redist` folder.
- Copy the custom FNA assemblies into the `redist` folder.
- Compile your patch!
```bash
MONO_PREFIX=/usr
GAME_ASSEMBLY=~/path/to/GameAssembly.exe
PATCH_SOURCE=
COMPILER=( Compiler/bin/*/*/Compiler.dll )

dotnet "${COMPILER[0]}" build/GamePatches.dll ${GAME_ASSEMBLY} "${MONO_PREFIX}/lib/mono/4.5/"*.dll redist/*.dll
```
- Make sure mono can find `0Harmony.dll` in your game's folder.
- Copy the patch and make it known to FNA, then run your game.
```bash
export FNA_PATCH=/path/to/GamePatch.dll
cd ~/path/to/
mono GameAssembly.exe
```

### LICENSE:
-------------

The files in this repository are free software licensed under MIT, read the [License File](LICENSE) for reference.