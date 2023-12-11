#include "InputCmdMSG.h"


InputCmdMSG::InputCmdMSG(std::map<int, Controlls>& crls, Controlls cmd) {
	cmd = cmd;
	for (auto el : crls) {
		if (el.second == cmd) {
			KeyCode = el.first;
		}
	}
}

std::string InputCmdMSG::PackMSG() {
	std::string str;
	if (cmd == Controlls::nothing) {
		str = "No command on work, input KeyCode ";
		str.append(std::to_string(KeyCode));
		str.append("\n");
		return str;
	}
	str = "Command worked ";
	str.append(std::to_string(static_cast<int>(cmd)));
	str.append(", input KeyCode ");
	str.append(std::to_string(KeyCode));
	str.append("\n");
	return str;
}