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

	void setXY(int x, int y); // 매개변수 x, y를 private x, y에 저장
	const auto& getXY(); // vector에 저장된 x, y 페어 로그 모두 출력
	int getX();
	int getY();
	int getCount();


	bool checkXY(int x, int y); // 현재 좌표(x, y)가 이미 사용되었으면 ture, 사용되어있지 않으면 false 
	void print(int x, int y); // 현재 좌표의 커서를 표기
		
	void gotoxy(int x, int y); // 출력을 좌표로 표기
	void curser(); // 방향키를 사용한 좌표 변경
	void select();

	~Move();

};

#else
#endif // !_MOVE_H_
