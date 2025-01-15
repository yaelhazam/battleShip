#include <iostream>
#include <string.h>
//#include "Destroyer.hpp"
//#include "Cruiser.hpp"
//#include "Carrier.hpp"
//#include "Submarine.hpp"
//#include "Battleship.hpp"
using namespace std;
class Ship
{
private:
    char *name;
    int size;
    int hitsTaken;

public:
    Ship(const char *name, int size);
    int GetSize();
    int GetHitsTaken();
    virtual void takeHit();
    void GetName();
    bool isSunk() const;
    virtual ~Ship();
};