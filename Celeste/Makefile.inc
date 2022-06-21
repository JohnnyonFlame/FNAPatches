SRC := $(MAKECMDGOALS)/CelestePatches.cs
ASM := $(SRC:%.cs=out/%.dll)
DEPS_FOLDER ?= deps/$(MAKECMDGOALS)
DEPS := $(DEPS_FOLDER)/Celeste.exe \
        deps/FNA/FNA.dll \
        deps/Harmony/net45/0Harmony.dll
