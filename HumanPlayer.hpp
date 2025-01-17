#ifndef HUMANPLAYER_HPP
#define HUMANPLAYER_HPP
#include <iostream>
using namespace std;
#include "Player.hpp"
class HumanPlayer : public Player
{
public:
    HumanPlayer(): Player("Human Player"){};
    void placeAllShips() override;
    void makeMove(Player *opponent) override;
};
#endif