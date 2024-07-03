#ifndef _USER_H_
#define _USER_H_

#include <iostream>
#include <string>
#include "player.h"

using namespace std;

class User : public Player
{
private :
	string name;
	int turn;

public : 
	User();

	void setID();
	void getWinnerID(int turn);
};

#endif // !_USER_H_



