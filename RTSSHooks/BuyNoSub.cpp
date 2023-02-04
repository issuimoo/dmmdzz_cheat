#include "BuyNoSub.hpp"

namespace cheat::feature
{
	bool BuyAddCoin = true;

	static void PlayerController_RpcSubCoin_HOOK(PlayerController* _this, int coin, int reason, int cardId, unsigned int parameters);
	static void PlayerController_SubCoin_HOOK(PlayerController* _this, int coin, int reason, int cardId);

	BuyNoSub::BuyNoSub() : Feature()
	{
		app::PlayerController_RpcSubCoin = ((void(*)(PlayerController*, int, int, int, unsigned int))((unsigned int)pch::GameAssembly + Address_PlayerController_RpcSubCoin));
		app::PlayerController_SubCoin = ((void(*)(PlayerController*, int, int, int))((unsigned int)pch::GameAssembly + Address_PlayerController_SubCoin));

		HookManager::install(app::PlayerController_RpcSubCoin, PlayerController_RpcSubCoin_HOOK);
		HookManager::install(app::PlayerController_SubCoin, PlayerController_SubCoin_HOOK);
	}
	const FeatureGUIInfo& BuyNoSub::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "购物设置", "玩家设置", true };
		return info;
	}
	void BuyNoSub::DrawMain()
	{
		ImGui::Checkbox(Text::GBKTOUTF8("购物反加").c_str(), &BuyAddCoin);
	}
	bool BuyNoSub::NeedStatusDraw() const
	{
		return BuyAddCoin;
	}
	void BuyNoSub::DrawStatus()
	{
		if (BuyAddCoin)
		{
			ImGui::Text(Text::GBKTOUTF8("购物反加").c_str());
		}
	}
	void BuyNoSub::save()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}

		json["BuyAddCoin"] = BuyAddCoin;

		std::ofstream ofile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ofile)
		{
			ofile << json;
			ofile.close();
		}
	}
	void BuyNoSub::load()
	{
		nlohmann::json json;
		std::ifstream ifile(Process::GetModuleFile(pch::m_hModule) + "\\" + jsonfile + ".json");
		if (ifile)
		{
			ifile >> json;
			ifile.close();
		}
		if (json.find("BuyAddCoin") != json.end())
		{
			BuyAddCoin = json["BuyAddCoin"];
		}
	}
	BuyNoSub& BuyNoSub::GetInstance()
	{
		static BuyNoSub instance;
		return instance;
	}
	void BuyNoSub::Update()
	{
	}
	static void PlayerController_RpcSubCoin_HOOK(PlayerController* _this, int coin, int reason, int cardId, unsigned int parameters)
	{
		coin = -9999;
		return CALL_ORIGIN(PlayerController_RpcSubCoin_HOOK, _this, coin, reason, cardId, parameters);
	}
	static void PlayerController_SubCoin_HOOK(PlayerController* _this, int coin, int reason, int cardId)
	{
		coin = -9999;
		return CALL_ORIGIN(PlayerController_SubCoin_HOOK, _this, coin, reason, cardId);
	}
}