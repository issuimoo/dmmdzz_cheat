#include "main.h"
#include <TlHelp32.h>

static HANDLE(WINAPI* OpenProcess_OLD)(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwProcessId) = OpenProcess;
static HANDLE WINAPI OpenProcess_NEW(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwProcessId)
{
	return (HANDLE)114514;
}

static HANDLE(WINAPI* CreateToolhelp32Snapshot_OLD)(DWORD dwFlags,DWORD th32ProcessID) = CreateToolhelp32Snapshot;
static HANDLE WINAPI CreateToolhelp32Snapshot_NEW(DWORD dwFlags, DWORD th32ProcessID)
{
	return (HANDLE)114514;
}

static int (WINAPI* OLD_MessageBoxW)(HWND hWnd,LPCWSTR lpText,LPCWSTR lpCaption,UINT uType) = MessageBoxW;
static int WINAPI NEW_MessageBoxW(HWND hWnd,LPCWSTR lpText,LPCWSTR lpCaption,UINT uType)
{
	return 1;
}

static SC_HANDLE(WINAPI* OpenServiceW_OLD)(SC_HANDLE hSCManager,LPCWSTR lpServiceName,DWORD dwDesiredAccess) = OpenServiceW;
static SC_HANDLE WINAPI OpenServiceW_NEW(SC_HANDLE hSCManager, LPCWSTR lpServiceName, DWORD dwDesiredAccess)
{
	return (SC_HANDLE)114514;
}

static SC_HANDLE (WINAPI* OpenSCManagerW_OLD)(LPCWSTR lpMachineName,LPCWSTR lpDatabaseName,DWORD dwDesiredAccess) = OpenSCManagerW;
static SC_HANDLE WINAPI OpenSCManagerW_NEW(LPCWSTR lpMachineName, LPCWSTR lpDatabaseName, DWORD dwDesiredAccess)
{
	return (SC_HANDLE)114514;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		HookManager::install(OpenProcess_OLD, OpenProcess_NEW);
		HookManager::install(CreateToolhelp32Snapshot_OLD, CreateToolhelp32Snapshot_NEW);
		HookManager::install(OpenServiceW_OLD, OpenServiceW_NEW);
		HookManager::install(OpenSCManagerW_OLD, OpenSCManagerW_NEW);
		HookManager::install(OLD_MessageBoxW, NEW_MessageBoxW);
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