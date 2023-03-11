#include "InGameScene.hpp"

namespace cheat::feature
{
	InGameScene::InGameScene() : Feature()
	{

	}
	const FeatureGUIInfo& InGameScene::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "InGameScene", "µ÷ÊÔ¹¦ÄÜ", true };
		return info;
	}
	void InGameScene::DrawMain()
	{
		
	}
	bool InGameScene::NeedStatusDraw() const
	{
		return false;
	}
	void InGameScene::DrawStatus()
	{
		
	}
	void InGameScene::save()
	{
		
	}
	void InGameScene::load()
	{
		
	}
	InGameScene& InGameScene::GetInstance()
	{
		static InGameScene instance;
		return instance;
	}
	void InGameScene::Update()
	{
		
	}
}