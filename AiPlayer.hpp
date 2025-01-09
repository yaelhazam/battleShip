#include <iostream>
#include "Player.hpp"
using namespace std;

class AiPlayer : public Player
{
public:
    AiPlayer() : Player("Computer") {};

private:
    void placeAllShips();
    void makeMove();
    int getRandomCoordinate();
    ~AiPlayer();
};