#pragma once

#include <cstdint>

#pragma pack(4)

namespace app
{
	struct __declspec(align(4)) Vector2
	{
		float x;
		float y;
	};

	struct __declspec(align(4)) Vector3
	{
		float x;
		float y;
		float z;
	};

	struct __declspec(align(4)) Matrix4x4
	{
		float _00;
		float _01;
		float _02;
		float _03;
		float _10;
		float _11;
		float _12;
		float _13;
		float _20;
		float _21;
		float _22;
		float _23;
		float _30;
		float _31;
		float _32;
		float _33;
	};

	struct __declspec(align(4)) GameObject 
	{

	};

	struct __declspec(align(4)) HttpResponseAceServer
	{
		char _space[16];
		struct System_String_o* ip;
		int32_t port;
		struct System_String_o* account;
		struct System_String_o* authKey;
		uint32_t authExpire;
	};

	struct __declspec(align(4)) WrappedTssAntibot {
		intptr_t antibot;
		struct AceSdk_TssAntibot_DeprecatedRoutine_o* deprecated;
		struct AceSdk_TssAntibot_GetReportAntiDataRoutine_o* get_report_anti_data;
		struct AceSdk_TssAntibot_DelReportAntiDataRoutine_o* del_report_anti_data;
		struct AceSdk_TssAntibot_OnRecvAntiDataRoutine_o* on_recv_anti_data;
		struct AceSdk_TssAntibot_DeprecatedRoutine2_o* deprecated2;
	};

	struct __declspec(align(4)) TssAntibot {
		char _space[8];
		struct WrappedTssAntibot antibot_;
		intptr_t data_buf_;
	};

	struct __declspec(align(4)) ACEInstance 
	{
		char _space[8];
		bool m_KickWithGameMsgBox;
		struct AceSdk_AceClient_o* m_AceClient;
		struct AceSdk_TssAntibot_o* m_TssAntibot;
		uint32_t m_RoleId;
		uint32_t m_PlatId;
		bool m_LoginOK;
		struct GameMessages_HttpResponseAceServer_o* m_AntiServerResponse;
		double m_LastRequestTimeSec;
		struct LightNet3_LightMessageClient_LightTcpStream__o* m_Connection;
		bool m_Connected;
		double m_LastDisconnectedTimeSec;
		double m_LastTryConnectTime;
		double m_QuitStartTimeSec;
	};

	struct __declspec(align(4)) APP_ColorRGBA {
		float r;
		float g;
		float b;
		float a;
	};

	struct __declspec(align(4)) NativeArray {
		void* m_Buffer;
		int32_t m_Length;
		int32_t m_AllocatorLabel;
	};

	struct __declspec(align(4)) APP_String {
		char _space[8];
		int32_t m_stringLength;
		uint16_t m_firstChar;
	};

	struct __declspec(align(4)) NativeListData {
		void* buffer;
		int32_t length;
		int32_t capacity;
	};

	struct __declspec(align(4)) NativeList {
		struct NativeListData* m_ListData;
		int32_t m_Allocator;
	};

	struct __declspec(align(4)) JobHandle {
		intptr_t jobGroup;
		int32_t version;
	};

	struct __declspec(align(4)) LayerMask {
		int32_t m_Mask;
	};

	struct __declspec(align(4)) Camera {
		struct Camera_CameraCallback* onPreCull;
		struct Camera_CameraCallback* onPreRender;
		struct Camera_CameraCallback* onPostRender;
	};

	struct __declspec(align(4)) APP_Text {
		char _space[128];
		struct UnityEngine_UI_FontData_o* m_FontData;
		struct APP_String* m_Text;
		struct UnityEngine_TextGenerator_o* m_TextCache;
		struct UnityEngine_TextGenerator_o* m_TextCacheForLayout;
		bool m_DisableFontTextureRebuiltCallback;
		struct UnityEngine_UIVertex_array* m_TempVerts;
	};

