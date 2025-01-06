#include "Grid.hpp"
Grid::Grid(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cells[i][j] = '~';
        }
    }
}
Grid::~Grid(){
    delete[] cells;
}