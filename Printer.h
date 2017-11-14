// Created by Shahar Palmor on 03/11/17.
// ID 307929927

#ifndef EX2_PRINTER_H
#define EX2_PRINTER_H


#include "Board.h"
#include "Player.h"
#include <vector>
#include "generaldefinition.h"
/**
 * class that prints the masseges of the game
 */
class Printer {
public:
    virtual void printBoard() =0;
    virtual void printNextPlayerMove(Player &player,vector <Coordinate*> vec) =0 ;
    virtual void printLastMove(Player &player,Coordinate *coor)=0;
    virtual void printOutOfBound() =0;
    virtual void printOccupiedCell()=0;
    virtual void printIllegalMove()=0;
    virtual void printEndOfGame(Player &p, status stat)=0;

};


#endif //EX2_PRINTER_H
