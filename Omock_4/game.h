#ifndef _GAME_H_
#define _GAME_H_

#include "omock.h"
#include <iostream>
#include <vector>
#include <string>

class grid;

using namespace std;

class Game : public Omock
{
private:
	int x, y;
	vector<pair<int, int>> vecBlack;
	vector<pair<int, int>> vecWhite;
	int count, turn;
	char c;
	string stone;

public:
	Game();

	void getVec(vector<pair<int, int>> vecColor);

	void menu();
	void start();
	void inputKey();
	void direcKey(char input);
	bool inputCheck(vector<pair<int, int>> vecColor);
	void gotoxy(int x, int y);

	bool checkStone(int x, int y, vector<pair<int, int>> vecColor);
	int countStone(int dx, int dy, vector<pair<int, int>> vecColor);
	void over(int turn);
};

#endif // !_GAME_H_
