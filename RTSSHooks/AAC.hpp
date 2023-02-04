#include "Feature.hpp"
namespace cheat::feature
{
	class AAC : public Feature
	{
	public:
		static AAC& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void save() override;
		void load() override;

		void Update() override;
	protected:
		AAC();
	};
}