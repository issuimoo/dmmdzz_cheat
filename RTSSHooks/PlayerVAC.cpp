#include "PlayerVAC.hpp"
#include "PlayerList.hpp"

bool VAC = false;

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
	}
	bool PlayerVAC::NeedStatusDraw() const
	{
		return VAC;
	}
	void PlayerVAC::DrawStatus()
	{
		if (VAC)
		{
			ImGui::Text(Text::GBKTOUTF8("Íæ¼ÒÎü¸½").c_str());
		}
	}
	void PlayerVAC::save()
	{
	}
	void PlayerVAC::load()
	{
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