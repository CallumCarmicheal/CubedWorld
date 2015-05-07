#include "Events.h"


void Events::onPlayerEat(float regenAmount){
	Console::Write("[EVENT] onPlayerEat(rgn ");

	wchar_t buffer[256]; wsprintfW(buffer, L"%d", regenAmount);
	Console::Write(buffer);

	Console::Write(") \n");
}

void Events::onPlayerAttacked(float damage){

}

void Events::onPlayerDamaged(float damage){

}


void Events::onPlayerCraft(){

}

void Events::onPlayerConnect(char* name){

}

void Events::onPlayerCast(){

}

void Events::onPlayerAttack(){

}

void Events::onPlayerEXP(float exp){

}

void Events::onPlayerLVL(){

}

// --------------------------------------------------

void Events::onPetEat(){

}

void Events::onPetEXP(float exp){

}

void Events::onPetLVL(){

}
