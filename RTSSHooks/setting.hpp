#include "Feature.hpp"

extern bool ShowStatusFeature;
extern bool MoveStatusFeature;
extern bool ShowGameFPS;
extern bool MoveGameFPS;

extern bool ShowImGuiDemo;
extern bool ShowImPlotDemo;

namespace cheat::feature
{
	class setting : public Feature
	{
	public:
		static setting& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void save() override;
		void load() override;

		void Update() override;
	protected:
		setting();
	};
}