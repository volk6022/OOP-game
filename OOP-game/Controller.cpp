#include "Controller.h"
#include "EventSystem.h"

#define def_steps 0
#define def_GameContinue false
#define def_EndGame true
#define def_win false
#define winwin true

#include <iostream>


Controller::Controller(Player* player, Field* field)
	: player(player), field(field), steps(def_steps), CheckEndGame(def_GameContinue), win(def_win)
{
	CheckEndGame = 0;
	player->set_position(field->get_start());
}


void Controller::MovePlayer(Controlls direction)
{
	Pos position = player->get_position();
	++steps;
	player->set_charact(Characts::HEALTH, player->get_charact(Characts::HEALTH).value - 1);
	switch (direction)
	{
	case Controlls::down:
		if ((position.y + 1 >= field->get_height()) ||(!field->get_movable(position.x, position.y + 1))) return;
		position.y += 1;
		break;
	case Controlls::up:
		if ((0 > position.y - 1) || (!field->get_movable(position.x, position.y - 1))) return;
		position.y -= 1;
		break;
	case Controlls::left:
		if ((0 > position.x - 1) || (!field->get_movable(position.x - 1, position.y))) return;
		position.x -= 1;
		break;
	case Controlls::right:
		if ((field->get_width() <= position.x + 1) || (!field->get_movable(position.x + 1, position.y))) return;
		position.x += 1;
		break;
	case Controlls::menu:
		CheckEndGame = def_EndGame;
		return;
	}

	CallEvent(position);

	if ((position.x < 0) || (position.y < 0) || (position.x >= field->get_width()) || (position.y >= field->get_height())) {
		position = field->get_start();
	}
	player->set_position(position);

	if ((position.x == field->get_stop().x) && (position.y == field->get_stop().y)) {
		win = winwin;
		CheckEndGame = def_EndGame;
	}
	if (player->get_charact(Characts::HEALTH).value <= 0)
		CheckEndGame = def_EndGame;
}


void Controller::CallEvent(Pos position)
{
	if (field->getCellEvent(position.x, position.y) != nullptr)
		field->getCellEvent(position.x, position.y)->OnEvent();
}

bool Controller::EndGame()
{
	return CheckEndGame;
}

bool Controller::get_win() {
	return win;
}

int Controller::getSteps() {
	return steps;
}
