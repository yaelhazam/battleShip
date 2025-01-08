#include "Game.hpp"
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
    p1->placeAllShips();
    p2->placeAllShips();
    start();
}
void Game::start()
{
    while (!isGameOver())
    {
        p1->makeMove(p2);
        p2->makeMove(p1);
    }
    if (p1->allShipsSunk())
    {
        cout << p2->getName() << " wins!" << endl;
    }
    else
    {
        cout << p1->getName() << " wins!" << endl;
    }
    cout << "Game Over (:" << endl;
}
bool isGameOver() const
{
    if (p1->allShipsSunk() || p2->allShipsSunk())
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