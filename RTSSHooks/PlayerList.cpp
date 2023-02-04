#include "PlayerList.hpp"

std::vector<PlayerController*> Vec_PlayerList;
PlayerController* m_PlayerController;

#include "ItemList.hpp"
#include "PlayerVAC.hpp"

namespace cheat::feature
{
	static void PlayerController_Awake_Hook(PlayerController* _this);
	static void PlayerController_OnDestroy_Hook(PlayerController* _this);

	PlayerList::PlayerList() : Feature()
	{
		app::PlayerController_Awake = (void(*)(PlayerController*))(((unsigned int)pch::GameAssembly) + Address_PlayerController_Awake);
		app::PlayerController_OnDestroy = (void(*)(PlayerController*))(((unsigned int)pch::GameAssembly) + Address_PlayerController_OnDestroy);
		app::AdrenalineObject_GetPlayerPos = (Vector3(*)(AdrenalineObject*, PlayerController*))(((unsigned int)pch::GameAssembly) + Address_AdrenalineObject_GetPlayerPos);
		app::PlayerController_SetPlayerPos = (void(*)(PlayerController*,Vector3))(((unsigned int)pch::GameAssembly) + Address_PlayerController_SetPlayerPos);
		app::PlayerController_get_CurCoin = (int(*)(PlayerController*))(((unsigned int)pch::GameAssembly) + Address_PlayerController_get_CurCoin);
		app::PlayerController_InSameTeam = (bool(*)(PlayerController*, PlayerController*))(((unsigned int)pch::GameAssembly) + Address_PlayerController_InSameTeam);


		HookManager::install(app::PlayerController_Awake, PlayerController_Awake_Hook);
		HookManager::install(app::PlayerController_OnDestroy, PlayerController_OnDestroy_Hook);
	}
	const FeatureGUIInfo& PlayerList::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "", "玩家设置", false };
		return info;
	}
	void PlayerList::DrawMain()
	{
		if (ImGui::BeginTable("PlayerList", 3, ImGuiTableFlags_ScrollX | ImGuiTableFlags_ScrollY | ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable, ImVec2(0.0f, ImGui::GetTextLineHeightWithSpacing() * 13)))
		{
			ImGui::TableSetupScrollFreeze(0, 1);
			ImGui::TableSetupColumn(Text::GBKTOUTF8("操作").c_str(), ImGuiTableColumnFlags_None);
			ImGui::TableSetupColumn(Text::GBKTOUTF8("名称").c_str(), ImGuiTableColumnFlags_None);
			ImGui::TableSetupColumn(Text::GBKTOUTF8("[地址][血量][队友][本地][坐标][金币]").c_str(), ImGuiTableColumnFlags_None);
			ImGui::TableHeadersRow();
			try
			{
				std::vector<PlayerController*>::iterator iterator_PlayerList = Vec_PlayerList.begin();
				while (iterator_PlayerList != Vec_PlayerList.end())
				{
					ImGui::PushID(*iterator_PlayerList); //必须加上不然按钮没效果
					AdrenalineObject AdrenalineObject_this;
					Vector3 pos = app::AdrenalineObject_GetPlayerPos(&AdrenalineObject_this, (*iterator_PlayerList));
					ImGui::TableNextRow();
					if (ImGui::TableSetColumnIndex(0))
					{
						if (!(*iterator_PlayerList)->m_IsLocalPlayer)
						{
							if (ImGui::SmallButton(Text::GBKTOUTF8("传送").c_str()))
							{
								app::PlayerController_SetPlayerPos(m_PlayerController, pos); //传送玩家
							}
						}
						else
						{
							ImGui::Text(Text::GBKTOUTF8("自己").c_str());
						}
					}
					if (ImGui::TableSetColumnIndex(1))
					{
						ImGui::TextColored(
							app::PlayerController_InSameTeam(m_PlayerController, (*iterator_PlayerList)) ? ImColor(128, 195, 66, 255) : ImColor(233, 66, 66, 255),
							"[%s]%s",
							Text::GBKTOUTF8(app::PlayerController_InSameTeam(m_PlayerController, (*iterator_PlayerList)) ? "友" : "敌").c_str(),
							Text::UTF16TOUTF8((wchar_t*)(&(*iterator_PlayerList)->m_NameText->m_Text->m_firstChar)).c_str()
						);
					}
					if (ImGui::TableSetColumnIndex(2))
					{
						ImGui::Text(fmt::format("[{}][{:0.2f}][{}][{}][x:{:0.2f} y:{:0.2f} z:{:0.2f}][{}]", (unsigned int)(*iterator_PlayerList), (*iterator_PlayerList)->m_BattleProperties->life, app::PlayerController_InSameTeam(m_PlayerController, (*iterator_PlayerList)), (*iterator_PlayerList)->m_IsLocalPlayer, pos.x, pos.y, pos.z, app::PlayerController_get_CurCoin(*iterator_PlayerList)).c_str());
					}
					ImGui::PopID();
					iterator_PlayerList++;
				}
			}
			catch (...)
			{
			}

			ImGui::EndTable();
		}
	}
	bool PlayerList::NeedStatusDraw() const
	{
		return false;
	}
	void PlayerList::DrawStatus()
	{
	}
	void PlayerList::save()
	{
	}
	void PlayerList::load()
	{
	}
	PlayerList& PlayerList::GetInstance()
	{
		static PlayerList instance;
		return instance;
	}
	void PlayerList::Update()
	{
		try
		{
			std::vector<PlayerController*>::iterator iterator_PlayerList = Vec_PlayerList.begin();
			while (iterator_PlayerList != Vec_PlayerList.end())
			{
				if ((*iterator_PlayerList)->m_IsLocalPlayer)
				{
					m_PlayerController = *iterator_PlayerList;
				}
				else
				{
					if (VAC)
					{
						if (!app::PlayerController_InSameTeam(m_PlayerController, (*iterator_PlayerList)))
						{
							AdrenalineObject AdrenalineObject_this;
							Vector3 pos = app::AdrenalineObject_GetPlayerPos(&AdrenalineObject_this, m_PlayerController);
							pos.x -= 1;
							app::PlayerController_SetPlayerPos((*iterator_PlayerList), pos);
						}
					}
				}
				iterator_PlayerList++;
			}
		}
		catch (...)
		{

		}
	}

	static void PlayerController_Awake_Hook(PlayerController* _this)
	{
		Vec_PlayerList.push_back(_this);
		return CALL_ORIGIN(PlayerController_Awake_Hook, _this);
	}

	static void PlayerController_OnDestroy_Hook(PlayerController* _this)
	{
		Vec_PlayerList.clear();
		Vec_ItemList.clear();
		m_PlayerController = nullptr;
		return CALL_ORIGIN(PlayerController_OnDestroy_Hook, _this);
	}
}