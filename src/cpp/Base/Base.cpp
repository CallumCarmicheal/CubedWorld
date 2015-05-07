#include <windows.h>
#include <fcntl.h>
#include <stdio.h>
#include <io.h>
#include <string>

#include "Cave.h"
#include "Console.h"
#include "Events.h"

using namespace std;

DWORD regenAmount = 0;
Events* evt = new Events();

// codecave "__declspec(naked)" function
__declspec(naked) void CC_ExtractScore(void) {

	__asm {
		MOVSS regenAmount, XMM0
	}

	evt->onPlayerEat(*(float*)regenAmount);

	__asm {
		// execute whatever code we took out for the codecave.
		MOVSS DWORD PTR DS : [ESI + 0x16C], XMM0
		ret
	}
}

extern "C" __declspec(dllexport) void Initialize()
{
	Console::Create();

	// Trying to find the correct address for the <Cube.onPlayerEat>
	Cave::Codecave(0x00267347, CC_ExtractScore, 1);
}