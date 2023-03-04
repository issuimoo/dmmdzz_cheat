#include "AntiImmobility.hpp"

namespace cheat::feature
{
	bool OnAntiImmobility = true;

	static bool BipedalDragonShapeController_get_DisableFireButton_Hook(BipedalDragonShapeController* _this);
	static bool BipedalDragonShapeController_get_DisableJumpButton_Hook(BipedalDragonShapeController* _this);
	static bool BipedalDragonShapeController_get_MoveTargetForward_Hook(BipedalDragonShapeController* _this);
	static bool BipedalDragonShapeController_get_ControllerMove_Hook(BipedalDragonShapeController* _this);

	AntiImmobility::AntiImmobility() : Feature()
	{
		DO_HOOK(BipedalDragonShapeController_get_DisableFireButton);
		DO_HOOK(BipedalDragonShapeController_get_DisableJumpButton);
		DO_HOOK(BipedalDragonShapeController_get_MoveTargetForward);
		DO_HOOK(BipedalDragonShapeController_get_ControllerMove);
	}
	const FeatureGUIInfo& AntiImmobility::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "反定身", "玩家设置", true };
		return info;
	}
	void AntiImmobility::DrawMain()
	{
		ImGui::Checkbox(Text::GBKTOUTF8("反定身").c_str(), &OnAntiImmobility);
	}
	bool AntiImmobility::NeedStatusDraw() const
	{
		return OnAntiImmobility;
	}
	void AntiImmobility::DrawStatus()
	{
		if (OnAntiImmobility)
		{
			ImGui::Text(Text::GBKTOUTF8("反定身").c_str());
		}
	}
	void AntiImmobility::save()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}

		json["AntiImmobility"] = OnAntiImmobility;

		std::ofstream ofile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ofile)
		{
			ofile << json;
			ofile.close();
		}
	}
	void AntiImmobility::load()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}
		if (json.find("AntiImmobility") != json.end())
		{
			OnAntiImmobility = json["AntiImmobility"];
		}
	}
	AntiImmobility& AntiImmobility::GetInstance()
	{
		static AntiImmobility instance;
		return instance;
	}
	void AntiImmobility::Update()
	{

	}
	static bool BipedalDragonShapeController_get_DisableFireButton_Hook(BipedalDragonShapeController* _this)
	{
		if (OnAntiImmobility)
		{
			return false;
		}
		return CALL_ORIGIN(BipedalDragonShapeController_get_DisableFireButton_Hook, _this);
	}
	static bool BipedalDragonShapeController_get_DisableJumpButton_Hook(BipedalDragonShapeController* _this)
	{
		if (OnAntiImmobility)
		{
			return false;
		}
		return CALL_ORIGIN(BipedalDragonShapeController_get_DisableJumpButton_Hook, _this);
	}
	static bool BipedalDragonShapeController_get_MoveTargetForward_Hook(BipedalDragonShapeController* _this)
	{
		if (OnAntiImmobility)
		{
			return true;
		}
		return CALL_ORIGIN(BipedalDragonShapeController_get_MoveTargetForward_Hook, _this);
	}
	static bool BipedalDragonShapeController_get_ControllerMove_Hook(BipedalDragonShapeController* _this)
	{
		if (OnAntiImmobility)
		{
			return true;
		}
		return CALL_ORIGIN(BipedalDragonShapeController_get_ControllerMove_Hook, _this);
	}
}