#define SUBMARINE_HPP
#define SUBMARINE_HPP
#include <iostream>
using namespace std;
#include "Ship.hpp"
class Submarine : public Ship
{
private:
public:
    Submarine():Ship("Submarime",3){};
    ~Submarine();
};
