#include "setting.hpp"

bool ShowStatusFeature = true;
bool MoveStatusFeature = false;
bool ShowGameFPS = true;
bool MoveGameFPS = false;

bool ShowImGuiDemo = false;
bool ShowImPlotDemo = false;

namespace cheat::feature
{
	setting::setting() : Feature()
	{

	}
	const FeatureGUIInfo& setting::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "其他窗口", "辅助设置", true };
		return info;
	}
	void setting::DrawMain()
	{
		ImGui::Checkbox(Text::GBKTOUTF8("显示启用功能").c_str(), &ShowStatusFeature);
		ImGui::SameLine();
		ImGui::Checkbox(Text::GBKTOUTF8("移动启用功能").c_str(), &MoveStatusFeature);
		ImGui::Checkbox(Text::GBKTOUTF8("显示游戏帧数").c_str(), &ShowGameFPS);
		ImGui::SameLine();
		ImGui::Checkbox(Text::GBKTOUTF8("移动游戏帧数").c_str(), &MoveGameFPS);
		ImGui::Checkbox(Text::GBKTOUTF8("显示ImGui演示").c_str(), &ShowImGuiDemo);
		ImGui::SameLine();
		ImGui::Checkbox(Text::GBKTOUTF8("显示ImPlot演示").c_str(), &ShowImPlotDemo);
	}
	bool setting::NeedStatusDraw() const
	{
		return ShowStatusFeature || ShowGameFPS;
	}
	void setting::DrawStatus()
	{
		ImGui::Text(Text::GBKTOUTF8(fmt::format("GUI[{}{}]", ShowStatusFeature ? "S" : "", ShowGameFPS ? "F" : "")).c_str());
	}
	void setting::save()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}

		json["ShowStatusFeature"] = ShowStatusFeature;
		json["MoveStatusFeature"] = MoveStatusFeature;
		json["ShowGameFPS"] = ShowGameFPS;
		json["MoveGameFPS"] = MoveGameFPS;

		std::ofstream ofile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ofile)
		{
			ofile << json;
			ofile.close();
		}
	}
	void setting::load()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}
		if (json.find("ShowStatusFeature") != json.end())
		{
			ShowStatusFeature = json["ShowStatusFeature"];
		}
		if (json.find("MoveStatusFeature") != json.end())
		{
			MoveStatusFeature = json["MoveStatusFeature"];
		}
		if (json.find("ShowGameFPS") != json.end())
		{
			ShowGameFPS = json["ShowGameFPS"];
		}
		if (json.find("MoveGameFPS") != json.end())
		{
			MoveGameFPS = json["MoveGameFPS"];
		}
	}
	setting& setting::GetInstance()
	{
		static setting instance;
		return instance;
	}
	void setting::Update()
	{
		if (ShowImGuiDemo)
		{
			ImGui::ShowDemoWindow();
		}
		if (ShowImPlotDemo)
		{
			ImPlot::ShowDemoWindow();
		}
	}
}