#pragma once
#ifndef _PALYER_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player
{
protected:
	string name;
	int turn;

public:
	virtual void setID() = 0;
	virtual void getWinnerID(int turn) = 0;

};

#else
#endif // !_PALYER_H_
