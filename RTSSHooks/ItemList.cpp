#include "ItemList.hpp"

vector_thl<UsableObject*> Vec_ItemList;

namespace cheat::feature
{
	static void UsableObject_Awake_Hook(UsableObject* _this);
	static void UsableObject_OnDestroy_Hook(UsableObject* _this);

	ItemList::ItemList() : Feature()
	{
		Vec_ItemList.vec.reserve(300);
		DO_HOOK(UsableObject_Awake);
		DO_HOOK(UsableObject_OnDestroy);
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
			if (ImGui::BeginTable("PlayerList", 3, ImGuiTableFlags_SizingFixedFit |  ImGuiTableFlags_ScrollX | ImGuiTableFlags_ScrollY | ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable, ImVec2(0.0f, ImGui::GetTextLineHeightWithSpacing() * 13)))
			{
				ImGui::TableSetupScrollFreeze(0, 1);
				ImGui::TableSetupColumn(Text::GBKTOUTF8("地址").c_str(), ImGuiTableColumnFlags_None);
				ImGui::TableSetupColumn(Text::GBKTOUTF8("").c_str(), ImGuiTableColumnFlags_None);
				ImGui::TableSetupColumn(Text::GBKTOUTF8("").c_str(), ImGuiTableColumnFlags_None);
				ImGui::TableHeadersRow();
				try
				{
					std::vector<UsableObject*> _ItemList;
					Vec_ItemList.getVector(_ItemList);
					auto ItemList_begin = _ItemList.begin();
					auto ItemList_end = _ItemList.end();
					while (ItemList_begin != ItemList_end)
					{
						ImGui::TableNextRow();
						ImGui::TableSetColumnIndex(0);
						ImGui::Text(fmt::format("{:#08x}",(DWORD)*ItemList_begin).c_str());
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
			auto ItemList_begin = Vec_ItemList.vec.begin();
			auto ItemList_end = Vec_ItemList.vec.end();
			while (ItemList_begin != ItemList_end)
			{
				if (*ItemList_begin == _this)
				{
					Vec_ItemList.vec.erase(ItemList_begin);
					return CALL_ORIGIN(UsableObject_OnDestroy_Hook, _this);
				}
				ItemList_begin++;
			}
			Vec_ItemList.merge();
		}
		catch (...)
		{

		}
		return CALL_ORIGIN(UsableObject_OnDestroy_Hook, _this);
	}
}