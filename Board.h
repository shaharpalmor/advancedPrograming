//
// Created by shahar on 28/10/17.
//

#ifndef EX2_BOARD_H
#define EX2_BOARD_H

#include "Cell.h"
#include "generaldefinition.h"
#include "Coordinate.h"

class Board {
private:
    int row;
    int col;
    Cell** matrix;
public:
    Board(int row,int col);
    Board(const Board &board);
    ~Board();
    void initBoard();
    int getRow()const ;
    int getCol()const ;
    void markCell(int row, int col,sign s);
    bool isCellEmpty(int row, int col)const ;
    bool isBoardFull()const ;
    bool isInBoard(int row,int col)const ;
    Cell getCell(Coordinate &c)const ;


};


#endif //EX2_BOARD_H
