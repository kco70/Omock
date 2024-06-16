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
		// 현재 맵 출력
		Design Map;
		Map.GridMap(inx, iny, color);

		// 흑 선공
		if (count / 2 == 0)
		{
			BlockPlay();
			Map.GridMap(inx, iny, color);
			flag = CheckWin(inx, iny);

			if (flag == 1)
				winer = 'B';
		}
		// 백 후공
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
		cout << "흑의 차례입니다 : ";

		Input();

		if (map[inx][iny] == 0)
		{
			color = 'B';
			map[inx][iny] = color;
			break;
		}
		else
			cout << "이미 입력된 좌표입니다. 다른 좌표를 입력해 주세요." << endl;

		cout << endl; 

	}

}

void Function::WhitePlay()
{
	while (1)
	{
		cout << "백의 차례입니다 : ";

		Input();

		if (map[inx][iny] == 0)
		{
			color = 'W';
			map[inx][iny] = color;
			break;
		}
		else
			cout << "이미 입력된 좌표입니다. 다른 좌표를 입력해 주세요." << endl;

		cout << endl;

	}
}

int Function::CheckWin(int inx, int iny)
{
	//cout << endl;
	//cout << "verical check" << endl;

	// 가로축 오목 체크
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

	// 세로축 오목 체크
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

	// /대각선 오목 체크
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

	// |대각선 오목 체크
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
		cout << "흑의 승리입니다!" << endl;
	else if (winer == 'W')
		cout << "백의 승리입니다!" << endl;
	else
		cout << "더 이상 돌을 둘 수 없습니다 : 무승부입니다. " << endl;
}


Function::~Function()
{

}     
