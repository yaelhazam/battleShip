#include "Player.hpp"
class Game{
public:
Player *players[2];
Game(Player *p1, Player *p2);
~Game();
};