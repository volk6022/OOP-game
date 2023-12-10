#pragma once
#include "Player.h"
#include "Field.h"
#include "Controlls.h"


class Controller
{
private:
	Player* player;
	Field* field;
	bool CheckEndGame;
	bool win;
	int steps;

	void SetEndGame();

public:
	Controller() {}

	Controller(Player *player, Field *field);

	void MovePlayer(Controlls direction);

	//void print();

	~Controller() {}

	void CallEvent(Pos position);

	int getSteps();

	bool EndGame();

	bool get_win();
};