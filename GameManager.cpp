// Created by Shahar Palmor on 03/11/17.
// ID 307929927

#include "GameManager.h"
#include <vector>
#include <iostream>

using namespace std;

/**
 * constrctor
 * @param board is the board of the game
 * @param printer is the printer that prints all the masseges
 * @param playerA
 * @param playerB
 * @param gameRules is the logic
 */
GameManager::GameManager( Board &board,  Printer &printer,  Player &playerA,  Player &playerB,
                          GameRules &gameRules) : board(board), printer(printer), playerA(playerA),
                                                       playerB(playerB), gameRules(gameRules) ,currentPlayer(){
    this->currentPlayer = &(this->playerA);
    move = NULL;
    firstTurn = true;
}
/**
 * gets the winner of the game or draw if its a tie.
 * @return the end of game result
 */
sign GameManager::getWinner() const {
    int x=0;
    int o=0;
    for(int i = 0;i<this->board.getRow();i++){
        for(int j = 0;j<this->board.getCol();j++) {
            Coordinate c1(i,j);
            if(this->board.getCell(c1).getSign()==E_X){
                x+=1;
            } else if(this->board.getCell(c1).getSign()==E_0){
                o+=1;
            } else{
                continue;
            }
        }
    }
    //x win
    if(x>o) {
        return E_X;
    }//o win
    else if(o>x) {
        return E_0;
    }else{//its a tie
        return E_S;
    }

}
/**
 * checks if the game is still running or should stop
 * @return the status
 */
status GameManager::checkStatus() {
    gameRules.getPossiblesMoves(E_X);
    gameRules.getPossiblesMoves(E_0);
    bool isls1Empty = gameRules.getCurrentVec(E_X).empty();
    bool isls2Empty = gameRules.getCurrentVec(E_0).empty();

    if(this->board.isBoardFull()||(isls1Empty &&isls2Empty)){
        sign result = this->getWinner();
        if(result == E_0){
            return DRAW;
        }
        else{
            return WIN;
        }
    }
    return RUNNIMG;
}

/**
 * plays the game, changes the current player with each turn.
 */
void GameManager::run() {
    status status1 = checkStatus();
    while(status1 == RUNNIMG){
        this->playOneTurn();
        if(currentPlayer == &playerA){
            currentPlayer = &playerB;
        }
        else{
            currentPlayer = &playerA;
        }
        status1 = checkStatus();
    }
    this->printer.printBoard();
    if(status1 == WIN){
        sign player = this->getWinner();
        if(player==E_0) {
            this->printer.printEndOfGame(this->playerB,WIN);
        }else{
            this->printer.printEndOfGame(this->playerA,WIN);
        }
    }else{
        this->printer.printEndOfGame(this->playerB,DRAW);
    }
    delete(move);
}

/**
 * play one turn does all that the current player should do. it offers him the options of playing
 * and updated the board, and call all the sub functions.
 */
void GameManager::playOneTurn() {
    possibleOutcome po;
    char c;
    this->printer.printBoard();
    vector<Coordinate*> vec;
    // checking if the list of the player is empty
    if(this->currentPlayer==&this->playerA){
         vec = this->gameRules.getCurrentVec(E_X);
    }else{
        vec = this->gameRules.getCurrentVec(E_0);
    }
    //in case the player has no moves
    if(vec.empty()){
        this->printer.printNextPlayerMove(*currentPlayer, vec);
        cin >> c;
        if(move!=NULL) {
            delete (move);
        }
        move = NULL;
        return;
    }

    // not the first time playing
    if(!this->firstTurn) {
        if (this->currentPlayer == &this->playerA) {
            this->printer.printLastMove(this->playerB, move);
            if(move!= NULL){
                delete(move);

            }
            this->printer.printNextPlayerMove(this->playerA,vec);
            move  = new Coordinate(this->playerA.getMove());
            po = this->gameRules.makeMove(*move,E_X);

        } else {
            this->printer.printLastMove(this->playerA, move);
            if(move!= NULL){
                delete(move);

            }
            this->printer.printNextPlayerMove(this->playerB,vec);
            move  = new Coordinate(this->playerB.getMove()) ;
            po = this->gameRules.makeMove(*move,E_0);
        }
    } else{
        //first time playing
        this->printer.printNextPlayerMove(this->playerA,vec);
        if(move!=NULL){
            delete(move);
        }
        move = new Coordinate(this->playerA.getMove());
        po = this->gameRules.makeMove(*move, E_X);
        firstTurn = false;
    }
    //according to the outcome print a proper massage
    if (po != SUCCESS) {
        this->getChoiseAgain(po);
    }

}
/**
 * if it was an illegal move it lets the player to choose again
 */
void GameManager:: getChoiseAgain(possibleOutcome outcome){

    sign player;

    if(this->currentPlayer == &playerA){
        player = E_X;
    }
    else{
        player = E_0;
    }

    while(outcome != SUCCESS){
        this->printAppropriateMassage(outcome);
        if(move != NULL){
            delete(move);
            move = new Coordinate(currentPlayer->getMove());
        }
        outcome = this->gameRules.makeMove(*move,player);
    }
}

void GameManager::printAppropriateMassage(possibleOutcome po){
    switch (po) {
        case ILLEGAL_MOVE:
            this->printer.printIllegalMove();
            break;
        case OUT_OF_BOUND:
            this->printer.printOutOfBound();
            break;
        case OCCUPIED_CELL:
            this->printer.printOccupiedCell();
            break;
        default:
            break;
    }
}