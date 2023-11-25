#include "Cell.h"

#define def_movable true
#define def_event nullptr


Cell::Cell() : movable(def_movable), eventInt(def_event) {
	GameObject(def_pos, def_vis);
}


Cell::Cell(bool movable = def_movable, bool visible = def_vis, Event* eventInt = def_event, Pos pos = def_pos)
	: movable(movable), eventInt(eventInt) 
{
	GameObject({pos.x, pos.y}, visible);
}

Cell::Cell(const Cell& other) : movable(other.movable), eventInt(other.eventInt) {
	GameObject(other.position, other.visible);
}

Cell::Cell(Cell&& other) noexcept : movable(other.movable), eventInt(other.eventInt) {
	GameObject(other.position, other.visible);
	other.~Cell();
}

Cell& Cell::operator=(const Cell& other) {
	if (this == &other) {
		return *this;
	}
	this->clear();
	movable = other.movable;
	eventInt = other.eventInt;
	position = other.position;
	visible = other.visible;
	return *this;
}

Cell& Cell::operator=(Cell&& other) noexcept {
	if (this == &other) {
		return *this;
	}
	this->clear();
	std::swap(movable, other.movable);
	std::swap(eventInt, other.eventInt);
	std::swap(position, other.position);
	std::swap(visible, other.visible);
	other.clear();
	return *this;
}

void Cell::clear() {
	if (eventInt)
		delete eventInt;
}

Cell::~Cell() {
	this->clear();
}

void Cell::set_Event(Event* e) {
	this->clear();
	eventInt = e;
}

Event* Cell::get_CellEvent() {
	return eventInt;
}

bool Cell::get_movable() {
	return movable;
}

void Cell::set_movable(bool movable) {
	this->movable = movable;
}

