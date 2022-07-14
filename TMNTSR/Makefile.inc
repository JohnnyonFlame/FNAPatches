SRC := $(wildcard $(MAKECMDGOALS)/*.TMNTSRPatches.mm.cs)
ASM := $(SRC:%.cs=out/%.dll)
DEPS_FOLDER ?= deps/$(MAKECMDGOALS)
DEPS := $(DEPS_FOLDER)/TMNT.exe \
        $(DEPS_FOLDER)/ParisEngine.dll \
        deps/Cecil/*.dll \
        deps/MonoMod/MonoMod.exe \
        deps/FNA/FNA.dll
