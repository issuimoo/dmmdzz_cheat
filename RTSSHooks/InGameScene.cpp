#include "InGameScene.hpp"

namespace cheat::feature
{
	InGameScene::InGameScene() : Feature()
	{

	}
	const FeatureGUIInfo& InGameScene::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "��������", "��������", true };
		return info;
	}
	void InGameScene::DrawMain()
	{
		ImGui::Checkbox(Text::GBKTOUTF8("��ʾ���ù���").c_str(), &ShowStatusFeature);
		ImGui::SameLine();
		ImGui::Checkbox(Text::GBKTOUTF8("�ƶ����ù���").c_str(), &MoveStatusFeature);
		ImGui::Checkbox(Text::GBKTOUTF8("��ʾ��Ϸ֡��").c_str(), &ShowGameFPS);
		ImGui::SameLine();
		ImGui::Checkbox(Text::GBKTOUTF8("�ƶ���Ϸ֡��").c_str(), &MoveGameFPS);
		ImGui::Checkbox(Text::GBKTOUTF8("��ʾImGui��ʾ").c_str(), &ShowImGuiDemo);
		ImGui::SameLine();
		ImGui::Checkbox(Text::GBKTOUTF8("��ʾImPlot��ʾ").c_str(), &ShowImPlotDemo);
	}
	bool InGameScene::NeedStatusDraw() const
	{
		return ShowStatusFeature || ShowGameFPS;
	}
	void InGameScene::DrawStatus()
	{
		ImGui::Text(Text::GBKTOUTF8(fmt::format("GUI[{}{}]", ShowStatusFeature ? "S" : "", ShowGameFPS ? "F" : "")).c_str());
	}
	void InGameScene::save()
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
	void InGameScene::load()
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
	InGameScene& InGameScene::GetInstance()
	{
		static InGameScene instance;
		return instance;
	}
	void InGameScene::Update()
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