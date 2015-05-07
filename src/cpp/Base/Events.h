#include <windows.h>
#include <fcntl.h>
#include <stdio.h>
#include <io.h>
#include <string>

#include "Console.h"

#pragma once
class Events
{
public:
	Events();

	void onPlayerEat(float regenAmount);
	void onPlayerAttacked(float damage);
	void onPlayerDamaged(float damage);
	void onPlayerCraft();
	void onPlayerConnect(char* name);
	void onPlayerChat(char* message);
	void onPlayerCast();
	void onPlayerAttack();
	void onPlayerEXP(float exp);
	void onPlayerLVL();

	void onPetEat();
	void onPetEXP(float exp);
	void onPetLVL();

	void onChat(char* ply, char* message);
};

