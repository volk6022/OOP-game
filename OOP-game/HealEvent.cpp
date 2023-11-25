#include "HealEvent.h"


HealEvent::HealEvent(Player* player, int heal) :
	player(player), heal(heal), symbol(Symbols::Heal) {}

void HealEvent::OnEvent() {
	if (player == nullptr) return;
	player->set_charact(Characts::HEALTH, player->get_charact(Characts::HEALTH).value + heal);
	heal = 0;
	symbol = Symbols::Empty;
}

Symbols HealEvent::get_symbol() {
	return symbol;
}
