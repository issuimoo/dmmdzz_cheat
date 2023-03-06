
//PlayerController
DO_API(void, PlayerController_Awake, (PlayerController* _this));
DO_API(void, PlayerController_OnDestroy, (PlayerController* _this));
DO_API(int, PlayerController_get_CurCoin, (PlayerController* _this));
DO_API(void, PlayerController_SetPlayerPos, (PlayerController* _this, Vector3 Pos));
DO_API(bool, PlayerController_InSameTeam, (PlayerController* _this, PlayerController* other));
DO_API(void, PlayerController_RpcSubCoin, (PlayerController* _this, int coin, int reason, int cardId, unsigned int parameters));
DO_API(void, PlayerController_SubCoin, (PlayerController* _this, int coin, int reason, int cardId));
DO_API(void, PlayerController_LocalAddMaxLife, (PlayerController* _this, float value));
DO_API(void, PlayerController_LocalResetMaxLife, (PlayerController* _this));
DO_API(void, PlayerController_LocalAddMaxLifeAndDefaultMaxLife, (PlayerController* _this, float value));
DO_API(void, PlayerController_SetSpeed, (PlayerController* _this, Vector3 v));

//AntiCheatingSystem
DO_API(void, AntiCheatingSystem_SendReport, (AntiCheatingSystem* _this, APP_String* userID, AntiCheatingResult result));
DO_API(void, AntiCheatingSystem_Quit, (AntiCheatingSystem* _this));
DO_API(void, AntiCheatingSystem_QuitApplication, (AntiCheatingSystem* _this));
DO_API(void, AntiCheatingSystem_AddGhost, (AntiCheatingSystem* _this, AntiCheatingGhost g, unsigned int t, APP_String* userId));

//InGameFogOfWar
DO_API(bool, InGameFogOfWar_get_ShowAllRoleView, (InGameFogOfWar* _this));
DO_API(bool, InGameFogOfWar_get_DisableFogVisual, (InGameFogOfWar* _this));

//PlayerControllerRpcProxy
DO_API(void, PlayerControllerRpcProxy_LocalSubCoin, (PlayerControllerRpcProxy* _this, int coin, int reason, int param));

//BipedalDragonShapeController
DO_API(bool, BipedalDragonShapeController_get_DisableFireButton, (BipedalDragonShapeController* _this));
DO_API(bool, BipedalDragonShapeController_get_DisableJumpButton, (BipedalDragonShapeController* _this));
DO_API(bool, BipedalDragonShapeController_get_MoveTargetForward, (BipedalDragonShapeController* _this));
DO_API(bool, BipedalDragonShapeController_get_ControllerMove, (BipedalDragonShapeController* _this));

//InGameStore
DO_API(void, InGameStore_Awake, (InGameStore* _this));
DO_API(void, InGameStore_OnDestroy, (InGameStore* _this));

//UsableObject
DO_API(void, UsableObject_Awake, (UsableObject* _this));
DO_API(void, UsableObject_OnDestroy, (UsableObject* _this));

//AdrenalineObject
DO_API(Vector3, AdrenalineObject_GetPlayerPos, (AdrenalineObject* _this, PlayerController* Player_this));

//AutoRecoverable
DO_API(void, AutoRecoverable_AutoRecoverBlood, (AutoRecoverable* _this));
DO_API(void, AutoRecoverable_Start, (AutoRecoverable* _this));

//ACEInstance
DO_API(ACEInstance_*, ACEInstance_get_Instance, (ACEInstance_* _this));
DO_API(ACEInstance_*, ACEInstance_InitInstance, (ACEInstance_* _this));
DO_API(void, ACEInstance_InitSwitches, (ACEInstance_* _this));
DO_API(TssAntibot*, ACEInstance_get_Antibot, (ACEInstance_* _this));
DO_API(void, ACEInstance_Init, (ACEInstance_* _this));
DO_API(void, ACEInstance_SetUserInfo, (ACEInstance_* _this, std::int32_t roleId, std::int32_t platId));
DO_API(void, ACEInstance_SetAntiServerResponse, (ACEInstance_* _this, HttpResponseAceServer* response));
DO_API(void, ACEInstance_Login, (ACEInstance_* _this, APP_String* openId));
DO_API(void, ACEInstance_OnExitProcess, (ACEInstance_* _this));
DO_API(void, ACEInstance_Tick, (ACEInstance_* _this));
DO_API(void, ACEInstance_RequestAntiServer, (ACEInstance_* _this, double currTimeSec));
DO_API(void, ACEInstance_ConnectAntiServer, (ACEInstance_* _this, double currTimeSec));
DO_API(void, ACEInstance_RecvAntiData, (ACEInstance_* _this));
DO_API(void, ACEInstance_OnRecvAntiData, (ACEInstance_* _this, char* data));
DO_API(void, ACEInstance_SendAntiData, (ACEInstance_* _this));
DO_API(void, ACEInstance_get_IsQuitting, (ACEInstance_* _this));
DO_API(void, ACEInstance_QuitWithMessageStatic, (ACEInstance_* _this, APP_String* text));
DO_API(void, ACEInstance_QuitWithError, (ACEInstance_* _this, int mainErr, int subErr));
DO_API(void, ACEInstance_TrySendShowMessageAndQuitEvent, (ACEInstance_* _this, APP_String* text));
DO_API(void, ACEInstance_ShowMessageAndQuit, (ACEInstance_* _this, APP_String* text));
DO_API(void, ACEInstance_ReportEvent, (ACEInstance_* _this, int mainErr, int subErr));