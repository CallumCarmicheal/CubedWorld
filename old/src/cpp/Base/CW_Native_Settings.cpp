#include "stdafx.h"
#include "CW_Native_Settings.h"
#include "Cave.h"
#include "Console.h"

DWORD addAmount = 3;
DWORD currentAmount = 0;
DWORD newAmount = 0;

DWORD RETURNADDRESS;

__declspec(naked) void CC_Settings_GUI_Rendering_Increase(void) {
	// Use our original code but set it to increase at 3 instead of 
	// 5

	// PRE
	__asm {
		// Preserve our stack, return location
		pop RETURNADDRESS;
	}


	// Get our current amount
	__asm {
		
	}

	// Do the original functions purpose!
	__asm {
		// Increase our amount
		//add dword ptr[ecx + 00000724], addAmount

		add dword ptr[ecx + 00000724], 3

		// Move our current amount into eax for cmp
		mov eax, [ecx + 00000724]

		// Get our new amount
		//mov newAmount, EAX -.-

		// move 100 into edx
		mov edx, 00000064

		// compare the both
		cmp eax, edx

		// If greater set eax to edx (100)
		cmovg eax, edx

		// return our result
		mov[ecx + 00000724], eax
	}

	Console::WriteLineF("Add: %i Old: %i Cur: %i", addAmount, currentAmount, newAmount);

	// Return (Finish function)
	__asm {
		push RETURNADDRESS
		ret
	}
}

__declspec(naked) void CC_Settings_GUI_Rendering_Decrease(void) {

}


// Init our hooks
void CubeWorld::Native::Settings::InitCodeCaves() {
	// We need to get the size of the bytes to modify so im going to dump the 
	// binary 

	Cave::Codecave(0x011334DD, CC_Settings_GUI_Rendering_Increase, 0x1D);
	Console::WriteLine("Added SETTINGS Native Hooks");
}