#pragma once

#include "I_Message.h"
#include "Player.h"

class LoseMSG : public I_Message
{
private:
	Pos postion;
public:
	LoseMSG(Player& player);

	std::string PackMSG() override;
};

