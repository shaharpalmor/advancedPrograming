// Created by Shahar Palmor on 03/11/17.
// ID 307929927

#ifndef EX2_GAMEMANAGER_H
#define EX2_GAMEMANAGER_H


#include "Board.h"
#include "Printer.h"
#include "GameRules.h"

class GameManager {
public:
    GameManager( Board &board,  Printer &printer,  Player &playerA,  Player &playerB,
                 GameRules &gameRules);

    void run();
private:
    Board &board;
    Printer &printer;
    Player &playerA;
    Player &playerB;
    GameRules &gameRules;
    Player *currentPlayer;
    Coordinate *move;
    bool firstTurn;
    void getChoiseAgain(possibleOutcome po);
    sign getWinner()const;
    status checkStatus();
    void playOneTurn();
    void printAppropriateMassage(possibleOutcome po);
};


#endif //EX2_GAMEMANAGER_H
