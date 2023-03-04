#include "Blood.hpp"
#include "PlayerList.hpp"

std::vector<AutoRecoverable*> autorecoverable;

namespace cheat::feature
{
	bool AutoRecoverBlood_b = false;
	bool BloodNoLimet = false;
	bool BloodNoRest = false;

	static void AutoRecoverable_AutoRecoverBlood_Hook(AutoRecoverable* _this);
	static void AutoRecoverable_Start_Hook(AutoRecoverable* _this);
	static void PlayerController_LocalAddMaxLife_Hook(PlayerController* _this, float value);
	static void PlayerController_LocalAddMaxLifeAndDefaultMaxLife_Hook(PlayerController* _this, float value);
	static void PlayerController_LocalResetMaxLife_Hook(PlayerController* _this);
	
	Blood::Blood() : Feature()
	{
		DWORD dwOldProtect;
		VirtualProtect((LPVOID)((int)AutoRecoverable_AutoRecoverBlood + 0x150), sizeof BYTE, PAGE_READWRITE, &dwOldProtect);
		*(BYTE*)((int)AutoRecoverable_AutoRecoverBlood + 0x150) = 0x6E;
		VirtualProtect((LPVOID)((int)AutoRecoverable_AutoRecoverBlood + 0x150), sizeof BYTE, PAGE_EXECUTE_READ, &dwOldProtect);

		DO_HOOK(AutoRecoverable_AutoRecoverBlood);
		DO_HOOK(AutoRecoverable_Start);
		DO_HOOK(PlayerController_LocalAddMaxLife);
		DO_HOOK(PlayerController_LocalAddMaxLifeAndDefaultMaxLife);
		DO_HOOK(PlayerController_LocalResetMaxLife);
	}
	const FeatureGUIInfo& Blood::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "血量设置", "玩家设置", true };
		return info;
	}
	void Blood::DrawMain()
	{
		ImGui::Checkbox(Text::GBKTOUTF8("自动回血").c_str(), &AutoRecoverBlood_b);
		ImGui::SameLine();
		ImGui::Checkbox(Text::GBKTOUTF8("血量无上限").c_str(), &BloodNoLimet);
		ImGui::SameLine();
		ImGui::Checkbox(Text::GBKTOUTF8("血量上限不重置").c_str(), &BloodNoRest);
	}
	bool Blood::NeedStatusDraw() const
	{
		return AutoRecoverBlood_b || BloodNoLimet || BloodNoRest;
	}
	void Blood::DrawStatus()
	{
		if (AutoRecoverBlood_b || BloodNoLimet || BloodNoRest)
		{
			ImGui::Text(Text::GBKTOUTF8(fmt::format("血量设置[{}{}{}]",AutoRecoverBlood_b ? "A" : "",BloodNoLimet ? "L" : "",BloodNoRest ? "R" : "")).c_str());
		}
	}
	void Blood::save()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}

		json["AutoRecoverBlood_b"] = AutoRecoverBlood_b;
		json["BloodNoLimet"] = BloodNoLimet;
		json["BloodNoRest"] = BloodNoRest;

		std::ofstream ofile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ofile)
		{
			ofile << json;
			ofile.close();
		}
	}
	void Blood::load()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}
		if (json.find("AutoRecoverBlood_b") != json.end())
		{
			AutoRecoverBlood_b = json["AutoRecoverBlood_b"];
		}
		if (json.find("BloodNoRest") != json.end())
		{
			BloodNoRest = json["BloodNoRest"];
		}
		if (json.find("BloodNoLimet") != json.end())
		{
			BloodNoLimet = json["BloodNoLimet"];
		}
	}
	Blood& Blood::GetInstance()
	{
		static Blood instance;
		return instance;
	}
	void Blood::Update()
	{
		for (size_t i = 0, max = autorecoverable.size(); i < max; i++)
		{
			try
			{
				if (AutoRecoverBlood_b && autorecoverable[i]->m_Controller == m_PlayerController)
				{
					if (m_PlayerController->m_BattleProperties->maxLife < 90000 && BloodNoLimet)
					{
						CALL_ORIGIN(PlayerController_LocalAddMaxLife_Hook, m_PlayerController, 90000.0f);
						CALL_ORIGIN(PlayerController_LocalAddMaxLifeAndDefaultMaxLife_Hook, m_PlayerController, 90000.0f);
					}
					CALL_ORIGIN(AutoRecoverable_AutoRecoverBlood_Hook, autorecoverable[i]);
				}
			}
			catch (...)
			{

			}
		}
	}

	static void AutoRecoverable_AutoRecoverBlood_Hook(AutoRecoverable* _this)
	{
		if (AutoRecoverBlood_b)
		{
			_this->m_Interval = 0.01f;
			_this->m_Amount = 1000.0f;
		}
		return CALL_ORIGIN(AutoRecoverable_AutoRecoverBlood_Hook, _this);
	}

	static void AutoRecoverable_Start_Hook(AutoRecoverable* _this)
	{
		autorecoverable.push_back(_this);
		return CALL_ORIGIN(AutoRecoverable_Start_Hook, _this);
	}
	static void PlayerController_LocalAddMaxLife_Hook(PlayerController* _this, float value)
	{
		float life = value;
		if (_this->m_BattleProperties->maxLife < 90000 && BloodNoLimet)
		{
			life = 90000;
		}
		return CALL_ORIGIN(PlayerController_LocalAddMaxLife_Hook, _this, life);
	}
	static void PlayerController_LocalAddMaxLifeAndDefaultMaxLife_Hook(PlayerController* _this, float value)
	{
		float life = value;
		if (_this->m_BattleProperties->maxLife < 90000 && BloodNoLimet)
		{
			life = 90000;
		}
		return CALL_ORIGIN(PlayerController_LocalAddMaxLifeAndDefaultMaxLife_Hook, _this, life);
	}
	static void PlayerController_LocalResetMaxLife_Hook(PlayerController* _this)
	{
		if (BloodNoRest)
		{
			return;
		}
		return CALL_ORIGIN(PlayerController_LocalResetMaxLife_Hook, _this);
	}
}