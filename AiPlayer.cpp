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
    this->ships[3] = new Battleship();
    this->ships[4] = new Carrier();

    bool horizontal = false;
    char Symbol = 'S';
    int row = 0;
    int col = 0;

    for (int i = 0; i < shipSize; i++)
    {
        if (horizontal)
        {
            if (isTillOccupied(row, col + i))
            {
                occupied = true;
                break;
            }
        }
        else
        {
            if (isTillOccupied(row + i, col))
            {
                occupied = true;
                break;
            }
        }
    }


    for (int i = 0; i < 5; i++)
    {
        row = getRandomCoordinate();
        col = getRandomCoordinate();
        horizontal = std::rand() % 2;
        while (this->grid.isTillOccupied(row, col) &&
        !this->grid.inBounds(row, col, this->ships[i]->getSize(), horizontal))
        {
            row = getRandomCoordinate();
            col = getRandomCoordinate();
        }
        this->grid.placeShip(row, col, this->ships[i]->getSize(), horizontal, Symbol);
    }

}

void AiPlayer::makeMove()
{
    
}

int AiPlayer::getRandomCoordinate()
{
    return std::rand() % 10;
}
