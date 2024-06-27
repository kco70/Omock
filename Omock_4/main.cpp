#include <iostream>
#include "user.h"
#include "game.h"

using namespace std;

int main()
{
	User person;
	Game round;

	person.setID();
	round.menu();
	person.getWinnerID(round.over());

	return 0;
}