#include "main.h"
#include "renderer.h"

namespace CheatMian
{
	void OnStart()
	{

		Sleep(15000);

		Console::StartConsole("云逸 by 遂沫", false);

		printf(" __    __                    __    __        \n");
		printf("/\\ \\  /\\ \\                  /\\ \\  /\\ \\ __    \n");
		printf("\\ `\\`\\\\/'/ __  __    ___    \\ `\\`\\\\/'//\\_\\   \n");
		printf(" `\\ `\\ /' /\\ \\/\\ \\ /' _ `\\   `\\ `\\ /' \\/\\ \\  \n");
		printf("   `\\ \\ \\ \\ \\ \\_\\ \\/\\ \\/\\ \\    `\\ \\ \\  \\ \\ \\ \n");
		printf("     \\ \\_\\ \\ \\____/\\ \\_\\ \\_\\     \\ \\_\\  \\ \\_\\ \n");
		printf("      \\/_/  \\/___/  \\/_/\\/_/      \\/_/   \\/_/ \n\n");
		printf("---------------------------------------------\n");
		printf("云逸 by 遂沫\n");
		printf("Copyright (c) 2022 - 2023 遂沫\n\n");

		LOGINFO("Wait Module Load...\n");
		while (pch::GameAssembly == NULL)
		{
			pch::GameAssembly = GetModuleHandleA("GameAssembly.dll");
		}
		LOGDEBUG(fmt::format("GameAssembly:{}\n", (int)pch::GameAssembly));

		FUNC_Init();
		cheat::Init();

		DX11Hook::installDX11Hook(&renderer::DrawRenderer, pch::m_hModule, pch::m_file + "\\imgui.ini", 13, nullptr, &pch::DX11D3D11Device, &pch::DX11D3D11DeviceContext, &pch::DX11D3D11RenderTargetView, &pch::DX11SwapChain);
		ImGui::AnemoTheme();
	}
}