// Created by Shahar Palmor on 03/11/17.
// ID 307929927

#include <iostream>
#include "ConsolePrinter.h"
#include <sstream>
/**
 * constructor for the console printer
 * @param board is the board to print
 * @param playerA
 * @param playerB
 */
ConsolePrinter::ConsolePrinter(Board &board, Player &playerA, Player &playerB) : board(board), playerA(playerA),
                                                                                 playerB(playerB) {}
/**
 * print the commas
 */
void ConsolePrinter::printTheCommas() const {
    cout << "--";
    // Print commas as separators
    for (int i = 0; i <this->board.getCol() ; i++) {
        cout << "----";
    }
    cout << endl;
}

/**
 *  print each line
 * @param currentRow
 */
void ConsolePrinter::printOneLine(int currentRow) const {

    // Print the number of the row at the start
    cout << currentRow + 1 << '|';


    for (int currentCol = 0; currentCol < this->board.getCol(); currentCol++) {
        Coordinate c (currentRow,currentCol);
        sign s = this->board.getCell(c).getSign();
        if(s == E_X){
            cout << ' ' << this->playerA.getSymbol() << " |";
        } else if (s == E_0){
            cout << ' ' << this->playerB.getSymbol() << " |";
        }else{
            cout << "   |" ;
        }

    }
    cout << endl;
    printTheCommas();
}

/**
 * prints the board
 */
void ConsolePrinter::printBoard()  {
    cout << "Current Board:" << endl;

            // Print the numbers of the columns.
            cout << " |";
            for (int i = 1; i <= this->board.getCol(); i++) {
                cout << ' ' << i << " |";
            }
            cout << endl;

            // Print a line of commas.
            printTheCommas();

            // Print each line of the board.
            for (int i = 0; i < this->board.getRow(); i++)  {
                printOneLine(i);
            }
}

/**
 * prints whose the current player, and print the possebiities if they exsits.
 * @param player is the current player
 * @param vec is the vector of options.
 */
void ConsolePrinter::printNextPlayerMove(Player &player, vector<Coordinate *> vec) {
    cout << player.getSymbol() << ": it's your move" << endl;
    //if the vector is empty it means that the turn should pass to the second player.
    if(vec.size() == 0){
        cout << "No possible moves. Play passes back to the other player. Press any key to continue." << endl;
    }//printing the possible moves
    else{
        cout <<"your possible moves: ";
        for (int i = 0; i < vec.size(); ++i) {
            //converting to string the move
            ostringstream xcoor;
            ostringstream ycoor;
            ycoor << vec.at(i)->getY()+1;
            xcoor << vec.at(i)->getX()+1;
            cout << "(" << xcoor.str() << ","<< ycoor.str() << ") " ;
        }
        cout << endl;
        cout << "Please enter your move row,col: "<<endl;
    }


}

/**
 * the move was out of the bounds of the board
 */
void ConsolePrinter::printOutOfBound() {
    cout << " move out of the bounds of the board, please enter your move row,col: " << endl;
}

/**
 * the move was on occiupied cell
 */
void ConsolePrinter::printOccupiedCell() {
    cout << " this cell is allready occupied, please enter your move row,col: " << endl;
}
/**
 * illegal move
 */
void ConsolePrinter::printIllegalMove() {
    cout << " Illegal move! please enter your move row,col: " << endl;
}


/**
 * prints the winner
 * @param p is the winner
 * @param stat is the status of the game
 */
void ConsolePrinter::printEndOfGame(Player &p, status stat) {
    if(stat == WIN)
    cout << "" <<p.getSymbol() << " won!"<< "press any key to continue"<<endl;
    else if (stat == DRAW){
        cout  << " it a draw!"<< "press any key to continue"<<endl;
    }
}

/**
 * prints who played and what. or if there where no options for the player
 * @param player is the current player
 * @param coor is the coordinate that he played
 */
void ConsolePrinter::printLastMove(Player &player, Coordinate *coor) {

  if(coor == NULL){
      cout << player.getSymbol()<<" didnt played"<<endl;
  }
    else{
      //converting to string the move
      ostringstream xcoor;
      ostringstream ycoor;
      ycoor << coor->getY()+1;
      xcoor << coor->getX()+1;
      cout << player.getSymbol() << " played " << "(" << xcoor.str() << ","<< ycoor.str() << ")" << endl;
  }

}