	struct __declspec(align(4)) BattleProperties {
		char _space[8];
		float life;
		float maxLife;
		float radius;
		struct UnityEngine_GameObject_o* critialEffect;
		struct UnityEngine_GameObject_o* damageTextEffect;
		struct UnityEngine_GameObject_o* recoverTextEffect;
		float extraMaxLifeLimit;
		float qteCoinWeight;
		float vaultOrDoorCoinWeight;
		float reviveCoinWeight;
		float supplementBoxCoinWight;
		float rebornSpeed;
		float ingameStoreColdDownSpeedUp;
	};

	struct __declspec(align(4)) PlayerController {
		char _space[104];
		struct LightUtility_MeshRendererGroup_o* m_MeshRendererGroup;
		struct UnityEngine_Events_UnityAction_string__int__int__int__o* OnCoinChanged;
		struct UnityEngine_Events_UnityAction_string__o* OnStoreCardChanged;
		struct PlayerController_MovementProperties_o* m_MovementProperties;
		struct PlayerController_ViewProperties_o* m_ViewProperties;
		struct BattleProperties* m_BattleProperties;
		struct PlayerController_TalentProperties_o* m_TalentProperties;
		struct APP_Text* m_NameText;
		struct CharacterBloodBar_o* m_BloodBar;
		struct LayerMask m_GroundLayer;
		struct PhotonView_o* m_PhotonViewForTransform;
		struct UnityEngine_GameObject_o* m_UI;
		struct InGameWidget_o* m_Widget;
		struct UnityEngine_GameObject_o* m_Body;
		struct UnityEngine_CanvasGroup_o* m_TextDialog;
		struct UnityEngine_GameObject_o* m_VoiceIcon;
		struct UnityEngine_GameObject_o* m_AddMaxLifeEffect;
		struct LightUI_UIProgressBar_o* m_VehicleBar;
		struct UnityEngine_CanvasGroup_o* m_HideFadeUI;
		struct UnityEngine_Transform_o* CastHookFinger;
		bool m_IsPuppet;
		bool BTMoveFlag;
		struct LightUI_UIStateImage_o* m_Num;
		struct LightUI_UIStateItem_o* m_LackOfCoin;
		struct UnityEngine_GameObject_o* m_InAirPosPointer;
		struct UnityEngine_Events_UnityAction_PlayerController__o* OnFinalDeadWithPlayer;
		struct UnityEngine_Events_UnityAction_o* OnFinalDead;
		struct UnityEngine_AudioSource_o* m_InGrassAS;
		struct Vector3 m_PhysicsSpeed;
		struct Vector3 m_AppendSpeed;
		struct CharacterBloodBar_o* m_ArmorBar;
		struct UnityEngine_CanvasGroup_o* m_ArmorCanvas;
		struct UnityEngine_CanvasGroup_o* m_ArmorCanvasIncludeArmorIcon;
		struct Vector3 m_TargetDirection;
		struct Vector3 m_TowardsDirection;
		bool m_Hiding;
		bool m_InAir;
		bool m_ReverseMove;
		float m_Visibility;
		float m_LastJumpTime;
		float m_RebornTime;
		bool m_LastVisible;
		bool m_InWater;
		bool m_ForceHideUI;
		bool m_Negtive;
		struct SkinPartController_o* m_SkinPartController;
		struct ActorPrefabCtrl_o* _m_ActorPrefabCtrl_k__BackingField;
		struct GamePhotonTransformView_o* m_PhotonTransformView;
		struct LightUtility_PhysicsVelocityCaculator_o* m_VelocityCaculator;
		struct BuffManager_o* m_BuffManager;
		struct CanvasGroupProxy_o* m_canvasGroupProxy;
		struct LightUtility_SpriteRendererGroup_o* m_SpriteRendererGroup;
		struct AIController_o* m_AIController;
		struct Teleporter_o* m_Teleporter;
		struct ShapeShifter_o* m_ShapeShifter;
		struct TalentManager_o* m_TalentManager;
		struct SkillManager_o* m_SkillManager;
		struct IngameEmotionController_o* m_IngameEmotionController;
		struct DamagableTarget_o* m_DamagableTarget;
		struct PhotonView_o* m_OnVehicle;
		struct VehicleJoint_o* m_VehicleJoint;
		struct PhotonVoiceSpeaker_o* m_PhotonVoiceSpeaker;
		struct NetworkCullingHandler_o* m_CullingHandler;
		struct PropcardKnapsack_o* m_PropcardKnapsack;
		struct LightUtility_LiteComponentOwner_o* m_LiteComponentOwner;
		struct PlayerForceMove_o* m_PlayerForceMove;
		struct PlayerControllerRpcProxy_o* m_PlayerControllerRpcProxy;
		struct PlaceableCreater_o* m_PlaceableCreater;
		struct SelectableCreater_o* m_SelectableCreater;
		struct System_Collections_Generic_List_int__o* m_CarriedTraps;
		struct System_Collections_Generic_List_int__o* m_CarriedPortals;
		struct System_Collections_Generic_Dictionary_int__List_int___o* m_CarriedPropIDs;
		struct System_Collections_Generic_List_int__o* m_CarriedSoltRankList;
		struct System_Collections_Generic_List_PlayerController_DamageInfo__o* m_DamageHistory;
		bool m_TransformOwnershipLock;
		float m_SpeedForAnimator;
		float m_DefaultRotationFactor;
		float m_DefaultFogViewDistance;
		float m_LastDamageTime;
		float m_LastRequestOwnershipTime;
		int32_t m_DieCount;
		float m_DefaultMaxLife;
		bool m_IsLocalPlayer;
		bool m_IsSpeaking;
		bool m_IsDevouring;
		bool m_ControllingPosition;
		uint8_t m_PerformaneceQuality;
		int32_t m_CarryPropLimit;
		bool m_TransferenceCD;
		bool m_ImprovedShield;
		float m_DefaultMass;
		float m_BodyScale;
		float m_LastCheckRepairTime;
		float m_LastReviveTime;
		struct UsableObject_o* m_UsingObject;
		bool m_AutoJumping;
		bool m_SkateboardJumping;
		struct HookObject_o* m_HookObject;
		struct HookJoint_o* m_HookJoint;
		struct System_String_o* m_lastHelpReviveUserID;
		struct System_String_o* m_lastKillerUserID;
		float m_lastKillTime;
		float m_LastDyingTime;
		bool m_UIActive;
		bool m_AnimatorEnabled;
		struct LightUtility_SmartUpdaterDeltaTime_o* m_LastUpdateUITime;
		struct LightUtility_SmartUpdaterLOD_o* m_LastUpdateVisibility;
		struct LightUtility_Delegates_ObjectCallback_Collision__o* onCollisionEnter;
		struct LightUtility_Delegates_ObjectCallback_Collision__o* onCollisionStay;
		struct PortalAdapter_o* m_PortalAdapter;
		struct UnityEngine_UI_Text_o* m_NumText;
		struct DG_Tweening_Tween_o* m_CanvasTween;
		struct DG_Tweening_Tween_o* m_SpriteRendererTween;
		struct DG_Tweening_Tween_o* m_MeshRendererTween;
		struct UnityChan_SpringManager_array* m_SpringManagers;
		float m_DyingTime;
		bool m_IsInitializeUICalled;
		bool m_AiEnable;
		bool m_CloseSpringUpdate;
		float m_LimitSpeed;
		float m_NewLimitSpeed;
		bool _Jetting_k__BackingField;
		float _LastTrapDamageTime_k__BackingField;
		struct System_Int32_array* _Cards_k__BackingField;
		struct System_Int32_array* _CardLevels_k__BackingField;
		struct System_Int32_array* _CardSkins_k__BackingField;
		struct System_Int32_array* _CardStyles_k__BackingField;
		struct System_Int32_array* _RelatedCardSkins_k__BackingField;
		struct System_Int32_array* _CardSkinOrStyleIDs_k__BackingField;
		struct System_Int32_array* _IngameEmotion_k__BackingField;
		float _ReinforceLife_k__BackingField;
		float m_InteractionDistance;
		struct System_Collections_Generic_Dictionary_SkinResourceKey__string__o* _SkinRelatedResources_k__BackingField;
		float m_showTime;
		float m_ScannedTime;
		float m_ShowBodyTime;
		bool m_CanNotUseStore;
		bool m_CanNotShapeShift;
		float _CustomCoinRatio_k__BackingField;
		bool _Flying_k__BackingField;
		bool _Leaping_k__BackingField;
		bool _InStealth_k__BackingField;
		float m_StealthVolume;
		float m_StealthTargetWarning;
		float _StealthAlpha_k__BackingField;
		float _AlphaDuration_k__BackingField;
		bool _IsFoxStealth_k__BackingField;
		bool _DisableControlling_k__BackingField;
		int32_t _LocalNum_k__BackingField;
		struct PlayerController_o* _HostPlayer_k__BackingField;
		struct PuppetController_o* _PuppetPlayer_k__BackingField;
		struct KagebunsinController_o* _KagebunsinPlayer_k__BackingField;
		struct KagebunsinController_o* _AdditionalKagebunsinPlayer_k__BackingField;
		struct FoxDollController_o* _FoxDollPlayer_k__BackingField;
		int32_t _RescueNum_k__BackingField;
		int32_t _BeKnockDownNum_k__BackingField;
		float _TotalDamage_k__BackingField;
		float _TotalHealing_k__BackingField;
		float _TotalSufferInjury_k__BackingField;
		int32_t m_ForceMoveStateNow;
		int32_t _CurCoin_k__BackingField;
		int32_t _KnockDownNum_k__BackingField;
		int32_t _AssistNum_k__BackingField;
		bool _AutoPathFinding_k__BackingField;
		struct System_Int32_array* m_StoreCards;
		struct System_Collections_Generic_Dictionary_int__PlaceableObject__o* m_StoreCardsObj;
		struct System_Single_array* m_CardsTriggerTime;
		struct System_Single_array* m_LastBoughtTimes;
		bool _CanBuyFree_k__BackingField;
		float _SqrFogViewDistance_k__BackingField;
		bool _Ready_k__BackingField;
		int32_t ExclusiveWeaponID;
		bool _Reborning_k__BackingField;
		float _CollisionPenetration_k__BackingField;
		struct System_Collections_Generic_List_string__o* m_IsPlayerSendingRpc;
		bool _BeConnect_k__BackingField;
		int32_t _InitBattleRoyaleCardsState_k__BackingField;
	};

