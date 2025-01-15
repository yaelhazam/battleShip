#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include "Ship.hpp"
#include "Grid.hpp"
#include "Destroyer.hpp"
#include "Cruiser.hpp"
#include "Carrier.hpp"
#include "Submarine.hpp"
#include "BattleShip.hpp"
using namespace std;
class Player
{
protected:
    char *playerName;
    Ship *ships[5];
    Grid grid;

public:
    Player(const char *name);
    virtual void placeAllShips();
    virtual void makeMove(Player *opponent);
    bool allShipsSunk() const;
    void GetName();
    void SetShip(Ship *ship);
    void displayGrid();
    virtual ~Player();
};

#endif
