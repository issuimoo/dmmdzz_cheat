#include "Store.hpp"

std::vector<InGameStore*> Vec_StoreList;

namespace cheat::feature
{
	static void InGameStore_Awake_Hook(InGameStore* _this);
	static void InGameStore_OnDestroy_Hook(InGameStore* _this);

	Store::Store() : Feature()
	{
		app::InGameStore_Awake = (void(*)(InGameStore*))(((unsigned int)pch::GameAssembly) + Address_InGameStore_Awake);
		app::InGameStore_OnDestroy = (void(*)(InGameStore*))(((unsigned int)pch::GameAssembly) + Address_InGameStore_OnDestroy);

		HookManager::install(app::InGameStore_Awake, InGameStore_Awake_Hook);
		HookManager::install(app::InGameStore_OnDestroy, InGameStore_OnDestroy_Hook);
	}
	const FeatureGUIInfo& Store::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "", "其他设置", false };
		return info;
	}
	void Store::DrawMain()
	{
		if (ImGui::CollapsingHeader(Text::GBKTOUTF8("商品列表").c_str()))
		{
			if (ImGui::BeginTable("StoreList", 3, ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_ScrollX | ImGuiTableFlags_ScrollY | ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable, ImVec2(0.0f, ImGui::GetTextLineHeightWithSpacing() * 13)))
			{
				ImGui::TableSetupScrollFreeze(0, 1);
				ImGui::TableSetupColumn(Text::GBKTOUTF8("").c_str(), ImGuiTableColumnFlags_None);
				ImGui::TableSetupColumn(Text::GBKTOUTF8("").c_str(), ImGuiTableColumnFlags_None);
				ImGui::TableSetupColumn(Text::GBKTOUTF8("地址").c_str(), ImGuiTableColumnFlags_None);
				ImGui::TableHeadersRow();
				try
				{
					auto ItemList_begin = Vec_StoreList.begin();
					auto ItemList_end = Vec_StoreList.end();
					while (ItemList_begin != ItemList_end)
					{
						ImGui::TableNextRow();
						ImGui::TableSetColumnIndex(0);
						ImGui::Text("%i", (unsigned int)*ItemList_begin);
						ImGui::TableSetColumnIndex(1);
						//ImGui::Text("%s", Text::UTF16TOUTF8((wchar_t*)(&(*iterator_ItemList)->m_NameText->m_Text->m_firstChar)).c_str());
						ImGui::TableSetColumnIndex(2);
						//ImGui::Text(fmt::format("[{:0.2f}][{}]", (*iterator_PlayerList)->m_BattleProperties->life, (*iterator_PlayerList)->m_IsLocalPlayer).c_str());
						ItemList_begin++;
					}
				}
				catch (...)
				{

				}
				ImGui::EndTable();
			}
		}
	}
	bool Store::NeedStatusDraw() const
	{
		return false;
	}
	void Store::DrawStatus()
	{
	}
	void Store::save()
	{
	}
	void Store::load()
	{
	}
	Store& Store::GetInstance()
	{
		static Store instance;
		return instance;
	}
	void Store::Update()
	{

	}

	static void InGameStore_Awake_Hook(InGameStore* _this)
	{
		Vec_StoreList.push_back(_this);
		LOGDEBUG(fmt::format("InGameStore_Awake_Hook-> _this: {}\n", (int)_this));
		return CALL_ORIGIN(InGameStore_Awake_Hook, _this);
	}
	static void InGameStore_OnDestroy_Hook(InGameStore* _this)
	{
		LOGDEBUG(fmt::format("InGameStore_OnDestroy_Hook-> _this: {}\n", (int)_this));
		auto StoreList_begin = Vec_StoreList.begin();
		auto StoreList_end = Vec_StoreList.end();
		while (StoreList_begin != StoreList_end)
		{
			if (*StoreList_begin == _this)
			{
				Vec_StoreList.erase(StoreList_begin);
				return CALL_ORIGIN(InGameStore_OnDestroy_Hook, _this);
			}
			StoreList_begin++;
		}
		return CALL_ORIGIN(InGameStore_OnDestroy_Hook, _this);
	}
}