#ifndef AIPLAYER_HPP
#define AIPLAYER_HPP
#include <iostream>
#include "Player.hpp"
using namespace std;

class AiPlayer : public Player
{
public:
    AiPlayer() : Player("Computer") {};

private:
    void placeAllShips() override;
    void makeMove(Player *opponent);
    int getRandomCoordinate();
    ~AiPlayer();
};

#endif