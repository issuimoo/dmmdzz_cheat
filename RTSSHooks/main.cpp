#include "main.h"
#include "renderer.h"
namespace CheatMian
{
	void OnStart()
	{
		Sleep(15000);

		Console::StartConsole("ÔÆÒÝ by ËìÄ­", false);

		printf(" __    __                    __    __        \n");
		printf("/\\ \\  /\\ \\                  /\\ \\  /\\ \\ __    \n");
		printf("\\ `\\`\\\\/'/ __  __    ___    \\ `\\`\\\\/'//\\_\\   \n");
		printf(" `\\ `\\ /' /\\ \\/\\ \\ /' _ `\\   `\\ `\\ /' \\/\\ \\  \n");
		printf("   `\\ \\ \\ \\ \\ \\_\\ \\/\\ \\/\\ \\    `\\ \\ \\  \\ \\ \\ \n");
		printf("     \\ \\_\\ \\ \\____/\\ \\_\\ \\_\\     \\ \\_\\  \\ \\_\\ \n");
		printf("      \\/_/  \\/___/  \\/_/\\/_/      \\/_/   \\/_/ \n\n");
		printf("---------------------------------------------\n");
		printf("ÔÆÒÝ by ËìÄ­\n");
		printf("Copyright (c) 2022 - 2023 ËìÄ­\n\n");

		LOGINFO("inject Succeeded!\n");
		LOGDEBUG(fmt::format("m_hModule:{}\n", (int)pch::m_hModule));

		pch::m_file = Process::GetModuleFile(pch::m_hModule);
		LOGDEBUG(fmt::format("m_file:{}\n", pch::m_file));

		LOGDEBUG(fmt::format("PID:{}\n", _getpid()));
		if (_getpid() != Process::GetProcessIdByName("dmmdzz_ace.exe"))
		{
			LOGERROR("Inject Error Process\n");
		}

		LOGINFO("Wait Module Load...\n");
		while (pch::GameAssembly == NULL)
		{
			pch::GameAssembly = GetModuleHandleA("GameAssembly.dll");
		}
		LOGDEBUG(fmt::format("GameAssembly:{}\n", (int)pch::GameAssembly));

		cheat::Init();

		DX11Hook::installDX11Hook(&renderer::DrawRenderer, pch::m_hModule, pch::m_file + "\\imgui.ini", 13, nullptr, &pch::DX11D3D11Device, &pch::DX11D3D11DeviceContext, &pch::DX11D3D11RenderTargetView, &pch::DX11SwapChain);
		ImGui::AnemoTheme();
	}
}