#include "user.h"
#include "game.h"
#include <iostream>
#include <string>
 
using namespace std;

User::User()
{
	this->name = " ";
	this->turn = 0;
}

void User::setID()
{
	cout << "사용자 이름을 입력해주세요 : ";
	cin >> this->name; 
}

void User::getWinnerID(int turn)
{
	if (turn % 2 == 0)
		cout << this->name << "이(가) 승리하였습니다." << endl;
	else if (turn % 2 == 1)
		cout << this->name << "이(가) 승리하였습니다." << endl;
}
