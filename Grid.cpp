#include "Grid.hpp"
Grid::Grid()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cells[i][j] = '~';
        }
    }
}
bool Grid::isTillOccupied(int row, int col)
{
    if (cells[row][col] != '~' && cells[row][col] != 'M')
    {
        return true;
    }
    return false;
}
bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const
{
    if (horizontal)
    {
        if (col + shipSize > 10)
            return false;
    }
    if (!horizontal)
    {
        if (row + shipSize > 10)
            return false;
    }
    return true;
}
void Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol)
{
    cells[row][col] = symbol;//
    return;
}
void Grid::markHit(int row, int col)
{
    cells[row][col] = 'H';
    return;
}
void Grid::markMiss(int row, int col)
{
    cells[row][col] = 'M';
    return;
}
char Grid::getCell(int row, int col) const
{
    return cells[row][col];
}
void Grid::printGrid()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << cells[i][j] << " ";
        }
        cout << endl;
    }
}
Grid::~Grid()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            delete[] cells[i][j];
        }
    }
    delete[] cells;
}