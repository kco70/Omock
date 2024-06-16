#pragma once
#ifndef _MOVE_H_

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
#define X_MAX 27
#define Y_MAX 10

#include "Move.h"
#include "Play.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <utility>

using namespace std;

class Move
{
private:
	char input;
	int count;
	int x, y;
	vector <pair<int, int>> vec;

	Play p;

public:

	Move();

	void setXY(int x, int y); // �Ű����� x, y�� private x, y�� ����
	const auto& getXY(); // vector�� ����� x, y ��� �α� ��� ���
	int getX();
	int getY();
	int getCount();


	bool checkXY(int x, int y); // ���� ��ǥ(x, y)�� �̹� ���Ǿ����� ture, ���Ǿ����� ������ false 
	void print(int x, int y); // ���� ��ǥ�� Ŀ���� ǥ��
		
	void gotoxy(int x, int y); // ����� ��ǥ�� ǥ��
	void curser(); // ����Ű�� ����� ��ǥ ����
	void select();

	~Move();

};

#else
#endif // !_MOVE_H_
