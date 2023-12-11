#pragma once

#include "I_Message.h"
#include "Player.h"
#include "Field.h"


class NewGameMSG : public I_Message
{
private:
	Pos fieldShape;
	Pos PlayerPosition;
public:
	NewGameMSG(Field& field);

	std::string PackMSG() override;
};

