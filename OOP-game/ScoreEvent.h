#include "EventSystem.h"

#define def_score 10
class ScoreEvent : virtual public Event
{
private:
	Symbols symbol;
	Player* player;
	int score;
public:
	ScoreEvent(Player* player, int score = def_score);

	void OnEvent() override;

	Symbols get_symbol() override;
};

