#pragma once
#include "stdafx.h"
#include "Events.h"

class App : CWEvent {
public:
   virtual void Initialize() override;
   virtual void evtSocketListen(SocketState socketState) override;
   virtual void evtSocketConnection() override;
};