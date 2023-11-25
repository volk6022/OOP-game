#include "DamageEvent.h"

DamageEvent::DamageEvent(Player* player, int damage) :
	player(player), damage(damage), symbol(Symbols::Damage) {}

void DamageEvent::OnEvent() {
	if (player == nullptr) return;
	player->set_charact(Characts::HEALTH, player->get_charact(Characts::HEALTH).value - damage);
	damage = 0;
	symbol = Symbols::Empty;
}

Symbols DamageEvent::get_symbol() {
	return symbol;
}
