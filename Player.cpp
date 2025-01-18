#include "Player.hpp"
#include <iostream>
#include <limits>
using namespace std;

Player::Player(const char *name)
{
    this->playerName = new char[strlen(name) + 1];
    strcpy(this->playerName, name);
}
void Player::placeAllShips()
{
    this->ships[0] = new Destroyer();
    this->ships[1] = new Cruiser();
    this->ships[2] = new Submarine();
    this->ships[3] = new BattleShip();
    this->ships[4] = new Carrier();

    bool horizontal = false;
    char Symbol = ' ';
    int row = 0;
    int col = 0;
    int direction = 0;

    cout << "this is your grid" << endl;
    this->grid.printGrid();
    cout << "now you will need to place all 5 ships:" << endl;
    cout << "notice that the row and column are 1-10" << endl;

    for (int i = 0; i < 5; i++)
    {
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
        cout << "ship - " << i + 1 << " -" << endl;
        ships[i]->GetName();
        cout << "Has size of " << this->ships[i]->GetSize() << " cells" << endl;
        cout << "Please Enter for row and then column:" << endl;
        cin >> row >> col;
        cout << "Enter for horizontal or vertical with 1 for horizontal and 0 for vertical:" << endl;
        cin >> direction;
        horizontal = (direction == 1) ? true : false;
        row--;
        col--;
        this->grid.placeShip(row, col, this->ships[i]->GetSize(), horizontal, Symbol);
        this->grid.printGrid();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
void Player::makeMove(Player *opponent)
{
    int row;
    int col;
    cout << "please enter row and then column:" << endl;
    cin >> row >> col;
    row--;
    col--;
    while (row < 0 || row > 9 || col < 0 || col > 9)
    {
        cout << "Invalid input, please try again (row and column between 1-10):" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> row >> col;
        row--;
        col--;
    }

    if (opponent->grid.getCell(row, col) == 'S')
    {
        opponent->grid.markHit(row, col);
        for (int i = 0; i < 5; i++)
        {
            if ((opponent->grid.getPositions()[i].GetRow() == row) && (opponent->grid.getPositions()[i].GetCol() == col))
            {
                char symbol = opponent->grid.getPositions()[i].GetSymbol();
                if (symbol == 'D')
                {
                    opponent->ships[0]->takeHit();
                    ships[0]->GetName();
                    cout << " has been hit!" << ships[0]->GetHitsTaken() << endl;
                    break;
                }
                else if (symbol == 'c')
                {
                    opponent->ships[1]->takeHit();
                    ships[1]->GetName();
                    cout << " has been hit!" << ships[1]->GetHitsTaken() << endl;
                    break;
                }
                else if (symbol == 's')
                {
                    opponent->ships[2]->takeHit();
                    ships[2]->GetName();
                    cout << " has been hit!" << ships[2]->GetHitsTaken() << endl;
                    break;
                }
                else if (symbol == 'B')
                {
                    opponent->ships[3]->takeHit();
                    ships[3]->GetName();
                    cout << " has been hit!" << ships[3]->GetHitsTaken() << endl;
                    break;
                }
                else if (symbol == 'C')
                {
                    opponent->ships[4]->takeHit();
                    ships[4]->GetName();
                    cout << " has been hit!" << ships[4]->GetHitsTaken() << endl;
                    break;
                }
            }
        }
        cout << "Hit!" << endl;
    }
    else
    {
        opponent->grid.markMiss(row, col);
        cout << "Miss!" << endl;
    }
    opponent->grid.printGrid();
    return;
}
Grid &Player::GetGrid()
{
    return this->grid;
}
Ship *Player::getShip(int i)
{
    if (i >= 0 && i < 5 && ships[i] != nullptr)
    {
        return this->ships[i];
    }
    return nullptr;
}
bool Player ::allShipsSunk() const
{
    for (int i = 0; i < 5; i++)
    {
        if (!ships[i]->isSunk())
        {
            return false;
        }
    }
    return true;
}
void Player::GetName()
{
    cout << this->playerName << endl;
}
Player::~Player()
{
    delete[] this->playerName;
    for (int i = 0; i < 5; i++)
    {
        delete this->ships[i];
    }
}