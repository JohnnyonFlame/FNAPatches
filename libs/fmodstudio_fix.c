// FMODStudio Fix
// This is a wrapper that bridges FMOD 1.x and FMOD 2.x.
// This is necessary, but not enough by itself, to run games such as Celeste on ARM64 systems.
// You'll also need:
// - The appropriate libfmodstudio.so.13 and libfmod.so.13 files (from https://www.fmod.com/download)
// - Any necessary plugin to enable fmod to use your audio backend. (such as https://github.com/flibitijibibo/FMOD_SDL)
// - The necessary mono .config file for your title, as an example, Celeste.exe.config:

/*
<?xml version="1.0" encoding="utf-8"?>
<configuration>
	<dllmap dll="fmod" os="linux" target="libfmod.so.13"/>
	<dllmap dll="fmodstudio" os="linux" target="libfmodstudio.so.13">
		<dllentry dll="fmodstudio_fix.so" name="FMOD_Studio_EventInstance_SetParameterValue" target="_FMOD_Studio_EventInstance_SetParameterValue"/>
		<dllentry dll="fmodstudio_fix.so" name="FMOD_Studio_System_Create" target="_FMOD_Studio_System_Create"/>
		<dllentry dll="fmodstudio.so.13" name="FMOD_Studio_System_GetLowLevelSystem" target="FMOD_Studio_System_GetCoreSystem"/>
		<dllentry dll="fmodstudio.so.13" name="FMOD_Studio_EventInstance_TriggerCue" target="FMOD_Studio_EventInstance_KeyOff"/>
	</dllmap>
</configuration>
*/

#include <stdio.h>
#define FMOD_VERSION 0x00020206

# define DECLSPEC __attribute__ ((visibility("default")))
DECLSPEC int _FMOD_Studio_EventInstance_SetParameterValue(void *system, const char *name, float value) {
	extern int FMOD_Studio_EventInstance_SetParameterByName(void *, const char *, float, int);
	return FMOD_Studio_EventInstance_SetParameterByName(system, name, value, 0);
}

DECLSPEC int _FMOD_Studio_System_Create(void *studiosystem, unsigned int headerversion)
{
	// If this fails, check if the FMOD_VERSION number is correct.
	extern int FMOD_Studio_System_Create(void *, int);
	return FMOD_Studio_System_Create(studiosystem, FMOD_VERSION);
}
