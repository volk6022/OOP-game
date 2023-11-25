#pragma once
#include "Cell.h"


class Field
{
private:
	Cell** cells;
	int height;
	int width;
	Pos start;
	Pos stop;

	void clear();
public:
	Field(int x, int y, Pos start, Pos stop);

	Field(const Field& f);

	Field& operator=(const Field& f);

	Field(Field&& f) noexcept;

	Field& operator=(Field&& f) noexcept;

	int get_height() ;

	int get_width() ;

	Pos get_start() ;

	Pos get_stop() ;

	void set_start(Pos s) ;

	void set_stop(Pos s) ;

	bool get_movable(int x, int y);

	void set_movable(int x, int y, bool movable);

	bool get_visible(int x, int y);

	void set_visible(int x, int y, bool visible);

	Pos check_pos(Pos p);

	Event* getCellEvent(int x, int y);

	void setCellEvent(int x, int y, Event* evnt);

	~Field();

	//void print();

	//void make_box();
};