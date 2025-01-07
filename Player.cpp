#include "Player.hpp"

Player::Player(const char *name)
{
    this->playerName = new char *[strlen(name) + 1];
    strcpy(this->name, name);
    delete[] name;
    this->grid = new Grid();
}
virtual void placeAllShips()
{
    int count = 0;
    while(count<5)
    {
        
    }
}
virtual void makeMove(Player *opponent)
{
    
}
bool allShipsSunk()const{
    
}

Player::~Player()
{
    delete[] this->playerName;
    delete this->grid;
    delete this->ships;
}