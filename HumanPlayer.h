//
// Created by shahar on 28/10/17.
//

#ifndef EX2_HUMANPLAYER_H
#define EX2_HUMANPLAYER_H

#include "Player.h"
/**
 * human player class
 */
class HumanPlayer:public Player{
public:
    HumanPlayer(char s);
    HumanPlayer();
    virtual Coordinate getMove();

};
#endif //EX2_HUMANPLAYER_H