	struct __declspec(align(4)) PlayerControllerRpcProxy {
		char _space[12];
		PlayerController m_PlayerController;
	};

	struct __declspec(align(4)) AutoRecoverable {
		char _space[12];
		struct GameObject* m_Effect;
		float m_FriendMinRange;
		float m_Interval;
		float m_Amount;
		float m_DisengageTime;
		struct PlayerController* m_Controller;
		float m_LastDamageTime;
	};

	struct __declspec(align(4)) DirectionalObject {
		char _space[220];
		struct UnityEngine_AnimationCurve_o* m_SpeedCurve;
		struct UnityEngine_AnimationCurve_o* m_ColliderSizeCurve;
		struct UnityEngine_GameObject_o* m_Colliders;
		struct Vector3 m_StartOffset;
		bool m_RootOffset;
		float m_StartDelay;
		float m_MinHeight;
		float m_SpeedScale;
		float m_VehicleExtraSpeed;
		float m_MinHitTime;
		float m_MinHitDistance;
		float m_Timeout;
		float m_ExplosionRadius;
		float m_FallAccelerated;
		struct DynamicAssetsModule_M_PrefabRef_o* m_HitEffectRef;
		struct UnityEngine_GameObject_o* m_HitEffect;
		struct Vector3 m_HitEffectOffset;
		struct UnityEngine_GameObject_o* m_TrailEffect;
		struct Vector3 m_TrailEffectOffset;
		bool m_IsGrounder;
		struct PlayerController* m_PlayerController;
		bool m_Launched;
		bool m_Hit;
		bool m_Falling;
		float m_GroundHeight;
		struct Vector3 m_StartDir;
		struct Vector3 m_StartPos;
		float m_StartTime;
		bool m_OnVehicle;
		float m_FallTime;
		bool m_HitEffectShowed;
		struct UnityEngine_GameObject_o* m_TrailEffectInst;
		struct PlaceableCreater_o* m_PlaceableCreater;
		bool m_Trigger;
		float m_TriggerTime;
		struct Vector3 m_AutoAimiedTargetPos;
		bool m_IsTimeOut;
		struct System_Collections_Generic_List_Vector3__o* m_CheckFallPos;
	};

