#include <iostream>


#include "Player.h"
#include "HumanPlayer.h"
#include "GameManager.h"
#include "TwoPlayersGame.h"
#include "ConsolePrinter.h"

using namespace std;

/**
 * main function. create all the objects of the game. and starts the game.
 * @return
 */
int main() {
    Board board(4,4);
    TwoPlayersGame reversiTwoPlayers(board);
    HumanPlayer xPlayer('x');
    HumanPlayer oPlayer('o');
    ConsolePrinter printer(board,xPlayer,oPlayer);
    GameManager game(board,printer,xPlayer,oPlayer,reversiTwoPlayers);

    game.run();

    return 0;
}