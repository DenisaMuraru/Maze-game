#include <iostream>
#include <vector>
#include <fstream>
#include<conio.h>
#include<string>
#include<Windows.h>
#include <ctime>
#include <string>
using namespace std;
#include"MazeClass.h"


struct HighScores {
	double time;
	int moves;
};

void DisplayMenu()
{
	cout << "MENU" << endl<<endl;
	cout << "1. Choose Level and Play" << endl;
	cout << "2. View High Scores" << endl;
	cout << "3. Exit" << endl;
}

void DisplayLevelMenu()
{
	cout << "1. Easy" << endl;
	cout << "2. Medium" << endl;
	cout << "3. Hard" << endl;
	cout << "4. Back" << endl;
}

int MazeLevel(string mazeLevel)
{
	MazeClass maze;
	maze.LoadingMazefromFile(mazeLevel);
	maze.PrintMaze();
	maze.MovePlayer();
	return maze.ReturnNumberMoves();
}

void HighScoresFile(double time, int moves, string level_name)
{
	ofstream highScores("highscores.txt", ios::app);
	highScores <<time << "," << moves << ","<<level_name<<endl;
}

int main()
{
	HighScores easyScores[100], mediumScores[100], hardScores[100];
	int TotalMoves = 0;
	double time;
	MazeClass maze;

	int KeyInput = 0,KeyInput2=0;
	while (KeyInput != '3')
	{
		system("cls");
		DisplayMenu();
		KeyInput = getch();
		KeyInput2 = 0;
		if (KeyInput == '1')
			while (KeyInput2 != '4')
			{
				system("cls");
				DisplayLevelMenu();
				KeyInput2 = getch();
				if (KeyInput2 == '1')
				{
					clock_t start = clock();
					TotalMoves=MazeLevel("easymaze1.txt")+ MazeLevel("easymaze2.txt")+ MazeLevel("easymaze3.txt");
					time = (clock() - start) / (double)CLOCKS_PER_SEC;
					HighScoresFile(time, TotalMoves, "easy");
					cout << "Number of moves: " << TotalMoves << endl;
					cout << "Time: " << time << endl;
					getch();
					break;
				}
				else if (KeyInput2 == '2') 
				{
					clock_t start = clock();
					TotalMoves=MazeLevel("mediummaze1.txt")+ MazeLevel("mediummaze2.txt")+ MazeLevel("mediummaze3.txt");
					time = (clock() - start) / (double)CLOCKS_PER_SEC;
					HighScoresFile(time, TotalMoves, "medium");
					cout << "Number of moves: " << TotalMoves << endl;
					cout << "Time: " << time << endl;
					getch();
					break;
				}
				else if (KeyInput2 == '3')
				{
					clock_t start = clock();
					TotalMoves = MazeLevel("hardmaze1.txt") + MazeLevel("hardmaze2.txt") + MazeLevel("hardmaze3.txt");
					time = (clock() - start) / (double)CLOCKS_PER_SEC;
					HighScoresFile(time, TotalMoves, "hard");
					cout << "Number of moves: " << TotalMoves << endl;
					cout << "Time: " << time << endl;
					getch();
					break;
				}
			}
		else 
			if (KeyInput == '2') 
			{
				while (KeyInput2 != '4')
				{
					system("cls");
					DisplayLevelMenu();
					KeyInput2 = getch();
					if (KeyInput2 == '1')
					{
						//reading from file
						ifstream highScores("highscores.txt");
						int count = 0;
						while (!highScores.eof()) {
							string temp;
							double tempTime;
							int tempMoves;
							getline(highScores, temp, ',');
							//temp string converted to double and saved in scores structure
							tempTime = atof(temp.c_str());
							getline(highScores, temp, ',');
							//temp string converted to int and saved in scores structure
							tempMoves = atoi(temp.c_str());
							getline(highScores, temp);
							if (temp == "easy") {
								easyScores[count].time = tempTime;
								easyScores[count].moves = tempMoves;
								count++;
							}
						}

						//sorting the scores
						int ok;
						do {
							ok = 1;
							for (int i = 0; i < count - 1; i++) 
								if (easyScores[i].moves > easyScores[i + 1].moves ||
									(easyScores[i].moves == easyScores[i + 1].moves && easyScores[i].time > easyScores[i + 1].time)) {
									HighScores aux = easyScores[i];
									easyScores[i] = easyScores[i + 1];
									easyScores[i + 1] = aux;
									ok = 0;
								}
							
						} while (ok == 0);

						//print scores
						system("cls");
						for (int i = 0; i < count; i++) {
							cout << i + 1 << ". " << easyScores[i].moves << ", " << easyScores[i].time << endl;
						}
						getch();
						break;
					}
					else if (KeyInput2 == '2')
					{
						//reading from file
						ifstream highScores("highscores.txt");
						int count = 0;
						while (!highScores.eof()) {
							string temp;
							double tempTime;
							int tempMoves;
							getline(highScores, temp, ',');
							//temp string converted to double and saved in scores structure
							tempTime = atof(temp.c_str());
							getline(highScores, temp, ',');
							//temp string converted to int and saved in scores structure
							tempMoves = atoi(temp.c_str());
							getline(highScores, temp);
							if (temp == "medium") {
								mediumScores[count].time = tempTime;
								mediumScores[count].moves = tempMoves;
								count++;
							}
						}

						//sorting the scores
						int ok;
						do {
							ok = 1;
							for (int i = 0; i < count - 1; i++)
								if (mediumScores[i].moves > mediumScores[i + 1].moves ||
									(mediumScores[i].moves == mediumScores[i + 1].moves && mediumScores[i].time > mediumScores[i + 1].time)) {
									HighScores aux = mediumScores[i];
									mediumScores[i] = mediumScores[i + 1];
									mediumScores[i + 1] = aux;
									ok = 0;
								}

						} while (ok == 0);

						//print scores
						system("cls");
						for (int i = 0; i < count; i++) {
							cout << i + 1 << ". " << mediumScores[i].moves << ", " << mediumScores[i].time << endl;
						}
						getch();
						break;
					}
					else if (KeyInput2 == '3')
					{
						//reading from file
						ifstream highScores("highscores.txt");
						int count = 0;
						while (!highScores.eof()) {
							string temp;
							double tempTime;
							int tempMoves;
							getline(highScores, temp, ',');
							//temp string converted to double and saved in scores structure
							tempTime = atof(temp.c_str());
							getline(highScores, temp, ',');
							//temp string converted to int and saved in scores structure
							tempMoves = atoi(temp.c_str());
							getline(highScores, temp);
							if (temp == "hard") {
								hardScores[count].time = tempTime;
								hardScores[count].moves = tempMoves;
								count++;
							}
						}

						//sorting the scores
						int ok;
						do {
							ok = 1;
							for (int i = 0; i < count - 1; i++)
								if (hardScores[i].moves > hardScores[i + 1].moves ||
									(hardScores[i].moves == hardScores[i + 1].moves && hardScores[i].time > hardScores[i + 1].time)) {
									HighScores aux = hardScores[i];
									hardScores[i] = hardScores[i + 1];
									hardScores[i + 1] = aux;
									ok = 0;
								}

						} while (ok == 0);

						//print scores
						system("cls");
						for (int i = 0; i < count; i++) {
							cout << i + 1 << ". " << hardScores[i].moves << ", " << hardScores[i].time << endl;
						}
						getch();
						break;
					}
				}
				
			}
			
	}

	return 0;
}