	struct __declspec(align(4)) InGameFogOfWar {
		bool m_IsDoBlurOnSmallRT;
		bool m_IsDownSamplingAsBlur;
		float m_UpdateInterval;
		float m_OutputMapScale;
		float m_BlurRTScale;
		struct Vector2 m_BlurTexelScale;
		float m_fowYOffset;
		struct Material* m_BlurMaterial;
		struct Texture2D* m_MapTexture;
		int32_t m_RGFormat;
		struct RenderTexture* m_FOWMapRT_RG;
		struct RenderTexture* m_FOWBlurRT;
		struct NativeArray m_MapColorData;
		struct NativeArray m_MapDirectionsData;
		struct array* m_MapDirections;
		bool m_IsMapDirectionsDirty;
		struct NativeArray m_FogMap;
		struct NativeArray m_EnemyFogMap;
		struct array* m_FogMapCache;
		struct array* m_EnemyFogMapCache;
		struct NativeList m_ViewPositions;
		struct NativeList m_EnemyViewPositions;
		struct NativeList m_ViewHeights;
		struct NativeList m_EnemyViewHeights;
		struct NativeList m_ViewDistances;
		struct NativeList m_EnemyViewDistances;
		float m_MaxEnergyToFogIntensity;
		float m_BlendTime;
		bool m_FirstUpdated;
		int32_t m_CoreCount;
		struct TiledMap* m_Map;
		struct System_Func_Vector3__bool__o* m_IsPositionCollidableFunc;
		float m_LastUpdateFOWTime;
		struct UnityEngine_Vector3_array* m_Offsets;
		bool m_IsDisableFogOfWar;
		struct JobHandle m_UpdateJobs;
		bool m_IsRunningJobs;
		bool _ShowAllRoleView_k__BackingField;
		bool _DisableFogVisual_k__BackingField;
	};

