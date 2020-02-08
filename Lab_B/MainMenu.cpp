#include "pch.h"
#include "MainMenu.h"
#include <fstream>

using namespace std;



MainMenu::MainMenu()
{
}


MainMenu::~MainMenu()
{
	for (unsigned int index = 0; index < status.size(); index++)
	{
		delete status[index];
		status[index] = nullptr;
	}
	delete game;
}

void MainMenu::Play()
{
	int number;
	
	while (true)
	{
		Console::CursorVisible(true);

		system("cls");
		cout << "Welcome to Space Ship!" << endl;
		cout << endl;
		cout << "1). Play " << endl;
		cout << "2). See high scores " << endl;
		cout << "3). Quit " << endl;
		cout << endl;

		cin >> number;

		if (cin.good())
		{
			if (number == 3)
			{
				cout << endl;
				cout << "See Ya! " << endl;
				cout << endl;
				system("pause");
				Quit();
			}
			else if (number == 2)
			{
				TextIn();
				cout << endl;
				Play();
			}
			else if (number == 1)
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				StartGame();
			}
			
		}

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		cout << endl;
		cout << "Try again." << endl;
	}
	

	
}

void MainMenu::StartGame()
{
	Console::CursorVisible(false);

	// Insert gameloop
	for (;;)
	{
		game->RealTimeUpdates();
		
	}

}

void MainMenu::ScoreReview(double score)
{

	char viewScores;

	while (true)
	{
		system("cls");
		cout << "Current score: " << score << endl;
		cout << endl;
		cout << "Would you like to see your previous score(s)? " << endl;
		cout << endl;
		cout << "y or n? ";
		cin >> viewScores;
		cout << endl;

		viewScores = toupper(viewScores);

		if (viewScores == 'N')
		{
			PlayAgainQuestion();
		}
		if (viewScores == 'Y')
		{
			char save;

			system("cls");
			cout << "Previous Score: " << endl;
			cout << endl;
			TextIn();
			cout << endl;

			cin.clear();
			cin.ignore(INT_MAX, '\n');
			while (true)
			{
				cout << "would you like to custom save your high score? " << endl;
				cout << endl;
				cout << "y or n? ";

				cin >> save;
				save = toupper(save);

				if (save == 'N')
				{
					PlayAgainQuestion();
				}
				if (save == 'Y')
				{
					Textout(score);
					BinaryOut();
					cout << "saved!" << endl;
					cout << endl;
					system("pause");

					TextIn();

					PlayAgainQuestion();

				}
				if (viewScores != 'N' || viewScores != 'Y')
				{
					InvalidResponse();
					system("pause");
					continue;
				}
			}
			
		}
		if (viewScores != 'N' || viewScores != 'Y')
		{
			InvalidResponse();
			system("pause");
			continue;
		}
	}
	


}

void MainMenu::Quit()
{
	exit(0);
}

void MainMenu::Textout(double score)
{
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	cout << endl;

	status.push_back(new PlayerStats);

	cout << "Enter you name? ";
	cin >> status[0]->name;



	fstream outfile;

	outfile.open("Player Stats.txt", ios_base::out | ios_base::app);

	if (outfile.is_open())
	{
		
		outfile << status[0]->name << '\t' << score << '\n';
		

		outfile.close();

	}
	else
	{
		cout << "File is already open elsewhere.";
	}
}

void MainMenu::BinaryOut()
{
	SetPlayerStatsCounterinFile(GetPlayerStatsCounterinFile() + 1);

	fstream outFile;
	
	outFile.open("Binary Player Stats.txt", ios_base::app | ios_base::binary | ios_base::out);

	if (outFile.is_open())
	{
		outFile << GetPlayerStatsCounterinFile();
		outFile.write((char*)&status[0], sizeof(PlayerStats));

		outFile.close();
	}
	else
	{
		cout << "File is already open elsewhere. ";
	}
}

void MainMenu::TextIn()
{
	vector<PlayerStats> stats;
	PlayerStats player;

	ifstream infile;

	infile.open("Player Stats.txt", ios::in);

	if (infile.is_open())
	{
		while (true)
		{
			infile.getline(player.name, INT_MAX, '\t');
			if (infile.eof())
			{
				break;
			}
			infile >> player.score;
			infile.ignore(INT_MAX, '\n');

			stats.push_back(player);
		}
		infile.close();
	}
	else
	{
		cout << "Player Stats.txt file not found." << endl;
	}

	for (unsigned int index = 0; index < stats.size(); index++)
	{
		cout << "Name: " << stats[index].name << " Score: " << stats[index].score << endl;
		cout << endl;
	}
	
	system("pause");

}

void MainMenu::BinaryIn()
{
	ifstream inFile;

	inFile.open("Binary Player Stats.txt", ios_base::binary | ios_base::in);

	if (inFile.is_open())
	{
		int count;

		inFile.seekg(0, ios_base::beg);

		inFile.read((char*)&count, sizeof(int)/* Reading the integer at the top of the list to see how many PlayerStats we have*/);

		status.resize(count);

		inFile.read((char*)&status[0], status.size() * count);

		inFile.close();
	}
	else
	{
		cout << "File is already open elsewhere. ";
	}
}


void MainMenu::InvalidResponse()
{
	cout << "Invalid response. " << endl;
	cout << endl;

	cin.clear();
	cin.ignore(INT_MAX, '\n');
}

void MainMenu::PlayAgainQuestion()
{
	char answer;

	while (true)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		system("cls");

		cout << "Would you like to play again? " << endl;
		cout << "y or n? ";

		cin >> answer;
		answer = toupper(answer);

		
		if (answer == 'N')
		{
			cout << "Thanks for playing! " << endl;
			system("pause");
			Quit();
		}
		if (answer == 'Y')
		{
			StartGame();
		}
		if (answer != 'N' || answer != 'Y')
		{
			InvalidResponse();
			system("pause");
			continue;
		}
	}
}

int MainMenu::GetPlayerStatsCounterinFile()
{
	return PlayerStatsCounterinfile;
}

void MainMenu::SetPlayerStatsCounterinFile(int numberOfFiles)
{
	PlayerStatsCounterinfile = numberOfFiles;
}


void MainMenu::GameOver(double score)
{
	system("cls");
	Console::CursorVisible(true);
	ScoreReview(score);
}
