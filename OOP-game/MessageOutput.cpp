#include "MessageOutput.h"


void MessageOutput::writeLog(I_Message* msg) {
	if (output.is_open())
		output << msg->PackMSG();
}