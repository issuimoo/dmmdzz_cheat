#include "ACEInstance.hpp"

namespace cheat::feature
{

	bool ExAAC = true;

	static app::ACEInstance* ACEInstance_get_Instance_Hook(app::ACEInstance* _this);
	static app::ACEInstance* ACEInstance_InitInstance_Hook(app::ACEInstance* _this);
	static void ACEInstance_InitSwitches_Hook(app::ACEInstance* _this);
	static app::TssAntibot* ACEInstance_get_Antibot_Hook(app::ACEInstance* _this);
	static void ACEInstance_Init_Hook(app::ACEInstance* _this);
	static void ACEInstance_SetUserInfo_Hook(app::ACEInstance* _this, std::int32_t roleId, std::int32_t platId);
	static void ACEInstance_SetAntiServerResponse_Hook(app::ACEInstance* _this, HttpResponseAceServer* response);
	static void ACEInstance_Login_Hook(app::ACEInstance* _this, APP_String* openId);
	static void ACEInstance_OnExitProcess_Hook(app::ACEInstance* _this);
	static void ACEInstance_Tick_Hook(app::ACEInstance* _this);
	static void ACEInstance_RequestAntiServer_Hook(app::ACEInstance* _this, double currTimeSec);
	static void ACEInstance_ConnectAntiServer_Hook(app::ACEInstance* _this, double currTimeSec);
	static void ACEInstance_RecvAntiData_Hook(app::ACEInstance* _this);
	static void ACEInstance_OnRecvAntiData_Hook(app::ACEInstance* _this, char* data);
	static void ACEInstance_SendAntiData_Hook(app::ACEInstance* _this);
	static void ACEInstance_get_IsQuitting_Hook(app::ACEInstance* _this);
	static void ACEInstance_QuitWithMessageStatic_Hook(app::ACEInstance* _this, APP_String* text);
	static void ACEInstance_QuitWithError_Hook(app::ACEInstance* _this, int mainErr, int subErr);
	static void ACEInstance_TrySendShowMessageAndQuitEvent_Hook(app::ACEInstance* _this, APP_String* text);
	static void ACEInstance_ShowMessageAndQuit_Hook(app::ACEInstance* _this, APP_String* text);
	static void ACEInstance_ReportEvent_Hook(app::ACEInstance* _this, int mainErr, int subErr);