	struct __declspec(align(4)) AntiCheatingSystem {
		char _space[16];
		float m_CheckInterval;
		float m_TimeDiffThreshold;
		float m_OverSpeedTimeThreshold;
		float m_OverSpeedFactorThreshold;
		float m_PlaceableDistanceThreshold;
		float m_CooldownTimeThreshold;
		float m_UseDistanceThreshold;
		float m_ProjectileDistance;
		float m_GrenadeDistance;
		float m_MedkitDistance;
		float m_SaberDistance;
		float m_TrapMinDamage;
		float m_SpawnProjectileDistance;
		int32_t m_SuspectCountThreshold;
		float m_MinTrapInterval;
		int32_t m_MaxSupplementBoxCount;
		float m_StartLocalTime;
		uint32_t m_StartServerTime;
		float m_CullDistance2;
		float m_LastUpdateTime;
		float m_AllThiefsShowInMiniMapDuration;
		float m_NotAllThiefsShowInMiniMapDuration;
		float m_LastUpdateTimeHalfSecond;
		float m_LastUpdateTimeTenSecond;
		struct SafeGameDictionary_string__List_AntiCheatingResult___o* PlayerReported;
		struct SafeGameDictionary_string__bool__o* PlayerNotified;
		struct SafeGameDictionary_string__float__o* PlayerOverSpeedTime;
		struct SafeGameDictionary_string__float__o* PlayerOverAnimatorSpeedTime;
		struct SafeGameDictionary_string__float__o* PlayerExpectedSpeed;
		struct SafeGameDictionary_string__AntiCheatingSystem_UsingTime__o* PlayerUsingTime;
		struct SafeGameDictionary_string__SafeGameDictionary_AntiCheatingResult__int___o* SuspectCounter;
		struct SafeGameDictionary_string__SafeGameDictionary_AntiCheatingResult__StringBuilder___o* SuspectDetails;
		struct SafeGameDictionary_AntiCheatingGhost__AntiCheatingSystem_GhostList__o* Ghosts;
		struct SafeGameDictionary_string__float__o* PlayerLastAddTrapTime;
		struct SafeGameDictionary_string__AntiCheatingSystem_EnemyShow__o* EnemyShows;
		float m_MaxLife;
		bool _AlarmOn_k__BackingField;
		struct SafeGameDictionary_int__SafeGameDictionary_int__AntiCheatingSystem_RpcCallRecord___o* m_RpcCallRecords;
	};

