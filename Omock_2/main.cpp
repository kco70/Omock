#include <iostream>
#include <string>
#include <sstream>

#include "Design.h"
#include "Function.h"

using namespace std;

int main()
{
	int select = 0;

	Function Game;

	while (1)
	{
		cout << "1. 게임 시작" << endl;
		cout << "2. 게임 종료" << endl;

		cin >> select;

		if (select == 1)
		{
			cout << "게임을 시작합니다." << endl;
			Game.Play();
		}
		else if (select == 2)
		{
			cout << "게임을 종료합니다. " << endl;
			break;
		}
		else
			cout << "메뉴 내에서 입력해주세요." << endl;
	}

	return 0;
}