#pragma once
# include "Game.h"

struct PlayerStats
{
	char name[32];
	float score = 0;
};

class MainMenu:Game
{
public:
	MainMenu();
	~MainMenu();

	void Play();

	void StartGame();

	void Quit();

	void TextIn();

	void BinaryIn();

	void Textout(double score);

	void BinaryOut();

	void ScoreReview(double score);

	void InvalidResponse();

	void PlayAgainQuestion();

	void GameOver(double score);

	vector<PlayerStats*> status;

	// Make an instance of Game.
	Game* game = new Game();

	int GetPlayerStatsCounterinFile();
	void SetPlayerStatsCounterinFile(int numberOfFiles);

private:

	int PlayerStatsCounterinfile = 0;
};

