#include "PlayerVAC.hpp"
#include "PlayerList.hpp"

bool VAC = false;
float x_p = 1.0f;

namespace cheat::feature
{
	PlayerVAC::PlayerVAC() : Feature()
	{

	}
	const FeatureGUIInfo& PlayerVAC::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "Íæ¼ÒÎü¸½", "Íæ¼ÒÉèÖÃ", true };
		return info;
	}
	void PlayerVAC::DrawMain()
	{
		ImGui::Checkbox(Text::GBKTOUTF8("Íæ¼ÒÎü¸½").c_str(), &VAC);
		if (VAC)
		{
			ImGui::SliderFloat(Text::GBKTOUTF8("Æ«ÒÆ").c_str(), &x_p, 0.0f, 10.0f, "%.2f");
		}
	}
	bool PlayerVAC::NeedStatusDraw() const
	{
		return VAC;
	}
	void PlayerVAC::DrawStatus()
	{
		if (VAC)
		{
			ImGui::Text(Text::GBKTOUTF8(fmt::format("Íæ¼ÒÎü¸½[{:0.2f}]",x_p)).c_str());
		}
	}
	void PlayerVAC::save()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}

		json["VAC"] = VAC;
		json["x_p"] = x_p;

		std::ofstream ofile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ofile)
		{
			ofile << json;
			ofile.close();
		}
	}
	void PlayerVAC::load()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}
		if (json.find("VAC") != json.end())
		{
			VAC = json["VAC"];
		}
		if (json.find("x_p") != json.end())
		{
			x_p = json["x_p"];
		}
	}
	PlayerVAC& PlayerVAC::GetInstance()
	{
		static PlayerVAC instance;
		return instance;
	}
	void PlayerVAC::Update()
	{
	}
}