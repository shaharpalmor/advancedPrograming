//
// Created by shahar on 28/10/17.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H
#include "generaldefinition.h"
#include "Coordinate.h"
using namespace std;

class Player{

public:
    char getSymbol();
    virtual Coordinate getMove() = 0 ;
protected:
    char symbol;
};

#endif //EX2_PLAYER_H
