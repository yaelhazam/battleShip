#include <iostream>
using namespace std;
#include "Ship.hpp"

class Carrier : public Ship
{
    public:
        Carrier():Ship("Carrier",5){};
        ~Carrier();

};