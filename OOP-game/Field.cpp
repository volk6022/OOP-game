#include "Field.h"

#define def_start Pos{0, 0}


// get/set/check smth methods

int Field::get_height() { return height; }
int Field::get_width() { return width; }
Pos Field::get_start() { return start; }
Pos Field::get_stop() { return stop; }

void Field::set_start(Pos s) {
	if(((s.x < 0) && (s.x >= width))
		|| ((s.y < 0) && (s.y >= height)))
		return;
	start = s;
}
void Field::set_stop(Pos s) {
	if (((s.x < 0) && (s.x >= width))
		|| ((s.y < 0) && (s.y >= height)))
		return;
	stop = s;
}

bool Field::get_movable(int x, int y) {
	if (((x < 0) && (x >= width))
		|| ((y < 0) && (y >= height)))
		return false;
	return cells[y][x].get_movable();
}

void Field::set_movable(int x, int y, bool movable) {
	if (((x < 0) && (x >= width))
		|| ((y < 0) && (y >= height)))
		return;
	cells[y][x].set_movable(movable);
}


bool Field::get_visible(int x, int y) {
	if (((x < 0) && (x >= width))
		|| ((y < 0) && (y >= height)))
		return false;
	return cells[y][x].get_movable();
}


void Field::set_visible(int x, int y, bool visible) {
	if (((x < 0) && (x >= width))
		|| ((y < 0) && (y >= height)))
		return;
	cells[y][x].set_visible(visible);
}


Pos Field::check_pos(Pos p) {
	if (p.x >= width) p.x = width - 1;
	if (p.x < 0) p.x = 0;
	if (p.y >= height) p.y = height - 1;
	if (p.y < 0) p.y = 0;
	return p;
}


// event system methods

Event* Field::getCellEvent(int x, int y) {
	if (((x < 0) && (x >= width))
		|| ((y < 0) && (y >= height)))
		return nullptr;
	return cells[y][x].get_CellEvent();
}


void Field::setCellEvent(int x, int y, Event* evnt) {
	if (((x < 0) && (x >= width))
		|| ((y < 0) && (y >= height)))
		return;
	cells[y][x].set_Event(evnt);
}


// copy/move/init methods

Field::Field(int x, int y, Pos start, Pos stop) {
	if (y < 0) y = 0;
	if (x < 0) x = 0;
	width = x;
	height = y;
	cells = new Cell * [height];
	for (int i = 0; i < height; i++) {
		cells[i] = new Cell[width];
	}
	this->start = check_pos(start);
	this->stop = check_pos(stop);
	cells[start.y][start.x].set_movable(true);
	cells[stop.y][stop.x].set_movable(true);
}

void Field::clear() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < width; j++) {
			cells[i][j].~Cell();
		}
		delete[] cells[i];
	}
	delete[] cells;
}

Field::~Field() {
	this->clear();
}

Field& Field::operator=(const Field& f) {
	if (this == &f) {
		return *this;
	}
	this->clear();
	width = f.width;
	height = f.height;
	stop = f.stop;
	start = f.start;
	cells = new Cell * [height];
	for (int i = 0; i < height; i++) {
		cells[i] = new Cell[width];
		std::copy(f.cells[i], f.cells[i] + width, cells[i]);
	}
	return *this;
}

Field::Field(const Field& f) : width(f.width), height(f.height), start(f.start), stop(f.stop), cells(nullptr)
{
	if (this == &f) {
		return;
	}
	cells = new Cell*[height];
	for (int i = 0; i < height; i++) {
		cells[i] = new Cell[width];
		std::copy(f.cells[i], f.cells[i] + width, cells[i]);
	}
}

Field& Field::operator=(Field&& f) noexcept {
	if (this == &f) {
		return *this;
	}
	this->clear();
	width = std::move(f.width);
	height = std::move(f.height);
	stop = std::move(f.stop);
	start = std::move(f.start);
	cells = new Cell * [height];
	for (int i = 0; i < height; i++) {
		cells[i] = new Cell[width];
		std::copy(f.cells[i], f.cells[i] + width - 1, cells[i]);
	}
	f.~Field();
	return *this;
}

Field::Field(Field&& f) noexcept : width(f.width), height(f.height), start(f.start), stop(f.stop), cells(nullptr)
{
	if (this == &f) {
		return;
	}
	cells = new Cell * [height];
	for (int i = 0; i < height; i++) {
		cells[i] = new Cell[width];
		std::copy(f.cells[i], f.cells[i]+width, cells[i]);
	}
	f.~Field();
}


// generator and controll methods (dk is it needed&)

//void Field::print() {
//	for (int j = 0; j < height; j++) {
//		std::cout << '\n';
//		for (int i = 0; i < width; i++) {
//			if ((i == stop.x) && (j == stop.y))
//				if ((start.x == j) && (start.y == i))
//					std::cout << '@' << ' ';
//				else
//					std::cout << '#' << ' ';
//			else if ((start.x == j) && (start.y == i))
//				std::cout << '@' << ' ';
//			else
//				std::cout << int(get_movable(j, i)) << ' ';
//		}
//	}
//	std::cout << '\n';
//}

//void Field::make_box() {
//	for (int i = 0; i < height; i++) {
//		if ((i == 0) || (i == height - 1)) {
//			for (int j = 0; j < width; j++) {
//				set_movable(j, i, false);
//			}
//		}
//		else {
//			cells[i][0].set_movable(false);
//			cells[i][width - 1].set_movable(false);
//		}
//	}
//}
