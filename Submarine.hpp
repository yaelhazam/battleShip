#define SUBMARINE_HPP
#define SUBMARINE_HPP
#include <iostream>
using namespace std;
#include "Ship.hpp"
class Submarime : public Ship
{
private:
public:
    Submarime():Ship("Submarime",3){};
    ~Submarime();
};
