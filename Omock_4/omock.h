#ifndef _OMOCK_H_
#define _OMOCK_H_

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
public :
	virtual void getVec(vector<pair<int, int>> vecColor) = 0;
	
	virtual void menu() = 0;
	virtual void start() = 0;
	virtual void inputKey() = 0;
	virtual void direcKey(char input) = 0;
	virtual bool inputCheck(vector<pair<int, int>> vecColor) = 0;
	virtual void gotoxy(int x, int y) = 0;

	virtual bool checkStone(int x, int y, vector<pair<int, int>> vecColor) = 0;
	virtual int countStone(int dx, int dy, vector<pair<int, int>> vecColor) = 0;
	virtual void over(int turn) = 0;
};

#endif // _OMOCK_H_