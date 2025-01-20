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
        throw std::invalid_argument("There needs to be a human player and an AI player.");
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
    int count = 0;
    while (!isGameOver())
    {
        count++;
        player1->makeMove(player2);
        if (isGameOver())
            break;
        cout << "human player grid after turn - " << count << endl;
        player1->displayGrid();

        player2->makeMove(player1);
        cout << "ai player grid after turn - " << count << endl;
        player2->displayGrid();
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
    cout << "Game Over!" << endl;
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