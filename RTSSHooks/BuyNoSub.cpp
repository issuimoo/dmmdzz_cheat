#include "BuyNoSub.hpp"

namespace cheat::feature
{
	bool BuyAddCoin = true;
	bool BuyAddCoin_ret = false;

	static void PlayerController_RpcSubCoin_Hook(PlayerController* _this, int coin, int reason, int cardId, unsigned int parameters);
	static void PlayerController_SubCoin_Hook(PlayerController* _this, int coin, int reason, int cardId);
	static void PlayerControllerRpcProxy_LocalSubCoin_Hook(PlayerControllerRpcProxy* _this, int coin, int reason, int param);

	BuyNoSub::BuyNoSub() : Feature()
	{
		DO_HOOK(PlayerController_RpcSubCoin);
		DO_HOOK(PlayerController_SubCoin);
		DO_HOOK(PlayerControllerRpcProxy_LocalSubCoin);
	}
	const FeatureGUIInfo& BuyNoSub::GetGUIInfo() const
	{
		static const FeatureGUIInfo info{ "购物设置", "玩家设置", true };
		return info;
	}
	void BuyNoSub::DrawMain()
	{
		ImGui::Checkbox(Text::GBKTOUTF8("购物不减").c_str(), &BuyAddCoin);
		if (BuyAddCoin)
		{
			ImGui::Indent();
			ImGui::Checkbox(Text::GBKTOUTF8("拦截模式").c_str(), &BuyAddCoin_ret);
			ImGui::Unindent();
		}
	}
	bool BuyNoSub::NeedStatusDraw() const
	{
		return BuyAddCoin;
	}
	void BuyNoSub::DrawStatus()
	{
		if (BuyAddCoin)
		{
			ImGui::Text(Text::GBKTOUTF8(fmt::format("购物不减[{}]", BuyAddCoin_ret ? "R" : "C")).c_str());
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
	static void PlayerController_RpcSubCoin_Hook(PlayerController* _this, int coin, int reason, int cardId, unsigned int parameters)
	{
		LOGDEBUG(fmt::format("PlayerController_RpcSubCoin_Hook-> coin: {} reason:{} cardId:{} parameters:{}\n", (int)_this, coin, reason, cardId, parameters));
		if (BuyAddCoin_ret)
		{
			return;
		}
		if (BuyAddCoin)
		{
			return CALL_ORIGIN(PlayerController_SubCoin_Hook, _this, 0, reason, cardId);
		}
		return CALL_ORIGIN(PlayerController_RpcSubCoin_Hook, _this, coin, reason, cardId, parameters);
	}
	static void PlayerController_SubCoin_Hook(PlayerController* _this, int coin, int reason, int cardId)
	{
		LOGDEBUG(fmt::format("PlayerController_SubCoin_Hook->coin: {} reason:{} cardId:{}\n", (int)_this, coin, reason, cardId));
		if (BuyAddCoin_ret)
		{
			return;
		}
		if (BuyAddCoin)
		{
			return CALL_ORIGIN(PlayerController_SubCoin_Hook, _this, 0, reason, cardId);
		}
		return CALL_ORIGIN(PlayerController_SubCoin_Hook, _this, coin, reason, cardId);
	}
	static void PlayerControllerRpcProxy_LocalSubCoin_Hook(PlayerControllerRpcProxy* _this, int coin, int reason, int param)
	{
		LOGDEBUG(fmt::format("PlayerControllerRpcProxy_LocalSubCoin_Hook->coin: {} reason:{} param:{}\n", (int)_this, coin, reason, param));
		if (BuyAddCoin_ret)
		{
			return;
		}
		if (BuyAddCoin)
		{
			return CALL_ORIGIN(PlayerControllerRpcProxy_LocalSubCoin_Hook, _this, 0, reason, param);
		}
		return CALL_ORIGIN(PlayerControllerRpcProxy_LocalSubCoin_Hook, _this, coin, reason, param);
	}
}