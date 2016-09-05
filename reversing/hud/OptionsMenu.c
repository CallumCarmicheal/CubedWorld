#include "../stdafx.h"

//TODO: Place re-interp protection

/* TODO: Restructure the code

	int __thiscall sub_12EF90(void *this, int a2, int a3, int a4, int a5, int a6, int a7)
	{
	  int v7; // edi@1
	  int v8; // eax@3
	  int v9; // eax@3
	  int v10; // ecx@3
	  int v11; // eax@5
	  int v12; // eax@5
	  int v13; // ecx@5
	  int v14; // eax@7
	  int v15; // eax@7
	  int v16; // ecx@7
	  int v17; // eax@9
	  int v18; // eax@9
	  int v19; // ecx@9
	  int v20; // eax@11
	  int v21; // eax@11
	  int v22; // ecx@11
	  int v23; // eax@13
	  int v24; // eax@13
	  int v25; // ecx@13
	  int v26; // eax@15
	  int v27; // eax@15
	  int v28; // ecx@15
	  int v29; // eax@17
	  int v30; // eax@17
	  int v31; // ecx@17
	  int v32; // eax@19
	  int v33; // eax@19
	  int v34; // ecx@19
	  int v35; // eax@21
	  int v36; // eax@21
	  int v37; // ecx@21
	  int v38; // eax@23
	  int v39; // eax@23
	  int v40; // ecx@23
	  int v41; // eax@25
	  int v42; // eax@25
	  int v43; // ecx@25
	  int v44; // eax@27
	  int v45; // eax@27
	  int v46; // ecx@27
	  int v47; // eax@29
	  int v48; // eax@29
	  int v49; // ecx@29
	  int v50; // eax@31
	  int v51; // eax@31
	  int v52; // ecx@31
	  int v53; // eax@33
	  int v54; // eax@33
	  int v55; // ecx@33
	  int v56; // eax@35
	  int v57; // eax@35
	  int v58; // ecx@35
	  int v59; // eax@37
	  int v60; // eax@37
	  int v61; // ecx@37
	  unsigned int v63; // [sp+Ch] [bp-60h]@1
	  void *v64; // [sp+2Ch] [bp-40h]@43
	  unsigned int v65; // [sp+40h] [bp-2Ch]@43
	  void *v66; // [sp+44h] [bp-28h]@1
	  int v67; // [sp+54h] [bp-18h]@1
	  unsigned int v68; // [sp+58h] [bp-14h]@1
	  unsigned int v69; // [sp+5Ch] [bp-10h]@1
	  int v70; // [sp+68h] [bp-4h]@1
	  int v71; // [sp+6Ch] [bp+0h]@1

	  v69 = (unsigned int)&v71 ^ __security_cookie;
	  v63 = (unsigned int)&v71 ^ __security_cookie;
	  v7 = (int)this;
	  v68 = 7;
	  v67 = 0;
	  LOWORD(v66) = 0;
	  sub_6F990(&unk_35BCAC, 0);
	  v70 = 0;
	  sub_285B60(a2, a3, &v66);
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)v7 = &off_3622C4;
	  *(_DWORD *)(v7 + 36) = off_362374;
	  *(_DWORD *)(v7 + 352) = 0;
	  *(_DWORD *)(v7 + 356) = 0;
	  *(_DWORD *)(v7 + 360) = 0;
	  LOBYTE(v70) = 3;
	  *(_DWORD *)(v7 + 364) = a4;
	  sub_12E400(v7 + 452);
	  *(_DWORD *)(v7 + 492) = 0;
	  *(_DWORD *)(v7 + 368) = sub_294900(a3);
	  v8 = (*(int (__stdcall **)(unsigned int))(**(_DWORD **)(a5 + 56) + 8))(v63);
	  sub_295430(v8);
	  v9 = (*(int (**)(void))(**(_DWORD **)(a5 + 60) + 8))();
	  sub_2951A0(v9);
	  v68 = 7;
	  v67 = 0;
	  LOWORD(v66) = 0;
	  sub_6F990(L"leftbutton", 10);
	  v10 = *(_DWORD *)(v7 + 368);
	  LOBYTE(v70) = 4;
	  _CUBE_GUI_ITEMS_AddMenuItem(v10, (int)&v66, 2, v7, (int)sub_1333C0, 0, 1);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)(v7 + 372) = sub_294900(a3);
	  v11 = (*(int (**)(void))(**(_DWORD **)(a6 + 56) + 8))();
	  sub_295430(v11);
	  v12 = (*(int (**)(void))(**(_DWORD **)(a6 + 60) + 8))();
	  sub_2951A0(v12);
	  v68 = 7;
	  v67 = 0;
	  LOWORD(v66) = 0;
	  sub_6F990(L"rightbutton", 11);
	  v13 = *(_DWORD *)(v7 + 372);
	  LOBYTE(v70) = 5;
	  _CUBE_GUI_ITEMS_AddMenuItem(v13, (int)&v66, 2, v7, (int)sub_133400, 0, 1);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)(v7 + 376) = sub_294900(a3);
	  v14 = (*(int (**)(void))(**(_DWORD **)(a5 + 56) + 8))();
	  sub_295430(v14);
	  v15 = (*(int (**)(void))(**(_DWORD **)(a5 + 60) + 8))();
	  sub_2951A0(v15);
	  v68 = 7;
	  v67 = 0;
	  LOWORD(v66) = 0;
	  sub_6F990(L"leftbutton", 10);
	  v16 = *(_DWORD *)(v7 + 376);
	  LOBYTE(v70) = 6;
	  _CUBE_GUI_ITEMS_AddMenuItem(v16, (int)&v66, 2, v7, (int)sub_133A10, 0, 1);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)(v7 + 380) = sub_294900(a3);
	  v17 = (*(int (**)(void))(**(_DWORD **)(a6 + 56) + 8))();
	  sub_295430(v17);
	  v18 = (*(int (**)(void))(**(_DWORD **)(a6 + 60) + 8))();
	  sub_2951A0(v18);
	  v68 = 7;
	  v67 = 0;
	  LOWORD(v66) = 0;
	  sub_6F990(L"rightbutton", 11);
	  v19 = *(_DWORD *)(v7 + 380);
	  LOBYTE(v70) = 7;
	  _CUBE_GUI_ITEMS_AddMenuItem(v19, (int)&v66, 2, v7, (int)sub_133A80, 0, 1);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)(v7 + 384) = sub_294900(a3);
	  v20 = (*(int (**)(void))(**(_DWORD **)(a5 + 56) + 8))();
	  sub_295430(v20);
	  v21 = (*(int (**)(void))(**(_DWORD **)(a5 + 60) + 8))();
	  sub_2951A0(v21);
	  v68 = 7;
	  v67 = 0;
	  LOWORD(v66) = 0;
	  sub_6F990(L"leftbutton", 10);
	  v22 = *(_DWORD *)(v7 + 384);
	  LOBYTE(v70) = 8;
	  _CUBE_GUI_ITEMS_AddMenuItem(v22, (int)&v66, 2, v7, (int)sub_1332C0, 0, 1);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)(v7 + 388) = sub_294900(a3);
	  v23 = (*(int (**)(void))(**(_DWORD **)(a6 + 56) + 8))();
	  sub_295430(v23);
	  v24 = (*(int (**)(void))(**(_DWORD **)(a6 + 60) + 8))();
	  sub_2951A0(v24);
	  v68 = 7;
	  v67 = 0;
	  LOWORD(v66) = 0;
	  sub_6F990(L"rightbutton", 11);
	  v25 = *(_DWORD *)(v7 + 388);
	  LOBYTE(v70) = 9;
	  _CUBE_GUI_ITEMS_AddMenuItem(v25, (int)&v66, 2, v7, (int)sub_1332E0, 0, 1);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)(v7 + 392) = sub_294900(a3);
	  v26 = (*(int (**)(void))(**(_DWORD **)(a5 + 56) + 8))();
	  sub_295430(v26);
	  v27 = (*(int (**)(void))(**(_DWORD **)(a5 + 60) + 8))();
	  sub_2951A0(v27);
	  v68 = 7;
	  v67 = 0;
	  LOWORD(v66) = 0;
	  sub_6F990(L"leftbutton", 10);
	  v28 = *(_DWORD *)(v7 + 392);
	  LOBYTE(v70) = 10;
	  _CUBE_GUI_ITEMS_AddMenuItem(v28, (int)&v66, 2, v7, (int)CUBE_GUI_BUTTONS_leftButton_CLICK, 0, 1);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)(v7 + 396) = sub_294900(a3);
	  v29 = (*(int (**)(void))(**(_DWORD **)(a6 + 56) + 8))();
	  sub_295430(v29);
	  v30 = (*(int (**)(void))(**(_DWORD **)(a6 + 60) + 8))();
	  sub_2951A0(v30);
	  v68 = 7;
	  v67 = 0;
	  LOWORD(v66) = 0;
	  sub_6F990(L"rightbutton", 11);
	  v31 = *(_DWORD *)(v7 + 396);
	  LOBYTE(v70) = 11;
	  _CUBE_GUI_ITEMS_AddMenuItem(v31, (int)&v66, 2, v7, (int)sub_1334E0, 0, 1);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)(v7 + 400) = sub_294900(a3);
	  v32 = (*(int (**)(void))(**(_DWORD **)(a5 + 56) + 8))();
	  sub_295430(v32);
	  v33 = (*(int (**)(void))(**(_DWORD **)(a5 + 60) + 8))();
	  sub_2951A0(v33);
	  v68 = 7;
	  v67 = 0;
	  LOWORD(v66) = 0;
	  sub_6F990(L"leftbutton", 10);
	  v34 = *(_DWORD *)(v7 + 400);
	  LOBYTE(v70) = 12;
	  _CUBE_GUI_ITEMS_AddMenuItem(v34, (int)&v66, 2, v7, (int)sub_133B00, 0, 1);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)(v7 + 404) = sub_294900(a3);
	  v35 = (*(int (**)(void))(**(_DWORD **)(a6 + 56) + 8))();
	  sub_295430(v35);
	  v36 = (*(int (**)(void))(**(_DWORD **)(a6 + 60) + 8))();
	  sub_2951A0(v36);
	  v68 = 7;
	  v67 = 0;
	  LOWORD(v66) = 0;
	  sub_6F990(L"rightbutton", 11);
	  v37 = *(_DWORD *)(v7 + 404);
	  LOBYTE(v70) = 13;
	  _CUBE_GUI_ITEMS_AddMenuItem(v37, (int)&v66, 2, v7, (int)sub_133B20, 0, 1);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)(v7 + 408) = sub_294900(a3);
	  v38 = (*(int (**)(void))(**(_DWORD **)(a5 + 56) + 8))();
	  sub_295430(v38);
	  v39 = (*(int (**)(void))(**(_DWORD **)(a5 + 60) + 8))();
	  sub_2951A0(v39);
	  v68 = 7;
	  v67 = 0;
	  LOWORD(v66) = 0;
	  sub_6F990(L"leftbutton", 10);
	  v40 = *(_DWORD *)(v7 + 408);
	  LOBYTE(v70) = 14;
	  _CUBE_GUI_ITEMS_AddMenuItem(v40, (int)&v66, 2, v7, (int)sub_133440, 0, 1);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)(v7 + 412) = sub_294900(a3);
	  v41 = (*(int (**)(void))(**(_DWORD **)(a6 + 56) + 8))();
	  sub_295430(v41);
	  v42 = (*(int (**)(void))(**(_DWORD **)(a6 + 60) + 8))();
	  sub_2951A0(v42);
	  v68 = 7;
	  v67 = 0;
	  LOWORD(v66) = 0;
	  sub_6F990(L"rightbutton", 11);
	  v43 = *(_DWORD *)(v7 + 412);
	  LOBYTE(v70) = 15;
	  _CUBE_GUI_ITEMS_AddMenuItem(v43, (int)&v66, 2, v7, (int)sub_133460, 0, 1);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)(v7 + 416) = sub_294900(a3);
	  v44 = (*(int (**)(void))(**(_DWORD **)(a5 + 56) + 8))();
	  sub_295430(v44);
	  v45 = (*(int (**)(void))(**(_DWORD **)(a5 + 60) + 8))();
	  sub_2951A0(v45);
	  v68 = 7;
	  v67 = 0;
	  LOWORD(v66) = 0;
	  sub_6F990(L"leftbutton", 10);
	  v46 = *(_DWORD *)(v7 + 416);
	  LOBYTE(v70) = 16;
	  _CUBE_GUI_ITEMS_AddMenuItem(v46, (int)&v66, 2, v7, (int)sub_133360, 0, 1);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)(v7 + 420) = sub_294900(a3);
	  v47 = (*(int (**)(void))(**(_DWORD **)(a6 + 56) + 8))();
	  sub_295430(v47);
	  v48 = (*(int (**)(void))(**(_DWORD **)(a6 + 60) + 8))();
	  sub_2951A0(v48);
	  v68 = 7;
	  v67 = 0;
	  LOWORD(v66) = 0;
	  sub_6F990(L"rightbutton", 11);
	  v49 = *(_DWORD *)(v7 + 420);
	  LOBYTE(v70) = 17;
	  _CUBE_GUI_ITEMS_AddMenuItem(v49, (int)&v66, 2, v7, (int)sub_133380, 0, 1);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)(v7 + 424) = sub_294900(a3);
	  v50 = (*(int (**)(void))(**(_DWORD **)(a5 + 56) + 8))();
	  sub_295430(v50);
	  v51 = (*(int (**)(void))(**(_DWORD **)(a5 + 60) + 8))();
	  sub_2951A0(v51);
	  v68 = 7;
	  v67 = 0;
	  LOWORD(v66) = 0;
	  sub_6F990(L"leftbutton", 10);
	  v52 = *(_DWORD *)(v7 + 424);
	  LOBYTE(v70) = 18;
	  _CUBE_GUI_ITEMS_AddMenuItem(v52, (int)&v66, 2, v7, (int)sub_133320, 0, 1);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)(v7 + 428) = sub_294900(a3);
	  v53 = (*(int (**)(void))(**(_DWORD **)(a6 + 56) + 8))();
	  sub_295430(v53);
	  v54 = (*(int (**)(void))(**(_DWORD **)(a6 + 60) + 8))();
	  sub_2951A0(v54);
	  v68 = 7;
	  v67 = 0;
	  LOWORD(v66) = 0;
	  sub_6F990(L"rightbutton", 11);
	  v55 = *(_DWORD *)(v7 + 428);
	  LOBYTE(v70) = 19;
	  _CUBE_GUI_ITEMS_AddMenuItem(v55, (int)&v66, 2, v7, (int)sub_133340, 0, 1);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)(v7 + 432) = sub_294900(a3);
	  v56 = (*(int (**)(void))(**(_DWORD **)(a5 + 56) + 8))();
	  sub_295430(v56);
	  v57 = (*(int (**)(void))(**(_DWORD **)(a5 + 60) + 8))();
	  sub_2951A0(v57);
	  v68 = 7;
	  v67 = 0;
	  LOWORD(v66) = 0;
	  sub_6F990(L"leftbutton", 10);
	  v58 = *(_DWORD *)(v7 + 432);
	  LOBYTE(v70) = 20;
	  _CUBE_GUI_ITEMS_AddMenuItem(v58, (int)&v66, 2, v7, (int)sub_133420, 0, 1);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)(v7 + 436) = sub_294900(a3);
	  v59 = (*(int (**)(void))(**(_DWORD **)(a6 + 56) + 8))();
	  sub_295430(v59);
	  v60 = (*(int (**)(void))(**(_DWORD **)(a6 + 60) + 8))();
	  sub_2951A0(v60);
	  sub_6EDA0(L"rightbutton");
	  v61 = *(_DWORD *)(v7 + 436);
	  LOBYTE(v70) = 21;
	  _CUBE_GUI_ITEMS_AddMenuItem(v61, (int)&v66, 2, v7, (int)sub_133430, 0, 1);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  *(_DWORD *)(v7 + 440) = sub_290F90(a3);
	  *(_DWORD *)(v7 + 444) = sub_290F90(a3);
	  *(_DWORD *)(v7 + 448) = sub_290F90(a3);
	  sub_28AE70(1121714176, 1097859072, 1);
	  sub_6EDA0(&off_36237C);
	  LOBYTE(v70) = 22;
	  sub_295390(&v66);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  sub_28AE70(1121714176, 1097859072, 1);
	  sub_6EDA0(L"OK");
	  LOBYTE(v70) = 23;
	  sub_295390(&v66);
	  LOBYTE(v70) = 3;
	  if ( v68 >= 8 )
		operator delete(v66);
	  sub_28AE70(1121714176, 1097859072, 1);
	  sub_6EDA0(L"Cancel");
	  LOBYTE(v70) = 24;
	  sub_295390(&v64);
	  LOBYTE(v70) = 3;
	  if ( v65 >= 8 )
		operator delete(v64);
	  sub_12EE70(2, v7, sub_133300, 0, 1, 1);
	  sub_12EE70(2, v7, sub_133480, 0, 1, 1);
	  sub_12EE70(2, v7, sub_1333A0, 0, 1, 1);
	  return v7;
	}
 */

