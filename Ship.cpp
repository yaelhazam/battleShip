#include "Ship.hpp"
#include <iostream>
Ship::Ship(const char *name, int size)
{
    this->size = size;
    this->hitsTaken = 0;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    delete[] name;
}
virtual void takeHit()
{
    this->hitsTaken++;
    cout << "Ship" << name << "has been hit!" << endl;
    if (isSunk())
        cout << "Ship" << name << "has been sunk!" << endl;
    return;
}
bool isSunk() const
{
    if (hitsTaken >= size)
        return true;
    return false;
}
Ship::~Ship()
{
    delete[] name;
}
