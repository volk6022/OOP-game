#pragma once

#include "Player.h"
#include "Field.h"
#include "EventSystem.h"

#include <iostream>
#include <map>

class Visualise
{
private:
    Player* player;
    Field* field;
    std::map<Symbols, char>* vis;
public:
    Visualise(Player* player, Field* field, std::map<Symbols, char>* vis) :
        player(player), field(field), vis(vis) {}

    void printField() {
        system("cls");
        Pos p = player->get_position();
        for (int i = 0; i < field->get_height(); i++)
        {
            for (int j = 0; j < field->get_width(); j++) {
                if ((p.y == i) && (p.x == j)) {
                    std::cout << (*vis)[Symbols::Player] << ' ';
                    continue;
                }
                if ((j == field->get_stop().x) && (i == field->get_stop().y)) {
                    std::cout << (*vis)[Symbols::Finish] << ' ';
                }
                else if (field->get_movable(j, i)) {
                    Event* e = field->getCellEvent(j, i);
                    if (e == nullptr)
                        std::cout << (*vis)[Symbols::Empty] << ' ';
                    else {
                        char c = static_cast<char>((*vis)[e->get_symbol()]);
                        std::cout << c << ' ';
                    }
                }
                else {
                    std::cout << (*vis)[Symbols::Impassable] << ' ';
                }
                }
                std::cout << '\n';
            }
        std::cout << "\nhealth:" << player->get_charact(Characts::HEALTH).value
           << "\nscore:" << player->get_charact(Characts::SCORE).value
           << "\nposition:" << player->get_position().x << ' ' << player->get_position().y << '\n';
    }

    void GameOver(int steps) {
        std::cout << "Game Over\n";
        std::cout << "Your score:" << player->get_charact(Characts::SCORE).value << '\n' << "Your steps: " << steps << '\n';
    }

    void Win(int steps) {
        std::cout << "You Win!\n" << "Your score:" << player->get_charact(Characts::SCORE).value << '\n' << "Your steps: " << steps << '\n';
    }

    void ReadingErrorMessage(std::string name) {
        std::cout << "Reading file error, file: " << name << '\n';
    }
};

