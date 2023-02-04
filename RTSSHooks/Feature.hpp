#pragma once

#include "il2cpp-appdata.h"
#include "API-Address.h++"

#include "pch.h"

using namespace app;

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