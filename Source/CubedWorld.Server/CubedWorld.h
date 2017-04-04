#pragma once
#include "stdafx.h"
#include "Events.h"
#include "Console.h"

class CWHandle;

class CubedWorld {
private:
   CWEvent* eventHandler;

public:
   HINSTANCE   hCubedWorld;
   DWORD       dwBaseAddress;
   CWHandle    *cwHandle = NULL;

   CubedWorld();
   void setupCodeCaves();
   void setEventHandler(CWEvent* eventHandler);

   CWEvent* getEventHandler();
};