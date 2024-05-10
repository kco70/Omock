#include <iostream>
#include <string>
#include <sstream>

#include "Design.h"
#include "Function.h"

using namespace std;

int main()
{
	int count = 0;
	char color = 'N';
	int flag = 0;
	int x = 0;
	int y = 0;

	Design GridMap;
	Function Mapping;

	GridMap.Basic();

	cout << "����� ������ �����մϴ�." << endl;
	cout << "1~10 �� ��ǥ�� ���е� ��ǥ�� �Է����ּ��� (���� : 2,4)" << endl;
	cout << endl;

	while (flag == 0)
	{ 
		if (count % 2 == 0)
		{
			cout << "���� �����Դϴ� : ";

			string coor;

			getline(cin, coor);

			stringstream ss(coor);

			string sx, sy;

			getline(ss, sx, ',');
			getline(ss, sy, ',');

			x = stoi(sx);
			y = stoi(sy);

			color = Mapping.BlockPlay(x, y);
			GridMap.ChangeColor(x, y, color);
			cout << endl;
		}
		else if (count % 2 == 1)
		{
			cout << "���� �����Դϴ� : ";

			string coor;

			getline(cin, coor);

			stringstream ss(coor);

			string sx, sy;

			getline(ss, sx, ',');
			getline(ss, sy, ',');

			x = stoi(sx);
			y = stoi(sy);

			color = Mapping.WhitePlay(x, y);
			GridMap.ChangeColor(x, y, color);
			cout << endl;
		}

		flag = Mapping.CheckWin(x, y);

		count++;
	}

	if (count % 2 == 1)
	{
		cout << "���� �¸��Դϴ�!" << endl;
	}
	else if (count % 2 == 0)
	{
		cout << "���� �¸��Դϴ�!" << endl;
	}

	return 0;
}