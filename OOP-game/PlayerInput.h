#pragma once
#include "I_PlayerInput.h"
#include "timer.h"

#include <map>


class PlayerInput : public I_PlayerInput
{
private:
	std::map<int, Controlls> crls;
	Timer ti;
	long long frameRate;
	Controlls c;
public:
	PlayerInput() {}
	PlayerInput(std::map<int, Controlls>& crls, long long frameRate) : crls(crls), frameRate(frameRate) {};

	Controlls action() override;
};

