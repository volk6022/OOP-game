#pragma once
#include "I_Message.h"
#include "Player.h"

#include <vector>

class WinMSG : public I_Message
{
private:
	std::vector<Charact> characts;
public:
	// get all characts
	WinMSG(Player& player);

	std::string PackMSG() override;
};

