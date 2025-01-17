#ifndef DESTROYER_HPP
#define DESTROYER_HPP
#include <iostream>
#include "Ship.hpp"
class Destroyer:public Ship{
    public:
    Destroyer() : Ship("Destroyer", 2) {};
};

#endif