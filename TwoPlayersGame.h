// Created by Shahar Palmor on 03/11/17.
// ID 307929927

#ifndef EX2_TWOPLAYERSGAME_H
#define EX2_TWOPLAYERSGAME_H


#include "GameRules.h"
/**
 * two human players logic
 */
class TwoPlayersGame : public GameRules {
public:
    TwoPlayersGame(Board &board);
    virtual vector<Coordinate*> getPossiblesMoves(sign s);
    void lastCheck(Cell c,int dirX, int dirY,int xPath,int yPath,sign s);
    void checksurround(Coordinate coor,sign symbol);

};


#endif //EX2_TWOPLAYERSGAME_H
