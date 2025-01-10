
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
    int ShipPosition::GetRow();
    int ShipPosition::GetCol();
    bool ShipPosition::GetHorizontal();
    char ShipPosition::GetSymbol();
    void SetInit();
    bool GetIsInit();
    void SetCol(int col);
    void SetHorizontal(bool horizontal);
    void SetSymbol(char symbol);
    ~ShipPosition();
};
#
