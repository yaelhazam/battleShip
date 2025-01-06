#include <iostream>
using namespace std;
#include "Player.hpp"
class AiPlayer : public Player
{
    AiPlayer();
    void placeAllShips();
    void makeMove();
    int getRandomCoordinate();
    ~AiPlayer();
};