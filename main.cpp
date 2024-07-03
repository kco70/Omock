#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
#define X_MAX 27
#define Y_MAX 10
#define MAX 10

using namespace std;

class Game
{
private:
	char input;
	int x, y;
	vector<pair<int, int>> vec;
	int count, turn;
	int currentX;

public:
	Game();

	void drawMap();

	int getX();
	int getY();

	void inputKey();
	void direcKey(char input);
	void palceStone(int count);
	bool inputCheck(int x, int y);
	void gotoxy(int x, int y);

	vector<pair<int, int>> swapXY(vector<pair<int, int>> vec);
	void winnerCheck(vector<pair<int, int>> vec);
	int over();
};

Game::Game()
{
	this->x = 2;
	this->y = 1;
	this->count = 0;
	this->turn = 0;;
	this->currentX = 0;
}


int Game::getX()
{
	return this->x;
}

int Game::getY()
{
	return this->y;
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
						gotoxy(0, 10+i);
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
		{
			gotoxy(0, 10 + i);
			cout << "�̹� ���� �� �ڸ��Դϴ�." << endl;
			return false;
		}
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

// ���ʿ� ���ӵǴ� ���ڰ� �ƴϾ���!!!! ���ڹ��� ������ ���� �� ĭ�� ��� �־���!!!
void Game::winnerCheck(vector<pair<int, int>> vec)
{
	count = 0;
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
			over();
			return;
		}
	}

	// y���� �������� 5�� �̻� ������ ���
	vector<pair<int, int>> vecYX = swapXY(vec);
	currentX = -1;
	count = 0;
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
			over();
			return;
		}
	}

	// ����ϴ� x�� y�� 5�� �̻� ������ ���
	count = 0;
	for (const auto& p : vec)
	{
		if (p.first == p.second) // �ش� ����� first�� second�� ���� ������
		{
			count++;
			if (count > 4)
			{
				over();
				return;
			}
		}
		else
			count = 0;
	}

	// �ݺ���ϴ� x�� y�� 5�� �̻� ������ ���
	count = 0;
	for (const auto& p : vec)
	{
		if (p.first + p.second == MAX)
		{
			count++;

			if (count > 4)
			{
				over();
				return;
			}
		}
		else
			count = 0;
	}
}

int Game::over()
{
	return this->turn;
}

void Game::drawMap()
{
	this->x = 0;
	this->y = 0;

	for (; x < 10; x++)
	{
		// y = 0�� x ���� ���� ��ȣ (0 ~ 9)
		cout << x << " ";

		// x = 0�� y ���� ���� ��ȣ (0 ~ 9)
		if (x == 0)
		{
			for (int y = 1; y < 10; y++)
			{
				cout << y << "  ";
			}
		}
		// x = 1 �� ��� �𼭸� (��������)
		else if (x == 1)
		{
			for (int y = 1; y < MAX; y++)
			{
				if (y == 1)
					cout << "��-";
				else if (y == MAX - 1)
					cout << "-��";
				else
					cout << "-��-";
			}

		}
		// x = 9 �� �ϴ� �𼭸� (��������)
		else if (x == 9)
		{
			for (int y = 1; y < MAX; y++)
			{
				if (y == 1)
					cout << "��-";
				else if (y == MAX - 1)
					cout << "-��";
				else
					cout << "-��-";
			}
		}
		// x = 2 ~ 9 �� �ߴ� (��������)
		else
		{
			for (int y = 1; y < MAX; y++)
			{
				if (y == 1)
					cout << "��-";
				else if (y == MAX - 1)
					cout << "-��";
				else
					cout << "-��-";
			}
		}
		cout << endl;
	}
}


int main()
{
	Game round;
	round.drawMap();
	round.inputKey();

	return 0;
}