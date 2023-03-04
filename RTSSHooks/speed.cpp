#include "speed.hpp"
#include "PlayerList.hpp"

namespace cheat::feature
{

	bool speedhack = false;
	bool NoMove = false;

	float speedv = 1.0;

	static void PlayerController_SetSpeed_Hook(PlayerController* _this, Vector3 v);

	speed::speed() : Feature()
	{
		DO_HOOK(PlayerController_SetSpeed);
	}
	const FeatureGUIInfo& speed::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "速度设置", "玩家设置", true };
		return info;
	}
	void speed::DrawMain()
	{
		ImGui::Checkbox(Text::GBKTOUTF8("修改速度").c_str(), &speedhack);
		ImGui::SameLine();
		ImGui::Checkbox(Text::GBKTOUTF8("玩家无移速").c_str(), &NoMove);
		if (speedhack)
		{
			ImGui::SliderFloat(Text::GBKTOUTF8("值").c_str(), &speedv, 0.0f, 10.0f, "%.2f");
		}
	}
	bool speed::NeedStatusDraw() const
	{
		return speedhack;
	}
	void speed::DrawStatus()
	{
		if (speedhack)
		{
			ImGui::Text(Text::GBKTOUTF8(fmt::format("修改速度[{:0.2}]",speedv)).c_str());
		}	
	}
	void speed::save()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}

		json["speedhack"] = speedhack;
		json["speedv"] = speedv;
		json["NoMove"] = NoMove;

		std::ofstream ofile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ofile)
		{
			ofile << json;
			ofile.close();
		}
	}
	void speed::load()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}
		if (json.find("speedhack") != json.end())
		{
			speedhack = json["speedhack"];
		}
		if (json.find("speedv") != json.end())
		{
			speedv = json["speedv"];
		}
		if (json.find("NoMove") != json.end())
		{
			NoMove = json["NoMove"];
		}
	}
	speed& speed::GetInstance()
	{
		static speed instance;
		return instance;
	}
	void speed::Update()
	{
		try
		{
			
			Vector3 speeds{ speedv,speedv,speedv };
			if (speedhack)
				CALL_ORIGIN(PlayerController_SetSpeed_Hook, m_PlayerController, speeds);
			if (NoMove)
			{
				speeds = { 0,0,0 };
				for (size_t i = 0, max = Vec_PlayerList.size(); i < max; i++)
				{
					if (!Vec_PlayerList[i]->m_IsLocalPlayer)
					{
						CALL_ORIGIN(PlayerController_SetSpeed_Hook, Vec_PlayerList[i], speeds);
					}
				}
			}
		}
		catch (...)
		{

		}
	}
	static void PlayerController_SetSpeed_Hook(PlayerController* _this, Vector3 v)
	{
		Vector3 speeds = v;
		if (speedhack)
		{
			speeds.x = speedv;
			speeds.y = speedv;
			speeds.z = speedv;
		}
		if (NoMove)
		{
			speeds.x = 0;
			speeds.y = 0;
			speeds.z = 0;
		}
		return CALL_ORIGIN(PlayerController_SetSpeed_Hook, _this, speeds);
	}
}