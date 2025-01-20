#include "Ship.hpp"
#include <iostream>

Ship::Ship(const char *name, int size)
{
    this->size = size;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
void Ship::SetDirection(int dir)
{
    this->dir = dir;//0 for vertical, 1 for horizontal
}
void Ship::SetRow(int row)
{
    this->row = row;
}
void Ship::SetCol(int col)
{
    this->col = col;
}
int Ship::GetRow()
{
    return this->row;
}
int Ship::GetCol()
{
    return this->col;
}

int Ship::GetSize()
{
    return this->size;
}
int Ship::GetHitsTaken()
{
    return this->hitsTaken;
}
int Ship::GetDirection()
{
    return this->dir;
}

void Ship::takeHit()
{
    this->hitsTaken++;
   // cout << "Ship " << name << " has been hit!" << endl;//for debbuging
    if (isSunk())
        cout << "Ship " << this->name << " has been sunk!" << endl;
    return;
}
bool Ship::isSunk() const
{
    if (this->hitsTaken >= this->size)
        return true;
    return false;
}
void Ship::GetName()
{
    cout << this->name << endl;
}
Ship::~Ship()
{
    delete[] name;
}
