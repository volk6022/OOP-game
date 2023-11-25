#include "EventSystem.h"

class TeleportEvent : virtual public Event
{
private:
	Symbols symbol;
	Player* player;
	Pos teleport;
public:
	TeleportEvent(Player* player, Pos teleport = def_pos);

	void OnEvent() override;

	Symbols get_symbol() override;
};