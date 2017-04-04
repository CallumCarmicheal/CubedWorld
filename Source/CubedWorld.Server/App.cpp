#include "stdafx.h"
#include "App.h"
#include "Console.h"

void App::Initialize() {
   Console::WriteLine("App::Initialize()");
}

void App::evtSocketCreated() {
   Console::WriteLineF("App::evtSocketCreated()");
}

void App::evtSocketError(SocketErrorState state) {
   std::string result;
   result = CWEnumHelper::socketStateToString(state);
   Console::WriteLineF("App::evtSocketError( %s )", result);
}

void App::evtSocketConnection() {
   Console::WriteLine("App::evtSocketConnection()");
}