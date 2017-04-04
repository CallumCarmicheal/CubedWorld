#include "stdafx.h"
#include "Console.h"
#include "Events.h"
#include "CubedWorld.h"
#include "CodeCaves.h"
#include "App.h"

CubedWorld::CubedWorld() {
   // Get the base address of the CW server.
   dwBaseAddress = (DWORD) GetModuleHandle("Server.exe");

   // Set our eventHandler to null
   eventHandler = NULL;
}

CWEvent* CubedWorld::getEventHandler() {
   return eventHandler;
}

void CubedWorld::setEventHandler(CWEvent* handler) {
   this->eventHandler = handler;

   // Check if the event handler is null
   // if not then call evtHandler->Initialize()
   if (this->eventHandler)
       this->eventHandler->Initialize();
}