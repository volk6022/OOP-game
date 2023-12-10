#pragma once

#include "I_Message.h"

#include "Controlls.h"

#include <string>
#include <map>

class InputNoCmdMSG : public I_Message
{
private:
	Controlls cmd;
	int KeyCode;
public:
	InputNoCmdMSG(std::map<int, Controlls>& crls, Controlls cmd);

	std::string PackMSG() override;
};

