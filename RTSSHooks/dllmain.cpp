#include "main.h"
#include <TlHelp32.h>
#include <psapi.h>

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

static BOOL WINAPI CreateProcessW_NEW(LPCWSTR lpApplicationName, LPWSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCWSTR lpCurrentDirectory, LPSTARTUPINFOW lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation)
{
	return TRUE;
}

static BOOL WINAPI EnumProcessModules_NEW(HANDLE hProcess, HMODULE* lphModule, DWORD cb, LPDWORD lpcbNeeded)
{
	return TRUE;
}

static VOID WINAPI ExitProcess_NEW(UINT uExitCode)
{
	return;
}

static HMODULE WINAPI LoadLibraryA_NEW(LPCSTR lpLibFileName)
{
	return CALL_ORIGIN(LoadLibraryA_NEW, lpLibFileName);
}

#define HOOK(func) \
LOGINFO(fmt::format("Hooking [{}] {:#08x}\n",#func,(DWORD_PTR)func));\
HookManager::install(func,func##_NEW);

static HMODULE WINAPI LoadLibraryW_NEW(LPCWSTR lpLibFileName)
{
	HMODULE module = CALL_ORIGIN(LoadLibraryW_NEW, lpLibFileName);
	if (std::wstring(lpLibFileName).find(L"ACE-") != std::string::npos)
	{
		LOGWARNING(fmt::format("[LoadLibraryW] {} DLL Load! \n", Text::UTF8TOGBK(Text::UTF16TOUTF8(std::wstring(lpLibFileName).c_str()))));
	}
	return module;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		//NO ACE Check
		//HOOK(CreateProcessW);
		HOOK(OpenProcess);
		HOOK(CreateToolhelp32Snapshot);
		HOOK(MessageBoxW);
		HOOK(OpenServiceW);
		HOOK(OpenSCManagerW);
		HOOK(EnumProcessModules);
		HOOK(ExitProcess);
		HOOK(LoadLibraryW);
		HOOK(LoadLibraryA);
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