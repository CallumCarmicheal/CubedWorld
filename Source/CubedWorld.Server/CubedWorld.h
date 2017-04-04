#pragma once
#include "stdafx.h"
#include "Events.h"
#include "Console.h"

class CWHandle;

class CubedWorld {

public:
   CWEvent* const eventHandler;
   DWORD dwBaseAddress;
   CWHandle *cwHandle = NULL;
   int x = 1;

   CubedWorld();
   void setupCodeCaves();
   //void setEventHandler(CWEvent* eventHandler);

   void printSomething() {
      Console::WriteLineF("CubedWorld->printSomething, %i", ++x);
   }

   CWEvent* getEventHandler();
};

class CWHandle {
   bool procIsfrozen;
      
public:
   HANDLE hCubeWorld;

   CWHandle();
   void FreezeProcess();
   void ResumeProcess();
   
   bool isFreezed;
};