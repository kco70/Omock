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
			cout << "������ �����մϴ�." << endl;
			this->turn = -1;
			over();
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
						cout << "vecter ũ�� : " << vec.size() << endl;
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
		cout << "��";
	else if (turn % 2 == 1)
		cout << "��";
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


// winnercheck ��ü ���� ����
void Game::winnerCheck(vector<pair<int, int>> vec)
{
	count = 0;

	//x ���� �������� 5�� �̻��� ���� ������ ��� ���� +3
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

	// y���� �������� 5�� �̻� ������ ��� +1
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

	// ����ϴ� x�� y�� 5�� �̻� ������ ��� +3, +1?
	for (const auto& p : vec)
	{
		if (p.first == p.second) // �ش� ����� first�� second�� ���� ������
			count++; // ������ count +1 

		count = 0;

		if (count > 4)
			over();
	}

	// �ݺ���ϴ� x�� y�� 5�� �̻� ������ ��� +1. +3?
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

