// Created by Shahar Palmor on 03/11/17.
// ID 307929927

#include "TwoPlayersGame.h"
#include <iostream>
using namespace std;
/**
 * c'tor
 * @param board is the board of the game
 */
TwoPlayersGame::TwoPlayersGame(Board &board) : GameRules(board) {

}

/**
 * checks for the possible moves of the current player.
 * @param s is the symbol of the player.
 * @return a vector that includes all the options.
 */
vector<Coordinate*> TwoPlayersGame :: getPossiblesMoves(sign s){
    this->freeVector(s);
    for (int i = 0; i <this->board.getRow() ; ++i) {
        for (int j = 0; j <this->board.getCol() ; ++j) {
            Coordinate c (i,j);
            if (this->board.getCell(c).getSign()==s){
                checksurround(c,s);
            }
        }
    }
   if(s == E_X){
       return this->vector1;
   }
    else if(s == E_0){
       return vector2;
   }
}


/**
 * checks the surrounding of the cell and where it is possible to step forward.
 * @param coor is a corrdinate that holds the current player.
 * @param symbol is the symbol of the current player.
 */
void TwoPlayersGame::checksurround(Coordinate coor,sign symbol)  {
    int rowAbove = coor.getX() - 1;
    int rowBelow = coor.getX() + 1;
    int colRight = coor.getY() + 1;
    int colLeft = coor.getY() - 1;

    Coordinate c1(coor.getX(),colLeft);
    if (board.isInBoard(c1.getX(), c1.getY())) {
        Cell lmid = this->board.getCell(c1);
        //left middle
        if((lmid.getSign()!=symbol)&&(lmid.getSign()!=E_S)){
            Coordinate c11(coor.getX(),colLeft);
            while((lmid.getSign()!=E_S)&&(lmid.getSign()!=symbol)&&(this->board.isInBoard(c11.getX(), c11.getY()))){
                c11.setY(c11.getY() - 1);
                if (board.isInBoard(c11.getX(), c11.getY())){
                    lmid = this->board.getCell(c11);
                }

            }
            lastCheck(lmid,c11.getX(),c11.getY(),0,1,symbol);
        }
    }

    Coordinate c2(rowAbove,colLeft);
    if (board.isInBoard(c2.getX(), c2.getY())) {
        Cell lup = this->board.getCell(c2);
        //left up
        if((lup.getSign()!=symbol)&&(lup.getSign()!=E_S)){
            Coordinate c22(rowAbove,colLeft);

            while((lup.getSign()!=E_S)&&(lup.getSign()!=symbol)&&(this->board.isInBoard(c22.getX(), c22.getY()))){
                c22.setX(c22.getX() - 1);
                c22.setY(c22.getY() - 1);
                if (board.isInBoard(c22.getX(), c22.getY())) {
                    lup = this->board.getCell(c22);
                }
            }
            lastCheck(lup,c22.getX(), c22.getY(),1,1,symbol);
        }
    }

    Coordinate c3(rowBelow,colLeft);
    if (board.isInBoard(c3.getX(), c3.getY())) {
        Cell ldown = this->board.getCell(c3);
        //left down
        if((ldown.getSign()!=symbol)&&(ldown.getSign()!=E_S)){
            Coordinate c33(rowBelow,colLeft);
            while((ldown.getSign()!=E_S)&&(ldown.getSign()!=symbol)&&(this->board.isInBoard(c33.getX(), c33.getY()))){
                c33.setX(c33.getX() + 1);
                c33.setY(c33.getY() - 1);
                if (board.isInBoard(c33.getX(), c33.getY())){
                    ldown = this->board.getCell(c33);
                }

            }lastCheck(ldown ,c33.getX(), c33.getY(),-1,1,symbol);
        }
    }


    Coordinate c4(rowAbove,coor.getY());
    if (board.isInBoard(c4.getX(), c4.getY())) {
        Cell midup = this->board.getCell(c4);
        //mid up
        if((midup.getSign()!=symbol)&&(midup.getSign()!=E_S)){
            Coordinate c44(rowAbove,coor.getY());
            while((midup.getSign()!=E_S)&&(midup.getSign()!=symbol)&&(this->board.isInBoard(c44.getX(), c44.getY()))){
                c44.setX(c44.getX() - 1);
                if (board.isInBoard(c44.getX(), c44.getY())) {
                    midup = this->board.getCell(c44);
                }
            }
            lastCheck(midup,c44.getX(), c44.getY(),1,0,symbol);
        }
    }

    Coordinate c5(rowBelow,coor.getY());
    if (board.isInBoard(c5.getX(), c5.getY())) {
        Cell midown = this->board.getCell(c5);
        //mid down
        if((midown.getSign()!=symbol)&&(midown.getSign()!=E_S)){
            Coordinate c55(rowBelow,coor.getY());
            while((midown.getSign()!=E_S)&&(midown.getSign()!=symbol)&&(this->board.isInBoard(c55.getX(), c55.getY()))){
                c55.setX(c55.getX() + 1);
                if (board.isInBoard(c55.getX(), c55.getY())){
                    midown = this->board.getCell(c55);
                }

            }
            lastCheck(midown,c55.getX(), c55.getY(),-1,0,symbol);
        }
    }


    Coordinate c6(coor.getX(),colRight);
    if (board.isInBoard(c6.getX(), c6.getY())) {
        Cell rmid = this->board.getCell(c6);
        //right middle
        if((rmid.getSign()!=symbol)&&(rmid.getSign()!=E_S)){
            Coordinate c66(coor.getX(),colRight);
            while((rmid.getSign()!=E_S)&&(rmid.getSign()!=symbol)&&(this->board.isInBoard(c66.getX(), c66.getY()))){
                c66.setY(c66.getY() + 1);
                if (board.isInBoard(c66.getX(), c66.getY())){
                    rmid = this->board.getCell(c66);
                }

            }
            lastCheck(rmid,c66.getX(), c66.getY(),0,-1,symbol);
        }
    }


    Coordinate c7(rowAbove,colRight);
    if (board.isInBoard(c7.getX(), c7.getY())) {
        Cell rup = this->board.getCell(c7);
        //right up
        if((rup.getSign()!=symbol)&&(rup.getSign()!=E_S)){
            Coordinate c77(rowAbove,colRight);
            while((rup.getSign()!=E_S)&&(rup.getSign()!=symbol)&&(this->board.isInBoard(c77.getX(), c77.getY()))){
                c77.setY(c77.getY() + 1);
                c77.setX(c77.getX() - 1);

                if (board.isInBoard(c77.getX(), c77.getY())) {
                    rup = this->board.getCell(c77);
                }
            }
            lastCheck(rup,c77.getX(), c77.getY(),1,-1,symbol);
        }
    }


    Coordinate c8(rowBelow,colRight);
    if (board.isInBoard(c8.getX(), c8.getY())) {
        Cell rdown = this->board.getCell(c8);
        //right down
        if((rdown.getSign()!=symbol)&&(rdown.getSign()!=E_S)){
            Coordinate c88(rowBelow,colRight);
            while((rdown.getSign()!=E_S)&&(rdown.getSign()!=symbol)&&(this->board.isInBoard(c88.getX(), c88.getY()))){
                c88.setY(c88.getY() + 1);
                c88.setX(c88.getX() + 1);

                if (board.isInBoard(c88.getX(), c88.getY())) {
                    rdown = this->board.getCell(c88);
                }
            }
            lastCheck(rdown,c88.getX(), c88.getY(),-1,-1,symbol);
        }
    }

}

/**
 * adds the option to the vector after checking lat conditions.
 * @param c is the optinal cell.
 * @param dirX is the xcoor
 * @param dirY is the ycoor
 * @param xPath
 * @param yPath
 */
void TwoPlayersGame::lastCheck(Cell c,int dirX, int dirY,int xPath,int yPath,sign s) {

    if((c.getSign()==E_S)&&(this->board.isInBoard(dirX,dirY))){
        Coordinate c (dirX, dirY);
        bool sw = this->isInVector(c,s);
        if(!sw) {
            Coordinate *coor = new Coordinate(c);
            Coordinate *directions = new Coordinate(xPath,yPath);
            coor->insertDirection(directions);
            if(s == E_X){
                this->vector1.push_back(coor);
            }else if(s ==E_0){
                this->vector2.push_back(coor);
            }

        }
    }
}
