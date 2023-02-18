#include "pch.h"

BOOL CopyVirtualProtect(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD& lpflOldProtect);