#ifndef SHIP_HPP
#define SHIP_HPP
#include <iostream>
#include <string.h>
using namespace std;
class Ship
{
protected:
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

#endif