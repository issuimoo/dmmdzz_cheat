#include "ACEInstance.hpp"

namespace cheat::feature
{

	bool ExAAC = true;

	static ACEInstance* ACEInstance_get_Instance_Hook(ACEInstance* _this);
	static ACEInstance* ACEInstance_InitInstance_Hook(ACEInstance* _this);
	static void ACEInstance_InitSwitches_Hook(ACEInstance* _this);
	static TssAntibot* ACEInstance_get_Antibot_Hook(ACEInstance* _this);
	static void ACEInstance_Init_Hook(ACEInstance* _this);
	static void ACEInstance_SetUserInfo_Hook(ACEInstance* _this, std::int32_t roleId, std::int32_t platId);
	static void ACEInstance_SetAntiServerResponse_Hook(ACEInstance* _this, HttpResponseAceServer* response);
	static void ACEInstance_Login_Hook(ACEInstance* _this, APP_String* openId);
	static void ACEInstance_OnExitProcess_Hook(ACEInstance* _this);
	static void ACEInstance_Tick_Hook(ACEInstance* _this);
	static void ACEInstance_RequestAntiServer_Hook(ACEInstance* _this, double currTimeSec);
	static void ACEInstance_ConnectAntiServer_Hook(ACEInstance* _this, double currTimeSec);
	static void ACEInstance_RecvAntiData_Hook(ACEInstance* _this);
	static void ACEInstance_OnRecvAntiData_Hook(ACEInstance* _this, char* data);
	static void ACEInstance_SendAntiData_Hook(ACEInstance* _this);
	static void ACEInstance_get_IsQuitting_Hook(ACEInstance* _this);
	static void ACEInstance_QuitWithMessageStatic_Hook(ACEInstance* _this, APP_String* text);
	static void ACEInstance_QuitWithError_Hook(ACEInstance* _this, int mainErr, int subErr);
	static void ACEInstance_TrySendShowMessageAndQuitEvent_Hook(ACEInstance* _this, APP_String* text);
	static void ACEInstance_ShowMessageAndQuit_Hook(ACEInstance* _this, APP_String* text);
	static void ACEInstance_ReportEvent_Hook(ACEInstance* _this, int mainErr, int subErr);

	ACEInstance::ACEInstance() : Feature()
	{
		DO_HOOK(ACEInstance_get_Instance);
		DO_HOOK(ACEInstance_InitSwitches);
		DO_HOOK(ACEInstance_get_Antibot);
		DO_HOOK(ACEInstance_Init);
		DO_HOOK(ACEInstance_SetUserInfo);
		DO_HOOK(ACEInstance_SetAntiServerResponse);
		DO_HOOK(ACEInstance_Login);
		DO_HOOK(ACEInstance_OnExitProcess);
		DO_HOOK(ACEInstance_Tick);
		DO_HOOK(ACEInstance_RequestAntiServer);
		DO_HOOK(ACEInstance_ConnectAntiServer);
		DO_HOOK(ACEInstance_RecvAntiData);
		DO_HOOK(ACEInstance_OnRecvAntiData);
		DO_HOOK(ACEInstance_SendAntiData);
		DO_HOOK(ACEInstance_get_IsQuitting);
		DO_HOOK(ACEInstance_QuitWithMessageStatic);
		DO_HOOK(ACEInstance_QuitWithError);
		DO_HOOK(ACEInstance_TrySendShowMessageAndQuitEvent);
		DO_HOOK(ACEInstance_ShowMessageAndQuit);
		DO_HOOK(ACEInstance_ReportEvent);
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
	static ACEInstance* ACEInstance_get_Instance_Hook(ACEInstance* _this)
	{
		if (ExAAC)
			return 0;
		return CALL_ORIGIN(ACEInstance_get_Instance_Hook, _this);
	}
	static ACEInstance* ACEInstance_InitInstance_Hook(ACEInstance* _this)
	{
		if (ExAAC)
			return 0;
		return CALL_ORIGIN(ACEInstance_InitInstance_Hook, _this);
	}
	static void ACEInstance_InitSwitches_Hook(ACEInstance* _this)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_InitSwitches_Hook, _this);
	}
	static TssAntibot* ACEInstance_get_Antibot_Hook(ACEInstance* _this)
	{
		if (ExAAC)
			return 0;
		return CALL_ORIGIN(ACEInstance_get_Antibot_Hook, _this);
	}
	static void ACEInstance_Init_Hook(ACEInstance* _this)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_Init_Hook, _this);
	}
	static void ACEInstance_SetUserInfo_Hook(ACEInstance* _this, std::int32_t roleId, std::int32_t platId)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_SetUserInfo_Hook, _this, roleId, platId);
	}
	static void ACEInstance_SetAntiServerResponse_Hook(ACEInstance* _this, HttpResponseAceServer* response)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_SetAntiServerResponse_Hook, _this, response);
	}
	static void ACEInstance_Login_Hook(ACEInstance* _this, APP_String* openId)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_Login_Hook, _this, openId);
	}
	static void ACEInstance_OnExitProcess_Hook(ACEInstance* _this)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_OnExitProcess_Hook, _this);
	}
	static void ACEInstance_Tick_Hook(ACEInstance* _this)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_Tick_Hook, _this);
	}
	static void ACEInstance_RequestAntiServer_Hook(ACEInstance* _this, double currTimeSec)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_RequestAntiServer_Hook, _this, currTimeSec);
	}
	static void ACEInstance_ConnectAntiServer_Hook(ACEInstance* _this, double currTimeSec)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_ConnectAntiServer_Hook, _this, currTimeSec);
	}
	static void ACEInstance_RecvAntiData_Hook(ACEInstance* _this)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_RecvAntiData_Hook, _this);
	}
	static void ACEInstance_OnRecvAntiData_Hook(ACEInstance* _this, char* data)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_OnRecvAntiData_Hook, _this, data);
	}
	static void ACEInstance_SendAntiData_Hook(ACEInstance* _this)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_SendAntiData_Hook, _this);
	}
	static void ACEInstance_get_IsQuitting_Hook(ACEInstance* _this)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_get_IsQuitting_Hook, _this);
	}
	static void ACEInstance_QuitWithMessageStatic_Hook(ACEInstance* _this, APP_String* text)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_QuitWithMessageStatic_Hook, _this, text);
	}
	static void ACEInstance_QuitWithError_Hook(ACEInstance* _this, int mainErr, int subErr)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_QuitWithError_Hook, _this, mainErr, subErr);
	}
	static void ACEInstance_TrySendShowMessageAndQuitEvent_Hook(ACEInstance* _this, APP_String* text)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_TrySendShowMessageAndQuitEvent_Hook, _this, text);
	}
	static void ACEInstance_ShowMessageAndQuit_Hook(ACEInstance* _this, APP_String* text)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_ShowMessageAndQuit_Hook, _this, text);
	}
	static void ACEInstance_ReportEvent_Hook(ACEInstance* _this, int mainErr, int subErr)
	{
		if (ExAAC)
			return;
		return CALL_ORIGIN(ACEInstance_ReportEvent_Hook, _this, mainErr, subErr);
	}
}