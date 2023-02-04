#include "Feature.hpp"

extern bool VAC;

namespace cheat::feature
{
	class PlayerVAC : public Feature
	{
	public:
		static PlayerVAC& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void save() override;
		void load() override;

		void Update() override;
	protected:
		PlayerVAC();
	};
}