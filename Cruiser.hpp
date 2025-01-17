#ifndef CRUISER_HPP
#define CRUISER_HPP
#include <iostream>
#include "Ship.hpp"

class Cruiser : public Ship
{
public:
    Cruiser():Ship("Cruiser",3){};
};

#endif