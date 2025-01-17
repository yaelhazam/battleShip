#include "ShipPosition.hpp"

ShipPosition::ShipPosition() {}
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
