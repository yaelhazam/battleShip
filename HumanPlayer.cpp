#include "HumanPlayer.hpp"
#include <iostream>
#include <iomanip>

HumanPlayer::HumanPlayer() : Player("Human Player")
{
    cout << "please enter your name , not longer than 25 notes:" << endl;
    char name[25];
    cin.getline(name, 25);
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input." << endl;
        return;
    }
    delete[] this->playerName;
    this->playerName = new char[strlen(name) + 1];
    strcpy(this->playerName, name);
}

void HumanPlayer::placeAllShips()
{
    Player::placeAllShips();
}

void HumanPlayer::makeMove()
{
    Player::makeMove();
}

HumanPlayer::~HumanPlayer()
{
    delete[] this->playerName;
}