#include <iostream>
#include <cstdlib> // For std::rand(), std::srand()
#include <ctime>   // For std::time()
#include "HumanPlayer.hpp"
#include "Player.hpp"
#include "AiPlayer.hpp"
#include "Game.hpp"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
   
    Player *p1 = new HumanPlayer("Player 1");
    Player *p2 = new AiPlayer("Player 2");

    Game game(p1, p2);

    game.setup();
    
    game.start();
    
    return 0;
}