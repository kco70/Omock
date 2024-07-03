#ifndef _PALYER_H_
#define _PALYER_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player
{
public:
	virtual void setID() = 0;
	virtual void getWinnerID(int turn) = 0;
};

#endif // !_PALYER_H_
