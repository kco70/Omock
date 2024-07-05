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

void Game::getVec(vector<pair<int, int>> vecColor)
{
	if (turn % 2 == 0)
	{
		gotoxy(0, 13);
		cout << "vecBlack : ";
	}
	else if (turn % 2 == 1)
	{
		gotoxy(0, 14);
		cout << "vecWhite : ";
	}

	for (const auto& p : vecColor)
		cout << "{" << p.first << ", " << p.second << "} ";
}

void Game::menu()
{
	while (true)
	{
		cout << "������ �����ϰڽ��ϱ�? (Y/N) : ";
		cin >> c;

		if (c == 'y' || c == 'Y')
		{
			while (true)
			{
				cout << "�浹�� �鵹 �� ��� ���� ��ڽ��ϱ�? : ";
				cin >> stone;

				if (stone == "�浹" || stone == "��")
				{
					this->turn = 0;
					break;
				}
				else if (stone == "�鵹" || stone == "��")
				{
					this->turn = 1;
					break;
				}
				else
					cout << "�浹 �Ǵ� �鵹 �߿� �������ּ���." << endl;
			}
			start();
		}
		else if (c == 'n' || c == 'N')
		{
			this->turn = -1;
			over(turn);
			break;
		}
		else
			cout << "Y �Ǵ� N���� �Է����ּ���." << endl;
	}
}

void Game::start()
{
	system("cls");

	Grid go = {};
	go.drawMap();

	cout << "�浹 ���� �����մϴ�. " << endl;
	cout << "���� �ΰ� ���� ��ҿ��� ENTER�� �Է��ϼ���" << endl;

	inputKey();
}

void Game::inputKey()
{
	while (true)
	{
		char input;
		gotoxy(x, y);

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
				if (inputCheck(vecBlack) && inputCheck(vecWhite))
				{
					if (turn % 2 == 0)
					{
						vecBlack.push_back(make_pair(x, y));
						cout << "��";
						if (checkStone(x, y, vecBlack))
						{
							over(turn);
							break;
						}
//						getVec(vecBlack);
					}
					else if (turn % 2 == 1)
					{
						vecWhite.push_back(make_pair(x, y));
						cout << "��";
						if (checkStone(x, y, vecWhite))
						{
							over(turn);
						}
//						getVec(vecWhite);
					}
				}
				turn++;
			}
		}
	}
}
   
bool Game::checkStone(int x, int y, vector<pair<int, int>> vecColor)
{
//	gotoxy(0, 16);

	int xCount = countStone(1, 0, vecColor);
	int yCount = countStone(0, 1, vecColor);
	int xyCount = countStone(1, 1, vecColor);
	int minusxyCount = countStone(-1, 1, vecColor);

//	cout << "xCount : " << xCount << endl;
//	cout << "yCount : " << yCount << endl;
//	cout << "xyCount : " << xyCount << endl;
//	cout << "minusxyCount : " << minusxyCount << endl;

	return (xCount == 5 || yCount == 5 || xyCount == 5 || minusxyCount == 5);
}

int Game::countStone(int dx, int dy, vector<pair<int, int>> vecColor)
{
	count = 0;
	x = vecColor[0].first;
	y = vecColor[0].second;


	for (int i = 0; i < vecColor.size(); i++)
	{
		if (x == vecColor[i].first && y == vecColor[i].second)
		{
			count++;

			x = x + dx * 3;
			y += dy;
		}
	}

	for (const auto& p : vecColor)
	{
		if (p.first == x && p.second == y)
		{
			count++;

			x = x + dx * 3;
			y += dy;
		}
	}

	return count;
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
		cout << "������ �����մϴ�." << endl;
	}
	else if(turn % 2 == 0)
	{
		gotoxy(0, 13);
		cout << "�浹�� �¸��Դϴ�" << endl;
	}
	else if (turn % 2 == 1)
	{
		gotoxy(0, 13);     
		cout << "�鵹�� �¸��Դϴ�" << endl;
	}

}

