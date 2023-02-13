#include "Feature.hpp"

extern std::vector<std::string> AACLogs;

namespace cheat::feature
{
	class AACLog : public Feature
	{
	public:
		static AACLog& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

		bool NeedStatusDraw() const override;
		void DrawStatus() override;

		void save() override;
		void load() override;

		void Update() override;
	protected:
		AACLog();
	};
}