	struct __declspec(align(4)) AdrenalineObject {
		char _space[468];
		int32_t m_BuffID;
		float m_LifeAmount;
		int32_t m_DamageSourceType;
		int32_t _CatalogId_k__BackingField;
	};

	struct __declspec(align(4)) UsableObject {
		char _space[28];
		float m_TimeComsuption;
		float m_RpcInterval;
		float m_StandStillUseRadiusThief;
		float m_StandStillUseRadiusPolice;
		float m_StandUseHeight;
		bool m_Reusable;
		bool m_KeepProgress;
		int32_t m_UsePriority;
		struct UsableObject_QTEProperties_o* m_QTEProperties;
		int32_t m_ProgressShowMode;
		struct LightUI_UIProgressBar_o* m_ProgressBar;
		struct UnityEngine_Transform_o* m_UI;
		struct UnityEngine_GameObject_o* m_UIPrefab;
		struct UsableObject_AudioSources_o* m_AudioSources;
		struct System_Single_array* m_SpeedLimit;
		float m_MinUsingTimeLimit;
		struct UnityEngine_Renderer_array* m_OutlineTarget;
		float m_MaxOutlineWidth;
		struct UnityEngine_GameObject_o* m_UseTipsBubblePrefabs;
		struct UnityEngine_Transform_o* m_UseTipsBubbleAnchor;
		struct LightUtility_Delegates_VoidCallback_o* OnLocalUseComplete;
		struct LightUtility_Delegates_VoidCallback_o* OnPlayerMeNearBy;
		bool m_Irreversible;
		int32_t m_State;
		int64_t m_Progress;
		struct TiledBlock_o* m_TiledBlock;
		struct System_Collections_Generic_List_string__o* m_CurrentUsers;
		struct System_Collections_Generic_Dictionary_string__Coroutine__o* m_AddUsingCoroutines;
		bool m_InQTE;
		float m_LastQTETime;
		bool m_IsOutline;
		struct APP_ColorRGBA m_OutlineColor;
		float m_OutlineWidthResult;
		struct UnityEngine_Material_o* m_OutlineMat;
		struct UnityEngine_Material_array_array* m_OriginalMatsPerRendererArray;
		struct UnityEngine_Material_array_array* m_OutlineMatsPerRendererArray;
		struct UnityEngine_GameObject_o* m_UseTipsBubbleInst;
		float m_LastShowUseTipsBubbleTime;
		struct UnityEngine_Coroutine_o* m_LaterShowUseTipsBubbleCorontine;
		struct DG_Tweening_Tween_o* m_BubbleTween;
		struct UnityEngine_Animator_o* m_ProgressAnimator;
		bool m_UIActive;
		struct LightUtility_SmartUpdaterDeltaTime_o* m_LastUpdateUITime;
		bool m_AttachedToPlayer;
		struct PhotonView_o* m_MyPhotonView;
		int32_t m_UsableId;
		int32_t m_DynamicMapStreamerCellId;
		bool _ShowingUseTipsBubble_k__BackingField;
		int32_t m_UsableID;
	};

