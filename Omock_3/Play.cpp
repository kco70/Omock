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
		cout << "���� ������ �����ϰڽ��ϱ�?(Y/N)" << endl;
		cin >> c;

		if (c == 'y' || c == 'Y')
		{
			system("cls");

			Map grid;

			cout << "�浹���� ���� �ΰ� ���� ��ҿ� ENTER�� �Է��ϼ���" << endl;

			while (true)
			{
				m.select();
			}
			break;
		}
		else if (c == 'n' || c == 'N')
		{
			cout << "������ �����մϴ�" << endl;
			gameover();
		}
		else
		{
			cout << "Y �Ǵ� N�� �Է����ּ���." << endl;
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
		//x ���� �������� 5�� �̻��� ���� ������ ��� ����
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

		// y���� �������� 5�� �̻� ������ ���
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

		// ����ϴ� x�� y�� 5�� �̻� ������ ���
		for (const auto& p : vec)
		{
			if (p.first == p.second) // �ش� ����� first�� second�� ���� ������
				count++; // ������ count +1 

			if (count > 4)
			{
				flag = false;
				break;
			}
		}

		// �ݺ���ϴ� x�� y�� 5�� �̻� ������ ���
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
			cout << "�浹�� �¸��Դϴ�. " << endl;
		}
		else if (count % 2 == 1)
		{
			cout << "�鵹�� �¸��Դϴ�. " << endl;
		}
	}
	else
		cout << "���º��Դϴ�. " << endl;
}

void Play::gameover()
{
	c = ' ';

	winner(m.getCount());

	while (true)
	{
		cout << "������ �����ϰڽ��ϱ�? (y/n)" << endl;
		cin >> c;

		if (c == 'y' || c == 'Y')
		{
			start();
		}
		else if (c == 'n' || c == 'N')
		{
			cout << "������ �����մϴ�" << endl;
			break;
		}
		else
		{
			cout << "Y �Ǵ� N�� �Է����ּ���." << endl;
		}
	}
}

Play::~Play()
{

}