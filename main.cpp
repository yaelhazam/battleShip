#include <iostream>
#include <cstdlib> // For std::rand(), std::srand()
#include <ctime>   // For std::time()
#include "HumanPlayer.hpp"
#include "Player.hpp"
#include "AiPlayer.hpp"
#include "Game.hpp"
#include "Grid.hpp"
#include "Ship.hpp"
#include "Destroyer.hpp"
#include "Cruiser.hpp"
#include "Carrier.hpp"
#include "Submarine.hpp"
#include "BattleShip.hpp"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Player *p1 = new HumanPlayer();
    Player *p2 = new AiPlayer();

    Game game(p1, p2);

    game.setup();

    game.start();

    return 0;
}