#include "AACLog.hpp"

std::vector<std::string> AACLogs;

namespace cheat::feature
{
	AACLog::AACLog() : Feature()
	{
		
	}
	const FeatureGUIInfo& AACLog::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "", "调试功能", false };
		return info;
	}
	void AACLog::DrawMain()
	{
		if (ImGui::CollapsingHeader(Text::GBKTOUTF8("反作弊日志").c_str()))
		{
			if (ImGui::Button(Text::GBKTOUTF8("清空日志").c_str()))
			{
				AACLogs.clear();
			}
			if (ImGui::BeginTable("AACLogs", 1, ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_ScrollX | ImGuiTableFlags_ScrollY | ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable, ImVec2(0.0f, ImGui::GetTextLineHeightWithSpacing() * 13)))
			{
				ImGui::TableSetupScrollFreeze(0, 1);
				ImGui::TableSetupColumn(Text::GBKTOUTF8("内容").c_str(), ImGuiTableColumnFlags_None);
				ImGui::TableHeadersRow();
				try
				{
					for (size_t i = 0, max = AACLogs.size() - 1; i >= max; i++)
					{
						ImGui::PushID(&AACLogs[i]); //必须加上不然按钮没效果
						ImGui::TableNextRow();
						if (ImGui::TableSetColumnIndex(0))
						{
							ImGui::Text(AACLogs[i].c_str());
						}
						ImGui::PopID();
					}
				}
				catch (...)
				{

				}
				ImGui::EndTable();
			}
		}
	}
	bool AACLog::NeedStatusDraw() const
	{
		return false;
	}
	void AACLog::DrawStatus()
	{
	}
	void AACLog::save()
	{
	}
	void AACLog::load()
	{
	}
	AACLog& AACLog::GetInstance()
	{
		static AACLog instance;
		return instance;
	}
	void AACLog::Update()
	{

	}
}
