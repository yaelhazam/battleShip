#include <iostream>
using namespace std;
#include "Ship.hpp"
class BattleShip : public Ship
{
public:
    BattleShip():Ship("BattleShit",4){};
    ~BattleShip();
};