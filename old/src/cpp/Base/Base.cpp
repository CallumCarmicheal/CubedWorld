#include "stdafx.h"

#include "Cave.h"
#include "Console.h"
#include "stdafx.h"
#include "Events.h"

using namespace std;

DWORD regenAmount = 0;
//Events* evt = new Events();

// codecave "__declspec(naked)" function
/*__declspec(naked) void CC_ExtractScore(void) {
	__asm {
		MOVSS regenAmount, XMM0
	}

	//evt->onPlayerEat(*(float*)regenAmount);

	__asm {
		MOVSS DWORD PTR DS : [ESI + 0x16C], XMM0
			ret
	}
}*/


DWORD distance__ = 1337;
void ExtractRD() {
	Console::WriteLineF("DIST: %i", distance__);
}


DWORD _REGISTER_RETURN_ADDR = 0;
// codecave "__declspec(naked)" function
__declspec(naked) void CC_ExtractRD(void) {

	// Save our registers state
	__asm {
		//pop _REGISTER_RETURN_ADDR

		//PUSHAD
		//PUSHFD
	}

	// Extract the variable
	__asm {
		//mov ebx, [ecx + 0x000001D4]
		//	mov distance__, ebx
	}

	//ExtractRD();

	// Run our original code
	__asm {
		//POPFD
		//POPAD

		//cmp eax, edx

		//push _REGISTER_RETURN_ADDR
		//ret
	}
}

extern "C" __declspec(dllexport) void Initialize() {
	Console::Create();
	Console::WriteLine(L"CH");

	// Trying to find the correct address for the <Cube.onPlayerEat>
	//Cave::Codecave(0x00267347, CC_ExtractScore, 7);
	Cave::Codecave(0x011334D2, CC_ExtractRD, 2); // 2 bytes i think...
	Console::WriteLine(L"Hooked");
}