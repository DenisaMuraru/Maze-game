#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include<conio.h>
#include<Windows.h>
using namespace std;
#include"MazeClass.h"
void MazeClass::LoadingMazefromFile(string mazeLevel)
{
	countMoves = 0;
	MazeMatrix.clear();

	//open file with the maze
	ifstream file(mazeLevel);
	for (int i = 0; !file.eof(); i++) {
		//temporary string and vector and reading
		string temporary;
		vector<char> tempVector;

		//read one line of values into temporary string
		getline(file, temporary);

		//all string characters added to temporary vector
		for (int j = 0;j < temporary.size();j++) {
			//if the read value is the player character, this remembers it's coordinates
			if (temporary[j] == 'o')
			{
				iPlayer = i;
				jPlayer = j;
			}
			tempVector.push_back(temporary[j]);//this adds the temporary vector to the main vector, MazeMatrix
		}

		//adding a row of chars to our main vector(the matrix)
		MazeMatrix.push_back(tempVector);
	}
	file.close();
}
void MazeClass::PrintMaze()
{
	system("cls");//this clears the screen every time before printing the next maze
	cout << countMoves << endl;
				  //prints the maze
	for (int i = 0; i < MazeMatrix.size(); i++)
	{
		for (int j = 0; j < MazeMatrix[i].size(); j++) 
		{
			if (MazeMatrix[i][j] == '_' || MazeMatrix[i][j] == 'x')//if the position we are trying to print is _ ,
				cout << ' ';//on the screen it will be an empty space
			else if (MazeMatrix[i][j] == '*')
				cout << char(177);
			else
				cout << char(207);//otherwise it prints the wall or the player
		}
		cout << endl;
	}
}
void MazeClass::MovePlayer()
{

	char aux;
	int KeyInput = 0;
	//the loop for moving the player which ends when the exit is reached
	while (1)
	{//allows user to input a key
		KeyInput = getch();

		if (KeyInput == 72 && MazeMatrix[iPlayer - 1][jPlayer] != '*' && MazeMatrix[iPlayer - 1][jPlayer] != 'x')//up if there's no wall
		{//exchanges the player with the emty space
			aux = MazeMatrix[iPlayer][jPlayer];
			MazeMatrix[iPlayer][jPlayer] = MazeMatrix[iPlayer - 1][jPlayer];
			MazeMatrix[iPlayer - 1][jPlayer] = aux;
			iPlayer--;
			countMoves++;
			PrintMaze();
		}
		else
			if (KeyInput == 80 && MazeMatrix[iPlayer + 1][jPlayer] != '*' && MazeMatrix[iPlayer + 1][jPlayer] != 'x')//down if there's no wall
			{//exchanges the player with the emty space
				aux = MazeMatrix[iPlayer][jPlayer];
				MazeMatrix[iPlayer][jPlayer] = MazeMatrix[iPlayer + 1][jPlayer];
				MazeMatrix[iPlayer + 1][jPlayer] = aux;
				iPlayer++;
				countMoves++;
				PrintMaze();
			}
			else
				if (KeyInput == 75 && MazeMatrix[iPlayer][jPlayer - 1] != '*' && MazeMatrix[iPlayer][jPlayer - 1] != 'x')//left if there's no wall
				{//exchanges the player with the emty space
					aux = MazeMatrix[iPlayer][jPlayer];
					MazeMatrix[iPlayer][jPlayer] = MazeMatrix[iPlayer][jPlayer - 1];
					MazeMatrix[iPlayer][jPlayer - 1] = aux;
					jPlayer--;
					countMoves++;
					PrintMaze();
				}
				else
					if (KeyInput == 77 && MazeMatrix[iPlayer][jPlayer + 1] != '*' && MazeMatrix[iPlayer][jPlayer + 1] != 'x')//right if there's no wall
					{//exchanges the player with the emty space
						aux = MazeMatrix[iPlayer][jPlayer];
						MazeMatrix[iPlayer][jPlayer] = MazeMatrix[iPlayer][jPlayer + 1];
						MazeMatrix[iPlayer][jPlayer + 1] = aux;
						jPlayer++;
						countMoves++;
						PrintMaze();
					}
					else
						if (KeyInput == 72 && MazeMatrix[iPlayer - 1][jPlayer] == 'x')//if the x is up
						{
							countMoves++;
							break;
						}
						else
							if (KeyInput == 80 && MazeMatrix[iPlayer + 1][jPlayer] == 'x')//if the x is down
							{
								countMoves++;
								break;
							}
							else
								if (KeyInput == 75 && MazeMatrix[iPlayer][jPlayer - 1] == 'x')//if the x is left
								{
									countMoves++;
									break;
								}
								else
									if (KeyInput == 77 && MazeMatrix[iPlayer][jPlayer + 1] == 'x')//if the x is right
									{
										countMoves++;
										break;
									}
	}

}
int MazeClass::ReturnNumberMoves()
{
	 return countMoves;
}
