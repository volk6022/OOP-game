#pragma once
#include "EventSystem.h"
#include "Controlls.h"
#include "Player.h"
#include "Field.h"
#include "Controller.h"
#include "PlayerInput.h"
#include "Visualise.h"
#include "Generator.h"


#include <iostream>
#include <string>
#include <map>


class lvl
{
private:
	Player* player;
	Field* field;
	Controller* contr;
	PlyerInput* pi;
	Visualise* v;
	std::map<int, Controlls>* crls;
	std::map<Symbols, char>* visuals;
	long long frameRate;
public:
	lvl(std::string path, long long frameRate)
		: player(nullptr), field(nullptr), contr(nullptr), pi(nullptr), v(nullptr), crls(nullptr), visuals(nullptr), frameRate(frameRate)
	{
		Generator g(path);
		try {
			player = g.readPlayer();
			if (player == nullptr) {
				throw "Unable to read player.txt\n";
			}
			field = g.readField(player);
			if (field == nullptr) {
				throw "Unable to read field.txt\n";
			}
			crls = g.readControlSymbols();
			if (crls == nullptr) {
				throw "Unable to read crls.txt\n";
			}
			visuals = g.readSimbols();
			if (visuals == nullptr) {
				throw "Unable to read visuals.txt\n";
			}
			player->set_position(field->get_start());
		}
		catch (std::string s) {
			std::cerr << s;
			system("pause");
			exit(1);
		}
		if ((player != nullptr) && (field != nullptr) && (crls != nullptr) && (visuals != nullptr)) {
			contr = new Controller(player, field);
			pi = new PlyerInput(*crls, frameRate);
			v = new Visualise(player, field, visuals);
		}
	}

	void start() {
		if ((player == nullptr) || (field == nullptr) || (crls == nullptr) || (visuals == nullptr)) return;
		v->printField();
		contr->MovePlayer(pi->action());
		v->printField();
		while (!contr->EndGame()) {
			contr->MovePlayer(pi->action());
			v->printField();
		}
		if (contr->get_win()) {
			v->Win(contr->getSteps());
		}
		else {
			v->GameOver(contr->getSteps());
		}
	}

	~lvl(){
		delete player;
		delete field;
		delete crls;
		delete visuals;
		delete contr;
		delete pi;
		delete v;
	}
};

