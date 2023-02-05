#include "ItemList.hpp"

std::vector<UsableObject*> Vec_ItemList;

namespace cheat::feature
{
	static void UsableObject_Awake_Hook(UsableObject* _this);
	static void UsableObject_OnDestroy_Hook(UsableObject* _this);

	bool CloseHook = false;

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
		if (ImGui::CollapsingHeader(Text::GBKTOUTF8("物品列表").c_str()))
		{
			ImGui::Checkbox(Text::GBKTOUTF8("关闭Hook(解决因迭代而闪退)").c_str(), &CloseHook);
			if (ImGui::BeginTable("PlayerList", 3, ImGuiTableFlags_ScrollX | ImGuiTableFlags_ScrollY | ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable, ImVec2(0.0f, ImGui::GetTextLineHeightWithSpacing() * 13)))
			{
				ImGui::TableSetupScrollFreeze(0, 1);
				ImGui::TableSetupColumn(Text::GBKTOUTF8("地址").c_str(), ImGuiTableColumnFlags_None);
				ImGui::TableSetupColumn(Text::GBKTOUTF8("").c_str(), ImGuiTableColumnFlags_None);
				ImGui::TableSetupColumn(Text::GBKTOUTF8("").c_str(), ImGuiTableColumnFlags_None);
				ImGui::TableHeadersRow();
				if (!CloseHook)
				{
					try
					{
						auto ItemList_begin = Vec_ItemList.begin();
						auto ItemList_end = Vec_ItemList.end();
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
				}
				ImGui::EndTable();
			}
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
		if (!CloseHook)
		{
			Vec_ItemList.push_back(_this);
		}
		return CALL_ORIGIN(UsableObject_Awake_Hook, _this);
	}

	static void UsableObject_OnDestroy_Hook(UsableObject* _this)
	{
		if (!CloseHook)
		{
			try
			{
				auto ItemList_begin = Vec_ItemList.begin();
				auto ItemList_end = Vec_ItemList.end();
				while (ItemList_begin != ItemList_end)
				{
					if (*ItemList_begin == _this)
					{
						Vec_ItemList.erase(ItemList_begin);
						return CALL_ORIGIN(UsableObject_OnDestroy_Hook, _this);
					}
					ItemList_begin++;
				}
			}
			catch (...)
			{

			}
		}
		return CALL_ORIGIN(UsableObject_OnDestroy_Hook, _this);
	}
}