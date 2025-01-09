#include <iostream>
using namespace std;
#include "Ship.hpp"

class Cruiser : public Ship
{
private:
public:
    Cruiser():Ship("Cruiser",3){};
    ~Cruiser();
};