SRC := $(wildcard $(MAKECMDGOALS)/*.TMNTSRMods.mm.cs)
ASM := $(SRC:%.cs=out/%.dll)
DEPS_FOLDER ?= deps/$(MAKECMDGOALS)
DEPS := $(DEPS_FOLDER)/TMNT.exe \
        $(DEPS_FOLDER)/ParisEngine.dll \
        deps/Cecil/*.dll \
        deps/FNA/FNA.dll \
        deps/MonoMod/MonoMod.exe
