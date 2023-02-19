#pragma once
using namespace app;

//AntiCheatingSystem
DO_APP_FUNC(void, AntiCheatingSystem_SendReport, (AntiCheatingSystem* _this, APP_String* userID, AntiCheatingResult result));
DO_APP_FUNC(void, AntiCheatingSystem_Quit, (AntiCheatingSystem* _this));
DO_APP_FUNC(void, AntiCheatingSystem_AddGhost, (AntiCheatingSystem* _this, AntiCheatingGhost g, unsigned int t, APP_String* userId));

//InGameFogOfWar
DO_APP_FUNC(bool, InGameFogOfWar_get_ShowAllRoleView, (InGameFogOfWar* _this));
DO_APP_FUNC(bool, InGameFogOfWar_get_DisableFogVisual, (InGameFogOfWar* _this));

//PlayerController
DO_APP_FUNC(void, PlayerController_Awake, (PlayerController* _this));
DO_APP_FUNC(void, PlayerController_OnDestroy, (PlayerController* _this));
DO_APP_FUNC(int, PlayerController_get_CurCoin, (PlayerController* _this));
DO_APP_FUNC(void, PlayerController_SetPlayerPos, (PlayerController* _this,Vector3 Pos));
DO_APP_FUNC(bool, PlayerController_InSameTeam, (PlayerController* _this, PlayerController* other));
DO_APP_FUNC(void, PlayerController_RpcSubCoin, (PlayerController* _this, int coin, int reason, int cardId, unsigned int parameters));
DO_APP_FUNC(void, PlayerController_SubCoin, (PlayerController* _this, int coin, int reason, int cardId));
DO_APP_FUNC(void, PlayerController_LocalAddMaxLife, (PlayerController* _this, float value));
DO_APP_FUNC(void, PlayerController_LocalResetMaxLife, (PlayerController* _this));
DO_APP_FUNC(void, PlayerController_LocalAddMaxLifeAndDefaultMaxLife, (PlayerController* _this, float value));
DO_APP_FUNC(void, PlayerController_SetSpeed, (PlayerController* _this, Vector3 v));

//PlayerControllerRpcProxy
DO_APP_FUNC(void, PlayerControllerRpcProxy_LocalSubCoin, (PlayerControllerRpcProxy* _this, int coin, int reason, int param));

//BipedalDragonShapeController
DO_APP_FUNC(bool, BipedalDragonShapeController_get_DisableFireButton, (BipedalDragonShapeController* _this));
DO_APP_FUNC(bool, BipedalDragonShapeController_get_DisableJumpButton, (BipedalDragonShapeController* _this));
DO_APP_FUNC(bool, BipedalDragonShapeController_get_MoveTargetForward, (BipedalDragonShapeController* _this));
DO_APP_FUNC(bool, BipedalDragonShapeController_get_ControllerMove, (BipedalDragonShapeController* _this));

//ACEInstance
DO_APP_FUNC(ACEInstance*, ACEInstance_get_Instance, (ACEInstance* _this));
DO_APP_FUNC(ACEInstance*, ACEInstance_InitInstance, (ACEInstance* _this));
DO_APP_FUNC(void, ACEInstance_InitSwitches, (ACEInstance* _this));
DO_APP_FUNC(TssAntibot*, ACEInstance_get_Antibot, (ACEInstance* _this));
DO_APP_FUNC(void, ACEInstance_Init, (ACEInstance* _this));
DO_APP_FUNC(void, ACEInstance_SetUserInfo, (ACEInstance* _this, std::int32_t roleId, std::int32_t platId));
DO_APP_FUNC(void, ACEInstance_SetAntiServerResponse, (ACEInstance* _this, HttpResponseAceServer* response));
DO_APP_FUNC(void, ACEInstance_Login, (ACEInstance* _this, APP_String* openId));
DO_APP_FUNC(void, ACEInstance_OnExitProcess, (ACEInstance* _this));
DO_APP_FUNC(void, ACEInstance_Tick, (ACEInstance* _this));
DO_APP_FUNC(void, ACEInstance_RequestAntiServer, (ACEInstance* _this, double currTimeSec));
DO_APP_FUNC(void, ACEInstance_ConnectAntiServer, (ACEInstance* _this, double currTimeSec));
DO_APP_FUNC(void, ACEInstance_RecvAntiData, (ACEInstance* _this));
DO_APP_FUNC(void, ACEInstance_OnRecvAntiData, (ACEInstance* _this, char* data));
DO_APP_FUNC(void, ACEInstance_SendAntiData, (ACEInstance* _this));
DO_APP_FUNC(void, ACEInstance_get_IsQuitting, (ACEInstance* _this));
DO_APP_FUNC(void, ACEInstance_QuitWithMessageStatic, (ACEInstance* _this, APP_String* text));
DO_APP_FUNC(void, ACEInstance_QuitWithError, (ACEInstance* _this, int mainErr, int subErr));
DO_APP_FUNC(void, ACEInstance_TrySendShowMessageAndQuitEvent, (ACEInstance* _this, APP_String* text));
DO_APP_FUNC(void, ACEInstance_ShowMessageAndQuit, (ACEInstance* _this, APP_String* text));
DO_APP_FUNC(void, ACEInstance_ReportEvent, (ACEInstance* _this, int mainErr, int subErr));

//InGameStore
DO_APP_FUNC(void, InGameStore_Awake, (InGameStore* _this));
DO_APP_FUNC(void, InGameStore_OnDestroy, (InGameStore* _this));

//UsableObject
DO_APP_FUNC(void, UsableObject_Awake, (UsableObject* _this));
DO_APP_FUNC(void, UsableObject_OnDestroy, (UsableObject* _this));

//AdrenalineObject
DO_APP_FUNC(Vector3, AdrenalineObject_GetPlayerPos, (AdrenalineObject* _this, PlayerController* Player_this));

//AutoRecoverable
DO_APP_FUNC(void, AutoRecoverable_AutoRecoverBlood, (AutoRecoverable* _this));
DO_APP_FUNC(void, AutoRecoverable_Start, (AutoRecoverable* _this));