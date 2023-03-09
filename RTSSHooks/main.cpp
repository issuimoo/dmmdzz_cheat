#include "main.h"
#include "renderer.h"

BOOL stopDvr(const char* serviceName) {

	SC_HANDLE schSCManager = OpenSCManager(NULL,NULL,SC_MANAGER_ALL_ACCESS);
	if (schSCManager == NULL) {
		CloseServiceHandle(schSCManager);
		return FALSE;
	}
	SC_HANDLE hs = OpenService(schSCManager,serviceName,SERVICE_ALL_ACCESS);
	if (hs == NULL) 
{
		CloseServiceHandle(hs);
		CloseServiceHandle(schSCManager);
		return FALSE;
	}
	SERVICE_STATUS status;
	if (QueryServiceStatus(hs, &status) == 0) {
		CloseServiceHandle(hs);
		CloseServiceHandle(schSCManager);
		return FALSE;
	}
	if (status.dwCurrentState != SERVICE_STOPPED && status.dwCurrentState != SERVICE_STOP_PENDING) {
		if (ControlService(hs,SERVICE_CONTROL_STOP,&status) == 0) {
			CloseServiceHandle(hs);
			CloseServiceHandle(schSCManager);
			return FALSE;
		}
		INT timeOut = 0;
		while (status.dwCurrentState != SERVICE_STOPPED) {
			timeOut++;
			QueryServiceStatus(hs, &status);
			Sleep(50);
		}
		if (timeOut > 80) {
			CloseServiceHandle(hs);
			CloseServiceHandle(schSCManager);
			return FALSE;
		}
	}
	CloseServiceHandle(hs);
	CloseServiceHandle(schSCManager);
	return TRUE;
}

BOOL unloadDvr(const char* serviceName) {
	SC_HANDLE schSCManager = OpenSCManager(NULL,NULL,SC_MANAGER_ALL_ACCESS);
	if (schSCManager == NULL) {
		CloseServiceHandle(schSCManager);
		return FALSE;
	}
	SC_HANDLE hs = OpenService(schSCManager,serviceName,SERVICE_ALL_ACCESS);
	if (hs == NULL) {
		CloseServiceHandle(hs);
		CloseServiceHandle(schSCManager);
		return FALSE;
	}
	if (DeleteService(hs) == 0) {
		CloseServiceHandle(hs);
		CloseServiceHandle(schSCManager);
		return FALSE;
	}
	CloseServiceHandle(hs);
	CloseServiceHandle(schSCManager);
	return TRUE;
}

namespace CheatMian
{
	void OnStart()
	{
		Console::StartConsole("Logding ...", false);
		float Time = 5000;

		std::cout << "[info] Wait Game ... \n";
		for (size_t i = 0; i < Time; i++)
		{
			printf("\r[%i|%i]", i, (int)Time);
			for (size_t i2 = 0; i2 < (i / Time) * 10; i2++)
			{
				printf("■");
			}
			for (size_t i2 = 0; i2 < 10 - (i / Time) * 10; i2++)
			{
				printf("  ");
			}
			printf("%0.2f%%", ((float(i) / Time) * 100.0f));
			Sleep(1);
		}
		Console::EndConsole();

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

		
		printf("\r");

		LOGDEBUG(fmt::format("stopDvr [ACE-BASE]:{}\n", stopDvr("ACE-BASE")));
		LOGDEBUG(fmt::format("stopDvr [ACE-SSC-DRV64]:{}\n", stopDvr("ACE-SSC-DRV64")));
		LOGDEBUG(fmt::format("unloadDvr [ACE-BASE]:{}\n", unloadDvr("ACE-BASE")));
		LOGDEBUG(fmt::format("unloadDvr [ACE-SSC-DRV64]:{}\n", unloadDvr("ACE-SSC-DRV64")));

		LOGINFO("Wait Module Load...\n");
		while (pch::GameAssembly == NULL)
		{
			pch::GameAssembly = GetModuleHandleA("GameAssembly.dll");
		}
		LOGDEBUG(fmt::format("GameAssembly:{}\n", (int)pch::GameAssembly));

		cheat::Init();

		DX11Hook::installDX11Hook(&renderer::DrawRenderer, pch::m_hModule, ".\\imgui.ini", 13, nullptr, &pch::DX11D3D11Device, &pch::DX11D3D11DeviceContext, &pch::DX11D3D11RenderTargetView, &pch::DX11SwapChain);
		ImGui::AnemoTheme();
	}
}