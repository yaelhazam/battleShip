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

    bool horizontal;
    char Symbol;
    int row, col;

    for (int i = 0; i < 5; i++)
    {
        Symbol = 'S'; 
        bool placed = false;

        while (!placed)
        {
            row = getRandomCoordinate();
            col = getRandomCoordinate();
            horizontal = (std::rand() % 2 == 0);

            cout << "AI trying to place ship " << ships[i]->GetSize() 
                 << " cells at row " << row + 1 << ", col " << col + 1 
                 << " (horizontal: " << horizontal << ")" << endl;

            if (!grid.isAdjacentOccupied(row, col, ships[i]->GetSize(), horizontal) &&
                grid.inBounds(row, col, ships[i]->GetSize(), horizontal) &&
                !grid.isTillOccupied(row, col))
            {
                grid.placeShip(row, col, ships[i]->GetSize(), horizontal, Symbol);
                placed = true;

                cout << "AI placed ship at row " << row + 1 << ", col " 
                     << col + 1 << endl;
            }
        }
    }

    cout << "AI placement completed!" << endl;
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

    if (opponent->GetGrid().getCell(row, col) == 'M' || opponent->GetGrid().getCell(row, col) == 'H')
    {
        while (row > 10 || row < 1 || col > 10 || col < 1)
        {
            row = getRandomCoordinate();
            col = getRandomCoordinate();
        }
    }

    if (opponent->GetGrid().getCell(row, col) == '~')
    {
        opponent->GetGrid().markMiss(row, col);
        cout << "You missed!" << endl;
        return;
    }

    if (opponent->GetGrid().getCell(row, col) == 'S')
    {
        opponent->GetGrid().markHit(row, col);
        for (int i = 0; i < 5; i++)
        {
            if ((opponent->GetGrid().getPositions()[i].GetRow() == row) && (opponent->GetGrid().getPositions()[i].GetRow() == col))
            {
                char symbol = opponent->GetGrid().getPositions()[i].GetSymbol();
                if (symbol == 'D')
                {
                    opponent->getShip(0)->takeHit();
                }
                else if (symbol == 'c')
                {
                    opponent->getShip(1)->takeHit();
                }
                else if (symbol == 's')
                {
                    opponent->getShip(2)->takeHit();
                }
                else if (symbol == 'B')
                {
                    opponent->getShip(3)->takeHit();
                }
                else if (symbol == 'C')
                {
                    opponent->getShip(4)->takeHit();
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
