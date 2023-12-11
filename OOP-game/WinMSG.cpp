#include "WinMSG.h"


WinMSG::WinMSG(Player& player) {
	characts = player.get_CR_List();
}

std::string WinMSG::PackMSG() {
	std::string str;
	str.append("Win; player Characts: health ");
	str.append(std::to_string(static_cast<int>(characts[0].value)));
	str.append(", score ");
	str.append(std::to_string(static_cast<int>(characts[1].value)));
	str.append("\n");
	return str;
}