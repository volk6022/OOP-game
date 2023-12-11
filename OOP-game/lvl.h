#pragma once
#include "EventSystem.h"
#include "Controlls.h"
#include "Player.h"
#include "Field.h"
#include "Controller.h"
#include "I_PlayerInput.h"
#include "Generator.h"
#include "I_Visualise.h"
#include "MessageOutput.h"


#include <string>
#include <map>
#include <fstream>


class lvl
{
private:
	Player player;
	Field field;
	Controller contr;
	I_PlayerInput* pi;
	I_Visualise* vis;
	std::map<int, Controlls> crls;
	std::map<Symbols, char> visuals;
	long long frameRate;
	std::ofstream out_stream;
	MessageOutput* output;
public:
	lvl(std::string path, long long frameRate);

	void start();

	~lvl();
};

