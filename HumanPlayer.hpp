#include <iostream>
using namespace std;
#include "Player.hpp"
class HumanPlayer : public Player
{
    HumanPlayer();
    void placeAllShips();
    void makeMove();
};