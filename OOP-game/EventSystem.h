#pragma once
#include "Player.h"
#include "Cell.h"
#include "Field.h"


enum class Symbols : char {
	Damage = '-',
	Heal = '+',
	Score = '*',
	Teleport = '^',
	Empty = '.',

	Player = '@',
	Start = '@',
	Finish = '0',

	Impassable = '#',
};


class Event
{
public:
	virtual void OnEvent() = 0;
	virtual Symbols get_symbol() = 0;
};
