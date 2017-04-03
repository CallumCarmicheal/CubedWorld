#pragma once

#include <socketapi.h>

enum class SocketState {
   Success,
   FailedToCreate,
   FailedToBind,
   FailedToListen
};


class CWEvent {
public: 
   virtual void Initialize() {}
   virtual void evtSocketListen(SocketState socketState) {}
   virtual void evtSocketConnection() {}
};

class CWEnumHelper {
public:
   static std::string socketStateToString(SocketState state) {
      switch (state) {
      case SocketState::Success:             return "Success";
      case SocketState::FailedToCreate:      return "Failed to create socket";
      case SocketState::FailedToBind:        return "Failed to bind to specified address";
      case SocketState::FailedToListen:      return "Failed to listen";
      default:                               return "Unknown error";
      }
   }
};