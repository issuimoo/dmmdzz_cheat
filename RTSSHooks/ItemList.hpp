#include "Feature.hpp"

struct  UsableObject_Info
{
	UsableObject* _this;
	bool  _isDisposed;
};

extern std::vector<UsableObject_Info> Vec_ItemList;

namespace cheat::feature
{
	class ItemList : public Feature
	{
	public:
		static ItemList& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void save() override;
		void load() override;

		void Update() override;
	protected:
		ItemList();
	};
}