#include "Ship.hpp"
Ship::Ship(const char *name, int size){
    this->size = size;
    this->hitsTaken = 0;
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
    delete[] name;
}
Ship::~Ship(){
    delete[] name;
}

