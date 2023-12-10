#pragma once

#include "I_Visualise.h"

#include "Player.h"
#include "Field.h"
#include "EventSystem.h"

#include <map>


class Visualise : public I_Visualise
{
private:
    Player& player;
    Field& field;
    std::map<Symbols, char> vis;
public:
    Visualise() : player(*(new Player())), field(*(new Field())) {};

    Visualise(Player& player, Field& field, std::map<Symbols, char> vis) :
        player(player), field(field), vis(vis) {}

    void printField() override;

    void GameOver(int steps) override;

    void Win(int steps) override;
};

