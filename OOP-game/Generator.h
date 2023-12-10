#pragma once
#include "Player.h"
#include "Field.h"
#include "Controlls.h"
#include "EventSystem.h"

#include <string>
#include <map>
#include <fstream>


class Generator
{
private:
	std::string pathDir;

public:
	Generator(std::string path) : pathDir(path) {}

	Player* readPlayer();

	Field* readField(Player* player);

	std::map<Symbols, char>* readSimbols();

	std::map<int, Controlls>* readControlSymbols();

private:
	void get_values(std::vector<def_value_type>& vec, std::ifstream* in);

	void get_poses(std::vector<Pos>& vec, std::ifstream* in);
};



//void setDefControls(std::map<int, Controlls>* m) {
	//	// pass
	//}
	//void setDefVisuals() {}

//#pragma once
//#include "Controller.h"
//
//#include <string>
//
//
//class Generator
//{
//public:
//	Player* player;
//	Controller* contr;
//	Field* field;
//public:
//	Generator(std::string path);
//
//private:
//	void default_lvl();
//
//private:
//	void get_lvl(std::string path);
//
//	void get_field(std::ifstream* in);
//
//	void get_poses(std::vector<Pos>& vec, std::ifstream* in);
//
//	void get_values(std::vector<def_value_type>& vec, std::ifstream* in);
//
//	void get_player(std::ifstream* in);
//
//public:
//	~Generator();
//};



// lvl1
/* 10x10
* 1 2 3 4 5 6 7 8 9 10
* ____________________
* @ . . . . . . . . . |- 1
* . . . . . . . . . . |- 2
* . . . . . . . . . . |- 3
* . # . # * . . . . . |- 4
* . # . # * * * * * * |- 5
* . # . # # # # * * * |- 6
* . # . . . . # * * * |- 7
* . # . . . . # # # * |- 8
* . # # # # . # 0 # * |- 9
* - - - - ^ - + * * * |- 10 teleport to: 1x10
*/

// lvl2
/*
* 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0
* ________________________________________
* . . . . . . . . . . . . . . . . . . . . |- 1
* . . . . . . . . . . . . . . . . . . . . |- 2
* . . . . . . . . . . . . . . . . . . . . |- 3
* . . . . . . . . . . . . . . . . . . . . |- 4
* . . . . . . . . . . . . . . . . . . . . |- 5
* . . . . . . . . . . . . . . . . . . . . |- 6
* . . . . . . . . . . . . . . . . . . . . |- 7
* . . . . . . . . . . . . . . . . . . . . |- 8
* . . . . . . . . . . . . . . . . . . . . |- 9
* . . . . . . . . . . . . . . . . . . . . |- 10
* . . . . . . . . . . . . . . . . . . . . |- 11
* . . . . . . . . . . . . . . . . . . . . |- 12
* . . . . . . . . . . . . . . . . . . . . |- 13
* . . . . . . . . . . . . . . . . . . . . |- 14
* . . . . . . . . . . . . . . . . . . . . |- 15
* . . . . . . . . . . . . . . . . . . . . |- 16
* . . . . . . . . . . . . . . . . . . . . |- 17
* . . . . . . . . . . . . . . . . . . . . |- 18
* . . . . . . . . . . . . . . . . . . . . |- 19
* . . . . . . . . . . . . . . . . . . . . |- 20
*/

/*
* rules:
* normal movable cell - '.'
* player - '@'
* not movable cell - '#'
* heal event on cell - '+'
* damage event on cell - '-'
* teleport enevt on cell - '^'
* score event on cell - '*'
* finish cell - '0'
*/
