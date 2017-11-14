//
// Created by shahar on 28/10/17.
//

#include "GameRules.h"
using namespace std;

/**
 * constructor.
 * @param board is the board
 */
GameRules::GameRules(Board &board):board(board) {
}

/**
 * checks if the values of the coordinate are proper for the board.
 * @param row is the row of the coordinate
 * @param col is the col of the coordinate
 * @return true or false
 */
bool GameRules::isLegal(int row, int col) {
    if(this->board.isInBoard(row,col)){
        return true;
    }
    return false;
}

/**
 * checks if a specific coordinate is allready in the vector.
 * @param c is the coordinate
 * @param symbol is the player sign
 * @return the answer if it true.
 */
bool GameRules::isInVector(Coordinate &c,sign symbol) const {

    if(symbol==E_X){
        for (int i = 0; i <this->vector1.size() ; ++i) {
            if(c.isEqual(*(this->vector1.at(i)))){
                return true;
            }
        }
    }else if(symbol==E_0){
        for (int i = 0; i <this->vector2.size() ; ++i) {
            if(c.isEqual(*(this->vector2.at(i)))){
                return true;
            }
        }
    }
    return false;
}

/**
 * free the vector of option according to the player
 * @param symbol is the player symbol
 */
void GameRules::freeVector(sign symbol){
    if(symbol==E_X){
        for (int i = 0; i < this->vector1.size() ; i++) {
            delete(this->vector1.at(i));
        }
        vector1.clear();
    }
    else if(symbol==E_0) {
        for (int i = 0; i < this->vector2.size() ; i++) {
            delete(this->vector2.at(i));
        }
        vector2.clear();
    }

}
/**
 * makes a legal move according to some conditions and updates the cells of
 * the board according to the players move
 * @param coor is the coordinate of the cell to mark.
 * @param s is the sign to be assigned to the cells of the board
 * @return if the mark successeded or else.
 */
possibleOutcome GameRules::makeMove(Coordinate &coor, sign s) {

    vector<Coordinate*> vec;
    if(!this->board.isInBoard(coor.getX(),coor.getY())){
        return OUT_OF_BOUND;
    }
    if(!this->board.isCellEmpty(coor.getX(),coor.getY())){
        return OCCUPIED_CELL;
    }
    //not in the options
    if(!this->isInVector(coor,s)){
        return ILLEGAL_MOVE;
    }

    if(s==E_0){
        vec = vector2;
    }
    else if (s==E_X){
        vec = vector1;

    }
    // a legal cell to mark
    this->board.markCell(coor.getX(),coor.getY(),s);
    vector<Coordinate*> directions = getCoorInVec(coor,vec)->getDirections();


    for (int i = 0; i <directions.size() ; ++i) {

        int dRow = directions[i]->getX();
        int dCol = directions[i]->getY();
        Coordinate c(coor.getX() + dRow ,coor.getY() + dCol);

        while(this->board.isInBoard(c.getX(), c.getY()) && this->board.getCell(c).getSign()!=s){
            this->board.markCell(c.getX(),c.getY(),s);
            c.setX(c.getX()+dRow);
            c.setY(c.getY()+dCol);

        }
    }

    return SUCCESS;
}
/**
 * checks if a specific coordinate is in the vector of options
 * @param c is the coordinate
 * @param vec is the vector
 * @return the pointer to the option
 */
Coordinate* GameRules::getCoorInVec(Coordinate &c,vector <Coordinate*> vec) {
        for (int i = 0; i < vec.size(); ++i) {
            if(vec.at(i)->isEqual(c)) {
                return vec.at(i);
            }
        }

}
/**
 * gets the possible moves of the current player.
 * @param s is the sign of the current player
 * @return the options
 */
vector<Coordinate *> GameRules::getPossiblesMoves(sign s) {
    return vector<Coordinate *>();
}
/**
 * d'tor
 */
GameRules::~GameRules() {
    for (int i = 0; i <vector1.size() ; ++i) {
        delete(vector1.at(i));
    }
    vector1.clear();
    for (int j = 0; j <vector2.size() ; ++j) {
        delete(vector2.at(j));
    }
    vector2.clear();
}
/**
 * gets the cuurent vector of the current player.
 * @param symbol is the player symbol
 * @return the vector
 */
vector<Coordinate *> &GameRules::getCurrentVec(sign symbol) {
    if(symbol == E_X){
        return vector1;
    }
    else if(symbol == E_0){
        return vector2;
    }
}
