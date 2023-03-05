#pragma once

#include "il2cpp-Iint.hpp"

#define DO_HOOK(GAMEFUNC) \
LOGINFO(fmt::format("[Hook] Func: {} Address: {:#08x}\n",#GAMEFUNC,(DWORD)GAMEFUNC)); \
HookManager::install(GAMEFUNC,GAMEFUNC##_Hook);

extern std::string jsonfile;

namespace cheat
{
	struct FeatureGUIInfo
	{
		std::string name;
		std::string moduleName;
		bool isGroup;
	};

	class Feature
	{
	public:
		Feature(Feature const&) = delete;
		void operator=(Feature const&) = delete;

		virtual const FeatureGUIInfo& GetGUIInfo() const = 0;

		virtual void DrawMain() = 0;

		virtual bool NeedStatusDraw() const { return false; };
		virtual void DrawStatus() { };

		virtual void save() {};
		virtual void load() {};

		virtual void Update() {};

	protected:
		Feature() { };
	};

	void Init();

	static std::string ver = "1.0.0";
}