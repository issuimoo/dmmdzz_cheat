#include "renderer.h"

renderer::CheatManagerBase Mem;

std::string jsonfile = "TYPE-1";

#include "setting.hpp"
#include "AAC.hpp"
#include "Store.hpp"
#include "About.hpp"
#include "ItemList.hpp"
#include "PlayerList.hpp"
#include "NoFogOfWar.hpp"
#include "BuyNoSub.hpp"
#include "PlayerVAC.hpp"
#include "AntiImmobility.hpp"
#include "AACLog.hpp"

namespace renderer
{
	bool OpenALL;

	void CheatManagerBase::PushFeature(Feature* feature)
	{
		m_Features.push_back(feature);

		auto& info = feature->GetGUIInfo();
		if (m_FeatureMap.count(info.moduleName) == 0)
		{
			m_FeatureMap[info.moduleName] = {};
			m_ModuleOrder.push_back(info.moduleName);
		}

		auto& sectionMap = m_FeatureMap[info.moduleName];
		std::string sectionName = info.isGroup ? info.name : std::string();
		if (sectionMap.count(sectionName) == 0)
			sectionMap[sectionName] = {};

		auto& featureList = sectionMap[sectionName];
		featureList.push_back(feature);
	}

	void CheatManagerBase::AddFeature(Feature* feature)
	{
		PushFeature(feature);
	}

	void CheatManagerBase::AddFeatures(std::vector<Feature*> features)
	{
		for (auto& feature : features)
		{
			PushFeature(feature);
		}
	}

	void CheatManagerBase::SetModuleOrder(std::vector<std::string> moduleOrder)
	{
		std::unordered_set<std::string> moduleSet;
		moduleSet.insert(m_ModuleOrder.begin(), m_ModuleOrder.end());

		m_ModuleOrder.clear();

		for (auto& moduleName : moduleOrder)
		{
			if (m_FeatureMap.count(moduleName) == 0)
				continue;

			m_ModuleOrder.push_back(moduleName);
			moduleSet.erase(moduleName);
		}

		for (auto& moduleName : moduleSet)
		{
			m_ModuleOrder.push_back(moduleName);
		}
	}

	void CheatManagerBase::DrawFps()
	{

		ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoFocusOnAppearing
			| ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize;

		if (!MoveGameFPS)
			flags |= ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoMove;

		if (ImGui::Begin("FPS", nullptr, flags))
		{
			static float values[120] = { 0 };
			static int values_offset = 0;
			values[values_offset++] = ImGui::GetIO().Framerate;
			if (values_offset >= IM_ARRAYSIZE(values))
				values_offset = 0;
			ImGui::PlotLines("", values, IM_ARRAYSIZE(values), values_offset, "", 0.0f, 100.0f, ImVec2(0, 80));
			ImGui::Text("%.1f FPS", ImGui::GetIO().Framerate);
			float avg_fps = 0.0f;
			for (int i = 0; i < IM_ARRAYSIZE(values); i++)
				avg_fps += values[i];
			avg_fps /= IM_ARRAYSIZE(values);
			ImGui::Text("%.1f FPS (avg)", avg_fps);
			ImGui::End();
		}
	}

	void CheatManagerBase::DrawMenuSection(const std::string& sectionName, const std::vector<Feature*>& features) const
	{
		if (!sectionName.empty())
		{
			if (ImGui::BeginGroupPanel(Text::GBKTOUTF8(sectionName).c_str(), true, { 0,0 }))
			{
				for (auto& feature : features)
				{
					ImGui::PushID(&feature);
					feature->DrawMain();
					ImGui::PopID();
				}
			}
			ImGui::EndGroupPanel();
		}
		else
		{
			for (auto& feature : features)
			{
				ImGui::PushID(&feature);
				feature->DrawMain();
				ImGui::PopID();
			}
		}
	}

	void CheatManagerBase::DrawStatus() const
	{
		// Drawing status window
		ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground |
			ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus |
			ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse;

		if (!MoveStatusFeature)
			flags |= ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoMove;

		ImGui::Begin("Cheat status", nullptr, flags);

		static ImGuiTableFlags tabFlags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;

		if (ImGui::BeginTable("activesTable", 1, tabFlags))
		{
			ImGui::TableSetupColumn(Text::GBKTOUTF8("启用功能").c_str());
			ImGui::TableHeadersRow();

			int row = 0;

			for (auto& feature : m_Features)
			{
				if (feature->NeedStatusDraw())
				{
					ImGui::TableNextRow();
					ImGui::TableSetColumnIndex(0);

					feature->DrawStatus();

					ImU32 row_bg_color = ImGui::GetColorU32(
						ImVec4(0.2f + row * 0.1f, 0.1f + row * 0.05f, 0.1f + row * 0.03f, 0.85f));
					ImGui::TableSetBgColor(ImGuiTableBgTarget_RowBg0, row_bg_color);
					row++;
				}
			}
			ImGui::EndTable();
		}

		ImGui::End();
	}
	
