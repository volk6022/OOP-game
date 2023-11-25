#include "EventSystem.h"

#define def_heal 10
class HealEvent : virtual public Event
{
private:
	Symbols symbol;
	Player* player;
	int heal;
public:
	HealEvent(Player* player, int heal = def_heal);

	void OnEvent() override;

	Symbols get_symbol() override;
};

