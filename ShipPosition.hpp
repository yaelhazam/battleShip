#ifndef SHIPPOSITION_HPP
#define SHIPPOSITION_HPP
#include "Ship.hpp"
class ShipPosition
{
private:
    int row;
    int col;
    bool horizontal;
    char symbol;
    bool isInit;

public:
    ShipPosition();
    void SetRow(int row);
    int GetRow();
    int GetCol();
    bool GetHorizontal();
    char GetSymbol();
    void SetInit();
    bool GetIsInit();
    void SetCol(int col);
    void SetHorizontal(bool horizontal);
    void SetSymbol(char symbol);
    ~ShipPosition();
};

#endif
