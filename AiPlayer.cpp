#include "AiPlayer.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;


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
            int direction = 0;
            if (horizontal)
            {
                direction = 1;
            }
            //cout << "AI trying to place ship " << ships[i]->GetSize()
            //     << " cells at row " << row + 1 << ", col " << col + 1
            //    << " (horizontal: " << horizontal << ")" << endl; //for debbuging

            if (!grid.isAdjacentOccupied(row, col, ships[i]->GetSize(), horizontal) &&
                grid.inBounds(row, col, ships[i]->GetSize(), horizontal) &&
                !grid.isTillOccupied(row, col))
            {
                grid.placeShip(row, col, ships[i]->GetSize(), horizontal, Symbol);
                placed = true;
                this->ships[i]->SetRow(row);
                this->ships[i]->SetCol(col);
                this->ships[i]->SetDirection(direction);
                //cout << "AI placed ship at row " << row + 1 << ", col "//for debbuging
                    // << col + 1 << endl;
            }
        }
    }
    //grid.printGrid();//debbuging
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
        cout << "AI You missed!" << endl;
    }

    else if (opponent->GetGrid().getCell(row, col) == 'S')
    {
        opponent->GetGrid().markHit(row, col);
        cout << "Hit!" << endl;

        for (int i = 0; i < 5; i++)
        {
            int shipSize = opponent->getShip(i)->GetSize();
            int dir = opponent->getShip(i)->GetDirection(); 
            int shipRow = opponent->getShip(i)->GetRow();
            int shipCol = opponent->getShip(i)->GetCol();

            bool hit = false;

            if (dir == 1) 
            {
                if (row == shipRow && col >= shipCol && col < shipCol + shipSize)
                {
                    hit = true;
                }
            }
            else 
            {
                if (col == shipCol && row >= shipRow && row < shipRow + shipSize)
                {
                    hit = true;
                }
            }

            if (hit)
            {
                opponent->getShip(i)->takeHit();
                break;
            }
        }
    }

    cout << "opponents ships state:" << endl;
    cout << "ship 1 hits: " << opponent->getShip(0)->GetHitsTaken() << endl;
    cout << "ship 2 hits: " << opponent->getShip(1)->GetHitsTaken() << endl;
    cout << "ship 3 hits: " << opponent->getShip(2)->GetHitsTaken() << endl;
    cout << "ship 4 hits: " << opponent->getShip(3)->GetHitsTaken() << endl;
    cout << "ship 5 hits: " << opponent->getShip(4)->GetHitsTaken() << endl;
}

int AiPlayer::getRandomCoordinate()
{
    return std::rand() % 10;
}
