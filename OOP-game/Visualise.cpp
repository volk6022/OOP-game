#include "Visualise.h"

#include <iostream>



void Visualise::printField() {
    system("cls");
    Pos p = player.get_position();
    for (int i = 0; i < field.get_height(); i++)
    {
        for (int j = 0; j < field.get_width(); j++) {
            if ((p.y == i) && (p.x == j)) {
                std::cout << vis[Symbols::Player] << ' ';
                continue;
            }
            if ((j == field.get_stop().x) && (i == field.get_stop().y)) {
                std::cout << vis[Symbols::Finish] << ' ';
            }
            else if (field.get_movable(j, i)) {
                Event* e = field.getCellEvent(j, i);
                if (e == nullptr)
                    std::cout << vis[Symbols::Empty] << ' ';
                else {
                    char c = static_cast<char>(vis[e->get_symbol()]);
                    std::cout << c << ' ';
                }
            }
            else {
                std::cout << vis[Symbols::Impassable] << ' ';
            }
        }
        std::cout << '\n';
    }
    std::cout << "\nhealth:" << player.get_charact(Characts::HEALTH).value
        << "\nscore:" << player.get_charact(Characts::SCORE).value << '\n';
}

void Visualise::GameOver(int steps) {
    std::cout << "Game Over\n";
    std::cout << "Your score:" << player.get_charact(Characts::SCORE).value << '\n' << "Your steps: " << steps << '\n';
}

void Visualise::Win(int steps) {
    std::cout << "You Win!\n" << "Your score:" << player.get_charact(Characts::SCORE).value << '\n' << "Your steps: " << steps << '\n';
}
