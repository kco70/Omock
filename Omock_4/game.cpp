#include "game.h"
#include "grid.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <string>

using namespace std;

Game::Game()
{
	this->x = 2;
	this->y = 1;
	this->count = 0;
	this->turn = 0;;
	this->currentX = 0;
	vector<pair<int, int>> vec;
	char c = ' ';
	string stone = "";
}

int Game::getX()
{
	return this->x;
}

int Game::getY()
{
	return this->y;
}

void Game::menu()
{
	while (true)
	{
		cout << "오목을 시작하겠습니까? (Y/N) : ";
		cin >> c;

		if (c == 'y' || c == 'Y')
		{
			while (true)
			{
				cout << "흑돌과 백돌 중 어느 쪽을 쥐겠습니까? : ";
				cin >> stone;

				if (stone == "흑돌" || stone == "흑")
				{
					this->turn = 0;
					break;
				}
				else if (stone == "백돌" || stone == "백")
				{
					this->turn = 1;
					break;
				}
				else
					cout << "흑돌 또는 백돌 중에 선택해주세요." << endl;
			}
			start();
		}
		else if (c == 'n' || c == 'N')
		{
			cout << "게임을 종료합니다." << endl;
			this->turn = -1;
			over();
		}
		else
			cout << "Y 또는 N으로 입력해주세요." << endl;
	}
}

void Game::start()
{
	system("cls");

	Grid go = {};
	go.drawMap();

	cout << "흑돌 먼저 시작합니다. " << endl;
	cout << "돌을 두고 싶은 장소에서 ENTER을 입력하세요" << endl;

	while (true)
		inputKey();
}

void Game::inputKey()
{
	while (true)
	{
		char input;

		if (_kbhit())
		{
			input = _getch();

			if (input == -32)
			{
				input = _getch();
				direcKey(input);
			}
			else if (input == ENTER)
			{
				if (inputCheck(x, y))
				{
					vec.push_back(make_pair(x, y));

					for (int i = 0; i < vec.size(); i++)
					{
						gotoxy(0, 10 + i);
						cout << "vecter 크기 : " << vec.size() << endl;
						cout << "vec : ";
						cout << "{" << vec[i].first << ", " << vec[i].second << "} ";
					}
					gotoxy(x, y);

					palceStone(turn);

					winnerCheck(vec);

					turn++;
				}
			}
		}
	}
}


void Game::palceStone(int turn)
{
	if (turn % 2 == 0)
		cout << "●";
	else if (turn % 2 == 1)
		cout << "○";
}

void Game::direcKey(char input)
{
	if (x < X_MAX && y < Y_MAX)
	{
		switch (input)
		{
		case LEFT:
			if (x > 3)
				x = x - 3;
			else
				x = X_MAX - 1;
			break;
		case RIGHT:
			if (x + 3 < X_MAX)
				x = x + 3;
			else
				x = 2;
			break;
		case UP:
			if (y > 2)
				y--;
			else
				y = Y_MAX - 1;
			break;
		case DOWN:
			if (y < Y_MAX - 1)
				y++;
			else
				y = 1;
			break;
		}
	}
	else if (x >= X_MAX)
	{
		x = 2;
		y = y + 1;
	}
	else if (y >= Y_MAX)
	{
		x = x + 3;
		y = 1;
	}

	gotoxy(x, y);
}

bool Game::inputCheck(int x, int y)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].first == x && vec[i].second == y)
			return false;
	}
	return true;
}

void Game::gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

vector<pair<int, int>> Game::swapXY(vector<pair<int, int>> vec)
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


// winnercheck 전체 수정 예정
void Game::winnerCheck(vector<pair<int, int>> vec)
{
	count = 0;

	//x 축을 기준으로 5개 이상의 값이 나열될 경우 종료 +3
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
			over();
	}

	// y축을 기준으로 5개 이상 나열될 경우 +1
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
			over();
	}

	// 비례하는 x와 y가 5개 이상 나열된 경우 +3, +1?
	for (const auto& p : vec)
	{
		if (p.first == p.second) // 해당 요소의 first가 second가 같지 않으면
			count++; // 같으면 count +1 

		count = 0;

		if (count > 4)
			over();
	}

	// 반비례하는 x와 y가 5개 이상 나열된 경우 +1. +3?
	for (const auto& p : vec)
	{
		if (p.first + p.second == MAX)
			count++;

		count = 0;

		if (count > 4)
			over();
	}
}

int Game::over()
{	
	return this->turn;
}

