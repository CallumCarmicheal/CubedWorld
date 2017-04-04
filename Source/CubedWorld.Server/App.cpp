#include "stdafx.h"
#include "App.h"
#include "Console.h"

void App::Initialize()        {}
void App::evtSocketCreated() { Console::WaitLine("Attach DEBUGGER NAOW!"); }

void App::evtSocketError(SocketErrorState state) {
   std::string result;
   result = CWEnumHelper::socketStateToString(state);
   Console::WaitLineF("App::evtSocketError( %s )", result.c_str());
}

void App::evtSocketConnection() {
      
}

void App::evtConsoleCommand(std::string command) {

}