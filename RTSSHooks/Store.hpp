#include "Feature.hpp"

extern std::vector<InGameStore*> Vec_StoreList;

namespace cheat::feature
{
	class Store : public Feature
	{
	public:
		static Store& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void save() override;
		void load() override;

		void Update() override;
	protected:
		Store();
	};
}