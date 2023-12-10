#pragma once
//#include "Characts.h"
#include "GameObject.h"
#include <memory>
#include <vector>


enum class Characts : int
{
	START = 0,

	HEALTH,
	SCORE,
	WEIGHT,

	END,
};


#define def_value_type float


struct Charact {
	Characts type;
	def_value_type value;
	Charact(Characts type, def_value_type value) :
		type(type), value(value) {}
};


class Player : GameObject
{
private:
	std::vector<Charact> CharactsList;
	std::vector<Charact> CharactsLimits;

	using GameObject::position;
	using GameObject::visible;

	void clear();
public:
	Player() {}

	Player(std::vector<def_value_type> characts, std::vector<def_value_type> Limits, Pos position);

	Charact get_charact(Characts c);

	void set_charact(Characts c, def_value_type value);

	Charact get_limit(Characts c);

	void set_limit(Characts c, def_value_type value);

	Player(Player& other);

	Player& operator=(const Player& other);

	Player(Player&& other) noexcept;

	Player& operator=(Player&& other) noexcept;

	~Player();

	using GameObject::get_position;
	using GameObject::set_position;
	using GameObject::get_visible;
	using GameObject::set_visible;
};