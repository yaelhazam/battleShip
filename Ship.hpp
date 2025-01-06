#include <iostream>

class Ship
{
private:
    char *name;
    int size;
    int hitsTaken;

public:
    Ship(const char *name, int size);
    virtual void takeHit();
    bool isSunk()const;
    virtual ~Ship();
};