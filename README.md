### What is in this repository?
-------------

This repository contains game-specific hacks and patches for Mono/FNA games on low power SBCs and handhelds, and the
required tooling to comfortably develop and deploy said patches are provided here.

- **FMODStudio Fix**: A dead simple FMOD Studio 1.x to FMOD Studio 2.x wrapper.
- **SteamStubs**: A series of 0-stubs to allow DRM-Free games not to crash when Steam's libraries aren't present.
- **EOSSDK-Shipping-Stubs**: A series of 0-stubs to allow games not to crash when Epic Online Services aren't present.
- **ChasmPatches**: Small patches for Chasm fullscreen logic on very small resolutions.
- **CelestePatches**: Extensions to allow loading ASTC4x4 textures and Graphical Settings.
- **SteelAssaultCsPatches**: A series of optimizations targeting low-power devices.
- **PanzerPaladinPatches**: Fixes breakage when running non-Steam, newer FNA builds and does general optimizations.
- **BleedPatches**: Fixes startup failures on certain FNA+SDL2 combinations.
- **TMNTSR-Mods**: Load custom sound assets on TMNT: Shredder's Revenge.
- **TMNTSRPatches**: Provides Performance settings, fixes Deadlocks on OpenGL, fixes file paths on Linux and more. 
- **MMLoader**: Force loading applications with MONOMODDED_*.dll redirection, change the AppDomain's BaseDirectory and more.

### Usage:
-------------

This isn't meant for end-users, but for development reference or contribution. Please refer to your favorite supported packaging system, such as [PortMaster](https://github.com/christianhaitian/PortMaster).

### Developing:
-------------

What follows is a non-exhaustive guide on how to first build the patch, it won't go into details on how to actually
work with Harmony or how to approach the patch development. If you're looking for those, read [Harmony's documentation](https://harmony.pardeike.net/articles/intro.html), [MonoMod's documentation](https://github.com/MonoMod/MonoMod#readme) and check out [ILSpy](https://github.com/icsharpcode/ILSpy).

### Building:
-------------

- [Optional] Build mono with a local prefix.
- Clone this repository recursively.
- Build the VisFree compiler (check the project's README for instructions).
- [Optional] Build the stubs and support libraries.
- Copy any necessary dependencies (such as game assemblies) into the `deps` folder, refer to the dot files included.
- Build one or all of the included projects, you have a few optional, configurable parameters:
    - `DEPS_FOLDER`: Where the referenced game assemblies are.
    - `MONO_PREFIX`: Where your mono install is.
    - `COMPILER`: Where your `VisFree.exe` assembly is.

Example:

```bash
export CONFIGURATION=Debug
export COMPILER=VisFree/bin/Debug/VisFree.exe
export MONO_PREFIX=~/mono-6.12.0.122/built
export DEPS_FOLDER=~/.steam/steam/SteamApps/common/Celeste
git clone --recursive https://github.com/JohnnyonFlame/FNAPatches
(cd deps/Harmony && wget https://github.com/pardeike/Harmony/releases/download/v2.2.1.0/Harmony.2.2.1.0.zip && unzip Harmony.2.2.1.0.zip)
(cd deps/MonoMod && wget https://github.com/MonoMod/MonoMod/releases/download/v22.05.01.01/MonoMod-22.05.01.01-net452.zip && unzip MonoMod-22.05.01.01-net452.zip)
(cd deps/FNA && wget https://github.com/JohnnyonFlame/FNAHacks/releases/download/IntPtr-SoundEffect/FNA_3d954a5-aarch64.tar.gz && tar zxvf FNA_3d954a5-aarch64.tar.gz --strip-components=1 --wildcards dlls/\*.dll)
make -C VisFree
make libs
make Celeste
```

### LICENSE:
-------------

The files in this repository are free software licensed under MIT, read the [License File](LICENSE) for reference.
