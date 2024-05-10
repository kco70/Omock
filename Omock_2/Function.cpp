#include <iostream>
#include <string>
#include <sstream>

#include "Function.h"

using namespace std;

Function::Function()
{

}

char Function::BlockPlay(int x, int y)
{
	this->x = x;
	this->y = y;

	while (1)
	{
		if (map[x][y] == 0)
		{
			color = 'B';
			map[x][y] = color;
			break;
		}
		else
			cout << "�̹� �Էµ� ��ǥ�Դϴ�." << endl;
	}

	return color;
}

char Function::WhitePlay(int x, int y)
{
	this->x = x;
	this->y = y;

	while (1)
	{
		if (map[x][y] == 0)
		{
			color = 'W';
			map[x][y] = color;
			break;
		}
		else
			cout << "�̹� �Էµ� ��ǥ�Դϴ�." << endl;
	}

	return color;
}

int Function::CheckWin(int x, int y)
{
	//cout << endl;
	//cout << "verical check" << endl;

	// ������ ���� üũ
	for (int i = -4; i < 5; i++)
	{
		if (x + i < 10 && 0 <= x + i)
		{
			if (map[x][y] == map[x + i][y]) 
			{
				check++;
				//cout << map[x][y] << " : " << map[x + i][y] << endl;
				//cout << "check = " << check << endl;
			}
			else
			{
				check = 0;
				//cout << map[x][y] << " : " << map[x + i][y] << endl;
				//cout << "check = " << check << endl;
			}
		}

		if (check == 5)
		{
			flag = 1;
			break;
		}
	}

	//cout << endl;
	//cout << "horizontal check" << endl;

	// ������ ���� üũ
	for (int j = -4; j < 5; j++)
	{
		if (y + j < 10 && 0 <= y + j)
		{
			if (map[x][y] == map[x][y + j]) 
			{
				check++;
				//cout << map[x][y] << " : " << map[x][y + j] << endl;
				//cout << "check = " << check << endl;
			}
			else
			{
				check = 0;
				//cout << map[x][y] << " : " << map[x][y + j] << endl;
				//cout << "check = " << check << endl;
			}
		}

		if (check == 5)
		{
			flag = 1;
			break;
		}
	}

	//cout << endl;
	//cout << "cross_1 check" << endl;

	// /�밢�� ���� üũ
	for (int i = -4; i < 5; i++)
	{
		for (int j = -4; j < 5; j++)
		{
			if (x + i < 10 && 0 <= x + i && y + j < 10 && 0 <= y + j)
			{
				if (map[x][y] == map[x + i][y - j])
				{
					check++;
					//cout << map[x][y] << " : " << map[x+i][y + j] << endl;
					//cout << "check = " << check << endl;
				}
				else
					check = 0;

				if (check == 5)
				{
					flag = 1;
					break;
				}
			}
		}
	}
	
	//cout << endl;
	//cout << "cross_2 check" << endl;

	// |�밢�� ���� üũ
	for (int i = -4; i < 5; i++)
	{
		for (int j = -4; j < 5; j++)
		{

			if (x + i < 10 && 0 <= x + i && y + j < 10 && 0 <= y + j)
			{
				if (map[x][y] == map[x - i][y + j])
				{
					check++;
					//cout << map[x][y] << " : " << map[x - i][y + j] << endl;
					//cout << "check = " << check << endl;
				}
				else
					check = 0;

				if (check == 5)
				{
					flag = 1;
					break;
				}
			}
		}
	}
	 
	return flag;
}

Function::~Function()
{

}     
