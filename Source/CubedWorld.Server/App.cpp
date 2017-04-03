#include "stdafx.h"
#include "App.h"
#include "Console.h"


void App::Initialize() {
   Console::WriteLine("App::Initialize()");
}

void App::evtSocketListen(SocketState state) {
   std::string result;
   result = CWEnumHelper::socketStateToString(state);
   Console::WriteLineF("App::evtSocketListen -> %s", result);
}

void App::evtSocketConnection() {
   Console::WriteLine("App::evtSocketConnection()");
}