#include "PlayerList.hpp"
#include "PlayerVAC.hpp"
#include "ItemList.hpp"
#include "Blood.hpp"

std::vector<PlayerController*> Vec_PlayerList;
PlayerController* m_PlayerController;

namespace cheat::feature
{
	static void PlayerController_Awake_Hook(PlayerController* _this);
	static void PlayerController_OnDestroy_Hook(PlayerController* _this);

	PlayerList::PlayerList() : Feature()
	{
		DO_HOOK(PlayerController_Awake);
		DO_HOOK(PlayerController_OnDestroy);
	}
	const FeatureGUIInfo& PlayerList::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "", "玩家设置", false };
		return info;
	}
	void PlayerList::DrawMain()
	{
		if (ImGui::CollapsingHeader(Text::GBKTOUTF8("玩家列表").c_str()))
		{
			if (ImGui::BeginTable("PlayerList", 3, ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_ScrollX | ImGuiTableFlags_ScrollY | ImGuiTableFlags_RowBg | ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersV | ImGuiTableFlags_Resizable | ImGuiTableFlags_Reorderable | ImGuiTableFlags_Hideable, ImVec2(0.0f, ImGui::GetTextLineHeightWithSpacing() * 13)))
			{
				ImGui::TableSetupScrollFreeze(0, 1);
				ImGui::TableSetupColumn(Text::GBKTOUTF8("操作").c_str(), ImGuiTableColumnFlags_None);
				ImGui::TableSetupColumn(Text::GBKTOUTF8("名称").c_str(), ImGuiTableColumnFlags_None);
				ImGui::TableSetupColumn(Text::GBKTOUTF8("[地址][血量][队友][本地][坐标][金币]").c_str(), ImGuiTableColumnFlags_None);
				ImGui::TableHeadersRow();
				for (size_t i = 0, max = Vec_PlayerList.size(); i < max; i++)
				{
					ImGui::TableNextRow(ImGuiTableRowFlags_None, 10);
					try
					{
						ImGui::PushID(Vec_PlayerList[i]); //必须加上不然按钮没效果
						Vector3 pos;
						AdrenalineObject AdrenalineObject_this;
						pos = AdrenalineObject_GetPlayerPos(&AdrenalineObject_this, Vec_PlayerList[i]);
						if (ImGui::TableSetColumnIndex(0))
						{
							if (!Vec_PlayerList[i]->m_IsLocalPlayer)
							{
								if (ImGui::SmallButton(Text::GBKTOUTF8("传送").c_str()))
								{
									PlayerController_SetPlayerPos(m_PlayerController, pos); //传送玩家
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
								PlayerController_InSameTeam(m_PlayerController, Vec_PlayerList[i]) ? ImColor(128, 195, 66, 255) : ImColor(233, 66, 66, 255),
								"[%i][%s]%s",
								i,
								Text::GBKTOUTF8(PlayerController_InSameTeam(m_PlayerController, Vec_PlayerList[i]) ? "友" : "敌").c_str(),
								Text::UTF16TOUTF8((wchar_t*)(&Vec_PlayerList[i]->m_NameText->m_Text->m_firstChar)).c_str()
							);
						}
						if (ImGui::TableSetColumnIndex(2))
						{
							ImGui::Text(fmt::format("[{:#X}][{:0.2f}][{}][{}][x:{:0.2f} y:{:0.2f} z:{:0.2f}][{}]", (unsigned int)Vec_PlayerList[i], Vec_PlayerList[i]->m_BattleProperties->life, PlayerController_InSameTeam(m_PlayerController, Vec_PlayerList[i]), Vec_PlayerList[i]->m_IsLocalPlayer, pos.x, pos.y, pos.z, PlayerController_get_CurCoin(Vec_PlayerList[i])).c_str());
						}
						ImGui::PopID();
					}
					catch (...)
					{
						continue;
					}
				}
				ImGui::EndTable();
			}
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
		for (size_t i = 0, max = Vec_PlayerList.size(); i < max; i++)
		{
			try
			{
				if (Vec_PlayerList[i]->m_IsLocalPlayer)
				{
					m_PlayerController = Vec_PlayerList[i];
				}
				else
				{
					if (VAC)
					{
						if (!PlayerController_InSameTeam(m_PlayerController, Vec_PlayerList[i]))
						{
							AdrenalineObject AdrenalineObject_this;
							Vector3 pos = AdrenalineObject_GetPlayerPos(&AdrenalineObject_this, m_PlayerController);
							pos.x -= x_p;
							PlayerController_SetPlayerPos(Vec_PlayerList[i], pos);
						}
					}
				}
			}
			catch (...)
			{
				continue;
			}
		}
	}

	static void PlayerController_Awake_Hook(PlayerController* _this)
	{
		Vec_PlayerList.push_back(_this);
		return CALL_ORIGIN(PlayerController_Awake_Hook, _this);
	}

	static void PlayerController_OnDestroy_Hook(PlayerController* _this)
	{
		if (Vec_PlayerList.size())
		{
			Vec_PlayerList.clear();
			m_PlayerController = nullptr;
			autorecoverable.clear();
		}
		return CALL_ORIGIN(PlayerController_OnDestroy_Hook, _this);
	}
}