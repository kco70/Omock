#include "Move.h"
#include "Play.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <utility>

using namespace std;

Move::Move()
{
	this->x = 2;
	this->y = 1 ;
	this->count = 0;

	gotoxy(x, y);
}

void Move::setXY(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Move::getX()
{
	return this->x;
}

int Move::getY()
{
	return this->y;
}

int Move::getCount()
{
	return count;
}

const auto& Move::getXY() 
{
	return this->vec;
}

bool Move::checkXY(int x, int y) 
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].first == x && vec[i].second == y)
			return true;
	}

	return false;
}

void Move::print(int x, int y)
{
	gotoxy(x, y);
}


void Move::gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Move::curser()
{
	int tempX = x;
	int tempY = y;

	do {
		tempX = x;
		tempY = y;
		if (x > X_MAX && y > Y_MAX)
		{
			switch (input)
			{
			case LEFT:
				if (this->x > 3)
					this->x = x - 3;
				else
					this->x = X_MAX - 1;
				break;
			case RIGHT:
				if (this->x + 3 < X_MAX)
					this->x = x + 3;
				else
					this->x = 2;
				break;
			case UP:
				if (this->y > 2)
					this->y--;
				else
					this->y = Y_MAX - 1;
				break;
			case DOWN:
				if (this->y < Y_MAX - 1)
					this->y++;
				else
					this->y = 1;
				break;
			}
		}
		else if (x >= X_MAX)
		{
			this->x = 2;
			this->y = y + 1;
		}
		else if (y >= Y_MAX)
		{
			this->x = x + 3;
			this->y = 1;
		}
		else if (x >= X_MAX && y >= Y_MAX)
		{
			cout << "게임이 종료되었습니다. " << endl;
		}
	} while (checkXY(x, y));

	print(x, y);

}

void Move::select()
{
	while (1)
	{
		if (_kbhit())
		{
			this->input = _getch();
			if (input == -32)
			{
				this->input = _getch();
				curser();
			}
			else if (input == ENTER)
			{
				if (!checkXY(x, y))
				{
					this->vec.push_back(make_pair(getX(), getY()));
					p.getXY(getX(), getY());

					gotoxy(x, y);

					if (count % 2 == 0)
						cout << "●";
					else if (count % 2 == 1)
						cout << "○";

					p.winCheck(vec);

					count++;
				}
			}
		}
	}
}

Move::~Move()
{

}