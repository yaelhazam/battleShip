#ifndef SHIPPOSITION_HPP
#define SHIPPOSITION_HPP

class ShipPosition
{
private:
   int row = 0;
    int col = 0;
    bool horizontal = false;
    char symbol = ' ';
    bool isInit = false;

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
    ~ShipPosition() = default;
};

#endif
