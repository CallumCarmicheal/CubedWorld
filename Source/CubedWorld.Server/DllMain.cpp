#include "stdafx.h"

#include <Psapi.h>
#include <iostream>
#include <conio.h>

#include "Cave.h"
#include "Console.h"
#include "stdafx.h"
#include "CubedWorld.h"
#include "App.h"

#pragma comment( lib, "psapi" )

using namespace std;

// codecave "__declspec(naked)" function
extern "C" __declspec(dllexport) void Initialize() {
	Console::Create();
    Console::SetTitle(_T("CubedWorld - Server"));

	Console::WriteLine(L"CubedWorld.DllMain->Initialize()");

    CubedWorld cw;
    cw.setupCodeCaves();
    
    Console::WriteLine ("Created Cave\n  PRESS ANY KEY TO CONTINUE\n  (Attach a debugger!)\n\n");

    // Wait for input
    _getch();
}