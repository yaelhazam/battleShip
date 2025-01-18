#ifndef GRID_HPP
#define GRID_HPP
#include <iostream>
#include "ShipPosition.hpp"
using namespace std;
class Grid
{
private:
    char cells[10][10];
    ShipPosition ships[5];

public:
    Grid();
    ShipPosition *getPositions();
    bool isAdjacentOccupied(int row, int col, int shipSize, bool horizontal);
    void placeShip(int row, int col, int shipSize, bool horizontal, char symbol);
    bool isTillOccupied(int row, int col);
    bool inBounds(int row, int col, int shipSize, bool horizontal) const;
    void markHit(int row, int col);
    void markMiss(int row, int col);
    char getCell(int row, int col) const;
    void printGrid();
};

#endif
