#include "AiPlayer.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

void AiPlayer::placeAllShips()
{
    this->ships[0] = new Destroyer();
    this->ships[1] = new Cruiser();
    this->ships[2] = new Submarine();
    this->ships[3] = new BattleShip();
    this->ships[4] = new Carrier();

    bool horizontal = false;
    char Symbol = 'S';
    int row = 0;
    int col = 0;

    for (int i = 0; i < 5; i++)
    {
        row = getRandomCoordinate();
        col = getRandomCoordinate();
        horizontal = std::rand() % 2;
        while (this->grid.isTillOccupied(row, col) &&
               !this->grid.inBounds(row, col, this->ships[i]->GetSize(), horizontal))
        {
            row = getRandomCoordinate();
            col = getRandomCoordinate();
            horizontal = std::rand() % 2;
        }
        if (i == 0)
        {
            Symbol = 'D';
        }
        else if (i == 1)
        {
            Symbol = 'c';
        }
        else if (i == 2)
        {
            Symbol = 's';
        }
        else if (i == 3)
        {
            Symbol = 'B';
        }
        else if (i == 4)
        {
            Symbol = 'C';
        }
        this->grid.placeShip(row, col, this->ships[i]->GetSize(), horizontal, Symbol);
    }
}

void AiPlayer::makeMove(Player *opponent)
{
    int row = getRandomCoordinate();
    int col = getRandomCoordinate();
    while (row > 10 || row < 1 || col > 10 || col < 1)
    {
        row = getRandomCoordinate();
        col = getRandomCoordinate();
    }

    row--;
    col--;

    if (this->grid.getCell(row, col) == '~')
    {
        this->grid.markMiss(row, col);
        return;
    }
    if (this->grid.getCell(row, col) == 'S')
    {
        this->grid.markHit(row, col);
     for(int i = 0; i < 5; i++){
        if ((opponent->grid.getPositions()[i].GetRow() == row) && (opponent->grid.getPositions()[i].GetRow() == col))
        {
            char symbol = opponent->grid.getPositions()[i].GetSymbol();
            if (symbol == 'D')
            {
                opponent->ships[0]->Hit();
            }
            else if (symbol == 'c')
            {
                opponent->ships[1]->Hit();
            }
            else if (symbol == 's')
            {
                opponent->ships[2]->Hit();
            }
            else if (symbol == 'B')
            {
                opponent->ships[3]->Hit();
            }
            else if (symbol == 'C')
            {
                opponent->ships[4]->Hit();
            }
        }
     }
    }
    this->grid.printGrid();
}

int AiPlayer::getRandomCoordinate()
{
    return std::rand() % 10;
}
