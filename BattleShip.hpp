#include <iostream>
using namespace std;
#include "Ship.hpp"
class BattleShip : public Ship
{
public:
    BattleShip() : Ship("BattleShip", 4) {};
    ~BattleShip();
};