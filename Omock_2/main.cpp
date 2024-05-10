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

	cout << "흑부터 게임을 시작합니다." << endl;
	cout << "1~10 중 쉼표로 구분된 좌표를 입력해주세요 (예시 : 2,4)" << endl;
	cout << endl;

	while (flag == 0)
	{ 
		if (count % 2 == 0)
		{
			cout << "흑의 차례입니다 : ";

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
			cout << "백의 차례입니다 : ";

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
		cout << "흑의 승리입니다!" << endl;
	}
	else if (count % 2 == 0)
	{
		cout << "백의 승리입니다!" << endl;
	}

	return 0;
}