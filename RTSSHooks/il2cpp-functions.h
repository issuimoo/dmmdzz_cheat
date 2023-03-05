
//PlayerController
DO_API(0x3763D0, void, PlayerController_Awake, (PlayerController* _this));
DO_API(0x384380, void, PlayerController_OnDestroy, (PlayerController* _this));
DO_API(0x390C60, int, PlayerController_get_CurCoin, (PlayerController* _this));
DO_API(0x38A510, void, PlayerController_SetPlayerPos, (PlayerController* _this, Vector3 Pos));
DO_API(0x37C190, bool, PlayerController_InSameTeam, (PlayerController* _this, PlayerController* other));
DO_API(0x388AC0, void, PlayerController_RpcSubCoin, (PlayerController* _this, int coin, int reason, int cardId, unsigned int parameters));
DO_API(0x38BB40, void, PlayerController_SubCoin, (PlayerController* _this, int coin, int reason, int cardId));
DO_API(0x37DFE0, void, PlayerController_LocalAddMaxLife, (PlayerController* _this, float value));
DO_API(0x383470, void, PlayerController_LocalResetMaxLife, (PlayerController* _this));
DO_API(0x37DDB0, void, PlayerController_LocalAddMaxLifeAndDefaultMaxLife, (PlayerController* _this, float value));
DO_API(0x38A770, void, PlayerController_SetSpeed, (PlayerController* _this, Vector3 v));

//AntiCheatingSystem
DO_API(0x369A20, void, AntiCheatingSystem_SendReport, (AntiCheatingSystem* _this, APP_String* userID, AntiCheatingResult result));
DO_API(0x369680, void, AntiCheatingSystem_Quit, (AntiCheatingSystem* _this));
DO_API(0x3695B0, void, AntiCheatingSystem_QuitApplication, (AntiCheatingSystem* _this));
DO_API(0x352120, void, AntiCheatingSystem_AddGhost, (AntiCheatingSystem* _this, AntiCheatingGhost g, unsigned int t, APP_String* userId));

//InGameFogOfWar
DO_API(0x84A160, bool, InGameFogOfWar_get_ShowAllRoleView, (InGameFogOfWar* _this));
DO_API(0x849ED0, bool, InGameFogOfWar_get_DisableFogVisual, (InGameFogOfWar* _this));

//PlayerControllerRpcProxy
DO_API(0x921880, void, PlayerControllerRpcProxy_LocalSubCoin, (PlayerControllerRpcProxy* _this, int coin, int reason, int param));

//BipedalDragonShapeController
DO_API(0x93E0D0, bool, BipedalDragonShapeController_get_DisableFireButton, (BipedalDragonShapeController* _this));
DO_API(0x93E120, bool, BipedalDragonShapeController_get_DisableJumpButton, (BipedalDragonShapeController* _this));
DO_API(0x93E170, bool, BipedalDragonShapeController_get_MoveTargetForward, (BipedalDragonShapeController* _this));
DO_API(0x93E040, bool, BipedalDragonShapeController_get_ControllerMove, (BipedalDragonShapeController* _this));

//ACEInstance
DO_API(0xFA6270, ACEInstance_*, ACEInstance_get_Instance, (ACEInstance_* _this));
DO_API(0xFA45D0, ACEInstance_*, ACEInstance_InitInstance, (ACEInstance_* _this));
DO_API(0xFA4720, void, ACEInstance_InitSwitches, (ACEInstance_* _this));
DO_API(0xFA61F0, TssAntibot*, ACEInstance_get_Antibot, (ACEInstance_* _this));
DO_API(0xFA48C0, void, ACEInstance_Init, (ACEInstance_* _this));
DO_API(0xFA5960, void, ACEInstance_SetUserInfo, (ACEInstance_* _this, std::int32_t roleId, std::int32_t platId));
DO_API(0xFA58D0, void, ACEInstance_SetAntiServerResponse, (ACEInstance_* _this, HttpResponseAceServer* response));
DO_API(0xFA4B00, void, ACEInstance_Login, (ACEInstance_* _this, APP_String* openId));
DO_API(0xFA4D10, void, ACEInstance_OnExitProcess, (ACEInstance_* _this));
DO_API(0xFA5BE0, void, ACEInstance_Tick, (ACEInstance_* _this));
DO_API(0xFA5520, void, ACEInstance_RequestAntiServer, (ACEInstance_* _this, double currTimeSec));
DO_API(0xFA4340, void, ACEInstance_ConnectAntiServer, (ACEInstance_* _this, double currTimeSec));
DO_API(0xFA5330, void, ACEInstance_RecvAntiData, (ACEInstance_* _this));
DO_API(0xFA4E00, void, ACEInstance_OnRecvAntiData, (ACEInstance_* _this, char* data));
DO_API(0xFA56E0, void, ACEInstance_SendAntiData, (ACEInstance_* _this));
DO_API(0xFA62F0, void, ACEInstance_get_IsQuitting, (ACEInstance_* _this));
DO_API(0xFA50A0, void, ACEInstance_QuitWithMessageStatic, (ACEInstance_* _this, APP_String* text));
DO_API(0xFA4F80, void, ACEInstance_QuitWithError, (ACEInstance_* _this, int mainErr, int subErr));
DO_API(0xFA6050, void, ACEInstance_TrySendShowMessageAndQuitEvent, (ACEInstance_* _this, APP_String* text));
DO_API(0xFA59E0, void, ACEInstance_ShowMessageAndQuit, (ACEInstance_* _this, APP_String* text));
DO_API(0xFA5450, void, ACEInstance_ReportEvent, (ACEInstance_* _this, int mainErr, int subErr));

//InGameStore
DO_API(0xE78520, void, InGameStore_Awake, (InGameStore* _this));
DO_API(0xE82B50, void, InGameStore_OnDestroy, (InGameStore* _this));

//UsableObject
DO_API(0xAB8020, void, UsableObject_Awake, (UsableObject* _this));
DO_API(0xABAAC0, void, UsableObject_OnDestroy, (UsableObject* _this));

//AdrenalineObject
DO_API(0x6D92C0, Vector3, AdrenalineObject_GetPlayerPos, (AdrenalineObject* _this, PlayerController* Player_this));

//AutoRecoverable
DO_API(0x2CBADF0, void, AutoRecoverable_AutoRecoverBlood, (AutoRecoverable* _this));
DO_API(0x2CBB2A0, void, AutoRecoverable_Start, (AutoRecoverable* _this));