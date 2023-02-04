#include "Feature.hpp"

namespace cheat::feature
{
	class BuyNoSub : public Feature
	{
	public:
		static BuyNoSub& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void save() override;
		void load() override;

		void Update() override;
	protected:
		BuyNoSub();
	};
}