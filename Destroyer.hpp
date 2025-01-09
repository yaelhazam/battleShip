#include <iostream>
using namespace std;
#include "Ship.hpp"
class Destroyer:public Ship{
    public:
    Destroyer() : Ship("Destroyer", 2) {};
};