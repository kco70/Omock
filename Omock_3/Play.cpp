#include "Play.h"
#include "Map.h"
#include "Move.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <utility>

using namespace std;

Play::Play()
{
	this->x = 0;
	this->y = 0;
	this->count = 0;
	this->flag = true;
	this->currentX = -1;
	this->c = ' ';
}

void Play::start()
{
	while (true)
	{
		cout << "오목 게임을 시작하겠습니까?(Y/N)" << endl;
		cin >> c;

		if (c == 'y' || c == 'Y')
		{
			system("cls");

			Map grid;

			cout << "흑돌부터 돌을 두고 싶은 장소에 ENTER를 입력하세요" << endl;

			while (true)
			{
				m.select();
			}
			break;
		}
		else if (c == 'n' || c == 'N')
		{
			cout << "게임을 종료합니다" << endl;
			gameover();
		}
		else
		{
			cout << "Y 또는 N을 입력해주세요." << endl;
		}
	}
}

void Play::getXY(int x, int y)
{
	this->x = x;
	this->y = y;
	
	this->vec.push_back(make_pair(x, y));
}

vector<pair<int, int>> Play::swapXY(vector<pair<int, int>> vec)
{
	vector<int> vecX;
	vector<int> vecY;

	for (int i = 0; i < vec.size(); i++)
	{
		vecX.push_back(vec[i].first);
		vecY.push_back(vec[i].second);
	}

	vector<pair<int, int>> vec2;

	for (int i = 0; i < vec.size(); i++)
	{
		vec2.push_back(make_pair(vecY[i], vecX[i]));
	}

	return vec2;
}


void Play::winCheck(vector<pair<int, int>> vec)
{
	while (flag)
	{
		//x 축을 기준으로 5개 이상의 값이 나열될 경우 종료
		for (const auto& p : vec)
		{
			if (p.first != currentX)
			{
				if (currentX != -1)
				{
					count = 0;
				}
				currentX = p.first;
			}
			count++;

			if (count > 4)
			{
				flag = false;
				break;
			}
		}

		// y축을 기준으로 5개 이상 나열될 경우
		vector<pair<int, int>> vecYX = swapXY(vec);
		for (const auto& p : vecYX)
		{
			if (p.first != currentX)
			{
				if (currentX != -1)
				{
					count = 0;
				}
				currentX = p.first;
			}
			count++;

			if (count > 4)
			{
				flag = false;
				break;
			}
		}

		// 비례하는 x와 y가 5개 이상 나열된 경우
		for (const auto& p : vec)
		{
			if (p.first == p.second) // 해당 요소의 first가 second가 같지 않으면
				count++; // 같으면 count +1 

			if (count > 4)
			{
				flag = false;
				break;
			}
		}

		// 반비례하는 x와 y가 5개 이상 나열된 경우
		for (const auto& p : vec)
		{
			if (p.first + p.second == MAX)
				count++;

			if (count > 4)
			{
				flag = false;
				break;
			}
		}
	}
	
	gameover();
}

void Play::winner(int count)
{
	this->count = count;

	if (flag == false)
	{
		if (count % 2 == 0)
		{
			cout << "흑돌의 승리입니다. " << endl;
		}
		else if (count % 2 == 1)
		{
			cout << "백돌의 승리입니다. " << endl;
		}
	}
	else
		cout << "무승부입니다. " << endl;
}

void Play::gameover()
{
	c = ' ';

	winner(m.getCount());

	while (true)
	{
		cout << "게임을 종료하겠습니까? (y/n)" << endl;
		cin >> c;

		if (c == 'y' || c == 'Y')
		{
			start();
		}
		else if (c == 'n' || c == 'N')
		{
			cout << "게임을 종료합니다" << endl;
			break;
		}
		else
		{
			cout << "Y 또는 N을 입력해주세요." << endl;
		}
	}
}

Play::~Play()
{

}