#include <windows.h>
#include <fcntl.h>
#include <stdio.h>
#include <io.h>
#include <string>

using namespace std;

// Codecave function
VOID Codecave(DWORD destAddress, VOID (*func)(VOID), BYTE nopCount);

// Writes bytes in the current process using an ASM method
VOID WriteBytesASM(DWORD destAddress, LPVOID patch, DWORD numBytes);

// Create a console
VOID CreateConsole();

DWORD currentScore = 0;


void DisplayCurrentScore()
{
	printf("Nom nom nom %i \r", currentScore);
}

// codecave "__declspec(naked)" function
__declspec(naked) void CC_ExtractScore(void)
{

	__asm {
		MOVSS currentScore, XMM0
	}

	DisplayCurrentScore();

	__asm 
	{
		// execute whatever code we took out for the codecave.
		MOVSS DWORD PTR DS : [ESI + 0x16C], XMM0
		ret
	}
}

extern "C" __declspec(dllexport) void Initialize()
{
	CreateConsole();

	// Trying to find the correct address for the <Cube.onPlayerEat>
	//Codecave(0x00267347, CC_ExtractScore, 1);
}



// Define the plugins main, use a define since the code is the same for all plugins
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ulReason, LPVOID lpReserved)
{
	// Get rid of compiler warnings since we do not use this parameter
	UNREFERENCED_PARAMETER(lpReserved);

	// If we are attaching to a process, we do not want the dll thread messages
	if(ulReason == DLL_PROCESS_ATTACH)
		DisableThreadLibraryCalls(hModule); 

	// Always load/unload
	return TRUE;
}



// Writes bytes in the current process using an ASM method
VOID WriteBytesASM(DWORD destAddress, LPVOID patch, DWORD numBytes)
{
	// Store old protection of the memory page
	DWORD oldProtect = 0;

	// Store the source address
	DWORD srcAddress = PtrToUlong(patch);

	// Make sure page is writeable
	VirtualProtect((void*)(destAddress), numBytes, PAGE_EXECUTE_READWRITE, &oldProtect);

	// Do the patch (oldschool style to avoid memcpy)
	__asm
	{
		nop						// Filler
		nop						// Filler
		nop						// Filler

		mov esi, srcAddress		// Save the address
		mov edi, destAddress	// Save the destination address
		mov ecx, numBytes		// Save the size of the patch
Start:
		cmp ecx, 0				// Are we done yet?
		jz Exit					// If so, go to end of function

		mov al, [esi]			// Move the byte at the patch into AL
		mov [edi], al			// Move AL into the destination byte
		dec ecx					// 1 less byte to patch
		inc esi					// Next source byte
		inc edi					// Next destination byte
		jmp Start				// Repeat the process
Exit:
		nop						// Filler
		nop						// Filler
		nop						// Filler
	}

	// Restore old page protection
	VirtualProtect((void*)(destAddress), numBytes, oldProtect, &oldProtect);
}



// Codecave function
VOID Codecave(DWORD destAddress, VOID (*func)(VOID), BYTE nopCount)
{
	// Calculate the code cave for chat interception
	DWORD offset = (PtrToUlong(func) - destAddress) - 5;

	// Buffer of NOPs, static since we limit to 'UCHAR_MAX' NOPs
	BYTE nopPatch[0xFF] = {0};

	// Construct the patch to the function call
	BYTE patch[5] = {0xE8, 0x00, 0x00, 0x00, 0x00};
	memcpy(patch + 1, &offset, sizeof(DWORD));
	WriteBytesASM(destAddress, patch, 5);

	// We are done if we do not have NOPs
	if(nopCount == 0)
		return;

	// Fill it with nops
	memset(nopPatch, 0x90, nopCount);

	// Make the patch now
	WriteBytesASM(destAddress + 5, nopPatch, nopCount);
}



// Create a console (this code is not mine, taken from online)
VOID CreateConsole()
{
	int hConHandle = 0;
	HANDLE lStdHandle = 0;
	FILE *fp = 0;

	// Allocate a console
	AllocConsole();

	// redirect unbuffered STDOUT to the console
	lStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	hConHandle = _open_osfhandle(PtrToUlong(lStdHandle), _O_TEXT);
	fp = _fdopen(hConHandle, "w");
	*stdout = *fp;
	setvbuf(stdout, NULL, _IONBF, 0);

	// redirect unbuffered STDIN to the console
	lStdHandle = GetStdHandle(STD_INPUT_HANDLE);
	hConHandle = _open_osfhandle(PtrToUlong(lStdHandle), _O_TEXT);
	fp = _fdopen(hConHandle, "r");
	*stdin = *fp;
	setvbuf(stdin, NULL, _IONBF, 0);

	// redirect unbuffered STDERR to the console
	lStdHandle = GetStdHandle(STD_ERROR_HANDLE);
	hConHandle = _open_osfhandle(PtrToUlong(lStdHandle), _O_TEXT);
	fp = _fdopen(hConHandle, "w");
	*stderr = *fp;
	setvbuf(stderr, NULL, _IONBF, 0);
}
