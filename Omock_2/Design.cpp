#include <iostream>

#include "Design.h"

using namespace std;

Design::Design()
{

}

void Design::GridMap(int inx, int iny, char color)
{
	for (int x = 0; x < 10; x++)
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
			for (int y = 1; y < 10; y++)
			{
				if (x == inx && y == iny)
				{
					if (color == 'B')
						cout << " " << "��" << " ";
					else if (color == 'W')
						cout << " " << "��" << " ";
				}
				else if (y == 1)
					cout << "��-";
				else if (y == 9)
					cout << "-��";
				else
					cout << "-��-";
			}

		}
		// x = 9 �� �ϴ� �𼭸� (��������)
		else if (x == 9)
		{
			for (int y = 1; y < 10; y++)
			{
				if (x == inx && y == iny)
				{
					if (color == 'B')
						cout << " " << "��" << " ";
					else if (color == 'W')
						cout << " " << "��" << " ";
				}
				else if (y == 1)
					cout << "��-";
				else if (y == 9)
					cout << "-��";
				else
					cout << "-��-";
			}
		}
		// x = 2 ~ 9 �� �ߴ� (��������)
		else
		{
			for (int y = 1; y < 10; y++)
			{
				if (x == inx && y == iny)
				{
					if (color == 'B')
						cout << " " << "��" << " ";
					else if (color == 'W')
						cout << " " << "��" << " ";
				}
				else if (y == 1)
					cout << "��-";
				else if (y == 9)
					cout << "-��";
				else
					cout << "-��-";
			}
		}
		cout << endl;
	}
}


Design::~Design()
{

}