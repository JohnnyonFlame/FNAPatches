#include <stdint.h>

typedef struct ControllerState
{
    unsigned int PacketNum;
    unsigned long Buttons;
    short LeftPadX;
    short LeftPadY;
    short RightPadX;
    short RightPadY;
} ControllerState;

typedef enum
{
    SteamControllerPadLeft,
    SteamControllerPadRight
} SteamControllerPad;

typedef char bool;
typedef char *string;
typedef uint32_t uint;
typedef uint64_t ulong;
typedef uint16_t ushort;
typedef intptr_t IntPtr;
typedef uint AppId_t;
typedef char byte;
#define out
#define ref
#define STUB(t, x, v, ...) t x( __VA_ARGS__ ) { return v; };

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
// [return: MarshalAs(UnmanagedType.I1)]
STUB(bool, SteamAPI_IsSteamRunning, 0);
STUB(bool, IsSteamRunning, 0);

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamAPI_Init();
STUB(bool, SteamAPI_Init, 0);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "InitSafe")]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamAPI_InitSafe();
STUB(bool, SteamAPI_InitSafe, 0, );
STUB(bool, InitSafe, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "Shutdown")]
// public static extern void SteamAPI_Shutdown();
STUB(void, SteamAPI_Shutdown, 0, );
STUB(void, Shutdown, 0, );

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_RunCallbacks, 0, );

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_RegisterCallback, 0);

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_UnregisterCallback, 0);

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_RegisterCallResult, 0);

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_UnregisterCallResult, 0);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "RestartAppIfNecessary")]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamAPI_RestartAppIfNecessary(AppId_t unOwnAppID);
STUB(bool, SteamAPI_RestartAppIfNecessary, 0, AppId_t unOwnAppID);
STUB(bool, RestartAppIfNecessary, 0, AppId_t unOwnAppID);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// private static extern void IJCSteamAPI_SetAchievement(string ID);
STUB(void, IJCSteamAPI_SetAchievement, 0, string ID);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// private static extern void IJCSteamAPI_FindLeaderboard(string ID);
STUB(void, IJCSteamAPI_FindLeaderboard, 0, string ID);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// [return: MarshalAs(UnmanagedType.I1)]
// private static extern bool IJCSteamAPI_UploadScore(int score);
STUB(bool, IJCSteamAPI_UploadScore, 0, int score);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// [return: MarshalAs(UnmanagedType.I1)]
// private static extern bool IJCSteamAPI_Init();
STUB(bool, IJCSteamAPI_Init, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// private static extern void IJCSteamAPI_RunCallbacks();
STUB(void, IJCSteamAPI_RunCallbacks, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// private static extern void IJCSteamAPI_Shutdown();
STUB(void, IJCSteamAPI_Shutdown, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// [return: MarshalAs(UnmanagedType.I1)]
// private static extern bool SteamWrapper_Init();
STUB(bool, SteamWrapper_Init, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_RunCallbacks();
STUB(bool, SteamWrapper_RunCallbacks, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_Shutdown();
STUB(bool, SteamWrapper_Shutdown, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// [return: MarshalAs(UnmanagedType.I1)]
// private static extern bool SteamWrapper_SetAchievement(string achievement);
STUB(bool, SteamWrapper_SetAchievement, 0, string achievement);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_InitStats(int count, int maxIndex);
STUB(bool, SteamWrapper_InitStats, 0, int count, int maxIndex);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_AddStat(string stat, int index);
STUB(bool, SteamWrapper_AddStat, 0, string stat, int index);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_SetStatIntByIndex(int index, int value);
STUB(bool, SteamWrapper_SetStatIntByIndex, 0, int index, int value);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_IncStatIntByIndex(int index, int value);
STUB(bool, SteamWrapper_IncStatIntByIndex, 0, int index, int value);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_GetStatIntByIndex(int index, out int value);
STUB(bool, SteamWrapper_GetStatIntByIndex, 0, int index, out int value);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_GetGlobalStatIntByIndex(int index, out long value);
STUB(bool, SteamWrapper_GetGlobalStatIntByIndex, 0, int index, out long value);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// public static extern void SteamWrapper_RequestGlobalStats();
STUB(void, SteamWrapper_RequestGlobalStats, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_HaveGlobalStats();
STUB(bool, SteamWrapper_HaveGlobalStats, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_StoreStats();
STUB(bool, SteamWrapper_StoreStats, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_ResetAllStats(int achievementsToo);
STUB(bool, SteamWrapper_ResetAllStats, 0, int achievementsToo);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// [return: MarshalAs(UnmanagedType.I1)]
// private static extern bool SteamWrapper_LbUploadScore(string leaderboard, int score);
STUB(bool, SteamWrapper_LbUploadScore, 0, string leaderboard, int score);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_LbBeginUserRead(string leaderboard);
STUB(bool, SteamWrapper_LbBeginUserRead, 0, string leaderboard);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_LbBeginGlobalRead(string leaderboard);
STUB(bool, SteamWrapper_LbBeginGlobalRead, 0, string leaderboard);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_LbBeginFriendRead(string leaderboard);
STUB(bool, SteamWrapper_LbBeginFriendRead, 0, string leaderboard);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_LbPageUp();
STUB(bool, SteamWrapper_LbPageUp, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_LbPageDown();
STUB(bool, SteamWrapper_LbPageDown, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_LbCanPageUp();
STUB(bool, SteamWrapper_LbCanPageUp, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_LbCanPageDown();
STUB(bool, SteamWrapper_LbCanPageDown, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_LbIsDownloading();
STUB(bool, SteamWrapper_LbIsDownloading, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// public static extern int SteamWrapper_LbGetRank(int index);
STUB(int, SteamWrapper_LbGetRank, 0, int index);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// public static extern int SteamWrapper_LbGetScore(int index);
STUB(int, SteamWrapper_LbGetScore, 0, int index);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// private static extern IntPtr SteamWrapper_LbGetName(int index);
STUB(IntPtr, SteamWrapper_LbGetName, 0, int index);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// public static extern ulong SteamWrapper_LbGetId(int index);
STUB(ulong, SteamWrapper_LbGetId, 0, int index);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// public static extern int SteamWrapper_LbGetCount();
STUB(int, SteamWrapper_LbGetCount, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// public static extern int SteamWrapper_LbGetTotalSize();
STUB(int, SteamWrapper_LbGetTotalSize, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// public static extern bool SteamWrapper_IsLbInitialized();
STUB(bool, SteamWrapper_IsLbInitialized, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_IsCloudStorageEnabled();
STUB(bool, SteamWrapper_IsCloudStorageEnabled, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// public static extern int SteamWrapper_FileWrite(string file, IntPtr data, int size);
STUB(int, SteamWrapper_FileWrite, 0, string file, IntPtr data, int size);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// public static extern int SteamWrapper_FileRead(string file, IntPtr data, int size);
STUB(int, SteamWrapper_FileRead, 0, string file, IntPtr data, int size);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_FileDelete(string file);
STUB(bool, SteamWrapper_FileDelete, 0, string file);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_FileExists(string file);
STUB(bool, SteamWrapper_FileExists, 0, string file);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// public static extern int SteamWrapper_GetFileSize(string file);
STUB(int, SteamWrapper_GetFileSize, 0, string file);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// public static extern long SteamWrapper_GetFileTimestamp(string file);
STUB(long, SteamWrapper_GetFileTimestamp, 0, string file);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// public static extern int SteamWrapper_GetFileCount();
STUB(int, SteamWrapper_GetFileCount, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// private static extern IntPtr SteamWrapper_GetFileNameAndSize(int index, out int fileSizeInBytes);
STUB(IntPtr, SteamWrapper_GetFileNameAndSize, 0, int index, out int fileSizeInBytes);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// private static extern IntPtr SteamWrapper_GetPersonaName();
STUB(IntPtr, SteamWrapper_GetPersonaName, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// public static extern ulong SteamWrapper_GetSteamId();
STUB(ulong, SteamWrapper_GetSteamId, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_SetRichPresence(string presence);
STUB(bool, SteamWrapper_SetRichPresence, 0, string presence);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// private static extern IntPtr SteamWrapper_GetUserDataFolder();
STUB(IntPtr, SteamWrapper_GetUserDataFolder, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// private static extern void SteamWrapper_ActivateGameOverlayToUser(string dialog, ulong steamId);
STUB(void, SteamWrapper_ActivateGameOverlayToUser, 0, string dialog, ulong steamId);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// public static extern void SteamWrapper_ActivateGameOverlayToStore(uint appId);
STUB(void, SteamWrapper_ActivateGameOverlayToStore, 0, uint appId);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// public static extern void SteamWrapper_ActivateGameOverlayToWebPage(string url);
STUB(void, SteamWrapper_ActivateGameOverlayToWebPage, 0, string url);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_IsOverlayEnabled();
STUB(bool, SteamWrapper_IsOverlayEnabled, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_IsOverlayActive();
STUB(bool, SteamWrapper_IsOverlayActive, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// private static extern IntPtr SteamWrapper_GetCurrentGameLanguage();
IntPtr SteamWrapper_GetCurrentGameLanguage()
{
    return (IntPtr)"english";
}

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// public static extern void SteamWrapper_NetUpdate(uint mapID);
STUB(void, SteamWrapper_NetUpdate, 0, uint mapID);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// public unsafe static extern int SteamWrapper_GetNextPacket(byte* packetBuf, int packetBufSize, ref ulong playerID);
STUB(int, SteamWrapper_GetNextPacket, 0, byte* packetBuf, int packetBufSize, ref ulong playerID);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// public unsafe static extern int SteamWrapper_SendPacket(void* packet, uint len, ulong playerID);
STUB(int, SteamWrapper_SendPacket, 0, void* packet, uint len, ulong playerID);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// public static extern void SteamWrapper_SetForceCreateRoom(int flag);
STUB(void, SteamWrapper_SetForceCreateRoom, 0, int flag);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// public static extern ulong SteamWrapper_GetNextNewPlayer();
STUB(ulong, SteamWrapper_GetNextNewPlayer, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_ControllerInit(string controllerPath);
STUB(bool, SteamWrapper_ControllerInit, 0, string controllerPath);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// public static extern void SteamWrapper_ControllerShutdown();
STUB(void, SteamWrapper_ControllerShutdown, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// [return: MarshalAs(UnmanagedType.I1)]
// public static extern bool SteamWrapper_ControllerState(uint controllerIndex, out SteamWrapper.ControllerState state);
STUB(bool, SteamWrapper_ControllerState, 0, uint controllerIndex, ControllerState state);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
// public static extern void SteamWrapper_TriggerHapticPulse(uint controllerIndex, SteamWrapper.SteamControllerPad targetPad, ushort duration);
STUB(void, SteamWrapper_TriggerHapticPulse, 0, uint controllerIndex, SteamControllerPad targetPad, ushort duration);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
// public static extern void SteamWrapper_ControllerOverideMode(string mode);
STUB(void, SteamWrapper_ControllerOverideMode, 0, string mode);
