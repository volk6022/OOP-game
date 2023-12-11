#pragma once

#include <fstream>
#include <string>

#include "I_Message.h"


class MessageOutput
{
private:
	std::ofstream& output;
public:
	MessageOutput(std::ofstream& output) : output(output) {}

	void writeLog(I_Message* msg);
};

