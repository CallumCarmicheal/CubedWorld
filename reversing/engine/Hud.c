#include "../stdafx.h"


#ifndef __DEF_CW_ENGINE_HUD_C 
#define __DEF_CW_ENGINE_HUD_C 1
	
	int* native_AddMenuItem(int p1, int p2, int p3, int p4, int p5, int p6, int p7);
	
	void CubeWorld::Engine::HUD::Init() {
		// Offset:  .text: 0012EDF0
		// ParsedN: sub_12EDF0
		// TODO: Get via a pointer
		// POINTER: 
		/*
			ASM FOR POINTER: 
				.text:012EDF0     push    ebp
				.text:0012EDF1    mov     ebp, esp
				.text:0012EDF3    push    ebx
				.text:0012EDF4    mov     ebx, ecx
				.text:0012EDF6    push    esi
				.text:0012EDF7    mov     eax, [ebx+40h]
				.text:0012EDFA    push    edi
		 */
		 
		 // NOTE: Would do it right now but ida is killing me atm T-T
	}
	
	int CubeWorld::Engine::HUD::AddMenuItem(
			int ecx, int a2, int a3, void* ButtonClick, int edi, int eax_var28, int a7);			
		) {
		
		// For compatibility pass on the values to the native function
		native_AddMenuItem(ecx, a2, a3, (int)ButtonClick, edi, eax_var28, a7);
	}

#endif