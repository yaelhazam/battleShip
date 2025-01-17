#include "Player.hpp"
#include <iostream>
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
        cout << "ship -" << endl;
        ships[i]->GetName();
        cout << " has zise of " << this->ships[i]->GetSize() << "" << endl;
        cout << "Please Enter for row and then column:" << endl;
        cin >> row >> col;
        cout << "Enter for horizontal or vertical with true or false:" << endl;
        cin >> horizontal;
        row--;
        col--;
        this->grid.placeShip(row, col, this->ships[i]->GetSize(), horizontal, Symbol);
    }
}
void Player::makeMove(Player *opponent)
{
    cout << "Invalid input. Row and column must be between 1 and 10. Please try again:" << endl;
    int row;
    int col;
    cin >> row >> col;
    if (row < 1 || row > 10 || col < 1 || col > 10)
    {
        cout << "Out of bounds" << endl;
        while (row < 1 || row > 10 || col < 1 || col > 10)
        {
            cout << "Invalid input. Row and column must be between 1 and 10. Please try again:" << endl;
            cin >> row >> col;
        }
    }

    row--;
    col--;

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
                    break;
                }
                else if (symbol == 'c')
                {
                    opponent->ships[1]->takeHit();
                    break;
                }
                else if (symbol == 's')
                {
                    opponent->ships[2]->takeHit();
                    break;
                }
                else if (symbol == 'B')
                {
                    opponent->ships[3]->takeHit();
                    break;
                }
                else if (symbol == 'C')
                {
                    opponent->ships[4]->takeHit();
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
    this->grid.printGrid();
    opponent->grid.printGrid();
    return;
}
Grid& Player::GetGrid()
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
        if (!(this->ships[i]->isSunk()))
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