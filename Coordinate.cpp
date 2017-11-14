//
// Created by shahar on 28/10/17.
//

#include "Coordinate.h"
/**
 * constructor
 * @param xCoor
 * @param yCoor
 */
Coordinate::Coordinate(int xCoor,int yCoor):x(xCoor),y(yCoor){

}

/**
 * returns the x coordinate
 * @return returns the x coordinate
 */
int Coordinate::getX() {
    return this->x;
}
/**
 * returns the y coordinate
 * @return returns the x coordinate
 */
int Coordinate::getY() {
    return this->y;
}

/**
 * compare two coordinates
 * @param c is the other coordinate
 * @return true or false
 */
bool Coordinate::isEqual(Coordinate &c) const {
    if((this->x == c.getX()) && (this->y == c.getY())){
        return true;
    }
    return false;
}

/**
 * insert a direction for a specific cell in the board that explains how to move
 * in order to mark cells.
 * @param dir is the direction coordinate.
 */
void Coordinate::insertDirection(Coordinate *dir) {
    this->directions.push_back(dir);
}

/**
 * d'tor.
 */
Coordinate::~Coordinate() {
    for (int i = this->directions.size()-1; i >=0 ; i--) {
        delete(this->directions.at(i));
    }
    this->directions.clear();

}

/**
 * gives the directions
 * @return the list of directions.
 */
const vector<Coordinate *> &Coordinate::getDirections() const {
    return directions;
}

/**
 * set x coor
 * @param x
 */
void Coordinate::setX(int x) {
    Coordinate::x = x;
}

/**
 * set y coor
 * @param y
 */
void Coordinate::setY(int y) {
    Coordinate::y = y;
}

/**
 * copy c'tor.
 * @param coor
 */
Coordinate::Coordinate(const Coordinate &coor) {
    this->x = coor.x;
    this->y = coor.y;
    for (int i = 0; i <coor.getDirections().size(); ++i) {
        directions.push_back(coor.getDirections().at(i)) ;
    }
}

/**
 * operator to compae two coordinate objects.
 * @param coor is the specific coordinate to compare.
 * @return the object that was assigned.
 */
Coordinate &Coordinate::operator=(const Coordinate &coor) {
    if(this != &coor){
        delete(this);
        x = coor.x;
        y = coor.y;
        for (int i = 0; i <coor.getDirections().size(); ++i) {
            directions.push_back(coor.getDirections().at(i)) ;
        }
    }
    // if its the same object
    return *this;
}




