#pragma once
#include "NoFogOfWar.hpp"
namespace cheat::feature
{
	bool CloseFog = true;

	static bool InGameFogOfWar_get_ShowAllRoleView_Hook(InGameFogOfWar* _this);
	static bool InGameFogOfWar_get_DisableFogVisual_Hook(InGameFogOfWar* _this);

	NoFogOfWar::NoFogOfWar() : Feature()
	{
		DO_HOOK(InGameFogOfWar_get_ShowAllRoleView);
		DO_HOOK(InGameFogOfWar_get_DisableFogVisual);
	}
	const FeatureGUIInfo& NoFogOfWar::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "战争迷雾", "地图设置", true };
		return info;
	}
	void NoFogOfWar::DrawMain()
	{
		ImGui::Checkbox(Text::GBKTOUTF8("无战争迷雾").c_str(), &CloseFog);
	}
	bool NoFogOfWar::NeedStatusDraw() const
	{
		return CloseFog;
	}
	void NoFogOfWar::DrawStatus()
	{
		if (CloseFog)
		{
			ImGui::Text(Text::GBKTOUTF8("无战争迷雾").c_str());
		}
	}
	void NoFogOfWar::save()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}

		json["NoFogWar"] = CloseFog;

		std::ofstream ofile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ofile)
		{
			ofile << json;
			ofile.close();
		}
	}
	void NoFogOfWar::load()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}
		if (json.find("NoFogWar") != json.end())
		{
			CloseFog = json["NoFogWar"];
		}
	}
	NoFogOfWar& NoFogOfWar::GetInstance()
	{
		static NoFogOfWar instance;
		return instance;
	}
	void NoFogOfWar::Update()
	{
	}

	static bool InGameFogOfWar_get_ShowAllRoleView_Hook(InGameFogOfWar* _this)
	{
		if (CloseFog)
		{
			return true;
		}
		return CALL_ORIGIN(InGameFogOfWar_get_ShowAllRoleView_Hook, _this);
	}
	static bool InGameFogOfWar_get_DisableFogVisual_Hook(InGameFogOfWar* _this)
	{
		if (CloseFog)
		{
			return true;
		}
		return CALL_ORIGIN(InGameFogOfWar_get_DisableFogVisual_Hook, _this);
	}
}