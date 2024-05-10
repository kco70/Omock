#pragma once
class Function
{
private:
	int x = 0;
	int y = 0;
	int flag = 0;
	char color = 'N';
	char map[10][10] = {0};
	int check = 0;

public:
	Function();

	char BlockPlay(int x, int y);
	char WhitePlay(int x, int y);
	int CheckWin(int x, int y);

	~Function();
};

