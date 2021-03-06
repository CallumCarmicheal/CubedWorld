#include "stdafx.h"

#include "Console.h"
#include "Cave.h"
#include "CubedWorld.h"

#include <conio.h>
#include <iostream>

// Setup the events for the socket listener
// REFER TO: Reversing/Documents/Server/Socket.md

#pragma region 

   CubedWorld* ptrCubedWorld;
   
   DWORD addr_PrintLine;
   DWORD addr_Socket_FailedSocketCreate;
   DWORD addr_Socket_FailedSocketBind;
   DWORD addr_Socket_FailedToListen;
   DWORD addr_Socket_SocketSuccess;

   #pragma region
      void CB_Socket_FailedCreate() {
         CWEvent* cwe = ptrCubedWorld->getEventHandler();

         if (cwe != NULL) {
            cwe->evtSocketError(SocketErrorState::FailedToCreate);
         } else {
            Console::WriteLine("[CubedWorld DEBUG] There is no event handler, using fallback");
            Console::WriteLine("Failed to create socket...\n\nPRESS ANY KEY TO EXIT");
            _getch();
         }

         exit(EXIT_FAILURE);
      }

      void CB_Socket_FailedBind() {
         CWEvent* cwe = ptrCubedWorld->getEventHandler();

         if (cwe != NULL) {
            cwe->evtSocketError(SocketErrorState::FailedToBind);
         } else {
            Console::WriteLine("[CubedWorld DEBUG] There is no event handler, using fallback");
            Console::WriteLine("Failed to bind to address or port...\n\nPRESS ANY KEY TO EXIT");
            _getch();
         }

         exit(EXIT_FAILURE);
      }

      void CB_Socket_FailedListen() {
         CWEvent* cwe = ptrCubedWorld->getEventHandler();
         
         if (cwe != NULL) {
            cwe->evtSocketError(SocketErrorState::FailedToListen);
         } else {
            Console::WriteLine("[CubedWorld DEBUG] There is no event handler, using fallback");
            Console::WriteLine("Failed to listen on socket...\n\nPRESS ANY KEY TO EXIT");
            _getch();
         }
         
         exit(EXIT_FAILURE);
      }

      void CB_Socket_Success() {
         if (!ptrCubedWorld) {
            Console::WaitLine("[DEBUG] !ptrCubedWorld");
            return;
         }

         CWEvent* cwe = ptrCubedWorld->getEventHandler();

         if (cwe != NULL) 
            cwe->evtSocketCreated();
      }
   #pragma endregion Assembly callbacks

   #pragma region
      DWORD pop_SocketListener_FailedCreate;
      __declspec(naked) void CC_SOCKET_FailedCreate(void) {
         // Store the state/stack
         __asm {
            pop pop_SocketListener_FailedCreate

            PUSHAD
            PUSHFD
         }

         // Call our event
         CB_Socket_FailedCreate();

         // Restore the state/stack
         __asm {
            POPFD
            POPAD

            call addr_PrintLine

            push pop_SocketListener_FailedCreate
            ret
         }
      }

      DWORD pop_SocketListener_FailedBind;
      __declspec(naked) void CC_SOCKET_FailedBind(void) {
         // Store the state/stack
         __asm {
            pop pop_SocketListener_FailedBind

            PUSHAD
            PUSHFD
         }

         // Call our event
         CB_Socket_FailedBind();

         // Restore the state/stack
         __asm {
            POPFD
            POPAD

            call addr_PrintLine

            push pop_SocketListener_FailedBind
            ret
         }
      }

      DWORD pop_SocketListener_FailedListen;
      __declspec(naked) void CC_SOCKET_FailedListen(void) {
         // Store the state/stack
         __asm {
            pop pop_SocketListener_FailedListen

            PUSHAD
            PUSHFD
         }

         // Call our event
         CB_Socket_FailedListen();

         // Restore the state/stack
         __asm {
            POPFD
            POPAD

            call addr_PrintLine

            push pop_SocketListener_FailedListen
            ret
         }
      }

      DWORD pop_SocketListener_Success;
      __declspec(naked) void CC_SOCKET_Success(void) {
         // Store the state/stack
         __asm {
            pop pop_SocketListener_Success

            PUSHAD
            PUSHFD
         }

         // Call our event
         CB_Socket_Success();

         // Restore the state/stack
         __asm {
            POPFD
            POPAD

            call addr_PrintLine

            push pop_SocketListener_Success
            ret
         }
      }
   #pragma endregion Native assembly calls


   void setupCodeCave_Socket(CubedWorld *cw) {
      // Display debug
      Console::WriteLine("[CubedWorld] CodeCaves: Socket -> Started.");

      // Setup the addresses
      addr_Socket_FailedSocketCreate = cw->dwBaseAddress + 0x000287FA;
      addr_Socket_FailedSocketBind   = cw->dwBaseAddress + 0x00028851;
      addr_Socket_FailedToListen     = cw->dwBaseAddress + 0x00028881;
      addr_Socket_SocketSuccess      = cw->dwBaseAddress + 0x000288A6;
      addr_PrintLine                 = cw->dwBaseAddress + 0x00012710;

      // Create the code caves
      Cave::CodeCave(addr_Socket_FailedSocketCreate,  CC_SOCKET_FailedCreate, 0);
      Cave::CodeCave(addr_Socket_FailedSocketBind,    CC_SOCKET_FailedBind,   0);
      Cave::CodeCave(addr_Socket_FailedToListen,      CC_SOCKET_FailedListen, 0);
      Cave::CodeCave(addr_Socket_SocketSuccess,       CC_SOCKET_Success,      0);


      // Store our CW instance
      ptrCubedWorld = cw;

      // Display debug
      Console::WriteLine("[CubedWorld] CodeCaves: Socket -> Finished.");
   }

#pragma endregion Socket Events

void CubedWorld::setupCodeCaves() {
   Console::WriteLine("[CubedWorld] CodeCaves: Started");

   setupCodeCave_Socket(this);

   Console::WriteLine("[CubedWorld] CodeCaves: Finished");
}