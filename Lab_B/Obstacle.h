#pragma once
#include "Console.h"
#include "stdafx.h"
#include "Base.h"
class Obstacle : public Base
{
public:
	Obstacle();

	Obstacle(char image);

	~Obstacle();

	void Update();
	void Render();
};

