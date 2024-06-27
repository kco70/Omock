#pragma once
#ifndef _USER_H_

#include <iostream>
#include <string>
#include "player.h"

using namespace std;

class User : public Player
{
public : 
	User();

	void setID();
	void getWinnerID(int turn);
};

#endif // !_USER_H_



