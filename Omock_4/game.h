#pragma once
#ifndef _GAME_H_

#include "omock.h"
#include <iostream>
#include <vector>
#include <string>

class grid;

using namespace std;

class Game : public Omock
{
public:
	Game();

	int getX();
	int getY();

	void menu();
	void start();
	void inputKey();
	void direcKey(char input);
	void palceStone(int count);
	bool inputCheck(int x, int y);
	void gotoxy(int x, int y);

	vector<pair<int, int>> swapXY(vector<pair<int, int>> vec);
	void winnerCheck(vector<pair<int, int>> vec);
	int over();
};

#else
#endif // !_GAME_H_
