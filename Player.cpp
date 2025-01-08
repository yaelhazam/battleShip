#include "Player.hpp"

Player::Player(const char *name)
{
    this->playerName = new char *[strlen(name) + 1];
    strcpy(this->name, name);
    this->grid = new Grid();
}
virtual void Player::placeAllShips()
{
    this->ships = new Ship *[5];
    this->ships[0] = new Destroyer();
    this->ships[1] = new Cruiser();
    this->ships[2] = new Submarine();
    this->ships[3] = new Battleship();
    this->ships[4] = new Carrier();

    int count = 0;
    bool horizontal = false;
    char Symbol = 'S';
    int row = 0;
    int col = 0;

    cout << "this is your grid" << endl;
    this->grid->printGrid();
    cout << "now you will need to place all 5 ships:" << endl;
    cout << "notice that the row and column are 1-10" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Ship" << i + 1 << " is a " << this->ships[i]->getName() << " of size " << this->ships[i]->getSize() << "" << endl;
        cout << "Please Enter for row and then column:" << endl;
        cin >> row >> col;
        cout << "Enter for horizontal or vertical with true or false:" << endl;
        cin >> horizontal;
        row--;
        col--;
        this->grid->placeShip(row, col, this->ships[i]->getSize(), horizontal, Symbol);
    }
    return;
}
virtual void Player:: makeMove(Player *opponent)
{
    cout << "Attacking player " << opponent->getName() << endl;
    cout << "Please Enter for row and then column:" << endl;
    int row;
    int col;
    cin >> row >> col;
    if (row < 0 || row > 9 || col < 0 || col > 9)
    {
        cout << "Out of bounds" << endl;
        while (row < 1 || row > 10 || col < 1 || col > 10)
        {
            cout << "Please Enter for row and then column:" << endl;
            cin >> row >> col;
        }
    }

    row--;
    col--;

    if (opponent->grid->getCell(row, col) == 'S')
    {
        opponent->grid->markHit(row, col);
        cout << "Hit!" << endl;
    }
    else
    {
        opponent->grid->markMiss(row, col);
        cout << "Miss!" << endl;
    }
    this->grid->printGrid();
    opponent->grid->printGrid();
    return;
}

bool Player :: allShipsSunk() const
{
    for (int i = 0; i < 5; i++)
    {
        if (this->ships[i]->!isSunk())
        {
            return false;
        }
    }
    return true;
}

Player::~Player()
{
    delete[] this->playerName;
    delete this->grid;
    for (int i = 0; i < 5; i++)
    {
        delete this->ships[i];
    }
}