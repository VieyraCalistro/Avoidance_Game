#include "pch.h"
#include "Obstacle.h"
#include "Console.h"
#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include <chrono>

using namespace std;

Obstacle::Obstacle()
{
	
}
Obstacle::Obstacle(char aimage)
{
	SetImage(aimage);
	SetXPos(1 + (rand()% 100));
	SetYPos(rand()% 15);

}

Obstacle::~Obstacle()
{
}

void Obstacle::Update()
{
	SetYPos(GetYPos() + 1);

	if (GetYPos() == Console::WindowHeight())
	{
		SetXPos(1 + (rand()% 100));
		SetYPos(rand ()% 15);
	}
	
	
}

void Obstacle::Render()
{
	Console::Show(GetXPos(), GetYPos(), GetImage());
}