	struct __declspec(align(4)) BipedalDragonShapeController 
	{
		char _space[104];
		float m_DelayTime;
		float m_AttackReturnTime;
		bool m_IsFire;
	};

	struct __declspec(align(4)) InGameStore {
		char _space[12];
		struct LightUI_UIStateItem_o* m_Header;
		struct LightUI_UITemplateInitiator_o* m_StorePanel;
		struct InGameInteractionButton_o* m_PropButton;
		struct UnityEngine_UI_Text_o* m_CoinText;
		struct UnityEngine_Transform_o* m_CoinEffectTarget;
		struct UnityEngine_GameObject_o* m_CoinEffect;
		struct UnityEngine_GameObject_o* m_CoinHelpEffect;
		struct UnityEngine_GameObject_o* m_CoinAddEffect;
		struct UnityEngine_GameObject_o* m_CoinSubEffect;
		struct UnityEngine_Transform_o* m_CoinChangeEffectRoot;
		float m_CooldownTime;
		float m_MaxCoinDistance;
		int32_t m_ItemCount;
		struct TouchOccupy_o* m_TouchOccupy;
		struct InGameStore_Audio_o* m_Audio;
		struct Vector2 m_HeaderYScope;
		struct Vector2 m_PanelYScope;
		struct LightUI_UIDataBinderBase_array* m_InGameStore_ItemTemplates;
		struct LightUI_UIDataBinderBase_o* m_Magazine_ItemTemplates;
		struct UnityEngine_UI_Image_o* m_NextCardIcon;
		struct UnityEngine_GameObject_o* m_NextCardEffect;
		struct LightUI_UICooldownBar_o* m_NextCardCooldown;
		struct UnityEngine_GameObject_o* m_CoolDownTipsPrefab;
		bool m_CostFree;
		bool m_LastBuyFree;
		struct UnityEngine_Camera_o* m_RenderCamera;
		struct UnityEngine_RectTransform_o* m_RectTransform;
		struct LightUI_CommonDataCollection_o* m_StoreContent;
		struct System_Collections_Generic_List_int__o* m_LockIndex;
		struct System_Collections_Generic_List_GameObject__o* m_CoinChangeEffectInstances;
		int32_t m_CoinNum;
		int32_t m_FlyingCoin;
		bool m_HasNewItem;
		int32_t m_PanelState;
		struct InGameStoreInfo_o* m_BuyingItemInfo;
		int32_t m_BuyOpType;
		struct System_Action_int__o* OnBuyCard;
		struct SafeGameDictionary_int__float__o* m_LastItemBoughtTime;
		struct SafeGameDictionary_int__float__o* m_CardTriggerTime;
		float m_RemainedCooldownTime;
		int32_t m_BuyCount;
		bool m_LastDisabled;
		struct PlayerController_o* m_LastController;
		struct InGameStoreInfo_o* m_MagazineInfo;
		struct UnityEngine_CanvasGroup_o* m_lastCooldownTipsCanvasGroup;
		struct UnityEngine_UI_Text_o* m_cooldownTipsText;
		bool m_IsInitialized;
		struct System_Collections_Generic_List_int__o* TempCandidateList;
		int32_t m_ServerGold;
		bool m_IsSyncGold;
		struct System_Collections_Generic_List_int__o* TempShowCardList;
		struct System_Collections_Generic_List_float__o* TempTriggerCardList;
		struct System_Collections_Generic_List_float__o* TempBoughtTimeList;
		int32_t _BuyItemMask_k__BackingField;
		bool m_Disabled;
		bool _DisableAutoOpen_k__BackingField;
	};

