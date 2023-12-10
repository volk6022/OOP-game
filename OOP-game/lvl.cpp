#include "lvl.h"

#include <iostream>

#include "Visualise.h"
#include "PlayerInput.h"


lvl::lvl(std::string path, long long frameRate) : frameRate(frameRate)
{
	Generator g(path);
	try {
		Player* P = g.readPlayer();
		if (P == nullptr) {
			throw "Unable to read player.txt\n";
		}
		player = *P;
		Field* F = g.readField(P);
		if (F == nullptr) {
			throw "Unable to read field.txt\n";
		}
		field = *F;
		std::map<int, Controlls>* C = g.readControlSymbols();
		if (C == nullptr) {
			throw "Unable to read crls.txt\n";
		}
		crls = *C;
		std::map<Symbols, char>* V = g.readSimbols();
		if (V == nullptr) {
			throw "Unable to read visuals.txt\n";
		}
		visuals = *V;
		player.set_position(field.get_start());
	}
	catch (std::string s) {
		std::cerr << s;
		system("pause");
		exit(1);
	}
	contr = Controller(&player, &field);
	pi = dynamic_cast<I_PlayerInput*>(new PlayerInput(crls, frameRate));
	vis = dynamic_cast<I_Visualise*>(new Visualise(player, field, visuals));
}

void lvl::start() {
	vis->printField();
	contr.MovePlayer(pi->action());
	vis->printField();
	while (!contr.EndGame()) {
		contr.MovePlayer(pi->action());
		vis->printField();
	}
	if (contr.get_win()) {
		vis->Win(contr.getSteps());
	}
	else {
		vis->GameOver(contr.getSteps());
	}
	system("pause");
}


lvl::~lvl() {
	delete vis;
}