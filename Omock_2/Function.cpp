#include <iostream>
#include <string>
#include <sstream>

#include "Design.h"
#include "Function.h"

using namespace std;

Function::Function()
{

}

void Function::Play()
{
	for (count = 0; count < 100; count++)
	{
		// ���� �� ���
		Design Map;
		Map.GridMap(inx, iny, color);

		// �� ����
		if (count / 2 == 0)
		{
			BlockPlay();
			Map.GridMap(inx, iny, color);
			flag = CheckWin(inx, iny);

			if (flag == 1)
				winer = 'B';
		}
		// �� �İ�
		else if (count / 2 == 1)

		{
			WhitePlay();
			Map.GridMap(inx, iny, color);
			flag = CheckWin(inx, iny);

			if (flag == 1)
				winer = 'W';
		}
		
		if (winer = !'N')
			break;
	}

	GameResult(winer);
}

void Function::Input()
{
	inx = 0;
	iny = 0;

	string coor = "0,0";

	cin.ignore();

	getline(cin, coor);

	stringstream ss(coor);

	string sx, sy;

	getline(ss, sx, ',');
	getline(ss, sy, ',');
	 
	inx = stoi(sx);
	iny = stoi(sy);
}

bool Function::InputCheck(int inx, int iny, int x, int y)
{
	this->inx = inx;
	this->iny = iny;

	if (inx == x && iny == y)
	{
		return 1;
	}
	else
		return 0;
}

void Function::BlockPlay()
{
	while (1)
	{
		cout << "���� �����Դϴ� : ";

		Input();

		if (map[inx][iny] == 0)
		{
			color = 'B';
			map[inx][iny] = color;
			break;
		}
		else
			cout << "�̹� �Էµ� ��ǥ�Դϴ�. �ٸ� ��ǥ�� �Է��� �ּ���." << endl;

		cout << endl; 

	}

}

void Function::WhitePlay()
{
	while (1)
	{
		cout << "���� �����Դϴ� : ";

		Input();

		if (map[inx][iny] == 0)
		{
			color = 'W';
			map[inx][iny] = color;
			break;
		}
		else
			cout << "�̹� �Էµ� ��ǥ�Դϴ�. �ٸ� ��ǥ�� �Է��� �ּ���." << endl;

		cout << endl;

	}
}

int Function::CheckWin(int inx, int iny)
{
	//cout << endl;
	//cout << "verical check" << endl;

	// ������ ���� üũ
	for (int i = -4; i < 5; i++)
	{
		if (inx + i < 10 && 0 <= x + i)
		{
			if (map[inx][iny] == map[inx + i][iny]) 
			{
				check++;
			}
			else
			{
				check = 0;
			}
		}

		if (check == 5)
		{
			flag = 1;
			break;
		}
	}

	// ������ ���� üũ
	for (int j = -4; j < 5; j++)
	{
		if (iny + j < 10 && 0 <= iny + j)
		{
			if (map[inx][iny] == map[inx][iny + j]) 
			{
				check++;
			}
			else
			{
				check = 0;
			}
		}

		if (check == 5)
		{
			flag = 1;
			break;
		}
	}

	// /�밢�� ���� üũ
	for (int i = -4; i < 5; i++)
	{
		for (int j = -4; j < 5; j++)
		{
			if (inx + i < 10 && 0 <= inx + i && iny + j < 10 && 0 <= iny + j)
			{
				if (map[inx][iny] == map[inx + i][iny - j])
				{
					check++;
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

	// |�밢�� ���� üũ
	for (int i = -4; i < 5; i++)
	{
		for (int j = -4; j < 5; j++)
		{

			if (inx + i < 10 && 0 <= inx + i && iny + j < 10 && 0 <= iny + j)
			{
				if (map[inx][iny] == map[inx - i][iny + j])
				{
					check++;
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

void Function::GameResult(char winer)
{
	if (winer == 'B')
		cout << "���� �¸��Դϴ�!" << endl;
	else if (winer == 'W')
		cout << "���� �¸��Դϴ�!" << endl;
	else
		cout << "�� �̻� ���� �� �� �����ϴ� : ���º��Դϴ�. " << endl;
}


Function::~Function()
{

}     
