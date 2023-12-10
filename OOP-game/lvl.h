#pragma once
#include "EventSystem.h"
#include "Controlls.h"
#include "Player.h"
#include "Field.h"
#include "Controller.h"
#include "I_PlayerInput.h"
#include "Generator.h"
#include "I_Visualise.h"


#include <string>
#include <map>


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
public:
	lvl(std::string path, long long frameRate);

	void start();

	~lvl();
};

