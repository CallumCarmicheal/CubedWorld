; Add 5 from the current rendering distance
    ;Cube.exe+D34E0 - 83 81 D4010000 05     - 
	add dword ptr [ecx+000001D4],05 { 5 }

; Move the rendering distance into eax
    ;Cube.exe+D34E7 - 8B 81 D4010000        - 
	mov eax,[ecx+000001D4]

; Move 100/0x64 into edx (Max rendering distance)
    ;Cube.exe+D34ED - BA 64000000           - 
	mov edx,00000064 { 100 }

; Compare EAX and EDX
    ;Cube.exe+D34F2 - 3B C2                 - 
	cmp eax,edx

; EAX = EDX if EAX is less than EDX (CHECKS IF RENDERING DISTANCE IS UNDER 25 THEN USE 25 INSTEAD)
; Sample Data
   ; EAX - 1000
   ; EDX - 100
; C++ = if(EAX > EDX) { EAX = EDX; }
; If we fill this with a NOP operation we may be able to bypass the max limit
    ;Cube.exe+D34F4 - 0F4F C2               - 
	cmovg eax,edx

; Here we store the rendering distnace (SPECULATION tells me this is the rendering distance)
    ;Cube.exe+D34F7 - 89 81 D4010000        - 
	mov [ecx+000001D4],eax

; Return the new value
    ;Cube.exe+D34FD - C3                    - 
	ret 