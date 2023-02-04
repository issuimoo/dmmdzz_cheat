#include "ItemList.hpp"

std::vector<UsableObject*> Vec_ItemList;

namespace cheat::feature
{
	static void UsableObject_Awake_Hook(UsableObject* _this);
	static void UsableObject_OnDestroy_Hook(UsableObject* _this);

	ItemList::ItemList() : Feature()
	{
		app::UsableObject_Awake = (void(*)(UsableObject*))(((unsigned int)pch::GameAssembly) + Address_UsableObject_Awake);
		app::UsableObject_OnDestroy = (void(*)(UsableObject*))(((unsigned int)pch::GameAssembly) + Address_UsableObject_OnDestroy);

		HookManager::install(app::UsableObject_Awake, UsableObject_Awake_Hook);
		HookManager::install(app::UsableObject_OnDestroy, UsableObject_OnDestroy_Hook);
	}
	const FeatureGUIInfo& ItemList::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "", "实体设置", false };
		return info;
	}
	void ItemList::DrawMain()
	{
		if (ImGui::BeginTable("PlayerList", 3, ImGuiTableFlags_ScrollX | ImGuiTableFlags_ScrollY | ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable, ImVec2(0.0f, ImGui::GetTextLineHeightWithSpacing() * 13)))
		{
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableSetupColumn(Text::GBKTOUTF8("地址").c_str(), ImGuiTableColumnFlags_None);
			ImGui::TableSetupColumn(Text::GBKTOUTF8("").c_str(), ImGuiTableColumnFlags_None);
			ImGui::TableSetupColumn(Text::GBKTOUTF8("").c_str(), ImGuiTableColumnFlags_None);
			ImGui::TableHeadersRow();
			try
			{
				std::vector<UsableObject*>::iterator iterator_ItemList = Vec_ItemList.begin();
				while (iterator_ItemList != Vec_ItemList.end())
				{
					ImGui::TableNextRow();
					ImGui::TableSetColumnIndex(0);
					ImGui::Text("%i", (unsigned int)(*iterator_ItemList));
					ImGui::TableSetColumnIndex(1);
					//ImGui::Text("%s", Text::UTF16TOUTF8((wchar_t*)(&(*iterator_ItemList)->m_NameText->m_Text->m_firstChar)).c_str());
					ImGui::TableSetColumnIndex(2);
					//ImGui::Text(fmt::format("[{:0.2f}][{}]", (*iterator_PlayerList)->m_BattleProperties->life, (*iterator_PlayerList)->m_IsLocalPlayer).c_str());
					iterator_ItemList++;
				}
			}
			catch (...)
			{
			}

			ImGui::EndTable();
		}
	}
	bool ItemList::NeedStatusDraw() const
	{
		return false;
	}
	void ItemList::DrawStatus()
	{
	}
	void ItemList::save()
	{
	}
	void ItemList::load()
	{
	}
	ItemList& ItemList::GetInstance()
	{
		static ItemList instance;
		return instance;
	}
	void ItemList::Update()
	{
		
	}

	static void UsableObject_Awake_Hook(UsableObject* _this)
	{
		Vec_ItemList.push_back(_this);
		return CALL_ORIGIN(UsableObject_Awake_Hook, _this);
	}

	static void UsableObject_OnDestroy_Hook(UsableObject* _this)
	{
		try
		{
			std::vector<UsableObject*>::iterator iterator_ItemList = Vec_ItemList.begin();
			while (iterator_ItemList != Vec_ItemList.end())
			{
				if ((*iterator_ItemList) == _this)
				{
					Vec_ItemList.erase(iterator_ItemList);
				}
				iterator_ItemList++;
			}
		}
		catch (...)
		{

		}
		return CALL_ORIGIN(UsableObject_OnDestroy_Hook, _this);
	}
}