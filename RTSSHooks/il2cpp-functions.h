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

//PlayerControllerRpcProxy
DO_APP_FUNC(void, PlayerControllerRpcProxy_LocalSubCoin, (PlayerControllerRpcProxy* _this, int coin, int reason, int param));

//BipedalDragonShapeController
DO_APP_FUNC(bool, BipedalDragonShapeController_get_DisableFireButton, (BipedalDragonShapeController* _this));
DO_APP_FUNC(bool, BipedalDragonShapeController_get_DisableJumpButton, (BipedalDragonShapeController* _this));
DO_APP_FUNC(bool, BipedalDragonShapeController_get_MoveTargetForward, (BipedalDragonShapeController* _this));
DO_APP_FUNC(bool, BipedalDragonShapeController_get_ControllerMove, (BipedalDragonShapeController* _this));



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