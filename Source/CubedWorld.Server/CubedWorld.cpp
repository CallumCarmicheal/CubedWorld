#include "stdafx.h"
#include "Console.h"
#include "Events.h"
#include "CubedWorld.h"
#include "CodeCaves.h"

CubedWorld::CubedWorld() {
   // Get the base address of the CW server.
   dwBaseAddress = (DWORD) GetModuleHandle("Server.exe");

   // Create a instance of CWInstance
   cwHandle = new CWHandle();

   Console::WriteLine("CubedWorld instance initialized.");
}