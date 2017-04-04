#pragma once

#include <socketapi.h>
#include "Console.h"

enum class SocketErrorState {
   FailedToCreate,
   FailedToBind,
   FailedToListen
};


class CWEvent {
public: 
   virtual void Initialize()                                   {}
   virtual void evtSocketError(SocketErrorState socketState)   {}
   virtual void evtSocketCreated()                             {}
   virtual void evtSocketConnection()                          {}
   virtual void evtConsoleCommand(std::string command)         {}
};

class CWEnumHelper {
public:
   static std::string socketStateToString(SocketErrorState state) {
      switch (state) {
      case SocketErrorState::FailedToCreate:    return "Failed to create socket";
      case SocketErrorState::FailedToBind:      return "Failed to bind to specified address";
      case SocketErrorState::FailedToListen:    return "Failed to listen";
      default:                                  return "Unknown error";
      }

      return "Unknown error (fb)";
   }
};