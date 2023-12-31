#include "Generator.h"

#include "Player.h"
#include "Field.h"
#include "DamageEvent.h"
#include "HealEvent.h"
#include "ScoreEvent.h"
#include "TeleportEvent.h"
#include "Controlls.h"
#include "EventSystem.h"

#include <string>
#include <map>
#include <fstream>
#include <iostream>


Player* Generator::readPlayer()
{
	std::ifstream in(pathDir + "\\player.txt");
	if (!in.is_open()) {
		std::cout << "there is no player.txt file\n";
		return nullptr;
	}
	std::vector<def_value_type> chars;
	std::vector<def_value_type> lims;
	std::string str;
	bool Ends = false;
	while (!Ends && (std::getline(in, str))) {
		if (str.empty()) break;
		switch (str[0]) {
		case 'c':
			get_values(chars, &in);
			break;
		case 'l':
			get_values(lims, &in);
			break;
		default:
			Ends = !Ends;
			break;
		}
	}
	in.close();
	return new Player(chars, lims, Pos(def_pos));
}


Field* Generator::readField(Player* player) {
	std::ifstream in(pathDir + "\\field.txt");
	if (!in.is_open()) {
		std::cout << "there is no field.txt file\n";
		return nullptr;
	}
	std::string str;
	if (!std::getline(in, str)) { return nullptr; }
	int x = std::stoi(str.c_str());
	if (!std::getline(in, str)) { return nullptr; }
	int y = std::stoi(str.c_str());
	std::vector<Pos> teleport;
	std::vector<def_value_type> heal;
	std::vector<def_value_type> damage;
	std::vector<def_value_type> score;
	Field* field = new Field(x, y, def_pos, def_pos);
	bool evntEnds = false;
	while (!evntEnds && (std::getline(in, str))) {
		if (str.empty()) break;
		switch (str[0]) {
		case 't':
			get_poses(teleport, &in);
			break;
		case 'd':
			get_values(damage, &in);
			break;
		case 'h':
			get_values(heal, &in);
			break;
		case 's':
			get_values(score, &in);
			break;
		case 'f':
			evntEnds = !evntEnds;
			break;
		}
	}

	int c = 0;
	uint32_t telep_c = 0, dmg_c = 0, heal_c = 0, score_c = 0;
	while (std::getline(in, str)) {
		if (str.empty()) break;
		for (int i = 0; i < str.size() / 2; i++) {
			switch (str[i * 2])
			{
				case char(Symbols::Start) :
					field->set_start({ int(i), c });
					break;
				case char(Symbols::Impassable) :
					field->set_movable(i, c, false);
					break;
				case char(Symbols::Damage) :
					field->setCellEvent(i, c, new DamageEvent(player, (dmg_c < damage.size()) ? damage[dmg_c] : def_damage));
					++dmg_c;
					break;
				case char(Symbols::Heal) :
					field->setCellEvent(i, c, new HealEvent(player, (heal_c < heal.size()) ? heal[heal_c] : def_heal));
					++heal_c;
					break;
				case char(Symbols::Teleport) :
					field->setCellEvent(i, c, new TeleportEvent(player, (telep_c < teleport.size()) ? teleport[telep_c] : Pos(def_pos)));
					++telep_c;
					break;
				case char(Symbols::Score) :
					field->setCellEvent(i, c, new ScoreEvent(player, (score_c < score.size()) ? score[score_c] : def_score));
					++score_c;
					break;
				case char(Symbols::Finish) :
					field->set_stop({ int(i), c });
					break;
			}
		}
		++c;
	}
	in.close();
	return field;
}


std::map<Symbols, char>* Generator::readSimbols() {
	// make check if not all visuals is set, use def values
	std::ifstream in(pathDir + "\\visuals.txt");
	if (!in.is_open()) {
		std::cout << "there is no visuals.txt file\n";
		return nullptr;
	}

	std::string str;
	std::map<Symbols, char>* m = new std::map<Symbols, char>;
	while (std::getline(in, str)) {
		if ((str == "Damage") && (std::getline(in, str))) {
			(*m)[Symbols::Damage] = str[0];
			continue;
		}
		if ((str == "Heal") && (std::getline(in, str))) {
			(*m)[Symbols::Heal] = str[0];
			continue;
		}
		if ((str == "Score") && (std::getline(in, str))) {
			(*m)[Symbols::Score] = str[0];
			continue;
		}
		if ((str == "Teleport") && (std::getline(in, str))) {
			(*m)[Symbols::Teleport] = str[0];
			continue;
		}
		if ((str == "Empty") && (std::getline(in, str))) {
			(*m)[Symbols::Empty] = str[0];
			continue;
		}
		if ((str == "Player") && (std::getline(in, str))) {
			(*m)[Symbols::Player] = str[0];
			continue;
		}
		if ((str == "Start") && (std::getline(in, str))) {
			(*m)[Symbols::Start] = str[0];
			continue;
		}
		if ((str == "Finish") && (std::getline(in, str))) {
			(*m)[Symbols::Finish] = str[0];
			continue;
		}
		if ((str == "Impassable") && (std::getline(in, str))) {
			(*m)[Symbols::Impassable] = str[0];
			continue;
		}
	}
	in.close();
	return m;
}


std::map<int, Controlls>* Generator::readControlSymbols() {
	// make check if not all controls is set
	std::ifstream in(pathDir + "\\controls.txt");
	if (!in.is_open()) {
		std::cout << "there is no controls.txt file\n";
		return nullptr;
	}

	std::string str;
	std::map<int, Controlls>* m = new std::map<int, Controlls>;
	while (std::getline(in, str)) {
		if ((str == "up") && (std::getline(in, str))) {
			(*m)[std::atoi(str.c_str())] = Controlls::up;
			continue;
		}
		if ((str == "down") && (std::getline(in, str))) {
			(*m)[std::atoi(str.c_str())] = Controlls::down;
			continue;
		}
		if ((str == "right") && (std::getline(in, str))) {
			(*m)[std::atoi(str.c_str())] = Controlls::right;
			continue;
		}
		if ((str == "left") && (std::getline(in, str))) {
			(*m)[std::atoi(str.c_str())] = Controlls::left;
			continue;
		}
		if ((str == "menu") && (std::getline(in, str))) {
			(*m)[std::atoi(str.c_str())] = Controlls::menu;
			continue;
		}
	}
	in.close();
	return m;
}


void Generator::get_values(std::vector<def_value_type>& vec, std::ifstream* in) {
	std::string str;
	size_t p;
	while (std::getline(*in, str)) {
		if (str.empty()) break;
		p = str.find_first_of("0123456789");
		vec.push_back(static_cast<def_value_type>(std::stof(str.substr(p), &p)));
	}
}


void Generator::get_poses(std::vector<Pos>& vec, std::ifstream* in) {
	std::string str;
	int x = 0, y = 0;
	size_t p;
	while (std::getline(*in, str)) {
		if (str.empty()) break;
		p = str.find_first_of("0123456789");
		x = std::stoi(str.substr(p), &p);
		p = str.find_first_of("0123456789", p);
		y = std::stoi(str.substr(p), &p);
		vec.push_back({ x, y });
	}
}