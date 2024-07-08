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

typedef int AudioPlayback_Status;
typedef int EAccountType;
typedef int EActivateGameOverlayToWebPageMode;
typedef int EChatEntryType;
typedef int EControllerHapticLocation;
typedef int EFriendFlags;
typedef int EFriendRelationship;
typedef int EHTMLKeyModifiers;
typedef int EHTMLMouseButton;
typedef int EInputActionOrigin;
typedef int ELobbyComparison;
typedef int ELobbyDistanceFilter;
typedef int ELobbyType;
typedef int EOverlayToStoreFlag;
typedef int EP2PSend;
typedef int EPersonaState;
typedef int ESNetSocketConnectionType;
typedef int ESteamControllerPad;
typedef int ESteamInputGlyphSize;
typedef int ESteamInputType;
typedef int ESteamNetworkingConnectionState;
typedef int ESteamPartyBeaconLocationData;
typedef int EXboxOrigin;
typedef int ESteamIPType;
typedef int EGameSearchErrorCode_t;
typedef uint32_t HServerListRequest;
typedef uint32_t HServerQuery;
typedef uint32_t HSteamListenSocket;
typedef uint32_t HSteamNetPollGroup;
typedef uint32_t HSteamUser;
typedef uint32_t HTTPCookieContainerHandle;
typedef struct EPlayerResult_t { } EPlayerResult_t;
typedef struct FriendsGroupID_t { } FriendsGroupID_t;
typedef struct InputActionSetHandle_t { } InputActionSetHandle_t;
typedef struct InputAnalogActionData_t { } InputAnalogActionData_t;
typedef struct InputAnalogActionHandle_t { } InputAnalogActionHandle_t;
typedef struct InputDigitalActionData_t { } InputDigitalActionData_t;
typedef struct InputDigitalActionHandle_t { } InputDigitalActionHandle_t;
typedef struct InputHandle_t { } InputHandle_t;
typedef struct InputMotionData_t { } InputMotionData_t;
typedef struct P2PSessionState_t { } P2PSessionState_t;
typedef struct PartyBeaconID_t { } PartyBeaconID_t;
typedef struct SNetListenSocket_t { } SNetListenSocket_t;
typedef struct SNetSocket_t { } SNetSocket_t;
typedef uint32_t ClientUnifiedMessageHandle;
typedef uint32_t ControllerActionSetHandle_t;
typedef uint32_t ControllerAnalogActionHandle_t;
typedef uint32_t ControllerDigitalActionHandle_t;
typedef uint32_t ControllerHandle_t;
typedef struct ControllerAnalogActionData_t { } ControllerAnalogActionData_t;
typedef struct ControllerDigitalActionData_t { } ControllerDigitalActionData_t;
typedef struct ControllerMotionData_t { } ControllerMotionData_t;
typedef struct EControllerActionOrigin { } EControllerActionOrigin;
typedef struct SteamDatagramRelayAuthTicket { } SteamDatagramRelayAuthTicket;
typedef struct SteamInventoryResult_t { } SteamInventoryResult_t;
typedef struct SteamInventoryUpdateHandle_t { } SteamInventoryUpdateHandle_t;
typedef struct SteamIPAddress_t {
    uint64_t ipv6;
    ESteamIPType type;
} SteamIPAddress_t;
typedef struct SteamItemDef_t { } SteamItemDef_t;
typedef struct SteamItemDetails_t { } SteamItemDetails_t;
typedef struct SteamItemInstanceID_t { } SteamItemInstanceID_t;
typedef struct SteamNetAuthenticationStatus_t { } SteamNetAuthenticationStatus_t;
typedef struct SteamNetConnectionInfo_t { } SteamNetConnectionInfo_t;
typedef struct SteamNetConnectionRealTimeLaneStatus_t { } SteamNetConnectionRealTimeLaneStatus_t;
typedef struct SteamNetConnectionRealTimeStatus_t { } SteamNetConnectionRealTimeStatus_t;
typedef struct SteamNetworkingMessage_t { } SteamNetworkingMessage_t;
typedef struct SteamPartyBeaconLocation_t { } SteamPartyBeaconLocation_t;

typedef struct CGameID { } CGameID;
typedef char bool;
typedef char * string;
typedef char * SteamNetworkingErrMsg;
typedef void * FSteamNetworkingSocketsDebugOutput;
typedef void * SteamAPIWarningMessageHook_t;
typedef void * SteamInputActionEventCallbackPointer;
typedef struct SteamRelayNetworkStatus_t { } SteamRelayNetworkStatus_t;
typedef struct SteamNetworkPingLocation_t { } SteamNetworkPingLocation_t;
typedef struct FriendGameInfo_t { } FriendGameInfo_t;
typedef struct PublishedFileId_t { } PublishedFileId_t;
typedef struct DepotId_t { } DepotId_t;
typedef struct UGCUpdateHandle_t { } UGCUpdateHandle_t;
typedef struct UGCQueryHandle_t { } UGCQueryHandle_t;
typedef struct SteamUGCDetails_t { } SteamUGCDetails_t;
typedef struct PublishedFileUpdateHandle_t { } PublishedFileUpdateHandle_t;
typedef struct UGCFileWriteStreamHandle_t { } UGCFileWriteStreamHandle_t;
typedef struct RemotePlaySessionID_t { } RemotePlaySessionID_t;
typedef struct AccountID_t { } AccountID_t;
typedef struct SteamNetworkingIdentity { } SteamNetworkingIdentity;
typedef struct SteamNetworkingIPAddr { } SteamNetworkingIPAddr;
typedef struct SteamNetworkingConfigValue_t { } SteamNetworkingConfigValue_t;
typedef struct SteamNetworkingFakeIPResult_t { } SteamNetworkingFakeIPResult_t;
typedef struct SteamDatagramHostedAddress { } SteamDatagramHostedAddress;
typedef int ISteamNetworkingConnectionSignaling;
typedef int ISteamNetworkingSignalingRecvContext;
typedef int ESteamNetworkingAvailability;
typedef int ESteamNetworkingConfigValue;
typedef int ESteamNetworkingSocketsDebugOutputType;
typedef int EResult;
typedef int ESteamNetworkingGetConfigValueResult;
typedef int ESteamNetworkingConfigDataType;
typedef int ESteamNetworkingConfigScope;
typedef int ESteamNetworkingFakeIPType;
typedef int EParentalFeature;
typedef int ESteamDeviceFormFactor;
typedef int ERemoteStoragePlatform;
typedef int EUGCReadAction;
typedef int EWorkshopVideoProvider;
typedef int EWorkshopFileAction;
typedef int EWorkshopEnumerationType;
typedef int ERemoteStorageLocalFileChange;
typedef int ERemoteStorageFilePathType;
typedef int ELeaderboardUploadScoreMethod;
typedef int EVRScreenshotType;
typedef int EUserUGCList;
typedef int EUserUGCListSortOrder;
typedef int EUGCQuery;
typedef int EUGCMatchingUGCType;
typedef int EItemStatistic;
typedef int EWorkshopFileType;
typedef int ERemoteStoragePublishedFileVisibility;
typedef int EItemPreviewType;
typedef int EItemUpdateStatus;
typedef int EUniverse;
typedef int ENotificationPosition;
typedef int ESteamAPICallFailure;
typedef int EGamepadTextInputMode;
typedef int EGamepadTextInputLineMode;
typedef int ETextFilteringContext;
typedef int EFloatingGamepadTextInputMode;
typedef int ESteamIPv6ConnectivityProtocol;
typedef int ESteamIPv6ConnectivityState;
typedef int EUserHasLicenseForAppResult;
typedef int ELeaderboardDataRequest;
typedef int ELeaderboardDisplayType;
typedef int ELeaderboardSortMethod;
typedef int EDurationControlOnlineState;
typedef int EVoiceResult;
typedef uint64_t CSteamID;
typedef uint64_t SteamLeaderboard_t;
typedef uint64_t UGCHandle_t;
typedef uint64_t SteamAPICall_t;
typedef uint64_t SteamLeaderboardEntries_t;
typedef uint64_t LeaderboardEntry_t;
typedef int EHTTPMethod;
typedef uint32_t SteamNetworkingPOPID;
typedef uint32_t ScreenshotHandle;
typedef uint32_t HSteamNetConnection;
typedef uint32_t HSteamPipe;
typedef uint32_t HAuthTicket;
typedef uint32_t HHTMLBrowser;
typedef uint32_t HTTPRequestHandle;
typedef uint32_t uint;
typedef uint64_t ulong;
typedef uint16_t ushort;
typedef intptr_t IntPtr;
typedef uint AppId_t;
typedef int EServerMode;
typedef int EBeginAuthSessionResult;
typedef char byte;
#define out
#define ref
#define STUB(t, x, v, ...) t x( __VA_ARGS__ ) { return v; };

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_Init, 0, )

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_Shutdown, 0, )

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_RestartAppIfNecessary, 0, AppId_t unOwnAppID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_ReleaseCurrentThreadMemory, 0, )

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_WriteMiniDump, 0, uint uStructuredExceptionCode, IntPtr pvExceptionInfo, uint uBuildID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_SetMiniDumpComment, 0, char * pchMsg)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_RunCallbacks, 0, )

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_RegisterCallback, 0, IntPtr pCallback, int iCallback)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_UnregisterCallback, 0, IntPtr pCallback)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_RegisterCallResult, 0, IntPtr pCallback, ulong hAPICall)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_UnregisterCallResult, 0, IntPtr pCallback, ulong hAPICall)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_IsSteamRunning, 0, )

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(int, SteamAPI_GetSteamInstallPath, 0, )

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(int, SteamAPI_GetHSteamPipe, 0, )

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_SetTryCatchCallbacks, 0, char bTryCatchCallbacks)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(int, SteamAPI_GetHSteamUser, 0, )

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, SteamInternal_ContextInit, 0, IntPtr pContextInitData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, SteamInternal_CreateInterface, 0, char * ver)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, SteamInternal_FindOrCreateUserInterface, 0, HSteamUser hSteamUser, char * pszVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, SteamInternal_FindOrCreateGameServerInterface, 0, HSteamUser hSteamUser, char * pszVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_UseBreakpadCrashHandler, 0, char * pchVersion, char * pchDate, char * pchTime, char bFullMemoryDumps, IntPtr pvContext, IntPtr m_pfnPreMinidumpCallback)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_SetBreakpadAppID, 0, uint unAppID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_ManualDispatch_Init, 0, )

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_ManualDispatch_RunFrame, 0, HSteamPipe hSteamPipe)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_ManualDispatch_GetNextCallback, 0, HSteamPipe hSteamPipe, IntPtr pCallbackMsg)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_ManualDispatch_FreeLastCallback, 0, HSteamPipe hSteamPipe)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_ManualDispatch_GetAPICallResult, 0, HSteamPipe hSteamPipe, SteamAPICall_t hSteamAPICall, IntPtr pCallback, int cubCallback, int iCallbackExpected, out bool pbFailed)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamGameServer_Shutdown, 0, )

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamGameServer_RunCallbacks, 0, )

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamGameServer_ReleaseCurrentThreadMemory, 0, )

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamGameServer_BSecure, 0, )

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, SteamGameServer_GetSteamID, 0, )

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(int, SteamGameServer_GetHSteamPipe, 0, )

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(int, SteamGameServer_GetHSteamUser, 0, )

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamInternal_GameServer_Init, 0, uint unIP, ushort usPort, ushort usGamePort, ushort usQueryPort, EServerMode eServerMode, char * pchVersionString)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, SteamClient, 0, )

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, SteamGameServerClient, 0, )

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_SteamNetworkingIPAddr_Clear, 0, struct SteamNetworkingIPAddr * self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_SteamNetworkingIPAddr_IsIPv6AllZeros, 0, struct SteamNetworkingIPAddr * self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_SteamNetworkingIPAddr_SetIPv6, 0, struct SteamNetworkingIPAddr * self, byte* ipv6, ushort nPort)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_SteamNetworkingIPAddr_SetIPv4, 0, struct SteamNetworkingIPAddr * self, uint nIP, ushort nPort)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_SteamNetworkingIPAddr_IsIPv4, 0, struct SteamNetworkingIPAddr * self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, SteamAPI_SteamNetworkingIPAddr_GetIPv4, 0, struct SteamNetworkingIPAddr * self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_SteamNetworkingIPAddr_SetIPv6LocalHost, 0, struct SteamNetworkingIPAddr * self, ushort nPort)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_SteamNetworkingIPAddr_IsLocalHost, 0, struct SteamNetworkingIPAddr * self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_SteamNetworkingIPAddr_ToString, 0, struct SteamNetworkingIPAddr * self, IntPtr buf, uint cbBuf, char bWithPort)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_SteamNetworkingIPAddr_ParseString, 0, struct SteamNetworkingIPAddr * self, char * pszStr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_SteamNetworkingIPAddr_IsEqualTo, 0, struct SteamNetworkingIPAddr * self, struct SteamNetworkingIPAddr * x)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(ESteamNetworkingFakeIPType, SteamAPI_SteamNetworkingIPAddr_GetFakeIPType, 0, struct SteamNetworkingIPAddr * self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_SteamNetworkingIPAddr_IsFakeIP, 0, struct SteamNetworkingIPAddr * self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_SteamNetworkingIdentity_Clear, 0, ref SteamNetworkingIdentity self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_SteamNetworkingIdentity_IsInvalid, 0, ref SteamNetworkingIdentity self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_SteamNetworkingIdentity_SetSteamID, 0, ref SteamNetworkingIdentity self, ulong steamID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, SteamAPI_SteamNetworkingIdentity_GetSteamID, 0, ref SteamNetworkingIdentity self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_SteamNetworkingIdentity_SetSteamID64, 0, ref SteamNetworkingIdentity self, ulong steamID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, SteamAPI_SteamNetworkingIdentity_GetSteamID64, 0, ref SteamNetworkingIdentity self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_SteamNetworkingIdentity_SetXboxPairwiseID, 0, ref SteamNetworkingIdentity self, char * pszString)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, SteamAPI_SteamNetworkingIdentity_GetXboxPairwiseID, 0, ref SteamNetworkingIdentity self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, SteamAPI_SteamNetworkingIdentity_SetIPAddr, 0, ref SteamNetworkingIdentity self, struct SteamNetworkingIPAddr * addr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, SteamAPI_SteamNetworkingIdentity_GetIPAddr, 0, ref SteamNetworkingIdentity self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_SteamNetworkingIdentity_SetIPv4Addr, 0, ref SteamNetworkingIdentity self, uint nIPv4, ushort nPort)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, SteamAPI_SteamNetworkingIdentity_GetIPv4, 0, ref SteamNetworkingIdentity self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(ESteamNetworkingFakeIPType, SteamAPI_SteamNetworkingIdentity_GetFakeIPType, 0, ref SteamNetworkingIdentity self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_SteamNetworkingIdentity_IsFakeIP, 0, ref SteamNetworkingIdentity self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_SteamNetworkingIdentity_SetLocalHost, 0, ref SteamNetworkingIdentity self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_SteamNetworkingIdentity_IsLocalHost, 0, ref SteamNetworkingIdentity self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_SteamNetworkingIdentity_SetGenericString, 0, ref SteamNetworkingIdentity self, char * pszString)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, SteamAPI_SteamNetworkingIdentity_GetGenericString, 0, ref SteamNetworkingIdentity self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_SteamNetworkingIdentity_SetGenericBytes, 0, ref SteamNetworkingIdentity self, byte* data, uint cbLen)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, SteamAPI_SteamNetworkingIdentity_GetGenericBytes, 0, ref SteamNetworkingIdentity self, out int cbLen)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_SteamNetworkingIdentity_IsEqualTo, 0, ref SteamNetworkingIdentity self, ref SteamNetworkingIdentity x)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_SteamNetworkingIdentity_ToString, 0, ref SteamNetworkingIdentity self, IntPtr buf, uint cbBuf)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_SteamNetworkingIdentity_ParseString, 0, ref SteamNetworkingIdentity self, char * pszStr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_SteamNetworkingMessage_t_Release, 0, IntPtr self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamAPI_ISteamNetworkingConnectionSignaling_SendSignal, 0, ref ISteamNetworkingConnectionSignaling self, HSteamNetConnection hConn, ref SteamNetConnectionInfo_t info, IntPtr pMsg, int cbMsg)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_ISteamNetworkingConnectionSignaling_Release, 0, ref ISteamNetworkingConnectionSignaling self)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, SteamAPI_ISteamNetworkingSignalingRecvContext_OnConnectRequest, 0, ref ISteamNetworkingSignalingRecvContext self, HSteamNetConnection hConn, ref SteamNetworkingIdentity identityPeer, int nLocalVirtualPort)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamAPI_ISteamNetworkingSignalingRecvContext_SendRejectionSignal, 0, ref ISteamNetworkingSignalingRecvContext self, ref SteamNetworkingIdentity identityPeer, IntPtr pMsg, int cbMsg)

// [DllImport("sdkencryptedappticket", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamEncryptedAppTicket_BDecryptTicket, 0, byte* rgubTicketEncrypted, uint cubTicketEncrypted, byte* rgubTicketDecrypted, ref uint pcubTicketDecrypted, byte* rgubKey, int cubKey)

// [DllImport("sdkencryptedappticket", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamEncryptedAppTicket_BIsTicketForApp, 0, byte* rgubTicketDecrypted, uint cubTicketDecrypted, AppId_t nAppID)

// [DllImport("sdkencryptedappticket", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, SteamEncryptedAppTicket_GetTicketIssueTime, 0, byte* rgubTicketDecrypted, uint cubTicketDecrypted)

// [DllImport("sdkencryptedappticket", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamEncryptedAppTicket_GetTicketSteamID, 0, byte* rgubTicketDecrypted, uint cubTicketDecrypted, out CSteamID psteamID)

// [DllImport("sdkencryptedappticket", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, SteamEncryptedAppTicket_GetTicketAppID, 0, byte* rgubTicketDecrypted, uint cubTicketDecrypted)

// [DllImport("sdkencryptedappticket", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamEncryptedAppTicket_BUserOwnsAppInTicket, 0, byte* rgubTicketDecrypted, uint cubTicketDecrypted, AppId_t nAppID)

// [DllImport("sdkencryptedappticket", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamEncryptedAppTicket_BUserIsVacBanned, 0, byte* rgubTicketDecrypted, uint cubTicketDecrypted)

// [DllImport("sdkencryptedappticket", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, SteamEncryptedAppTicket_GetUserVariableData, 0, byte* rgubTicketDecrypted, uint cubTicketDecrypted, out uint pcubUserData)

// [DllImport("sdkencryptedappticket", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamEncryptedAppTicket_BIsTicketSigned, 0, byte* rgubTicketDecrypted, uint cubTicketDecrypted, byte* pubRSAKey, uint cubRSAKey)

// [DllImport("sdkencryptedappticket", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamEncryptedAppTicket_BIsLicenseBorrowed, 0, byte* rgubTicketDecrypted, uint cubTicketDecrypted)

