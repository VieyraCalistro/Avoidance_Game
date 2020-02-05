#pragma once
#include <vector>
#include "Base.h"
#include "Console.h"
#include "stdafx.h"
//#include "Player.h"

class Game
{
public:

	Game();

	~Game();

	void RealTimeUpdates();

	void Render();

	void Update();

	void Collision();

	double GetScore();

	int GetLives();

	bool GetPlayingStatus();

	void SetBaseList(Base* abase);


private:

	double score = 0;

	int lives = 15;

	bool _play = true;

	vector<Base*> BaseList;
};

