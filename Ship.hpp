#ifndef SHIP_HPP
#define SHIP_HPP
#include <iostream>
#include <string.h>
using namespace std;
class Ship
{
protected:
    char *name;
    int size = 0;
    int hitsTaken = 0;
    int row = 0;
    int col = 0;
    int dir = 0; // 0 for vertical, 1 for horizontal

public:
    Ship(const char *name, int size);
    void SetDirection(int dir);
    void SetRow(int row);
    void SetCol(int col);
    int GetDirection();
    int GetRow();
    int GetCol();
    int GetSize();
    int GetHitsTaken();
    virtual void takeHit();
    void GetName();
    bool isSunk() const;
    virtual ~Ship();
};

#endif