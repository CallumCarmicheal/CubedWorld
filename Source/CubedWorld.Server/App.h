#pragma once
#include "stdafx.h"
#include "Events.h"

class App : public CWEvent {
public:
   void Initialize() override;
   void evtSocketCreated() override;
   void evtSocketError(SocketErrorState socketState) override;
   void evtSocketConnection() override;
};