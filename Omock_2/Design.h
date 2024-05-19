#pragma once
class Design
{
private:
	char color = 'N';
	int x = 0;
	int y = 0;
	int inx = 0;
	int iny = 0;

public :
	Design();

	void GridMap(int inx, int iny, char color);

	~Design();
};

