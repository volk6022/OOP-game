#pragma once
#include <memory>
#include "GameObject.h"


class Event;


class Cell : GameObject
{
private:
	bool movable;
	Event* eventInt;

	using GameObject::position;
	using GameObject::visible;

	void clear();
public:
	Cell();

	Cell(bool movable, bool visible, Event* eventInt, Pos position);

	Cell(const Cell& other);

	Cell& operator=(const Cell& other);

	Cell(Cell&& other) noexcept;

	Cell& operator=(Cell&& other) noexcept;

	Event* get_CellEvent();

	void set_Event(Event* e);

	bool get_movable();

	void set_movable(bool movable);

	~Cell();

	using GameObject::get_position;
	using GameObject::set_position;
	using GameObject::get_visible;
	using GameObject::set_visible;
};
