SRC := $(wildcard $(MAKECMDGOALS)/*.PanzerPaladin.mm.cs)
ASM := $(SRC:%.cs=out/%.dll)
DEPS_FOLDER ?= deps/$(MAKECMDGOALS)
DEPS := $(DEPS_FOLDER)/PanzerPaladin.exe \
        $(DEPS_FOLDER)/ParisEngine.dll \
        deps/FNA/FNA.dll \
        deps/MonoMod/MonoMod.exe
