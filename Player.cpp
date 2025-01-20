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
    char Symbol = 'S';
    int row = 0;
    int col = 0;
    int direction = 0;

    cout << "this is your grid" << endl;
    this->grid.printGrid();
    cout << "now you will need to place all 5 ships:" << endl;
    cout << "notice that the row and column are 1-10" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "ship - " << i + 1 << " -" << endl;
        ships[i]->GetName();
        cout << "Has size of " << this->ships[i]->GetSize() << " cells" << endl;
        cout << "Please Enter for row and then column:" << endl;
        cin >> row >> col;
        cout << "Enter for horizontal or vertical with 1 for horizontal and 0 for vertical:" << endl;
        cin >> direction;
        while (direction != 0 && direction != 1)
        {
            cout << "Invalid input. Please enter 1 for horizontal and 0 for vertical:" << endl;
            cin >> direction;
        }
        horizontal = (direction == 1) ? true : false;
        row--;
        col--;
        this->grid.placeShip(row, col, this->ships[i]->GetSize(), horizontal, Symbol);
        this->ships[i]->SetRow(row);
        this->ships[i]->SetCol(col);
        this->ships[i]->SetDirection(direction);
        this->grid.printGrid();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // placing the ship in the row  col and direction the user inserted if its in bounds ,no taken already,and valid input and not near
    // other ship by one cell in every direction
}
void Player::makeMove(Player *opponent)
{
    int row;
    int col;
    cout << "please enter row and then column:" << endl;
    cin >> row >> col;
    row--;
    col--;
    while (row < 0 || row > 9 || col < 0 || col > 9 || opponent->grid.getCell(row, col) == 'H' || opponent->grid.getCell(row, col) == 'M')
    {
        cout << "Invalid input, please try again (row and column between 1-10):" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> row >> col;
        row--;
        col--;
    }
    if (opponent->grid.getCell(row, col) == '~')
    {
        opponent->grid.markMiss(row, col);
        cout << "Miss!" << endl;
    }
    else if (opponent->grid.getCell(row, col) == 'S')
    {
        opponent->grid.markHit(row, col);
        cout << "Hit!" << endl;

        for (int i = 0; i < 5; i++)
        {
            int shipSize = opponent->ships[i]->GetSize();
            int dir = opponent->ships[i]->GetDirection();
            int shipRow = opponent->ships[i]->GetRow();
            int shipCol = opponent->ships[i]->GetCol();

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
                opponent->ships[i]->takeHit();
                break;
            }
        }
    }

    cout << "opponents ships state:" << endl;
    cout << "ship 1 hits: " << opponent->ships[0]->GetHitsTaken() << endl;
    cout << "ship 2 hits: " << opponent->ships[1]->GetHitsTaken() << endl;
    cout << "ship 3 hits: " << opponent->ships[2]->GetHitsTaken() << endl;
    cout << "ship 4 hits: " << opponent->ships[3]->GetHitsTaken() << endl;
    cout << "ship 5 hits: " << opponent->ships[4]->GetHitsTaken() << endl;
    return;
}
Grid &Player::GetGrid()
{
    return this->grid;
}
void Player::displayGrid()
{
    this->grid.printGrid();
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