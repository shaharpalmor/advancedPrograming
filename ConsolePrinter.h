// Created by Shahar Palmor on 03/11/17.
// ID 307929927

#ifndef EX2_CONSOLEPRINTER_H
#define EX2_CONSOLEPRINTER_H


#include "Board.h"
#include "Printer.h"
using namespace std;

class ConsolePrinter: public Printer{
public:
    //ConsolePrinter(Board &board,Player &pA,Player &pB);

    ConsolePrinter(Board &board, Player &playerA, Player &playerB);


    virtual void printBoard() ;
    virtual void printNextPlayerMove(Player &player,vector <Coordinate*> vec);
    virtual void printLastMove(Player &player,Coordinate *coor);
    virtual void printOutOfBound();
    virtual void printOccupiedCell();
    virtual void printIllegalMove();
    virtual void printEndOfGame(Player &p, status stat);
    //functions of the console.
    void printTheCommas() const;
    void printOneLine(int currentRow) const;

protected:
    Board &board;
    Player &playerA;
    Player &playerB;

};


#endif //EX2_CONSOLEPRINTER_H
