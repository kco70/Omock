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
	cout << "����� �̸��� �Է����ּ��� : ";
	cin >> this->name; 
}

void User::getWinnerID(int turn)
{
	if (turn % 2 == 0)
		cout << this->name << "��(��) �¸��Ͽ����ϴ�." << endl;
	else if (turn % 2 == 1)
		cout << this->name << "��(��) �¸��Ͽ����ϴ�." << endl;
}
