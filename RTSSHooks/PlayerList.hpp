#include "Feature.hpp"

extern std::vector<PlayerController*> Vec_PlayerList;
extern PlayerController* m_PlayerController;

namespace cheat::feature
{
	class PlayerList : public Feature
	{
	public:
		static PlayerList& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void save() override;
		void load() override;

		void Update() override;
	protected:
		PlayerList();
	};
}