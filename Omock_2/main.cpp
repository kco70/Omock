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
		cout << "1. ���� ����" << endl;
		cout << "2. ���� ����" << endl;

		cin >> select;

		if (select == 1)
		{
			cout << "������ �����մϴ�." << endl;
			Game.Play();
		}
		else if (select == 2)
		{
			cout << "������ �����մϴ�. " << endl;
			break;
		}
		else
			cout << "�޴� ������ �Է����ּ���." << endl;
	}

	return 0;
}