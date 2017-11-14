//
// Created by shahar on 28/10/17.
//

#include <iostream>
#include <limits>
#include "HumanPlayer.h"
#include "Player.h"
using namespace std;



/**
 * get the move to be done from the player.
 *  i took  the code from the piazza.
 * @return the coordinate that represents the movethat the player wants to do.
 */
Coordinate HumanPlayer::getMove() {
    int num1;
    int num2;
    while (true) {
        cout << "Enter a number: ";
        cin >> num1 >> num2;

        if (!cin.fail()) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            return Coordinate(num1-1, num2-1);
            //return num;
        }

        // user didn't input a number
        cout << "Please enter numbers only." << endl;
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    }
}
/**
 * constructor
 * @param s is the sign of the player
 */
HumanPlayer::HumanPlayer(char s) {
    this->symbol = s;
}


