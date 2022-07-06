CFLAGS?=-O3 -shared -rdynamic

all: ../out/libs ../out/libs/fmodstudio_fix.so ../out/libs/EOSSDK-Win64-Shipping.so ../out/libs/libsteam_api.so

clean:
	@rm -f ../out/libs/*

../out/libs:
	mkdir -p ../out/libs

../out/libs/fmodstudio_fix.so: ../out fmodstudio_fix.c
	$(CC) -Wno-return-type $(CFLAGS) fmodstudio_fix.c -o ../out/libs/fmodstudio_fix.so

../out/libs/EOSSDK-Win64-Shipping.so: ../out EOSSDK-Shipping-Stubs.c
	$(CC) -Wno-return-type $(CFLAGS) EOSSDK-Shipping-Stubs.c -o ../out/libs/EOSSDK-Win64-Shipping.so

../out/libs/libsteam_api.so: ../out/libs SteamStubs.c
	$(CC) -Wno-return-type $(CFLAGS) SteamStubs.c -o ../out/libs/libsteam_api.so
	@cp ../out/libs/libsteam_api.so ../out/libs/libsteam_api64.so
	@cp ../out/libs/libsteam_api.so ../out/libs/CSteamworks
