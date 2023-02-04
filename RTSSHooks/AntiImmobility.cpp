#include "AntiImmobility.hpp"

namespace cheat::feature
{
	bool OnAntiImmobility = true;

	static bool BipedalDragonShapeController_get_DisableFireButton_HOOK(BipedalDragonShapeController* _this);
	static bool BipedalDragonShapeController_get_DisableJumpButton_HOOK(BipedalDragonShapeController* _this);
	static bool BipedalDragonShapeController_get_MoveTargetForward_HOOK(BipedalDragonShapeController* _this);
	static bool BipedalDragonShapeController_get_ControllerMove_HOOK(BipedalDragonShapeController* _this);

	AntiImmobility::AntiImmobility() : Feature()
	{
		app::BipedalDragonShapeController_get_DisableFireButton = (bool(*)(BipedalDragonShapeController*))(((unsigned int)pch::GameAssembly) + Address_BipedalDragonShapeController_get_DisableFireButton);
		app::BipedalDragonShapeController_get_DisableJumpButton = (bool(*)(BipedalDragonShapeController*))(((unsigned int)pch::GameAssembly) + Address_BipedalDragonShapeController_get_DisableJumpButton);
		app::BipedalDragonShapeController_get_MoveTargetForward = (bool(*)(BipedalDragonShapeController*))(((unsigned int)pch::GameAssembly) + Address_BipedalDragonShapeController_get_MoveTargetForward);
		app::BipedalDragonShapeController_get_ControllerMove = (bool(*)(BipedalDragonShapeController*))(((unsigned int)pch::GameAssembly) + Address_BipedalDragonShapeController_get_ControllerMove);
	
		HookManager::install(app::BipedalDragonShapeController_get_DisableFireButton, BipedalDragonShapeController_get_DisableFireButton_HOOK);
		HookManager::install(app::BipedalDragonShapeController_get_DisableJumpButton, BipedalDragonShapeController_get_DisableJumpButton_HOOK);
		HookManager::install(app::BipedalDragonShapeController_get_MoveTargetForward, BipedalDragonShapeController_get_MoveTargetForward_HOOK);
		HookManager::install(app::BipedalDragonShapeController_get_ControllerMove, BipedalDragonShapeController_get_ControllerMove_HOOK);
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
	}
	void AntiImmobility::load()
	{
	}
	AntiImmobility& AntiImmobility::GetInstance()
	{
		static AntiImmobility instance;
		return instance;
	}
	void AntiImmobility::Update()
	{

	}
	static bool BipedalDragonShapeController_get_DisableFireButton_HOOK(BipedalDragonShapeController* _this)
	{
		if (OnAntiImmobility)
		{
			return false;
		}
		return CALL_ORIGIN(BipedalDragonShapeController_get_DisableFireButton_HOOK, _this);
	}
	static bool BipedalDragonShapeController_get_DisableJumpButton_HOOK(BipedalDragonShapeController* _this)
	{
		if (OnAntiImmobility)
		{
			return false;
		}
		return CALL_ORIGIN(BipedalDragonShapeController_get_DisableJumpButton_HOOK, _this);
	}
	static bool BipedalDragonShapeController_get_MoveTargetForward_HOOK(BipedalDragonShapeController* _this)
	{
		if (OnAntiImmobility)
		{
			return true;
		}
		return CALL_ORIGIN(BipedalDragonShapeController_get_MoveTargetForward_HOOK, _this);
	}
	static bool BipedalDragonShapeController_get_ControllerMove_HOOK(BipedalDragonShapeController* _this)
	{
		if (OnAntiImmobility)
		{
			return true;
		}
		return CALL_ORIGIN(BipedalDragonShapeController_get_ControllerMove_HOOK, _this);
	}
}