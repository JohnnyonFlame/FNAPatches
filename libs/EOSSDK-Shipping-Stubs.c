#include <stdio.h>
#include <stdint.h>

#define NotImplemented 0x10

typedef char bool;
typedef char *string;
typedef uint32_t uint;
typedef uint64_t ulong;
typedef uint16_t ushort;
typedef intptr_t IntPtr;
typedef uint AppId_t;
typedef char byte;
typedef int Result;
#define out
#define ref
#ifndef NDEBUG
#define STUB(t, x, v, ...) t x( __VA_ARGS__ ) { printf("[stub] %s\n", __FUNCTION__); return v; };
#else
#define STUB(t, x, v, ...) t x( __VA_ARGS__ ) { return v; };
#endif

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_Achievements_AddNotifyAchievementsUnlocked(IntPtr handle, IntPtr options, IntPtr clientData, OnAchievementsUnlockedCallbackInternal notificationFn);
STUB(ulong, EOS_Achievements_AddNotifyAchievementsUnlocked, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_Achievements_AddNotifyAchievementsUnlockedV2(IntPtr handle, IntPtr options, IntPtr clientData, OnAchievementsUnlockedCallbackV2Internal notificationFn);
STUB(ulong, EOS_Achievements_AddNotifyAchievementsUnlockedV2, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Achievements_CopyAchievementDefinitionByAchievementId(IntPtr handle, IntPtr options, ref IntPtr outDefinition);
STUB(Result, EOS_Achievements_CopyAchievementDefinitionByAchievementId, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outDefinition);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Achievements_CopyAchievementDefinitionByIndex(IntPtr handle, IntPtr options, ref IntPtr outDefinition);
STUB(Result, EOS_Achievements_CopyAchievementDefinitionByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outDefinition);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Achievements_CopyAchievementDefinitionV2ByAchievementId(IntPtr handle, IntPtr options, ref IntPtr outDefinition);
STUB(Result, EOS_Achievements_CopyAchievementDefinitionV2ByAchievementId, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outDefinition);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Achievements_CopyAchievementDefinitionV2ByIndex(IntPtr handle, IntPtr options, ref IntPtr outDefinition);
STUB(Result, EOS_Achievements_CopyAchievementDefinitionV2ByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outDefinition);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Achievements_CopyPlayerAchievementByAchievementId(IntPtr handle, IntPtr options, ref IntPtr outAchievement);
STUB(Result, EOS_Achievements_CopyPlayerAchievementByAchievementId, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outAchievement);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Achievements_CopyPlayerAchievementByIndex(IntPtr handle, IntPtr options, ref IntPtr outAchievement);
STUB(Result, EOS_Achievements_CopyPlayerAchievementByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outAchievement);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Achievements_CopyUnlockedAchievementByAchievementId(IntPtr handle, IntPtr options, ref IntPtr outAchievement);
STUB(Result, EOS_Achievements_CopyUnlockedAchievementByAchievementId, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outAchievement);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Achievements_CopyUnlockedAchievementByIndex(IntPtr handle, IntPtr options, ref IntPtr outAchievement);
STUB(Result, EOS_Achievements_CopyUnlockedAchievementByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outAchievement);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Achievements_DefinitionV2_Release(IntPtr achievementDefinition);
STUB(void, EOS_Achievements_DefinitionV2_Release, 0, IntPtr achievementDefinition);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Achievements_Definition_Release(IntPtr achievementDefinition);
STUB(void, EOS_Achievements_Definition_Release, 0, IntPtr achievementDefinition);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Achievements_GetAchievementDefinitionCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Achievements_GetAchievementDefinitionCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Achievements_GetPlayerAchievementCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Achievements_GetPlayerAchievementCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Achievements_GetUnlockedAchievementCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Achievements_GetUnlockedAchievementCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Achievements_PlayerAchievement_Release(IntPtr achievement);
STUB(void, EOS_Achievements_PlayerAchievement_Release, 0, IntPtr achievement);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Achievements_QueryDefinitions(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryDefinitionsCompleteCallbackInternal completionDelegate);
STUB(void, EOS_Achievements_QueryDefinitions, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Achievements_QueryPlayerAchievements(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryPlayerAchievementsCompleteCallbackInternal completionDelegate);
STUB(void, EOS_Achievements_QueryPlayerAchievements, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Achievements_RemoveNotifyAchievementsUnlocked(IntPtr handle, ulong inId);
STUB(void, EOS_Achievements_RemoveNotifyAchievementsUnlocked, 0, IntPtr handle, ulong inId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Achievements_UnlockAchievements(IntPtr handle, IntPtr options, IntPtr clientData, OnUnlockAchievementsCompleteCallbackInternal completionDelegate);
STUB(void, EOS_Achievements_UnlockAchievements, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Achievements_UnlockedAchievement_Release(IntPtr achievement);
STUB(void, EOS_Achievements_UnlockedAchievement_Release, 0, IntPtr achievement);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_ActiveSession_CopyInfo(IntPtr handle, IntPtr options, ref IntPtr outActiveSessionInfo);
STUB(Result, EOS_ActiveSession_CopyInfo, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outActiveSessionInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_ActiveSession_GetRegisteredPlayerByIndex(IntPtr handle, IntPtr options);
STUB(IntPtr, EOS_ActiveSession_GetRegisteredPlayerByIndex, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_ActiveSession_GetRegisteredPlayerCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_ActiveSession_GetRegisteredPlayerCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_ActiveSession_Info_Release(IntPtr activeSessionInfo);
STUB(void, EOS_ActiveSession_Info_Release, 0, IntPtr activeSessionInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_ActiveSession_Release(IntPtr activeSessionHandle);
STUB(void, EOS_ActiveSession_Release, 0, IntPtr activeSessionHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatClient_AddExternalIntegrityCatalog(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatClient_AddExternalIntegrityCatalog, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_AntiCheatClient_AddNotifyMessageToPeer(IntPtr handle, IntPtr options, IntPtr clientData, OnMessageToPeerCallbackInternal notificationFn);
STUB(ulong, EOS_AntiCheatClient_AddNotifyMessageToPeer, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_AntiCheatClient_AddNotifyMessageToServer(IntPtr handle, IntPtr options, IntPtr clientData, OnMessageToServerCallbackInternal notificationFn);
STUB(ulong, EOS_AntiCheatClient_AddNotifyMessageToServer, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_AntiCheatClient_AddNotifyPeerActionRequired(IntPtr handle, IntPtr options, IntPtr clientData, OnPeerActionRequiredCallbackInternal notificationFn);
STUB(ulong, EOS_AntiCheatClient_AddNotifyPeerActionRequired, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_AntiCheatClient_AddNotifyPeerAuthStatusChanged(IntPtr handle, IntPtr options, IntPtr clientData, OnPeerAuthStatusChangedCallbackInternal notificationFn);
STUB(ulong, EOS_AntiCheatClient_AddNotifyPeerAuthStatusChanged, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatClient_BeginSession(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatClient_BeginSession, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatClient_EndSession(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatClient_EndSession, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatClient_GetProtectMessageOutputLength(IntPtr handle, IntPtr options, ref uint outBufferSizeBytes);
STUB(Result, EOS_AntiCheatClient_GetProtectMessageOutputLength, NotImplemented, IntPtr handle, IntPtr options, ref uint outBufferSizeBytes);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatClient_PollStatus(IntPtr handle, IntPtr options, ref AntiCheatClientViolationType outViolationType, IntPtr outMessage);
STUB(Result, EOS_AntiCheatClient_PollStatus, NotImplemented, IntPtr handle, IntPtr options, IntPtr outViolationType, IntPtr outMessage);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatClient_ProtectMessage(IntPtr handle, IntPtr options, IntPtr outBuffer, ref uint outBytesWritten);
STUB(Result, EOS_AntiCheatClient_ProtectMessage, NotImplemented, IntPtr handle, IntPtr options, IntPtr outBuffer, ref uint outBytesWritten);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatClient_ReceiveMessageFromPeer(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatClient_ReceiveMessageFromPeer, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatClient_ReceiveMessageFromServer(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatClient_ReceiveMessageFromServer, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatClient_RegisterPeer(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatClient_RegisterPeer, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_AntiCheatClient_RemoveNotifyMessageToPeer(IntPtr handle, ulong notificationId);
STUB(void, EOS_AntiCheatClient_RemoveNotifyMessageToPeer, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_AntiCheatClient_RemoveNotifyMessageToServer(IntPtr handle, ulong notificationId);
STUB(void, EOS_AntiCheatClient_RemoveNotifyMessageToServer, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_AntiCheatClient_RemoveNotifyPeerActionRequired(IntPtr handle, ulong notificationId);
STUB(void, EOS_AntiCheatClient_RemoveNotifyPeerActionRequired, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_AntiCheatClient_RemoveNotifyPeerAuthStatusChanged(IntPtr handle, ulong notificationId);
STUB(void, EOS_AntiCheatClient_RemoveNotifyPeerAuthStatusChanged, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatClient_UnprotectMessage(IntPtr handle, IntPtr options, IntPtr outBuffer, ref uint outBytesWritten);
STUB(Result, EOS_AntiCheatClient_UnprotectMessage, NotImplemented, IntPtr handle, IntPtr options, IntPtr outBuffer, ref uint outBytesWritten);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatClient_UnregisterPeer(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatClient_UnregisterPeer, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_AntiCheatServer_AddNotifyClientActionRequired(IntPtr handle, IntPtr options, IntPtr clientData, OnClientActionRequiredCallbackInternal notificationFn);
STUB(ulong, EOS_AntiCheatServer_AddNotifyClientActionRequired, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_AntiCheatServer_AddNotifyClientAuthStatusChanged(IntPtr handle, IntPtr options, IntPtr clientData, OnClientAuthStatusChangedCallbackInternal notificationFn);
STUB(ulong, EOS_AntiCheatServer_AddNotifyClientAuthStatusChanged, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_AntiCheatServer_AddNotifyMessageToClient(IntPtr handle, IntPtr options, IntPtr clientData, OnMessageToClientCallbackInternal notificationFn);
STUB(ulong, EOS_AntiCheatServer_AddNotifyMessageToClient, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_BeginSession(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_BeginSession, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_EndSession(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_EndSession, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_GetProtectMessageOutputLength(IntPtr handle, IntPtr options, ref uint outBufferSizeBytes);
STUB(Result, EOS_AntiCheatServer_GetProtectMessageOutputLength, NotImplemented, IntPtr handle, IntPtr options, ref uint outBufferSizeBytes);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_LogEvent(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_LogEvent, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_LogGameRoundEnd(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_LogGameRoundEnd, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_LogGameRoundStart(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_LogGameRoundStart, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_LogPlayerDespawn(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_LogPlayerDespawn, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_LogPlayerRevive(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_LogPlayerRevive, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_LogPlayerSpawn(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_LogPlayerSpawn, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_LogPlayerTakeDamage(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_LogPlayerTakeDamage, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_LogPlayerTick(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_LogPlayerTick, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_LogPlayerUseAbility(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_LogPlayerUseAbility, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_LogPlayerUseWeapon(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_LogPlayerUseWeapon, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_ProtectMessage(IntPtr handle, IntPtr options, IntPtr outBuffer, ref uint outBytesWritten);
STUB(Result, EOS_AntiCheatServer_ProtectMessage, NotImplemented, IntPtr handle, IntPtr options, IntPtr outBuffer, ref uint outBytesWritten);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_ReceiveMessageFromClient(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_ReceiveMessageFromClient, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_RegisterClient(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_RegisterClient, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_RegisterEvent(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_RegisterEvent, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_AntiCheatServer_RemoveNotifyClientActionRequired(IntPtr handle, ulong notificationId);
STUB(void, EOS_AntiCheatServer_RemoveNotifyClientActionRequired, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_AntiCheatServer_RemoveNotifyClientAuthStatusChanged(IntPtr handle, ulong notificationId);
STUB(void, EOS_AntiCheatServer_RemoveNotifyClientAuthStatusChanged, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_AntiCheatServer_RemoveNotifyMessageToClient(IntPtr handle, ulong notificationId);
STUB(void, EOS_AntiCheatServer_RemoveNotifyMessageToClient, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_SetClientDetails(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_SetClientDetails, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_SetClientNetworkState(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_SetClientNetworkState, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_SetGameSessionId(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_SetGameSessionId, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_UnprotectMessage(IntPtr handle, IntPtr options, IntPtr outBuffer, ref uint outBytesWritten);
STUB(Result, EOS_AntiCheatServer_UnprotectMessage, NotImplemented, IntPtr handle, IntPtr options, IntPtr outBuffer, ref uint outBytesWritten);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_AntiCheatServer_UnregisterClient(IntPtr handle, IntPtr options);
STUB(Result, EOS_AntiCheatServer_UnregisterClient, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_Auth_AddNotifyLoginStatusChanged(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.Auth.OnLoginStatusChangedCallbackInternal notification);
STUB(ulong, EOS_Auth_AddNotifyLoginStatusChanged, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notification);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Auth_CopyIdToken(IntPtr handle, IntPtr options, ref IntPtr outIdToken);
STUB(Result, EOS_Auth_CopyIdToken, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outIdToken);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Auth_CopyUserAuthToken(IntPtr handle, IntPtr options, IntPtr localUserId, ref IntPtr outUserAuthToken);
STUB(Result, EOS_Auth_CopyUserAuthToken, NotImplemented, IntPtr handle, IntPtr options, IntPtr localUserId, ref IntPtr outUserAuthToken);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Auth_DeletePersistentAuth(IntPtr handle, IntPtr options, IntPtr clientData, OnDeletePersistentAuthCallbackInternal completionDelegate);
STUB(void, EOS_Auth_DeletePersistentAuth, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Auth_GetLoggedInAccountByIndex(IntPtr handle, int index);
STUB(IntPtr, EOS_Auth_GetLoggedInAccountByIndex, 0, IntPtr handle, int index);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern int EOS_Auth_GetLoggedInAccountsCount(IntPtr handle);
STUB(int, EOS_Auth_GetLoggedInAccountsCount, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern LoginStatus EOS_Auth_GetLoginStatus(IntPtr handle, IntPtr localUserId);
STUB(IntPtr, EOS_Auth_GetLoginStatus, 0, IntPtr handle, IntPtr localUserId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Auth_GetMergedAccountByIndex(IntPtr handle, IntPtr localUserId, uint index);
STUB(IntPtr, EOS_Auth_GetMergedAccountByIndex, 0, IntPtr handle, IntPtr localUserId, uint index);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Auth_GetMergedAccountsCount(IntPtr handle, IntPtr localUserId);
STUB(uint, EOS_Auth_GetMergedAccountsCount, 0, IntPtr handle, IntPtr localUserId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Auth_GetSelectedAccountId(IntPtr handle, IntPtr localUserId, ref IntPtr outSelectedAccountId);
STUB(Result, EOS_Auth_GetSelectedAccountId, NotImplemented, IntPtr handle, IntPtr localUserId, ref IntPtr outSelectedAccountId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Auth_IdToken_Release(IntPtr idToken);
STUB(void, EOS_Auth_IdToken_Release, 0, IntPtr idToken);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Auth_LinkAccount(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.Auth.OnLinkAccountCallbackInternal completionDelegate);
STUB(void, EOS_Auth_LinkAccount, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Auth_Login(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.Auth.OnLoginCallbackInternal completionDelegate);
STUB(void, EOS_Auth_Login, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Auth_Logout(IntPtr handle, IntPtr options, IntPtr clientData, OnLogoutCallbackInternal completionDelegate);
STUB(void, EOS_Auth_Logout, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Auth_QueryIdToken(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryIdTokenCallbackInternal completionDelegate);
STUB(void, EOS_Auth_QueryIdToken, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Auth_RemoveNotifyLoginStatusChanged(IntPtr handle, ulong inId);
STUB(void, EOS_Auth_RemoveNotifyLoginStatusChanged, 0, IntPtr handle, ulong inId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Auth_Token_Release(IntPtr authToken);
STUB(void, EOS_Auth_Token_Release, 0, IntPtr authToken);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Auth_VerifyIdToken(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.Auth.OnVerifyIdTokenCallbackInternal completionDelegate);
STUB(void, EOS_Auth_VerifyIdToken, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Auth_VerifyUserAuth(IntPtr handle, IntPtr options, IntPtr clientData, OnVerifyUserAuthCallbackInternal completionDelegate);
STUB(void, EOS_Auth_VerifyUserAuth, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_ByteArray_ToString(IntPtr byteArray, uint length, IntPtr outBuffer, ref uint inOutBufferLength);
STUB(Result, EOS_ByteArray_ToString, NotImplemented, IntPtr byteArray, uint length, IntPtr outBuffer, ref uint inOutBufferLength);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_Connect_AddNotifyAuthExpiration(IntPtr handle, IntPtr options, IntPtr clientData, OnAuthExpirationCallbackInternal notification);
STUB(ulong, EOS_Connect_AddNotifyAuthExpiration, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notification);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_Connect_AddNotifyLoginStatusChanged(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.Connect.OnLoginStatusChangedCallbackInternal notification);
STUB(ulong, EOS_Connect_AddNotifyLoginStatusChanged, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notification);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Connect_CopyIdToken(IntPtr handle, IntPtr options, ref IntPtr outIdToken);
STUB(Result, EOS_Connect_CopyIdToken, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outIdToken);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Connect_CopyProductUserExternalAccountByAccountId(IntPtr handle, IntPtr options, ref IntPtr outExternalAccountInfo);
STUB(Result, EOS_Connect_CopyProductUserExternalAccountByAccountId, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outExternalAccountInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Connect_CopyProductUserExternalAccountByAccountType(IntPtr handle, IntPtr options, ref IntPtr outExternalAccountInfo);
STUB(Result, EOS_Connect_CopyProductUserExternalAccountByAccountType, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outExternalAccountInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Connect_CopyProductUserExternalAccountByIndex(IntPtr handle, IntPtr options, ref IntPtr outExternalAccountInfo);
STUB(Result, EOS_Connect_CopyProductUserExternalAccountByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outExternalAccountInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Connect_CopyProductUserInfo(IntPtr handle, IntPtr options, ref IntPtr outExternalAccountInfo);
STUB(Result, EOS_Connect_CopyProductUserInfo, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outExternalAccountInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Connect_CreateDeviceId(IntPtr handle, IntPtr options, IntPtr clientData, OnCreateDeviceIdCallbackInternal completionDelegate);
STUB(void, EOS_Connect_CreateDeviceId, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Connect_CreateUser(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.Connect.OnCreateUserCallbackInternal completionDelegate);
STUB(void, EOS_Connect_CreateUser, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Connect_DeleteDeviceId(IntPtr handle, IntPtr options, IntPtr clientData, OnDeleteDeviceIdCallbackInternal completionDelegate);
STUB(void, EOS_Connect_DeleteDeviceId, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Connect_ExternalAccountInfo_Release(IntPtr externalAccountInfo);
STUB(void, EOS_Connect_ExternalAccountInfo_Release, 0, IntPtr externalAccountInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Connect_GetExternalAccountMapping(IntPtr handle, IntPtr options);
STUB(IntPtr, EOS_Connect_GetExternalAccountMapping, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Connect_GetLoggedInUserByIndex(IntPtr handle, int index);
STUB(IntPtr, EOS_Connect_GetLoggedInUserByIndex, 0, IntPtr handle, int index);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern int EOS_Connect_GetLoggedInUsersCount(IntPtr handle);
STUB(int, EOS_Connect_GetLoggedInUsersCount, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern LoginStatus EOS_Connect_GetLoginStatus(IntPtr handle, IntPtr localUserId);
STUB(IntPtr, EOS_Connect_GetLoginStatus, 0, IntPtr handle, IntPtr localUserId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Connect_GetProductUserExternalAccountCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Connect_GetProductUserExternalAccountCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Connect_GetProductUserIdMapping(IntPtr handle, IntPtr options, IntPtr outBuffer, ref int inOutBufferLength);
STUB(Result, EOS_Connect_GetProductUserIdMapping, NotImplemented, IntPtr handle, IntPtr options, IntPtr outBuffer, ref int inOutBufferLength);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Connect_IdToken_Release(IntPtr idToken);
STUB(void, EOS_Connect_IdToken_Release, 0, IntPtr idToken);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Connect_LinkAccount(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.Connect.OnLinkAccountCallbackInternal completionDelegate);
STUB(void, EOS_Connect_LinkAccount, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Connect_Login(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.Connect.OnLoginCallbackInternal completionDelegate);
STUB(void, EOS_Connect_Login, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Connect_QueryExternalAccountMappings(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryExternalAccountMappingsCallbackInternal completionDelegate);
STUB(void, EOS_Connect_QueryExternalAccountMappings, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Connect_QueryProductUserIdMappings(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryProductUserIdMappingsCallbackInternal completionDelegate);
STUB(void, EOS_Connect_QueryProductUserIdMappings, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Connect_RemoveNotifyAuthExpiration(IntPtr handle, ulong inId);
STUB(void, EOS_Connect_RemoveNotifyAuthExpiration, 0, IntPtr handle, ulong inId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Connect_RemoveNotifyLoginStatusChanged(IntPtr handle, ulong inId);
STUB(void, EOS_Connect_RemoveNotifyLoginStatusChanged, 0, IntPtr handle, ulong inId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Connect_TransferDeviceIdAccount(IntPtr handle, IntPtr options, IntPtr clientData, OnTransferDeviceIdAccountCallbackInternal completionDelegate);
STUB(void, EOS_Connect_TransferDeviceIdAccount, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Connect_UnlinkAccount(IntPtr handle, IntPtr options, IntPtr clientData, OnUnlinkAccountCallbackInternal completionDelegate);
STUB(void, EOS_Connect_UnlinkAccount, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Connect_VerifyIdToken(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.Connect.OnVerifyIdTokenCallbackInternal completionDelegate);
STUB(void, EOS_Connect_VerifyIdToken, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_ContinuanceToken_ToString(IntPtr continuanceToken, IntPtr outBuffer, ref int inOutBufferLength);
STUB(Result, EOS_ContinuanceToken_ToString, NotImplemented, IntPtr continuanceToken, IntPtr outBuffer, ref int inOutBufferLength);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_CustomInvites_AddNotifyCustomInviteAccepted(IntPtr handle, IntPtr options, IntPtr clientData, OnCustomInviteAcceptedCallbackInternal notificationFn);
STUB(ulong, EOS_CustomInvites_AddNotifyCustomInviteAccepted, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_CustomInvites_AddNotifyCustomInviteReceived(IntPtr handle, IntPtr options, IntPtr clientData, OnCustomInviteReceivedCallbackInternal notificationFn);
STUB(ulong, EOS_CustomInvites_AddNotifyCustomInviteReceived, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_CustomInvites_FinalizeInvite(IntPtr handle, IntPtr options);
STUB(Result, EOS_CustomInvites_FinalizeInvite, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_CustomInvites_RemoveNotifyCustomInviteAccepted(IntPtr handle, ulong inId);
STUB(void, EOS_CustomInvites_RemoveNotifyCustomInviteAccepted, 0, IntPtr handle, ulong inId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_CustomInvites_RemoveNotifyCustomInviteReceived(IntPtr handle, ulong inId);
STUB(void, EOS_CustomInvites_RemoveNotifyCustomInviteReceived, 0, IntPtr handle, ulong inId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_CustomInvites_SendCustomInvite(IntPtr handle, IntPtr options, IntPtr clientData, OnSendCustomInviteCallbackInternal completionDelegate);
STUB(void, EOS_CustomInvites_SendCustomInvite, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_CustomInvites_SetCustomInvite(IntPtr handle, IntPtr options);
STUB(Result, EOS_CustomInvites_SetCustomInvite, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern int EOS_EResult_IsOperationComplete(Result result);
STUB(int, EOS_EResult_IsOperationComplete, 0, Result result);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_EResult_ToString(Result result);
STUB(IntPtr, EOS_EResult_ToString, 0, Result result);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Ecom_CatalogItem_Release(IntPtr catalogItem);
STUB(void, EOS_Ecom_CatalogItem_Release, 0, IntPtr catalogItem);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Ecom_CatalogOffer_Release(IntPtr catalogOffer);
STUB(void, EOS_Ecom_CatalogOffer_Release, 0, IntPtr catalogOffer);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Ecom_CatalogRelease_Release(IntPtr catalogRelease);
STUB(void, EOS_Ecom_CatalogRelease_Release, 0, IntPtr catalogRelease);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Ecom_Checkout(IntPtr handle, IntPtr options, IntPtr clientData, OnCheckoutCallbackInternal completionDelegate);
STUB(void, EOS_Ecom_Checkout, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Ecom_CopyEntitlementById(IntPtr handle, IntPtr options, ref IntPtr outEntitlement);
STUB(Result, EOS_Ecom_CopyEntitlementById, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outEntitlement);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Ecom_CopyEntitlementByIndex(IntPtr handle, IntPtr options, ref IntPtr outEntitlement);
STUB(Result, EOS_Ecom_CopyEntitlementByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outEntitlement);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Ecom_CopyEntitlementByNameAndIndex(IntPtr handle, IntPtr options, ref IntPtr outEntitlement);
STUB(Result, EOS_Ecom_CopyEntitlementByNameAndIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outEntitlement);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Ecom_CopyItemById(IntPtr handle, IntPtr options, ref IntPtr outItem);
STUB(Result, EOS_Ecom_CopyItemById, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outItem);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Ecom_CopyItemImageInfoByIndex(IntPtr handle, IntPtr options, ref IntPtr outImageInfo);
STUB(Result, EOS_Ecom_CopyItemImageInfoByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outImageInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Ecom_CopyItemReleaseByIndex(IntPtr handle, IntPtr options, ref IntPtr outRelease);
STUB(Result, EOS_Ecom_CopyItemReleaseByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outRelease);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Ecom_CopyOfferById(IntPtr handle, IntPtr options, ref IntPtr outOffer);
STUB(Result, EOS_Ecom_CopyOfferById, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outOffer);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Ecom_CopyOfferByIndex(IntPtr handle, IntPtr options, ref IntPtr outOffer);
STUB(Result, EOS_Ecom_CopyOfferByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outOffer);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Ecom_CopyOfferImageInfoByIndex(IntPtr handle, IntPtr options, ref IntPtr outImageInfo);
STUB(Result, EOS_Ecom_CopyOfferImageInfoByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outImageInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Ecom_CopyOfferItemByIndex(IntPtr handle, IntPtr options, ref IntPtr outItem);
STUB(Result, EOS_Ecom_CopyOfferItemByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outItem);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Ecom_CopyTransactionById(IntPtr handle, IntPtr options, ref IntPtr outTransaction);
STUB(Result, EOS_Ecom_CopyTransactionById, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outTransaction);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Ecom_CopyTransactionByIndex(IntPtr handle, IntPtr options, ref IntPtr outTransaction);
STUB(Result, EOS_Ecom_CopyTransactionByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outTransaction);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Ecom_Entitlement_Release(IntPtr entitlement);
STUB(void, EOS_Ecom_Entitlement_Release, 0, IntPtr entitlement);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Ecom_GetEntitlementsByNameCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Ecom_GetEntitlementsByNameCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Ecom_GetEntitlementsCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Ecom_GetEntitlementsCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Ecom_GetItemImageInfoCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Ecom_GetItemImageInfoCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Ecom_GetItemReleaseCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Ecom_GetItemReleaseCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Ecom_GetOfferCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Ecom_GetOfferCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Ecom_GetOfferImageInfoCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Ecom_GetOfferImageInfoCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Ecom_GetOfferItemCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Ecom_GetOfferItemCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Ecom_GetTransactionCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Ecom_GetTransactionCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Ecom_KeyImageInfo_Release(IntPtr keyImageInfo);
STUB(void, EOS_Ecom_KeyImageInfo_Release, 0, IntPtr keyImageInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Ecom_QueryEntitlements(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryEntitlementsCallbackInternal completionDelegate);
STUB(void, EOS_Ecom_QueryEntitlements, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Ecom_QueryOffers(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryOffersCallbackInternal completionDelegate);
STUB(void, EOS_Ecom_QueryOffers, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Ecom_QueryOwnership(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryOwnershipCallbackInternal completionDelegate);
STUB(void, EOS_Ecom_QueryOwnership, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Ecom_QueryOwnershipToken(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryOwnershipTokenCallbackInternal completionDelegate);
STUB(void, EOS_Ecom_QueryOwnershipToken, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Ecom_RedeemEntitlements(IntPtr handle, IntPtr options, IntPtr clientData, OnRedeemEntitlementsCallbackInternal completionDelegate);
STUB(void, EOS_Ecom_RedeemEntitlements, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Ecom_Transaction_CopyEntitlementByIndex(IntPtr handle, IntPtr options, ref IntPtr outEntitlement);
STUB(Result, EOS_Ecom_Transaction_CopyEntitlementByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outEntitlement);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Ecom_Transaction_GetEntitlementsCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Ecom_Transaction_GetEntitlementsCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Ecom_Transaction_GetTransactionId(IntPtr handle, IntPtr outBuffer, ref int inOutBufferLength);
STUB(Result, EOS_Ecom_Transaction_GetTransactionId, NotImplemented, IntPtr handle, IntPtr outBuffer, ref int inOutBufferLength);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Ecom_Transaction_Release(IntPtr transaction);
STUB(void, EOS_Ecom_Transaction_Release, 0, IntPtr transaction);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_EpicAccountId_FromString(IntPtr accountIdString);
STUB(IntPtr, EOS_EpicAccountId_FromString, 0, IntPtr accountIdString);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern int EOS_EpicAccountId_IsValid(IntPtr accountId);
STUB(int, EOS_EpicAccountId_IsValid, 0, IntPtr accountId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_EpicAccountId_ToString(IntPtr accountId, IntPtr outBuffer, ref int inOutBufferLength);
STUB(Result, EOS_EpicAccountId_ToString, NotImplemented, IntPtr accountId, IntPtr outBuffer, ref int inOutBufferLength);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Friends_AcceptInvite(IntPtr handle, IntPtr options, IntPtr clientData, OnAcceptInviteCallbackInternal completionDelegate);
STUB(void, EOS_Friends_AcceptInvite, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_Friends_AddNotifyFriendsUpdate(IntPtr handle, IntPtr options, IntPtr clientData, OnFriendsUpdateCallbackInternal friendsUpdateHandler);
STUB(ulong, EOS_Friends_AddNotifyFriendsUpdate, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr friendsUpdateHandler);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Friends_GetFriendAtIndex(IntPtr handle, IntPtr options);
STUB(IntPtr, EOS_Friends_GetFriendAtIndex, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern int EOS_Friends_GetFriendsCount(IntPtr handle, IntPtr options);
STUB(int, EOS_Friends_GetFriendsCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern FriendsStatus EOS_Friends_GetStatus(IntPtr handle, IntPtr options);
STUB(IntPtr, EOS_Friends_GetStatus, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Friends_QueryFriends(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryFriendsCallbackInternal completionDelegate);
STUB(void, EOS_Friends_QueryFriends, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Friends_RejectInvite(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.Friends.OnRejectInviteCallbackInternal completionDelegate);
STUB(void, EOS_Friends_RejectInvite, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Friends_RemoveNotifyFriendsUpdate(IntPtr handle, ulong notificationId);
STUB(void, EOS_Friends_RemoveNotifyFriendsUpdate, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Friends_SendInvite(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.Friends.OnSendInviteCallbackInternal completionDelegate);
STUB(void, EOS_Friends_SendInvite, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Initialize(IntPtr options);
STUB(Result, EOS_Initialize, NotImplemented, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_KWS_AddNotifyPermissionsUpdateReceived(IntPtr handle, IntPtr options, IntPtr clientData, OnPermissionsUpdateReceivedCallbackInternal notificationFn);
STUB(ulong, EOS_KWS_AddNotifyPermissionsUpdateReceived, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_KWS_CopyPermissionByIndex(IntPtr handle, IntPtr options, ref IntPtr outPermission);
STUB(Result, EOS_KWS_CopyPermissionByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outPermission);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_KWS_CreateUser(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.KWS.OnCreateUserCallbackInternal completionDelegate);
STUB(void, EOS_KWS_CreateUser, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_KWS_GetPermissionByKey(IntPtr handle, IntPtr options, ref KWSPermissionStatus outPermission);
STUB(Result, EOS_KWS_GetPermissionByKey, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outPermission);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern int EOS_KWS_GetPermissionsCount(IntPtr handle, IntPtr options);
STUB(int, EOS_KWS_GetPermissionsCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_KWS_PermissionStatus_Release(IntPtr permissionStatus);
STUB(void, EOS_KWS_PermissionStatus_Release, 0, IntPtr permissionStatus);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_KWS_QueryAgeGate(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryAgeGateCallbackInternal completionDelegate);
STUB(void, EOS_KWS_QueryAgeGate, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_KWS_QueryPermissions(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryPermissionsCallbackInternal completionDelegate);
STUB(void, EOS_KWS_QueryPermissions, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_KWS_RemoveNotifyPermissionsUpdateReceived(IntPtr handle, ulong inId);
STUB(void, EOS_KWS_RemoveNotifyPermissionsUpdateReceived, 0, IntPtr handle, ulong inId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_KWS_RequestPermissions(IntPtr handle, IntPtr options, IntPtr clientData, OnRequestPermissionsCallbackInternal completionDelegate);
STUB(void, EOS_KWS_RequestPermissions, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_KWS_UpdateParentEmail(IntPtr handle, IntPtr options, IntPtr clientData, OnUpdateParentEmailCallbackInternal completionDelegate);
STUB(void, EOS_KWS_UpdateParentEmail, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Leaderboards_CopyLeaderboardDefinitionByIndex(IntPtr handle, IntPtr options, ref IntPtr outLeaderboardDefinition);
STUB(Result, EOS_Leaderboards_CopyLeaderboardDefinitionByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outLeaderboardDefinition);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId(IntPtr handle, IntPtr options, ref IntPtr outLeaderboardDefinition);
STUB(Result, EOS_Leaderboards_CopyLeaderboardDefinitionByLeaderboardId, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outLeaderboardDefinition);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Leaderboards_CopyLeaderboardRecordByIndex(IntPtr handle, IntPtr options, ref IntPtr outLeaderboardRecord);
STUB(Result, EOS_Leaderboards_CopyLeaderboardRecordByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outLeaderboardRecord);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Leaderboards_CopyLeaderboardRecordByUserId(IntPtr handle, IntPtr options, ref IntPtr outLeaderboardRecord);
STUB(Result, EOS_Leaderboards_CopyLeaderboardRecordByUserId, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outLeaderboardRecord);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Leaderboards_CopyLeaderboardUserScoreByIndex(IntPtr handle, IntPtr options, ref IntPtr outLeaderboardUserScore);
STUB(Result, EOS_Leaderboards_CopyLeaderboardUserScoreByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outLeaderboardUserScore);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Leaderboards_CopyLeaderboardUserScoreByUserId(IntPtr handle, IntPtr options, ref IntPtr outLeaderboardUserScore);
STUB(Result, EOS_Leaderboards_CopyLeaderboardUserScoreByUserId, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outLeaderboardUserScore);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Leaderboards_Definition_Release(IntPtr leaderboardDefinition);
STUB(void, EOS_Leaderboards_Definition_Release, 0, IntPtr leaderboardDefinition);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Leaderboards_GetLeaderboardDefinitionCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Leaderboards_GetLeaderboardDefinitionCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Leaderboards_GetLeaderboardRecordCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Leaderboards_GetLeaderboardRecordCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Leaderboards_GetLeaderboardUserScoreCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Leaderboards_GetLeaderboardUserScoreCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Leaderboards_LeaderboardDefinition_Release(IntPtr leaderboardDefinition);
STUB(void, EOS_Leaderboards_LeaderboardDefinition_Release, 0, IntPtr leaderboardDefinition);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Leaderboards_LeaderboardRecord_Release(IntPtr leaderboardRecord);
STUB(void, EOS_Leaderboards_LeaderboardRecord_Release, 0, IntPtr leaderboardRecord);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Leaderboards_LeaderboardUserScore_Release(IntPtr leaderboardUserScore);
STUB(void, EOS_Leaderboards_LeaderboardUserScore_Release, 0, IntPtr leaderboardUserScore);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Leaderboards_QueryLeaderboardDefinitions(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryLeaderboardDefinitionsCompleteCallbackInternal completionDelegate);
STUB(void, EOS_Leaderboards_QueryLeaderboardDefinitions, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Leaderboards_QueryLeaderboardRanks(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryLeaderboardRanksCompleteCallbackInternal completionDelegate);
STUB(void, EOS_Leaderboards_QueryLeaderboardRanks, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Leaderboards_QueryLeaderboardUserScores(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryLeaderboardUserScoresCompleteCallbackInternal completionDelegate);
STUB(void, EOS_Leaderboards_QueryLeaderboardUserScores, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbyDetails_CopyAttributeByIndex(IntPtr handle, IntPtr options, ref IntPtr outAttribute);
STUB(Result, EOS_LobbyDetails_CopyAttributeByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outAttribute);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbyDetails_CopyAttributeByKey(IntPtr handle, IntPtr options, ref IntPtr outAttribute);
STUB(Result, EOS_LobbyDetails_CopyAttributeByKey, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outAttribute);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbyDetails_CopyInfo(IntPtr handle, IntPtr options, ref IntPtr outLobbyDetailsInfo);
STUB(Result, EOS_LobbyDetails_CopyInfo, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outLobbyDetailsInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbyDetails_CopyMemberAttributeByIndex(IntPtr handle, IntPtr options, ref IntPtr outAttribute);
STUB(Result, EOS_LobbyDetails_CopyMemberAttributeByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outAttribute);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbyDetails_CopyMemberAttributeByKey(IntPtr handle, IntPtr options, ref IntPtr outAttribute);
STUB(Result, EOS_LobbyDetails_CopyMemberAttributeByKey, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outAttribute);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_LobbyDetails_GetAttributeCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_LobbyDetails_GetAttributeCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_LobbyDetails_GetLobbyOwner(IntPtr handle, IntPtr options);
STUB(IntPtr, EOS_LobbyDetails_GetLobbyOwner, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_LobbyDetails_GetMemberAttributeCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_LobbyDetails_GetMemberAttributeCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_LobbyDetails_GetMemberByIndex(IntPtr handle, IntPtr options);
STUB(IntPtr, EOS_LobbyDetails_GetMemberByIndex, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_LobbyDetails_GetMemberCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_LobbyDetails_GetMemberCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_LobbyDetails_Info_Release(IntPtr lobbyDetailsInfo);
STUB(void, EOS_LobbyDetails_Info_Release, 0, IntPtr lobbyDetailsInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_LobbyDetails_Release(IntPtr lobbyHandle);
STUB(void, EOS_LobbyDetails_Release, 0, IntPtr lobbyHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbyModification_AddAttribute(IntPtr handle, IntPtr options);
STUB(Result, EOS_LobbyModification_AddAttribute, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbyModification_AddMemberAttribute(IntPtr handle, IntPtr options);
STUB(Result, EOS_LobbyModification_AddMemberAttribute, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_LobbyModification_Release(IntPtr lobbyModificationHandle);
STUB(void, EOS_LobbyModification_Release, 0, IntPtr lobbyModificationHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbyModification_RemoveAttribute(IntPtr handle, IntPtr options);
STUB(Result, EOS_LobbyModification_RemoveAttribute, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbyModification_RemoveMemberAttribute(IntPtr handle, IntPtr options);
STUB(Result, EOS_LobbyModification_RemoveMemberAttribute, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbyModification_SetBucketId(IntPtr handle, IntPtr options);
STUB(Result, EOS_LobbyModification_SetBucketId, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbyModification_SetInvitesAllowed(IntPtr handle, IntPtr options);
STUB(Result, EOS_LobbyModification_SetInvitesAllowed, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbyModification_SetMaxMembers(IntPtr handle, IntPtr options);
STUB(Result, EOS_LobbyModification_SetMaxMembers, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbyModification_SetPermissionLevel(IntPtr handle, IntPtr options);
STUB(Result, EOS_LobbyModification_SetPermissionLevel, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbySearch_CopySearchResultByIndex(IntPtr handle, IntPtr options, ref IntPtr outLobbyDetailsHandle);
STUB(Result, EOS_LobbySearch_CopySearchResultByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outLobbyDetailsHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_LobbySearch_Find(IntPtr handle, IntPtr options, IntPtr clientData, LobbySearchOnFindCallbackInternal completionDelegate);
STUB(void, EOS_LobbySearch_Find, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_LobbySearch_GetSearchResultCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_LobbySearch_GetSearchResultCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_LobbySearch_Release(IntPtr lobbySearchHandle);
STUB(void, EOS_LobbySearch_Release, 0, IntPtr lobbySearchHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbySearch_RemoveParameter(IntPtr handle, IntPtr options);
STUB(Result, EOS_LobbySearch_RemoveParameter, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbySearch_SetLobbyId(IntPtr handle, IntPtr options);
STUB(Result, EOS_LobbySearch_SetLobbyId, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbySearch_SetMaxResults(IntPtr handle, IntPtr options);
STUB(Result, EOS_LobbySearch_SetMaxResults, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbySearch_SetParameter(IntPtr handle, IntPtr options);
STUB(Result, EOS_LobbySearch_SetParameter, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_LobbySearch_SetTargetUserId(IntPtr handle, IntPtr options);
STUB(Result, EOS_LobbySearch_SetTargetUserId, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_Lobby_AddNotifyJoinLobbyAccepted(IntPtr handle, IntPtr options, IntPtr clientData, OnJoinLobbyAcceptedCallbackInternal notificationFn);
STUB(ulong, EOS_Lobby_AddNotifyJoinLobbyAccepted, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_Lobby_AddNotifyLobbyInviteAccepted(IntPtr handle, IntPtr options, IntPtr clientData, OnLobbyInviteAcceptedCallbackInternal notificationFn);
STUB(ulong, EOS_Lobby_AddNotifyLobbyInviteAccepted, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_Lobby_AddNotifyLobbyInviteReceived(IntPtr handle, IntPtr options, IntPtr clientData, OnLobbyInviteReceivedCallbackInternal notificationFn);
STUB(ulong, EOS_Lobby_AddNotifyLobbyInviteReceived, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_Lobby_AddNotifyLobbyMemberStatusReceived(IntPtr handle, IntPtr options, IntPtr clientData, OnLobbyMemberStatusReceivedCallbackInternal notificationFn);
STUB(ulong, EOS_Lobby_AddNotifyLobbyMemberStatusReceived, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_Lobby_AddNotifyLobbyMemberUpdateReceived(IntPtr handle, IntPtr options, IntPtr clientData, OnLobbyMemberUpdateReceivedCallbackInternal notificationFn);
STUB(ulong, EOS_Lobby_AddNotifyLobbyMemberUpdateReceived, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_Lobby_AddNotifyLobbyUpdateReceived(IntPtr handle, IntPtr options, IntPtr clientData, OnLobbyUpdateReceivedCallbackInternal notificationFn);
STUB(ulong, EOS_Lobby_AddNotifyLobbyUpdateReceived, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_Lobby_AddNotifyRTCRoomConnectionChanged(IntPtr handle, IntPtr options, IntPtr clientData, OnRTCRoomConnectionChangedCallbackInternal notificationFn);
STUB(ulong, EOS_Lobby_AddNotifyRTCRoomConnectionChanged, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Lobby_Attribute_Release(IntPtr lobbyAttribute);
STUB(void, EOS_Lobby_Attribute_Release, 0, IntPtr lobbyAttribute);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Lobby_CopyLobbyDetailsHandle(IntPtr handle, IntPtr options, ref IntPtr outLobbyDetailsHandle);
STUB(Result, EOS_Lobby_CopyLobbyDetailsHandle, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outLobbyDetailsHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Lobby_CopyLobbyDetailsHandleByInviteId(IntPtr handle, IntPtr options, ref IntPtr outLobbyDetailsHandle);
STUB(Result, EOS_Lobby_CopyLobbyDetailsHandleByInviteId, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outLobbyDetailsHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Lobby_CopyLobbyDetailsHandleByUiEventId(IntPtr handle, IntPtr options, ref IntPtr outLobbyDetailsHandle);
STUB(Result, EOS_Lobby_CopyLobbyDetailsHandleByUiEventId, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outLobbyDetailsHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Lobby_CreateLobby(IntPtr handle, IntPtr options, IntPtr clientData, OnCreateLobbyCallbackInternal completionDelegate);
STUB(void, EOS_Lobby_CreateLobby, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Lobby_CreateLobbySearch(IntPtr handle, IntPtr options, ref IntPtr outLobbySearchHandle);
STUB(Result, EOS_Lobby_CreateLobbySearch, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outLobbySearchHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Lobby_DestroyLobby(IntPtr handle, IntPtr options, IntPtr clientData, OnDestroyLobbyCallbackInternal completionDelegate);
STUB(void, EOS_Lobby_DestroyLobby, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Lobby_GetInviteCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Lobby_GetInviteCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Lobby_GetInviteIdByIndex(IntPtr handle, IntPtr options, IntPtr outBuffer, ref int inOutBufferLength);
STUB(Result, EOS_Lobby_GetInviteIdByIndex, NotImplemented, IntPtr handle, IntPtr options, IntPtr outBuffer, ref int inOutBufferLength);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Lobby_GetRTCRoomName(IntPtr handle, IntPtr options, IntPtr outBuffer, ref uint inOutBufferLength);
STUB(Result, EOS_Lobby_GetRTCRoomName, NotImplemented, IntPtr handle, IntPtr options, IntPtr outBuffer, ref uint inOutBufferLength);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Lobby_IsRTCRoomConnected(IntPtr handle, IntPtr options, ref int bOutIsConnected);
STUB(Result, EOS_Lobby_IsRTCRoomConnected, NotImplemented, IntPtr handle, IntPtr options, ref int bOutIsConnected);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Lobby_JoinLobby(IntPtr handle, IntPtr options, IntPtr clientData, OnJoinLobbyCallbackInternal completionDelegate);
STUB(void, EOS_Lobby_JoinLobby, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Lobby_KickMember(IntPtr handle, IntPtr options, IntPtr clientData, OnKickMemberCallbackInternal completionDelegate);
STUB(void, EOS_Lobby_KickMember, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Lobby_LeaveLobby(IntPtr handle, IntPtr options, IntPtr clientData, OnLeaveLobbyCallbackInternal completionDelegate);
STUB(void, EOS_Lobby_LeaveLobby, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Lobby_PromoteMember(IntPtr handle, IntPtr options, IntPtr clientData, OnPromoteMemberCallbackInternal completionDelegate);
STUB(void, EOS_Lobby_PromoteMember, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Lobby_QueryInvites(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.Lobby.OnQueryInvitesCallbackInternal completionDelegate);
STUB(void, EOS_Lobby_QueryInvites, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Lobby_RejectInvite(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.Lobby.OnRejectInviteCallbackInternal completionDelegate);
STUB(void, EOS_Lobby_RejectInvite, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Lobby_RemoveNotifyJoinLobbyAccepted(IntPtr handle, ulong inId);
STUB(void, EOS_Lobby_RemoveNotifyJoinLobbyAccepted, 0, IntPtr handle, ulong inId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Lobby_RemoveNotifyLobbyInviteAccepted(IntPtr handle, ulong inId);
STUB(void, EOS_Lobby_RemoveNotifyLobbyInviteAccepted, 0, IntPtr handle, ulong inId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Lobby_RemoveNotifyLobbyInviteReceived(IntPtr handle, ulong inId);
STUB(void, EOS_Lobby_RemoveNotifyLobbyInviteReceived, 0, IntPtr handle, ulong inId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Lobby_RemoveNotifyLobbyMemberStatusReceived(IntPtr handle, ulong inId);
STUB(void, EOS_Lobby_RemoveNotifyLobbyMemberStatusReceived, 0, IntPtr handle, ulong inId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Lobby_RemoveNotifyLobbyMemberUpdateReceived(IntPtr handle, ulong inId);
STUB(void, EOS_Lobby_RemoveNotifyLobbyMemberUpdateReceived, 0, IntPtr handle, ulong inId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Lobby_RemoveNotifyLobbyUpdateReceived(IntPtr handle, ulong inId);
STUB(void, EOS_Lobby_RemoveNotifyLobbyUpdateReceived, 0, IntPtr handle, ulong inId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Lobby_RemoveNotifyRTCRoomConnectionChanged(IntPtr handle, ulong inId);
STUB(void, EOS_Lobby_RemoveNotifyRTCRoomConnectionChanged, 0, IntPtr handle, ulong inId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Lobby_SendInvite(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.Lobby.OnSendInviteCallbackInternal completionDelegate);
STUB(void, EOS_Lobby_SendInvite, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Lobby_UpdateLobby(IntPtr handle, IntPtr options, IntPtr clientData, OnUpdateLobbyCallbackInternal completionDelegate);
STUB(void, EOS_Lobby_UpdateLobby, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Lobby_UpdateLobbyModification(IntPtr handle, IntPtr options, ref IntPtr outLobbyModificationHandle);
STUB(Result, EOS_Lobby_UpdateLobbyModification, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outLobbyModificationHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Logging_SetCallback(LogMessageFuncInternal callback);
STUB(Result, EOS_Logging_SetCallback, NotImplemented, IntPtr callback);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Logging_SetLogLevel(LogCategory logCategory, LogLevel logLevel);
STUB(Result, EOS_Logging_SetLogLevel, NotImplemented, IntPtr logCategory, IntPtr logLevel);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Metrics_BeginPlayerSession(IntPtr handle, IntPtr options);
STUB(Result, EOS_Metrics_BeginPlayerSession, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Metrics_EndPlayerSession(IntPtr handle, IntPtr options);
STUB(Result, EOS_Metrics_EndPlayerSession, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Mods_CopyModInfo(IntPtr handle, IntPtr options, ref IntPtr outEnumeratedMods);
STUB(Result, EOS_Mods_CopyModInfo, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outEnumeratedMods);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Mods_EnumerateMods(IntPtr handle, IntPtr options, IntPtr clientData, OnEnumerateModsCallbackInternal completionDelegate);
STUB(void, EOS_Mods_EnumerateMods, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Mods_InstallMod(IntPtr handle, IntPtr options, IntPtr clientData, OnInstallModCallbackInternal completionDelegate);
STUB(void, EOS_Mods_InstallMod, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Mods_ModInfo_Release(IntPtr modInfo);
STUB(void, EOS_Mods_ModInfo_Release, 0, IntPtr modInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Mods_UninstallMod(IntPtr handle, IntPtr options, IntPtr clientData, OnUninstallModCallbackInternal completionDelegate);
STUB(void, EOS_Mods_UninstallMod, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Mods_UpdateMod(IntPtr handle, IntPtr options, IntPtr clientData, OnUpdateModCallbackInternal completionDelegate);
STUB(void, EOS_Mods_UpdateMod, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_P2P_AcceptConnection(IntPtr handle, IntPtr options);
STUB(Result, EOS_P2P_AcceptConnection, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_P2P_AddNotifyIncomingPacketQueueFull(IntPtr handle, IntPtr options, IntPtr clientData, OnIncomingPacketQueueFullCallbackInternal incomingPacketQueueFullHandler);
STUB(ulong, EOS_P2P_AddNotifyIncomingPacketQueueFull, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr incomingPacketQueueFullHandler);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_P2P_AddNotifyPeerConnectionClosed(IntPtr handle, IntPtr options, IntPtr clientData, OnRemoteConnectionClosedCallbackInternal connectionClosedHandler);
STUB(ulong, EOS_P2P_AddNotifyPeerConnectionClosed, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr connectionClosedHandler);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_P2P_AddNotifyPeerConnectionEstablished(IntPtr handle, IntPtr options, IntPtr clientData, OnPeerConnectionEstablishedCallbackInternal connectionEstablishedHandler);
STUB(ulong, EOS_P2P_AddNotifyPeerConnectionEstablished, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr connectionEstablishedHandler);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_P2P_AddNotifyPeerConnectionRequest(IntPtr handle, IntPtr options, IntPtr clientData, OnIncomingConnectionRequestCallbackInternal connectionRequestHandler);
STUB(ulong, EOS_P2P_AddNotifyPeerConnectionRequest, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr connectionRequestHandler);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_P2P_ClearPacketQueue(IntPtr handle, IntPtr options);
STUB(Result, EOS_P2P_ClearPacketQueue, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_P2P_CloseConnection(IntPtr handle, IntPtr options);
STUB(Result, EOS_P2P_CloseConnection, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_P2P_CloseConnections(IntPtr handle, IntPtr options);
STUB(Result, EOS_P2P_CloseConnections, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_P2P_GetNATType(IntPtr handle, IntPtr options, ref NATType outNATType);
STUB(Result, EOS_P2P_GetNATType, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outNATType);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_P2P_GetNextReceivedPacketSize(IntPtr handle, IntPtr options, ref uint outPacketSizeBytes);
STUB(Result, EOS_P2P_GetNextReceivedPacketSize, NotImplemented, IntPtr handle, IntPtr options, ref uint outPacketSizeBytes);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_P2P_GetPacketQueueInfo(IntPtr handle, IntPtr options, ref PacketQueueInfoInternal outPacketQueueInfo);
STUB(Result, EOS_P2P_GetPacketQueueInfo, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outPacketQueueInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_P2P_GetPortRange(IntPtr handle, IntPtr options, ref ushort outPort, ref ushort outNumAdditionalPortsToTry);
STUB(Result, EOS_P2P_GetPortRange, NotImplemented, IntPtr handle, IntPtr options, ref ushort outPort, ref ushort outNumAdditionalPortsToTry);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_P2P_GetRelayControl(IntPtr handle, IntPtr options, ref RelayControl outRelayControl);
STUB(Result, EOS_P2P_GetRelayControl, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outRelayControl);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_P2P_QueryNATType(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryNATTypeCompleteCallbackInternal completionDelegate);
STUB(void, EOS_P2P_QueryNATType, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_P2P_ReceivePacket(IntPtr handle, IntPtr options, ref IntPtr outPeerId, ref SocketIdInternal outSocketId, ref byte outChannel, IntPtr outData, ref uint outBytesWritten);
STUB(Result, EOS_P2P_ReceivePacket, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outPeerId, ref IntPtr outSocketId, ref byte outChannel, IntPtr outData, ref uint outBytesWritten);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_P2P_RemoveNotifyIncomingPacketQueueFull(IntPtr handle, ulong notificationId);
STUB(void, EOS_P2P_RemoveNotifyIncomingPacketQueueFull, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_P2P_RemoveNotifyPeerConnectionClosed(IntPtr handle, ulong notificationId);
STUB(void, EOS_P2P_RemoveNotifyPeerConnectionClosed, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_P2P_RemoveNotifyPeerConnectionEstablished(IntPtr handle, ulong notificationId);
STUB(void, EOS_P2P_RemoveNotifyPeerConnectionEstablished, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_P2P_RemoveNotifyPeerConnectionRequest(IntPtr handle, ulong notificationId);
STUB(void, EOS_P2P_RemoveNotifyPeerConnectionRequest, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_P2P_SendPacket(IntPtr handle, IntPtr options);
STUB(Result, EOS_P2P_SendPacket, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_P2P_SetPacketQueueSize(IntPtr handle, IntPtr options);
STUB(Result, EOS_P2P_SetPacketQueueSize, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_P2P_SetPortRange(IntPtr handle, IntPtr options);
STUB(Result, EOS_P2P_SetPortRange, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_P2P_SetRelayControl(IntPtr handle, IntPtr options);
STUB(Result, EOS_P2P_SetRelayControl, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Platform_CheckForLauncherAndRestart(IntPtr handle);
STUB(Result, EOS_Platform_CheckForLauncherAndRestart, NotImplemented, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_Create(IntPtr options);
STUB(IntPtr, EOS_Platform_Create, 0, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetAchievementsInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetAchievementsInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Platform_GetActiveCountryCode(IntPtr handle, IntPtr localUserId, IntPtr outBuffer, ref int inOutBufferLength);
STUB(Result, EOS_Platform_GetActiveCountryCode, NotImplemented, IntPtr handle, IntPtr localUserId, IntPtr outBuffer, ref int inOutBufferLength);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Platform_GetActiveLocaleCode(IntPtr handle, IntPtr localUserId, IntPtr outBuffer, ref int inOutBufferLength);
STUB(Result, EOS_Platform_GetActiveLocaleCode, NotImplemented, IntPtr handle, IntPtr localUserId, IntPtr outBuffer, ref int inOutBufferLength);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetAntiCheatClientInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetAntiCheatClientInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetAntiCheatServerInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetAntiCheatServerInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetAuthInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetAuthInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetConnectInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetConnectInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetCustomInvitesInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetCustomInvitesInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetEcomInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetEcomInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetFriendsInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetFriendsInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetKWSInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetKWSInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetLeaderboardsInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetLeaderboardsInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetLobbyInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetLobbyInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetMetricsInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetMetricsInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetModsInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetModsInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Platform_GetOverrideCountryCode(IntPtr handle, IntPtr outBuffer, ref int inOutBufferLength);
STUB(Result, EOS_Platform_GetOverrideCountryCode, NotImplemented, IntPtr handle, IntPtr outBuffer, ref int inOutBufferLength);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Platform_GetOverrideLocaleCode(IntPtr handle, IntPtr outBuffer, ref int inOutBufferLength);
STUB(Result, EOS_Platform_GetOverrideLocaleCode, NotImplemented, IntPtr handle, IntPtr outBuffer, ref int inOutBufferLength);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetP2PInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetP2PInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetPlayerDataStorageInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetPlayerDataStorageInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetPresenceInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetPresenceInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetProgressionSnapshotInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetProgressionSnapshotInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetRTCAdminInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetRTCAdminInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetRTCInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetRTCInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetReportsInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetReportsInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetSanctionsInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetSanctionsInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetSessionsInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetSessionsInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetStatsInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetStatsInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetTitleStorageInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetTitleStorageInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetUIInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetUIInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_Platform_GetUserInfoInterface(IntPtr handle);
STUB(IntPtr, EOS_Platform_GetUserInfoInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Platform_Release(IntPtr handle);
STUB(void, EOS_Platform_Release, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Platform_SetOverrideCountryCode(IntPtr handle, IntPtr newCountryCode);
STUB(Result, EOS_Platform_SetOverrideCountryCode, NotImplemented, IntPtr handle, IntPtr newCountryCode);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Platform_SetOverrideLocaleCode(IntPtr handle, IntPtr newLocaleCode);
STUB(Result, EOS_Platform_SetOverrideLocaleCode, NotImplemented, IntPtr handle, IntPtr newLocaleCode);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Platform_Tick(IntPtr handle);
STUB(void, EOS_Platform_Tick, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_PlayerDataStorageFileTransferRequest_CancelRequest(IntPtr handle);
STUB(Result, EOS_PlayerDataStorageFileTransferRequest_CancelRequest, NotImplemented, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_PlayerDataStorageFileTransferRequest_GetFileRequestState(IntPtr handle);
STUB(Result, EOS_PlayerDataStorageFileTransferRequest_GetFileRequestState, NotImplemented, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_PlayerDataStorageFileTransferRequest_GetFilename(IntPtr handle, uint filenameStringBufferSizeBytes, IntPtr outStringBuffer, ref int outStringLength);
STUB(Result, EOS_PlayerDataStorageFileTransferRequest_GetFilename, NotImplemented, IntPtr handle, uint filenameStringBufferSizeBytes, IntPtr outStringBuffer, ref int outStringLength);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_PlayerDataStorageFileTransferRequest_Release(IntPtr playerDataStorageFileTransferHandle);
STUB(void, EOS_PlayerDataStorageFileTransferRequest_Release, 0, IntPtr playerDataStorageFileTransferHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_PlayerDataStorage_CopyFileMetadataAtIndex(IntPtr handle, IntPtr copyFileMetadataOptions, ref IntPtr outMetadata);
STUB(Result, EOS_PlayerDataStorage_CopyFileMetadataAtIndex, NotImplemented, IntPtr handle, IntPtr copyFileMetadataOptions, ref IntPtr outMetadata);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_PlayerDataStorage_CopyFileMetadataByFilename(IntPtr handle, IntPtr copyFileMetadataOptions, ref IntPtr outMetadata);
STUB(Result, EOS_PlayerDataStorage_CopyFileMetadataByFilename, NotImplemented, IntPtr handle, IntPtr copyFileMetadataOptions, ref IntPtr outMetadata);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_PlayerDataStorage_DeleteCache(IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionCallback);
STUB(Result, EOS_PlayerDataStorage_DeleteCache, NotImplemented, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionCallback);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_PlayerDataStorage_DeleteFile(IntPtr handle, IntPtr deleteOptions, IntPtr clientData, OnDeleteFileCompleteCallbackInternal completionCallback);
STUB(void, EOS_PlayerDataStorage_DeleteFile, 0, IntPtr handle, IntPtr deleteOptions, IntPtr clientData, IntPtr completionCallback);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_PlayerDataStorage_DuplicateFile(IntPtr handle, IntPtr duplicateOptions, IntPtr clientData, OnDuplicateFileCompleteCallbackInternal completionCallback);
STUB(void, EOS_PlayerDataStorage_DuplicateFile, 0, IntPtr handle, IntPtr duplicateOptions, IntPtr clientData, IntPtr completionCallback);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_PlayerDataStorage_FileMetadata_Release(IntPtr fileMetadata);
STUB(void, EOS_PlayerDataStorage_FileMetadata_Release, 0, IntPtr fileMetadata);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_PlayerDataStorage_GetFileMetadataCount(IntPtr handle, IntPtr getFileMetadataCountOptions, ref int outFileMetadataCount);
STUB(Result, EOS_PlayerDataStorage_GetFileMetadataCount, NotImplemented, IntPtr handle, IntPtr getFileMetadataCountOptions, ref int outFileMetadataCount);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_PlayerDataStorage_QueryFile(IntPtr handle, IntPtr queryFileOptions, IntPtr clientData, IntPtr completionCallback);
STUB(void, EOS_PlayerDataStorage_QueryFile, 0, IntPtr handle, IntPtr queryFileOptions, IntPtr clientData, IntPtr completionCallback);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_PlayerDataStorage_QueryFileList(IntPtr handle, IntPtr queryFileListOptions, IntPtr clientData, IntPtr completionCallback);
STUB(void, EOS_PlayerDataStorage_QueryFileList, 0, IntPtr handle, IntPtr queryFileListOptions, IntPtr clientData, IntPtr completionCallback);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_PlayerDataStorage_ReadFile(IntPtr handle, IntPtr readOptions, IntPtr clientData, IntPtr completionCallback);
STUB(IntPtr, EOS_PlayerDataStorage_ReadFile, 0, IntPtr handle, IntPtr readOptions, IntPtr clientData, IntPtr completionCallback);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_PlayerDataStorage_WriteFile(IntPtr handle, IntPtr writeOptions, IntPtr clientData, OnWriteFileCompleteCallbackInternal completionCallback);
STUB(IntPtr, EOS_PlayerDataStorage_WriteFile, 0, IntPtr handle, IntPtr writeOptions, IntPtr clientData, IntPtr completionCallback);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_PresenceModification_DeleteData(IntPtr handle, IntPtr options);
STUB(Result, EOS_PresenceModification_DeleteData, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_PresenceModification_Release(IntPtr presenceModificationHandle);
STUB(void, EOS_PresenceModification_Release, 0, IntPtr presenceModificationHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_PresenceModification_SetData(IntPtr handle, IntPtr options);
STUB(Result, EOS_PresenceModification_SetData, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_PresenceModification_SetJoinInfo(IntPtr handle, IntPtr options);
STUB(Result, EOS_PresenceModification_SetJoinInfo, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_PresenceModification_SetRawRichText(IntPtr handle, IntPtr options);
STUB(Result, EOS_PresenceModification_SetRawRichText, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_PresenceModification_SetStatus(IntPtr handle, IntPtr options);
STUB(Result, EOS_PresenceModification_SetStatus, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_Presence_AddNotifyJoinGameAccepted(IntPtr handle, IntPtr options, IntPtr clientData, OnJoinGameAcceptedCallbackInternal notificationFn);
STUB(ulong, EOS_Presence_AddNotifyJoinGameAccepted, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_Presence_AddNotifyOnPresenceChanged(IntPtr handle, IntPtr options, IntPtr clientData, OnPresenceChangedCallbackInternal notificationHandler);
STUB(ulong, EOS_Presence_AddNotifyOnPresenceChanged, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationHandler);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Presence_CopyPresence(IntPtr handle, IntPtr options, ref IntPtr outPresence);
STUB(Result, EOS_Presence_CopyPresence, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outPresence);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Presence_CreatePresenceModification(IntPtr handle, IntPtr options, ref IntPtr outPresenceModificationHandle);
STUB(Result, EOS_Presence_CreatePresenceModification, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outPresenceModificationHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Presence_GetJoinInfo(IntPtr handle, IntPtr options, IntPtr outBuffer, ref int inOutBufferLength);
STUB(Result, EOS_Presence_GetJoinInfo, NotImplemented, IntPtr handle, IntPtr options, IntPtr outBuffer, ref int inOutBufferLength);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern int EOS_Presence_HasPresence(IntPtr handle, IntPtr options);
STUB(int, EOS_Presence_HasPresence, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Presence_Info_Release(IntPtr presenceInfo);
STUB(void, EOS_Presence_Info_Release, 0, IntPtr presenceInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Presence_QueryPresence(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryPresenceCompleteCallbackInternal completionDelegate);
STUB(void, EOS_Presence_QueryPresence, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Presence_RemoveNotifyJoinGameAccepted(IntPtr handle, ulong inId);
STUB(void, EOS_Presence_RemoveNotifyJoinGameAccepted, 0, IntPtr handle, ulong inId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Presence_RemoveNotifyOnPresenceChanged(IntPtr handle, ulong notificationId);
STUB(void, EOS_Presence_RemoveNotifyOnPresenceChanged, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Presence_SetPresence(IntPtr handle, IntPtr options, IntPtr clientData, SetPresenceCompleteCallbackInternal completionDelegate);
STUB(void, EOS_Presence_SetPresence, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_ProductUserId_FromString(IntPtr productUserIdString);
STUB(IntPtr, EOS_ProductUserId_FromString, 0, IntPtr productUserIdString);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern int EOS_ProductUserId_IsValid(IntPtr accountId);
STUB(int, EOS_ProductUserId_IsValid, 0, IntPtr accountId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_ProductUserId_ToString(IntPtr accountId, IntPtr outBuffer, ref int inOutBufferLength);
STUB(Result, EOS_ProductUserId_ToString, NotImplemented, IntPtr accountId, IntPtr outBuffer, ref int inOutBufferLength);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_ProgressionSnapshot_AddProgression(IntPtr handle, IntPtr options);
STUB(Result, EOS_ProgressionSnapshot_AddProgression, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_ProgressionSnapshot_BeginSnapshot(IntPtr handle, IntPtr options, ref uint outSnapshotId);
STUB(Result, EOS_ProgressionSnapshot_BeginSnapshot, NotImplemented, IntPtr handle, IntPtr options, ref uint outSnapshotId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_ProgressionSnapshot_DeleteSnapshot(IntPtr handle, IntPtr options, IntPtr clientData, OnDeleteSnapshotCallbackInternal completionDelegate);
STUB(void, EOS_ProgressionSnapshot_DeleteSnapshot, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_ProgressionSnapshot_EndSnapshot(IntPtr handle, IntPtr options);
STUB(Result, EOS_ProgressionSnapshot_EndSnapshot, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_ProgressionSnapshot_SubmitSnapshot(IntPtr handle, IntPtr options, IntPtr clientData, OnSubmitSnapshotCallbackInternal completionDelegate);
STUB(void, EOS_ProgressionSnapshot_SubmitSnapshot, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_RTCAdmin_CopyUserTokenByIndex(IntPtr handle, IntPtr options, ref IntPtr outUserToken);
STUB(Result, EOS_RTCAdmin_CopyUserTokenByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outUserToken);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_RTCAdmin_CopyUserTokenByUserId(IntPtr handle, IntPtr options, ref IntPtr outUserToken);
STUB(Result, EOS_RTCAdmin_CopyUserTokenByUserId, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outUserToken);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_RTCAdmin_Kick(IntPtr handle, IntPtr options, IntPtr clientData, OnKickCompleteCallbackInternal completionDelegate);
STUB(void, EOS_RTCAdmin_Kick, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_RTCAdmin_QueryJoinRoomToken(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryJoinRoomTokenCompleteCallbackInternal completionDelegate);
STUB(void, EOS_RTCAdmin_QueryJoinRoomToken, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_RTCAdmin_SetParticipantHardMute(IntPtr handle, IntPtr options, IntPtr clientData, OnSetParticipantHardMuteCompleteCallbackInternal completionDelegate);
STUB(void, EOS_RTCAdmin_SetParticipantHardMute, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_RTCAdmin_UserToken_Release(IntPtr userToken);
STUB(void, EOS_RTCAdmin_UserToken_Release, 0, IntPtr userToken);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_RTCAudio_AddNotifyAudioBeforeRender(IntPtr handle, IntPtr options, IntPtr clientData, OnAudioBeforeRenderCallbackInternal completionDelegate);
STUB(ulong, EOS_RTCAudio_AddNotifyAudioBeforeRender, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_RTCAudio_AddNotifyAudioBeforeSend(IntPtr handle, IntPtr options, IntPtr clientData, OnAudioBeforeSendCallbackInternal completionDelegate);
STUB(ulong, EOS_RTCAudio_AddNotifyAudioBeforeSend, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_RTCAudio_AddNotifyAudioDevicesChanged(IntPtr handle, IntPtr options, IntPtr clientData, OnAudioDevicesChangedCallbackInternal completionDelegate);
STUB(ulong, EOS_RTCAudio_AddNotifyAudioDevicesChanged, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_RTCAudio_AddNotifyAudioInputState(IntPtr handle, IntPtr options, IntPtr clientData, OnAudioInputStateCallbackInternal completionDelegate);
STUB(ulong, EOS_RTCAudio_AddNotifyAudioInputState, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_RTCAudio_AddNotifyAudioOutputState(IntPtr handle, IntPtr options, IntPtr clientData, OnAudioOutputStateCallbackInternal completionDelegate);
STUB(ulong, EOS_RTCAudio_AddNotifyAudioOutputState, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_RTCAudio_AddNotifyParticipantUpdated(IntPtr handle, IntPtr options, IntPtr clientData, OnParticipantUpdatedCallbackInternal completionDelegate);
STUB(ulong, EOS_RTCAudio_AddNotifyParticipantUpdated, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_RTCAudio_GetAudioInputDeviceByIndex(IntPtr handle, IntPtr options);
STUB(IntPtr, EOS_RTCAudio_GetAudioInputDeviceByIndex, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_RTCAudio_GetAudioInputDevicesCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_RTCAudio_GetAudioInputDevicesCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_RTCAudio_GetAudioOutputDeviceByIndex(IntPtr handle, IntPtr options);
STUB(IntPtr, EOS_RTCAudio_GetAudioOutputDeviceByIndex, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_RTCAudio_GetAudioOutputDevicesCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_RTCAudio_GetAudioOutputDevicesCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_RTCAudio_RegisterPlatformAudioUser(IntPtr handle, IntPtr options);
STUB(Result, EOS_RTCAudio_RegisterPlatformAudioUser, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_RTCAudio_RemoveNotifyAudioBeforeRender(IntPtr handle, ulong notificationId);
STUB(void, EOS_RTCAudio_RemoveNotifyAudioBeforeRender, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_RTCAudio_RemoveNotifyAudioBeforeSend(IntPtr handle, ulong notificationId);
STUB(void, EOS_RTCAudio_RemoveNotifyAudioBeforeSend, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_RTCAudio_RemoveNotifyAudioDevicesChanged(IntPtr handle, ulong notificationId);
STUB(void, EOS_RTCAudio_RemoveNotifyAudioDevicesChanged, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_RTCAudio_RemoveNotifyAudioInputState(IntPtr handle, ulong notificationId);
STUB(void, EOS_RTCAudio_RemoveNotifyAudioInputState, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_RTCAudio_RemoveNotifyAudioOutputState(IntPtr handle, ulong notificationId);
STUB(void, EOS_RTCAudio_RemoveNotifyAudioOutputState, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_RTCAudio_RemoveNotifyParticipantUpdated(IntPtr handle, ulong notificationId);
STUB(void, EOS_RTCAudio_RemoveNotifyParticipantUpdated, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_RTCAudio_SendAudio(IntPtr handle, IntPtr options);
STUB(Result, EOS_RTCAudio_SendAudio, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_RTCAudio_SetAudioInputSettings(IntPtr handle, IntPtr options);
STUB(Result, EOS_RTCAudio_SetAudioInputSettings, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_RTCAudio_SetAudioOutputSettings(IntPtr handle, IntPtr options);
STUB(Result, EOS_RTCAudio_SetAudioOutputSettings, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_RTCAudio_UnregisterPlatformAudioUser(IntPtr handle, IntPtr options);
STUB(Result, EOS_RTCAudio_UnregisterPlatformAudioUser, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_RTCAudio_UpdateReceiving(IntPtr handle, IntPtr options, IntPtr clientData, OnUpdateReceivingCallbackInternal completionDelegate);
STUB(void, EOS_RTCAudio_UpdateReceiving, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_RTCAudio_UpdateSending(IntPtr handle, IntPtr options, IntPtr clientData, OnUpdateSendingCallbackInternal completionDelegate);
STUB(void, EOS_RTCAudio_UpdateSending, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_RTC_AddNotifyDisconnected(IntPtr handle, IntPtr options, IntPtr clientData, OnDisconnectedCallbackInternal completionDelegate);
STUB(ulong, EOS_RTC_AddNotifyDisconnected, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_RTC_AddNotifyParticipantStatusChanged(IntPtr handle, IntPtr options, IntPtr clientData, OnParticipantStatusChangedCallbackInternal completionDelegate);
STUB(ulong, EOS_RTC_AddNotifyParticipantStatusChanged, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_RTC_BlockParticipant(IntPtr handle, IntPtr options, IntPtr clientData, OnBlockParticipantCallbackInternal completionDelegate);
STUB(void, EOS_RTC_BlockParticipant, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_RTC_GetAudioInterface(IntPtr handle);
STUB(IntPtr, EOS_RTC_GetAudioInterface, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_RTC_JoinRoom(IntPtr handle, IntPtr options, IntPtr clientData, OnJoinRoomCallbackInternal completionDelegate);
STUB(void, EOS_RTC_JoinRoom, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_RTC_LeaveRoom(IntPtr handle, IntPtr options, IntPtr clientData, OnLeaveRoomCallbackInternal completionDelegate);
STUB(void, EOS_RTC_LeaveRoom, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_RTC_RemoveNotifyDisconnected(IntPtr handle, ulong notificationId);
STUB(void, EOS_RTC_RemoveNotifyDisconnected, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_RTC_RemoveNotifyParticipantStatusChanged(IntPtr handle, ulong notificationId);
STUB(void, EOS_RTC_RemoveNotifyParticipantStatusChanged, 0, IntPtr handle, ulong notificationId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_RTC_SetRoomSetting(IntPtr handle, IntPtr options);
STUB(Result, EOS_RTC_SetRoomSetting, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_RTC_SetSetting(IntPtr handle, IntPtr options);
STUB(Result, EOS_RTC_SetSetting, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Reports_SendPlayerBehaviorReport(IntPtr handle, IntPtr options, IntPtr clientData, OnSendPlayerBehaviorReportCompleteCallbackInternal completionDelegate);
STUB(void, EOS_Reports_SendPlayerBehaviorReport, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Sanctions_CopyPlayerSanctionByIndex(IntPtr handle, IntPtr options, ref IntPtr outSanction);
STUB(Result, EOS_Sanctions_CopyPlayerSanctionByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outSanction);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Sanctions_GetPlayerSanctionCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Sanctions_GetPlayerSanctionCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Sanctions_PlayerSanction_Release(IntPtr sanction);
STUB(void, EOS_Sanctions_PlayerSanction_Release, 0, IntPtr sanction);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Sanctions_QueryActivePlayerSanctions(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryActivePlayerSanctionsCallbackInternal completionDelegate);
STUB(void, EOS_Sanctions_QueryActivePlayerSanctions, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_SessionDetails_Attribute_Release(IntPtr sessionAttribute);
STUB(void, EOS_SessionDetails_Attribute_Release, 0, IntPtr sessionAttribute);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_SessionDetails_CopyInfo(IntPtr handle, IntPtr options, ref IntPtr outSessionInfo);
STUB(Result, EOS_SessionDetails_CopyInfo, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outSessionInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_SessionDetails_CopySessionAttributeByIndex(IntPtr handle, IntPtr options, ref IntPtr outSessionAttribute);
STUB(Result, EOS_SessionDetails_CopySessionAttributeByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outSessionAttribute);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_SessionDetails_CopySessionAttributeByKey(IntPtr handle, IntPtr options, ref IntPtr outSessionAttribute);
STUB(Result, EOS_SessionDetails_CopySessionAttributeByKey, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outSessionAttribute);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_SessionDetails_GetSessionAttributeCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_SessionDetails_GetSessionAttributeCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_SessionDetails_Info_Release(IntPtr sessionInfo);
STUB(void, EOS_SessionDetails_Info_Release, 0, IntPtr sessionInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_SessionDetails_Release(IntPtr sessionHandle);
STUB(void, EOS_SessionDetails_Release, 0, IntPtr sessionHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_SessionModification_AddAttribute(IntPtr handle, IntPtr options);
STUB(Result, EOS_SessionModification_AddAttribute, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_SessionModification_Release(IntPtr sessionModificationHandle);
STUB(void, EOS_SessionModification_Release, 0, IntPtr sessionModificationHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_SessionModification_RemoveAttribute(IntPtr handle, IntPtr options);
STUB(Result, EOS_SessionModification_RemoveAttribute, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_SessionModification_SetBucketId(IntPtr handle, IntPtr options);
STUB(Result, EOS_SessionModification_SetBucketId, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_SessionModification_SetHostAddress(IntPtr handle, IntPtr options);
STUB(Result, EOS_SessionModification_SetHostAddress, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_SessionModification_SetInvitesAllowed(IntPtr handle, IntPtr options);
STUB(Result, EOS_SessionModification_SetInvitesAllowed, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_SessionModification_SetJoinInProgressAllowed(IntPtr handle, IntPtr options);
STUB(Result, EOS_SessionModification_SetJoinInProgressAllowed, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_SessionModification_SetMaxPlayers(IntPtr handle, IntPtr options);
STUB(Result, EOS_SessionModification_SetMaxPlayers, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_SessionModification_SetPermissionLevel(IntPtr handle, IntPtr options);
STUB(Result, EOS_SessionModification_SetPermissionLevel, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_SessionSearch_CopySearchResultByIndex(IntPtr handle, IntPtr options, ref IntPtr outSessionHandle);
STUB(Result, EOS_SessionSearch_CopySearchResultByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outSessionHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_SessionSearch_Find(IntPtr handle, IntPtr options, IntPtr clientData, SessionSearchOnFindCallbackInternal completionDelegate);
STUB(void, EOS_SessionSearch_Find, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_SessionSearch_GetSearchResultCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_SessionSearch_GetSearchResultCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_SessionSearch_Release(IntPtr sessionSearchHandle);
STUB(void, EOS_SessionSearch_Release, 0, IntPtr sessionSearchHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_SessionSearch_RemoveParameter(IntPtr handle, IntPtr options);
STUB(Result, EOS_SessionSearch_RemoveParameter, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_SessionSearch_SetMaxResults(IntPtr handle, IntPtr options);
STUB(Result, EOS_SessionSearch_SetMaxResults, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_SessionSearch_SetParameter(IntPtr handle, IntPtr options);
STUB(Result, EOS_SessionSearch_SetParameter, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_SessionSearch_SetSessionId(IntPtr handle, IntPtr options);
STUB(Result, EOS_SessionSearch_SetSessionId, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_SessionSearch_SetTargetUserId(IntPtr handle, IntPtr options);
STUB(Result, EOS_SessionSearch_SetTargetUserId, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_Sessions_AddNotifyJoinSessionAccepted(IntPtr handle, IntPtr options, IntPtr clientData, OnJoinSessionAcceptedCallbackInternal notificationFn);
STUB(ulong, EOS_Sessions_AddNotifyJoinSessionAccepted, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_Sessions_AddNotifySessionInviteAccepted(IntPtr handle, IntPtr options, IntPtr clientData, OnSessionInviteAcceptedCallbackInternal notificationFn);
STUB(ulong, EOS_Sessions_AddNotifySessionInviteAccepted, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_Sessions_AddNotifySessionInviteReceived(IntPtr handle, IntPtr options, IntPtr clientData, OnSessionInviteReceivedCallbackInternal notificationFn);
STUB(ulong, EOS_Sessions_AddNotifySessionInviteReceived, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Sessions_CopyActiveSessionHandle(IntPtr handle, IntPtr options, ref IntPtr outSessionHandle);
STUB(Result, EOS_Sessions_CopyActiveSessionHandle, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outSessionHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Sessions_CopySessionHandleByInviteId(IntPtr handle, IntPtr options, ref IntPtr outSessionHandle);
STUB(Result, EOS_Sessions_CopySessionHandleByInviteId, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outSessionHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Sessions_CopySessionHandleByUiEventId(IntPtr handle, IntPtr options, ref IntPtr outSessionHandle);
STUB(Result, EOS_Sessions_CopySessionHandleByUiEventId, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outSessionHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Sessions_CopySessionHandleForPresence(IntPtr handle, IntPtr options, ref IntPtr outSessionHandle);
STUB(Result, EOS_Sessions_CopySessionHandleForPresence, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outSessionHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Sessions_CreateSessionModification(IntPtr handle, IntPtr options, ref IntPtr outSessionModificationHandle);
STUB(Result, EOS_Sessions_CreateSessionModification, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outSessionModificationHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Sessions_CreateSessionSearch(IntPtr handle, IntPtr options, ref IntPtr outSessionSearchHandle);
STUB(Result, EOS_Sessions_CreateSessionSearch, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outSessionSearchHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Sessions_DestroySession(IntPtr handle, IntPtr options, IntPtr clientData, OnDestroySessionCallbackInternal completionDelegate);
STUB(void, EOS_Sessions_DestroySession, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Sessions_DumpSessionState(IntPtr handle, IntPtr options);
STUB(Result, EOS_Sessions_DumpSessionState, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Sessions_EndSession(IntPtr handle, IntPtr options, IntPtr clientData, OnEndSessionCallbackInternal completionDelegate);
STUB(void, EOS_Sessions_EndSession, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Sessions_GetInviteCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Sessions_GetInviteCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Sessions_GetInviteIdByIndex(IntPtr handle, IntPtr options, IntPtr outBuffer, ref int inOutBufferLength);
STUB(Result, EOS_Sessions_GetInviteIdByIndex, NotImplemented, IntPtr handle, IntPtr options, IntPtr outBuffer, ref int inOutBufferLength);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Sessions_IsUserInSession(IntPtr handle, IntPtr options);
STUB(Result, EOS_Sessions_IsUserInSession, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Sessions_JoinSession(IntPtr handle, IntPtr options, IntPtr clientData, OnJoinSessionCallbackInternal completionDelegate);
STUB(void, EOS_Sessions_JoinSession, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Sessions_QueryInvites(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.Sessions.OnQueryInvitesCallbackInternal completionDelegate);
STUB(void, EOS_Sessions_QueryInvites, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Sessions_RegisterPlayers(IntPtr handle, IntPtr options, IntPtr clientData, OnRegisterPlayersCallbackInternal completionDelegate);
STUB(void, EOS_Sessions_RegisterPlayers, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Sessions_RejectInvite(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.Sessions.OnRejectInviteCallbackInternal completionDelegate);
STUB(void, EOS_Sessions_RejectInvite, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Sessions_RemoveNotifyJoinSessionAccepted(IntPtr handle, ulong inId);
STUB(void, EOS_Sessions_RemoveNotifyJoinSessionAccepted, 0, IntPtr handle, ulong inId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Sessions_RemoveNotifySessionInviteAccepted(IntPtr handle, ulong inId);
STUB(void, EOS_Sessions_RemoveNotifySessionInviteAccepted, 0, IntPtr handle, ulong inId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Sessions_RemoveNotifySessionInviteReceived(IntPtr handle, ulong inId);
STUB(void, EOS_Sessions_RemoveNotifySessionInviteReceived, 0, IntPtr handle, ulong inId);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Sessions_SendInvite(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.Sessions.OnSendInviteCallbackInternal completionDelegate);
STUB(void, EOS_Sessions_SendInvite, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Sessions_StartSession(IntPtr handle, IntPtr options, IntPtr clientData, OnStartSessionCallbackInternal completionDelegate);
STUB(void, EOS_Sessions_StartSession, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Sessions_UnregisterPlayers(IntPtr handle, IntPtr options, IntPtr clientData, OnUnregisterPlayersCallbackInternal completionDelegate);
STUB(void, EOS_Sessions_UnregisterPlayers, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Sessions_UpdateSession(IntPtr handle, IntPtr options, IntPtr clientData, OnUpdateSessionCallbackInternal completionDelegate);
STUB(void, EOS_Sessions_UpdateSession, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Sessions_UpdateSessionModification(IntPtr handle, IntPtr options, ref IntPtr outSessionModificationHandle);
STUB(Result, EOS_Sessions_UpdateSessionModification, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outSessionModificationHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Shutdown();
// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Stats_CopyStatByIndex(IntPtr handle, IntPtr options, ref IntPtr outStat);
STUB(Result, EOS_Stats_CopyStatByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outStat);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_Stats_CopyStatByName(IntPtr handle, IntPtr options, ref IntPtr outStat);
STUB(Result, EOS_Stats_CopyStatByName, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outStat);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_Stats_GetStatsCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_Stats_GetStatsCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Stats_IngestStat(IntPtr handle, IntPtr options, IntPtr clientData, OnIngestStatCompleteCallbackInternal completionDelegate);
STUB(void, EOS_Stats_IngestStat, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Stats_QueryStats(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryStatsCompleteCallbackInternal completionDelegate);
STUB(void, EOS_Stats_QueryStats, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_Stats_Stat_Release(IntPtr stat);
STUB(void, EOS_Stats_Stat_Release, 0, IntPtr stat);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_TitleStorageFileTransferRequest_CancelRequest(IntPtr handle);
STUB(Result, EOS_TitleStorageFileTransferRequest_CancelRequest, NotImplemented, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_TitleStorageFileTransferRequest_GetFileRequestState(IntPtr handle);
STUB(Result, EOS_TitleStorageFileTransferRequest_GetFileRequestState, NotImplemented, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_TitleStorageFileTransferRequest_GetFilename(IntPtr handle, uint filenameStringBufferSizeBytes, IntPtr outStringBuffer, ref int outStringLength);
STUB(Result, EOS_TitleStorageFileTransferRequest_GetFilename, NotImplemented, IntPtr handle, uint filenameStringBufferSizeBytes, IntPtr outStringBuffer, ref int outStringLength);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_TitleStorageFileTransferRequest_Release(IntPtr titleStorageFileTransferHandle);
STUB(void, EOS_TitleStorageFileTransferRequest_Release, 0, IntPtr titleStorageFileTransferHandle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_TitleStorage_CopyFileMetadataAtIndex(IntPtr handle, IntPtr options, ref IntPtr outMetadata);
STUB(Result, EOS_TitleStorage_CopyFileMetadataAtIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outMetadata);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_TitleStorage_CopyFileMetadataByFilename(IntPtr handle, IntPtr options, ref IntPtr outMetadata);
STUB(Result, EOS_TitleStorage_CopyFileMetadataByFilename, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outMetadata);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_TitleStorage_DeleteCache(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.TitleStorage.OnDeleteCacheCompleteCallbackInternal completionCallback);
STUB(Result, EOS_TitleStorage_DeleteCache, NotImplemented, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionCallback);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_TitleStorage_FileMetadata_Release(IntPtr fileMetadata);
STUB(void, EOS_TitleStorage_FileMetadata_Release, 0, IntPtr fileMetadata);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_TitleStorage_GetFileMetadataCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_TitleStorage_GetFileMetadataCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_TitleStorage_QueryFile(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.TitleStorage.OnQueryFileCompleteCallbackInternal completionCallback);
STUB(void, EOS_TitleStorage_QueryFile, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionCallback);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_TitleStorage_QueryFileList(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.TitleStorage.OnQueryFileListCompleteCallbackInternal completionCallback);
STUB(void, EOS_TitleStorage_QueryFileList, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionCallback);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern IntPtr EOS_TitleStorage_ReadFile(IntPtr handle, IntPtr options, IntPtr clientData, Epic.OnlineServices.TitleStorage.OnReadFileCompleteCallbackInternal completionCallback);
STUB(IntPtr, EOS_TitleStorage_ReadFile, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionCallback);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_UI_AcknowledgeEventId(IntPtr handle, IntPtr options);
STUB(Result, EOS_UI_AcknowledgeEventId, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern ulong EOS_UI_AddNotifyDisplaySettingsUpdated(IntPtr handle, IntPtr options, IntPtr clientData, OnDisplaySettingsUpdatedCallbackInternal notificationFn);
STUB(ulong, EOS_UI_AddNotifyDisplaySettingsUpdated, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr notificationFn);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern int EOS_UI_GetFriendsVisible(IntPtr handle, IntPtr options);
STUB(int, EOS_UI_GetFriendsVisible, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern NotificationLocation EOS_UI_GetNotificationLocationPreference(IntPtr handle);
STUB(IntPtr, EOS_UI_GetNotificationLocationPreference, 0, IntPtr handle);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern KeyCombination EOS_UI_GetToggleFriendsKey(IntPtr handle, IntPtr options);
STUB(IntPtr, EOS_UI_GetToggleFriendsKey, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_UI_HideFriends(IntPtr handle, IntPtr options, IntPtr clientData, OnHideFriendsCallbackInternal completionDelegate);
STUB(void, EOS_UI_HideFriends, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern int EOS_UI_IsValidKeyCombination(IntPtr handle, KeyCombination keyCombination);
STUB(int, EOS_UI_IsValidKeyCombination, 0, IntPtr handle, IntPtr keyCombination);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_UI_RemoveNotifyDisplaySettingsUpdated(IntPtr handle, ulong id);
STUB(void, EOS_UI_RemoveNotifyDisplaySettingsUpdated, 0, IntPtr handle, ulong id);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_UI_SetDisplayPreference(IntPtr handle, IntPtr options);
STUB(Result, EOS_UI_SetDisplayPreference, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_UI_SetToggleFriendsKey(IntPtr handle, IntPtr options);
STUB(Result, EOS_UI_SetToggleFriendsKey, NotImplemented, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_UI_ShowFriends(IntPtr handle, IntPtr options, IntPtr clientData, OnShowFriendsCallbackInternal completionDelegate);
STUB(void, EOS_UI_ShowFriends, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_UserInfo_CopyExternalUserInfoByAccountId(IntPtr handle, IntPtr options, ref IntPtr outExternalUserInfo);
STUB(Result, EOS_UserInfo_CopyExternalUserInfoByAccountId, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outExternalUserInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_UserInfo_CopyExternalUserInfoByAccountType(IntPtr handle, IntPtr options, ref IntPtr outExternalUserInfo);
STUB(Result, EOS_UserInfo_CopyExternalUserInfoByAccountType, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outExternalUserInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_UserInfo_CopyExternalUserInfoByIndex(IntPtr handle, IntPtr options, ref IntPtr outExternalUserInfo);
STUB(Result, EOS_UserInfo_CopyExternalUserInfoByIndex, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outExternalUserInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern Result EOS_UserInfo_CopyUserInfo(IntPtr handle, IntPtr options, ref IntPtr outUserInfo);
STUB(Result, EOS_UserInfo_CopyUserInfo, NotImplemented, IntPtr handle, IntPtr options, ref IntPtr outUserInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_UserInfo_ExternalUserInfo_Release(IntPtr externalUserInfo);
STUB(void, EOS_UserInfo_ExternalUserInfo_Release, 0, IntPtr externalUserInfo);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern uint EOS_UserInfo_GetExternalUserInfoCount(IntPtr handle, IntPtr options);
STUB(uint, EOS_UserInfo_GetExternalUserInfoCount, 0, IntPtr handle, IntPtr options);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_UserInfo_QueryUserInfo(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryUserInfoCallbackInternal completionDelegate);
STUB(void, EOS_UserInfo_QueryUserInfo, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_UserInfo_QueryUserInfoByDisplayName(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryUserInfoByDisplayNameCallbackInternal completionDelegate);
STUB(void, EOS_UserInfo_QueryUserInfoByDisplayName, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_UserInfo_QueryUserInfoByExternalAccount(IntPtr handle, IntPtr options, IntPtr clientData, OnQueryUserInfoByExternalAccountCallbackInternal completionDelegate);
STUB(void, EOS_UserInfo_QueryUserInfoByExternalAccount, 0, IntPtr handle, IntPtr options, IntPtr clientData, IntPtr completionDelegate);

// [DllImport("EOSSDK-Win64-Shipping.dll")]
// internal static extern void EOS_UserInfo_Release(IntPtr userInfo);
STUB(void, EOS_UserInfo_Release, 0, IntPtr userInfo);
