//
// Created by shahar on 28/10/17.
//

#include "Cell.h"

/*
 * constructor.
 */
Cell::Cell() {
    this->eSign = E_S;
}

/**
 * checks if the cell is empty.
 * @return true or false.
 */
bool Cell::isEmpty() {
    if(this->eSign==E_S){
        return true;
    }
    return false;
}

/**
 * return the current player of the specific cell. or the sign of an empty cell.
 * @return the sign.
 */
sign Cell::getSign() const{
    return this->eSign;
}

/**
 * set the cell sign.
 * @param s is sign.
 */
void Cell::setSign(sign s){
    this->eSign = s;
}

/**
 * copy constructor
 * @param c is the object to copy.
 */
Cell::Cell(const Cell &c) {
    this->eSign = c.eSign;
}
