#include "Game.h"

//#include <iostream>
//#include <string>
//#include <conio.h>
//
//#define def_lvl "C:\\Users\\bhunp\\OneDrive\\Documents\\OOP\\OOP\\lvl1.txt"
//#define def_contr "C:\\Users\\bhunp\\OneDrive\\Documents\\OOP\\OOP\\lvl1.txt"
//
//
//void Game::clear() {
//	if (generator)
//		generator->~Generator();
//}
//
//Game::Game(bool start) {
//	if (start) menu();
//}
//
//void Game::startGame() {
//	int ret = movement->action();
//	while (ret == 0) {
//		ret = movement->action();
//	}
//	if (generator->contr->get_win()) {
//		std::cout << "CONGRATULATIONS!!!\nYOU WIN\n";
//	}
//	else {
//		std::cout << "GAME OVER\n";
//	}
//	if (ret == go2menu) {
//		menu();
//	}
//}
//
//void Game::menu() {
//getLVL:
//	clear();
//	std::cout << "Enter 1 or 2 to choose lvl 1 or 2\n";
//	char choise = ' ';
//	choise = _getch();
//	if (choise == '2') {
//		std::cout << "2nd lvl\n";
//		generator = new Generator(def_lvl);
//	}
//	else {
//		std::cout << "1st lvl\n";
//		std::string str;
//		generator = new Generator(str);
//	}
//	if (generator->contr == nullptr) goto getLVL;
//	visualise = new Visualise(*generator->field, *generator->player);
//	movement = new Movement(def_contr, *generator->contr, *visualise);
//	bool started = false;
//	while (!started) {
//		std::cout << "Enter s to start the game\nOr q to quit\n";
//		choise = _getch();
//		if (choise == 'q') {
//			exit(0);
//		}
//		if (choise == 's') {
//			started = true;
//			startGame();
//		}
//	}
//}
//
