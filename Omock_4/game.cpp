#include "game.h"
#include "grid.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <algorithm>

using namespace std;

Game::Game()
{
	this->x = 2;
	this->y = 1;
	this->count = 0;
	this->turn = 0;;
	char c = '0';
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
			over(turn); 
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

	inputKey();
}

//************************************************************
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
				if (turn % 2 == 0)
				{
					checkStone(x, y, vecBlack);
					cout << "●";
				}
				else if (turn % 2 == 1)
				{
					checkStone(x, y, vecWhite);
					cout << "○";
				}
			}
			turn++;
		}
	}
}

bool Game::checkStone(int x, int y, vector<pair<int, int>> vecColor)
{
	return (countStone(x, y, 1, 0, vecColor) + countStone(x, y, -1, 0, vecColor) - 1 == 5 ||
			countStone(x, y, 0, 1, vecColor) + countStone(x, y, 0, -1, vecColor) - 1 == 5 ||
			countStone(x, y, 1, 1, vecColor) + countStone(x, y, -1, -1, vecColor) - 1 == 5 ||
		    countStone(x, y, 1, -1, vecColor) + countStone(x, y, -1, 1, vecColor) - 1 == 5);
}

int Game::countStone(int x, int y, int dx, int dy, vector<pair<int, int>> vecColor)
{
	count = 0;
	
	while (0 <= x < X_MAX && 0 <= y < Y_MAX)
	{
		if (inputCheck(vecColor)) 
		{
			vecColor.push_back(make_pair(x, y));
			count++;
			x = x + 3 * dx;
			y = y + dy;
		}
		else 
		{
			return 0;
		}

		return count;
	}
}

bool Game::inputCheck(vector<pair<int, int>> vecColor)
{
	for (const auto& p : vecColor)
	{
		if (p.first == x && p.second == y)
		{
			return false;
		}
	}
	return true;
}

//************************************************************


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

void Game::gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Game::over(int turn)
{	
	if (turn == -1)
	{
		cout << "오목을 종료합니다." << endl;
	}
	else if(turn % 2 == 0)
	{
		gotoxy(0, 13);
		cout << "흑돌의 승리입니다" << endl;
	}
	else if (turn % 2 == 1)
	{
		gotoxy(0, 13);     
		cout << "백돌의 승리입니다" << endl;
	}


}