	enum AntiCheatingResult
	{
		Normal = 0,
		OverReport = 1,
		OverSpeed = 2,
		WallPenatration = 3,
		PlaceTooFar = 4,
		Teleport = 5,
		Buy = 6,
		BuyMagazine = 7,
		GiveCoinSelf = 8,
		CreateBuff = 9,
		ShapeShift = 10,
		AddProp = 11,
		StartUsing = 12,
		AddUsingNotStart = 13,
		AddUsingTooFast = 14,
		AddUsingTooFar = 15,
		ApplyDamage = 16,
		ApplyDamageTooFar = 17,
		ApplyDamageEmpty = 18,
		ApplyDamageExtraInfo = 19,
		ApplyDamageRole = 20,
		SpawnProjectile = 21,
		SpawnProjectileTooFast = 22,
		SpawnProjectileMismatched = 23,
		SpawnProjectileTooMuch = 24,
		SpawnProjectileRecoilless = 25,
		SpawnProjectileBulletOver = 26,
		GiveTalent = 27,
		GiveTalentTooMuch = 28,
		NotifyQTEResult = 29,
		NotifyQTEResultTooFar = 30,
		FinalEscaped = 31,
		TimeMismatched = 32,
		OverAnimatorSpeed = 33,
		CheckDLL = 34,
		NoPullBlacklist = 35,
		TalentMismatched = 36,
		EscapeDoor = 37,
		AddMaxLife = 38,
		CardMismatched = 39,
		AddTrap = 40,
		AddSupplementBox = 41,
		ChangeCardSkin = 42,
		TalentTrigger = 43,
		OverDamage = 44,
		MiniMapOpen = 45,
		UsePropcard = 46,
		StartUsingDying = 47,
		GiveCoinTooMuch = 48,
		CheckDLLSuspicion = 49,
		AddCoin = 50,
		ModifyMemory = 51,
		SummaryTooFast = 52,
		Task = 53,
		SubCoin = 54,
		CostFree = 55,
		Kagebunsin = 56,
		Clairvoyance = 57,
		BuyNotSubCoin = 58,
		NotAddFireRound = 59,
		AddPropCard = 60,
		BuffDuration = 61,
		Title = 62,
		IngameStoreBuyDying = 63,
		DoQTETooFast = 64,
		AutoOpenDoor = 65,
		OverMaxLife = 66,
		QTENotVault = 67,
		RpcIntervalSpawnFireProjectile = 68,
		RpcIntervalAddUsingTime = 69,
		RpcIntervalCardPlace = 70,
		RequestOwnership = 71,
		SummaryIllegality = 72,
		SummaryIllegalityTime = 73,
		SummaryIllegalityEscape = 74,
		SummaryIllegalityUnlockCount = 75,
		SummaryIllegalityEscaped = 76,
		SummaryIllegalityRescue = 77,
		SummaryIllegalityDamage = 78,
		SummaryIllegalityCapture = 79,
		SummaryIllegalityKill = 80,
		PlayerForceMoveTime = 81,
		Rogue = 82,
		SynGameTime = 83,
		FinalRageComplete = 84,
		LocalFinalDead = 85
	};

	enum AntiCheatingGhost
	{
		Projectile = 0,
		Grenade = 1,
		Medkit = 2,
		Saber = 3,
		ThrownBullet = 4
	};
}
#pragma pack()