#include "lvl.h"

#include <iostream>

#include "Visualise.h"
#include "PlayerInput.h"
#include "InputCmdMSG.h"
#include "LoseMSG.h"
#include "NewGameMSG.h"
#include "WinMSG.h"


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
	std::string str = path;
	str.append("\\log.txt");
	out_stream.open(str);
	output = new MessageOutput(out_stream);
}

void lvl::start() {
	I_Message* msg = new NewGameMSG(field);
	output->writeLog(msg);
	vis->printField();
	Controlls cmd = pi->action();
	contr.MovePlayer(cmd);
	vis->printField();
	delete msg;
	msg = new InputCmdMSG(crls, cmd);
	output->writeLog(msg);
	while (!contr.EndGame()) {
		cmd = pi->action();
		contr.MovePlayer(cmd);
		vis->printField();
		delete msg;
		msg = new InputCmdMSG(crls, cmd);
		output->writeLog(msg);
	}
	if (contr.get_win()) {
		vis->Win(contr.getSteps());
		delete msg;
		msg = new WinMSG(player);
		output->writeLog(msg);
	}
	else {
		vis->GameOver(contr.getSteps());
		delete msg;
		msg = new LoseMSG(player);
		output->writeLog(msg);
	}
	system("pause");
}


lvl::~lvl() {
	out_stream.close();
	delete pi;
	delete vis;
	delete output;
}