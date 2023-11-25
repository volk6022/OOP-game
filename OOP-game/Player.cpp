#include "Player.h"

#define def_charact_value 100.f


// private

void Player::clear() {
	if (!CharactsList.empty())
		CharactsList.clear();
	if (!CharactsLimits.empty())
		CharactsLimits.clear();
}


// public

Player::Player(std::vector<def_value_type> List, std::vector<def_value_type> Limits, Pos position) {
	GameObject({position.x, position.y});
	CharactsLimits.clear();
	int i = static_cast<int>(Characts::START) + 1;
	while (i < static_cast<int>(Characts::END)) {
		if (i <= Limits.size()) {
			CharactsLimits.push_back(Charact(static_cast<Characts>(i), Limits[i-1]));
		}
		else {
			CharactsLimits.push_back(Charact(static_cast<Characts>(i), def_charact_value));
		}
		++i;
	}
	CharactsList.clear();
	i = static_cast<int>(Characts::START) + 1;
	while (i < static_cast<int>(Characts::END)) {
		if (i <= List.size()) {
			CharactsList.push_back(Charact(static_cast<Characts>(i), List[i-1]));
		}
		else {
			CharactsList.push_back(Charact(static_cast<Characts>(i), def_charact_value));
		}
		++i;
	}
}


Charact Player::get_charact(Characts c) {
	return CharactsList[static_cast<int>(c) - 1];
}


void Player::set_charact(Characts c, def_value_type value) {
	if (value < 0) value = 0;
	if (value > CharactsLimits[static_cast<int>(c)-1].value) value = CharactsLimits[static_cast<int>(c)-1].value;
	CharactsList[static_cast<int>(c)-1].value = value;
}


Charact Player::get_limit(Characts c) {
	return CharactsList[static_cast<int>(c) - 1];
}


void Player::set_limit(Characts c, def_value_type value) {
	if (value < 0) value = 0;
	if (value > CharactsLimits[static_cast<int>(c) - 1].value) value = CharactsLimits[static_cast<int>(c) - 1].value;
	CharactsList[static_cast<int>(c) - 1].value = value;
}


Player::Player(Player& other) {
	CharactsLimits = other.CharactsLimits;
	CharactsList = other.CharactsList;
	GameObject(other.position);
}


Player& Player::operator=(const Player& other) {
	if (this == &other) {
		return *this;
	}
	this->clear();
	CharactsList = other.CharactsList;
	CharactsLimits = other.CharactsLimits;
	position = other.position;
	return *this;
}


Player::Player(Player&& other) noexcept {
	std::swap(CharactsLimits, other.CharactsLimits);
	std::swap(CharactsList, other.CharactsList);
	GameObject(other.position);
	other.~Player();
}


Player& Player::operator=(Player&& other) noexcept {
	if (this == &other) {
		return *this;
	}
	this->clear();
	std::swap(CharactsLimits, other.CharactsLimits);
	std::swap(CharactsList, other.CharactsList);
	position = other.position;
	other.~Player();
	return *this;
}


Player::~Player() {
	this->clear();
}
