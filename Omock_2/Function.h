#pragma once
class Function
{
private:
	int x = 0;
	int y = 0;
	int inx = 0;
	int iny = 0;
	int count = 0;
	int flag = 0;

	int GameFlag = 1;
	char winer = 'N';
	char color = 'N';
	char map[10][10] = {0};
	int check = 0;

public:
	Function();

	void Play();
	void Input();
	void BlockPlay();
	void WhitePlay();
	int CheckWin(int x, int y);
	bool InputCheck(int a, int b, int x, int y);
	void GameResult(char winer);

	~Function();
};

