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

HINSTANCE hDllMain;

// codecave "__declspec(naked)" function
extern "C" 
__declspec(dllexport) void Initialize() {
   Console::Create();
   Console::SetTitle(_T("CubedWorld - Server"));

   Console::WriteLine(L"[CubedWorld] Loading");

   App* app = new App();
   CubedWorld *cw = new CubedWorld();
   
   cw->setEventHandler(app);
   cw->hCubedWorld = hDllMain;
   cw->setupCodeCaves();
   
   Console::WaitLine ("[CubedWorld] Loaded... PRESS ANY KEY TO CONTINUE (Attach Debugger)\n");
}

BOOLEAN WINAPI DllMain(IN HINSTANCE hDllHandle, IN DWORD nReason, IN LPVOID Reserved) {
   BOOLEAN bSuccess = TRUE;

   //  Perform global initialization.

   switch (nReason) {
   case DLL_PROCESS_ATTACH:
      // Store our handle for later!
      hDllMain = hDllHandle;

      //  For optimization.
      DisableThreadLibraryCalls(hDllHandle);
      break;

   case DLL_PROCESS_DETACH:
      break;
   }

   return bSuccess;

}