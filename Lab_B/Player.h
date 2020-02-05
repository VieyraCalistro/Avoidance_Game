#pragma once
#include "Base.h"
#include "Console.h"
#include "stdafx.h"
class Player : public Base
{
public:
	Player();

	Player(char aimage);

	~Player();

	void Update();

	void Render();

	char GetPlayerCharacter();
	void SetPlayerCharacter(char aPlayerCharacter);

	//char GetProjectileCharacter();
	//void SetProjectileCharatcer(char aProjectileCharacter);

	//bool GetLaunched();
	//void SetLaunched(bool aLaunched);

private:

	char _playerCharacter;

	char projectileCharacter = '!';

	bool launched;
};

