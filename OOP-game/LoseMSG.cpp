#include "LoseMSG.h"


LoseMSG::LoseMSG(Player& player) {
	position = player.get_position();
}

std::string LoseMSG::PackMSG() {
	std::string str;
	str.append("Lose; player position: x ");
	str.append(std::to_string(position.x));
	str.append(", y ");
	str.append(std::to_string(position.y));
	str.append("\n");
	return str;
}