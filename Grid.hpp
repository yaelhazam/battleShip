#include <iostream>
using namespace std;
class Grid
{
    public:
    char* cells[10][10];
    Grid();
    void placeShip(int row, int col, int shipSize, bool horizontal, char symbol)
    bool isTillOccupied(int row, int col);
    bool inBounds(int row, int col, int shipSize, bool horizontal) const
    void markHit(int row, int col);
    void markMiss(int row, int col);
    char getCell(int row, int col) const;
    printGrid();
    ~Grid();

};
