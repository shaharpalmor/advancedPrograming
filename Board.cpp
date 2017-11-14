//
// Created by shahar on 28/10/17.
//

#include "Board.h"
/**
 * constructor
 * @param row is the number of rows
 * @param col is the number of columns
 */
Board::Board(int row=8, int col = 8) {
    this->row = row;
    this->col = col;

    this->matrix = new Cell*[row];
    for (int k = 0; k < row; ++k) {
        this->matrix[k] = new Cell[col];
    }
    this->initBoard();
}

/**
 * d'tor
 */
Board::~Board() {

    for (int k = 0; k < row; ++k) {
        delete(this->matrix[k]);
    }
    delete this->matrix;
}

/**
 * copy constructor.
 * @param board  is the board object.
 */
Board::Board(const Board &board) {
    this->row = board.getRow();
    this->col = board.getCol();
    this->matrix = new Cell *[this->row];
    for (int k = 0; k < row; ++k) {
        this->matrix[k] = new Cell[col];
    }
    //copy the cells
    for(int i = 0;i<this->row;i++){
        for (int j = 0; j < this->col; ++j) {
            Coordinate c(i,j);
            this->matrix[i][j] = Cell(board.getCell(c));
        }
        }
}
/**
 * a function that initializes the board.
 */
void Board::initBoard() {
    for(int i = 0;i<this->row;i++){
        for (int j = 0; j < this->col; ++j) {
            this->matrix[i][j].setSign(E_S);
        }
    }

    // initializing the board
    this->matrix[(row/2)-1][(col/2)-1].setSign(E_0);
    this->matrix[(row/2)-1][(col/2)].setSign(E_X);
    this->matrix[(row/2)][(col/2)].setSign(E_0);
    this->matrix[(row/2)][(col/2)-1].setSign(E_X);
}

/**
 * mark the cell with a specific player
 * @param row
 * @param col
 * @param s is the sign of the current player.
 */
void Board::markCell(int row, int col,sign s) {
    matrix[row][col].setSign(s);
}
/**
 * checks if the cell is empty.
 * @param row
 * @param col
 * @return true or false.
 */
bool Board::isCellEmpty(int row, int col)const {
    if(matrix[row][col].isEmpty()==true){
        return true;
    }
    return false;
}
/**
 * checks if all the board is full of players signs.
 * @return true or false.
 */
bool Board::isBoardFull()const {
    int numOfCells = (this->col)*(this->row);
    int counter = 0;
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            if((matrix[i][j].getSign() != E_S)){
                counter++;
            }
        }
    }
    if(counter == numOfCells){
        return true;
    }
    return false;
}
bool Board::isInBoard(int xCoor,int yCoor)const {
    if((xCoor >= 0)&&(xCoor < this->row)&&(yCoor >= 0)&&(yCoor<this->col)){
        return true;
    }
    return false;
}

/**
 * return a specific cell in the board
 * @param c is the coordinate in the board to check.
 * @return the cell.
 */
Cell Board::getCell(Coordinate &c) const {
    return this->matrix[c.getX()][c.getY()];
}

/**
 *
 * @return the numbers of rows in the board.
 */
int Board::getRow() const {
    return this->row;
}
/**
 *
 * @return the numbers of rows in the board.
 */
int Board::getCol() const {
    return this->col;
}






