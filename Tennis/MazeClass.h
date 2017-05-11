#pragma once
#ifndef MAZECLASS_H_INCLUDED
#define MAZECLASS_H_INCLUDED
#include<vector>
class MazeClass
{public://the class functions
	void LoadingMazefromFile(string mazeLevel);
	void PrintMaze();
	void MovePlayer();
	int ReturnNumberMoves();
protected:
	//the main vector which stores the maze matrix
	vector< vector<char> > MazeMatrix;
	//the memorized coordinates for the player
	int iPlayer, jPlayer,countMoves;
};
#endif