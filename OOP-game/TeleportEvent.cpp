#include "TeleportEvent.h"


TeleportEvent::TeleportEvent(Player* player, Pos teleport) :
	player(player), teleport(teleport), symbol(Symbols::Teleport) {}

void TeleportEvent::OnEvent() {
	if (player == nullptr) return;
	player->set_position(teleport);
}

Symbols TeleportEvent::get_symbol() {
	return symbol;
}
