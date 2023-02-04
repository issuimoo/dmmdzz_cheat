#pragma once
#include <ImGuiDx11Hook.hpp>
#include <json.hpp>
#include <Process.hpp>
#include <Console.hpp>
#include <Text.hpp>
#include <detours.h>
#include <fmt/format.h>
#include <magic_enum.hpp>
#include <SimpleIni.h>
#include <unordered_set>
#include <HookManager.h>
#include <magic_enum.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <iosfwd>
#include <fstream>
#include <ostream>

namespace pch
{
	static HMODULE m_hModule;
	static std::string m_file;
	extern std::vector<HANDLE> m_hHandle;
	extern HMODULE GameAssembly;
	static ID3D11Device* DX11D3D11Device;
	static ID3D11DeviceContext* DX11D3D11DeviceContext;
	static ID3D11RenderTargetView* DX11D3D11RenderTargetView;
	static IDXGISwapChain* DX11SwapChain;
}