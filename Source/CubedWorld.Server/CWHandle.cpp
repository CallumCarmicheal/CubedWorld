#include "stdafx.h"
#include "CubedWorld.h"

typedef LONG(NTAPI *NtSuspendProcess)(IN HANDLE ProcessHandle);

CWHandle::CWHandle() {
   // Get the handle
   hCubeWorld = GetModuleHandleA("Server.exe");
}

void CWHandle::FreezeProcess() {
   HANDLE processHandle = hCubeWorld;

   NtSuspendProcess pfnNtSuspendProcess = (NtSuspendProcess) GetProcAddress(
      GetModuleHandle("ntdll"), "NtSuspendProcess");

   pfnNtSuspendProcess(processHandle);
   CloseHandle(processHandle);
}