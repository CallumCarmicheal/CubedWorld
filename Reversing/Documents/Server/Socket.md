# Binary Information
`Image Base Address	= 00400000`

# Socket
Setup Socket Address: `.text:`00428790
The socket is setup like somewhat is shown below:
the langauge is JIBBERISH Pseudo Code

```
// This is the general process going on 
// this is not a 1:1 conversion, that is below!
// this is the englishified version ;)
FUNC cubeworld_serv_SetupSocket(void *p1) 
	// State we are starting the server
	print "Starting server...";

	// Setup variables
	set sName 		as SOCKADDR
	set sListener 	as SOCKET
	set sListener_2 as SOCKET
	set aObjects 	as ARRAY

	aObjects  = p1;
	sListener = socket(2, 1, 0)

	// .text:004287EF
	//
	//  Check if the socket is invalid
	if ( SOCKET == INVALID_SOCKET )
		// CODECAVE: failedSocketCreate
		display "Could not create server socket"
		ret

	// .text:00428802
	// 		
	// Setup socket listener data
	sName.sa_family  = 2
	sName.sa_data[0] = 12345 (3039) // Set the port
	sName.sa_data[2] = 0

	// .text:00428836
	//
	// Attempt to bind to the socket
	if ( bind(sListener_2, &sName, 16) == -1 )
		// CODECAVE: failedSocketBind
		display "Could not bind socket." 
		
	// .text:00428866
	//
	// Attempt to listen for incoming connections
	// Max Connections at once = 10
	if ( listen( *(aObjects + 9), 10 ) == -1 )
		// CODECAVE: failedToListen
		display "Listen failed."
	
	// Maybe a bool stating the server
	// is on
	*(aObjects + 76) = 1;
	
	print "Server started. Enter Q to quit."
	
	// CODECAVE: socketSuccess
	
	// Some stuff that confuse the hell out of me
	
END FUNC
```

###### The actual C code (HEXRAYS DECOMPILED)
```c++
int  __thiscall 
cubeworld_serv_SetupSocket (void *this) {

  void *arrayThis; // esi@1
  int v2; // eax@1
  SOCKET sListener; // eax@1
  SOCKET sListener_2; // ST04_4@3
  int tmpConO_5; // eax@4 Temp console output!
  int tmpConO_6; // eax@6 Temp console output!
  int result; // eax@7
  int v8; // ecx@7
  int v9; // eax@7
  int v10; // [sp+4h] [bp-38h]@7
  void *v11; // [sp+8h] [bp-34h]@7
  int *v12; // [sp+14h] [bp-28h]@7
  struct sockaddr name; // [sp+1Ch] [bp-20h]@3
  unsigned int v14; // [sp+2Ch] [bp-10h]@1
  int v15; // [sp+38h] [bp-4h]@7
  int v16; // [sp+3Ch] [bp+0h]@1

  v14 = &v16 ^ __security_cookie;
  arrayThis = this;
  
  v2 = conWriteLine(std__cout, "Starting server...");// State we are starting the server
  conNewLine(v2, std__endl);
  
  sListener = socket(2, 1, 0);
  *(arrayThis + 9) = sListener;
  
  // Check if the socket was created
  if ( sListener == -1 )
    conWriteLine(std__cout, "Could not create server socket.");
	// NOTE: There is no return, this will fallthrough!
	
  // Assembly
  __asm {
    xorps   xmm0, xmm0
    movq    qword ptr [ebp+name.sa_family], xmm0
    movq    qword ptr [ebp+name.sa_data+6], xmm0
  }
  
  name.sa_family = 2;
  *&name.sa_data[0] = htons(0x3039u);           // Set the port for the socket
  
  // ?!?!?! What
  sListener_2 = *(arrayThis + 9);
  
  *&name.sa_data[2] = 0;
  
  // Failed to bind socket
  if ( bind(sListener_2, &name, 16) == -1 ) {
    tmpConO_5 = conWriteLine(std__cout, "Could not bind socket.");
    conNewLine(tmpConO_5, std__endl);
	
	// NOTE: There is no return, this will fallthrough!
  }
  
  // Failed to listen for clients?!?!?!
  if ( listen(*(arrayThis + 9), 10) == -1 ) {
    tmpConO_6 = conWriteLine(std__cout, "Listen failed.");
    conNewLine(tmpConO_6, std__endl);
	
	// NOTE: There is no return, this will fallthrough!
  }
  
  // Maybe a bool to state the server has started
  *(arrayThis + 76) = 1; 
  
  v9 = conWriteLine(std__cout, "Server started. Enter Q to quit.");
  conNewLine(v9, std__endl);
  
  v10 = off_55B1E0;
  v11 = arrayThis;
  v12 = &v10;
  v15 = 1;
  
  result = sub_413640(&v10);
  v8 = v12;
  
  *(arrayThis + 20) = result;
  
  v15 = -1;
  
  if ( v8 )
    result = (*(*v8 + 16))(v8 != &v10);
	
  return result;
}
```

### Setup Socket

#### CodeCave Targets

failedSocketCreate
```
Assembly Code		= call Server.exe+12710
             		= call 00E32710
Machine Code		= E8 3F 9F FE FF
Address in Binary	= 004287FA
Actual Address 		= 000287FA
Pointer Address 	= Server.exe+000287FA
Pointer Offset 		= 0
```

failedSocketBind
```
Assembly Code		= call Server.exe+12710
             		= call 00E32710
Machine Code		= E8 3F 9F FE FF
Address in Binary	= 00428851
Actual Address 		= 00028851
Pointer Address 	= Server.exe+00028851
Pointer Offset 		= 0
```

failedToListen
```
Assembly Code		= call Server.exe+12710
             		= call 00E32710
Machine Code		= E8 3F 9F FE FF
Address in Binary	= 00428881
Actual Address 		= 00028881
Pointer Address 	= Server.exe+00028881
Pointer Offset 		= 0
```

socketSuccess
```
Assembly Code		= call Server.exe+12710
             		= call 00E32710
Machine Code		= E8 3F 9F FE FF
Address in Binary	= 004288A6
Actual Address 		= 000288A6
Pointer Address 	= Server.exe+000288A6
Pointer Offset 		= 0
```

#### Options: Max Connections

#### Options: Port

ByteScan: `68 39 30 00 00`
* Will only work if the port is not changed in the binary.

0x68 = Push instruction

0x39 = Integer (High)
0x30 = Integer (Low)

0x3039 = 12345 (SHORT)

To set the port 12346 (0x303A) you would set the data to 3A 30.
```
Assembly Code		= push 3039h
Machine Code		= 68 39 30 00 00
Address in Binary	= 0042880F
Actual Address 		= 0002880F
Pointer Address 	= Server.exe+0002880F
Pointer Offset		= 0
```