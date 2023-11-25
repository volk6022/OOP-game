#include "Generator.h"

//#include "DamageEvent.h"
//#include "HealEvent.h"
//#include "ScoreEvent.h"
//#include "TeleportEvent.h"
//
//#include <fstream>
//#include <exception>
//#include <iostream>
//
//#define field_start '@'
//#define field_stop '0'
//#define not_movable '#'
//#define movable '.'
//
//
//Generator::Generator(std::string path) : player(nullptr), contr(nullptr), field(nullptr) {
//	if (path.empty()) {
//		default_lvl();
//	}
//	else {
//		get_lvl(path);
//	}
//}
//
//void Generator::default_lvl() {
//	std::vector<def_value_type> chact;
//	chact.push_back(10);
//	chact.push_back(0);
//	chact.push_back(1);
//	std::vector<def_value_type> chactlim;
//	chactlim.push_back(100);
//	chactlim.push_back(1000);
//	chactlim.push_back(1);
//	player = new Player(chact, chactlim, { 0, 0 });
//	field = new Field(5, 5, { 0, 0 }, { 4, 4 });
//	field->set_movable(1, 1, false);
//	field->set_movable(1, 2, false);
//	field->set_movable(1, 3, false);
//	field->set_movable(2, 1, false);
//	field->setCellEvent(0, 1, new HealEvent(player, 20));
//	field->setCellEvent(0, 2, new DamageEvent(player, 20));
//	field->setCellEvent(0, 3, new ScoreEvent(player, 20));
//	field->setCellEvent(0, 4, new TeleportEvent(player, { 2,2 }));
//	contr = new Controller(*player, *field);
//}
//
//void Generator::get_lvl(std::string path) {
//	std::ifstream in(path);
//	if (!in) {
//		std::cout << "unable to open file\n";
//		return;
//	}
//	std::string str;
//	while (std::getline(in, str)) {
//		if (str.empty()) break;
//		if (str == "field:") { get_field(&in); continue; }
//		if (str == "player:") { get_player(&in); continue; }
//	}
//	try
//	{
//		if (player == nullptr) {
//			throw "Fatal Error: No Player detected";
//		}
//		if (field == nullptr) {
//			throw "Fatal Error: No Field detected";
//		}
//	}
//	catch (const char* error_message)
//	{
//		std::cout << error_message << std::endl;
//		system("pause");
//		std::abort();
//	}
//	contr = new Controller(*player, *field);
//	in.close();
//}
//
//void Generator::get_field(std::ifstream* in) {
//	std::string str;
//	if (!getline(*in, str)) { return; }
//	int x = std::stoi(str);
//	if (!getline(*in, str)) { return; }
//	int y = std::stoi(str);
//	std::vector<Pos> teleport;
//	std::vector<def_value_type> heal;
//	std::vector<def_value_type> damage;
//	std::vector<def_value_type> score;
//	field = new Field(x, y, def_pos, def_pos);
//	bool evntEnds = false;
//	while (!evntEnds && (std::getline(*in, str))) {
//		if (str.empty()) break;
//		switch (str[0]) {
//		case 't':
//			get_poses(teleport, in);
//			break;
//		case 'd':
//			get_values(damage, in);
//			break;
//		case 'h':
//			get_values(heal, in);
//			break;
//		case 's':
//			get_values(score, in);
//			break;
//		case 'f':
//			evntEnds = !evntEnds;
//			break;
//		}
//	}
//	int c = 0;
//	size_t telep_c = 0, dmg_c = 0, heal_c = 0, score_c = 0;
//	while (std::getline(*in, str)) {
//		if (str.empty()) break;
//		for (size_t i = 0; i < str.size() / 2; i++) {
//			switch (str[i * 2])
//			{
//				case char(field_start) :
//					field->set_start({ int(i), c });
//					if (player != nullptr) {
//						player->set_position(field->get_start());
//					}
//					break;
//				case char(not_movable) :
//					field->set_movable(i, c, false);
//					break;
//				case char(Symbols::Damage) :
//					field->setCellEvent(i, c, new DamageEvent(player, (dmg_c < damage.size()) ? damage[dmg_c] : def_damage));
//					++dmg_c;
//					break;
//				case char(Symbols::Heal) :
//					field->setCellEvent(i, c, new HealEvent(player, (heal_c < heal.size()) ? heal[heal_c] : def_heal));
//					++heal_c;
//					break;
//				case char(Symbols::Teleport) :
//					field->setCellEvent(i, c, new TeleportEvent(player, (telep_c < teleport.size()) ? teleport[telep_c] : Pos(def_pos)));
//					++telep_c;
//					break;
//				case char(Symbols::Score) :
//					field->setCellEvent(i, c, new ScoreEvent(player, (score_c < score.size()) ? score[score_c] : def_score));
//					++score_c;
//					break;
//				case char(field_stop) :
//					field->set_stop({ int(i), c });
//					break;
//			}
//		}
//		++c;
//	}
//}
//
//void Generator::get_poses(std::vector<Pos>& vec, std::ifstream* in) {
//	std::string str;
//	int x = 0, y = 0;
//	size_t p;
//	while (std::getline(*in, str)) {
//		if (str.empty()) break;
//		p = str.find_first_of("0123456789");
//		x = std::stoi(str.substr(p), &p);
//		p = str.find_first_of("0123456789", p);
//		y = std::stoi(str.substr(p), &p);
//		vec.push_back({ x, y });
//	}
//}
//
//void Generator::get_values(std::vector<def_value_type>& vec, std::ifstream* in) {
//	std::string str;
//	size_t p;
//	while (std::getline(*in, str)) {
//		if (str.empty()) break;
//		p = str.find_first_of("0123456789");
//		vec.push_back(static_cast<def_value_type>(std::stof(str.substr(p), &p)));
//	}
//}
//
//void Generator::get_player(std::ifstream* in) {
//	std::vector<def_value_type> chars;
//	std::vector<def_value_type> lims;
//	std::string str;
//	bool Ends = false;
//	while (!Ends && (std::getline(*in, str))) {
//		if (str.empty()) break;
//		switch (str[0]) {
//		case 'c':
//			get_values(chars, in);
//			break;
//		case 'l':
//			get_values(lims, in);
//			break;
//		default:
//			Ends = !Ends;
//			break;
//		}
//	}
//	player = new Player(chars, lims, (field != nullptr) ? field->get_start() : Pos(def_pos));
//}
//
//Generator::~Generator() {
//	player->~Player();
//	field->~Field();
//}
//
//
