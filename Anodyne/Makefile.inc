SRC := $(MAKECMDGOALS)/AnodynePatches.cs
ASM := $(SRC:%.cs=out/%.dll)
DEPS_FOLDER ?= deps/$(MAKECMDGOALS)
DEPS := $(DEPS_FOLDER)/AnodyneSharp.exe \
        deps/FNA/FNA.dll \
        deps/Harmony/net45/0Harmony.dll
