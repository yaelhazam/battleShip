#include "Player.hpp"
class Game
{
public:
    Player *player1;
    Player *player2;
    Game(Player *p1, Player *p2);
    void setup();
    void start();
    bool isGameOver();
    ~Game();
};