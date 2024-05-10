#pragma once
class Design
{
private:
	char ui_map[10][10] = { 0 };
	char color = 'N';
	int x = 0;
	int y = 0;

public :
	Design();

	void Basic();
	void ChangeColor(int x, int y, char color);

	~Design();
};

