#include "AAC.hpp"
#include "AACLog.hpp"

namespace cheat::feature
{
	bool CloseAC = true;
	bool closeCL = true;
	bool CloseGhost = true;
	bool NewMsg = false;

	unsigned int intercepts = 0;

	static void AntiCheatingSystem_SendReport_Hook(AntiCheatingSystem* _this, APP_String* userID, AntiCheatingResult result);
	static void AntiCheatingSystem_Quit_Hook(AntiCheatingSystem* _this);
	static void AntiCheatingSystem_AddGhost_Hook(AntiCheatingSystem* _this, AntiCheatingGhost g, unsigned int t, APP_String* userId);
	static void AntiCheatingSystem_QuitApplication_Hook(AntiCheatingSystem* _this);

	AAC::AAC() : Feature()
	{
		DO_HOOK(AntiCheatingSystem_SendReport);
		DO_HOOK(AntiCheatingSystem_Quit);
		DO_HOOK(AntiCheatingSystem_AddGhost);
		DO_HOOK(AntiCheatingSystem_QuitApplication);
	}
	const FeatureGUIInfo& AAC::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "反作弊", "辅助设置", true };
		return info;
	}
	void AAC::DrawMain()
	{
		ImGui::Checkbox(Text::GBKTOUTF8("拦截上报").c_str(), &CloseAC);
		ImGui::SameLine();
		ImGui::Checkbox(Text::GBKTOUTF8("拦截退出").c_str(), &closeCL);
		ImGui::SameLine();
		ImGui::Checkbox(Text::GBKTOUTF8("拦截鬼魂").c_str(), &CloseGhost);
		if (CloseAC)
		{
			ImGui::SameLine();
			ImGui::Checkbox(Text::GBKTOUTF8("替换模式").c_str(), &NewMsg);
		}
		ImGui::TextColored({ 255, 164, 0 ,255 }, Text::GBKTOUTF8(fmt::format("已拦截 {} 次上传", intercepts)).c_str());
	}
	bool AAC::NeedStatusDraw() const
	{
		return CloseAC || closeCL || CloseGhost;
	}
	void AAC::DrawStatus()
	{
		ImGui::Text(Text::GBKTOUTF8(fmt::format("反作弊[{}{}{}]", CloseAC ? "S" : "", closeCL ? "Q" : "", CloseGhost ? "G" : "")).c_str());
	}
	void AAC::save()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}

		json["AAC"] = CloseAC;
		json["AACEXIT"] = closeCL;
		json["AACGhost"] = CloseGhost;

		std::ofstream ofile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if(ofile)
		{
			ofile << json;
			ofile.close();
		}
	}
	void AAC::load()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}
		if (json.find("AAC") != json.end())
		{
			CloseAC = json["AAC"];
		}
		if (json.find("AACEXIT") != json.end())
		{
			closeCL = json["AACEXIT"];
		}
		if (json.find("AACGhost") != json.end())
		{
			CloseGhost = json["AACGhost"];
		}
	}
	AAC& AAC::GetInstance()
	{
		static AAC instance;
		return instance;
	}
	void AAC::Update()
	{
	}

	static void AntiCheatingSystem_SendReport_Hook(AntiCheatingSystem* _this, APP_String* userID, AntiCheatingResult result)
	{
		if (magic_enum::enum_name<AntiCheatingResult>(result) != "")
		{
			intercepts++;
			LOGDEBUG(fmt::format("AntiCheatingSystem_SendReport_Hook-> result:{} userID:{}\n", magic_enum::enum_name<AntiCheatingResult>(result),Text::UTF8TOGBK(Text::UTF16TOUTF8((wchar_t*)&userID->m_firstChar))));
			AACLogs.push_back(fmt::format("AntiCheatingSystem_SendReport_Hook-> result:{} userID:{}\n", magic_enum::enum_name<AntiCheatingResult>(result), Text::UTF16TOUTF8((wchar_t*)&userID->m_firstChar)));
		}
		if (CloseAC && !NewMsg)
		{
			return;
		}
		if (NewMsg)
		{
			const wchar_t* userid = L"114514";
			userID->m_stringLength = 6;
			userID->m_firstChar = userid[0];
			return CALL_ORIGIN(AntiCheatingSystem_SendReport_Hook, _this, userID, AntiCheatingResult::Normal);
		}
		return CALL_ORIGIN(AntiCheatingSystem_SendReport_Hook, _this, userID, result);
	}
	static void AntiCheatingSystem_Quit_Hook(AntiCheatingSystem* _this)
	{
		LOGDEBUG(fmt::format("AntiCheatingSystem_Quit_Hook-> Quit\n"));
		AACLogs.push_back(fmt::format("AntiCheatingSystem_Quit_Hook-> Quit\n"));
		if (closeCL)
		{
			return;
		}
		return CALL_ORIGIN(AntiCheatingSystem_Quit_Hook, _this);
	}
	static void AntiCheatingSystem_AddGhost_Hook(AntiCheatingSystem* _this, AntiCheatingGhost g, unsigned int t, APP_String* userId)
	{
		if (magic_enum::enum_name<AntiCheatingGhost>(g) != "")
		{
			LOGDEBUG(fmt::format("AntiCheatingSystem_AddGhost_Hook-> result:{} \n", magic_enum::enum_name<AntiCheatingGhost>(g)));
			AACLogs.push_back(fmt::format("AntiCheatingSystem_AddGhost_Hook-> result:{} \n", magic_enum::enum_name<AntiCheatingGhost>(g)));
		}
		if (CloseGhost)
		{
			return;
		}
		return CALL_ORIGIN(AntiCheatingSystem_AddGhost_Hook, _this,g,t, userId);
	}
	static void AntiCheatingSystem_QuitApplication_Hook(AntiCheatingSystem* _this)
	{
		if (closeCL)
		{
			return;
		}
		return CALL_ORIGIN(AntiCheatingSystem_QuitApplication_Hook, _this);
	}
}