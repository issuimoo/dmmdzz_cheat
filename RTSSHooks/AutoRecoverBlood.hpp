#include "Feature.hpp"

extern bool AutoRecoverBlood_b;
extern std::vector<app::AutoRecoverable*> autorecoverable;

namespace cheat::feature
{
	class AutoRecoverBlood : public Feature
	{
	public:
		static AutoRecoverBlood& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void save() override;
		void load() override;

		void Update() override;
	protected:
		AutoRecoverBlood();
	};
}