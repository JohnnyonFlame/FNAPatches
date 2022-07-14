SRC := $(MAKECMDGOALS)/Bleed.BleedPatches.mm.cs
ASM := deps/$(MAKECMDGOALS)/MMHOOK_Bleed.dll $(SRC:%.cs=out/%.dll)
DEPS_FOLDER ?= deps/$(MAKECMDGOALS)
DEPS := $(DEPS_FOLDER)/Bleed.exe \
        deps/$(MAKECMDGOALS)/MMHOOK_Bleed.dll \
        deps/Cecil/*.dll \
        deps/FNA/FNA.dll \
        deps/MonoMod/MonoMod.exe \
        deps/MonoMod/MonoMod.Utils.dll