// [DllImport("sdkencryptedappticket", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamEncryptedAppTicket_BIsLicenseTemporary, 0, byte* rgubTicketDecrypted, uint cubTicketDecrypted)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamAppList_GetNumInstalledApps")]
STUB(uint, SteamAPI_ISteamAppList_GetNumInstalledApps, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamAppList_GetInstalledApps")]
STUB(uint, SteamAPI_ISteamAppList_GetInstalledApps, 0, IntPtr instancePtr, AppId_t* pvecAppID, uint unMaxAppIDs)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamAppList_GetAppName")]
STUB(int, SteamAPI_ISteamAppList_GetAppName, 0, IntPtr instancePtr, AppId_t nAppID, IntPtr pchName, int cchNameMax)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamAppList_GetAppInstallDir")]
STUB(int, SteamAPI_ISteamAppList_GetAppInstallDir, 0, IntPtr instancePtr, AppId_t nAppID, IntPtr pchDirectory, int cchNameMax)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamAppList_GetAppBuildId")]
STUB(int, SteamAPI_ISteamAppList_GetAppBuildId, 0, IntPtr instancePtr, AppId_t nAppID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_BIsSubscribed")]
STUB(bool, SteamAPI_ISteamApps_BIsSubscribed, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_BIsLowViolence")]
STUB(bool, SteamAPI_ISteamApps_BIsLowViolence, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_BIsCybercafe")]
STUB(bool, SteamAPI_ISteamApps_BIsCybercafe, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_BIsVACBanned")]
STUB(bool, SteamAPI_ISteamApps_BIsVACBanned, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_GetCurrentGameLanguage")]
STUB(IntPtr, SteamAPI_ISteamApps_GetCurrentGameLanguage, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_GetAvailableGameLanguages")]
STUB(IntPtr, SteamAPI_ISteamApps_GetAvailableGameLanguages, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_BIsSubscribedApp")]
STUB(bool, SteamAPI_ISteamApps_BIsSubscribedApp, 0, IntPtr instancePtr, AppId_t appID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_BIsDlcInstalled")]
STUB(bool, SteamAPI_ISteamApps_BIsDlcInstalled, 0, IntPtr instancePtr, AppId_t appID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime")]
STUB(uint, SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime, 0, IntPtr instancePtr, AppId_t nAppID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend")]
STUB(bool, SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_GetDLCCount")]
STUB(int, SteamAPI_ISteamApps_GetDLCCount, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_BGetDLCDataByIndex")]
STUB(bool, SteamAPI_ISteamApps_BGetDLCDataByIndex, 0, IntPtr instancePtr, int iDLC, out AppId_t pAppID, out bool pbAvailable, IntPtr pchName, int cchNameBufferSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_InstallDLC")]
STUB(void, SteamAPI_ISteamApps_InstallDLC, 0, IntPtr instancePtr, AppId_t nAppID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_UninstallDLC")]
STUB(void, SteamAPI_ISteamApps_UninstallDLC, 0, IntPtr instancePtr, AppId_t nAppID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey")]
STUB(void, SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey, 0, IntPtr instancePtr, AppId_t nAppID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_GetCurrentBetaName")]
STUB(bool, SteamAPI_ISteamApps_GetCurrentBetaName, 0, IntPtr instancePtr, IntPtr pchName, int cchNameBufferSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_MarkContentCorrupt")]
STUB(bool, SteamAPI_ISteamApps_MarkContentCorrupt, 0, IntPtr instancePtr, char bMissingFilesOnly)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_GetInstalledDepots")]
STUB(uint, SteamAPI_ISteamApps_GetInstalledDepots, 0, IntPtr instancePtr, AppId_t appID, DepotId_t* pvecDepots, uint cMaxDepots)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_GetAppInstallDir")]
STUB(uint, SteamAPI_ISteamApps_GetAppInstallDir, 0, IntPtr instancePtr, AppId_t appID, IntPtr pchFolder, uint cchFolderBufferSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_BIsAppInstalled")]
STUB(bool, SteamAPI_ISteamApps_BIsAppInstalled, 0, IntPtr instancePtr, AppId_t appID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_GetAppOwner")]
STUB(ulong, SteamAPI_ISteamApps_GetAppOwner, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_GetLaunchQueryParam")]
STUB(IntPtr, SteamAPI_ISteamApps_GetLaunchQueryParam, 0, IntPtr instancePtr, char * pchKey)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_GetDlcDownloadProgress")]
STUB(bool, SteamAPI_ISteamApps_GetDlcDownloadProgress, 0, IntPtr instancePtr, AppId_t nAppID, out ulong punBytesDownloaded, out ulong punBytesTotal)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_GetAppBuildId")]
STUB(int, SteamAPI_ISteamApps_GetAppBuildId, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_RequestAllProofOfPurchaseKeys")]
STUB(void, SteamAPI_ISteamApps_RequestAllProofOfPurchaseKeys, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_GetFileDetails")]
STUB(ulong, SteamAPI_ISteamApps_GetFileDetails, 0, IntPtr instancePtr, char * pszFileName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_GetLaunchCommandLine")]
STUB(int, SteamAPI_ISteamApps_GetLaunchCommandLine, 0, IntPtr instancePtr, IntPtr pszCommandLine, int cubCommandLine)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_BIsSubscribedFromFamilySharing")]
STUB(bool, SteamAPI_ISteamApps_BIsSubscribedFromFamilySharing, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamApps_BIsTimedTrial")]
STUB(bool, SteamAPI_ISteamApps_BIsTimedTrial, 0, IntPtr instancePtr, out uint punSecondsAllowed, out uint punSecondsPlayed)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_CreateSteamPipe")]
STUB(int, SteamAPI_ISteamClient_CreateSteamPipe, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_BReleaseSteamPipe")]
STUB(bool, SteamAPI_ISteamClient_BReleaseSteamPipe, 0, IntPtr instancePtr, HSteamPipe hSteamPipe)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_ConnectToGlobalUser")]
STUB(int, SteamAPI_ISteamClient_ConnectToGlobalUser, 0, IntPtr instancePtr, HSteamPipe hSteamPipe)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_CreateLocalUser")]
STUB(int, SteamAPI_ISteamClient_CreateLocalUser, 0, IntPtr instancePtr, out HSteamPipe phSteamPipe, EAccountType eAccountType)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_ReleaseUser")]
STUB(void, SteamAPI_ISteamClient_ReleaseUser, 0, IntPtr instancePtr, HSteamPipe hSteamPipe, HSteamUser hUser)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamUser")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamUser, 0, IntPtr instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamGameServer")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamGameServer, 0, IntPtr instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_SetLocalIPBinding")]
STUB(void, SteamAPI_ISteamClient_SetLocalIPBinding, 0, IntPtr instancePtr, ref SteamIPAddress_t unIP, ushort usPort)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamFriends")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamFriends, 0, IntPtr instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamUtils")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamUtils, 0, IntPtr instancePtr, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamMatchmaking")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamMatchmaking, 0, IntPtr instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamMatchmakingServers")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamMatchmakingServers, 0, IntPtr instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamGenericInterface")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamGenericInterface, 0, IntPtr instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamUserStats")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamUserStats, 0, IntPtr instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamGameServerStats")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamGameServerStats, 0, IntPtr instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamApps")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamApps, 0, IntPtr instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamNetworking")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamNetworking, 0, IntPtr instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamRemoteStorage")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamRemoteStorage, 0, IntPtr instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamScreenshots")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamScreenshots, 0, IntPtr instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamGameSearch")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamGameSearch, 0, IntPtr instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetIPCCallCount")]
STUB(uint, SteamAPI_ISteamClient_GetIPCCallCount, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_SetWarningMessageHook")]
STUB(void, SteamAPI_ISteamClient_SetWarningMessageHook, 0, IntPtr instancePtr, SteamAPIWarningMessageHook_t pFunction)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_BShutdownIfAllPipesClosed")]
STUB(bool, SteamAPI_ISteamClient_BShutdownIfAllPipesClosed, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamHTTP")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamHTTP, 0, IntPtr instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamController")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamController, 0, IntPtr instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamUGC")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamUGC, 0, IntPtr instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamAppList")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamAppList, 0, IntPtr instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamMusic")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamMusic, 0, IntPtr instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamMusicRemote")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamMusicRemote, 0, IntPtr instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamHTMLSurface")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamHTMLSurface, 0, IntPtr instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamInventory")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamInventory, 0, IntPtr instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamVideo")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamVideo, 0, IntPtr instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamParentalSettings")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamParentalSettings, 0, IntPtr instancePtr, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamInput")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamInput, 0, IntPtr instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamParties")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamParties, 0, IntPtr instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamClient_GetISteamRemotePlay")]
STUB(IntPtr, SteamAPI_ISteamClient_GetISteamRemotePlay, 0, IntPtr instancePtr, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetPersonaName")]
STUB(IntPtr, SteamAPI_ISteamFriends_GetPersonaName, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_SetPersonaName")]
STUB(ulong, SteamAPI_ISteamFriends_SetPersonaName, 0, IntPtr instancePtr, char * pchPersonaName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetPersonaState")]
STUB(EPersonaState, SteamAPI_ISteamFriends_GetPersonaState, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendCount")]
STUB(int, SteamAPI_ISteamFriends_GetFriendCount, 0, IntPtr instancePtr, EFriendFlags iFriendFlags)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendByIndex")]
STUB(ulong, SteamAPI_ISteamFriends_GetFriendByIndex, 0, IntPtr instancePtr, int iFriend, EFriendFlags iFriendFlags)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendRelationship")]
STUB(EFriendRelationship, SteamAPI_ISteamFriends_GetFriendRelationship, 0, IntPtr instancePtr, CSteamID steamIDFriend)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendPersonaState")]
STUB(EPersonaState, SteamAPI_ISteamFriends_GetFriendPersonaState, 0, IntPtr instancePtr, CSteamID steamIDFriend)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendPersonaName")]
STUB(IntPtr, SteamAPI_ISteamFriends_GetFriendPersonaName, 0, IntPtr instancePtr, CSteamID steamIDFriend)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendGamePlayed")]
STUB(bool, SteamAPI_ISteamFriends_GetFriendGamePlayed, 0, IntPtr instancePtr, CSteamID steamIDFriend, out FriendGameInfo_t pFriendGameInfo)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendPersonaNameHistory")]
STUB(IntPtr, SteamAPI_ISteamFriends_GetFriendPersonaNameHistory, 0, IntPtr instancePtr, CSteamID steamIDFriend, int iPersonaName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendSteamLevel")]
STUB(int, SteamAPI_ISteamFriends_GetFriendSteamLevel, 0, IntPtr instancePtr, CSteamID steamIDFriend)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetPlayerNickname")]
STUB(IntPtr, SteamAPI_ISteamFriends_GetPlayerNickname, 0, IntPtr instancePtr, CSteamID steamIDPlayer)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendsGroupCount")]
STUB(int, SteamAPI_ISteamFriends_GetFriendsGroupCount, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendsGroupIDByIndex")]
STUB(short, SteamAPI_ISteamFriends_GetFriendsGroupIDByIndex, 0, IntPtr instancePtr, int iFG)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendsGroupName")]
STUB(IntPtr, SteamAPI_ISteamFriends_GetFriendsGroupName, 0, IntPtr instancePtr, FriendsGroupID_t friendsGroupID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendsGroupMembersCount")]
STUB(int, SteamAPI_ISteamFriends_GetFriendsGroupMembersCount, 0, IntPtr instancePtr, FriendsGroupID_t friendsGroupID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendsGroupMembersList")]
STUB(void, SteamAPI_ISteamFriends_GetFriendsGroupMembersList, 0, IntPtr instancePtr, FriendsGroupID_t friendsGroupID, CSteamID* pOutSteamIDMembers, int nMembersCount)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_HasFriend")]
STUB(bool, SteamAPI_ISteamFriends_HasFriend, 0, IntPtr instancePtr, CSteamID steamIDFriend, EFriendFlags iFriendFlags)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetClanCount")]
STUB(int, SteamAPI_ISteamFriends_GetClanCount, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetClanByIndex")]
STUB(ulong, SteamAPI_ISteamFriends_GetClanByIndex, 0, IntPtr instancePtr, int iClan)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetClanName")]
STUB(IntPtr, SteamAPI_ISteamFriends_GetClanName, 0, IntPtr instancePtr, CSteamID steamIDClan)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetClanTag")]
STUB(IntPtr, SteamAPI_ISteamFriends_GetClanTag, 0, IntPtr instancePtr, CSteamID steamIDClan)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetClanActivityCounts")]
STUB(bool, SteamAPI_ISteamFriends_GetClanActivityCounts, 0, IntPtr instancePtr, CSteamID steamIDClan, out int pnOnline, out int pnInGame, out int pnChatting)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_DownloadClanActivityCounts")]
STUB(ulong, SteamAPI_ISteamFriends_DownloadClanActivityCounts, 0, IntPtr instancePtr, CSteamID* psteamIDClans, int cClansToRequest)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendCountFromSource")]
STUB(int, SteamAPI_ISteamFriends_GetFriendCountFromSource, 0, IntPtr instancePtr, CSteamID steamIDSource)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendFromSourceByIndex")]
STUB(ulong, SteamAPI_ISteamFriends_GetFriendFromSourceByIndex, 0, IntPtr instancePtr, CSteamID steamIDSource, int iFriend)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_IsUserInSource")]
STUB(bool, SteamAPI_ISteamFriends_IsUserInSource, 0, IntPtr instancePtr, CSteamID steamIDUser, CSteamID steamIDSource)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_SetInGameVoiceSpeaking")]
STUB(void, SteamAPI_ISteamFriends_SetInGameVoiceSpeaking, 0, IntPtr instancePtr, CSteamID steamIDUser, char bSpeaking)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_ActivateGameOverlay")]
STUB(void, SteamAPI_ISteamFriends_ActivateGameOverlay, 0, IntPtr instancePtr, char * pchDialog)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_ActivateGameOverlayToUser")]
STUB(void, SteamAPI_ISteamFriends_ActivateGameOverlayToUser, 0, IntPtr instancePtr, char * pchDialog, CSteamID steamID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_ActivateGameOverlayToWebPage")]
STUB(void, SteamAPI_ISteamFriends_ActivateGameOverlayToWebPage, 0, IntPtr instancePtr, char * pchURL, EActivateGameOverlayToWebPageMode eMode)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_ActivateGameOverlayToStore")]
STUB(void, SteamAPI_ISteamFriends_ActivateGameOverlayToStore, 0, IntPtr instancePtr, AppId_t nAppID, EOverlayToStoreFlag eFlag)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_SetPlayedWith")]
STUB(void, SteamAPI_ISteamFriends_SetPlayedWith, 0, IntPtr instancePtr, CSteamID steamIDUserPlayedWith)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog")]
STUB(void, SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog, 0, IntPtr instancePtr, CSteamID steamIDLobby)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetSmallFriendAvatar")]
STUB(int, SteamAPI_ISteamFriends_GetSmallFriendAvatar, 0, IntPtr instancePtr, CSteamID steamIDFriend)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetMediumFriendAvatar")]
STUB(int, SteamAPI_ISteamFriends_GetMediumFriendAvatar, 0, IntPtr instancePtr, CSteamID steamIDFriend)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetLargeFriendAvatar")]
STUB(int, SteamAPI_ISteamFriends_GetLargeFriendAvatar, 0, IntPtr instancePtr, CSteamID steamIDFriend)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_RequestUserInformation")]
STUB(bool, SteamAPI_ISteamFriends_RequestUserInformation, 0, IntPtr instancePtr, CSteamID steamIDUser, char bRequireNameOnly)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_RequestClanOfficerList")]
STUB(ulong, SteamAPI_ISteamFriends_RequestClanOfficerList, 0, IntPtr instancePtr, CSteamID steamIDClan)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetClanOwner")]
STUB(ulong, SteamAPI_ISteamFriends_GetClanOwner, 0, IntPtr instancePtr, CSteamID steamIDClan)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetClanOfficerCount")]
STUB(int, SteamAPI_ISteamFriends_GetClanOfficerCount, 0, IntPtr instancePtr, CSteamID steamIDClan)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetClanOfficerByIndex")]
STUB(ulong, SteamAPI_ISteamFriends_GetClanOfficerByIndex, 0, IntPtr instancePtr, CSteamID steamIDClan, int iOfficer)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetUserRestrictions")]
STUB(uint, SteamAPI_ISteamFriends_GetUserRestrictions, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_SetRichPresence")]
STUB(bool, SteamAPI_ISteamFriends_SetRichPresence, 0, IntPtr instancePtr, char * pchKey, char * pchValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_ClearRichPresence")]
STUB(void, SteamAPI_ISteamFriends_ClearRichPresence, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendRichPresence")]
STUB(IntPtr, SteamAPI_ISteamFriends_GetFriendRichPresence, 0, IntPtr instancePtr, CSteamID steamIDFriend, char * pchKey)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount")]
STUB(int, SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount, 0, IntPtr instancePtr, CSteamID steamIDFriend)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex")]
STUB(IntPtr, SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex, 0, IntPtr instancePtr, CSteamID steamIDFriend, int iKey)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_RequestFriendRichPresence")]
STUB(void, SteamAPI_ISteamFriends_RequestFriendRichPresence, 0, IntPtr instancePtr, CSteamID steamIDFriend)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_InviteUserToGame")]
STUB(bool, SteamAPI_ISteamFriends_InviteUserToGame, 0, IntPtr instancePtr, CSteamID steamIDFriend, char * pchConnectString)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetCoplayFriendCount")]
STUB(int, SteamAPI_ISteamFriends_GetCoplayFriendCount, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetCoplayFriend")]
STUB(ulong, SteamAPI_ISteamFriends_GetCoplayFriend, 0, IntPtr instancePtr, int iCoplayFriend)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendCoplayTime")]
STUB(int, SteamAPI_ISteamFriends_GetFriendCoplayTime, 0, IntPtr instancePtr, CSteamID steamIDFriend)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendCoplayGame")]
STUB(uint, SteamAPI_ISteamFriends_GetFriendCoplayGame, 0, IntPtr instancePtr, CSteamID steamIDFriend)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_JoinClanChatRoom")]
STUB(ulong, SteamAPI_ISteamFriends_JoinClanChatRoom, 0, IntPtr instancePtr, CSteamID steamIDClan)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_LeaveClanChatRoom")]
STUB(bool, SteamAPI_ISteamFriends_LeaveClanChatRoom, 0, IntPtr instancePtr, CSteamID steamIDClan)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetClanChatMemberCount")]
STUB(int, SteamAPI_ISteamFriends_GetClanChatMemberCount, 0, IntPtr instancePtr, CSteamID steamIDClan)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetChatMemberByIndex")]
STUB(ulong, SteamAPI_ISteamFriends_GetChatMemberByIndex, 0, IntPtr instancePtr, CSteamID steamIDClan, int iUser)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_SendClanChatMessage")]
STUB(bool, SteamAPI_ISteamFriends_SendClanChatMessage, 0, IntPtr instancePtr, CSteamID steamIDClanChat, char * pchText)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetClanChatMessage")]
STUB(int, SteamAPI_ISteamFriends_GetClanChatMessage, 0, IntPtr instancePtr, CSteamID steamIDClanChat, int iMessage, IntPtr prgchText, int cchTextMax, out EChatEntryType peChatEntryType, out CSteamID psteamidChatter)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_IsClanChatAdmin")]
STUB(bool, SteamAPI_ISteamFriends_IsClanChatAdmin, 0, IntPtr instancePtr, CSteamID steamIDClanChat, CSteamID steamIDUser)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam")]
STUB(bool, SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam, 0, IntPtr instancePtr, CSteamID steamIDClanChat)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_OpenClanChatWindowInSteam")]
STUB(bool, SteamAPI_ISteamFriends_OpenClanChatWindowInSteam, 0, IntPtr instancePtr, CSteamID steamIDClanChat)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_CloseClanChatWindowInSteam")]
STUB(bool, SteamAPI_ISteamFriends_CloseClanChatWindowInSteam, 0, IntPtr instancePtr, CSteamID steamIDClanChat)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_SetListenForFriendsMessages")]
STUB(bool, SteamAPI_ISteamFriends_SetListenForFriendsMessages, 0, IntPtr instancePtr, char bInterceptEnabled)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_ReplyToFriendMessage")]
STUB(bool, SteamAPI_ISteamFriends_ReplyToFriendMessage, 0, IntPtr instancePtr, CSteamID steamIDFriend, char * pchMsgToSend)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFriendMessage")]
STUB(int, SteamAPI_ISteamFriends_GetFriendMessage, 0, IntPtr instancePtr, CSteamID steamIDFriend, int iMessageID, IntPtr pvData, int cubData, out EChatEntryType peChatEntryType)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetFollowerCount")]
STUB(ulong, SteamAPI_ISteamFriends_GetFollowerCount, 0, IntPtr instancePtr, CSteamID steamID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_IsFollowing")]
STUB(ulong, SteamAPI_ISteamFriends_IsFollowing, 0, IntPtr instancePtr, CSteamID steamID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_EnumerateFollowingList")]
STUB(ulong, SteamAPI_ISteamFriends_EnumerateFollowingList, 0, IntPtr instancePtr, uint unStartIndex)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_IsClanPublic")]
STUB(bool, SteamAPI_ISteamFriends_IsClanPublic, 0, IntPtr instancePtr, CSteamID steamIDClan)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_IsClanOfficialGameGroup")]
STUB(bool, SteamAPI_ISteamFriends_IsClanOfficialGameGroup, 0, IntPtr instancePtr, CSteamID steamIDClan)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_GetNumChatsWithUnreadPriorityMessages")]
STUB(int, SteamAPI_ISteamFriends_GetNumChatsWithUnreadPriorityMessages, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_ActivateGameOverlayRemotePlayTogetherInviteDialog")]
STUB(void, SteamAPI_ISteamFriends_ActivateGameOverlayRemotePlayTogetherInviteDialog, 0, IntPtr instancePtr, CSteamID steamIDLobby)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_RegisterProtocolInOverlayBrowser")]
STUB(bool, SteamAPI_ISteamFriends_RegisterProtocolInOverlayBrowser, 0, IntPtr instancePtr, char * pchProtocol)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialogConnectString")]
STUB(void, SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialogConnectString, 0, IntPtr instancePtr, char * pchConnectString)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_SetProduct")]
STUB(void, SteamAPI_ISteamGameServer_SetProduct, 0, IntPtr instancePtr, char * pszProduct)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_SetGameDescription")]
STUB(void, SteamAPI_ISteamGameServer_SetGameDescription, 0, IntPtr instancePtr, char * pszGameDescription)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_SetModDir")]
STUB(void, SteamAPI_ISteamGameServer_SetModDir, 0, IntPtr instancePtr, char * pszModDir)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_SetDedicatedServer")]
STUB(void, SteamAPI_ISteamGameServer_SetDedicatedServer, 0, IntPtr instancePtr, char bDedicated)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_LogOn")]
STUB(void, SteamAPI_ISteamGameServer_LogOn, 0, IntPtr instancePtr, char * pszToken)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_LogOnAnonymous")]
STUB(void, SteamAPI_ISteamGameServer_LogOnAnonymous, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_LogOff")]
STUB(void, SteamAPI_ISteamGameServer_LogOff, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_BLoggedOn")]
STUB(bool, SteamAPI_ISteamGameServer_BLoggedOn, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_BSecure")]
STUB(bool, SteamAPI_ISteamGameServer_BSecure, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_GetSteamID")]
STUB(ulong, SteamAPI_ISteamGameServer_GetSteamID, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_WasRestartRequested")]
STUB(bool, SteamAPI_ISteamGameServer_WasRestartRequested, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_SetMaxPlayerCount")]
STUB(void, SteamAPI_ISteamGameServer_SetMaxPlayerCount, 0, IntPtr instancePtr, int cPlayersMax)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_SetBotPlayerCount")]
STUB(void, SteamAPI_ISteamGameServer_SetBotPlayerCount, 0, IntPtr instancePtr, int cBotplayers)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_SetServerName")]
STUB(void, SteamAPI_ISteamGameServer_SetServerName, 0, IntPtr instancePtr, char * pszServerName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_SetMapName")]
STUB(void, SteamAPI_ISteamGameServer_SetMapName, 0, IntPtr instancePtr, char * pszMapName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_SetPasswordProtected")]
STUB(void, SteamAPI_ISteamGameServer_SetPasswordProtected, 0, IntPtr instancePtr, char bPasswordProtected)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_SetSpectatorPort")]
STUB(void, SteamAPI_ISteamGameServer_SetSpectatorPort, 0, IntPtr instancePtr, ushort unSpectatorPort)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_SetSpectatorServerName")]
STUB(void, SteamAPI_ISteamGameServer_SetSpectatorServerName, 0, IntPtr instancePtr, char * pszSpectatorServerName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_ClearAllKeyValues")]
STUB(void, SteamAPI_ISteamGameServer_ClearAllKeyValues, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_SetKeyValue")]
STUB(void, SteamAPI_ISteamGameServer_SetKeyValue, 0, IntPtr instancePtr, char * pKey, char * pValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_SetGameTags")]
STUB(void, SteamAPI_ISteamGameServer_SetGameTags, 0, IntPtr instancePtr, char * pchGameTags)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_SetGameData")]
STUB(void, SteamAPI_ISteamGameServer_SetGameData, 0, IntPtr instancePtr, char * pchGameData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_SetRegion")]
STUB(void, SteamAPI_ISteamGameServer_SetRegion, 0, IntPtr instancePtr, char * pszRegion)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_SetAdvertiseServerActive")]
STUB(void, SteamAPI_ISteamGameServer_SetAdvertiseServerActive, 0, IntPtr instancePtr, char bActive)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_GetAuthSessionTicket")]
STUB(uint, SteamAPI_ISteamGameServer_GetAuthSessionTicket, 0, IntPtr instancePtr, byte* pTicket, int cbMaxTicket, out uint pcbTicket)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_BeginAuthSession")]
STUB(EBeginAuthSessionResult, SteamAPI_ISteamGameServer_BeginAuthSession, 0, IntPtr instancePtr, byte* pAuthTicket, int cbAuthTicket, CSteamID steamID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_EndAuthSession")]
STUB(void, SteamAPI_ISteamGameServer_EndAuthSession, 0, IntPtr instancePtr, CSteamID steamID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_CancelAuthTicket")]
STUB(void, SteamAPI_ISteamGameServer_CancelAuthTicket, 0, IntPtr instancePtr, HAuthTicket hAuthTicket)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_UserHasLicenseForApp")]
STUB(EUserHasLicenseForAppResult, SteamAPI_ISteamGameServer_UserHasLicenseForApp, 2, IntPtr instancePtr, CSteamID steamID, AppId_t appID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_RequestUserGroupStatus")]
STUB(bool, SteamAPI_ISteamGameServer_RequestUserGroupStatus, 0, IntPtr instancePtr, CSteamID steamIDUser, CSteamID steamIDGroup)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_GetGameplayStats")]
STUB(void, SteamAPI_ISteamGameServer_GetGameplayStats, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_GetServerReputation")]
STUB(ulong, SteamAPI_ISteamGameServer_GetServerReputation, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_GetPublicIP")]
STUB(SteamIPAddress_t, SteamAPI_ISteamGameServer_GetPublicIP, (SteamIPAddress_t){ }, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_HandleIncomingPacket")]
STUB(bool, SteamAPI_ISteamGameServer_HandleIncomingPacket, 0, IntPtr instancePtr, byte* pData, int cbData, uint srcIP, ushort srcPort)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_GetNextOutgoingPacket")]
STUB(int, SteamAPI_ISteamGameServer_GetNextOutgoingPacket, 0, IntPtr instancePtr, byte* pOut, int cbMaxOut, out uint pNetAdr, out ushort pPort)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_AssociateWithClan")]
STUB(ulong, SteamAPI_ISteamGameServer_AssociateWithClan, 0, IntPtr instancePtr, CSteamID steamIDClan)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility")]
STUB(ulong, SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility, 0, IntPtr instancePtr, CSteamID steamIDNewPlayer)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate_DEPRECATED")]
STUB(bool, SteamAPI_ISteamGameServer_SendUserConnectAndAuthenticate_DEPRECATED, 0, IntPtr instancePtr, uint unIPClient, byte* pvAuthBlob, uint cubAuthBlobSize, out CSteamID pSteamIDUser)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection")]
STUB(ulong, SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_SendUserDisconnect_DEPRECATED")]
STUB(void, SteamAPI_ISteamGameServer_SendUserDisconnect_DEPRECATED, 0, IntPtr instancePtr, CSteamID steamIDUser)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServer_BUpdateUserData")]
STUB(bool, SteamAPI_ISteamGameServer_BUpdateUserData, 0, IntPtr instancePtr, CSteamID steamIDUser, char * pchPlayerName, uint uScore)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServerStats_RequestUserStats")]
STUB(ulong, SteamAPI_ISteamGameServerStats_RequestUserStats, 0, IntPtr instancePtr, CSteamID steamIDUser)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServerStats_GetUserStatInt32")]
STUB(bool, SteamAPI_ISteamGameServerStats_GetUserStatInt32, 0, IntPtr instancePtr, CSteamID steamIDUser, char * pchName, out int pData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServerStats_GetUserStatFloat")]
STUB(bool, SteamAPI_ISteamGameServerStats_GetUserStatFloat, 0, IntPtr instancePtr, CSteamID steamIDUser, char * pchName, out float pData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServerStats_GetUserAchievement")]
STUB(bool, SteamAPI_ISteamGameServerStats_GetUserAchievement, 0, IntPtr instancePtr, CSteamID steamIDUser, char * pchName, out bool pbAchieved)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServerStats_SetUserStatInt32")]
STUB(bool, SteamAPI_ISteamGameServerStats_SetUserStatInt32, 0, IntPtr instancePtr, CSteamID steamIDUser, char * pchName, int nData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServerStats_SetUserStatFloat")]
STUB(bool, SteamAPI_ISteamGameServerStats_SetUserStatFloat, 0, IntPtr instancePtr, CSteamID steamIDUser, char * pchName, float fData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServerStats_UpdateUserAvgRateStat")]
STUB(bool, SteamAPI_ISteamGameServerStats_UpdateUserAvgRateStat, 0, IntPtr instancePtr, CSteamID steamIDUser, char * pchName, float flCountThisSession, double dSessionLength)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServerStats_SetUserAchievement")]
STUB(bool, SteamAPI_ISteamGameServerStats_SetUserAchievement, 0, IntPtr instancePtr, CSteamID steamIDUser, char * pchName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServerStats_ClearUserAchievement")]
STUB(bool, SteamAPI_ISteamGameServerStats_ClearUserAchievement, 0, IntPtr instancePtr, CSteamID steamIDUser, char * pchName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameServerStats_StoreUserStats")]
STUB(ulong, SteamAPI_ISteamGameServerStats_StoreUserStats, 0, IntPtr instancePtr, CSteamID steamIDUser)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_Init")]
STUB(bool, SteamAPI_ISteamHTMLSurface_Init, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_Shutdown")]
STUB(bool, SteamAPI_ISteamHTMLSurface_Shutdown, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_CreateBrowser")]
STUB(ulong, SteamAPI_ISteamHTMLSurface_CreateBrowser, 0, IntPtr instancePtr, char * pchUserAgent, char * pchUserCSS)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_RemoveBrowser")]
STUB(void, SteamAPI_ISteamHTMLSurface_RemoveBrowser, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_LoadURL")]
STUB(void, SteamAPI_ISteamHTMLSurface_LoadURL, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, char * pchURL, char * pchPostData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_SetSize")]
STUB(void, SteamAPI_ISteamHTMLSurface_SetSize, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, uint unWidth, uint unHeight)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_StopLoad")]
STUB(void, SteamAPI_ISteamHTMLSurface_StopLoad, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_Reload")]
STUB(void, SteamAPI_ISteamHTMLSurface_Reload, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_GoBack")]
STUB(void, SteamAPI_ISteamHTMLSurface_GoBack, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_GoForward")]
STUB(void, SteamAPI_ISteamHTMLSurface_GoForward, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_AddHeader")]
STUB(void, SteamAPI_ISteamHTMLSurface_AddHeader, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, char * pchKey, char * pchValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_ExecuteJavascript")]
STUB(void, SteamAPI_ISteamHTMLSurface_ExecuteJavascript, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, char * pchScript)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_MouseUp")]
STUB(void, SteamAPI_ISteamHTMLSurface_MouseUp, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_MouseDown")]
STUB(void, SteamAPI_ISteamHTMLSurface_MouseDown, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_MouseDoubleClick")]
STUB(void, SteamAPI_ISteamHTMLSurface_MouseDoubleClick, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_MouseMove")]
STUB(void, SteamAPI_ISteamHTMLSurface_MouseMove, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, int x, int y)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_MouseWheel")]
STUB(void, SteamAPI_ISteamHTMLSurface_MouseWheel, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, int nDelta)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_KeyDown")]
STUB(void, SteamAPI_ISteamHTMLSurface_KeyDown, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, uint nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers, char bIsSystemKey)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_KeyUp")]
STUB(void, SteamAPI_ISteamHTMLSurface_KeyUp, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, uint nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_KeyChar")]
STUB(void, SteamAPI_ISteamHTMLSurface_KeyChar, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, uint cUnicodeChar, EHTMLKeyModifiers eHTMLKeyModifiers)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_SetHorizontalScroll")]
STUB(void, SteamAPI_ISteamHTMLSurface_SetHorizontalScroll, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, uint nAbsolutePixelScroll)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_SetVerticalScroll")]
STUB(void, SteamAPI_ISteamHTMLSurface_SetVerticalScroll, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, uint nAbsolutePixelScroll)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_SetKeyFocus")]
STUB(void, SteamAPI_ISteamHTMLSurface_SetKeyFocus, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, char bHasKeyFocus)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_ViewSource")]
STUB(void, SteamAPI_ISteamHTMLSurface_ViewSource, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_CopyToClipboard")]
STUB(void, SteamAPI_ISteamHTMLSurface_CopyToClipboard, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_PasteFromClipboard")]
STUB(void, SteamAPI_ISteamHTMLSurface_PasteFromClipboard, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_Find")]
STUB(void, SteamAPI_ISteamHTMLSurface_Find, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, char * pchSearchStr, char bCurrentlyInFind, char bReverse)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_StopFind")]
STUB(void, SteamAPI_ISteamHTMLSurface_StopFind, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_GetLinkAtPosition")]
STUB(void, SteamAPI_ISteamHTMLSurface_GetLinkAtPosition, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, int x, int y)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_SetCookie")]
STUB(void, SteamAPI_ISteamHTMLSurface_SetCookie, 0, IntPtr instancePtr, char * pchHostname, char * pchKey, char * pchValue, char * pchPath, uint nExpires, char bSecure, char bHTTPOnly)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_SetPageScaleFactor")]
STUB(void, SteamAPI_ISteamHTMLSurface_SetPageScaleFactor, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_SetBackgroundMode")]
STUB(void, SteamAPI_ISteamHTMLSurface_SetBackgroundMode, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, char bBackgroundMode)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_SetDPIScalingFactor")]
STUB(void, SteamAPI_ISteamHTMLSurface_SetDPIScalingFactor, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, float flDPIScaling)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_OpenDeveloperTools")]
STUB(void, SteamAPI_ISteamHTMLSurface_OpenDeveloperTools, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_AllowStartRequest")]
STUB(void, SteamAPI_ISteamHTMLSurface_AllowStartRequest, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, char bAllowed)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_JSDialogResponse")]
STUB(void, SteamAPI_ISteamHTMLSurface_JSDialogResponse, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, char bResult)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTMLSurface_FileLoadDialogResponse")]
STUB(void, SteamAPI_ISteamHTMLSurface_FileLoadDialogResponse, 0, IntPtr instancePtr, HHTMLBrowser unBrowserHandle, IntPtr pchSelectedFiles)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_CreateHTTPRequest")]
STUB(uint, SteamAPI_ISteamHTTP_CreateHTTPRequest, 0, IntPtr instancePtr, EHTTPMethod eHTTPRequestMethod, char * pchAbsoluteURL)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_SetHTTPRequestContextValue")]
STUB(bool, SteamAPI_ISteamHTTP_SetHTTPRequestContextValue, 0, IntPtr instancePtr, HTTPRequestHandle hRequest, ulong ulContextValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout")]
STUB(bool, SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout, 0, IntPtr instancePtr, HTTPRequestHandle hRequest, uint unTimeoutSeconds)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue")]
STUB(bool, SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue, 0, IntPtr instancePtr, HTTPRequestHandle hRequest, char * pchHeaderName, char * pchHeaderValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter")]
STUB(bool, SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter, 0, IntPtr instancePtr, HTTPRequestHandle hRequest, char * pchParamName, char * pchParamValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_SendHTTPRequest")]
STUB(bool, SteamAPI_ISteamHTTP_SendHTTPRequest, 0, IntPtr instancePtr, HTTPRequestHandle hRequest, out SteamAPICall_t pCallHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_SendHTTPRequestAndStreamResponse")]
STUB(bool, SteamAPI_ISteamHTTP_SendHTTPRequestAndStreamResponse, 0, IntPtr instancePtr, HTTPRequestHandle hRequest, out SteamAPICall_t pCallHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_DeferHTTPRequest")]
STUB(bool, SteamAPI_ISteamHTTP_DeferHTTPRequest, 0, IntPtr instancePtr, HTTPRequestHandle hRequest)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_PrioritizeHTTPRequest")]
STUB(bool, SteamAPI_ISteamHTTP_PrioritizeHTTPRequest, 0, IntPtr instancePtr, HTTPRequestHandle hRequest)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_GetHTTPResponseHeaderSize")]
STUB(bool, SteamAPI_ISteamHTTP_GetHTTPResponseHeaderSize, 0, IntPtr instancePtr, HTTPRequestHandle hRequest, char * pchHeaderName, out uint unResponseHeaderSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_GetHTTPResponseHeaderValue")]
STUB(bool, SteamAPI_ISteamHTTP_GetHTTPResponseHeaderValue, 0, IntPtr instancePtr, HTTPRequestHandle hRequest, char * pchHeaderName, byte* pHeaderValueBuffer, uint unBufferSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_GetHTTPResponseBodySize")]
STUB(bool, SteamAPI_ISteamHTTP_GetHTTPResponseBodySize, 0, IntPtr instancePtr, HTTPRequestHandle hRequest, out uint unBodySize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_GetHTTPResponseBodyData")]
STUB(bool, SteamAPI_ISteamHTTP_GetHTTPResponseBodyData, 0, IntPtr instancePtr, HTTPRequestHandle hRequest, byte* pBodyDataBuffer, uint unBufferSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_GetHTTPStreamingResponseBodyData")]
STUB(bool, SteamAPI_ISteamHTTP_GetHTTPStreamingResponseBodyData, 0, IntPtr instancePtr, HTTPRequestHandle hRequest, uint cOffset, byte* pBodyDataBuffer, uint unBufferSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_ReleaseHTTPRequest")]
STUB(bool, SteamAPI_ISteamHTTP_ReleaseHTTPRequest, 0, IntPtr instancePtr, HTTPRequestHandle hRequest)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_GetHTTPDownloadProgressPct")]
STUB(bool, SteamAPI_ISteamHTTP_GetHTTPDownloadProgressPct, 0, IntPtr instancePtr, HTTPRequestHandle hRequest, out float pflPercentOut)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_SetHTTPRequestRawPostBody")]
STUB(bool, SteamAPI_ISteamHTTP_SetHTTPRequestRawPostBody, 0, IntPtr instancePtr, HTTPRequestHandle hRequest, char * pchContentType, byte* pubBody, uint unBodyLen)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_CreateCookieContainer")]
STUB(uint, SteamAPI_ISteamHTTP_CreateCookieContainer, 0, IntPtr instancePtr, char bAllowResponsesToModify)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_ReleaseCookieContainer")]
STUB(bool, SteamAPI_ISteamHTTP_ReleaseCookieContainer, 0, IntPtr instancePtr, HTTPCookieContainerHandle hCookieContainer)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_SetCookie")]
STUB(bool, SteamAPI_ISteamHTTP_SetCookie, 0, IntPtr instancePtr, HTTPCookieContainerHandle hCookieContainer, char * pchHost, char * pchUrl, char * pchCookie)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer")]
STUB(bool, SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer, 0, IntPtr instancePtr, HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo")]
STUB(bool, SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo, 0, IntPtr instancePtr, HTTPRequestHandle hRequest, char * pchUserAgentInfo)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate")]
STUB(bool, SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate, 0, IntPtr instancePtr, HTTPRequestHandle hRequest, char bRequireVerifiedCertificate)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS")]
STUB(bool, SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS, 0, IntPtr instancePtr, HTTPRequestHandle hRequest, uint unMilliseconds)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamHTTP_GetHTTPRequestWasTimedOut")]
STUB(bool, SteamAPI_ISteamHTTP_GetHTTPRequestWasTimedOut, 0, IntPtr instancePtr, HTTPRequestHandle hRequest, out bool pbWasTimedOut)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_Init")]
STUB(bool, SteamAPI_ISteamInput_Init, 0, IntPtr instancePtr, char bExplicitlyCallRunFrame)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_Shutdown")]
STUB(bool, SteamAPI_ISteamInput_Shutdown, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_SetInputActionManifestFilePath")]
STUB(bool, SteamAPI_ISteamInput_SetInputActionManifestFilePath, 0, IntPtr instancePtr, char * pchInputActionManifestAbsolutePath)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_RunFrame")]
STUB(void, SteamAPI_ISteamInput_RunFrame, 0, IntPtr instancePtr, char bReservedValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_BWaitForData")]
STUB(bool, SteamAPI_ISteamInput_BWaitForData, 0, IntPtr instancePtr, char bWaitForever, uint unTimeout)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_BNewDataAvailable")]
STUB(bool, SteamAPI_ISteamInput_BNewDataAvailable, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetConnectedControllers")]
STUB(int, SteamAPI_ISteamInput_GetConnectedControllers, 0, IntPtr instancePtr, InputHandle_t* handlesOut)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_EnableDeviceCallbacks")]
STUB(void, SteamAPI_ISteamInput_EnableDeviceCallbacks, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_EnableActionEventCallbacks")]
STUB(void, SteamAPI_ISteamInput_EnableActionEventCallbacks, 0, IntPtr instancePtr, SteamInputActionEventCallbackPointer pCallback)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetActionSetHandle")]
STUB(ulong, SteamAPI_ISteamInput_GetActionSetHandle, 0, IntPtr instancePtr, char * pszActionSetName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_ActivateActionSet")]
STUB(void, SteamAPI_ISteamInput_ActivateActionSet, 0, IntPtr instancePtr, InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetCurrentActionSet")]
STUB(ulong, SteamAPI_ISteamInput_GetCurrentActionSet, 0, IntPtr instancePtr, InputHandle_t inputHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_ActivateActionSetLayer")]
STUB(void, SteamAPI_ISteamInput_ActivateActionSetLayer, 0, IntPtr instancePtr, InputHandle_t inputHandle, InputActionSetHandle_t actionSetLayerHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_DeactivateActionSetLayer")]
STUB(void, SteamAPI_ISteamInput_DeactivateActionSetLayer, 0, IntPtr instancePtr, InputHandle_t inputHandle, InputActionSetHandle_t actionSetLayerHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_DeactivateAllActionSetLayers")]
STUB(void, SteamAPI_ISteamInput_DeactivateAllActionSetLayers, 0, IntPtr instancePtr, InputHandle_t inputHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetActiveActionSetLayers")]
STUB(int, SteamAPI_ISteamInput_GetActiveActionSetLayers, 0, IntPtr instancePtr, InputHandle_t inputHandle, InputActionSetHandle_t* handlesOut)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetDigitalActionHandle")]
STUB(ulong, SteamAPI_ISteamInput_GetDigitalActionHandle, 0, IntPtr instancePtr, char * pszActionName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetDigitalActionData")]
STUB(InputDigitalActionData_t, SteamAPI_ISteamInput_GetDigitalActionData, (InputDigitalActionData_t) { }, IntPtr instancePtr, InputHandle_t inputHandle, InputDigitalActionHandle_t digitalActionHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetDigitalActionOrigins")]
STUB(int, SteamAPI_ISteamInput_GetDigitalActionOrigins, 0, IntPtr instancePtr, InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle, InputDigitalActionHandle_t digitalActionHandle, EInputActionOrigin* originsOut)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetStringForDigitalActionName")]
STUB(IntPtr, SteamAPI_ISteamInput_GetStringForDigitalActionName, 0, IntPtr instancePtr, InputDigitalActionHandle_t eActionHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetAnalogActionHandle")]
STUB(ulong, SteamAPI_ISteamInput_GetAnalogActionHandle, 0, IntPtr instancePtr, char * pszActionName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetAnalogActionData")]
STUB(InputAnalogActionData_t, SteamAPI_ISteamInput_GetAnalogActionData, (InputAnalogActionData_t){ }, IntPtr instancePtr, InputHandle_t inputHandle, InputAnalogActionHandle_t analogActionHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetAnalogActionOrigins")]
STUB(int, SteamAPI_ISteamInput_GetAnalogActionOrigins, 0, IntPtr instancePtr, InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle, InputAnalogActionHandle_t analogActionHandle, EInputActionOrigin* originsOut)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetGlyphPNGForActionOrigin")]
STUB(IntPtr, SteamAPI_ISteamInput_GetGlyphPNGForActionOrigin, 0, IntPtr instancePtr, EInputActionOrigin eOrigin, ESteamInputGlyphSize eSize, uint unFlags)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetGlyphSVGForActionOrigin")]
STUB(IntPtr, SteamAPI_ISteamInput_GetGlyphSVGForActionOrigin, 0, IntPtr instancePtr, EInputActionOrigin eOrigin, uint unFlags)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetGlyphForActionOrigin_Legacy")]
STUB(IntPtr, SteamAPI_ISteamInput_GetGlyphForActionOrigin_Legacy, 0, IntPtr instancePtr, EInputActionOrigin eOrigin)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetStringForActionOrigin")]
STUB(IntPtr, SteamAPI_ISteamInput_GetStringForActionOrigin, 0, IntPtr instancePtr, EInputActionOrigin eOrigin)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetStringForAnalogActionName")]
STUB(IntPtr, SteamAPI_ISteamInput_GetStringForAnalogActionName, 0, IntPtr instancePtr, InputAnalogActionHandle_t eActionHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_StopAnalogActionMomentum")]
STUB(void, SteamAPI_ISteamInput_StopAnalogActionMomentum, 0, IntPtr instancePtr, InputHandle_t inputHandle, InputAnalogActionHandle_t eAction)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetMotionData")]
STUB(InputMotionData_t, SteamAPI_ISteamInput_GetMotionData, (InputMotionData_t) { }, IntPtr instancePtr, InputHandle_t inputHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_TriggerVibration")]
STUB(void, SteamAPI_ISteamInput_TriggerVibration, 0, IntPtr instancePtr, InputHandle_t inputHandle, ushort usLeftSpeed, ushort usRightSpeed)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_TriggerVibrationExtended")]
STUB(void, SteamAPI_ISteamInput_TriggerVibrationExtended, 0, IntPtr instancePtr, InputHandle_t inputHandle, ushort usLeftSpeed, ushort usRightSpeed, ushort usLeftTriggerSpeed, ushort usRightTriggerSpeed)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_TriggerSimpleHapticEvent")]
STUB(void, SteamAPI_ISteamInput_TriggerSimpleHapticEvent, 0, IntPtr instancePtr, InputHandle_t inputHandle, EControllerHapticLocation eHapticLocation, byte nIntensity, char nGainDB, byte nOtherIntensity, char nOtherGainDB)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_SetLEDColor")]
STUB(void, SteamAPI_ISteamInput_SetLEDColor, 0, IntPtr instancePtr, InputHandle_t inputHandle, byte nColorR, byte nColorG, byte nColorB, uint nFlags)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_Legacy_TriggerHapticPulse")]
STUB(void, SteamAPI_ISteamInput_Legacy_TriggerHapticPulse, 0, IntPtr instancePtr, InputHandle_t inputHandle, ESteamControllerPad eTargetPad, ushort usDurationMicroSec)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_Legacy_TriggerRepeatedHapticPulse")]
STUB(void, SteamAPI_ISteamInput_Legacy_TriggerRepeatedHapticPulse, 0, IntPtr instancePtr, InputHandle_t inputHandle, ESteamControllerPad eTargetPad, ushort usDurationMicroSec, ushort usOffMicroSec, ushort unRepeat, uint nFlags)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_ShowBindingPanel")]
STUB(bool, SteamAPI_ISteamInput_ShowBindingPanel, 0, IntPtr instancePtr, InputHandle_t inputHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetInputTypeForHandle")]
STUB(ESteamInputType, SteamAPI_ISteamInput_GetInputTypeForHandle, 0, IntPtr instancePtr, InputHandle_t inputHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetControllerForGamepadIndex")]
STUB(ulong, SteamAPI_ISteamInput_GetControllerForGamepadIndex, 0, IntPtr instancePtr, int nIndex)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetGamepadIndexForController")]
STUB(int, SteamAPI_ISteamInput_GetGamepadIndexForController, 0, IntPtr instancePtr, InputHandle_t ulinputHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetStringForXboxOrigin")]
STUB(IntPtr, SteamAPI_ISteamInput_GetStringForXboxOrigin, 0, IntPtr instancePtr, EXboxOrigin eOrigin)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetGlyphForXboxOrigin")]
STUB(IntPtr, SteamAPI_ISteamInput_GetGlyphForXboxOrigin, 0, IntPtr instancePtr, EXboxOrigin eOrigin)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetActionOriginFromXboxOrigin")]
STUB(EInputActionOrigin, SteamAPI_ISteamInput_GetActionOriginFromXboxOrigin, 0, IntPtr instancePtr, InputHandle_t inputHandle, EXboxOrigin eOrigin)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_TranslateActionOrigin")]
STUB(EInputActionOrigin, SteamAPI_ISteamInput_TranslateActionOrigin, 0, IntPtr instancePtr, ESteamInputType eDestinationInputType, EInputActionOrigin eSourceOrigin)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetDeviceBindingRevision")]
STUB(bool, SteamAPI_ISteamInput_GetDeviceBindingRevision, 0, IntPtr instancePtr, InputHandle_t inputHandle, out int pMajor, out int pMinor)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetRemotePlaySessionID")]
STUB(uint, SteamAPI_ISteamInput_GetRemotePlaySessionID, 0, IntPtr instancePtr, InputHandle_t inputHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInput_GetSessionInputConfigurationSettings")]
STUB(ushort, SteamAPI_ISteamInput_GetSessionInputConfigurationSettings, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_GetResultStatus")]
STUB(EResult, SteamAPI_ISteamInventory_GetResultStatus, 0, IntPtr instancePtr, SteamInventoryResult_t resultHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_GetResultItems")]
STUB(bool, SteamAPI_ISteamInventory_GetResultItems, 0, IntPtr instancePtr, SteamInventoryResult_t resultHandle, SteamItemDetails_t* pOutItemsArray, ref uint punOutItemsArraySize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_GetResultItemProperty")]
STUB(bool, SteamAPI_ISteamInventory_GetResultItemProperty, 0, IntPtr instancePtr, SteamInventoryResult_t resultHandle, uint unItemIndex, char * pchPropertyName, IntPtr pchValueBuffer, ref uint punValueBufferSizeOut)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_GetResultTimestamp")]
STUB(uint, SteamAPI_ISteamInventory_GetResultTimestamp, 0, IntPtr instancePtr, SteamInventoryResult_t resultHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_CheckResultSteamID")]
STUB(bool, SteamAPI_ISteamInventory_CheckResultSteamID, 0, IntPtr instancePtr, SteamInventoryResult_t resultHandle, CSteamID steamIDExpected)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_DestroyResult")]
STUB(void, SteamAPI_ISteamInventory_DestroyResult, 0, IntPtr instancePtr, SteamInventoryResult_t resultHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_GetAllItems")]
STUB(bool, SteamAPI_ISteamInventory_GetAllItems, 0, IntPtr instancePtr, out SteamInventoryResult_t pResultHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_GetItemsByID")]
STUB(bool, SteamAPI_ISteamInventory_GetItemsByID, 0, IntPtr instancePtr, out SteamInventoryResult_t pResultHandle, SteamItemInstanceID_t* pInstanceIDs, uint unCountInstanceIDs)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_SerializeResult")]
STUB(bool, SteamAPI_ISteamInventory_SerializeResult, 0, IntPtr instancePtr, SteamInventoryResult_t resultHandle, byte* pOutBuffer, out uint punOutBufferSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_DeserializeResult")]
STUB(bool, SteamAPI_ISteamInventory_DeserializeResult, 0, IntPtr instancePtr, out SteamInventoryResult_t pOutResultHandle, byte* pBuffer, uint unBufferSize, char bRESERVED_MUST_BE_FALSE)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_GenerateItems")]
STUB(bool, SteamAPI_ISteamInventory_GenerateItems, 0, IntPtr instancePtr, out SteamInventoryResult_t pResultHandle, SteamItemDef_t* pArrayItemDefs, uint* punArrayQuantity, uint unArrayLength)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_GrantPromoItems")]
STUB(bool, SteamAPI_ISteamInventory_GrantPromoItems, 0, IntPtr instancePtr, out SteamInventoryResult_t pResultHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_AddPromoItem")]
STUB(bool, SteamAPI_ISteamInventory_AddPromoItem, 0, IntPtr instancePtr, out SteamInventoryResult_t pResultHandle, SteamItemDef_t itemDef)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_AddPromoItems")]
STUB(bool, SteamAPI_ISteamInventory_AddPromoItems, 0, IntPtr instancePtr, out SteamInventoryResult_t pResultHandle, SteamItemDef_t* pArrayItemDefs, uint unArrayLength)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_ConsumeItem")]
STUB(bool, SteamAPI_ISteamInventory_ConsumeItem, 0, IntPtr instancePtr, out SteamInventoryResult_t pResultHandle, SteamItemInstanceID_t itemConsume, uint unQuantity)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_ExchangeItems")]
STUB(bool, SteamAPI_ISteamInventory_ExchangeItems, 0, IntPtr instancePtr, out SteamInventoryResult_t pResultHandle, SteamItemDef_t* pArrayGenerate, uint* punArrayGenerateQuantity, uint unArrayGenerateLength, SteamItemInstanceID_t* pArrayDestroy, uint* punArrayDestroyQuantity, uint unArrayDestroyLength)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_TransferItemQuantity")]
STUB(bool, SteamAPI_ISteamInventory_TransferItemQuantity, 0, IntPtr instancePtr, out SteamInventoryResult_t pResultHandle, SteamItemInstanceID_t itemIdSource, uint unQuantity, SteamItemInstanceID_t itemIdDest)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_SendItemDropHeartbeat")]
STUB(void, SteamAPI_ISteamInventory_SendItemDropHeartbeat, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_TriggerItemDrop")]
STUB(bool, SteamAPI_ISteamInventory_TriggerItemDrop, 0, IntPtr instancePtr, out SteamInventoryResult_t pResultHandle, SteamItemDef_t dropListDefinition)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_TradeItems")]
STUB(bool, SteamAPI_ISteamInventory_TradeItems, 0, IntPtr instancePtr, out SteamInventoryResult_t pResultHandle, CSteamID steamIDTradePartner, SteamItemInstanceID_t* pArrayGive, uint* pArrayGiveQuantity, uint nArrayGiveLength, SteamItemInstanceID_t* pArrayGet, uint* pArrayGetQuantity, uint nArrayGetLength)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_LoadItemDefinitions")]
STUB(bool, SteamAPI_ISteamInventory_LoadItemDefinitions, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_GetItemDefinitionIDs")]
STUB(bool, SteamAPI_ISteamInventory_GetItemDefinitionIDs, 0, IntPtr instancePtr, SteamItemDef_t* pItemDefIDs, ref uint punItemDefIDsArraySize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_GetItemDefinitionProperty")]
STUB(bool, SteamAPI_ISteamInventory_GetItemDefinitionProperty, 0, IntPtr instancePtr, SteamItemDef_t iDefinition, char * pchPropertyName, IntPtr pchValueBuffer, ref uint punValueBufferSizeOut)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_RequestEligiblePromoItemDefinitionsIDs")]
STUB(ulong, SteamAPI_ISteamInventory_RequestEligiblePromoItemDefinitionsIDs, 0, IntPtr instancePtr, CSteamID steamID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_GetEligiblePromoItemDefinitionIDs")]
STUB(bool, SteamAPI_ISteamInventory_GetEligiblePromoItemDefinitionIDs, 0, IntPtr instancePtr, CSteamID steamID, SteamItemDef_t* pItemDefIDs, ref uint punItemDefIDsArraySize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_StartPurchase")]
STUB(ulong, SteamAPI_ISteamInventory_StartPurchase, 0, IntPtr instancePtr, SteamItemDef_t* pArrayItemDefs, uint* punArrayQuantity, uint unArrayLength)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_RequestPrices")]
STUB(ulong, SteamAPI_ISteamInventory_RequestPrices, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_GetNumItemsWithPrices")]
STUB(uint, SteamAPI_ISteamInventory_GetNumItemsWithPrices, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_GetItemsWithPrices")]
STUB(bool, SteamAPI_ISteamInventory_GetItemsWithPrices, 0, IntPtr instancePtr, SteamItemDef_t* pArrayItemDefs, ulong* pCurrentPrices, ulong* pBasePrices, uint unArrayLength)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_GetItemPrice")]
STUB(bool, SteamAPI_ISteamInventory_GetItemPrice, 0, IntPtr instancePtr, SteamItemDef_t iDefinition, out ulong pCurrentPrice, out ulong pBasePrice)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_StartUpdateProperties")]
STUB(ulong, SteamAPI_ISteamInventory_StartUpdateProperties, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_RemoveProperty")]
STUB(bool, SteamAPI_ISteamInventory_RemoveProperty, 0, IntPtr instancePtr, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, char * pchPropertyName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_SetPropertyString")]
STUB(bool, SteamAPI_ISteamInventory_SetPropertyString, 0, IntPtr instancePtr, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, char * pchPropertyName, char * pchPropertyValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_SetPropertyBool")]
STUB(bool, SteamAPI_ISteamInventory_SetPropertyBool, 0, IntPtr instancePtr, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, char * pchPropertyName, char bValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_SetPropertyInt64")]
STUB(bool, SteamAPI_ISteamInventory_SetPropertyInt64, 0, IntPtr instancePtr, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, char * pchPropertyName, long nValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_SetPropertyFloat")]
STUB(bool, SteamAPI_ISteamInventory_SetPropertyFloat, 0, IntPtr instancePtr, SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, char * pchPropertyName, float flValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_SubmitUpdateProperties")]
STUB(bool, SteamAPI_ISteamInventory_SubmitUpdateProperties, 0, IntPtr instancePtr, SteamInventoryUpdateHandle_t handle, out SteamInventoryResult_t pResultHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamInventory_InspectItem")]
STUB(bool, SteamAPI_ISteamInventory_InspectItem, 0, IntPtr instancePtr, out SteamInventoryResult_t pResultHandle, char * pchItemToken)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_GetFavoriteGameCount")]
STUB(int, SteamAPI_ISteamMatchmaking_GetFavoriteGameCount, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_GetFavoriteGame")]
STUB(bool, SteamAPI_ISteamMatchmaking_GetFavoriteGame, 0, IntPtr instancePtr, int iGame, out AppId_t pnAppID, out uint pnIP, out ushort pnConnPort, out ushort pnQueryPort, out uint punFlags, out uint pRTime32LastPlayedOnServer)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_AddFavoriteGame")]
STUB(int, SteamAPI_ISteamMatchmaking_AddFavoriteGame, 0, IntPtr instancePtr, AppId_t nAppID, uint nIP, ushort nConnPort, ushort nQueryPort, uint unFlags, uint rTime32LastPlayedOnServer)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_RemoveFavoriteGame")]
STUB(bool, SteamAPI_ISteamMatchmaking_RemoveFavoriteGame, 0, IntPtr instancePtr, AppId_t nAppID, uint nIP, ushort nConnPort, ushort nQueryPort, uint unFlags)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_RequestLobbyList")]
STUB(ulong, SteamAPI_ISteamMatchmaking_RequestLobbyList, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_AddRequestLobbyListStringFilter")]
STUB(void, SteamAPI_ISteamMatchmaking_AddRequestLobbyListStringFilter, 0, IntPtr instancePtr, char * pchKeyToMatch, char * pchValueToMatch, ELobbyComparison eComparisonType)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_AddRequestLobbyListNumericalFilter")]
STUB(void, SteamAPI_ISteamMatchmaking_AddRequestLobbyListNumericalFilter, 0, IntPtr instancePtr, char * pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter")]
STUB(void, SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter, 0, IntPtr instancePtr, char * pchKeyToMatch, int nValueToBeCloseTo)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable")]
STUB(void, SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable, 0, IntPtr instancePtr, int nSlotsAvailable)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_AddRequestLobbyListDistanceFilter")]
STUB(void, SteamAPI_ISteamMatchmaking_AddRequestLobbyListDistanceFilter, 0, IntPtr instancePtr, ELobbyDistanceFilter eLobbyDistanceFilter)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter")]
STUB(void, SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter, 0, IntPtr instancePtr, int cMaxResults)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter")]
STUB(void, SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter, 0, IntPtr instancePtr, CSteamID steamIDLobby)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_GetLobbyByIndex")]
STUB(ulong, SteamAPI_ISteamMatchmaking_GetLobbyByIndex, 0, IntPtr instancePtr, int iLobby)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_CreateLobby")]
STUB(ulong, SteamAPI_ISteamMatchmaking_CreateLobby, 0, IntPtr instancePtr, ELobbyType eLobbyType, int cMaxMembers)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_JoinLobby")]
STUB(ulong, SteamAPI_ISteamMatchmaking_JoinLobby, 0, IntPtr instancePtr, CSteamID steamIDLobby)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_LeaveLobby")]
STUB(void, SteamAPI_ISteamMatchmaking_LeaveLobby, 0, IntPtr instancePtr, CSteamID steamIDLobby)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_InviteUserToLobby")]
STUB(bool, SteamAPI_ISteamMatchmaking_InviteUserToLobby, 0, IntPtr instancePtr, CSteamID steamIDLobby, CSteamID steamIDInvitee)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_GetNumLobbyMembers")]
STUB(int, SteamAPI_ISteamMatchmaking_GetNumLobbyMembers, 0, IntPtr instancePtr, CSteamID steamIDLobby)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex")]
STUB(ulong, SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex, 0, IntPtr instancePtr, CSteamID steamIDLobby, int iMember)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_GetLobbyData")]
STUB(IntPtr, SteamAPI_ISteamMatchmaking_GetLobbyData, 0, IntPtr instancePtr, CSteamID steamIDLobby, char * pchKey)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_SetLobbyData")]
STUB(bool, SteamAPI_ISteamMatchmaking_SetLobbyData, 0, IntPtr instancePtr, CSteamID steamIDLobby, char * pchKey, char * pchValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_GetLobbyDataCount")]
STUB(int, SteamAPI_ISteamMatchmaking_GetLobbyDataCount, 0, IntPtr instancePtr, CSteamID steamIDLobby)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_GetLobbyDataByIndex")]
STUB(bool, SteamAPI_ISteamMatchmaking_GetLobbyDataByIndex, 0, IntPtr instancePtr, CSteamID steamIDLobby, int iLobbyData, IntPtr pchKey, int cchKeyBufferSize, IntPtr pchValue, int cchValueBufferSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_DeleteLobbyData")]
STUB(bool, SteamAPI_ISteamMatchmaking_DeleteLobbyData, 0, IntPtr instancePtr, CSteamID steamIDLobby, char * pchKey)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_GetLobbyMemberData")]
STUB(IntPtr, SteamAPI_ISteamMatchmaking_GetLobbyMemberData, 0, IntPtr instancePtr, CSteamID steamIDLobby, CSteamID steamIDUser, char * pchKey)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_SetLobbyMemberData")]
STUB(void, SteamAPI_ISteamMatchmaking_SetLobbyMemberData, 0, IntPtr instancePtr, CSteamID steamIDLobby, char * pchKey, char * pchValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_SendLobbyChatMsg")]
STUB(bool, SteamAPI_ISteamMatchmaking_SendLobbyChatMsg, 0, IntPtr instancePtr, CSteamID steamIDLobby, byte* pvMsgBody, int cubMsgBody)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_GetLobbyChatEntry")]
STUB(int, SteamAPI_ISteamMatchmaking_GetLobbyChatEntry, 0, IntPtr instancePtr, CSteamID steamIDLobby, int iChatID, out CSteamID pSteamIDUser, byte* pvData, int cubData, out EChatEntryType peChatEntryType)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_RequestLobbyData")]
STUB(bool, SteamAPI_ISteamMatchmaking_RequestLobbyData, 0, IntPtr instancePtr, CSteamID steamIDLobby)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_SetLobbyGameServer")]
STUB(void, SteamAPI_ISteamMatchmaking_SetLobbyGameServer, 0, IntPtr instancePtr, CSteamID steamIDLobby, uint unGameServerIP, ushort unGameServerPort, CSteamID steamIDGameServer)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_GetLobbyGameServer")]
STUB(bool, SteamAPI_ISteamMatchmaking_GetLobbyGameServer, 0, IntPtr instancePtr, CSteamID steamIDLobby, out uint punGameServerIP, out ushort punGameServerPort, out CSteamID psteamIDGameServer)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit")]
STUB(bool, SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit, 0, IntPtr instancePtr, CSteamID steamIDLobby, int cMaxMembers)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit")]
STUB(int, SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit, 0, IntPtr instancePtr, CSteamID steamIDLobby)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_SetLobbyType")]
STUB(bool, SteamAPI_ISteamMatchmaking_SetLobbyType, 0, IntPtr instancePtr, CSteamID steamIDLobby, ELobbyType eLobbyType)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_SetLobbyJoinable")]
STUB(bool, SteamAPI_ISteamMatchmaking_SetLobbyJoinable, 0, IntPtr instancePtr, CSteamID steamIDLobby, char bLobbyJoinable)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_GetLobbyOwner")]
STUB(ulong, SteamAPI_ISteamMatchmaking_GetLobbyOwner, 0, IntPtr instancePtr, CSteamID steamIDLobby)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_SetLobbyOwner")]
STUB(bool, SteamAPI_ISteamMatchmaking_SetLobbyOwner, 0, IntPtr instancePtr, CSteamID steamIDLobby, CSteamID steamIDNewOwner)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmaking_SetLinkedLobby")]
STUB(bool, SteamAPI_ISteamMatchmaking_SetLinkedLobby, 0, IntPtr instancePtr, CSteamID steamIDLobby, CSteamID steamIDLobbyDependent)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmakingServers_RequestInternetServerList")]
STUB(IntPtr, SteamAPI_ISteamMatchmakingServers_RequestInternetServerList, 0, IntPtr instancePtr, AppId_t iApp, IntPtr ppchFilters, uint nFilters, IntPtr pRequestServersResponse)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmakingServers_RequestLANServerList")]
STUB(IntPtr, SteamAPI_ISteamMatchmakingServers_RequestLANServerList, 0, IntPtr instancePtr, AppId_t iApp, IntPtr pRequestServersResponse)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmakingServers_RequestFriendsServerList")]
STUB(IntPtr, SteamAPI_ISteamMatchmakingServers_RequestFriendsServerList, 0, IntPtr instancePtr, AppId_t iApp, IntPtr ppchFilters, uint nFilters, IntPtr pRequestServersResponse)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmakingServers_RequestFavoritesServerList")]
STUB(IntPtr, SteamAPI_ISteamMatchmakingServers_RequestFavoritesServerList, 0, IntPtr instancePtr, AppId_t iApp, IntPtr ppchFilters, uint nFilters, IntPtr pRequestServersResponse)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmakingServers_RequestHistoryServerList")]
STUB(IntPtr, SteamAPI_ISteamMatchmakingServers_RequestHistoryServerList, 0, IntPtr instancePtr, AppId_t iApp, IntPtr ppchFilters, uint nFilters, IntPtr pRequestServersResponse)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmakingServers_RequestSpectatorServerList")]
STUB(IntPtr, SteamAPI_ISteamMatchmakingServers_RequestSpectatorServerList, 0, IntPtr instancePtr, AppId_t iApp, IntPtr ppchFilters, uint nFilters, IntPtr pRequestServersResponse)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmakingServers_ReleaseRequest")]
STUB(void, SteamAPI_ISteamMatchmakingServers_ReleaseRequest, 0, IntPtr instancePtr, HServerListRequest hServerListRequest)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmakingServers_GetServerDetails")]
STUB(IntPtr, SteamAPI_ISteamMatchmakingServers_GetServerDetails, 0, IntPtr instancePtr, HServerListRequest hRequest, int iServer)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmakingServers_CancelQuery")]
STUB(void, SteamAPI_ISteamMatchmakingServers_CancelQuery, 0, IntPtr instancePtr, HServerListRequest hRequest)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmakingServers_RefreshQuery")]
STUB(void, SteamAPI_ISteamMatchmakingServers_RefreshQuery, 0, IntPtr instancePtr, HServerListRequest hRequest)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmakingServers_IsRefreshing")]
STUB(bool, SteamAPI_ISteamMatchmakingServers_IsRefreshing, 0, IntPtr instancePtr, HServerListRequest hRequest)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmakingServers_GetServerCount")]
STUB(int, SteamAPI_ISteamMatchmakingServers_GetServerCount, 0, IntPtr instancePtr, HServerListRequest hRequest)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmakingServers_RefreshServer")]
STUB(void, SteamAPI_ISteamMatchmakingServers_RefreshServer, 0, IntPtr instancePtr, HServerListRequest hRequest, int iServer)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmakingServers_PingServer")]
STUB(int, SteamAPI_ISteamMatchmakingServers_PingServer, 0, IntPtr instancePtr, uint unIP, ushort usPort, IntPtr pRequestServersResponse)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmakingServers_PlayerDetails")]
STUB(int, SteamAPI_ISteamMatchmakingServers_PlayerDetails, 0, IntPtr instancePtr, uint unIP, ushort usPort, IntPtr pRequestServersResponse)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmakingServers_ServerRules")]
STUB(int, SteamAPI_ISteamMatchmakingServers_ServerRules, 0, IntPtr instancePtr, uint unIP, ushort usPort, IntPtr pRequestServersResponse)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMatchmakingServers_CancelServerQuery")]
STUB(void, SteamAPI_ISteamMatchmakingServers_CancelServerQuery, 0, IntPtr instancePtr, HServerQuery hServerQuery)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameSearch_AddGameSearchParams")]
STUB(EGameSearchErrorCode_t, SteamAPI_ISteamGameSearch_AddGameSearchParams, 0, IntPtr instancePtr, char * pchKeyToFind, char * pchValuesToFind)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameSearch_SearchForGameWithLobby")]
STUB(EGameSearchErrorCode_t, SteamAPI_ISteamGameSearch_SearchForGameWithLobby, 0, IntPtr instancePtr, CSteamID steamIDLobby, int nPlayerMin, int nPlayerMax)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameSearch_SearchForGameSolo")]
STUB(EGameSearchErrorCode_t, SteamAPI_ISteamGameSearch_SearchForGameSolo, 0, IntPtr instancePtr, int nPlayerMin, int nPlayerMax)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameSearch_AcceptGame")]
STUB(EGameSearchErrorCode_t, SteamAPI_ISteamGameSearch_AcceptGame, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameSearch_DeclineGame")]
STUB(EGameSearchErrorCode_t, SteamAPI_ISteamGameSearch_DeclineGame, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameSearch_RetrieveConnectionDetails")]
STUB(EGameSearchErrorCode_t, SteamAPI_ISteamGameSearch_RetrieveConnectionDetails, 0, IntPtr instancePtr, CSteamID steamIDHost, IntPtr pchConnectionDetails, int cubConnectionDetails)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameSearch_EndGameSearch")]
STUB(EGameSearchErrorCode_t, SteamAPI_ISteamGameSearch_EndGameSearch, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameSearch_SetGameHostParams")]
STUB(EGameSearchErrorCode_t, SteamAPI_ISteamGameSearch_SetGameHostParams, 0, IntPtr instancePtr, char * pchKey, char * pchValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameSearch_SetConnectionDetails")]
STUB(EGameSearchErrorCode_t, SteamAPI_ISteamGameSearch_SetConnectionDetails, 0, IntPtr instancePtr, char * pchConnectionDetails, int cubConnectionDetails)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameSearch_RequestPlayersForGame")]
STUB(EGameSearchErrorCode_t, SteamAPI_ISteamGameSearch_RequestPlayersForGame, 0, IntPtr instancePtr, int nPlayerMin, int nPlayerMax, int nMaxTeamSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameSearch_HostConfirmGameStart")]
STUB(EGameSearchErrorCode_t, SteamAPI_ISteamGameSearch_HostConfirmGameStart, 0, IntPtr instancePtr, ulong ullUniqueGameID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameSearch_CancelRequestPlayersForGame")]
STUB(EGameSearchErrorCode_t, SteamAPI_ISteamGameSearch_CancelRequestPlayersForGame, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameSearch_SubmitPlayerResult")]
STUB(EGameSearchErrorCode_t, SteamAPI_ISteamGameSearch_SubmitPlayerResult, 0, IntPtr instancePtr, ulong ullUniqueGameID, CSteamID steamIDPlayer, EPlayerResult_t EPlayerResult)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamGameSearch_EndGame")]
STUB(EGameSearchErrorCode_t, SteamAPI_ISteamGameSearch_EndGame, 0, IntPtr instancePtr, ulong ullUniqueGameID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamParties_GetNumActiveBeacons")]
STUB(uint, SteamAPI_ISteamParties_GetNumActiveBeacons, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamParties_GetBeaconByIndex")]
STUB(ulong, SteamAPI_ISteamParties_GetBeaconByIndex, 0, IntPtr instancePtr, uint unIndex)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamParties_GetBeaconDetails")]
STUB(bool, SteamAPI_ISteamParties_GetBeaconDetails, 0, IntPtr instancePtr, PartyBeaconID_t ulBeaconID, out CSteamID pSteamIDBeaconOwner, out SteamPartyBeaconLocation_t pLocation, IntPtr pchMetadata, int cchMetadata)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamParties_JoinParty")]
STUB(ulong, SteamAPI_ISteamParties_JoinParty, 0, IntPtr instancePtr, PartyBeaconID_t ulBeaconID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamParties_GetNumAvailableBeaconLocations")]
STUB(bool, SteamAPI_ISteamParties_GetNumAvailableBeaconLocations, 0, IntPtr instancePtr, out uint puNumLocations)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamParties_GetAvailableBeaconLocations")]
STUB(bool, SteamAPI_ISteamParties_GetAvailableBeaconLocations, 0, IntPtr instancePtr, SteamPartyBeaconLocation_t* pLocationList, uint uMaxNumLocations)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamParties_CreateBeacon")]
STUB(ulong, SteamAPI_ISteamParties_CreateBeacon, 0, IntPtr instancePtr, uint unOpenSlots, ref SteamPartyBeaconLocation_t pBeaconLocation, char * pchConnectString, char * pchMetadata)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamParties_OnReservationCompleted")]
STUB(void, SteamAPI_ISteamParties_OnReservationCompleted, 0, IntPtr instancePtr, PartyBeaconID_t ulBeacon, CSteamID steamIDUser)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamParties_CancelReservation")]
STUB(void, SteamAPI_ISteamParties_CancelReservation, 0, IntPtr instancePtr, PartyBeaconID_t ulBeacon, CSteamID steamIDUser)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamParties_ChangeNumOpenSlots")]
STUB(ulong, SteamAPI_ISteamParties_ChangeNumOpenSlots, 0, IntPtr instancePtr, PartyBeaconID_t ulBeacon, uint unOpenSlots)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamParties_DestroyBeacon")]
STUB(bool, SteamAPI_ISteamParties_DestroyBeacon, 0, IntPtr instancePtr, PartyBeaconID_t ulBeacon)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamParties_GetBeaconLocationData")]
STUB(bool, SteamAPI_ISteamParties_GetBeaconLocationData, 0, IntPtr instancePtr, SteamPartyBeaconLocation_t BeaconLocation, ESteamPartyBeaconLocationData eData, IntPtr pchDataStringOut, int cchDataStringOut)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusic_BIsEnabled")]
STUB(bool, SteamAPI_ISteamMusic_BIsEnabled, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusic_BIsPlaying")]
STUB(bool, SteamAPI_ISteamMusic_BIsPlaying, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusic_GetPlaybackStatus")]
STUB(AudioPlayback_Status, SteamAPI_ISteamMusic_GetPlaybackStatus, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusic_Play")]
STUB(void, SteamAPI_ISteamMusic_Play, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusic_Pause")]
STUB(void, SteamAPI_ISteamMusic_Pause, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusic_PlayPrevious")]
STUB(void, SteamAPI_ISteamMusic_PlayPrevious, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusic_PlayNext")]
STUB(void, SteamAPI_ISteamMusic_PlayNext, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusic_SetVolume")]
STUB(void, SteamAPI_ISteamMusic_SetVolume, 0, IntPtr instancePtr, float flVolume)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusic_GetVolume")]
STUB(float, SteamAPI_ISteamMusic_GetVolume, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_RegisterSteamMusicRemote")]
STUB(bool, SteamAPI_ISteamMusicRemote_RegisterSteamMusicRemote, 0, IntPtr instancePtr, char * pchName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_DeregisterSteamMusicRemote")]
STUB(bool, SteamAPI_ISteamMusicRemote_DeregisterSteamMusicRemote, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_BIsCurrentMusicRemote")]
STUB(bool, SteamAPI_ISteamMusicRemote_BIsCurrentMusicRemote, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_BActivationSuccess")]
STUB(bool, SteamAPI_ISteamMusicRemote_BActivationSuccess, 0, IntPtr instancePtr, char bValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_SetDisplayName")]
STUB(bool, SteamAPI_ISteamMusicRemote_SetDisplayName, 0, IntPtr instancePtr, char * pchDisplayName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_SetPNGIcon_64x64")]
STUB(bool, SteamAPI_ISteamMusicRemote_SetPNGIcon_64x64, 0, IntPtr instancePtr, byte* pvBuffer, uint cbBufferLength)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_EnablePlayPrevious")]
STUB(bool, SteamAPI_ISteamMusicRemote_EnablePlayPrevious, 0, IntPtr instancePtr, char bValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_EnablePlayNext")]
STUB(bool, SteamAPI_ISteamMusicRemote_EnablePlayNext, 0, IntPtr instancePtr, char bValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_EnableShuffled")]
STUB(bool, SteamAPI_ISteamMusicRemote_EnableShuffled, 0, IntPtr instancePtr, char bValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_EnableLooped")]
STUB(bool, SteamAPI_ISteamMusicRemote_EnableLooped, 0, IntPtr instancePtr, char bValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_EnableQueue")]
STUB(bool, SteamAPI_ISteamMusicRemote_EnableQueue, 0, IntPtr instancePtr, char bValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_EnablePlaylists")]
STUB(bool, SteamAPI_ISteamMusicRemote_EnablePlaylists, 0, IntPtr instancePtr, char bValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_UpdatePlaybackStatus")]
STUB(bool, SteamAPI_ISteamMusicRemote_UpdatePlaybackStatus, 0, IntPtr instancePtr, AudioPlayback_Status nStatus)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_UpdateShuffled")]
STUB(bool, SteamAPI_ISteamMusicRemote_UpdateShuffled, 0, IntPtr instancePtr, char bValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_UpdateLooped")]
STUB(bool, SteamAPI_ISteamMusicRemote_UpdateLooped, 0, IntPtr instancePtr, char bValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_UpdateVolume")]
STUB(bool, SteamAPI_ISteamMusicRemote_UpdateVolume, 0, IntPtr instancePtr, float flValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_CurrentEntryWillChange")]
STUB(bool, SteamAPI_ISteamMusicRemote_CurrentEntryWillChange, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_CurrentEntryIsAvailable")]
STUB(bool, SteamAPI_ISteamMusicRemote_CurrentEntryIsAvailable, 0, IntPtr instancePtr, char bAvailable)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_UpdateCurrentEntryText")]
STUB(bool, SteamAPI_ISteamMusicRemote_UpdateCurrentEntryText, 0, IntPtr instancePtr, char * pchText)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds")]
STUB(bool, SteamAPI_ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds, 0, IntPtr instancePtr, int nValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_UpdateCurrentEntryCoverArt")]
STUB(bool, SteamAPI_ISteamMusicRemote_UpdateCurrentEntryCoverArt, 0, IntPtr instancePtr, byte* pvBuffer, uint cbBufferLength)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_CurrentEntryDidChange")]
STUB(bool, SteamAPI_ISteamMusicRemote_CurrentEntryDidChange, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_QueueWillChange")]
STUB(bool, SteamAPI_ISteamMusicRemote_QueueWillChange, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_ResetQueueEntries")]
STUB(bool, SteamAPI_ISteamMusicRemote_ResetQueueEntries, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_SetQueueEntry")]
STUB(bool, SteamAPI_ISteamMusicRemote_SetQueueEntry, 0, IntPtr instancePtr, int nID, int nPosition, char * pchEntryText)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_SetCurrentQueueEntry")]
STUB(bool, SteamAPI_ISteamMusicRemote_SetCurrentQueueEntry, 0, IntPtr instancePtr, int nID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_QueueDidChange")]
STUB(bool, SteamAPI_ISteamMusicRemote_QueueDidChange, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_PlaylistWillChange")]
STUB(bool, SteamAPI_ISteamMusicRemote_PlaylistWillChange, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_ResetPlaylistEntries")]
STUB(bool, SteamAPI_ISteamMusicRemote_ResetPlaylistEntries, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_SetPlaylistEntry")]
STUB(bool, SteamAPI_ISteamMusicRemote_SetPlaylistEntry, 0, IntPtr instancePtr, int nID, int nPosition, char * pchEntryText)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_SetCurrentPlaylistEntry")]
STUB(bool, SteamAPI_ISteamMusicRemote_SetCurrentPlaylistEntry, 0, IntPtr instancePtr, int nID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamMusicRemote_PlaylistDidChange")]
STUB(bool, SteamAPI_ISteamMusicRemote_PlaylistDidChange, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_SendP2PPacket")]
STUB(bool, SteamAPI_ISteamNetworking_SendP2PPacket, 0, IntPtr instancePtr, CSteamID steamIDRemote, byte* pubData, uint cubData, EP2PSend eP2PSendType, int nChannel)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_IsP2PPacketAvailable")]
STUB(bool, SteamAPI_ISteamNetworking_IsP2PPacketAvailable, 0, IntPtr instancePtr, out uint pcubMsgSize, int nChannel)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_ReadP2PPacket")]
STUB(bool, SteamAPI_ISteamNetworking_ReadP2PPacket, 0, IntPtr instancePtr, byte* pubDest, uint cubDest, out uint pcubMsgSize, out CSteamID psteamIDRemote, int nChannel)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser")]
STUB(bool, SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser, 0, IntPtr instancePtr, CSteamID steamIDRemote)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_CloseP2PSessionWithUser")]
STUB(bool, SteamAPI_ISteamNetworking_CloseP2PSessionWithUser, 0, IntPtr instancePtr, CSteamID steamIDRemote)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_CloseP2PChannelWithUser")]
STUB(bool, SteamAPI_ISteamNetworking_CloseP2PChannelWithUser, 0, IntPtr instancePtr, CSteamID steamIDRemote, int nChannel)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_GetP2PSessionState")]
STUB(bool, SteamAPI_ISteamNetworking_GetP2PSessionState, 0, IntPtr instancePtr, CSteamID steamIDRemote, out P2PSessionState_t pConnectionState)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_AllowP2PPacketRelay")]
STUB(bool, SteamAPI_ISteamNetworking_AllowP2PPacketRelay, 0, IntPtr instancePtr, char bAllow)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_CreateListenSocket")]
STUB(uint, SteamAPI_ISteamNetworking_CreateListenSocket, 0, IntPtr instancePtr, int nVirtualP2PPort, SteamIPAddress_t nIP, ushort nPort, char bAllowUseOfPacketRelay)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_CreateP2PConnectionSocket")]
STUB(uint, SteamAPI_ISteamNetworking_CreateP2PConnectionSocket, 0, IntPtr instancePtr, CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec, char bAllowUseOfPacketRelay)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_CreateConnectionSocket")]
STUB(uint, SteamAPI_ISteamNetworking_CreateConnectionSocket, 0, IntPtr instancePtr, SteamIPAddress_t nIP, ushort nPort, int nTimeoutSec)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_DestroySocket")]
STUB(bool, SteamAPI_ISteamNetworking_DestroySocket, 0, IntPtr instancePtr, SNetSocket_t hSocket, char bNotifyRemoteEnd)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_DestroyListenSocket")]
STUB(bool, SteamAPI_ISteamNetworking_DestroyListenSocket, 0, IntPtr instancePtr, SNetListenSocket_t hSocket, char bNotifyRemoteEnd)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_SendDataOnSocket")]
STUB(bool, SteamAPI_ISteamNetworking_SendDataOnSocket, 0, IntPtr instancePtr, SNetSocket_t hSocket, byte* pubData, uint cubData, char bReliable)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_IsDataAvailableOnSocket")]
STUB(bool, SteamAPI_ISteamNetworking_IsDataAvailableOnSocket, 0, IntPtr instancePtr, SNetSocket_t hSocket, out uint pcubMsgSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_RetrieveDataFromSocket")]
STUB(bool, SteamAPI_ISteamNetworking_RetrieveDataFromSocket, 0, IntPtr instancePtr, SNetSocket_t hSocket, byte* pubDest, uint cubDest, out uint pcubMsgSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_IsDataAvailable")]
STUB(bool, SteamAPI_ISteamNetworking_IsDataAvailable, 0, IntPtr instancePtr, SNetListenSocket_t hListenSocket, out uint pcubMsgSize, out SNetSocket_t phSocket)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_RetrieveData")]
STUB(bool, SteamAPI_ISteamNetworking_RetrieveData, 0, IntPtr instancePtr, SNetListenSocket_t hListenSocket, byte* pubDest, uint cubDest, out uint pcubMsgSize, out SNetSocket_t phSocket)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_GetSocketInfo")]
STUB(bool, SteamAPI_ISteamNetworking_GetSocketInfo, 0, IntPtr instancePtr, SNetSocket_t hSocket, out CSteamID pSteamIDRemote, out int peSocketStatus, out SteamIPAddress_t punIPRemote, out ushort punPortRemote)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_GetListenSocketInfo")]
STUB(bool, SteamAPI_ISteamNetworking_GetListenSocketInfo, 0, IntPtr instancePtr, SNetListenSocket_t hListenSocket, out SteamIPAddress_t pnIP, out ushort pnPort)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_GetSocketConnectionType")]
STUB(ESNetSocketConnectionType, SteamAPI_ISteamNetworking_GetSocketConnectionType, 0, IntPtr instancePtr, SNetSocket_t hSocket)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworking_GetMaxPacketSize")]
STUB(int, SteamAPI_ISteamNetworking_GetMaxPacketSize, 0, IntPtr instancePtr, SNetSocket_t hSocket)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingMessages_SendMessageToUser")]
STUB(EResult, SteamAPI_ISteamNetworkingMessages_SendMessageToUser, 0, IntPtr instancePtr, ref SteamNetworkingIdentity identityRemote, IntPtr pubData, uint cubData, int nSendFlags, int nRemoteChannel)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingMessages_ReceiveMessagesOnChannel")]
STUB(int, SteamAPI_ISteamNetworkingMessages_ReceiveMessagesOnChannel, 0, IntPtr instancePtr, int nLocalChannel, IntPtr* ppOutMessages, int nMaxMessages)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingMessages_AcceptSessionWithUser")]
STUB(bool, SteamAPI_ISteamNetworkingMessages_AcceptSessionWithUser, 0, IntPtr instancePtr, ref SteamNetworkingIdentity identityRemote)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingMessages_CloseSessionWithUser")]
STUB(bool, SteamAPI_ISteamNetworkingMessages_CloseSessionWithUser, 0, IntPtr instancePtr, ref SteamNetworkingIdentity identityRemote)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingMessages_CloseChannelWithUser")]
STUB(bool, SteamAPI_ISteamNetworkingMessages_CloseChannelWithUser, 0, IntPtr instancePtr, ref SteamNetworkingIdentity identityRemote, int nLocalChannel)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingMessages_GetSessionConnectionInfo")]
STUB(ESteamNetworkingConnectionState, SteamAPI_ISteamNetworkingMessages_GetSessionConnectionInfo, 0, IntPtr instancePtr, ref SteamNetworkingIdentity identityRemote, out SteamNetConnectionInfo_t pConnectionInfo, out SteamNetConnectionRealTimeStatus_t pQuickStatus)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_CreateListenSocketIP")]
STUB(uint, SteamAPI_ISteamNetworkingSockets_CreateListenSocketIP, 0, IntPtr instancePtr, struct SteamNetworkingIPAddr * localAddress, int nOptions, SteamNetworkingConfigValue_t* pOptions)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_ConnectByIPAddress")]
STUB(uint, SteamAPI_ISteamNetworkingSockets_ConnectByIPAddress, 0, IntPtr instancePtr, struct SteamNetworkingIPAddr * address, int nOptions, SteamNetworkingConfigValue_t* pOptions)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2P")]
STUB(uint, SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2P, 0, IntPtr instancePtr, int nLocalVirtualPort, int nOptions, SteamNetworkingConfigValue_t* pOptions)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_ConnectP2P")]
STUB(uint, SteamAPI_ISteamNetworkingSockets_ConnectP2P, 0, IntPtr instancePtr, ref SteamNetworkingIdentity identityRemote, int nRemoteVirtualPort, int nOptions, SteamNetworkingConfigValue_t* pOptions)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_AcceptConnection")]
STUB(EResult, SteamAPI_ISteamNetworkingSockets_AcceptConnection, 0, IntPtr instancePtr, HSteamNetConnection hConn)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_CloseConnection")]
STUB(bool, SteamAPI_ISteamNetworkingSockets_CloseConnection, 0, IntPtr instancePtr, HSteamNetConnection hPeer, int nReason, char * pszDebug, char bEnableLinger)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_CloseListenSocket")]
STUB(bool, SteamAPI_ISteamNetworkingSockets_CloseListenSocket, 0, IntPtr instancePtr, HSteamListenSocket hSocket)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_SetConnectionUserData")]
STUB(bool, SteamAPI_ISteamNetworkingSockets_SetConnectionUserData, 0, IntPtr instancePtr, HSteamNetConnection hPeer, long nUserData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_GetConnectionUserData")]
STUB(long, SteamAPI_ISteamNetworkingSockets_GetConnectionUserData, 0, IntPtr instancePtr, HSteamNetConnection hPeer)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_SetConnectionName")]
STUB(void, SteamAPI_ISteamNetworkingSockets_SetConnectionName, 0, IntPtr instancePtr, HSteamNetConnection hPeer, char * pszName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_GetConnectionName")]
STUB(bool, SteamAPI_ISteamNetworkingSockets_GetConnectionName, 0, IntPtr instancePtr, HSteamNetConnection hPeer, IntPtr pszName, int nMaxLen)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_SendMessageToConnection")]
STUB(EResult, SteamAPI_ISteamNetworkingSockets_SendMessageToConnection, 0, IntPtr instancePtr, HSteamNetConnection hConn, IntPtr pData, uint cbData, int nSendFlags, out long pOutMessageNumber)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_SendMessages")]
STUB(void, SteamAPI_ISteamNetworkingSockets_SendMessages, 0, IntPtr instancePtr, int nMessages, SteamNetworkingMessage_t* pMessages, long* pOutMessageNumberOrResult)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_FlushMessagesOnConnection")]
STUB(EResult, SteamAPI_ISteamNetworkingSockets_FlushMessagesOnConnection, 0, IntPtr instancePtr, HSteamNetConnection hConn)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnConnection")]
STUB(int, SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnConnection, 0, IntPtr instancePtr, HSteamNetConnection hConn, IntPtr* ppOutMessages, int nMaxMessages)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_GetConnectionInfo")]
STUB(bool, SteamAPI_ISteamNetworkingSockets_GetConnectionInfo, 0, IntPtr instancePtr, HSteamNetConnection hConn, out SteamNetConnectionInfo_t pInfo)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_GetConnectionRealTimeStatus")]
STUB(EResult, SteamAPI_ISteamNetworkingSockets_GetConnectionRealTimeStatus, 0, IntPtr instancePtr, HSteamNetConnection hConn, ref SteamNetConnectionRealTimeStatus_t pStatus, int nLanes, ref SteamNetConnectionRealTimeLaneStatus_t pLanes)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_GetDetailedConnectionStatus")]
STUB(int, SteamAPI_ISteamNetworkingSockets_GetDetailedConnectionStatus, 0, IntPtr instancePtr, HSteamNetConnection hConn, IntPtr pszBuf, int cbBuf)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_GetListenSocketAddress")]
STUB(bool, SteamAPI_ISteamNetworkingSockets_GetListenSocketAddress, 0, IntPtr instancePtr, HSteamListenSocket hSocket, out SteamNetworkingIPAddr address)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_CreateSocketPair")]
STUB(bool, SteamAPI_ISteamNetworkingSockets_CreateSocketPair, 0, IntPtr instancePtr, out HSteamNetConnection pOutConnection1, out HSteamNetConnection pOutConnection2, char bUseNetworkLoopback, ref SteamNetworkingIdentity pIdentity1, ref SteamNetworkingIdentity pIdentity2)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_ConfigureConnectionLanes")]
STUB(EResult, SteamAPI_ISteamNetworkingSockets_ConfigureConnectionLanes, 0, IntPtr instancePtr, HSteamNetConnection hConn, int nNumLanes, out int pLanePriorities, out ushort pLaneWeights)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_GetIdentity")]
STUB(bool, SteamAPI_ISteamNetworkingSockets_GetIdentity, 0, IntPtr instancePtr, out SteamNetworkingIdentity pIdentity)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_InitAuthentication")]
STUB(ESteamNetworkingAvailability, SteamAPI_ISteamNetworkingSockets_InitAuthentication, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_GetAuthenticationStatus")]
STUB(ESteamNetworkingAvailability, SteamAPI_ISteamNetworkingSockets_GetAuthenticationStatus, 0, IntPtr instancePtr, out SteamNetAuthenticationStatus_t pDetails)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_CreatePollGroup")]
STUB(uint, SteamAPI_ISteamNetworkingSockets_CreatePollGroup, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_DestroyPollGroup")]
STUB(bool, SteamAPI_ISteamNetworkingSockets_DestroyPollGroup, 0, IntPtr instancePtr, HSteamNetPollGroup hPollGroup)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_SetConnectionPollGroup")]
STUB(bool, SteamAPI_ISteamNetworkingSockets_SetConnectionPollGroup, 0, IntPtr instancePtr, HSteamNetConnection hConn, HSteamNetPollGroup hPollGroup)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnPollGroup")]
STUB(int, SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnPollGroup, 0, IntPtr instancePtr, HSteamNetPollGroup hPollGroup, IntPtr* ppOutMessages, int nMaxMessages)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_ReceivedRelayAuthTicket")]
STUB(bool, SteamAPI_ISteamNetworkingSockets_ReceivedRelayAuthTicket, 0, IntPtr instancePtr, IntPtr pvTicket, int cbTicket, out SteamDatagramRelayAuthTicket pOutParsedTicket)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_FindRelayAuthTicketForServer")]
STUB(int, SteamAPI_ISteamNetworkingSockets_FindRelayAuthTicketForServer, 0, IntPtr instancePtr, ref SteamNetworkingIdentity identityGameServer, int nRemoteVirtualPort, out SteamDatagramRelayAuthTicket pOutParsedTicket)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_ConnectToHostedDedicatedServer")]
STUB(uint, SteamAPI_ISteamNetworkingSockets_ConnectToHostedDedicatedServer, 0, IntPtr instancePtr, ref SteamNetworkingIdentity identityTarget, int nRemoteVirtualPort, int nOptions, SteamNetworkingConfigValue_t* pOptions)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPort")]
STUB(ushort, SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPort, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPOPID")]
STUB(uint, SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPOPID, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerAddress")]
STUB(EResult, SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerAddress, 0, IntPtr instancePtr, out SteamDatagramHostedAddress pRouting)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_CreateHostedDedicatedServerListenSocket")]
STUB(uint, SteamAPI_ISteamNetworkingSockets_CreateHostedDedicatedServerListenSocket, 0, IntPtr instancePtr, int nLocalVirtualPort, int nOptions, SteamNetworkingConfigValue_t* pOptions)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_GetGameCoordinatorServerLogin")]
STUB(EResult, SteamAPI_ISteamNetworkingSockets_GetGameCoordinatorServerLogin, 0, IntPtr instancePtr, IntPtr pLoginInfo, out int pcbSignedBlob, IntPtr pBlob)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_ConnectP2PCustomSignaling")]
STUB(uint, SteamAPI_ISteamNetworkingSockets_ConnectP2PCustomSignaling, 0, IntPtr instancePtr, out ISteamNetworkingConnectionSignaling pSignaling, ref SteamNetworkingIdentity pPeerIdentity, int nRemoteVirtualPort, int nOptions, SteamNetworkingConfigValue_t* pOptions)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_ReceivedP2PCustomSignal")]
STUB(bool, SteamAPI_ISteamNetworkingSockets_ReceivedP2PCustomSignal, 0, IntPtr instancePtr, IntPtr pMsg, int cbMsg, out ISteamNetworkingSignalingRecvContext pContext)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_GetCertificateRequest")]
STUB(bool, SteamAPI_ISteamNetworkingSockets_GetCertificateRequest, 0, IntPtr instancePtr, out int pcbBlob, IntPtr pBlob, out SteamNetworkingErrMsg errMsg)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_SetCertificate")]
STUB(bool, SteamAPI_ISteamNetworkingSockets_SetCertificate, 0, IntPtr instancePtr, IntPtr pCertificate, int cbCertificate, out SteamNetworkingErrMsg errMsg)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_ResetIdentity")]
STUB(void, SteamAPI_ISteamNetworkingSockets_ResetIdentity, 0, IntPtr instancePtr, ref SteamNetworkingIdentity pIdentity)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_RunCallbacks")]
STUB(void, SteamAPI_ISteamNetworkingSockets_RunCallbacks, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_BeginAsyncRequestFakeIP")]
STUB(bool, SteamAPI_ISteamNetworkingSockets_BeginAsyncRequestFakeIP, 0, IntPtr instancePtr, int nNumPorts)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_GetFakeIP")]
STUB(void, SteamAPI_ISteamNetworkingSockets_GetFakeIP, 0, IntPtr instancePtr, int idxFirstPort, out SteamNetworkingFakeIPResult_t pInfo)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2PFakeIP")]
STUB(uint, SteamAPI_ISteamNetworkingSockets_CreateListenSocketP2PFakeIP, 0, IntPtr instancePtr, int idxFakePort, int nOptions, SteamNetworkingConfigValue_t* pOptions)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_GetRemoteFakeIPForConnection")]
STUB(EResult, SteamAPI_ISteamNetworkingSockets_GetRemoteFakeIPForConnection, 0, IntPtr instancePtr, HSteamNetConnection hConn, out SteamNetworkingIPAddr pOutAddr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingSockets_CreateFakeUDPPort")]
STUB(IntPtr, SteamAPI_ISteamNetworkingSockets_CreateFakeUDPPort, 0, IntPtr instancePtr, int idxFakeServerPort)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_AllocateMessage")]
STUB(IntPtr, SteamAPI_ISteamNetworkingUtils_AllocateMessage, 0, IntPtr instancePtr, int cbAllocateBuffer)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_InitRelayNetworkAccess")]
STUB(void, SteamAPI_ISteamNetworkingUtils_InitRelayNetworkAccess, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_GetRelayNetworkStatus")]
STUB(ESteamNetworkingAvailability, SteamAPI_ISteamNetworkingUtils_GetRelayNetworkStatus, 0, IntPtr instancePtr, out SteamRelayNetworkStatus_t pDetails)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_GetLocalPingLocation")]
STUB(float, SteamAPI_ISteamNetworkingUtils_GetLocalPingLocation, 0, IntPtr instancePtr, out SteamNetworkPingLocation_t result)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_EstimatePingTimeBetweenTwoLocations")]
STUB(int, SteamAPI_ISteamNetworkingUtils_EstimatePingTimeBetweenTwoLocations, 0, IntPtr instancePtr, ref SteamNetworkPingLocation_t location1, ref SteamNetworkPingLocation_t location2)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_EstimatePingTimeFromLocalHost")]
STUB(int, SteamAPI_ISteamNetworkingUtils_EstimatePingTimeFromLocalHost, 0, IntPtr instancePtr, ref SteamNetworkPingLocation_t remoteLocation)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_ConvertPingLocationToString")]
STUB(void, SteamAPI_ISteamNetworkingUtils_ConvertPingLocationToString, 0, IntPtr instancePtr, ref SteamNetworkPingLocation_t location, IntPtr pszBuf, int cchBufSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_ParsePingLocationString")]
STUB(bool, SteamAPI_ISteamNetworkingUtils_ParsePingLocationString, 0, IntPtr instancePtr, char * pszString, out SteamNetworkPingLocation_t result)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_CheckPingDataUpToDate")]
STUB(bool, SteamAPI_ISteamNetworkingUtils_CheckPingDataUpToDate, 0, IntPtr instancePtr, float flMaxAgeSeconds)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_GetPingToDataCenter")]
STUB(int, SteamAPI_ISteamNetworkingUtils_GetPingToDataCenter, 0, IntPtr instancePtr, SteamNetworkingPOPID popID, out SteamNetworkingPOPID pViaRelayPoP)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_GetDirectPingToPOP")]
STUB(int, SteamAPI_ISteamNetworkingUtils_GetDirectPingToPOP, 0, IntPtr instancePtr, SteamNetworkingPOPID popID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_GetPOPCount")]
STUB(int, SteamAPI_ISteamNetworkingUtils_GetPOPCount, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_GetPOPList")]
STUB(int, SteamAPI_ISteamNetworkingUtils_GetPOPList, 0, IntPtr instancePtr, out SteamNetworkingPOPID list, int nListSz)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_GetLocalTimestamp")]
STUB(long, SteamAPI_ISteamNetworkingUtils_GetLocalTimestamp, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_SetDebugOutputFunction")]
STUB(void, SteamAPI_ISteamNetworkingUtils_SetDebugOutputFunction, 0, IntPtr instancePtr, ESteamNetworkingSocketsDebugOutputType eDetailLevel, FSteamNetworkingSocketsDebugOutput pfnFunc)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_IsFakeIPv4")]
STUB(bool, SteamAPI_ISteamNetworkingUtils_IsFakeIPv4, 0, IntPtr instancePtr, uint nIPv4)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_GetIPv4FakeIPType")]
STUB(ESteamNetworkingFakeIPType, SteamAPI_ISteamNetworkingUtils_GetIPv4FakeIPType, 0, IntPtr instancePtr, uint nIPv4)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_GetRealIdentityForFakeIP")]
STUB(EResult, SteamAPI_ISteamNetworkingUtils_GetRealIdentityForFakeIP, 0, IntPtr instancePtr, struct SteamNetworkingIPAddr * fakeIP, out SteamNetworkingIdentity pOutRealIdentity)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_SetConfigValue")]
STUB(bool, SteamAPI_ISteamNetworkingUtils_SetConfigValue, 0, IntPtr instancePtr, ESteamNetworkingConfigValue eValue, ESteamNetworkingConfigScope eScopeType, IntPtr scopeObj, ESteamNetworkingConfigDataType eDataType, IntPtr pArg)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_GetConfigValue")]
STUB(ESteamNetworkingGetConfigValueResult, SteamAPI_ISteamNetworkingUtils_GetConfigValue, 0, IntPtr instancePtr, ESteamNetworkingConfigValue eValue, ESteamNetworkingConfigScope eScopeType, IntPtr scopeObj, out ESteamNetworkingConfigDataType pOutDataType, IntPtr pResult, ref ulong cbResult)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_GetConfigValueInfo")]
STUB(IntPtr, SteamAPI_ISteamNetworkingUtils_GetConfigValueInfo, 0, IntPtr instancePtr, ESteamNetworkingConfigValue eValue, out ESteamNetworkingConfigDataType pOutDataType, out ESteamNetworkingConfigScope pOutScope)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_IterateGenericEditableConfigValues")]
STUB(ESteamNetworkingConfigValue, SteamAPI_ISteamNetworkingUtils_IterateGenericEditableConfigValues, 0, IntPtr instancePtr, ESteamNetworkingConfigValue eCurrent, char bEnumerateDevVars)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ToString")]
STUB(void, SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ToString, 0, IntPtr instancePtr, struct SteamNetworkingIPAddr * addr, IntPtr buf, uint cbBuf, char bWithPort)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ParseString")]
STUB(bool, SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_ParseString, 0, IntPtr instancePtr, out SteamNetworkingIPAddr pAddr, char * pszStr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_GetFakeIPType")]
STUB(ESteamNetworkingFakeIPType, SteamAPI_ISteamNetworkingUtils_SteamNetworkingIPAddr_GetFakeIPType, 0, IntPtr instancePtr, struct SteamNetworkingIPAddr * addr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ToString")]
STUB(void, SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ToString, 0, IntPtr instancePtr, ref SteamNetworkingIdentity identity, IntPtr buf, uint cbBuf)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ParseString")]
STUB(bool, SteamAPI_ISteamNetworkingUtils_SteamNetworkingIdentity_ParseString, 0, IntPtr instancePtr, out SteamNetworkingIdentity pIdentity, char * pszStr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamParentalSettings_BIsParentalLockEnabled")]
STUB(bool, SteamAPI_ISteamParentalSettings_BIsParentalLockEnabled, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamParentalSettings_BIsParentalLockLocked")]
STUB(bool, SteamAPI_ISteamParentalSettings_BIsParentalLockLocked, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamParentalSettings_BIsAppBlocked")]
STUB(bool, SteamAPI_ISteamParentalSettings_BIsAppBlocked, 0, IntPtr instancePtr, AppId_t nAppID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamParentalSettings_BIsAppInBlockList")]
STUB(bool, SteamAPI_ISteamParentalSettings_BIsAppInBlockList, 0, IntPtr instancePtr, AppId_t nAppID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamParentalSettings_BIsFeatureBlocked")]
STUB(bool, SteamAPI_ISteamParentalSettings_BIsFeatureBlocked, 0, IntPtr instancePtr, EParentalFeature eFeature)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamParentalSettings_BIsFeatureInBlockList")]
STUB(bool, SteamAPI_ISteamParentalSettings_BIsFeatureInBlockList, 0, IntPtr instancePtr, EParentalFeature eFeature)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemotePlay_GetSessionCount")]
STUB(uint, SteamAPI_ISteamRemotePlay_GetSessionCount, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemotePlay_GetSessionID")]
STUB(uint, SteamAPI_ISteamRemotePlay_GetSessionID, 0, IntPtr instancePtr, int iSessionIndex)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemotePlay_GetSessionSteamID")]
STUB(ulong, SteamAPI_ISteamRemotePlay_GetSessionSteamID, 0, IntPtr instancePtr, RemotePlaySessionID_t unSessionID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemotePlay_GetSessionClientName")]
STUB(IntPtr, SteamAPI_ISteamRemotePlay_GetSessionClientName, 0, IntPtr instancePtr, RemotePlaySessionID_t unSessionID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemotePlay_GetSessionClientFormFactor")]
STUB(ESteamDeviceFormFactor, SteamAPI_ISteamRemotePlay_GetSessionClientFormFactor, 0, IntPtr instancePtr, RemotePlaySessionID_t unSessionID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemotePlay_BGetSessionClientResolution")]
STUB(bool, SteamAPI_ISteamRemotePlay_BGetSessionClientResolution, 0, IntPtr instancePtr, RemotePlaySessionID_t unSessionID, out int pnResolutionX, out int pnResolutionY)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemotePlay_BSendRemotePlayTogetherInvite")]
STUB(bool, SteamAPI_ISteamRemotePlay_BSendRemotePlayTogetherInvite, 0, IntPtr instancePtr, CSteamID steamIDFriend)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_FileWrite")]
STUB(bool, SteamAPI_ISteamRemoteStorage_FileWrite, 0, IntPtr instancePtr, char * pchFile, byte* pvData, int cubData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_FileRead")]
STUB(int, SteamAPI_ISteamRemoteStorage_FileRead, 0, IntPtr instancePtr, char * pchFile, byte* pvData, int cubDataToRead)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_FileWriteAsync")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_FileWriteAsync, 0, IntPtr instancePtr, char * pchFile, byte* pvData, uint cubData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_FileReadAsync")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_FileReadAsync, 0, IntPtr instancePtr, char * pchFile, uint nOffset, uint cubToRead)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_FileReadAsyncComplete")]
STUB(bool, SteamAPI_ISteamRemoteStorage_FileReadAsyncComplete, 0, IntPtr instancePtr, SteamAPICall_t hReadCall, byte* pvBuffer, uint cubToRead)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_FileForget")]
STUB(bool, SteamAPI_ISteamRemoteStorage_FileForget, 0, IntPtr instancePtr, char * pchFile)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_FileDelete")]
STUB(bool, SteamAPI_ISteamRemoteStorage_FileDelete, 0, IntPtr instancePtr, char * pchFile)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_FileShare")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_FileShare, 0, IntPtr instancePtr, char * pchFile)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_SetSyncPlatforms")]
STUB(bool, SteamAPI_ISteamRemoteStorage_SetSyncPlatforms, 0, IntPtr instancePtr, char * pchFile, ERemoteStoragePlatform eRemoteStoragePlatform)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen, 0, IntPtr instancePtr, char * pchFile)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk")]
STUB(bool, SteamAPI_ISteamRemoteStorage_FileWriteStreamWriteChunk, 0, IntPtr instancePtr, UGCFileWriteStreamHandle_t writeHandle, byte* pvData, int cubData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_FileWriteStreamClose")]
STUB(bool, SteamAPI_ISteamRemoteStorage_FileWriteStreamClose, 0, IntPtr instancePtr, UGCFileWriteStreamHandle_t writeHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel")]
STUB(bool, SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel, 0, IntPtr instancePtr, UGCFileWriteStreamHandle_t writeHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_FileExists")]
STUB(bool, SteamAPI_ISteamRemoteStorage_FileExists, 0, IntPtr instancePtr, char * pchFile)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_FilePersisted")]
STUB(bool, SteamAPI_ISteamRemoteStorage_FilePersisted, 0, IntPtr instancePtr, char * pchFile)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_GetFileSize")]
STUB(int, SteamAPI_ISteamRemoteStorage_GetFileSize, 0, IntPtr instancePtr, char * pchFile)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_GetFileTimestamp")]
STUB(long, SteamAPI_ISteamRemoteStorage_GetFileTimestamp, 0, IntPtr instancePtr, char * pchFile)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_GetSyncPlatforms")]
STUB(ERemoteStoragePlatform, SteamAPI_ISteamRemoteStorage_GetSyncPlatforms, 0, IntPtr instancePtr, char * pchFile)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_GetFileCount")]
STUB(int, SteamAPI_ISteamRemoteStorage_GetFileCount, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_GetFileNameAndSize")]
STUB(IntPtr, SteamAPI_ISteamRemoteStorage_GetFileNameAndSize, 0, IntPtr instancePtr, int iFile, out int pnFileSizeInBytes)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_GetQuota")]
STUB(bool, SteamAPI_ISteamRemoteStorage_GetQuota, 0, IntPtr instancePtr, out ulong pnTotalBytes, out ulong puAvailableBytes)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount")]
STUB(bool, SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp")]
STUB(bool, SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp")]
STUB(void, SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp, 0, IntPtr instancePtr, char bEnabled)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_UGCDownload")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_UGCDownload, 0, IntPtr instancePtr, UGCHandle_t hContent, uint unPriority)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_GetUGCDownloadProgress")]
STUB(bool, SteamAPI_ISteamRemoteStorage_GetUGCDownloadProgress, 0, IntPtr instancePtr, UGCHandle_t hContent, out int pnBytesDownloaded, out int pnBytesExpected)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_GetUGCDetails")]
STUB(bool, SteamAPI_ISteamRemoteStorage_GetUGCDetails, 0, IntPtr instancePtr, UGCHandle_t hContent, out AppId_t pnAppID, out IntPtr ppchName, out int pnFileSizeInBytes, out CSteamID pSteamIDOwner)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_UGCRead")]
STUB(int, SteamAPI_ISteamRemoteStorage_UGCRead, 0, IntPtr instancePtr, UGCHandle_t hContent, byte* pvData, int cubDataToRead, uint cOffset, EUGCReadAction eAction)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_GetCachedUGCCount")]
STUB(int, SteamAPI_ISteamRemoteStorage_GetCachedUGCCount, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle, 0, IntPtr instancePtr, int iCachedContent)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_PublishWorkshopFile")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_PublishWorkshopFile, 0, IntPtr instancePtr, char * pchFile, char * pchPreviewFile, AppId_t nConsumerAppId, char * pchTitle, char * pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, IntPtr pTags, EWorkshopFileType eWorkshopFileType)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest, 0, IntPtr instancePtr, PublishedFileId_t unPublishedFileId)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile")]
STUB(bool, SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile, 0, IntPtr instancePtr, PublishedFileUpdateHandle_t updateHandle, char * pchFile)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile")]
STUB(bool, SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile, 0, IntPtr instancePtr, PublishedFileUpdateHandle_t updateHandle, char * pchPreviewFile)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle")]
STUB(bool, SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle, 0, IntPtr instancePtr, PublishedFileUpdateHandle_t updateHandle, char * pchTitle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription")]
STUB(bool, SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription, 0, IntPtr instancePtr, PublishedFileUpdateHandle_t updateHandle, char * pchDescription)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_UpdatePublishedFileVisibility")]
STUB(bool, SteamAPI_ISteamRemoteStorage_UpdatePublishedFileVisibility, 0, IntPtr instancePtr, PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTags")]
STUB(bool, SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTags, 0, IntPtr instancePtr, PublishedFileUpdateHandle_t updateHandle, IntPtr pTags)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate, 0, IntPtr instancePtr, PublishedFileUpdateHandle_t updateHandle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails, 0, IntPtr instancePtr, PublishedFileId_t unPublishedFileId, uint unMaxSecondsOld)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_DeletePublishedFile")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_DeletePublishedFile, 0, IntPtr instancePtr, PublishedFileId_t unPublishedFileId)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles, 0, IntPtr instancePtr, uint unStartIndex)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_SubscribePublishedFile")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_SubscribePublishedFile, 0, IntPtr instancePtr, PublishedFileId_t unPublishedFileId)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles, 0, IntPtr instancePtr, uint unStartIndex)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile, 0, IntPtr instancePtr, PublishedFileId_t unPublishedFileId)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription")]
STUB(bool, SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription, 0, IntPtr instancePtr, PublishedFileUpdateHandle_t updateHandle, char * pchChangeDescription)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails, 0, IntPtr instancePtr, PublishedFileId_t unPublishedFileId)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote, 0, IntPtr instancePtr, PublishedFileId_t unPublishedFileId, char bVoteUp)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails, 0, IntPtr instancePtr, PublishedFileId_t unPublishedFileId)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles, 0, IntPtr instancePtr, CSteamID steamId, uint unStartIndex, IntPtr pRequiredTags, IntPtr pExcludedTags)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_PublishVideo")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_PublishVideo, 0, IntPtr instancePtr, EWorkshopVideoProvider eVideoProvider, char * pchVideoAccount, char * pchVideoIdentifier, char * pchPreviewFile, AppId_t nConsumerAppId, char * pchTitle, char * pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, IntPtr pTags)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_SetUserPublishedFileAction")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_SetUserPublishedFileAction, 0, IntPtr instancePtr, PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_EnumeratePublishedFilesByUserAction")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_EnumeratePublishedFilesByUserAction, 0, IntPtr instancePtr, EWorkshopFileAction eAction, uint unStartIndex)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_EnumeratePublishedWorkshopFiles")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_EnumeratePublishedWorkshopFiles, 0, IntPtr instancePtr, EWorkshopEnumerationType eEnumerationType, uint unStartIndex, uint unCount, uint unDays, IntPtr pTags, IntPtr pUserTags)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation")]
STUB(ulong, SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation, 0, IntPtr instancePtr, UGCHandle_t hContent, char * pchLocation, uint unPriority)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_GetLocalFileChangeCount")]
STUB(int, SteamAPI_ISteamRemoteStorage_GetLocalFileChangeCount, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_GetLocalFileChange")]
STUB(IntPtr, SteamAPI_ISteamRemoteStorage_GetLocalFileChange, 0, IntPtr instancePtr, int iFile, out ERemoteStorageLocalFileChange pEChangeType, out ERemoteStorageFilePathType pEFilePathType)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_BeginFileWriteBatch")]
STUB(bool, SteamAPI_ISteamRemoteStorage_BeginFileWriteBatch, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamRemoteStorage_EndFileWriteBatch")]
STUB(bool, SteamAPI_ISteamRemoteStorage_EndFileWriteBatch, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamScreenshots_WriteScreenshot")]
STUB(uint, SteamAPI_ISteamScreenshots_WriteScreenshot, 0, IntPtr instancePtr, byte* pubRGB, uint cubRGB, int nWidth, int nHeight)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamScreenshots_AddScreenshotToLibrary")]
STUB(uint, SteamAPI_ISteamScreenshots_AddScreenshotToLibrary, 0, IntPtr instancePtr, char * pchFilename, char * pchThumbnailFilename, int nWidth, int nHeight)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamScreenshots_TriggerScreenshot")]
STUB(void, SteamAPI_ISteamScreenshots_TriggerScreenshot, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamScreenshots_HookScreenshots")]
STUB(void, SteamAPI_ISteamScreenshots_HookScreenshots, 0, IntPtr instancePtr, char bHook)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamScreenshots_SetLocation")]
STUB(bool, SteamAPI_ISteamScreenshots_SetLocation, 0, IntPtr instancePtr, ScreenshotHandle hScreenshot, char * pchLocation)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamScreenshots_TagUser")]
STUB(bool, SteamAPI_ISteamScreenshots_TagUser, 0, IntPtr instancePtr, ScreenshotHandle hScreenshot, CSteamID steamID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamScreenshots_TagPublishedFile")]
STUB(bool, SteamAPI_ISteamScreenshots_TagPublishedFile, 0, IntPtr instancePtr, ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamScreenshots_IsScreenshotsHooked")]
STUB(bool, SteamAPI_ISteamScreenshots_IsScreenshotsHooked, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamScreenshots_AddVRScreenshotToLibrary")]
STUB(uint, SteamAPI_ISteamScreenshots_AddVRScreenshotToLibrary, 0, IntPtr instancePtr, EVRScreenshotType eType, char * pchFilename, char * pchVRFilename)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_CreateQueryUserUGCRequest")]
STUB(ulong, SteamAPI_ISteamUGC_CreateQueryUserUGCRequest, 0, IntPtr instancePtr, AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint unPage)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_CreateQueryAllUGCRequestPage")]
STUB(ulong, SteamAPI_ISteamUGC_CreateQueryAllUGCRequestPage, 0, IntPtr instancePtr, EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint unPage)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor")]
STUB(ulong, SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor, 0, IntPtr instancePtr, EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, char * pchCursor)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_CreateQueryUGCDetailsRequest")]
STUB(ulong, SteamAPI_ISteamUGC_CreateQueryUGCDetailsRequest, 0, IntPtr instancePtr, PublishedFileId_t* pvecPublishedFileID, uint unNumPublishedFileIDs)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SendQueryUGCRequest")]
STUB(ulong, SteamAPI_ISteamUGC_SendQueryUGCRequest, 0, IntPtr instancePtr, UGCQueryHandle_t handle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetQueryUGCResult")]
STUB(bool, SteamAPI_ISteamUGC_GetQueryUGCResult, 0, IntPtr instancePtr, UGCQueryHandle_t handle, uint index, out SteamUGCDetails_t pDetails)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetQueryUGCNumTags")]
STUB(uint, SteamAPI_ISteamUGC_GetQueryUGCNumTags, 0, IntPtr instancePtr, UGCQueryHandle_t handle, uint index)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetQueryUGCTag")]
STUB(bool, SteamAPI_ISteamUGC_GetQueryUGCTag, 0, IntPtr instancePtr, UGCQueryHandle_t handle, uint index, uint indexTag, IntPtr pchValue, uint cchValueSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetQueryUGCTagDisplayName")]
STUB(bool, SteamAPI_ISteamUGC_GetQueryUGCTagDisplayName, 0, IntPtr instancePtr, UGCQueryHandle_t handle, uint index, uint indexTag, IntPtr pchValue, uint cchValueSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetQueryUGCPreviewURL")]
STUB(bool, SteamAPI_ISteamUGC_GetQueryUGCPreviewURL, 0, IntPtr instancePtr, UGCQueryHandle_t handle, uint index, IntPtr pchURL, uint cchURLSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetQueryUGCMetadata")]
STUB(bool, SteamAPI_ISteamUGC_GetQueryUGCMetadata, 0, IntPtr instancePtr, UGCQueryHandle_t handle, uint index, IntPtr pchMetadata, uint cchMetadatasize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetQueryUGCChildren")]
STUB(bool, SteamAPI_ISteamUGC_GetQueryUGCChildren, 0, IntPtr instancePtr, UGCQueryHandle_t handle, uint index, PublishedFileId_t* pvecPublishedFileID, uint cMaxEntries)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetQueryUGCStatistic")]
STUB(bool, SteamAPI_ISteamUGC_GetQueryUGCStatistic, 0, IntPtr instancePtr, UGCQueryHandle_t handle, uint index, EItemStatistic eStatType, out ulong pStatValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetQueryUGCNumAdditionalPreviews")]
STUB(uint, SteamAPI_ISteamUGC_GetQueryUGCNumAdditionalPreviews, 0, IntPtr instancePtr, UGCQueryHandle_t handle, uint index)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetQueryUGCAdditionalPreview")]
STUB(bool, SteamAPI_ISteamUGC_GetQueryUGCAdditionalPreview, 0, IntPtr instancePtr, UGCQueryHandle_t handle, uint index, uint previewIndex, IntPtr pchURLOrVideoID, uint cchURLSize, IntPtr pchOriginalFileName, uint cchOriginalFileNameSize, out EItemPreviewType pPreviewType)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetQueryUGCNumKeyValueTags")]
STUB(uint, SteamAPI_ISteamUGC_GetQueryUGCNumKeyValueTags, 0, IntPtr instancePtr, UGCQueryHandle_t handle, uint index)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetQueryUGCKeyValueTag")]
STUB(bool, SteamAPI_ISteamUGC_GetQueryUGCKeyValueTag, 0, IntPtr instancePtr, UGCQueryHandle_t handle, uint index, uint keyValueTagIndex, IntPtr pchKey, uint cchKeySize, IntPtr pchValue, uint cchValueSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetQueryFirstUGCKeyValueTag")]
STUB(bool, SteamAPI_ISteamUGC_GetQueryFirstUGCKeyValueTag, 0, IntPtr instancePtr, UGCQueryHandle_t handle, uint index, char * pchKey, IntPtr pchValue, uint cchValueSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_ReleaseQueryUGCRequest")]
STUB(bool, SteamAPI_ISteamUGC_ReleaseQueryUGCRequest, 0, IntPtr instancePtr, UGCQueryHandle_t handle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_AddRequiredTag")]
STUB(bool, SteamAPI_ISteamUGC_AddRequiredTag, 0, IntPtr instancePtr, UGCQueryHandle_t handle, char * pTagName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_AddRequiredTagGroup")]
STUB(bool, SteamAPI_ISteamUGC_AddRequiredTagGroup, 0, IntPtr instancePtr, UGCQueryHandle_t handle, IntPtr pTagGroups)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_AddExcludedTag")]
STUB(bool, SteamAPI_ISteamUGC_AddExcludedTag, 0, IntPtr instancePtr, UGCQueryHandle_t handle, char * pTagName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetReturnOnlyIDs")]
STUB(bool, SteamAPI_ISteamUGC_SetReturnOnlyIDs, 0, IntPtr instancePtr, UGCQueryHandle_t handle, char bReturnOnlyIDs)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetReturnKeyValueTags")]
STUB(bool, SteamAPI_ISteamUGC_SetReturnKeyValueTags, 0, IntPtr instancePtr, UGCQueryHandle_t handle, char bReturnKeyValueTags)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetReturnLongDescription")]
STUB(bool, SteamAPI_ISteamUGC_SetReturnLongDescription, 0, IntPtr instancePtr, UGCQueryHandle_t handle, char bReturnLongDescription)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetReturnMetadata")]
STUB(bool, SteamAPI_ISteamUGC_SetReturnMetadata, 0, IntPtr instancePtr, UGCQueryHandle_t handle, char bReturnMetadata)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetReturnChildren")]
STUB(bool, SteamAPI_ISteamUGC_SetReturnChildren, 0, IntPtr instancePtr, UGCQueryHandle_t handle, char bReturnChildren)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetReturnAdditionalPreviews")]
STUB(bool, SteamAPI_ISteamUGC_SetReturnAdditionalPreviews, 0, IntPtr instancePtr, UGCQueryHandle_t handle, char bReturnAdditionalPreviews)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetReturnTotalOnly")]
STUB(bool, SteamAPI_ISteamUGC_SetReturnTotalOnly, 0, IntPtr instancePtr, UGCQueryHandle_t handle, char bReturnTotalOnly)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetReturnPlaytimeStats")]
STUB(bool, SteamAPI_ISteamUGC_SetReturnPlaytimeStats, 0, IntPtr instancePtr, UGCQueryHandle_t handle, uint unDays)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetLanguage")]
STUB(bool, SteamAPI_ISteamUGC_SetLanguage, 0, IntPtr instancePtr, UGCQueryHandle_t handle, char * pchLanguage)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetAllowCachedResponse")]
STUB(bool, SteamAPI_ISteamUGC_SetAllowCachedResponse, 0, IntPtr instancePtr, UGCQueryHandle_t handle, uint unMaxAgeSeconds)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetCloudFileNameFilter")]
STUB(bool, SteamAPI_ISteamUGC_SetCloudFileNameFilter, 0, IntPtr instancePtr, UGCQueryHandle_t handle, char * pMatchCloudFileName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetMatchAnyTag")]
STUB(bool, SteamAPI_ISteamUGC_SetMatchAnyTag, 0, IntPtr instancePtr, UGCQueryHandle_t handle, char bMatchAnyTag)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetSearchText")]
STUB(bool, SteamAPI_ISteamUGC_SetSearchText, 0, IntPtr instancePtr, UGCQueryHandle_t handle, char * pSearchText)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetRankedByTrendDays")]
STUB(bool, SteamAPI_ISteamUGC_SetRankedByTrendDays, 0, IntPtr instancePtr, UGCQueryHandle_t handle, uint unDays)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetTimeCreatedDateRange")]
STUB(bool, SteamAPI_ISteamUGC_SetTimeCreatedDateRange, 0, IntPtr instancePtr, UGCQueryHandle_t handle, uint rtStart, uint rtEnd)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetTimeUpdatedDateRange")]
STUB(bool, SteamAPI_ISteamUGC_SetTimeUpdatedDateRange, 0, IntPtr instancePtr, UGCQueryHandle_t handle, uint rtStart, uint rtEnd)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_AddRequiredKeyValueTag")]
STUB(bool, SteamAPI_ISteamUGC_AddRequiredKeyValueTag, 0, IntPtr instancePtr, UGCQueryHandle_t handle, char * pKey, char * pValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_RequestUGCDetails")]
STUB(ulong, SteamAPI_ISteamUGC_RequestUGCDetails, 0, IntPtr instancePtr, PublishedFileId_t nPublishedFileID, uint unMaxAgeSeconds)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_CreateItem")]
STUB(ulong, SteamAPI_ISteamUGC_CreateItem, 0, IntPtr instancePtr, AppId_t nConsumerAppId, EWorkshopFileType eFileType)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_StartItemUpdate")]
STUB(ulong, SteamAPI_ISteamUGC_StartItemUpdate, 0, IntPtr instancePtr, AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetItemTitle")]
STUB(bool, SteamAPI_ISteamUGC_SetItemTitle, 0, IntPtr instancePtr, UGCUpdateHandle_t handle, char * pchTitle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetItemDescription")]
STUB(bool, SteamAPI_ISteamUGC_SetItemDescription, 0, IntPtr instancePtr, UGCUpdateHandle_t handle, char * pchDescription)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetItemUpdateLanguage")]
STUB(bool, SteamAPI_ISteamUGC_SetItemUpdateLanguage, 0, IntPtr instancePtr, UGCUpdateHandle_t handle, char * pchLanguage)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetItemMetadata")]
STUB(bool, SteamAPI_ISteamUGC_SetItemMetadata, 0, IntPtr instancePtr, UGCUpdateHandle_t handle, char * pchMetaData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetItemVisibility")]
STUB(bool, SteamAPI_ISteamUGC_SetItemVisibility, 0, IntPtr instancePtr, UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetItemTags")]
STUB(bool, SteamAPI_ISteamUGC_SetItemTags, 0, IntPtr instancePtr, UGCUpdateHandle_t updateHandle, IntPtr pTags)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetItemContent")]
STUB(bool, SteamAPI_ISteamUGC_SetItemContent, 0, IntPtr instancePtr, UGCUpdateHandle_t handle, char * pszContentFolder)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetItemPreview")]
STUB(bool, SteamAPI_ISteamUGC_SetItemPreview, 0, IntPtr instancePtr, UGCUpdateHandle_t handle, char * pszPreviewFile)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetAllowLegacyUpload")]
STUB(bool, SteamAPI_ISteamUGC_SetAllowLegacyUpload, 0, IntPtr instancePtr, UGCUpdateHandle_t handle, char bAllowLegacyUpload)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_RemoveAllItemKeyValueTags")]
STUB(bool, SteamAPI_ISteamUGC_RemoveAllItemKeyValueTags, 0, IntPtr instancePtr, UGCUpdateHandle_t handle)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_RemoveItemKeyValueTags")]
STUB(bool, SteamAPI_ISteamUGC_RemoveItemKeyValueTags, 0, IntPtr instancePtr, UGCUpdateHandle_t handle, char * pchKey)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_AddItemKeyValueTag")]
STUB(bool, SteamAPI_ISteamUGC_AddItemKeyValueTag, 0, IntPtr instancePtr, UGCUpdateHandle_t handle, char * pchKey, char * pchValue)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_AddItemPreviewFile")]
STUB(bool, SteamAPI_ISteamUGC_AddItemPreviewFile, 0, IntPtr instancePtr, UGCUpdateHandle_t handle, char * pszPreviewFile, EItemPreviewType type)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_AddItemPreviewVideo")]
STUB(bool, SteamAPI_ISteamUGC_AddItemPreviewVideo, 0, IntPtr instancePtr, UGCUpdateHandle_t handle, char * pszVideoID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_UpdateItemPreviewFile")]
STUB(bool, SteamAPI_ISteamUGC_UpdateItemPreviewFile, 0, IntPtr instancePtr, UGCUpdateHandle_t handle, uint index, char * pszPreviewFile)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_UpdateItemPreviewVideo")]
STUB(bool, SteamAPI_ISteamUGC_UpdateItemPreviewVideo, 0, IntPtr instancePtr, UGCUpdateHandle_t handle, uint index, char * pszVideoID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_RemoveItemPreview")]
STUB(bool, SteamAPI_ISteamUGC_RemoveItemPreview, 0, IntPtr instancePtr, UGCUpdateHandle_t handle, uint index)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SubmitItemUpdate")]
STUB(ulong, SteamAPI_ISteamUGC_SubmitItemUpdate, 0, IntPtr instancePtr, UGCUpdateHandle_t handle, char * pchChangeNote)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetItemUpdateProgress")]
STUB(EItemUpdateStatus, SteamAPI_ISteamUGC_GetItemUpdateProgress, 0, IntPtr instancePtr, UGCUpdateHandle_t handle, out ulong punBytesProcessed, out ulong punBytesTotal)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SetUserItemVote")]
STUB(ulong, SteamAPI_ISteamUGC_SetUserItemVote, 0, IntPtr instancePtr, PublishedFileId_t nPublishedFileID, char bVoteUp)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetUserItemVote")]
STUB(ulong, SteamAPI_ISteamUGC_GetUserItemVote, 0, IntPtr instancePtr, PublishedFileId_t nPublishedFileID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_AddItemToFavorites")]
STUB(ulong, SteamAPI_ISteamUGC_AddItemToFavorites, 0, IntPtr instancePtr, AppId_t nAppId, PublishedFileId_t nPublishedFileID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_RemoveItemFromFavorites")]
STUB(ulong, SteamAPI_ISteamUGC_RemoveItemFromFavorites, 0, IntPtr instancePtr, AppId_t nAppId, PublishedFileId_t nPublishedFileID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SubscribeItem")]
STUB(ulong, SteamAPI_ISteamUGC_SubscribeItem, 0, IntPtr instancePtr, PublishedFileId_t nPublishedFileID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_UnsubscribeItem")]
STUB(ulong, SteamAPI_ISteamUGC_UnsubscribeItem, 0, IntPtr instancePtr, PublishedFileId_t nPublishedFileID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetNumSubscribedItems")]
STUB(uint, SteamAPI_ISteamUGC_GetNumSubscribedItems, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetSubscribedItems")]
STUB(uint, SteamAPI_ISteamUGC_GetSubscribedItems, 0, IntPtr instancePtr, PublishedFileId_t* pvecPublishedFileID, uint cMaxEntries)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetItemState")]
STUB(uint, SteamAPI_ISteamUGC_GetItemState, 0, IntPtr instancePtr, PublishedFileId_t nPublishedFileID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetItemInstallInfo")]
STUB(bool, SteamAPI_ISteamUGC_GetItemInstallInfo, 0, IntPtr instancePtr, PublishedFileId_t nPublishedFileID, out ulong punSizeOnDisk, IntPtr pchFolder, uint cchFolderSize, out uint punTimeStamp)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetItemDownloadInfo")]
STUB(bool, SteamAPI_ISteamUGC_GetItemDownloadInfo, 0, IntPtr instancePtr, PublishedFileId_t nPublishedFileID, out ulong punBytesDownloaded, out ulong punBytesTotal)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_DownloadItem")]
STUB(bool, SteamAPI_ISteamUGC_DownloadItem, 0, IntPtr instancePtr, PublishedFileId_t nPublishedFileID, char bHighPriority)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_BInitWorkshopForGameServer")]
STUB(bool, SteamAPI_ISteamUGC_BInitWorkshopForGameServer, 0, IntPtr instancePtr, DepotId_t unWorkshopDepotID, char * pszFolder)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_SuspendDownloads")]
STUB(void, SteamAPI_ISteamUGC_SuspendDownloads, 0, IntPtr instancePtr, char bSuspend)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_StartPlaytimeTracking")]
STUB(ulong, SteamAPI_ISteamUGC_StartPlaytimeTracking, 0, IntPtr instancePtr, PublishedFileId_t* pvecPublishedFileID, uint unNumPublishedFileIDs)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_StopPlaytimeTracking")]
STUB(ulong, SteamAPI_ISteamUGC_StopPlaytimeTracking, 0, IntPtr instancePtr, PublishedFileId_t* pvecPublishedFileID, uint unNumPublishedFileIDs)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_StopPlaytimeTrackingForAllItems")]
STUB(ulong, SteamAPI_ISteamUGC_StopPlaytimeTrackingForAllItems, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_AddDependency")]
STUB(ulong, SteamAPI_ISteamUGC_AddDependency, 0, IntPtr instancePtr, PublishedFileId_t nParentPublishedFileID, PublishedFileId_t nChildPublishedFileID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_RemoveDependency")]
STUB(ulong, SteamAPI_ISteamUGC_RemoveDependency, 0, IntPtr instancePtr, PublishedFileId_t nParentPublishedFileID, PublishedFileId_t nChildPublishedFileID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_AddAppDependency")]
STUB(ulong, SteamAPI_ISteamUGC_AddAppDependency, 0, IntPtr instancePtr, PublishedFileId_t nPublishedFileID, AppId_t nAppID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_RemoveAppDependency")]
STUB(ulong, SteamAPI_ISteamUGC_RemoveAppDependency, 0, IntPtr instancePtr, PublishedFileId_t nPublishedFileID, AppId_t nAppID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetAppDependencies")]
STUB(ulong, SteamAPI_ISteamUGC_GetAppDependencies, 0, IntPtr instancePtr, PublishedFileId_t nPublishedFileID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_DeleteItem")]
STUB(ulong, SteamAPI_ISteamUGC_DeleteItem, 0, IntPtr instancePtr, PublishedFileId_t nPublishedFileID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_ShowWorkshopEULA")]
STUB(bool, SteamAPI_ISteamUGC_ShowWorkshopEULA, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUGC_GetWorkshopEULAStatus")]
STUB(ulong, SteamAPI_ISteamUGC_GetWorkshopEULAStatus, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_GetHSteamUser")]
STUB(int, SteamAPI_ISteamUser_GetHSteamUser, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_BLoggedOn")]
STUB(bool, SteamAPI_ISteamUser_BLoggedOn, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_GetSteamID")]
STUB(ulong, SteamAPI_ISteamUser_GetSteamID, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_InitiateGameConnection_DEPRECATED")]
STUB(int, SteamAPI_ISteamUser_InitiateGameConnection_DEPRECATED, 0, IntPtr instancePtr, byte* pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint unIPServer, ushort usPortServer, char bSecure)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_TerminateGameConnection_DEPRECATED")]
STUB(void, SteamAPI_ISteamUser_TerminateGameConnection_DEPRECATED, 0, IntPtr instancePtr, uint unIPServer, ushort usPortServer)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_TrackAppUsageEvent")]
STUB(void, SteamAPI_ISteamUser_TrackAppUsageEvent, 0, IntPtr instancePtr, CGameID gameID, int eAppUsageEvent, char * pchExtraInfo)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_GetUserDataFolder")]
STUB(bool, SteamAPI_ISteamUser_GetUserDataFolder, 0, IntPtr instancePtr, IntPtr pchBuffer, int cubBuffer)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_StartVoiceRecording")]
STUB(void, SteamAPI_ISteamUser_StartVoiceRecording, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_StopVoiceRecording")]
STUB(void, SteamAPI_ISteamUser_StopVoiceRecording, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_GetAvailableVoice")]
STUB(EVoiceResult, SteamAPI_ISteamUser_GetAvailableVoice, 0, IntPtr instancePtr, out uint pcbCompressed, IntPtr pcbUncompressed_Deprecated, uint nUncompressedVoiceDesiredSampleRate_Deprecated)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_GetVoice")]
STUB(EVoiceResult, SteamAPI_ISteamUser_GetVoice, 0, IntPtr instancePtr, char bWantCompressed, byte* pDestBuffer, uint cbDestBufferSize, out uint nBytesWritten, char bWantUncompressed_Deprecated, IntPtr pUncompressedDestBuffer_Deprecated, uint cbUncompressedDestBufferSize_Deprecated, IntPtr nUncompressBytesWritten_Deprecated, uint nUncompressedVoiceDesiredSampleRate_Deprecated)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_DecompressVoice")]
STUB(EVoiceResult, SteamAPI_ISteamUser_DecompressVoice, 0, IntPtr instancePtr, byte* pCompressed, uint cbCompressed, byte* pDestBuffer, uint cbDestBufferSize, out uint nBytesWritten, uint nDesiredSampleRate)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_GetVoiceOptimalSampleRate")]
STUB(uint, SteamAPI_ISteamUser_GetVoiceOptimalSampleRate, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_GetAuthSessionTicket")]
STUB(uint, SteamAPI_ISteamUser_GetAuthSessionTicket, 0, IntPtr instancePtr, byte* pTicket, int cbMaxTicket, out uint pcbTicket)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_BeginAuthSession")]
STUB(EBeginAuthSessionResult, SteamAPI_ISteamUser_BeginAuthSession, 0, IntPtr instancePtr, byte* pAuthTicket, int cbAuthTicket, CSteamID steamID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_EndAuthSession")]
STUB(void, SteamAPI_ISteamUser_EndAuthSession, 0, IntPtr instancePtr, CSteamID steamID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_CancelAuthTicket")]
STUB(void, SteamAPI_ISteamUser_CancelAuthTicket, 0, IntPtr instancePtr, HAuthTicket hAuthTicket)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_UserHasLicenseForApp")]
STUB(EUserHasLicenseForAppResult, SteamAPI_ISteamUser_UserHasLicenseForApp, 0, IntPtr instancePtr, CSteamID steamID, AppId_t appID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_BIsBehindNAT")]
STUB(bool, SteamAPI_ISteamUser_BIsBehindNAT, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_AdvertiseGame")]
STUB(void, SteamAPI_ISteamUser_AdvertiseGame, 0, IntPtr instancePtr, CSteamID steamIDGameServer, uint unIPServer, ushort usPortServer)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_RequestEncryptedAppTicket")]
STUB(ulong, SteamAPI_ISteamUser_RequestEncryptedAppTicket, 0, IntPtr instancePtr, byte* pDataToInclude, int cbDataToInclude)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_GetEncryptedAppTicket")]
STUB(bool, SteamAPI_ISteamUser_GetEncryptedAppTicket, 0, IntPtr instancePtr, byte* pTicket, int cbMaxTicket, out uint pcbTicket)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_GetGameBadgeLevel")]
STUB(int, SteamAPI_ISteamUser_GetGameBadgeLevel, 0, IntPtr instancePtr, int nSeries, char bFoil)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_GetPlayerSteamLevel")]
STUB(int, SteamAPI_ISteamUser_GetPlayerSteamLevel, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_RequestStoreAuthURL")]
STUB(ulong, SteamAPI_ISteamUser_RequestStoreAuthURL, 0, IntPtr instancePtr, char * pchRedirectURL)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_BIsPhoneVerified")]
STUB(bool, SteamAPI_ISteamUser_BIsPhoneVerified, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_BIsTwoFactorEnabled")]
STUB(bool, SteamAPI_ISteamUser_BIsTwoFactorEnabled, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_BIsPhoneIdentifying")]
STUB(bool, SteamAPI_ISteamUser_BIsPhoneIdentifying, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_BIsPhoneRequiringVerification")]
STUB(bool, SteamAPI_ISteamUser_BIsPhoneRequiringVerification, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_GetMarketEligibility")]
STUB(ulong, SteamAPI_ISteamUser_GetMarketEligibility, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_GetDurationControl")]
STUB(ulong, SteamAPI_ISteamUser_GetDurationControl, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUser_BSetDurationControlOnlineState")]
STUB(bool, SteamAPI_ISteamUser_BSetDurationControlOnlineState, 0, IntPtr instancePtr, EDurationControlOnlineState eNewState)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_RequestCurrentStats")]
STUB(bool, SteamAPI_ISteamUserStats_RequestCurrentStats, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetStatInt32")]
STUB(bool, SteamAPI_ISteamUserStats_GetStatInt32, 0, IntPtr instancePtr, char * pchName, out int pData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetStatFloat")]
STUB(bool, SteamAPI_ISteamUserStats_GetStatFloat, 0, IntPtr instancePtr, char * pchName, out float pData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_SetStatInt32")]
STUB(bool, SteamAPI_ISteamUserStats_SetStatInt32, 0, IntPtr instancePtr, char * pchName, int nData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_SetStatFloat")]
STUB(bool, SteamAPI_ISteamUserStats_SetStatFloat, 0, IntPtr instancePtr, char * pchName, float fData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_UpdateAvgRateStat")]
STUB(bool, SteamAPI_ISteamUserStats_UpdateAvgRateStat, 0, IntPtr instancePtr, char * pchName, float flCountThisSession, double dSessionLength)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetAchievement")]
STUB(bool, SteamAPI_ISteamUserStats_GetAchievement, 0, IntPtr instancePtr, char * pchName, out bool pbAchieved)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_SetAchievement")]
STUB(bool, SteamAPI_ISteamUserStats_SetAchievement, 0, IntPtr instancePtr, char * pchName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_ClearAchievement")]
STUB(bool, SteamAPI_ISteamUserStats_ClearAchievement, 0, IntPtr instancePtr, char * pchName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetAchievementAndUnlockTime")]
STUB(bool, SteamAPI_ISteamUserStats_GetAchievementAndUnlockTime, 0, IntPtr instancePtr, char * pchName, out bool pbAchieved, out uint punUnlockTime)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_StoreStats")]
STUB(bool, SteamAPI_ISteamUserStats_StoreStats, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetAchievementIcon")]
STUB(int, SteamAPI_ISteamUserStats_GetAchievementIcon, 0, IntPtr instancePtr, char * pchName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute")]
STUB(IntPtr, SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute, 0, IntPtr instancePtr, char * pchName, char * pchKey)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_IndicateAchievementProgress")]
STUB(bool, SteamAPI_ISteamUserStats_IndicateAchievementProgress, 0, IntPtr instancePtr, char * pchName, uint nCurProgress, uint nMaxProgress)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetNumAchievements")]
STUB(uint, SteamAPI_ISteamUserStats_GetNumAchievements, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetAchievementName")]
STUB(IntPtr, SteamAPI_ISteamUserStats_GetAchievementName, 0, IntPtr instancePtr, uint iAchievement)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_RequestUserStats")]
STUB(ulong, SteamAPI_ISteamUserStats_RequestUserStats, 0, IntPtr instancePtr, CSteamID steamIDUser)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetUserStatInt32")]
STUB(bool, SteamAPI_ISteamUserStats_GetUserStatInt32, 0, IntPtr instancePtr, CSteamID steamIDUser, char * pchName, out int pData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetUserStatFloat")]
STUB(bool, SteamAPI_ISteamUserStats_GetUserStatFloat, 0, IntPtr instancePtr, CSteamID steamIDUser, char * pchName, out float pData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetUserAchievement")]
STUB(bool, SteamAPI_ISteamUserStats_GetUserAchievement, 0, IntPtr instancePtr, CSteamID steamIDUser, char * pchName, out bool pbAchieved)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetUserAchievementAndUnlockTime")]
STUB(bool, SteamAPI_ISteamUserStats_GetUserAchievementAndUnlockTime, 0, IntPtr instancePtr, CSteamID steamIDUser, char * pchName, out bool pbAchieved, out uint punUnlockTime)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_ResetAllStats")]
STUB(bool, SteamAPI_ISteamUserStats_ResetAllStats, 0, IntPtr instancePtr, char bAchievementsToo)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_FindOrCreateLeaderboard")]
STUB(ulong, SteamAPI_ISteamUserStats_FindOrCreateLeaderboard, 0, IntPtr instancePtr, char * pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_FindLeaderboard")]
STUB(ulong, SteamAPI_ISteamUserStats_FindLeaderboard, 0, IntPtr instancePtr, char * pchLeaderboardName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetLeaderboardName")]
STUB(IntPtr, SteamAPI_ISteamUserStats_GetLeaderboardName, 0, IntPtr instancePtr, SteamLeaderboard_t hSteamLeaderboard)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetLeaderboardEntryCount")]
STUB(int, SteamAPI_ISteamUserStats_GetLeaderboardEntryCount, 0, IntPtr instancePtr, SteamLeaderboard_t hSteamLeaderboard)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetLeaderboardSortMethod")]
STUB(ELeaderboardSortMethod, SteamAPI_ISteamUserStats_GetLeaderboardSortMethod, 0, IntPtr instancePtr, SteamLeaderboard_t hSteamLeaderboard)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetLeaderboardDisplayType")]
STUB(ELeaderboardDisplayType, SteamAPI_ISteamUserStats_GetLeaderboardDisplayType, 0, IntPtr instancePtr, SteamLeaderboard_t hSteamLeaderboard)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_DownloadLeaderboardEntries")]
STUB(ulong, SteamAPI_ISteamUserStats_DownloadLeaderboardEntries, 0, IntPtr instancePtr, SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_DownloadLeaderboardEntriesForUsers")]
STUB(ulong, SteamAPI_ISteamUserStats_DownloadLeaderboardEntriesForUsers, 0, IntPtr instancePtr, SteamLeaderboard_t hSteamLeaderboard, CSteamID* prgUsers, int cUsers)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry")]
STUB(bool, SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry, 0, IntPtr instancePtr, SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, out LeaderboardEntry_t pLeaderboardEntry, int* pDetails, int cDetailsMax)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_UploadLeaderboardScore")]
STUB(ulong, SteamAPI_ISteamUserStats_UploadLeaderboardScore, 0, IntPtr instancePtr, SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int nScore, int* pScoreDetails, int cScoreDetailsCount)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_AttachLeaderboardUGC")]
STUB(ulong, SteamAPI_ISteamUserStats_AttachLeaderboardUGC, 0, IntPtr instancePtr, SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers")]
STUB(ulong, SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages")]
STUB(ulong, SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetMostAchievedAchievementInfo")]
STUB(int, SteamAPI_ISteamUserStats_GetMostAchievedAchievementInfo, 0, IntPtr instancePtr, IntPtr pchName, uint unNameBufLen, out float pflPercent, out bool pbAchieved)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetNextMostAchievedAchievementInfo")]
STUB(int, SteamAPI_ISteamUserStats_GetNextMostAchievedAchievementInfo, 0, IntPtr instancePtr, int iIteratorPrevious, IntPtr pchName, uint unNameBufLen, out float pflPercent, out bool pbAchieved)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetAchievementAchievedPercent")]
STUB(bool, SteamAPI_ISteamUserStats_GetAchievementAchievedPercent, 0, IntPtr instancePtr, char * pchName, out float pflPercent)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_RequestGlobalStats")]
STUB(ulong, SteamAPI_ISteamUserStats_RequestGlobalStats, 0, IntPtr instancePtr, int nHistoryDays)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetGlobalStatInt64")]
STUB(bool, SteamAPI_ISteamUserStats_GetGlobalStatInt64, 0, IntPtr instancePtr, char * pchStatName, out long pData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetGlobalStatDouble")]
STUB(bool, SteamAPI_ISteamUserStats_GetGlobalStatDouble, 0, IntPtr instancePtr, char * pchStatName, out double pData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetGlobalStatHistoryInt64")]
STUB(int, SteamAPI_ISteamUserStats_GetGlobalStatHistoryInt64, 0, IntPtr instancePtr, char * pchStatName, long* pData, uint cubData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetGlobalStatHistoryDouble")]
STUB(int, SteamAPI_ISteamUserStats_GetGlobalStatHistoryDouble, 0, IntPtr instancePtr, char * pchStatName, double* pData, uint cubData)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetAchievementProgressLimitsInt32")]
STUB(bool, SteamAPI_ISteamUserStats_GetAchievementProgressLimitsInt32, 0, IntPtr instancePtr, char * pchName, out int pnMinProgress, out int pnMaxProgress)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUserStats_GetAchievementProgressLimitsFloat")]
STUB(bool, SteamAPI_ISteamUserStats_GetAchievementProgressLimitsFloat, 0, IntPtr instancePtr, char * pchName, out float pfMinProgress, out float pfMaxProgress)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_GetSecondsSinceAppActive")]
STUB(uint, SteamAPI_ISteamUtils_GetSecondsSinceAppActive, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_GetSecondsSinceComputerActive")]
STUB(uint, SteamAPI_ISteamUtils_GetSecondsSinceComputerActive, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_GetConnectedUniverse")]
STUB(EUniverse, SteamAPI_ISteamUtils_GetConnectedUniverse, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_GetServerRealTime")]
STUB(uint, SteamAPI_ISteamUtils_GetServerRealTime, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_GetIPCountry")]
STUB(IntPtr, SteamAPI_ISteamUtils_GetIPCountry, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_GetImageSize")]
STUB(bool, SteamAPI_ISteamUtils_GetImageSize, 0, IntPtr instancePtr, int iImage, out uint pnWidth, out uint pnHeight)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_GetImageRGBA")]
STUB(bool, SteamAPI_ISteamUtils_GetImageRGBA, 0, IntPtr instancePtr, int iImage, byte* pubDest, int nDestBufferSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_GetCurrentBatteryPower")]
STUB(byte, SteamAPI_ISteamUtils_GetCurrentBatteryPower, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_GetAppID")]
STUB(uint, SteamAPI_ISteamUtils_GetAppID, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_SetOverlayNotificationPosition")]
STUB(void, SteamAPI_ISteamUtils_SetOverlayNotificationPosition, 0, IntPtr instancePtr, ENotificationPosition eNotificationPosition)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_IsAPICallCompleted")]
STUB(bool, SteamAPI_ISteamUtils_IsAPICallCompleted, 0, IntPtr instancePtr, SteamAPICall_t hSteamAPICall, out bool pbFailed)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_GetAPICallFailureReason")]
STUB(ESteamAPICallFailure, SteamAPI_ISteamUtils_GetAPICallFailureReason, 0, IntPtr instancePtr, SteamAPICall_t hSteamAPICall)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_GetAPICallResult")]
STUB(bool, SteamAPI_ISteamUtils_GetAPICallResult, 0, IntPtr instancePtr, SteamAPICall_t hSteamAPICall, IntPtr pCallback, int cubCallback, int iCallbackExpected, out bool pbFailed)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_GetIPCCallCount")]
STUB(uint, SteamAPI_ISteamUtils_GetIPCCallCount, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_SetWarningMessageHook")]
STUB(void, SteamAPI_ISteamUtils_SetWarningMessageHook, 0, IntPtr instancePtr, SteamAPIWarningMessageHook_t pFunction)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_IsOverlayEnabled")]
STUB(bool, SteamAPI_ISteamUtils_IsOverlayEnabled, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_BOverlayNeedsPresent")]
STUB(bool, SteamAPI_ISteamUtils_BOverlayNeedsPresent, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_CheckFileSignature")]
STUB(ulong, SteamAPI_ISteamUtils_CheckFileSignature, 0, IntPtr instancePtr, char * szFileName)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_ShowGamepadTextInput")]
STUB(bool, SteamAPI_ISteamUtils_ShowGamepadTextInput, 0, IntPtr instancePtr, EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, char * pchDescription, uint unCharMax, char * pchExistingText)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_GetEnteredGamepadTextLength")]
STUB(uint, SteamAPI_ISteamUtils_GetEnteredGamepadTextLength, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_GetEnteredGamepadTextInput")]
STUB(bool, SteamAPI_ISteamUtils_GetEnteredGamepadTextInput, 0, IntPtr instancePtr, IntPtr pchText, uint cchText)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_GetSteamUILanguage")]
STUB(IntPtr, SteamAPI_ISteamUtils_GetSteamUILanguage, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_IsSteamRunningInVR")]
STUB(bool, SteamAPI_ISteamUtils_IsSteamRunningInVR, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_SetOverlayNotificationInset")]
STUB(void, SteamAPI_ISteamUtils_SetOverlayNotificationInset, 0, IntPtr instancePtr, int nHorizontalInset, int nVerticalInset)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_IsSteamInBigPictureMode")]
STUB(bool, SteamAPI_ISteamUtils_IsSteamInBigPictureMode, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_StartVRDashboard")]
STUB(void, SteamAPI_ISteamUtils_StartVRDashboard, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_IsVRHeadsetStreamingEnabled")]
STUB(bool, SteamAPI_ISteamUtils_IsVRHeadsetStreamingEnabled, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_SetVRHeadsetStreamingEnabled")]
STUB(void, SteamAPI_ISteamUtils_SetVRHeadsetStreamingEnabled, 0, IntPtr instancePtr, char bEnabled)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_IsSteamChinaLauncher")]
STUB(bool, SteamAPI_ISteamUtils_IsSteamChinaLauncher, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_InitFilterText")]
STUB(bool, SteamAPI_ISteamUtils_InitFilterText, 0, IntPtr instancePtr, uint unFilterOptions)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_FilterText")]
STUB(int, SteamAPI_ISteamUtils_FilterText, 0, IntPtr instancePtr, ETextFilteringContext eContext, CSteamID sourceSteamID, char * pchInputMessage, IntPtr pchOutFilteredText, uint nByteSizeOutFilteredText)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_GetIPv6ConnectivityState")]
STUB(ESteamIPv6ConnectivityState, SteamAPI_ISteamUtils_GetIPv6ConnectivityState, 0, IntPtr instancePtr, ESteamIPv6ConnectivityProtocol eProtocol)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_IsSteamRunningOnSteamDeck")]
STUB(bool, SteamAPI_ISteamUtils_IsSteamRunningOnSteamDeck, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_ShowFloatingGamepadTextInput")]
STUB(bool, SteamAPI_ISteamUtils_ShowFloatingGamepadTextInput, 0, IntPtr instancePtr, EFloatingGamepadTextInputMode eKeyboardMode, int nTextFieldXPosition, int nTextFieldYPosition, int nTextFieldWidth, int nTextFieldHeight)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_SetGameLauncherMode")]
STUB(void, SteamAPI_ISteamUtils_SetGameLauncherMode, 0, IntPtr instancePtr, char bLauncherMode)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamUtils_DismissFloatingGamepadTextInput")]
STUB(bool, SteamAPI_ISteamUtils_DismissFloatingGamepadTextInput, 0, IntPtr instancePtr)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamVideo_GetVideoURL")]
STUB(void, SteamAPI_ISteamVideo_GetVideoURL, 0, IntPtr instancePtr, AppId_t unVideoAppID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamVideo_IsBroadcasting")]
STUB(bool, SteamAPI_ISteamVideo_IsBroadcasting, 0, IntPtr instancePtr, out int pnNumViewers)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamVideo_GetOPFSettings")]
STUB(void, SteamAPI_ISteamVideo_GetOPFSettings, 0, IntPtr instancePtr, AppId_t unVideoAppID)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamAPI_ISteamVideo_GetOPFStringForApp")]
STUB(bool, SteamAPI_ISteamVideo_GetOPFStringForApp, 0, IntPtr instancePtr, AppId_t unVideoAppID, IntPtr pchBuffer, ref int pnBufferSize)

// [DllImport("steam_api", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, IsSteamRunning, 0);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(void, IJCSteamAPI_SetAchievement, 0, string ID);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(void, IJCSteamAPI_FindLeaderboard, 0, string ID);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, IJCSteamAPI_UploadScore, 0, int score);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, IJCSteamAPI_Init, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(void, IJCSteamAPI_RunCallbacks, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(void, IJCSteamAPI_Shutdown, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamWrapper_Init, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamWrapper_RunCallbacks, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamWrapper_Shutdown, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(bool, SteamWrapper_SetAchievement, 0, string achievement);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(bool, SteamWrapper_InitStats, 0, int count, int maxIndex);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(bool, SteamWrapper_AddStat, 0, string stat, int index);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(bool, SteamWrapper_SetStatIntByIndex, 0, int index, int value);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(bool, SteamWrapper_IncStatIntByIndex, 0, int index, int value);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(bool, SteamWrapper_GetStatIntByIndex, 0, int index, out int value);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(bool, SteamWrapper_GetGlobalStatIntByIndex, 0, int index, out long value);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(void, SteamWrapper_RequestGlobalStats, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(bool, SteamWrapper_HaveGlobalStats, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(bool, SteamWrapper_StoreStats, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(bool, SteamWrapper_ResetAllStats, 0, int achievementsToo);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(bool, SteamWrapper_LbUploadScore, 0, string leaderboard, int score);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(bool, SteamWrapper_LbBeginUserRead, 0, string leaderboard);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(bool, SteamWrapper_LbBeginGlobalRead, 0, string leaderboard);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(bool, SteamWrapper_LbBeginFriendRead, 0, string leaderboard);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamWrapper_LbPageUp, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamWrapper_LbPageDown, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamWrapper_LbCanPageUp, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamWrapper_LbCanPageDown, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamWrapper_LbIsDownloading, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(int, SteamWrapper_LbGetRank, 0, int index);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(int, SteamWrapper_LbGetScore, 0, int index);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, SteamWrapper_LbGetName, 0, int index);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, SteamWrapper_LbGetId, 0, int index);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(int, SteamWrapper_LbGetCount, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(int, SteamWrapper_LbGetTotalSize, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamWrapper_IsLbInitialized, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamWrapper_IsCloudStorageEnabled, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(int, SteamWrapper_FileWrite, 0, string file, IntPtr data, int size);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(int, SteamWrapper_FileRead, 0, string file, IntPtr data, int size);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(bool, SteamWrapper_FileDelete, 0, string file);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(bool, SteamWrapper_FileExists, 0, string file);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(int, SteamWrapper_GetFileSize, 0, string file);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(long, SteamWrapper_GetFileTimestamp, 0, string file);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(int, SteamWrapper_GetFileCount, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, SteamWrapper_GetFileNameAndSize, 0, int index, out int fileSizeInBytes);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, SteamWrapper_GetPersonaName, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, SteamWrapper_GetSteamId, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(bool, SteamWrapper_SetRichPresence, 0, string presence);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, SteamWrapper_GetUserDataFolder, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(void, SteamWrapper_ActivateGameOverlayToUser, 0, string dialog, ulong steamId);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamWrapper_ActivateGameOverlayToStore, 0, uint appId);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(void, SteamWrapper_ActivateGameOverlayToWebPage, 0, string url);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamWrapper_IsOverlayEnabled, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamWrapper_IsOverlayActive, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
IntPtr SteamWrapper_GetCurrentGameLanguage()
{
    return (IntPtr)"english";
}

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamWrapper_NetUpdate, 0, uint mapID);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(int, SteamWrapper_GetNextPacket, 0, byte* packetBuf, int packetBufSize, ref ulong playerID);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(int, SteamWrapper_SendPacket, 0, void* packet, uint len, ulong playerID);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamWrapper_SetForceCreateRoom, 0, int flag);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, SteamWrapper_GetNextNewPlayer, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(bool, SteamWrapper_ControllerInit, 0, string controllerPath);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamWrapper_ControllerShutdown, 0, );

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, SteamWrapper_ControllerState, 0, uint controllerIndex, ControllerState state);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl)]
STUB(void, SteamWrapper_TriggerHapticPulse, 0, uint controllerIndex, SteamControllerPad targetPad, ushort duration);

// [DllImport("SteamWrapper.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
STUB(void, SteamWrapper_ControllerOverideMode, 0, string mode);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "Init")]
STUB(bool, Init, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "InitSafe")]
STUB(bool, InitSafe, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "Shutdown")]
STUB(void, Shutdown, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "RestartAppIfNecessary")]
STUB(bool, RestartAppIfNecessary, 0, AppId_t unOwnAppID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "ReleaseCurrentThreadMemory")]
STUB(void, ReleaseCurrentThreadMemory, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "WriteMiniDump")]
STUB(void, WriteMiniDump, 0, uint uStructuredExceptionCode, IntPtr pvExceptionInfo, uint uBuildID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SetMiniDumpComment")]
STUB(void, SetMiniDumpComment, 0, char * pchMsg);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "RunCallbacks")]
STUB(void, RunCallbacks, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "RegisterCallback")]
STUB(void, RegisterCallback, 0, IntPtr pCallback, int iCallback);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "UnregisterCallback")]
STUB(void, UnregisterCallback, 0, IntPtr pCallback);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "RegisterCallResult")]
STUB(void, RegisterCallResult, 0, IntPtr pCallback, ulong hAPICall);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "UnregisterCallResult")]
STUB(void, UnregisterCallResult, 0, IntPtr pCallback, ulong hAPICall);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "IsSteamRunning")]
// STUB(bool, IsSteamRunning, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "Steam_RunCallbacks_")]
STUB(void, Steam_RunCallbacks_, 0, HSteamPipe hSteamPipe, bool bGameServerCallbacks);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "Steam_RegisterInterfaceFuncs_")]
STUB(void, Steam_RegisterInterfaceFuncs_, 0, IntPtr hModule);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "Steam_GetHSteamUserCurrent_")]
STUB(int, Steam_GetHSteamUserCurrent_, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "GetSteamInstallPath")]
STUB(int, GetSteamInstallPath, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "GetHSteamPipe_")]
STUB(int, GetHSteamPipe_, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SetTryCatchCallbacks")]
STUB(void, SetTryCatchCallbacks, 0, bool bTryCatchCallbacks);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "GetHSteamUser_")]
STUB(int, GetHSteamUser_, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamInternal_CreateInterface_")]
STUB(void, SteamInternal_CreateInterface_, 0, IntPtr ver);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "UseBreakpadCrashHandler")]
STUB(void, UseBreakpadCrashHandler, 0, char * pchVersion, char * pchDate, char * pchTime, bool bFullMemoryDumps, IntPtr pvContext, IntPtr m_pfnPreMinidumpCallback);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SetBreakpadAppID")]
STUB(void, SetBreakpadAppID, 0, uint unAppID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "GameServer_Init")]
STUB(bool, GameServer_Init, 0, uint unIP, ushort usSteamPort, ushort usGamePort, ushort usQueryPort, EServerMode eServerMode, char * pchVersionString);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "GameServer_Shutdown")]
STUB(void, GameServer_Shutdown, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "GameServer_RunCallbacks")]
STUB(void, GameServer_RunCallbacks, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "GameServer_ReleaseCurrentThreadMemory")]
STUB(void, GameServer_ReleaseCurrentThreadMemory, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "GameServer_BSecure")]
STUB(bool, GameServer_BSecure, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "GameServer_GetSteamID")]
STUB(ulong, GameServer_GetSteamID, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "GameServer_GetHSteamPipe")]
STUB(int, GameServer_GetHSteamPipe, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "GameServer_GetHSteamUser")]
STUB(int, GameServer_GetHSteamUser, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamInternal_GameServer_Init_")]
STUB(bool, SteamInternal_GameServer_Init_, 0, uint unIP, ushort usPort, ushort usGamePort, ushort usQueryPort, EServerMode eServerMode, char * pchVersionString);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamClient_")]
STUB(IntPtr, SteamClient_, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SteamGameServerClient_")]
STUB(IntPtr, SteamGameServerClient_, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamAppList_GetNumInstalledApps, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamAppList_GetInstalledApps, 0, AppId_t* pvecAppID, uint unMaxAppIDs);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamAppList_GetAppName, 0, AppId_t nAppID, IntPtr pchName, int cchNameMax);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamAppList_GetAppInstallDir, 0, AppId_t nAppID, IntPtr pchDirectory, int cchNameMax);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamAppList_GetAppBuildId, 0, AppId_t nAppID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamApps_BIsSubscribed, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamApps_BIsLowViolence, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamApps_BIsCybercafe, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamApps_BIsVACBanned, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamApps_GetCurrentGameLanguage, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamApps_GetAvailableGameLanguages, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamApps_BIsSubscribedApp, 0, AppId_t appID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamApps_BIsDlcInstalled, 0, AppId_t appID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamApps_GetEarliestPurchaseUnixTime, 0, AppId_t nAppID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamApps_BIsSubscribedFromFreeWeekend, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamApps_GetDLCCount, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamApps_BGetDLCDataByIndex, 0, int iDLC, out AppId_t pAppID, out bool pbAvailable, IntPtr pchName, int cchNameBufferSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamApps_InstallDLC, 0, AppId_t nAppID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamApps_UninstallDLC, 0, AppId_t nAppID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamApps_RequestAppProofOfPurchaseKey, 0, AppId_t nAppID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamApps_GetCurrentBetaName, 0, IntPtr pchName, int cchNameBufferSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamApps_MarkContentCorrupt, 0, bool bMissingFilesOnly);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamApps_GetInstalledDepots, 0, AppId_t appID, DepotId_t* pvecDepots, uint cMaxDepots);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamApps_GetAppInstallDir, 0, AppId_t appID, IntPtr pchFolder, uint cchFolderBufferSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamApps_BIsAppInstalled, 0, AppId_t appID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamApps_GetAppOwner, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamApps_GetLaunchQueryParam, 0, char * pchKey);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamApps_GetDlcDownloadProgress, 0, AppId_t nAppID, out ulong punBytesDownloaded, out ulong punBytesTotal);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamApps_GetAppBuildId, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamApps_RequestAllProofOfPurchaseKeys, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamApps_GetFileDetails, 0, char * pszFileName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamClient_CreateSteamPipe, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamClient_BReleaseSteamPipe, 0, HSteamPipe hSteamPipe);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamClient_ConnectToGlobalUser, 0, HSteamPipe hSteamPipe);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamClient_CreateLocalUser, 0, out HSteamPipe phSteamPipe, EAccountType eAccountType);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamClient_ReleaseUser, 0, HSteamPipe hSteamPipe, HSteamUser hUser);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamUser, 0, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamGameServer, 0, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamClient_SetLocalIPBinding, 0, uint unIP, ushort usPort);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamFriends, 0, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamUtils, 0, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamMatchmaking, 0, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamMatchmakingServers, 0, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamGenericInterface, 0, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamUserStats, 0, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamGameServerStats, 0, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamApps, 0, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamNetworking, 0, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamRemoteStorage, 0, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamScreenshots, 0, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamClient_GetIPCCallCount, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamClient_SetWarningMessageHook, 0, SteamAPIWarningMessageHook_t pFunction);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamClient_BShutdownIfAllPipesClosed, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamHTTP, 0, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamUnifiedMessages, 0, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamController, 0, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamUGC, 0, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamAppList, 0, HSteamUser hSteamUser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamMusic, 0, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamMusicRemote, 0, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamHTMLSurface, 0, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamInventory, 0, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamClient_GetISteamVideo, 0, HSteamUser hSteamuser, HSteamPipe hSteamPipe, char * pchVersion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamController_Init, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamController_Shutdown, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamController_RunFrame, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamController_GetConnectedControllers, 0, ControllerHandle_t* handlesOut);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamController_ShowBindingPanel, 0, ControllerHandle_t controllerHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamController_GetActionSetHandle, 0, char * pszActionSetName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamController_ActivateActionSet, 0, ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamController_GetCurrentActionSet, 0, ControllerHandle_t controllerHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamController_GetDigitalActionHandle, 0, char * pszActionName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ControllerDigitalActionData_t, ISteamController_GetDigitalActionData, (ControllerDigitalActionData_t){ }, ControllerHandle_t controllerHandle, ControllerDigitalActionHandle_t digitalActionHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamController_GetDigitalActionOrigins, 0, ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle, ControllerDigitalActionHandle_t digitalActionHandle, EControllerActionOrigin* originsOut);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamController_GetAnalogActionHandle, 0, char * pszActionName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ControllerAnalogActionData_t, ISteamController_GetAnalogActionData, (ControllerAnalogActionData_t){ }, ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t analogActionHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamController_GetAnalogActionOrigins, 0, ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle, ControllerAnalogActionHandle_t analogActionHandle, EControllerActionOrigin* originsOut);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamController_StopAnalogActionMomentum, 0, ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t eAction);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamController_TriggerHapticPulse, 0, ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, ushort usDurationMicroSec);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamController_TriggerRepeatedHapticPulse, 0, ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, ushort usDurationMicroSec, ushort usOffMicroSec, ushort unRepeat, uint nFlags);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamController_GetGamepadIndexForController, 0, ControllerHandle_t ulControllerHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamController_GetControllerForGamepadIndex, 0, int nIndex);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ControllerMotionData_t, ISteamController_GetMotionData, (ControllerMotionData_t) { }, ControllerHandle_t controllerHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamController_ShowDigitalActionOrigins, 0, ControllerHandle_t controllerHandle, ControllerDigitalActionHandle_t digitalActionHandle, float flScale, float flXPosition, float flYPosition);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamController_ShowAnalogActionOrigins, 0, ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t analogActionHandle, float flScale, float flXPosition, float flYPosition);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamFriends_GetPersonaName, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamFriends_SetPersonaName, 0, char * pchPersonaName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(EPersonaState, ISteamFriends_GetPersonaState, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamFriends_GetFriendCount, 0, EFriendFlags iFriendFlags);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamFriends_GetFriendByIndex, 0, int iFriend, EFriendFlags iFriendFlags);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(EFriendRelationship, ISteamFriends_GetFriendRelationship, 0, CSteamID steamIDFriend);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(EPersonaState, ISteamFriends_GetFriendPersonaState, 0, CSteamID steamIDFriend);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamFriends_GetFriendPersonaName, 0, CSteamID steamIDFriend);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamFriends_GetFriendGamePlayed, 0, CSteamID steamIDFriend, out FriendGameInfo_t pFriendGameInfo);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamFriends_GetFriendPersonaNameHistory, 0, CSteamID steamIDFriend, int iPersonaName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamFriends_GetFriendSteamLevel, 0, CSteamID steamIDFriend);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamFriends_GetPlayerNickname, 0, CSteamID steamIDPlayer);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamFriends_GetFriendsGroupCount, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(short, ISteamFriends_GetFriendsGroupIDByIndex, 0, int iFG);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamFriends_GetFriendsGroupName, 0, FriendsGroupID_t friendsGroupID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamFriends_GetFriendsGroupMembersCount, 0, FriendsGroupID_t friendsGroupID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamFriends_GetFriendsGroupMembersList, 0, FriendsGroupID_t friendsGroupID, CSteamID* pOutSteamIDMembers, int nMembersCount);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamFriends_HasFriend, 0, CSteamID steamIDFriend, EFriendFlags iFriendFlags);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamFriends_GetClanCount, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamFriends_GetClanByIndex, 0, int iClan);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamFriends_GetClanName, 0, CSteamID steamIDClan);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamFriends_GetClanTag, 0, CSteamID steamIDClan);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamFriends_GetClanActivityCounts, 0, CSteamID steamIDClan, out int pnOnline, out int pnInGame, out int pnChatting);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamFriends_DownloadClanActivityCounts, 0, CSteamID* psteamIDClans, int cClansToRequest);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamFriends_GetFriendCountFromSource, 0, CSteamID steamIDSource);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamFriends_GetFriendFromSourceByIndex, 0, CSteamID steamIDSource, int iFriend);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamFriends_IsUserInSource, 0, CSteamID steamIDUser, CSteamID steamIDSource);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamFriends_SetInGameVoiceSpeaking, 0, CSteamID steamIDUser, bool bSpeaking);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamFriends_ActivateGameOverlay, 0, char * pchDialog);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamFriends_ActivateGameOverlayToUser, 0, char * pchDialog, CSteamID steamID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamFriends_ActivateGameOverlayToWebPage, 0, char * pchURL);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamFriends_ActivateGameOverlayToStore, 0, AppId_t nAppID, EOverlayToStoreFlag eFlag);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamFriends_SetPlayedWith, 0, CSteamID steamIDUserPlayedWith);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamFriends_ActivateGameOverlayInviteDialog, 0, CSteamID steamIDLobby);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamFriends_GetSmallFriendAvatar, 0, CSteamID steamIDFriend);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamFriends_GetMediumFriendAvatar, 0, CSteamID steamIDFriend);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamFriends_GetLargeFriendAvatar, 0, CSteamID steamIDFriend);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamFriends_RequestUserInformation, 0, CSteamID steamIDUser, bool bRequireNameOnly);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamFriends_RequestClanOfficerList, 0, CSteamID steamIDClan);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamFriends_GetClanOwner, 0, CSteamID steamIDClan);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamFriends_GetClanOfficerCount, 0, CSteamID steamIDClan);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamFriends_GetClanOfficerByIndex, 0, CSteamID steamIDClan, int iOfficer);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamFriends_GetUserRestrictions, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamFriends_SetRichPresence, 0, char * pchKey, char * pchValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamFriends_ClearRichPresence, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamFriends_GetFriendRichPresence, 0, CSteamID steamIDFriend, char * pchKey);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamFriends_GetFriendRichPresenceKeyCount, 0, CSteamID steamIDFriend);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamFriends_GetFriendRichPresenceKeyByIndex, 0, CSteamID steamIDFriend, int iKey);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamFriends_RequestFriendRichPresence, 0, CSteamID steamIDFriend);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamFriends_InviteUserToGame, 0, CSteamID steamIDFriend, char * pchConnectString);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamFriends_GetCoplayFriendCount, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamFriends_GetCoplayFriend, 0, int iCoplayFriend);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamFriends_GetFriendCoplayTime, 0, CSteamID steamIDFriend);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamFriends_GetFriendCoplayGame, 0, CSteamID steamIDFriend);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamFriends_JoinClanChatRoom, 0, CSteamID steamIDClan);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamFriends_LeaveClanChatRoom, 0, CSteamID steamIDClan);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamFriends_GetClanChatMemberCount, 0, CSteamID steamIDClan);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamFriends_GetChatMemberByIndex, 0, CSteamID steamIDClan, int iUser);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamFriends_SendClanChatMessage, 0, CSteamID steamIDClanChat, char * pchText);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamFriends_GetClanChatMessage, 0, CSteamID steamIDClanChat, int iMessage, IntPtr prgchText, int cchTextMax, out EChatEntryType peChatEntryType, out CSteamID psteamidChatter);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamFriends_IsClanChatAdmin, 0, CSteamID steamIDClanChat, CSteamID steamIDUser);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamFriends_IsClanChatWindowOpenInSteam, 0, CSteamID steamIDClanChat);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamFriends_OpenClanChatWindowInSteam, 0, CSteamID steamIDClanChat);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamFriends_CloseClanChatWindowInSteam, 0, CSteamID steamIDClanChat);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamFriends_SetListenForFriendsMessages, 0, bool bInterceptEnabled);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamFriends_ReplyToFriendMessage, 0, CSteamID steamIDFriend, char * pchMsgToSend);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamFriends_GetFriendMessage, 0, CSteamID steamIDFriend, int iMessageID, IntPtr pvData, int cubData, out EChatEntryType peChatEntryType);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamFriends_GetFollowerCount, 0, CSteamID steamID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamFriends_IsFollowing, 0, CSteamID steamID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamFriends_EnumerateFollowingList, 0, uint unStartIndex);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServer_InitGameServer, 0, uint unIP, ushort usGamePort, ushort usQueryPort, uint unFlags, AppId_t nGameAppId, char * pchVersionString);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_SetProduct, 0, char * pszProduct);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_SetGameDescription, 0, char * pszGameDescription);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_SetModDir, 0, char * pszModDir);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_SetDedicatedServer, 0, bool bDedicated);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_LogOn, 0, char * pszToken);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_LogOnAnonymous, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_LogOff, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServer_BLoggedOn, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServer_BSecure, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServer_GetSteamID, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServer_WasRestartRequested, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_SetMaxPlayerCount, 0, int cPlayersMax);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_SetBotPlayerCount, 0, int cBotplayers);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_SetServerName, 0, char * pszServerName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_SetMapName, 0, char * pszMapName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_SetPasswordProtected, 0, bool bPasswordProtected);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_SetSpectatorPort, 0, ushort unSpectatorPort);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_SetSpectatorServerName, 0, char * pszSpectatorServerName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_ClearAllKeyValues, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_SetKeyValue, 0, char * pKey, char * pValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_SetGameTags, 0, char * pchGameTags);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_SetGameData, 0, char * pchGameData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_SetRegion, 0, char * pszRegion);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServer_SendUserConnectAndAuthenticate, 0, uint unIPClient, char *pvAuthBlob, uint cubAuthBlobSize, out CSteamID pSteamIDUser);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServer_CreateUnauthenticatedUserConnection, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_SendUserDisconnect, 0, CSteamID steamIDUser);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServer_BUpdateUserData, 0, CSteamID steamIDUser, char * pchPlayerName, uint uScore);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServer_GetAuthSessionTicket, 0, char *pTicket, int cbMaxTicket, out uint pcbTicket);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(EBeginAuthSessionResult, ISteamGameServer_BeginAuthSession, 0, char *pAuthTicket, int cbAuthTicket, CSteamID steamID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_EndAuthSession, 0, CSteamID steamID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_CancelAuthTicket, 0, HAuthTicket hAuthTicket);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(EUserHasLicenseForAppResult, ISteamGameServer_UserHasLicenseForApp, 0, CSteamID steamID, AppId_t appID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServer_RequestUserGroupStatus, 0, CSteamID steamIDUser, CSteamID steamIDGroup);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_GetGameplayStats, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServer_GetServerReputation, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServer_GetPublicIP, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServer_HandleIncomingPacket, 0, char *pData, int cbData, uint srcIP, ushort srcPort);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamGameServer_GetNextOutgoingPacket, 0, char *pOut, int cbMaxOut, out uint pNetAdr, out ushort pPort);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_EnableHeartbeats, 0, bool bActive);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_SetHeartbeatInterval, 0, int iHeartbeatInterval);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServer_ForceHeartbeat, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServer_AssociateWithClan, 0, CSteamID steamIDClan);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServer_ComputeNewPlayerCompatibility, 0, CSteamID steamIDNewPlayer);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerStats_RequestUserStats, 0, CSteamID steamIDUser);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerStats_GetUserStat, 0, CSteamID steamIDUser, char * pchName, out int pData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerStats_GetUserStat_, 0, CSteamID steamIDUser, char * pchName, out float pData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerStats_GetUserAchievement, 0, CSteamID steamIDUser, char * pchName, out bool pbAchieved);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerStats_SetUserStat, 0, CSteamID steamIDUser, char * pchName, int nData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerStats_SetUserStat_, 0, CSteamID steamIDUser, char * pchName, float fData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerStats_UpdateUserAvgRateStat, 0, CSteamID steamIDUser, char * pchName, float flCountThisSession, double dSessionLength);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerStats_SetUserAchievement, 0, CSteamID steamIDUser, char * pchName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerStats_ClearUserAchievement, 0, CSteamID steamIDUser, char * pchName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerStats_StoreUserStats, 0, CSteamID steamIDUser);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTMLSurface_Init, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTMLSurface_Shutdown, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamHTMLSurface_CreateBrowser, 0, char * pchUserAgent, char * pchUserCSS);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_RemoveBrowser, 0, HHTMLBrowser unBrowserHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_LoadURL, 0, HHTMLBrowser unBrowserHandle, char * pchURL, char * pchPostData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_SetSize, 0, HHTMLBrowser unBrowserHandle, uint unWidth, uint unHeight);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_StopLoad, 0, HHTMLBrowser unBrowserHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_Reload, 0, HHTMLBrowser unBrowserHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_GoBack, 0, HHTMLBrowser unBrowserHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_GoForward, 0, HHTMLBrowser unBrowserHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_AddHeader, 0, HHTMLBrowser unBrowserHandle, char * pchKey, char * pchValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_ExecuteJavascript, 0, HHTMLBrowser unBrowserHandle, char * pchScript);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_MouseUp, 0, HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_MouseDown, 0, HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_MouseDoubleClick, 0, HHTMLBrowser unBrowserHandle, EHTMLMouseButton eMouseButton);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_MouseMove, 0, HHTMLBrowser unBrowserHandle, int x, int y);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_MouseWheel, 0, HHTMLBrowser unBrowserHandle, int nDelta);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_KeyDown, 0, HHTMLBrowser unBrowserHandle, uint nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_KeyUp, 0, HHTMLBrowser unBrowserHandle, uint nNativeKeyCode, EHTMLKeyModifiers eHTMLKeyModifiers);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_KeyChar, 0, HHTMLBrowser unBrowserHandle, uint cUnicodeChar, EHTMLKeyModifiers eHTMLKeyModifiers);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_SetHorizontalScroll, 0, HHTMLBrowser unBrowserHandle, uint nAbsolutePixelScroll);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_SetVerticalScroll, 0, HHTMLBrowser unBrowserHandle, uint nAbsolutePixelScroll);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_SetKeyFocus, 0, HHTMLBrowser unBrowserHandle, bool bHasKeyFocus);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_ViewSource, 0, HHTMLBrowser unBrowserHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_CopyToClipboard, 0, HHTMLBrowser unBrowserHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_PasteFromClipboard, 0, HHTMLBrowser unBrowserHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_Find, 0, HHTMLBrowser unBrowserHandle, char * pchSearchStr, bool bCurrentlyInFind, bool bReverse);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_StopFind, 0, HHTMLBrowser unBrowserHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_GetLinkAtPosition, 0, HHTMLBrowser unBrowserHandle, int x, int y);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_SetCookie, 0, char * pchHostname, char * pchKey, char * pchValue, char * pchPath, uint nExpires, bool bSecure, bool bHTTPOnly);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_SetPageScaleFactor, 0, HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_SetBackgroundMode, 0, HHTMLBrowser unBrowserHandle, bool bBackgroundMode);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_AllowStartRequest, 0, HHTMLBrowser unBrowserHandle, bool bAllowed);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_JSDialogResponse, 0, HHTMLBrowser unBrowserHandle, bool bResult);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamHTMLSurface_FileLoadDialogResponse, 0, HHTMLBrowser unBrowserHandle, IntPtr pchSelectedFiles);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamHTTP_CreateHTTPRequest, 0, EHTTPMethod eHTTPRequestMethod, char * pchAbsoluteURL);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_SetHTTPRequestContextValue, 0, HTTPRequestHandle hRequest, ulong ulContextValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_SetHTTPRequestNetworkActivityTimeout, 0, HTTPRequestHandle hRequest, uint unTimeoutSeconds);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_SetHTTPRequestHeaderValue, 0, HTTPRequestHandle hRequest, char * pchHeaderName, char * pchHeaderValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_SetHTTPRequestGetOrPostParameter, 0, HTTPRequestHandle hRequest, char * pchParamName, char * pchParamValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_SendHTTPRequest, 0, HTTPRequestHandle hRequest, out SteamAPICall_t pCallHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_SendHTTPRequestAndStreamResponse, 0, HTTPRequestHandle hRequest, out SteamAPICall_t pCallHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_DeferHTTPRequest, 0, HTTPRequestHandle hRequest);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_PrioritizeHTTPRequest, 0, HTTPRequestHandle hRequest);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_GetHTTPResponseHeaderSize, 0, HTTPRequestHandle hRequest, char * pchHeaderName, out uint unResponseHeaderSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_GetHTTPResponseHeaderValue, 0, HTTPRequestHandle hRequest, char * pchHeaderName, char *pHeaderValueBuffer, uint unBufferSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_GetHTTPResponseBodySize, 0, HTTPRequestHandle hRequest, out uint unBodySize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_GetHTTPResponseBodyData, 0, HTTPRequestHandle hRequest, char *pBodyDataBuffer, uint unBufferSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_GetHTTPStreamingResponseBodyData, 0, HTTPRequestHandle hRequest, uint cOffset, char *pBodyDataBuffer, uint unBufferSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_ReleaseHTTPRequest, 0, HTTPRequestHandle hRequest);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_GetHTTPDownloadProgressPct, 0, HTTPRequestHandle hRequest, out float pflPercentOut);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_SetHTTPRequestRawPostBody, 0, HTTPRequestHandle hRequest, char * pchContentType, char *pubBody, uint unBodyLen);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamHTTP_CreateCookieContainer, 0, bool bAllowResponsesToModify);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_ReleaseCookieContainer, 0, HTTPCookieContainerHandle hCookieContainer);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_SetCookie, 0, HTTPCookieContainerHandle hCookieContainer, char * pchHost, char * pchUrl, char * pchCookie);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_SetHTTPRequestCookieContainer, 0, HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_SetHTTPRequestUserAgentInfo, 0, HTTPRequestHandle hRequest, char * pchUserAgentInfo);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate, 0, HTTPRequestHandle hRequest, bool bRequireVerifiedCertificate);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS, 0, HTTPRequestHandle hRequest, uint unMilliseconds);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamHTTP_GetHTTPRequestWasTimedOut, 0, HTTPRequestHandle hRequest, out bool pbWasTimedOut);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(EResult, ISteamInventory_GetResultStatus, 0, SteamInventoryResult_t resultHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamInventory_GetResultItems, 0, SteamInventoryResult_t resultHandle, SteamItemDetails_t* pOutItemsArray, ref uint punOutItemsArraySize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamInventory_GetResultTimestamp, 0, SteamInventoryResult_t resultHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamInventory_CheckResultSteamID, 0, SteamInventoryResult_t resultHandle, CSteamID steamIDExpected);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamInventory_DestroyResult, 0, SteamInventoryResult_t resultHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamInventory_GetAllItems, 0, out SteamInventoryResult_t pResultHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamInventory_GetItemsByID, 0, out SteamInventoryResult_t pResultHandle, SteamItemInstanceID_t* pInstanceIDs, uint unCountInstanceIDs);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamInventory_SerializeResult, 0, SteamInventoryResult_t resultHandle, char *pOutBuffer, out uint punOutBufferSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamInventory_DeserializeResult, 0, out SteamInventoryResult_t pOutResultHandle, char *pBuffer, uint unBufferSize, bool bRESERVED_MUST_BE_FALSE);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamInventory_GenerateItems, 0, out SteamInventoryResult_t pResultHandle, SteamItemDef_t* pArrayItemDefs, uint* punArrayQuantity, uint unArrayLength);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamInventory_GrantPromoItems, 0, out SteamInventoryResult_t pResultHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamInventory_AddPromoItem, 0, out SteamInventoryResult_t pResultHandle, SteamItemDef_t itemDef);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamInventory_AddPromoItems, 0, out SteamInventoryResult_t pResultHandle, SteamItemDef_t* pArrayItemDefs, uint unArrayLength);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamInventory_ConsumeItem, 0, out SteamInventoryResult_t pResultHandle, SteamItemInstanceID_t itemConsume, uint unQuantity);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamInventory_ExchangeItems, 0, out SteamInventoryResult_t pResultHandle, SteamItemDef_t* pArrayGenerate, uint* punArrayGenerateQuantity, uint unArrayGenerateLength, SteamItemInstanceID_t* pArrayDestroy, uint* punArrayDestroyQuantity, uint unArrayDestroyLength);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamInventory_TransferItemQuantity, 0, out SteamInventoryResult_t pResultHandle, SteamItemInstanceID_t itemIdSource, uint unQuantity, SteamItemInstanceID_t itemIdDest);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamInventory_SendItemDropHeartbeat, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamInventory_TriggerItemDrop, 0, out SteamInventoryResult_t pResultHandle, SteamItemDef_t dropListDefinition);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamInventory_TradeItems, 0, out SteamInventoryResult_t pResultHandle, CSteamID steamIDTradePartner, SteamItemInstanceID_t* pArrayGive, uint* pArrayGiveQuantity, uint nArrayGiveLength, SteamItemInstanceID_t* pArrayGet, uint* pArrayGetQuantity, uint nArrayGetLength);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamInventory_LoadItemDefinitions, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamInventory_GetItemDefinitionIDs, 0, SteamItemDef_t* pItemDefIDs, out uint punItemDefIDsArraySize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamInventory_GetItemDefinitionProperty, 0, SteamItemDef_t iDefinition, char * pchPropertyName, IntPtr pchValueBuffer, ref uint punValueBufferSizeOut);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamMatchmaking_GetFavoriteGameCount, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMatchmaking_GetFavoriteGame, 0, int iGame, out AppId_t pnAppID, out uint pnIP, out ushort pnConnPort, out ushort pnQueryPort, out uint punFlags, out uint pRTime32LastPlayedOnServer);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamMatchmaking_AddFavoriteGame, 0, AppId_t nAppID, uint nIP, ushort nConnPort, ushort nQueryPort, uint unFlags, uint rTime32LastPlayedOnServer);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMatchmaking_RemoveFavoriteGame, 0, AppId_t nAppID, uint nIP, ushort nConnPort, ushort nQueryPort, uint unFlags);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamMatchmaking_RequestLobbyList, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMatchmaking_AddRequestLobbyListStringFilter, 0, char * pchKeyToMatch, char * pchValueToMatch, ELobbyComparison eComparisonType);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMatchmaking_AddRequestLobbyListNumericalFilter, 0, char * pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMatchmaking_AddRequestLobbyListNearValueFilter, 0, char * pchKeyToMatch, int nValueToBeCloseTo);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable, 0, int nSlotsAvailable);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMatchmaking_AddRequestLobbyListDistanceFilter, 0, ELobbyDistanceFilter eLobbyDistanceFilter);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMatchmaking_AddRequestLobbyListResultCountFilter, 0, int cMaxResults);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter, 0, CSteamID steamIDLobby);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamMatchmaking_GetLobbyByIndex, 0, int iLobby);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamMatchmaking_CreateLobby, 0, ELobbyType eLobbyType, int cMaxMembers);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamMatchmaking_JoinLobby, 0, CSteamID steamIDLobby);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMatchmaking_LeaveLobby, 0, CSteamID steamIDLobby);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMatchmaking_InviteUserToLobby, 0, CSteamID steamIDLobby, CSteamID steamIDInvitee);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamMatchmaking_GetNumLobbyMembers, 0, CSteamID steamIDLobby);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamMatchmaking_GetLobbyMemberByIndex, 0, CSteamID steamIDLobby, int iMember);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamMatchmaking_GetLobbyData, 0, CSteamID steamIDLobby, char * pchKey);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMatchmaking_SetLobbyData, 0, CSteamID steamIDLobby, char * pchKey, char * pchValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamMatchmaking_GetLobbyDataCount, 0, CSteamID steamIDLobby);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMatchmaking_GetLobbyDataByIndex, 0, CSteamID steamIDLobby, int iLobbyData, IntPtr pchKey, int cchKeyBufferSize, IntPtr pchValue, int cchValueBufferSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMatchmaking_DeleteLobbyData, 0, CSteamID steamIDLobby, char * pchKey);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamMatchmaking_GetLobbyMemberData, 0, CSteamID steamIDLobby, CSteamID steamIDUser, char * pchKey);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMatchmaking_SetLobbyMemberData, 0, CSteamID steamIDLobby, char * pchKey, char * pchValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMatchmaking_SendLobbyChatMsg, 0, CSteamID steamIDLobby, char *pvMsgBody, int cubMsgBody);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamMatchmaking_GetLobbyChatEntry, 0, CSteamID steamIDLobby, int iChatID, out CSteamID pSteamIDUser, char *pvData, int cubData, out EChatEntryType peChatEntryType);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMatchmaking_RequestLobbyData, 0, CSteamID steamIDLobby);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMatchmaking_SetLobbyGameServer, 0, CSteamID steamIDLobby, uint unGameServerIP, ushort unGameServerPort, CSteamID steamIDGameServer);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMatchmaking_GetLobbyGameServer, 0, CSteamID steamIDLobby, out uint punGameServerIP, out ushort punGameServerPort, out CSteamID psteamIDGameServer);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMatchmaking_SetLobbyMemberLimit, 0, CSteamID steamIDLobby, int cMaxMembers);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamMatchmaking_GetLobbyMemberLimit, 0, CSteamID steamIDLobby);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMatchmaking_SetLobbyType, 0, CSteamID steamIDLobby, ELobbyType eLobbyType);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMatchmaking_SetLobbyJoinable, 0, CSteamID steamIDLobby, bool bLobbyJoinable);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamMatchmaking_GetLobbyOwner, 0, CSteamID steamIDLobby);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMatchmaking_SetLobbyOwner, 0, CSteamID steamIDLobby, CSteamID steamIDNewOwner);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMatchmaking_SetLinkedLobby, 0, CSteamID steamIDLobby, CSteamID steamIDLobbyDependent);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamMatchmakingServers_RequestInternetServerList, 0, AppId_t iApp, IntPtr ppchFilters, uint nFilters, IntPtr pRequestServersResponse);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamMatchmakingServers_RequestLANServerList, 0, AppId_t iApp, IntPtr pRequestServersResponse);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamMatchmakingServers_RequestFriendsServerList, 0, AppId_t iApp, IntPtr ppchFilters, uint nFilters, IntPtr pRequestServersResponse);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamMatchmakingServers_RequestFavoritesServerList, 0, AppId_t iApp, IntPtr ppchFilters, uint nFilters, IntPtr pRequestServersResponse);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamMatchmakingServers_RequestHistoryServerList, 0, AppId_t iApp, IntPtr ppchFilters, uint nFilters, IntPtr pRequestServersResponse);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamMatchmakingServers_RequestSpectatorServerList, 0, AppId_t iApp, IntPtr ppchFilters, uint nFilters, IntPtr pRequestServersResponse);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMatchmakingServers_ReleaseRequest, 0, HServerListRequest hServerListRequest);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamMatchmakingServers_GetServerDetails, 0, HServerListRequest hRequest, int iServer);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMatchmakingServers_CancelQuery, 0, HServerListRequest hRequest);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMatchmakingServers_RefreshQuery, 0, HServerListRequest hRequest);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMatchmakingServers_IsRefreshing, 0, HServerListRequest hRequest);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamMatchmakingServers_GetServerCount, 0, HServerListRequest hRequest);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMatchmakingServers_RefreshServer, 0, HServerListRequest hRequest, int iServer);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamMatchmakingServers_PingServer, 0, uint unIP, ushort usPort, IntPtr pRequestServersResponse);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamMatchmakingServers_PlayerDetails, 0, uint unIP, ushort usPort, IntPtr pRequestServersResponse);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamMatchmakingServers_ServerRules, 0, uint unIP, ushort usPort, IntPtr pRequestServersResponse);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMatchmakingServers_CancelServerQuery, 0, HServerQuery hServerQuery);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusic_BIsEnabled, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusic_BIsPlaying, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(AudioPlayback_Status, ISteamMusic_GetPlaybackStatus, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMusic_Play, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMusic_Pause, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMusic_PlayPrevious, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMusic_PlayNext, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamMusic_SetVolume, 0, float flVolume);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(float, ISteamMusic_GetVolume, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_RegisterSteamMusicRemote, 0, char * pchName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_DeregisterSteamMusicRemote, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_BIsCurrentMusicRemote, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_BActivationSuccess, 0, bool bValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_SetDisplayName, 0, char * pchDisplayName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_SetPNGIcon_64x64, 0, char *pvBuffer, uint cbBufferLength);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_EnablePlayPrevious, 0, bool bValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_EnablePlayNext, 0, bool bValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_EnableShuffled, 0, bool bValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_EnableLooped, 0, bool bValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_EnableQueue, 0, bool bValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_EnablePlaylists, 0, bool bValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_UpdatePlaybackStatus, 0, AudioPlayback_Status nStatus);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_UpdateShuffled, 0, bool bValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_UpdateLooped, 0, bool bValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_UpdateVolume, 0, float flValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_CurrentEntryWillChange, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_CurrentEntryIsAvailable, 0, bool bAvailable);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_UpdateCurrentEntryText, 0, char * pchText);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_UpdateCurrentEntryElapsedSeconds, 0, int nValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_UpdateCurrentEntryCoverArt, 0, char *pvBuffer, uint cbBufferLength);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_CurrentEntryDidChange, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_QueueWillChange, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_ResetQueueEntries, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_SetQueueEntry, 0, int nID, int nPosition, char * pchEntryText);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_SetCurrentQueueEntry, 0, int nID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_QueueDidChange, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_PlaylistWillChange, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_ResetPlaylistEntries, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_SetPlaylistEntry, 0, int nID, int nPosition, char * pchEntryText);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_SetCurrentPlaylistEntry, 0, int nID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamMusicRemote_PlaylistDidChange, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamNetworking_SendP2PPacket, 0, CSteamID steamIDRemote, char *pubData, uint cubData, EP2PSend eP2PSendType, int nChannel);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamNetworking_IsP2PPacketAvailable, 0, out uint pcubMsgSize, int nChannel);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamNetworking_ReadP2PPacket, 0, char *pubDest, uint cubDest, out uint pcubMsgSize, out CSteamID psteamIDRemote, int nChannel);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamNetworking_AcceptP2PSessionWithUser, 0, CSteamID steamIDRemote);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamNetworking_CloseP2PSessionWithUser, 0, CSteamID steamIDRemote);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamNetworking_CloseP2PChannelWithUser, 0, CSteamID steamIDRemote, int nChannel);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamNetworking_GetP2PSessionState, 0, CSteamID steamIDRemote, out P2PSessionState_t pConnectionState);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamNetworking_AllowP2PPacketRelay, 0, bool bAllow);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamNetworking_CreateListenSocket, 0, int nVirtualP2PPort, uint nIP, ushort nPort, bool bAllowUseOfPacketRelay);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamNetworking_CreateP2PConnectionSocket, 0, CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec, bool bAllowUseOfPacketRelay);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamNetworking_CreateConnectionSocket, 0, uint nIP, ushort nPort, int nTimeoutSec);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamNetworking_DestroySocket, 0, SNetSocket_t hSocket, bool bNotifyRemoteEnd);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamNetworking_DestroyListenSocket, 0, SNetListenSocket_t hSocket, bool bNotifyRemoteEnd);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamNetworking_SendDataOnSocket, 0, SNetSocket_t hSocket, char *pubData, uint cubData, bool bReliable);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamNetworking_IsDataAvailableOnSocket, 0, SNetSocket_t hSocket, out uint pcubMsgSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamNetworking_RetrieveDataFromSocket, 0, SNetSocket_t hSocket, char *pubDest, uint cubDest, out uint pcubMsgSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamNetworking_IsDataAvailable, 0, SNetListenSocket_t hListenSocket, out uint pcubMsgSize, out SNetSocket_t phSocket);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamNetworking_RetrieveData, 0, SNetListenSocket_t hListenSocket, char *pubDest, uint cubDest, out uint pcubMsgSize, out SNetSocket_t phSocket);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamNetworking_GetSocketInfo, 0, SNetSocket_t hSocket, out CSteamID pSteamIDRemote, out int peSocketStatus, out uint punIPRemote, out ushort punPortRemote);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamNetworking_GetListenSocketInfo, 0, SNetListenSocket_t hListenSocket, out uint pnIP, out ushort pnPort);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ESNetSocketConnectionType, ISteamNetworking_GetSocketConnectionType, 0, SNetSocket_t hSocket);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamNetworking_GetMaxPacketSize, 0, SNetSocket_t hSocket);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_FileWrite, 0, char * pchFile, char *pvData, int cubData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamRemoteStorage_FileRead, 0, char * pchFile, char *pvData, int cubDataToRead);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_FileWriteAsync, 0, char * pchFile, char *pvData, uint cubData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_FileReadAsync, 0, char * pchFile, uint nOffset, uint cubToRead);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_FileReadAsyncComplete, 0, SteamAPICall_t hReadCall, char *pvBuffer, uint cubToRead);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_FileForget, 0, char * pchFile);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_FileDelete, 0, char * pchFile);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_FileShare, 0, char * pchFile);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_SetSyncPlatforms, 0, char * pchFile, ERemoteStoragePlatform eRemoteStoragePlatform);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_FileWriteStreamOpen, 0, char * pchFile);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_FileWriteStreamWriteChunk, 0, UGCFileWriteStreamHandle_t writeHandle, char *pvData, int cubData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_FileWriteStreamClose, 0, UGCFileWriteStreamHandle_t writeHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_FileWriteStreamCancel, 0, UGCFileWriteStreamHandle_t writeHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_FileExists, 0, char * pchFile);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_FilePersisted, 0, char * pchFile);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamRemoteStorage_GetFileSize, 0, char * pchFile);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(long, ISteamRemoteStorage_GetFileTimestamp, 0, char * pchFile);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ERemoteStoragePlatform, ISteamRemoteStorage_GetSyncPlatforms, 0, char * pchFile);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamRemoteStorage_GetFileCount, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamRemoteStorage_GetFileNameAndSize, 0, int iFile, out int pnFileSizeInBytes);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_GetQuota, 0, out ulong pnTotalBytes, out ulong puAvailableBytes);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_IsCloudEnabledForAccount, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_IsCloudEnabledForApp, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamRemoteStorage_SetCloudEnabledForApp, 0, bool bEnabled);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_UGCDownload, 0, UGCHandle_t hContent, uint unPriority);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_GetUGCDownloadProgress, 0, UGCHandle_t hContent, out int pnBytesDownloaded, out int pnBytesExpected);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_GetUGCDetails, 0, UGCHandle_t hContent, out AppId_t pnAppID, out IntPtr ppchName, out int pnFileSizeInBytes, out CSteamID pSteamIDOwner);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamRemoteStorage_UGCRead, 0, UGCHandle_t hContent, char *pvData, int cubDataToRead, uint cOffset, EUGCReadAction eAction);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamRemoteStorage_GetCachedUGCCount, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_GetCachedUGCHandle, 0, int iCachedContent);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_PublishWorkshopFile, 0, char * pchFile, char * pchPreviewFile, AppId_t nConsumerAppId, char * pchTitle, char * pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, IntPtr pTags, EWorkshopFileType eWorkshopFileType);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_CreatePublishedFileUpdateRequest, 0, PublishedFileId_t unPublishedFileId);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_UpdatePublishedFileFile, 0, PublishedFileUpdateHandle_t updateHandle, char * pchFile);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_UpdatePublishedFilePreviewFile, 0, PublishedFileUpdateHandle_t updateHandle, char * pchPreviewFile);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_UpdatePublishedFileTitle, 0, PublishedFileUpdateHandle_t updateHandle, char * pchTitle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_UpdatePublishedFileDescription, 0, PublishedFileUpdateHandle_t updateHandle, char * pchDescription);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_UpdatePublishedFileVisibility, 0, PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_UpdatePublishedFileTags, 0, PublishedFileUpdateHandle_t updateHandle, IntPtr pTags);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_CommitPublishedFileUpdate, 0, PublishedFileUpdateHandle_t updateHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_GetPublishedFileDetails, 0, PublishedFileId_t unPublishedFileId, uint unMaxSecondsOld);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_DeletePublishedFile, 0, PublishedFileId_t unPublishedFileId);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_EnumerateUserPublishedFiles, 0, uint unStartIndex);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_SubscribePublishedFile, 0, PublishedFileId_t unPublishedFileId);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_EnumerateUserSubscribedFiles, 0, uint unStartIndex);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_UnsubscribePublishedFile, 0, PublishedFileId_t unPublishedFileId);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription, 0, PublishedFileUpdateHandle_t updateHandle, char * pchChangeDescription);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_GetPublishedItemVoteDetails, 0, PublishedFileId_t unPublishedFileId);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_UpdateUserPublishedItemVote, 0, PublishedFileId_t unPublishedFileId, bool bVoteUp);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_GetUserPublishedItemVoteDetails, 0, PublishedFileId_t unPublishedFileId);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_EnumerateUserSharedWorkshopFiles, 0, CSteamID steamId, uint unStartIndex, IntPtr pRequiredTags, IntPtr pExcludedTags);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_PublishVideo, 0, EWorkshopVideoProvider eVideoProvider, char * pchVideoAccount, char * pchVideoIdentifier, char * pchPreviewFile, AppId_t nConsumerAppId, char * pchTitle, char * pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, IntPtr pTags);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_SetUserPublishedFileAction, 0, PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_EnumeratePublishedFilesByUserAction, 0, EWorkshopFileAction eAction, uint unStartIndex);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_EnumeratePublishedWorkshopFiles, 0, EWorkshopEnumerationType eEnumerationType, uint unStartIndex, uint unCount, uint unDays, IntPtr pTags, IntPtr pUserTags);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamRemoteStorage_UGCDownloadToLocation, 0, UGCHandle_t hContent, char * pchLocation, uint unPriority);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamScreenshots_WriteScreenshot, 0, char *pubRGB, uint cubRGB, int nWidth, int nHeight);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamScreenshots_AddScreenshotToLibrary, 0, char * pchFilename, char * pchThumbnailFilename, int nWidth, int nHeight);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamScreenshots_TriggerScreenshot, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamScreenshots_HookScreenshots, 0, bool bHook);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamScreenshots_SetLocation, 0, ScreenshotHandle hScreenshot, char * pchLocation);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamScreenshots_TagUser, 0, ScreenshotHandle hScreenshot, CSteamID steamID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamScreenshots_TagPublishedFile, 0, ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamScreenshots_IsScreenshotsHooked, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamScreenshots_AddVRScreenshotToLibrary, 0, EVRScreenshotType eType, char * pchFilename, char * pchVRFilename);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUGC_CreateQueryUserUGCRequest, 0, AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint unPage);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUGC_CreateQueryAllUGCRequest, 0, EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint unPage);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUGC_CreateQueryUGCDetailsRequest, 0, PublishedFileId_t* pvecPublishedFileID, uint unNumPublishedFileIDs);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUGC_SendQueryUGCRequest, 0, UGCQueryHandle_t handle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_GetQueryUGCResult, 0, UGCQueryHandle_t handle, uint index, out SteamUGCDetails_t pDetails);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_GetQueryUGCPreviewURL, 0, UGCQueryHandle_t handle, uint index, IntPtr pchURL, uint cchURLSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_GetQueryUGCMetadata, 0, UGCQueryHandle_t handle, uint index, IntPtr pchMetadata, uint cchMetadatasize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_GetQueryUGCChildren, 0, UGCQueryHandle_t handle, uint index, PublishedFileId_t* pvecPublishedFileID, uint cMaxEntries);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_GetQueryUGCStatistic, 0, UGCQueryHandle_t handle, uint index, EItemStatistic eStatType, out ulong pStatValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamUGC_GetQueryUGCNumAdditionalPreviews, 0, UGCQueryHandle_t handle, uint index);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_GetQueryUGCAdditionalPreview, 0, UGCQueryHandle_t handle, uint index, uint previewIndex, IntPtr pchURLOrVideoID, uint cchURLSize, IntPtr pchOriginalFileName, uint cchOriginalFileNameSize, out EItemPreviewType pPreviewType);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamUGC_GetQueryUGCNumKeyValueTags, 0, UGCQueryHandle_t handle, uint index);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_GetQueryUGCKeyValueTag, 0, UGCQueryHandle_t handle, uint index, uint keyValueTagIndex, IntPtr pchKey, uint cchKeySize, IntPtr pchValue, uint cchValueSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_ReleaseQueryUGCRequest, 0, UGCQueryHandle_t handle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_AddRequiredTag, 0, UGCQueryHandle_t handle, char * pTagName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_AddExcludedTag, 0, UGCQueryHandle_t handle, char * pTagName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetReturnOnlyIDs, 0, UGCQueryHandle_t handle, bool bReturnOnlyIDs);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetReturnKeyValueTags, 0, UGCQueryHandle_t handle, bool bReturnKeyValueTags);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetReturnLongDescription, 0, UGCQueryHandle_t handle, bool bReturnLongDescription);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetReturnMetadata, 0, UGCQueryHandle_t handle, bool bReturnMetadata);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetReturnChildren, 0, UGCQueryHandle_t handle, bool bReturnChildren);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetReturnAdditionalPreviews, 0, UGCQueryHandle_t handle, bool bReturnAdditionalPreviews);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetReturnTotalOnly, 0, UGCQueryHandle_t handle, bool bReturnTotalOnly);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetLanguage, 0, UGCQueryHandle_t handle, char * pchLanguage);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetAllowCachedResponse, 0, UGCQueryHandle_t handle, uint unMaxAgeSeconds);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetCloudFileNameFilter, 0, UGCQueryHandle_t handle, char * pMatchCloudFileName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetMatchAnyTag, 0, UGCQueryHandle_t handle, bool bMatchAnyTag);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetSearchText, 0, UGCQueryHandle_t handle, char * pSearchText);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetRankedByTrendDays, 0, UGCQueryHandle_t handle, uint unDays);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_AddRequiredKeyValueTag, 0, UGCQueryHandle_t handle, char * pKey, char * pValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUGC_RequestUGCDetails, 0, PublishedFileId_t nPublishedFileID, uint unMaxAgeSeconds);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUGC_CreateItem, 0, AppId_t nConsumerAppId, EWorkshopFileType eFileType);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUGC_StartItemUpdate, 0, AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetItemTitle, 0, UGCUpdateHandle_t handle, char * pchTitle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetItemDescription, 0, UGCUpdateHandle_t handle, char * pchDescription);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetItemUpdateLanguage, 0, UGCUpdateHandle_t handle, char * pchLanguage);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetItemMetadata, 0, UGCUpdateHandle_t handle, char * pchMetaData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetItemVisibility, 0, UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetItemTags, 0, UGCUpdateHandle_t updateHandle, IntPtr pTags);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetItemContent, 0, UGCUpdateHandle_t handle, char * pszContentFolder);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_SetItemPreview, 0, UGCUpdateHandle_t handle, char * pszPreviewFile);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_RemoveItemKeyValueTags, 0, UGCUpdateHandle_t handle, char * pchKey);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_AddItemKeyValueTag, 0, UGCUpdateHandle_t handle, char * pchKey, char * pchValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_AddItemPreviewFile, 0, UGCUpdateHandle_t handle, char * pszPreviewFile, EItemPreviewType type);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_AddItemPreviewVideo, 0, UGCUpdateHandle_t handle, char * pszVideoID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_UpdateItemPreviewFile, 0, UGCUpdateHandle_t handle, uint index, char * pszPreviewFile);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_UpdateItemPreviewVideo, 0, UGCUpdateHandle_t handle, uint index, char * pszVideoID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_RemoveItemPreview, 0, UGCUpdateHandle_t handle, uint index);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUGC_SubmitItemUpdate, 0, UGCUpdateHandle_t handle, char * pchChangeNote);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(EItemUpdateStatus, ISteamUGC_GetItemUpdateProgress, 0, UGCUpdateHandle_t handle, out ulong punBytesProcessed, out ulong punBytesTotal);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUGC_SetUserItemVote, 0, PublishedFileId_t nPublishedFileID, bool bVoteUp);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUGC_GetUserItemVote, 0, PublishedFileId_t nPublishedFileID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUGC_AddItemToFavorites, 0, AppId_t nAppId, PublishedFileId_t nPublishedFileID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUGC_RemoveItemFromFavorites, 0, AppId_t nAppId, PublishedFileId_t nPublishedFileID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUGC_SubscribeItem, 0, PublishedFileId_t nPublishedFileID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUGC_UnsubscribeItem, 0, PublishedFileId_t nPublishedFileID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamUGC_GetNumSubscribedItems, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamUGC_GetSubscribedItems, 0, PublishedFileId_t* pvecPublishedFileID, uint cMaxEntries);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamUGC_GetItemState, 0, PublishedFileId_t nPublishedFileID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_GetItemInstallInfo, 0, PublishedFileId_t nPublishedFileID, out ulong punSizeOnDisk, IntPtr pchFolder, uint cchFolderSize, out uint punTimeStamp);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_GetItemDownloadInfo, 0, PublishedFileId_t nPublishedFileID, out ulong punBytesDownloaded, out ulong punBytesTotal);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_DownloadItem, 0, PublishedFileId_t nPublishedFileID, bool bHighPriority);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUGC_BInitWorkshopForGameServer, 0, DepotId_t unWorkshopDepotID, char * pszFolder);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamUGC_SuspendDownloads, 0, bool bSuspend);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUGC_StartPlaytimeTracking, 0, PublishedFileId_t* pvecPublishedFileID, uint unNumPublishedFileIDs);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUGC_StopPlaytimeTracking, 0, PublishedFileId_t* pvecPublishedFileID, uint unNumPublishedFileIDs);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUGC_StopPlaytimeTrackingForAllItems, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUnifiedMessages_SendMethod, 0, char * pchServiceMethod, char *pRequestBuffer, uint unRequestBufferSize, ulong unContext);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUnifiedMessages_GetMethodResponseInfo, 0, ClientUnifiedMessageHandle hHandle, out uint punResponseSize, out EResult peResult);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUnifiedMessages_GetMethodResponseData, 0, ClientUnifiedMessageHandle hHandle, char *pResponseBuffer, uint unResponseBufferSize, bool bAutoRelease);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUnifiedMessages_ReleaseMethod, 0, ClientUnifiedMessageHandle hHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUnifiedMessages_SendNotification, 0, char * pchServiceNotification, char *pNotificationBuffer, uint unNotificationBufferSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamUser_GetHSteamUser, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUser_BLoggedOn, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUser_GetSteamID, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamUser_InitiateGameConnection, 0, char *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint unIPServer, ushort usPortServer, bool bSecure);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamUser_TerminateGameConnection, 0, uint unIPServer, ushort usPortServer);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamUser_TrackAppUsageEvent, 0, CGameID gameID, int eAppUsageEvent, char * pchExtraInfo);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUser_GetUserDataFolder, 0, IntPtr pchBuffer, int cubBuffer);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamUser_StartVoiceRecording, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamUser_StopVoiceRecording, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(EVoiceResult, ISteamUser_GetAvailableVoice, 0, out uint pcbCompressed, out uint pcbUncompressed, uint nUncompressedVoiceDesiredSampleRate);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(EVoiceResult, ISteamUser_GetVoice, 0, bool bWantCompressed, char *pDestBuffer, uint cbDestBufferSize, out uint nBytesWritten, bool bWantUncompressed, char *pUncompressedDestBuffer, uint cbUncompressedDestBufferSize, out uint nUncompressBytesWritten, uint nUncompressedVoiceDesiredSampleRate);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(EVoiceResult, ISteamUser_DecompressVoice, 0, char *pCompressed, uint cbCompressed, char *pDestBuffer, uint cbDestBufferSize, out uint nBytesWritten, uint nDesiredSampleRate);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamUser_GetVoiceOptimalSampleRate, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamUser_GetAuthSessionTicket, 0, char *pTicket, int cbMaxTicket, out uint pcbTicket);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(EBeginAuthSessionResult, ISteamUser_BeginAuthSession, 0, char *pAuthTicket, int cbAuthTicket, CSteamID steamID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamUser_EndAuthSession, 0, CSteamID steamID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamUser_CancelAuthTicket, 0, HAuthTicket hAuthTicket);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(EUserHasLicenseForAppResult, ISteamUser_UserHasLicenseForApp, 0, CSteamID steamID, AppId_t appID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUser_BIsBehindNAT, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamUser_AdvertiseGame, 0, CSteamID steamIDGameServer, uint unIPServer, ushort usPortServer);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUser_RequestEncryptedAppTicket, 0, char *pDataToInclude, int cbDataToInclude);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUser_GetEncryptedAppTicket, 0, char *pTicket, int cbMaxTicket, out uint pcbTicket);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamUser_GetGameBadgeLevel, 0, int nSeries, bool bFoil);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamUser_GetPlayerSteamLevel, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUser_RequestStoreAuthURL, 0, char * pchRedirectURL);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUser_BIsPhoneVerified, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUser_BIsTwoFactorEnabled, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUser_BIsPhoneIdentifying, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUser_BIsPhoneRequiringVerification, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_RequestCurrentStats, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_GetStat, 0, char * pchName, out int pData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_GetStat_, 0, char * pchName, out float pData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_SetStat, 0, char * pchName, int nData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_SetStat_, 0, char * pchName, float fData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_UpdateAvgRateStat, 0, char * pchName, float flCountThisSession, double dSessionLength);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_GetAchievement, 0, char * pchName, out bool pbAchieved);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_SetAchievement, 0, char * pchName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_ClearAchievement, 0, char * pchName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_GetAchievementAndUnlockTime, 0, char * pchName, out bool pbAchieved, out uint punUnlockTime);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_StoreStats, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamUserStats_GetAchievementIcon, 0, char * pchName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamUserStats_GetAchievementDisplayAttribute, 0, char * pchName, char * pchKey);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_IndicateAchievementProgress, 0, char * pchName, uint nCurProgress, uint nMaxProgress);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamUserStats_GetNumAchievements, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamUserStats_GetAchievementName, 0, uint iAchievement);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUserStats_RequestUserStats, 0, CSteamID steamIDUser);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_GetUserStat, 0, CSteamID steamIDUser, char * pchName, out int pData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_GetUserStat_, 0, CSteamID steamIDUser, char * pchName, out float pData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_GetUserAchievement, 0, CSteamID steamIDUser, char * pchName, out bool pbAchieved);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_GetUserAchievementAndUnlockTime, 0, CSteamID steamIDUser, char * pchName, out bool pbAchieved, out uint punUnlockTime);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_ResetAllStats, 0, bool bAchievementsToo);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUserStats_FindOrCreateLeaderboard, 0, char * pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUserStats_FindLeaderboard, 0, char * pchLeaderboardName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamUserStats_GetLeaderboardName, 0, SteamLeaderboard_t hSteamLeaderboard);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamUserStats_GetLeaderboardEntryCount, 0, SteamLeaderboard_t hSteamLeaderboard);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ELeaderboardSortMethod, ISteamUserStats_GetLeaderboardSortMethod, 0, SteamLeaderboard_t hSteamLeaderboard);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ELeaderboardDisplayType, ISteamUserStats_GetLeaderboardDisplayType, 0, SteamLeaderboard_t hSteamLeaderboard);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUserStats_DownloadLeaderboardEntries, 0, SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUserStats_DownloadLeaderboardEntriesForUsers, 0, SteamLeaderboard_t hSteamLeaderboard, CSteamID* prgUsers, int cUsers);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_GetDownloadedLeaderboardEntry, 0, SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, out LeaderboardEntry_t pLeaderboardEntry, int* pDetails, int cDetailsMax);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUserStats_UploadLeaderboardScore, 0, SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int nScore, int* pScoreDetails, int cScoreDetailsCount);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUserStats_AttachLeaderboardUGC, 0, SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUserStats_GetNumberOfCurrentPlayers, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUserStats_RequestGlobalAchievementPercentages, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamUserStats_GetMostAchievedAchievementInfo, 0, IntPtr pchName, uint unNameBufLen, out float pflPercent, out bool pbAchieved);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamUserStats_GetNextMostAchievedAchievementInfo, 0, int iIteratorPrevious, IntPtr pchName, uint unNameBufLen, out float pflPercent, out bool pbAchieved);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_GetAchievementAchievedPercent, 0, char * pchName, out float pflPercent);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUserStats_RequestGlobalStats, 0, int nHistoryDays);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_GetGlobalStat, 0, char * pchStatName, out long pData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUserStats_GetGlobalStat_, 0, char * pchStatName, out double pData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamUserStats_GetGlobalStatHistory, 0, char * pchStatName, long* pData, uint cubData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamUserStats_GetGlobalStatHistory_, 0, char * pchStatName, double* pData, uint cubData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamUtils_GetSecondsSinceAppActive, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamUtils_GetSecondsSinceComputerActive, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(EUniverse, ISteamUtils_GetConnectedUniverse, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamUtils_GetServerRealTime, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamUtils_GetIPCountry, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUtils_GetImageSize, 0, int iImage, out uint pnWidth, out uint pnHeight);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUtils_GetImageRGBA, 0, int iImage, char *pubDest, int nDestBufferSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUtils_GetCSERIPPort, 0, out uint unIP, out ushort usPort);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(byte, ISteamUtils_GetCurrentBatteryPower, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamUtils_GetAppID, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamUtils_SetOverlayNotificationPosition, 0, ENotificationPosition eNotificationPosition);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUtils_IsAPICallCompleted, 0, SteamAPICall_t hSteamAPICall, out bool pbFailed);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ESteamAPICallFailure, ISteamUtils_GetAPICallFailureReason, 0, SteamAPICall_t hSteamAPICall);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUtils_GetAPICallResult, 0, SteamAPICall_t hSteamAPICall, IntPtr pCallback, int cubCallback, int iCallbackExpected, out bool pbFailed);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamUtils_GetIPCCallCount, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamUtils_SetWarningMessageHook, 0, SteamAPIWarningMessageHook_t pFunction);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUtils_IsOverlayEnabled, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUtils_BOverlayNeedsPresent, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamUtils_CheckFileSignature, 0, char * szFileName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUtils_ShowGamepadTextInput, 0, EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, char * pchDescription, uint unCharMax, char * pchExistingText);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamUtils_GetEnteredGamepadTextLength, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUtils_GetEnteredGamepadTextInput, 0, IntPtr pchText, uint cchText);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamUtils_GetSteamUILanguage, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUtils_IsSteamRunningInVR, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamUtils_SetOverlayNotificationInset, 0, int nHorizontalInset, int nVerticalInset);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamUtils_IsSteamInBigPictureMode, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamUtils_StartVRDashboard, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamVideo_GetVideoURL, 0, AppId_t unVideoAppID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamVideo_IsBroadcasting, 0, out int pnNumViewers);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServerHTTP_CreateHTTPRequest, 0, EHTTPMethod eHTTPRequestMethod, char * pchAbsoluteURL);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_SetHTTPRequestContextValue, 0, HTTPRequestHandle hRequest, ulong ulContextValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_SetHTTPRequestNetworkActivityTimeout, 0, HTTPRequestHandle hRequest, uint unTimeoutSeconds);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_SetHTTPRequestHeaderValue, 0, HTTPRequestHandle hRequest, char * pchHeaderName, char * pchHeaderValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_SetHTTPRequestGetOrPostParameter, 0, HTTPRequestHandle hRequest, char * pchParamName, char * pchParamValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_SendHTTPRequest, 0, HTTPRequestHandle hRequest, out SteamAPICall_t pCallHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_SendHTTPRequestAndStreamResponse, 0, HTTPRequestHandle hRequest, out SteamAPICall_t pCallHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_DeferHTTPRequest, 0, HTTPRequestHandle hRequest);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_PrioritizeHTTPRequest, 0, HTTPRequestHandle hRequest);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_GetHTTPResponseHeaderSize, 0, HTTPRequestHandle hRequest, char * pchHeaderName, out uint unResponseHeaderSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_GetHTTPResponseHeaderValue, 0, HTTPRequestHandle hRequest, char * pchHeaderName, char *pHeaderValueBuffer, uint unBufferSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_GetHTTPResponseBodySize, 0, HTTPRequestHandle hRequest, out uint unBodySize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_GetHTTPResponseBodyData, 0, HTTPRequestHandle hRequest, char *pBodyDataBuffer, uint unBufferSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_GetHTTPStreamingResponseBodyData, 0, HTTPRequestHandle hRequest, uint cOffset, char *pBodyDataBuffer, uint unBufferSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_ReleaseHTTPRequest, 0, HTTPRequestHandle hRequest);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_GetHTTPDownloadProgressPct, 0, HTTPRequestHandle hRequest, out float pflPercentOut);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_SetHTTPRequestRawPostBody, 0, HTTPRequestHandle hRequest, char * pchContentType, char *pubBody, uint unBodyLen);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServerHTTP_CreateCookieContainer, 0, bool bAllowResponsesToModify);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_ReleaseCookieContainer, 0, HTTPCookieContainerHandle hCookieContainer);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_SetCookie, 0, HTTPCookieContainerHandle hCookieContainer, char * pchHost, char * pchUrl, char * pchCookie);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_SetHTTPRequestCookieContainer, 0, HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_SetHTTPRequestUserAgentInfo, 0, HTTPRequestHandle hRequest, char * pchUserAgentInfo);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_SetHTTPRequestRequiresVerifiedCertificate, 0, HTTPRequestHandle hRequest, bool bRequireVerifiedCertificate);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_SetHTTPRequestAbsoluteTimeoutMS, 0, HTTPRequestHandle hRequest, uint unMilliseconds);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerHTTP_GetHTTPRequestWasTimedOut, 0, HTTPRequestHandle hRequest, out bool pbWasTimedOut);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(EResult, ISteamGameServerInventory_GetResultStatus, 0, SteamInventoryResult_t resultHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerInventory_GetResultItems, 0, SteamInventoryResult_t resultHandle, SteamItemDetails_t* pOutItemsArray, ref uint punOutItemsArraySize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServerInventory_GetResultTimestamp, 0, SteamInventoryResult_t resultHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerInventory_CheckResultSteamID, 0, SteamInventoryResult_t resultHandle, CSteamID steamIDExpected);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServerInventory_DestroyResult, 0, SteamInventoryResult_t resultHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerInventory_GetAllItems, 0, out SteamInventoryResult_t pResultHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerInventory_GetItemsByID, 0, out SteamInventoryResult_t pResultHandle, SteamItemInstanceID_t* pInstanceIDs, uint unCountInstanceIDs);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerInventory_SerializeResult, 0, SteamInventoryResult_t resultHandle, char *pOutBuffer, out uint punOutBufferSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerInventory_DeserializeResult, 0, out SteamInventoryResult_t pOutResultHandle, char *pBuffer, uint unBufferSize, bool bRESERVED_MUST_BE_FALSE);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerInventory_GenerateItems, 0, out SteamInventoryResult_t pResultHandle, SteamItemDef_t* pArrayItemDefs, uint* punArrayQuantity, uint unArrayLength);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerInventory_GrantPromoItems, 0, out SteamInventoryResult_t pResultHandle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerInventory_AddPromoItem, 0, out SteamInventoryResult_t pResultHandle, SteamItemDef_t itemDef);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerInventory_AddPromoItems, 0, out SteamInventoryResult_t pResultHandle, SteamItemDef_t* pArrayItemDefs, uint unArrayLength);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerInventory_ConsumeItem, 0, out SteamInventoryResult_t pResultHandle, SteamItemInstanceID_t itemConsume, uint unQuantity);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerInventory_ExchangeItems, 0, out SteamInventoryResult_t pResultHandle, SteamItemDef_t* pArrayGenerate, uint* punArrayGenerateQuantity, uint unArrayGenerateLength, SteamItemInstanceID_t* pArrayDestroy, uint* punArrayDestroyQuantity, uint unArrayDestroyLength);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerInventory_TransferItemQuantity, 0, out SteamInventoryResult_t pResultHandle, SteamItemInstanceID_t itemIdSource, uint unQuantity, SteamItemInstanceID_t itemIdDest);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServerInventory_SendItemDropHeartbeat, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerInventory_TriggerItemDrop, 0, out SteamInventoryResult_t pResultHandle, SteamItemDef_t dropListDefinition);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerInventory_TradeItems, 0, out SteamInventoryResult_t pResultHandle, CSteamID steamIDTradePartner, SteamItemInstanceID_t* pArrayGive, uint* pArrayGiveQuantity, uint nArrayGiveLength, SteamItemInstanceID_t* pArrayGet, uint* pArrayGetQuantity, uint nArrayGetLength);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerInventory_LoadItemDefinitions, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerInventory_GetItemDefinitionIDs, 0, SteamItemDef_t* pItemDefIDs, out uint punItemDefIDsArraySize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerInventory_GetItemDefinitionProperty, 0, SteamItemDef_t iDefinition, char * pchPropertyName, IntPtr pchValueBuffer, ref uint punValueBufferSizeOut);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerNetworking_SendP2PPacket, 0, CSteamID steamIDRemote, char *pubData, uint cubData, EP2PSend eP2PSendType, int nChannel);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerNetworking_IsP2PPacketAvailable, 0, out uint pcubMsgSize, int nChannel);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerNetworking_ReadP2PPacket, 0, char *pubDest, uint cubDest, out uint pcubMsgSize, out CSteamID psteamIDRemote, int nChannel);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerNetworking_AcceptP2PSessionWithUser, 0, CSteamID steamIDRemote);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerNetworking_CloseP2PSessionWithUser, 0, CSteamID steamIDRemote);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerNetworking_CloseP2PChannelWithUser, 0, CSteamID steamIDRemote, int nChannel);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerNetworking_GetP2PSessionState, 0, CSteamID steamIDRemote, out P2PSessionState_t pConnectionState);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerNetworking_AllowP2PPacketRelay, 0, bool bAllow);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServerNetworking_CreateListenSocket, 0, int nVirtualP2PPort, uint nIP, ushort nPort, bool bAllowUseOfPacketRelay);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServerNetworking_CreateP2PConnectionSocket, 0, CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec, bool bAllowUseOfPacketRelay);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServerNetworking_CreateConnectionSocket, 0, uint nIP, ushort nPort, int nTimeoutSec);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerNetworking_DestroySocket, 0, SNetSocket_t hSocket, bool bNotifyRemoteEnd);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerNetworking_DestroyListenSocket, 0, SNetListenSocket_t hSocket, bool bNotifyRemoteEnd);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerNetworking_SendDataOnSocket, 0, SNetSocket_t hSocket, char *pubData, uint cubData, bool bReliable);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerNetworking_IsDataAvailableOnSocket, 0, SNetSocket_t hSocket, out uint pcubMsgSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerNetworking_RetrieveDataFromSocket, 0, SNetSocket_t hSocket, char *pubDest, uint cubDest, out uint pcubMsgSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerNetworking_IsDataAvailable, 0, SNetListenSocket_t hListenSocket, out uint pcubMsgSize, out SNetSocket_t phSocket);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerNetworking_RetrieveData, 0, SNetListenSocket_t hListenSocket, char *pubDest, uint cubDest, out uint pcubMsgSize, out SNetSocket_t phSocket);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerNetworking_GetSocketInfo, 0, SNetSocket_t hSocket, out CSteamID pSteamIDRemote, out int peSocketStatus, out uint punIPRemote, out ushort punPortRemote);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerNetworking_GetListenSocketInfo, 0, SNetListenSocket_t hListenSocket, out uint pnIP, out ushort pnPort);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ESNetSocketConnectionType, ISteamGameServerNetworking_GetSocketConnectionType, 0, SNetSocket_t hSocket);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(int, ISteamGameServerNetworking_GetMaxPacketSize, 0, SNetSocket_t hSocket);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerUGC_CreateQueryUserUGCRequest, 0, AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint unPage);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerUGC_CreateQueryAllUGCRequest, 0, EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint unPage);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerUGC_CreateQueryUGCDetailsRequest, 0, PublishedFileId_t* pvecPublishedFileID, uint unNumPublishedFileIDs);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerUGC_SendQueryUGCRequest, 0, UGCQueryHandle_t handle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_GetQueryUGCResult, 0, UGCQueryHandle_t handle, uint index, out SteamUGCDetails_t pDetails);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_GetQueryUGCPreviewURL, 0, UGCQueryHandle_t handle, uint index, IntPtr pchURL, uint cchURLSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_GetQueryUGCMetadata, 0, UGCQueryHandle_t handle, uint index, IntPtr pchMetadata, uint cchMetadatasize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_GetQueryUGCChildren, 0, UGCQueryHandle_t handle, uint index, PublishedFileId_t* pvecPublishedFileID, uint cMaxEntries);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_GetQueryUGCStatistic, 0, UGCQueryHandle_t handle, uint index, EItemStatistic eStatType, out ulong pStatValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServerUGC_GetQueryUGCNumAdditionalPreviews, 0, UGCQueryHandle_t handle, uint index);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_GetQueryUGCAdditionalPreview, 0, UGCQueryHandle_t handle, uint index, uint previewIndex, IntPtr pchURLOrVideoID, uint cchURLSize, IntPtr pchOriginalFileName, uint cchOriginalFileNameSize, out EItemPreviewType pPreviewType);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServerUGC_GetQueryUGCNumKeyValueTags, 0, UGCQueryHandle_t handle, uint index);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_GetQueryUGCKeyValueTag, 0, UGCQueryHandle_t handle, uint index, uint keyValueTagIndex, IntPtr pchKey, uint cchKeySize, IntPtr pchValue, uint cchValueSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_ReleaseQueryUGCRequest, 0, UGCQueryHandle_t handle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_AddRequiredTag, 0, UGCQueryHandle_t handle, char * pTagName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_AddExcludedTag, 0, UGCQueryHandle_t handle, char * pTagName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetReturnOnlyIDs, 0, UGCQueryHandle_t handle, bool bReturnOnlyIDs);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetReturnKeyValueTags, 0, UGCQueryHandle_t handle, bool bReturnKeyValueTags);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetReturnLongDescription, 0, UGCQueryHandle_t handle, bool bReturnLongDescription);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetReturnMetadata, 0, UGCQueryHandle_t handle, bool bReturnMetadata);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetReturnChildren, 0, UGCQueryHandle_t handle, bool bReturnChildren);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetReturnAdditionalPreviews, 0, UGCQueryHandle_t handle, bool bReturnAdditionalPreviews);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetReturnTotalOnly, 0, UGCQueryHandle_t handle, bool bReturnTotalOnly);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetLanguage, 0, UGCQueryHandle_t handle, char * pchLanguage);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetAllowCachedResponse, 0, UGCQueryHandle_t handle, uint unMaxAgeSeconds);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetCloudFileNameFilter, 0, UGCQueryHandle_t handle, char * pMatchCloudFileName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetMatchAnyTag, 0, UGCQueryHandle_t handle, bool bMatchAnyTag);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetSearchText, 0, UGCQueryHandle_t handle, char * pSearchText);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetRankedByTrendDays, 0, UGCQueryHandle_t handle, uint unDays);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_AddRequiredKeyValueTag, 0, UGCQueryHandle_t handle, char * pKey, char * pValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerUGC_RequestUGCDetails, 0, PublishedFileId_t nPublishedFileID, uint unMaxAgeSeconds);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerUGC_CreateItem, 0, AppId_t nConsumerAppId, EWorkshopFileType eFileType);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerUGC_StartItemUpdate, 0, AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetItemTitle, 0, UGCUpdateHandle_t handle, char * pchTitle);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetItemDescription, 0, UGCUpdateHandle_t handle, char * pchDescription);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetItemUpdateLanguage, 0, UGCUpdateHandle_t handle, char * pchLanguage);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetItemMetadata, 0, UGCUpdateHandle_t handle, char * pchMetaData);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetItemVisibility, 0, UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetItemTags, 0, UGCUpdateHandle_t updateHandle, IntPtr pTags);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetItemContent, 0, UGCUpdateHandle_t handle, char * pszContentFolder);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_SetItemPreview, 0, UGCUpdateHandle_t handle, char * pszPreviewFile);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_RemoveItemKeyValueTags, 0, UGCUpdateHandle_t handle, char * pchKey);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_AddItemKeyValueTag, 0, UGCUpdateHandle_t handle, char * pchKey, char * pchValue);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_AddItemPreviewFile, 0, UGCUpdateHandle_t handle, char * pszPreviewFile, EItemPreviewType type);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_AddItemPreviewVideo, 0, UGCUpdateHandle_t handle, char * pszVideoID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_UpdateItemPreviewFile, 0, UGCUpdateHandle_t handle, uint index, char * pszPreviewFile);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_UpdateItemPreviewVideo, 0, UGCUpdateHandle_t handle, uint index, char * pszVideoID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_RemoveItemPreview, 0, UGCUpdateHandle_t handle, uint index);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerUGC_SubmitItemUpdate, 0, UGCUpdateHandle_t handle, char * pchChangeNote);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(EItemUpdateStatus, ISteamGameServerUGC_GetItemUpdateProgress, 0, UGCUpdateHandle_t handle, out ulong punBytesProcessed, out ulong punBytesTotal);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerUGC_SetUserItemVote, 0, PublishedFileId_t nPublishedFileID, bool bVoteUp);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerUGC_GetUserItemVote, 0, PublishedFileId_t nPublishedFileID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerUGC_AddItemToFavorites, 0, AppId_t nAppId, PublishedFileId_t nPublishedFileID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerUGC_RemoveItemFromFavorites, 0, AppId_t nAppId, PublishedFileId_t nPublishedFileID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerUGC_SubscribeItem, 0, PublishedFileId_t nPublishedFileID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerUGC_UnsubscribeItem, 0, PublishedFileId_t nPublishedFileID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServerUGC_GetNumSubscribedItems, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServerUGC_GetSubscribedItems, 0, PublishedFileId_t* pvecPublishedFileID, uint cMaxEntries);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServerUGC_GetItemState, 0, PublishedFileId_t nPublishedFileID);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_GetItemInstallInfo, 0, PublishedFileId_t nPublishedFileID, out ulong punSizeOnDisk, IntPtr pchFolder, uint cchFolderSize, out uint punTimeStamp);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_GetItemDownloadInfo, 0, PublishedFileId_t nPublishedFileID, out ulong punBytesDownloaded, out ulong punBytesTotal);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_DownloadItem, 0, PublishedFileId_t nPublishedFileID, bool bHighPriority);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUGC_BInitWorkshopForGameServer, 0, DepotId_t unWorkshopDepotID, char * pszFolder);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServerUGC_SuspendDownloads, 0, bool bSuspend);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerUGC_StartPlaytimeTracking, 0, PublishedFileId_t* pvecPublishedFileID, uint unNumPublishedFileIDs);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerUGC_StopPlaytimeTracking, 0, PublishedFileId_t* pvecPublishedFileID, uint unNumPublishedFileIDs);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerUGC_StopPlaytimeTrackingForAllItems, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServerUtils_GetSecondsSinceAppActive, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServerUtils_GetSecondsSinceComputerActive, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(EUniverse, ISteamGameServerUtils_GetConnectedUniverse, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServerUtils_GetServerRealTime, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamGameServerUtils_GetIPCountry, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUtils_GetImageSize, 0, int iImage, out uint pnWidth, out uint pnHeight);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUtils_GetImageRGBA, 0, int iImage, char *pubDest, int nDestBufferSize);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUtils_GetCSERIPPort, 0, out uint unIP, out ushort usPort);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(byte, ISteamGameServerUtils_GetCurrentBatteryPower, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServerUtils_GetAppID, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServerUtils_SetOverlayNotificationPosition, 0, ENotificationPosition eNotificationPosition);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUtils_IsAPICallCompleted, 0, SteamAPICall_t hSteamAPICall, out bool pbFailed);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ESteamAPICallFailure, ISteamGameServerUtils_GetAPICallFailureReason, 0, SteamAPICall_t hSteamAPICall);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUtils_GetAPICallResult, 0, SteamAPICall_t hSteamAPICall, IntPtr pCallback, int cubCallback, int iCallbackExpected, out bool pbFailed);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServerUtils_GetIPCCallCount, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServerUtils_SetWarningMessageHook, 0, SteamAPIWarningMessageHook_t pFunction);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUtils_IsOverlayEnabled, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUtils_BOverlayNeedsPresent, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(ulong, ISteamGameServerUtils_CheckFileSignature, 0, char * szFileName);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUtils_ShowGamepadTextInput, 0, EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, char * pchDescription, uint unCharMax, char * pchExistingText);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(uint, ISteamGameServerUtils_GetEnteredGamepadTextLength, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUtils_GetEnteredGamepadTextInput, 0, IntPtr pchText, uint cchText);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(IntPtr, ISteamGameServerUtils_GetSteamUILanguage, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUtils_IsSteamRunningInVR, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServerUtils_SetOverlayNotificationInset, 0, int nHorizontalInset, int nVerticalInset);

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(bool, ISteamGameServerUtils_IsSteamInBigPictureMode, 0, );

// [DllImport("CSteamworks", CallingConvention = CallingConvention.Cdecl)]
STUB(void, ISteamGameServerUtils_StartVRDashboard, 0, );
