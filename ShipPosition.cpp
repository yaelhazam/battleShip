#include "ShipPosition.hpp"

ShipPosition::ShipPosition()
{
    this->row = 0;
    this->col = 0;
    this->horizontal = false;
    this->symbol = ' ';
    this->isInit = false;
}
void ShipPosition::SetInit() { this->isInit = true; }
bool ShipPosition::GetIsInit() { return this->isInit; }
void ShipPosition::SetCol(int col) { this->col = col; }
void ShipPosition::SetRow(int row) { this->row = row; }
void ShipPosition::SetHorizontal(bool horizontal) { this->horizontal = horizontal; }
void ShipPosition::SetSymbol(char symbol) { this->symbol = symbol; }

ShipPosition::~ShipPosition() {}