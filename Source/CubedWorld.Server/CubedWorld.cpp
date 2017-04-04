#include "stdafx.h"
#include "Console.h"
#include "Events.h"
#include "CubedWorld.h"
#include "CodeCaves.h"
#include "App.h"

CubedWorld::CubedWorld() : eventHandler(new App()) {
   // Get the base address of the CW server.
   dwBaseAddress = (DWORD) GetModuleHandle("Server.exe");

   // Create a instance of CWInstance
   cwHandle = new CWHandle();
   
   Console::WriteLine("CubedWorld instance initialized.");
}

CWEvent* CubedWorld::getEventHandler() {
   return eventHandler;
}

/*
void CubedWorld::setEventHandler(CWEvent* handler) {
   this->eventHandler = handler;

   // Check if the event handler is null
   // if not then call evtHandler->Initialize()
   this->eventHandler->Initialize();
}*/