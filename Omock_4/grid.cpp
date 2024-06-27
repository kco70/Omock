#include "grid.h"
#include "game.h"
#include <iostream>

using namespace std;

void Grid::drawMap()
{
	this->x = 0;
	this->y = 0;

	for (; x < 10; x++)
	{
		// y = 0�� x ���� ���� ��ȣ (0 ~ 9)
		cout << x << " ";

		// x = 0�� y ���� ���� ��ȣ (0 ~ 9)
		if (x == 0)
		{
			for (int y = 1; y < 10; y++)
			{
				cout << y << "  ";
			}
		}
		// x = 1 �� ��� �𼭸� (��������)
		else if (x == 1)
		{
			for (int y = 1; y < MAX; y++)
			{
				if (y == 1)
					cout << "��-";
				else if (y == MAX - 1)
					cout << "-��";
				else
					cout << "-��-";
			}

		}
		// x = 9 �� �ϴ� �𼭸� (��������)
		else if (x == 9)
		{
			for (int y = 1; y < MAX; y++)
			{
				if (y == 1)
					cout << "��-";
				else if (y == MAX - 1)
					cout << "-��";
				else
					cout << "-��-";
			}
		}
		// x = 2 ~ 9 �� �ߴ� (��������)
		else
		{
			for (int y = 1; y < MAX; y++)
			{
				if (y == 1)
					cout << "��-";
				else if (y == MAX - 1)
					cout << "-��";
				else
					cout << "-��-";
			}
		}
		cout << endl;
	}
}
