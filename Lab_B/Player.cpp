#include "pch.h"
#include "Console.h"
#include "Player.h"
#include <ctime>
#include <time.h>


Player::Player()
{
}

Player::Player(char aimage)
{
	SetImage(aimage);
	SetXPos(Console::WindowWidth() / 2);
	SetYPos(30);
}


Player::~Player()
{

}


void Player::Update()
{
	/*if (GetAsyncKeyState(VK_SPACE))
	{
		SetLaunched(true);

	}*/

	/*if (GetLaunched() == true)
	{
		Console::Show(GetProjectileXPos(), GetProjectileYPos(), GetProjectileCharacter());
		SetProjectileXPos(GetXPos());

		SetProjectileYPos(GetProjectileYPos() - 1);
		Sleep(10);
	}*/
	

	if (GetAsyncKeyState(VK_UP))
	{
		if (GetYPos() < 0)
		{
			SetYPos(0);
		}
		else
		{
			SetYPos(GetYPos()- 1);
		}
		
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		if (GetYPos() > Console::WindowHeight())
		{
			SetYPos(Console::WindowHeight());
		}
		else
		{
			SetYPos(GetYPos() + 1);
		}
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		// Prevent player from hiding on the edge only!
		if (GetXPos() < 2)
		{
			SetXPos(2);
		}
		else
		{
			SetXPos(GetXPos() - 1);
		}
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		// Prevent player from hiding on the edge only!
		if (GetXPos() > Console::WindowWidth()-3)
		{
			SetXPos(Console::WindowWidth()-3);
		}
		else
		{
			SetXPos(GetXPos() + 1);
		}
		
	}
}

void Player::Render()
{
	
	Console::Show(GetXPos(), GetYPos(), GetImage());

	//SetLaunched(false);
}

char Player::GetPlayerCharacter()
{
	return _playerCharacter;
}

void Player::SetPlayerCharacter(char aPlayerCharacter)
{
	_playerCharacter = aPlayerCharacter;
}

//char Player::GetProjectileCharacter()
//{
//	return projectileCharacter;
//}
//
//void Player::SetProjectileCharatcer(char aProjectileCharacter)
//{
//	projectileCharacter = aProjectileCharacter;
//}
//
//bool Player::GetLaunched()
//{
//	return launched;
//}
//
//void Player::SetLaunched(bool aLaunched)
//{
//	launched = aLaunched;
//}
