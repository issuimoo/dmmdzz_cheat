#include "Feature.hpp"

extern bool AutoRecoverBlood_b;
extern std::vector<AutoRecoverable*> autorecoverable;

namespace cheat::feature
{
	class Blood : public Feature
	{
	public:
		static Blood& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void save() override;
		void load() override;

		void Update() override;
	protected:
		Blood();
	};
}