#pragma once
#include "ObjectPosition.h"

#define def_pos {0,0}
#define def_vis false


class GameObject
{
protected:
	Pos position;
	bool visible;
	Pos get_position() {
		return position;
	}
	void set_position(Pos p) {
		position = p;
	}
	bool get_visible() {
		return visible;
	}
	void set_visible(bool b) {
		visible = b;
	}
public:
	GameObject(Pos position = def_pos, bool visible = def_vis) : position(position), visible(visible) {}
};

