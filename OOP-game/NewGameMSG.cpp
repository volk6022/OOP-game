#include "NewGameMSG.h"


NewGameMSG::NewGameMSG(Field& field) {
	fieldShape = Pos(field.get_width(), field.get_height());
	PlayerPosition = field.get_start();
}

std::string NewGameMSG::PackMSG() {
	std::string str;
	str.append("New Game; start position: x ");
	str.append(std::to_string(PlayerPosition.x));
	str.append(", y ");
	str.append(std::to_string(PlayerPosition.y));
	str.append(" ; field shape: x ");
	str.append(std::to_string(fieldShape.x));
	str.append(", y ");
	str.append(std::to_string(fieldShape.y));
	str.append("\n");
	return str;
}
