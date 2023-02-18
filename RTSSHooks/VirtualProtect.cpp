#include "VirtualProtect.Hpp"

void* NtdllAddress = GetProcAddress(GetModuleHandleA("ntdll.dll"), "RtlInterlockedCompareExchange64");
void* KernelAddress = GetProcAddress(GetModuleHandleA("kernel.dll"), "GetSystemLeapSecondInformation");

DWORD ntdll170 = (DWORD)NtdllAddress + 0x170;
DWORD KernelEC85 = (DWORD)KernelAddress + 0xEC85;

void __declspec(naked) CopyZwVirtualProtect()
{
	__asm
	{
		mov eax, 0x50
		mov edx, ntdll170
		call edx
		ret 0x14
	}
}

BOOL __declspec(naked) __cdecl CopyVirtualProtec_(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect)
{
	__asm
	{
		mov edi, edi
		push ebp
		mov ebp, esp
		push ecx
		push ecx
		mov eax, [ebp + 0xC]
		push esi
		push[ebp + 0x14]
		mov[ebp - 4], eax
		push[ebp + 0x10]
		mov eax, [ebp + 8]
		mov[ebp - 8], eax
		lea eax, [ebp - 4]
		push eax
		lea eax, [ebp - 8]
		push eax
		push - 1
		call CopyZwVirtualProtect
		mov esi, eax
		test esi, esi
		js KK
		xor eax, eax
		inc eax
		pop esi
		leave
		ret 0x10

		KK:
		jmp KernelEC85
	}
}

BOOL CopyVirtualProtect(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD& lpflOldProtect)
{
	return CopyVirtualProtec_(lpAddress, dwSize, flNewProtect, lpflOldProtect);
}