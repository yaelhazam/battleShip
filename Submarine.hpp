#ifndef SUBMARINE_HPP
#define SUBMARINE_HPP
#include <iostream>
#include "Ship.hpp"
class Submarine : public Ship
{
private:
public:
    Submarine():Ship("Submarine",3){};
};

#endif