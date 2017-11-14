//
// Created by shahar on 28/10/17.
//

#ifndef EX2_GAMERULES_H
#define EX2_GAMERULES_H

#include <vector>
#include "Board.h"
#include "generaldefinition.h"
#include "Coordinate.h"
using namespace std;
class GameRules {
protected:
    Board &board;
    vector<Coordinate*> vector1;
    vector<Coordinate*> vector2;
    void freeVector(sign symbol);

public:
    virtual ~GameRules();

public:
    GameRules(Board &board);
    bool isInVector(Coordinate &c,sign symbol)const ;
    virtual vector<Coordinate*> getPossiblesMoves(sign s)  ;
    possibleOutcome makeMove(Coordinate &coor,sign s);
    bool isLegal(int row,int col);
    vector<Coordinate*> &getCurrentVec(sign symbol);

private:
    Coordinate* getCoorInVec(Coordinate &c,vector <Coordinate*> vec);
};


#endif //EX2_GAMERULES_H
