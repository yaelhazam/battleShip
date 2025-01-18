#include "Grid.hpp"
#include <limits>
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
bool Grid::isAdjacentOccupied(int row, int col, int shipSize, bool horizontal)
{
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            for (int k = 0; k < shipSize; k++)
            {
                int checkRow = horizontal ? row + i : row + k + i;
                int checkCol = horizontal ? col + k + j : col + j;

                if (checkRow >= 0 && checkRow < 10 && checkCol >= 0 && checkCol < 10)
                {
                    if (cells[checkRow][checkCol] == 'S')
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool Grid::isTillOccupied(int row, int col)
{
    if (cells[row][col] == 'S' || cells[row][col] == 'X')
    {
        return true;
    }
    return false;
}
bool Grid::inBounds(int row, int col, int shipSize, bool horizontal) const
{
    if (row < 0 || row > 9 || col < 0 || col > 9)
        return false;
    if (horizontal)
    {
        if (col + shipSize > 9)
            return false;
    }
    else
    {
        if (row + shipSize > 9)
            return false;
    }
    return true;
}
void Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol)
{
    while (isAdjacentOccupied(row, col, shipSize, horizontal) ||
           !inBounds(row, col, shipSize, horizontal) ||
           isTillOccupied(row, col))
    {
        cout << "Invalid placement, please try again (row and column between 1-10):" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (!(cin >> row >> col) || row < 1 || row > 10 || col < 1 || col > 10)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter row and column between 1-10:" << endl;
        }

        row--;
        col--;
    }

    for (int i = 0; i < shipSize; i++)
    {
        if (horizontal)
        {
            cells[row][col + i] = 'S';
        }
        else
        {
            cells[row + i][col] = 'S';
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (!ships[i].GetIsInit())
        {
            ships[i].SetCol(col);
            ships[i].SetRow(row);
            ships[i].SetHorizontal(horizontal);
            ships[i].SetSymbol(symbol);
            ships[i].SetInit();
            if(i==4){
                cout<<"All ships have been placed!"<<endl;
            }
            break;
        }
    }
}

ShipPosition *Grid::getPositions()
{
    return ships;
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
    cout << "   A B C D E F G H I J" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << (i + 1) << (i < 9 ? "  " : " ");
        for (int j = 0; j < 10; j++)
        {
            cout << cells[i][j] << " ";
        }

        cout << endl;
    }
}
