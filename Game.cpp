#include "Game.hpp"
using namespace std;

Game::Game(Player *p1, Player *p2)
{
    bool human = false;
    bool ai = false;
    if (dynamic_cast<HumanPlayer *>(p1) != nullptr ||
        dynamic_cast<HumanPlayer *>(p2) != nullptr)
    {
        human = true;
    }
    if (dynamic_cast<AiPlayer *>(p1) != nullptr ||
        dynamic_cast<AiPlayer *>(p2) != nullptr)
    {
        ai = true;
    }
    if (!(human && ai))
    {
        cout << "Invalid players." << endl;
        cout << "There needs to be a human player and an AI player." << endl;
        return;
    }
    player1 = p1;
    player2 = p2;
}

void Game::setup()
{
    player1->placeAllShips();
    player2->placeAllShips();
    start();
}
void Game::start()
{
    while (!isGameOver())
    {
        player1->makeMove(player2);
        player2->makeMove(player1);
    }
    if (player1->allShipsSunk())
    {
        player2->GetName();
        cout << " wins!" << endl;
    }
    else
    {
        player1->GetName();
        cout << " wins!" << endl;
    }
    cout << "Game Over (:" << endl;
}
bool Game::isGameOver() const
{
    if (player1->allShipsSunk() || player2->allShipsSunk())
    {
        return true;
    }
    return false;
}
Game::~Game()
{
    delete player1;
    delete player2;
}