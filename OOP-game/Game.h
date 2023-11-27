#pragma once

#include "Menu.h"
#include "lvl.h"

#include <string>
#include <map>

class Game
{
public:
	Game() {}
	void StartGame() {
		Menu m;
		std::string path = m.MainMenu();
		lvl* l;
		while (!path.empty()) {
			// create new lvl and start it
			l = new lvl(path, 200);
			l->start();
			l->~lvl();
			path = m.MainMenu();
		}
	}
};


//#pragma once
//#include "Generator.h"
//#include "Movement.h"
//#include "Visualise.h"
//
//
//class Game
//{
//private:
//	Generator* generator;
//	Movement* movement;
//	Visualise* visualise;
//
//	void clear();
//public:
//	Game(bool start = false);
//	
//	void startGame();
//
//	void menu();
//};

