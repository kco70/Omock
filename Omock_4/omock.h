#pragma once
#ifndef _OMOCK_H_

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
#define X_MAX 27
#define Y_MAX 10
#define MAX 10

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Omock
{
protected:
	int x, y;
	vector<pair<int, int>> vec;
	int count, turn;
	int currentX;
	char c;
	string stone;

public :
	virtual int getX() = 0;
	virtual int getY() = 0;

	virtual void menu() = 0;
	virtual void start() = 0;
	virtual void inputKey() = 0;
	virtual void direcKey(char input) = 0;
	virtual void palceStone(int count) = 0;
	virtual bool inputCheck(int x, int y) = 0;
	virtual void gotoxy(int x, int y) = 0;

	virtual vector<pair<int, int>> swapXY(vector<pair<int, int>> vec) = 0;
	virtual void winnerCheck(vector<pair<int, int>> vec) = 0;
	virtual int over() = 0;
};

#else
#endif // _OMOCK_H_