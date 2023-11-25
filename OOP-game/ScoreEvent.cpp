#include "ScoreEvent.h"


ScoreEvent::ScoreEvent(Player* player, int score) :
	player(player), score(score), symbol(Symbols::Score) {}

void ScoreEvent::OnEvent() {
	if (player == nullptr) return;
	player->set_charact(Characts::SCORE, player->get_charact(Characts::SCORE).value + score);
	score = 0;
	symbol = Symbols::Empty;
}

Symbols ScoreEvent::get_symbol() {
	return symbol;
}
