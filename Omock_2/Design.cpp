#include <iostream>
#include "Design.h"

using namespace std;

Design::Design()
{

}

void Design::Basic()
{
	// (0,0) ~ (0,9)�� ���� �Ҵ�
	for (int y = 0; y < 10; y++)
	{
		ui_map[0][y] = '0' + y;
	}

	// (1,0) ~ (9,9) �Ҵ�
	for (int y = 0; y < 10; y++)
	{
		// (1,0) ~ (9,0)�� ���� �Ҵ�
		if (y == 0)
		{
			for (int x = 0; x < 10; x++)
			{
				ui_map[x][0] = '0' + x;
			}
		}
		// (2,1) ~ (2,9)�� ��� �𼭸� �Ҵ�
		else if (y == 1)
		{
			for (int x = 1; x < 10; x++)
			{
				if (x == 1)
					ui_map[x][y] = '+'; //��
				else if (x == 9)
					ui_map[x][y] = '+'; // ��
				else
					ui_map[x][y] = '+'; // ��
			}
		}
		// (9,1) ~ (9,9)�� �ϴ� �𼭸� �Ҵ�
		else if (y == 9)
		{
			for (int x = 1; x < 10; x++)
			{
				if (x == 1)
					ui_map[x][y] = '+'; //��
				else if (x == 9)
					ui_map[x][y] = '+'; // ��
				else
					ui_map[x][y] = '+'; // ��
			}
		}
		// (3,1) ~ (8,9)�� �߾� ���� �Ҵ� 
		else
		{
			for (int x = 1; x < 10; x++)
			{
				if (x == 1)
					ui_map[x][y] = '+'; //��
				else if (x == 9)
					ui_map[x][y] = '+'; // ��
				else
					ui_map[x][y] = '+'; // ��
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << ui_map[i][j] << "  ";
		}
		cout << endl;
	}
}

void Design::ChangeColor(int x, int y, char color)
{
	if (color == 'B')
	{
		ui_map[x][y] = 'B';
	}
	else if (color == 'W')
	{
		ui_map[x][y] = 'W';
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << ui_map[i][j] << "  ";
		}
		cout << endl;
	}
}

Design::~Design()
{

}