	ACEInstance::ACEInstance() : Feature()
	{
		app::ACEInstance_get_Instance = (app::ACEInstance*(*)(app::ACEInstance*))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_get_Instance);
		app::ACEInstance_InitInstance = (app::ACEInstance*(*)(app::ACEInstance*))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_InitInstance);
		app::ACEInstance_InitSwitches = (void(*)(app::ACEInstance*))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_InitSwitches);
		app::ACEInstance_get_Antibot = (app::TssAntibot*(*)(app::ACEInstance*))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_get_Antibot);
		app::ACEInstance_Init = (void(*)(app::ACEInstance*))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_Init);
		app::ACEInstance_SetUserInfo = (void(*)(app::ACEInstance*,std::int32_t, std::int32_t))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_SetUserInfo);
		app::ACEInstance_SetAntiServerResponse = (void(*)(app::ACEInstance*,HttpResponseAceServer*))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_SetAntiServerResponse);
		app::ACEInstance_Login = (void(*)(app::ACEInstance*, APP_String*))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_Login);
		app::ACEInstance_OnExitProcess = (void(*)(app::ACEInstance*))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_OnExitProcess);
		app::ACEInstance_Tick = (void(*)(app::ACEInstance*))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_Tick);
		app::ACEInstance_RequestAntiServer = (void(*)(app::ACEInstance*, double))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_RequestAntiServer);
		app::ACEInstance_ConnectAntiServer = (void(*)(app::ACEInstance*, double))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_ConnectAntiServer);
		app::ACEInstance_RecvAntiData = (void(*)(app::ACEInstance*))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_RecvAntiData);
		app::ACEInstance_OnRecvAntiData = (void(*)(app::ACEInstance*, char*))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_OnRecvAntiData);
		app::ACEInstance_SendAntiData = (void(*)(app::ACEInstance*))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_SendAntiData);
		app::ACEInstance_get_IsQuitting = (void(*)(app::ACEInstance*))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_get_IsQuitting);
		app::ACEInstance_QuitWithMessageStatic = (void(*)(app::ACEInstance*, APP_String*))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_QuitWithMessageStatic);
		app::ACEInstance_QuitWithError = (void(*)(app::ACEInstance*,int, int))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_QuitWithError);
		app::ACEInstance_TrySendShowMessageAndQuitEvent = (void(*)(app::ACEInstance*, APP_String*))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_TrySendShowMessageAndQuitEvent);
		app::ACEInstance_ShowMessageAndQuit = (void(*)(app::ACEInstance*, APP_String*))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_ShowMessageAndQuit);
		app::ACEInstance_ReportEvent = (void(*)(app::ACEInstance*,int, int))(((unsigned int)pch::GameAssembly) + Address_ACEInstance_ReportEvent);

		HookManager::install(app::ACEInstance_get_Instance, ACEInstance_get_Instance_Hook);
		HookManager::install(app::ACEInstance_InitInstance, ACEInstance_InitInstance_Hook);
		HookManager::install(app::ACEInstance_InitSwitches, ACEInstance_InitSwitches_Hook);
		HookManager::install(app::ACEInstance_get_Antibot, ACEInstance_get_Antibot_Hook);
		HookManager::install(app::ACEInstance_Init, ACEInstance_Init_Hook);
		HookManager::install(app::ACEInstance_SetUserInfo, ACEInstance_SetUserInfo_Hook);
		HookManager::install(app::ACEInstance_SetAntiServerResponse, ACEInstance_SetAntiServerResponse_Hook);
		HookManager::install(app::ACEInstance_Login, ACEInstance_Login_Hook);
		HookManager::install(app::ACEInstance_OnExitProcess, ACEInstance_OnExitProcess_Hook);
		HookManager::install(app::ACEInstance_Tick, ACEInstance_Tick_Hook);
		HookManager::install(app::ACEInstance_RequestAntiServer, ACEInstance_RequestAntiServer_Hook);
		HookManager::install(app::ACEInstance_ConnectAntiServer, ACEInstance_ConnectAntiServer_Hook);
		HookManager::install(app::ACEInstance_RecvAntiData, ACEInstance_RecvAntiData_Hook);
		HookManager::install(app::ACEInstance_OnRecvAntiData, ACEInstance_OnRecvAntiData_Hook);
		HookManager::install(app::ACEInstance_SendAntiData, ACEInstance_SendAntiData_Hook);
		HookManager::install(app::ACEInstance_get_IsQuitting, ACEInstance_get_IsQuitting_Hook);
		HookManager::install(app::ACEInstance_QuitWithMessageStatic, ACEInstance_QuitWithMessageStatic_Hook);
		HookManager::install(app::ACEInstance_QuitWithError, ACEInstance_QuitWithError_Hook);
		HookManager::install(app::ACEInstance_TrySendShowMessageAndQuitEvent, ACEInstance_TrySendShowMessageAndQuitEvent_Hook);
		HookManager::install(app::ACEInstance_ShowMessageAndQuit, ACEInstance_ShowMessageAndQuit_Hook);
		HookManager::install(app::ACEInstance_ReportEvent, ACEInstance_ReportEvent_Hook);
	}
	const FeatureGUIInfo& ACEInstance::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "·´×÷±×", "¸¨ÖúÉèÖÃ", true };
		return info;
	}
	void ACEInstance::DrawMain()
	{
		ImGui::Checkbox(Text::GBKTOUTF8("À©Õ¹À¹½Ø").c_str(), &ExAAC);
	}
	bool ACEInstance::NeedStatusDraw() const
	{
		return true;
	}
	void ACEInstance::DrawStatus()
	{
		if (ExAAC)
		{
			ImGui::Text(Text::GBKTOUTF8("À©Õ¹À¹½Ø").c_str());
		}
	}
	void ACEInstance::save()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}

		json["ExAAC"] = ExAAC;

		std::ofstream ofile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if(ofile)
		{
			ofile << json;
			ofile.close();
		}
	}
	void ACEInstance::load()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}
		if (json.find("ExAAC") != json.end())
		{
			ExAAC = json["ExAAC"];
		}
	}
	ACEInstance& ACEInstance::GetInstance()
	{
		static ACEInstance instance;
		return instance;
	}
	void ACEInstance::Update()
	{
	}
	static app::ACEInstance* ACEInstance_get_Instance_Hook(app::ACEInstance* _this)
	{
		if (ExAAC)
			return 0;
		return CALL_ORIGIN(ACEInstance_get_Instance_Hook, _this);
	}
	static app::ACEInstance* ACEInstance_InitInstance_Hook(app::ACEInstance* _this)
	{
		if (ExAAC)
			return 0;
		return CALL_ORIGIN(ACEInstance_InitInstance_Hook, _this);
	}
	static void ACEInstance_InitSwitches_Hook(app::ACEInstance* _this)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_InitSwitches_Hook, _this);
	}
	static app::TssAntibot* ACEInstance_get_Antibot_Hook(app::ACEInstance* _this)
	{
		if (ExAAC)
			return 0;
		return CALL_ORIGIN(ACEInstance_get_Antibot_Hook, _this);
	}
	static void ACEInstance_Init_Hook(app::ACEInstance* _this)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_Init_Hook, _this);
	}
	static void ACEInstance_SetUserInfo_Hook(app::ACEInstance* _this, std::int32_t roleId, std::int32_t platId)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_SetUserInfo_Hook, _this, roleId, platId);
	}
	static void ACEInstance_SetAntiServerResponse_Hook(app::ACEInstance* _this, HttpResponseAceServer* response)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_SetAntiServerResponse_Hook, _this, response);
	}
	static void ACEInstance_Login_Hook(app::ACEInstance* _this, APP_String* openId)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_Login_Hook, _this, openId);
	}
	static void ACEInstance_OnExitProcess_Hook(app::ACEInstance* _this)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_OnExitProcess_Hook, _this);
	}
	static void ACEInstance_Tick_Hook(app::ACEInstance* _this)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_Tick_Hook, _this);
	}
	static void ACEInstance_RequestAntiServer_Hook(app::ACEInstance* _this, double currTimeSec)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_RequestAntiServer_Hook, _this, currTimeSec);
	}
	static void ACEInstance_ConnectAntiServer_Hook(app::ACEInstance* _this, double currTimeSec)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_ConnectAntiServer_Hook, _this, currTimeSec);
	}
	static void ACEInstance_RecvAntiData_Hook(app::ACEInstance* _this)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_RecvAntiData_Hook, _this);
	}
	static void ACEInstance_OnRecvAntiData_Hook(app::ACEInstance* _this, char* data)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_OnRecvAntiData_Hook, _this, data);
	}
	static void ACEInstance_SendAntiData_Hook(app::ACEInstance* _this)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_SendAntiData_Hook, _this);
	}
	static void ACEInstance_get_IsQuitting_Hook(app::ACEInstance* _this)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_get_IsQuitting_Hook, _this);
	}
	static void ACEInstance_QuitWithMessageStatic_Hook(app::ACEInstance* _this, APP_String* text)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_QuitWithMessageStatic_Hook, _this, text);
	}
	static void ACEInstance_QuitWithError_Hook(app::ACEInstance* _this, int mainErr, int subErr)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_QuitWithError_Hook, _this, mainErr, subErr);
	}
	static void ACEInstance_TrySendShowMessageAndQuitEvent_Hook(app::ACEInstance* _this, APP_String* text)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_TrySendShowMessageAndQuitEvent_Hook, _this, text);
	}
	static void ACEInstance_ShowMessageAndQuit_Hook(app::ACEInstance* _this, APP_String* text)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_ShowMessageAndQuit_Hook, _this, text);
	}
	static void ACEInstance_ReportEvent_Hook(app::ACEInstance* _this, int mainErr, int subErr)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_ReportEvent_Hook, _this, mainErr, subErr);
	}
}