#pragma once
#include "stdafx.h"
#include "Events.h"

class CWHandle;

class CubedWorld {
   CWEvent* eventHandler;

public:
   DWORD dwBaseAddress;
   CWHandle *cwHandle;


   CubedWorld();
   void setupCodeCaves();
   void setEventHandler(CWEvent *eventHandler);

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