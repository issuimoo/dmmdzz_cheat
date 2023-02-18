#include "AutoRecoverBlood.hpp"
#include "PlayerList.hpp"

std::vector<app::AutoRecoverable*> autorecoverable;

namespace cheat::feature
{
	bool AutoRecoverBlood_b = false;

	static void AutoRecoverable_AutoRecoverBlood_Hook(app::AutoRecoverable* _this);
	static void AutoRecoverable_Start_Hook(app::AutoRecoverable* _this);
	
	AutoRecoverBlood::AutoRecoverBlood() : Feature()
	{
		app::AutoRecoverable_AutoRecoverBlood = (void(*)(app::AutoRecoverable * _this))(((unsigned int)pch::GameAssembly) + Address_AutoRecoverable_AutoRecoverBlood);
		app::AutoRecoverable_Start = (void(*)(app::AutoRecoverable * _this))(((unsigned int)pch::GameAssembly) + Address_AutoRecoverable_Start);
		
		//解决他以实现功能
		//*(BYTE*)((int)app::AutoRecoverable_AutoRecoverBlood + 0x150) = 0x6E;

		HookManager::install(app::AutoRecoverable_AutoRecoverBlood, AutoRecoverable_AutoRecoverBlood_Hook);
		HookManager::install(app::AutoRecoverable_Start, AutoRecoverable_Start_Hook);
	}
	const FeatureGUIInfo& AutoRecoverBlood::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "自动回血", "玩家设置", true };
		return info;
	}
	void AutoRecoverBlood::DrawMain()
	{
		ImGui::Checkbox(Text::GBKTOUTF8("自动回血").c_str(), &AutoRecoverBlood_b);
	}
	bool AutoRecoverBlood::NeedStatusDraw() const
	{
		return false;
	}
	void AutoRecoverBlood::DrawStatus()
	{
	}
	void AutoRecoverBlood::save()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}

		json["AutoRecoverBlood_b"] = AutoRecoverBlood_b;

		std::ofstream ofile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ofile)
		{
			ofile << json;
			ofile.close();
		}
	}
	void AutoRecoverBlood::load()
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
	}
	AutoRecoverBlood& AutoRecoverBlood::GetInstance()
	{
		static AutoRecoverBlood instance;
		return instance;
	}
	void AutoRecoverBlood::Update()
	{
		try
		{
			size_t size_i = autorecoverable.size();
			for (int i = 0; i < size_i; i++)
			{
				if (AutoRecoverBlood_b && autorecoverable[i]->m_Controller == m_PlayerController)
				{
					return CALL_ORIGIN(AutoRecoverable_AutoRecoverBlood_Hook, autorecoverable[i]);
				}
			}
		}
		catch (...)
		{

		}
	}

	static void AutoRecoverable_AutoRecoverBlood_Hook(app::AutoRecoverable* _this)
	{
		if(AutoRecoverBlood_b)
			_this->m_Amount = 100;
		return CALL_ORIGIN(AutoRecoverable_AutoRecoverBlood_Hook, _this);
	}

	static void AutoRecoverable_Start_Hook(app::AutoRecoverable* _this)
	{
		autorecoverable.push_back(_this);
		return CALL_ORIGIN(AutoRecoverable_Start_Hook, _this);
	}
}