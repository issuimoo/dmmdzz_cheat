static unsigned int Address_AntiCheatingSystem_SendReport = 0x2560C60;
static unsigned int Address_AntiCheatingSystem_Quit = 0x25608C0;
static unsigned int Address_AntiCheatingSystem_AddGhost = 0x2549550;

static unsigned int Address_InGameFogOfWar_get_ShowAllRoleView = 0x283FA50;
static unsigned int Address_InGameFogOfWar_get_DisableFogVisual = 0x283F7C0;

static unsigned int Address_PlayerController_Awake = 0x2516E80;
static unsigned int Address_PlayerController_OnDestroy = 0x2524E00;
static unsigned int Address_PlayerController_InSameTeam = 0x251CC40;
static unsigned int Address_PlayerController_get_CurCoin = 0x25316C0;
static unsigned int Address_PlayerController_SetPlayerPos = 0x252AF90;
static unsigned int Address_PlayerController_RpcSubCoin = 0x2529540;
static unsigned int Address_PlayerController_SubCoin = 0x252C5C0;
static unsigned int Address_PlayerController_LocalAddMaxLife = 0x251EA90;
static unsigned int Address_PlayerController_LocalResetMaxLife = 0x2523EF0;
static unsigned int Address_PlayerController_LocalAddMaxLifeAndDefaultMaxLife = 0x251E860;
static unsigned int Address_PlayerController_SetSpeed = 0x252B1F0;

static unsigned int Address_InGameStore_Awake = 0x2B4BC50;
static unsigned int Address_InGameStore_OnDestroy = 0x2B562A0;

static unsigned int Address_PlayerControllerRpcProxy_LocalSubCoin = 0x2883660;

static unsigned int Address_BipedalDragonShapeController_get_DisableFireButton = 0x289FEB0;
static unsigned int Address_BipedalDragonShapeController_get_DisableJumpButton = 0x289FF00;
static unsigned int Address_BipedalDragonShapeController_get_MoveTargetForward = 0x289FF50;
static unsigned int Address_BipedalDragonShapeController_get_ControllerMove = 0x289FE20;

static unsigned int Address_UsableObject_Awake = 0x29C3AC0;
static unsigned int Address_UsableObject_OnDestroy = 0x29C6570;

static unsigned int Address_AdrenalineObject_GetPlayerPos = 0x2737140;

static unsigned int Address_AutoRecoverable_AutoRecoverBlood = 0x2956F10;
static unsigned int Address_AutoRecoverable_Start = 0x29573C0;

//ACEInstance
static unsigned int Address_ACEInstance_get_Instance = 0x2BB2830;
static unsigned int Address_ACEInstance_InitInstance = 0x2BB0B80;
static unsigned int Address_ACEInstance_InitSwitches = 0x2BB0CD0;
static unsigned int Address_ACEInstance_get_Antibot = 0x2BB27B0;
static unsigned int Address_ACEInstance_Init = 0x2BB0E80;
static unsigned int Address_ACEInstance_SetUserInfo = 0x2BB1F20;
static unsigned int Address_ACEInstance_SetAntiServerResponse = 0x2BB1E90;
static unsigned int Address_ACEInstance_Login = 0x2BB10C0;
static unsigned int Address_ACEInstance_OnExitProcess = 0x2BB12D0;
static unsigned int Address_ACEInstance_Tick = 0x2BB21A0;
static unsigned int Address_ACEInstance_RequestAntiServer = 0x2BB1AE0;
static unsigned int Address_ACEInstance_ConnectAntiServer = 0x2BB08F0;
static unsigned int Address_ACEInstance_RecvAntiData = 0x2BB18F0;
static unsigned int Address_ACEInstance_OnRecvAntiData = 0x2BB13C0;
static unsigned int Address_ACEInstance_SendAntiData = 0x2BB1CA0;
static unsigned int Address_ACEInstance_get_IsQuitting = 0x2BB28B0;
static unsigned int Address_ACEInstance_QuitWithMessageStatic = 0x2BB1660;
static unsigned int Address_ACEInstance_QuitWithError = 0x2BB1540;
static unsigned int Address_ACEInstance_TrySendShowMessageAndQuitEvent = 0x2BB2610;
static unsigned int Address_ACEInstance_ShowMessageAndQuit = 0x2BB1FA0;
static unsigned int Address_ACEInstance_ReportEvent = 0x2BB1A10;