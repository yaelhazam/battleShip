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
private:
    char *playerName;
    Ship *ships[5];
    Grid grid;

public:
    Player(const char *name);
    virtual void placeAllShips();
    virtual void makeMove(Player *opponent);
    bool allShipsSunk() const;
    void GetName();
    void displayGrid();
    virtual ~Player();
};