//___security_cookie dd 0BB40E64Eh
DWORD ___security_cookie = 0x0BB40E64Eh;

std::string unk_35BCAC; // ??
 
// SUB @ 12EF90
int initHudItems() {
	int v7;  /* edi@1 */	int v8;  /* eax@3 */	int v9;  /* eax@3 */
	int v10; /* ecx@3 */	int v11; /* eax@5 */	int v12; /* eax@5 */	
	int v13; /* ecx@5 */	int v14; /* eax@7 */	int v15; /* eax@7 */	
	int v16; /* ecx@7 */	int v17; /* eax@9 */	int v18; /* eax@9 */
	int v19; /* ecx@9 */	int v20; /* eax@11 */	int v21; /* eax@11 */
	int v22; /* ecx@11 */	int v23; /* eax@13 */	int v24; /* eax@13 */
	int v25; /* ecx@13 */	int v26; /* eax@15 */	int v27; /* eax@15 */
	int v28; /* ecx@15 */	int v29; /* eax@17 */	int v30; /* eax@17 */
	int v31; /* ecx@17 */	int v32; /* eax@19 */	int v33; /* eax@19 */
	int v34; /* ecx@19 */	int v35; /* eax@21 */	int v36; /* eax@21 */
	int v37; /* ecx@21 */	int v38; /* eax@23 */	int v39; /* eax@23 */
	int v40; /* ecx@23 */	int v41; /* eax@25 */	int v42; /* eax@25 */
	int v43; /* ecx@25 */	int v44; /* eax@27 */	int v45; /* eax@27 */
	int v46; /* ecx@27 */	int v47; /* eax@29 */	int v48; /* eax@29 */
	int v49; /* ecx@29 */	int v50; /* eax@31 */	int v51; /* eax@31 */
	int v52; /* ecx@31 */	int v53; /* eax@33 */	int v54; /* eax@33 */
	int v55; /* ecx@33 */	int v56; /* eax@35 */	int v57; /* eax@35 */
	int v58; /* ecx@35 */	int v59; /* eax@37 */	int v60; /* eax@37 */
	int v61; /* ecx@37 */
	
	unsigned int v63;		/* [sp+Ch]  [bp-60h]@1  */
	void *v64; 				/* [sp+2Ch] [bp-40h]@43 */
	unsigned int v65; 		/* [sp+40h] [bp-2Ch]@43 */
	void *v66; 				/* [sp+44h] [bp-28h]@1  */
	int v67; 				/* [sp+54h] [bp-18h]@1  */
	unsigned int v68; 		/* [sp+58h] [bp-14h]@1  */
	unsigned int v69; 		/* [sp+5Ch] [bp-10h]@1  */
	int v70; 				/* [sp+68h] [bp-4h]@1   */
	int v71;				/* [sp+6Ch] [bp+0h]@1   */
	
	v69 		= (unsigned int)&v71 ^ __security_cookie;
	v63 		= (unsigned int)&v71 ^ __security_cookie;
	v7  		= (int)this;
	v68 		= 7;
	v67 		= 0;
	LOWORD(v66) = 0;
	
	sub_6F990((unsigned int)&v66, (int)this, &unk_35BCAC, 0);
	
	v70 		= 0;
	
	sub_285B60(a2, a3, &v66);
	
	
}


void CubeWorld::HUD::OptionsMenu::Init() {
	initHudItems();
}