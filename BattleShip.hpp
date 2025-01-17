#ifndef BATTLESHIP_HPP
#define BATTLESHIP_HPP
#include <iostream>
#include "Ship.hpp"
class BattleShip : public Ship
{
public:
    BattleShip() : Ship("BattleShip", 4) {};
};

#endif