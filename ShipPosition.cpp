#include "ShipPosition.hpp"

ShipPosition::ShipPosition()
{
    this->row = 0;
    this->col = 0;
    this->horizontal = false;
    this->symbol = ' ';
    this->isInit = false;
}
bool ShipPosition::GetIsInit() { return this->isInit; }
int ShipPosition::GetRow() { return this->row; }
int ShipPosition::GetCol() { return this->col; }
bool ShipPosition::GetHorizontal() { return this->horizontal; }
char ShipPosition::GetSymbol() { return this->symbol; }
void ShipPosition::SetInit() { this->isInit = true; }

void ShipPosition::SetCol(int col) { this->col = col; }
void ShipPosition::SetRow(int row) { this->row = row; }
void ShipPosition::SetHorizontal(bool horizontal) { this->horizontal = horizontal; }
void ShipPosition::SetSymbol(char symbol) { this->symbol = symbol; }

ShipPosition::~ShipPosition() {}