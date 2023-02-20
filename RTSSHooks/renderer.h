#pragma once
#include "pch.h"
#include "Feature.hpp"
#include <vector>
#include <map>
#include <string>
#include <Windows.h>
using namespace cheat;
namespace renderer
{
	void DrawRenderer();

	class CheatManagerBase
	{
	public:
		void Draw();
		void AddFeature(Feature* feature);
		void AddFeatures(std::vector<Feature*> features);
		void SetModuleOrder(std::vector<std::string> moduleOrder);

		std::vector<Feature*> m_Features;
	protected:
		std::vector<std::string> m_ModuleOrder;
		std::map<std::string, std::map<std::string, std::vector<Feature*>>> m_FeatureMap;

		size_t m_SelectedSection;

		bool m_IsBlockingInput;

		void PushFeature(Feature* feature);
		void DrawMenuSection(const std::string& sectionName, const std::vector<Feature*>& features) const;
		void DrawStatus() const;
		void DrawFps();
	};
}

void FUNC_Init();