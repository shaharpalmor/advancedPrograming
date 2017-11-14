//
// Created by shahar on 28/10/17.
//

#ifndef EX2_CELL_H
#define EX2_CELL_H


#include "generaldefinition.h"
class Cell {
protected:
    sign eSign;
public:
    Cell();
    Cell(const Cell &c);
    bool isEmpty();
    sign getSign() const;
    void setSign(sign s) ;
};


#endif //EX2_CELL_H
