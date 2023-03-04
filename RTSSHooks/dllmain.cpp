#include "main.h"
#include <TlHelp32.h>

static HANDLE WINAPI OpenProcess_NEW(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwProcessId)
{
	return (HANDLE)114514;
}

static HANDLE WINAPI CreateToolhelp32Snapshot_NEW(DWORD dwFlags, DWORD th32ProcessID)
{
	return (HANDLE)114514;
}

static int WINAPI MessageBoxW_NEW(HWND hWnd,LPCWSTR lpText,LPCWSTR lpCaption,UINT uType)
{
	return 1;
}

static SC_HANDLE WINAPI OpenServiceW_NEW(SC_HANDLE hSCManager, LPCWSTR lpServiceName, DWORD dwDesiredAccess)
{
	return (SC_HANDLE)114514;
}

static SC_HANDLE WINAPI OpenSCManagerW_NEW(LPCWSTR lpMachineName, LPCWSTR lpDatabaseName, DWORD dwDesiredAccess)
{
	return (SC_HANDLE)114514;
}

#define HOOK(func) \
		HookManager::install(func,func##_NEW)

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		//NO ACE Check
		HOOK(OpenProcess);
		HOOK(CreateToolhelp32Snapshot);
		HOOK(MessageBoxW);
		HOOK(OpenServiceW);
		HOOK(OpenSCManagerW);

		pch::m_hModule = hModule;
		pch::m_hHandle.push_back(CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)CheatMian::OnStart, NULL, NULL, NULL));
	}
	if (ul_reason_for_call == DLL_PROCESS_DETACH)
	{
		HookManager::detachAll();
		DX11Hook::uninstallDX11Hook();
	}
	return TRUE;
}