#include "About.hpp"
namespace cheat::feature
{
	About::About() : Feature()
	{
	}
	const FeatureGUIInfo& About::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "", "关于辅助", false };
		return info;
	}
	void About::DrawMain()
	{
		ImGui::Text(Text::GBKTOUTF8("开发: 遂沫(a1992724048@outlook.com)").c_str());
		ImGui::TextColored(ImGui::HexToRGBA("C93756"), Text::GBKTOUTF8("本辅助完全免费!如果您是买来的说明你被骗了!").c_str());
		ImGui::Text(Text::GBKTOUTF8("已用源码:").c_str());
		ImGui::TextColored(ImColor(0, 102, 255, 255),
			"%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",
			"ImGui - Omar Cornut",
			"fmt - Victor Zverovich",
			"ImNodes - Johann Muszynski",
			"ImPlot - Evan Pezent",
			"json - nlohmann",
			"magic_enum - Daniil Goncharov",
			"simpleini - Brodie Thiesfield",
			"detours - Microsoft");
	}
	bool About::NeedStatusDraw() const
	{
		return false;
	}
	void About::DrawStatus()
	{
	}
	void About::save()
	{
	}
	void About::load()
	{
	}
	About& About::GetInstance()
	{
		static About instance;
		return instance;
	}
	void About::Update()
	{
	}
}