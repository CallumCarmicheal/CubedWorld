#include <windows.h>
#include <fcntl.h>
#include <stdio.h>
#include <io.h>
#include <string>

#pragma once
class Cave {
public:
	static BOOL APIENTRY DllMain(HMODULE hModule, DWORD ulReason, LPVOID lpReserved);
	static VOID WriteBytesASM(DWORD destAddress, LPVOID patch, DWORD numBytes);
	static void Codecave(DWORD destAddress, VOID(*func)(VOID), BYTE nopCount);
};

