; Subtract 5 from the current rendering distance
    ;Cube.exe+D34C0 - 83 81 D4010000 FB     - 
	add dword ptr [ecx+000001D4],-05 { 251 }

; Move the rendering distance into eax
    ;Cube.exe+D34C7 - 8B 81 D4010000        - 
	mov eax,[ecx+000001D4]

; Move 25/0x19 into edx (MIN RENDERING DISTANCE)
    ;Cube.exe+D34CD - BA 19000000           - 
	mov edx,00000019 { 25 }

; Compare EAX and EDX
    ;Cube.exe+D34D2 - 3B C2                 - 
	cmp eax,edx

; EAX = EDX if EAX is less than EDX (CHECKS IF RENDERING DISTANCE IS UNDER 25 THEN USE 25 INSTEAD)
; Sample Data
   ; EAX - 1000
   ; EDX - 25
; C++ = if(EAX < EDX) { EAX = EDX; }
    ;Cube.exe+D34D4 - 0F4C C2               - 
	cmovl eax,edx

; Here we move our finished value into [ecx+000001D4]
    ;Cube.exe+D34D7 - 89 81 D4010000        - 
	mov [ecx+000001D4],eax

; This here will return to the callers offset, where the value in 
; [ecx+000001D4] will be used for the rendering distance
    ;Cube.exe+D34DD - C3                    - 
	ret 