SRC := $(MAKECMDGOALS)/ShipwreckPatches.cs
ASM := $(SRC:%.cs=out/%.dll)
DEPS_FOLDER ?= deps/$(MAKECMDGOALS)
DEPS := $(DEPS_FOLDER)/Shipwreck.exe \
        deps/Shipwreck/FNA.dll \
        deps/Harmony/net45/0Harmony.dll