	void CheatManagerBase::Draw()
	{
		if (m_ModuleOrder.empty())
			return;
		ImGui::SetNextWindowSize({ 600,300 }, true);
		static std::string* current = &m_ModuleOrder[m_SelectedSection];
		if (ImGui::Begin("Dmmdzz Free Hack", nullptr, ImGuiWindowFlags_NoResize))
		{
			ImGui::BeginGroup();
			if (ImGui::Checkbox(Text::GBKTOUTF8("拦截键鼠消息").c_str(), &m_IsBlockingInput))
			{
				ImGui::SetInPutLock(this, m_IsBlockingInput);
			}
			if (ImGui::BeginListBox("##listbox 2", ImVec2(100, -FLT_MIN)))
			{
				size_t index = 0;
				for (auto& moduleName : m_ModuleOrder)
				{
					const bool is_selected = (current == &moduleName);
					if (ImGui::Selectable(Text::GBKTOUTF8(moduleName).c_str(), is_selected))
					{
						current = &moduleName;
						m_SelectedSection = index;
					}

					if (is_selected)
						ImGui::SetItemDefaultFocus();
					index++;
				}
				ImGui::Text(Text::GBKTOUTF8("频道:").c_str());
				ImGui::TextURL(Text::GBKTOUTF8("Discord").c_str(), "https://discord.gg/5TT7tM9aCB", true, false);
				ImGui::PushStyleColor(ImGuiCol_Button, ImGui::HexToRGBA("C93756"));
				ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImGui::HexToRGBA("F47983"));
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImGui::HexToRGBA("DB5A6B"));
				if (ImGui::Button(Text::GBKTOUTF8("卸载辅助").c_str()))
				{
					HookManager::detachAll(); //释放所有钩子
					DX11Hook::uninstallDX11Hook(); //释放函数钩子
					for (size_t i = 0; i < pch::m_hHandle.size(); i++)
					{
						TerminateThread(pch::m_hHandle[i], 0); //内存不安全操作 不会释放堆内存栈内存
					}
					FreeLibrary(pch::m_hModule); //释放自己
				}
				ImGui::PopStyleColor(3);
				ImGui::EndListBox();
			}
			ImGui::EndGroup();
			ImGui::SameLine();
			ImGui::BeginGroup();
			constexpr float width = 200.0f;
			ImGui::SetNextItemWidth(width);
			if (ImGui::BeginCombo(Text::GBKTOUTF8("配置").c_str(), jsonfile.c_str()))
			{
				if (ImGui::Selectable("TYPE-1")) { jsonfile = "TYPE-1"; }
				if (ImGui::Selectable("TYPE-2")) { jsonfile = "TYPE-2"; }
				if (ImGui::Selectable("TYPE-3")) { jsonfile = "TYPE-3"; }
				if (ImGui::Selectable("TYPE-4")) { jsonfile = "TYPE-4"; }
				ImGui::EndCombo();
			}
			ImGui::SameLine();
			if (ImGui::Button(Text::GBKTOUTF8("保存").c_str()))
			{
				std::vector<Feature*>::iterator iterator_Features = m_Features.begin();
				while (iterator_Features != m_Features.end())
				{
					(*iterator_Features)->save();
					iterator_Features++;
				}
			}
			ImGui::SameLine();
			if (ImGui::Button(Text::GBKTOUTF8("加载").c_str()))
			{
				std::vector<Feature*>::iterator iterator_Features = m_Features.begin();
				while (iterator_Features != m_Features.end())
				{
					(*iterator_Features)->load();
					iterator_Features++;
				}
			}
			ImGui::SameLine();
			if (ImGui::Button(Text::GBKTOUTF8("清空").c_str()))
			{
				std::ofstream file(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile);
				if (file)
				{
					file << "";
					file.close();
				}
			}
			ImGui::SameLine();
			if (ImGui::Button(Text::GBKTOUTF8("退出游戏").c_str()))
			{
				exit(0);
			}
			ImGui::SameLine();
			ImGui::Text("FPS:%0.1f", ImGui::GetIO().Framerate);
			ImGui::BeginChild("1", ImVec2(0, 0), true, ImGuiWindowFlags_None);

			auto& sections = m_FeatureMap[*current];
			auto emptyName = std::string();
			if (sections.count(emptyName) > 0)
				DrawMenuSection(emptyName, sections[""]);

			for (auto& [sectionName, features] : sections)
			{
				if (sectionName.empty())
					continue;

				DrawMenuSection(sectionName, features);
			}

			ImGui::EndChild();
			ImGui::EndGroup();
		}
		ImGui::End();

		if (ShowStatusFeature)
		{
			DrawStatus();
		}
		if (ShowGameFPS)
		{
			DrawFps();
		}
		std::vector<Feature*>::iterator iterator_Features = m_Features.begin();
		while (iterator_Features != m_Features.end())
		{
			(*iterator_Features)->Update();
			iterator_Features++;
		}
	}

	void DrawRenderer()
	{
		Mem.Draw();
	}
}
namespace cheat
{
	void Init()
	{
#define FEAT_INST(name) &cheat::feature::##name##::GetInstance()
		Mem.AddFeatures({
			FEAT_INST(AAC),
			FEAT_INST(About),
			FEAT_INST(Store),
			FEAT_INST(AACLog),
			FEAT_INST(setting),
			FEAT_INST(ItemList),
			FEAT_INST(PlayerList),
			FEAT_INST(BuyNoSub),
			FEAT_INST(AntiImmobility),
			FEAT_INST(PlayerVAC),
			FEAT_INST(NoFogOfWar)
			});
#undef FEAT_INST
		Mem.SetModuleOrder({
			"地图设置",
			"玩家设置",
			"实体设置",
			"其他设置",
			"辅助设置",
			"调试功能",
			"关于辅助",
			"用户协议"
			});
	}
}