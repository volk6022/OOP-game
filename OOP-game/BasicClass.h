#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <math.h>

#define def_visibility true
#define def_position Position {0, 0, 1}

struct Position
{
	float x;
	float y;
	int z;
};

class BasicClass
{
protected:
	Position position;
	bool visibility;
public:
	BasicClass(bool vis=def_visibility, Position pos=def_position) {
		set_visibility(vis);
		set_position(pos);
	}
	virtual Position get_position() {
		return position;
	}

	virtual void set_position(Position pos) {
		position = pos;
	}

	virtual bool get_visibility() {
		return visibility;
	}

	virtual void set_visibility(bool vis) {
		visibility = vis;
	}

	// возвращает рассто€ение от переданной точки до объека
	// предполагаетс€, что контроллер будет вычисл€ть координату крайней точки игрока по направлению этого объека
	// (игрок - круг, так что вычисление не должно оказатьс€ грамоздким)
	virtual float CheckCollision(Position pos) = 0;

	virtual void OnCollisionEnter() = 0;

	virtual ~BasicClass() = default;
};

