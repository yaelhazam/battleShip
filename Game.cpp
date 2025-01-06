#include "Game.hpp"
Game::Game(Player *p1, Player *p2)
{
    if(p1 == nullptr || p2 == nullptr){
        cout << "Invalid players" << endl;
        return;
    }//check if one is ai and one is human

    players[0] = p1;
    players[1] = p2;
}

Game::~Game()
{
    delete players[0];
    delete players[1];
}