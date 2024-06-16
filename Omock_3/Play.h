#pragma once
#ifndef _PLAY_H_

#define MAX 10;

#include "Play.h"
#include "Map.h"
#include "Move.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <utility>
 
class Play
{
private:
	int x, y;
	int count;
	bool flag;
	int currentX;
	vector<pair<int, int>> vec;
	char c;

	Move m;

public:
	Play();

	void start();
	void getXY(int x, int y);
	vector<pair<int, int>> swapXY(vector<pair<int, int>> vec);
	void winCheck(vector<pair<int, int>> vec); 
	void winner(int count);
	void gameover();

	~Play();
};


#else
#endif // !_PLAY_H_