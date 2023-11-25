#include "EventSystem.h"

#define def_damage 10
class DamageEvent : virtual public Event
{
private:
	Symbols symbol;
	Player* player;
	int damage;
public:
	DamageEvent(Player* player, int damage = def_damage);

	void OnEvent() override;

	Symbols get_symbol() override;
};
