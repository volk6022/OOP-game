#pragma once

#include "I_Message.h"
#include "Player.h"
#include "Field.h"

#include <string>

class NewGameMSG : public I_Message
{
private:
	Pos fieldShape;
	Pos PlayerPosition;
public:
	NewGameMSG(Player& player, Field& filed);

	std::string PackMSG() override;
};

