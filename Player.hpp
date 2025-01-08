#include <iostream>
#include "Ship.hpp"
#include "Grid.hpp"
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
    void displayGrid();
    virtual ~Player();
}
