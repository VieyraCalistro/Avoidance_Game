#include "pch.h"
#include "Console.h"
#include "Player.h"
#include "Game.h"
#include "Obstacle.h"
#include "MainMenu.h"
using namespace std;
using namespace System;

Game::Game()
{
	Console::SetWindowSize(90, 40);

	Console::SetBufferSize(90, 40);

	// Player will be assigned in position [0]
	BaseList.push_back(new Player('@'));

	for (unsigned int index = 0; index < 40; index++)
	{
		BaseList.push_back(new Obstacle('#'));
	}

}


Game::~Game()
{
	for (unsigned int index = 0; index < BaseList.size(); index++)
	{
		delete BaseList[index];
		BaseList[index] = nullptr;
	}
	
}

void Game::RealTimeUpdates()
{
	Update();
	Render();
	Collision();
}

void Game::Update()
{
	if (_play)
	{
		for (unsigned int index = 0; index < BaseList.size(); index++)
		{
			BaseList[index]->Update();
		}
	}
	
}

void Game::Collision()
{
	MainMenu isGameOver;

	if (_play)
	{
		for (unsigned int index = 0; index < BaseList.size(); index++)
		{
			Base* player = dynamic_cast<Player*>(BaseList[index]);

			if (player != 0)
			{
				for (unsigned int index = 0; index < BaseList.size(); index++)
				{
					if (BaseList[index]->GetYPos() == Console::WindowHeight() - 1)
					{
						if (BaseList[index] != player)
						{
							BaseList[index]->SetYPos(0);
							BaseList[index]->SetXPos(1 + (rand() % 90));
							score += 0.1;
						}
					}
					else if ((BaseList[index]->GetXPos() == player->GetXPos()) && (BaseList[index]->GetYPos() == player->GetYPos()))
					{
						if (BaseList[index] != player)
						{
							BaseList[index]->SetYPos(0);
							BaseList[index]->SetXPos(1 + (rand() % 90));
							if (score > 0)
							{
								score--;

								if (lives < 1)
								{
									// End game if player runs out of lives.
									_play = false;
									isGameOver.GameOver(score);
								}

								lives--;
							}
							else
							{
								score = 0;

								if (lives < 1)
								{
									// End game if player runs out of lives.
									_play = false;
									isGameOver.GameOver(score);
								}

								lives--;
							}
						}




					}

				}
			}

		}
	}
	
}

double Game::GetScore()
{
	return score;
}

int Game::GetLives()
{
	return lives;
}

bool Game::GetPlayingStatus()
{
	return true;
}

void Game::SetBaseList(Base * abase)
{
	BaseList.push_back(abase);
}

void Game::Render()
{
	if (_play)
	{
		Console::Lock(true);
		Console::Clear();

		for (unsigned int index = 0; index < BaseList.size(); index++)
		{
			BaseList[index]->Render();
		}

		Console::SetCursorPosition(Console::WindowWidth() / 3, 0);
		cout << "Score: " << score << " Lives: " << lives << endl;
		Console::Lock(false);
		Sleep(10);
	}
}