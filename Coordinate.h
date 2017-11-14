//
// Created by shahar on 28/10/17.
//

#ifndef EX2_COORDINATE_H
#define EX2_COORDINATE_H
#include <vector>
using namespace std;
class Coordinate {

public:
    Coordinate(int x,int y);
    Coordinate(const Coordinate &coor);
    virtual ~Coordinate();
    int getX();
    int getY();
    bool isEqual(Coordinate &c)const;
    void setX(int x);
    void setY(int y);
    Coordinate& operator = (const Coordinate& coor);
    void insertDirection(Coordinate * dir);
    const vector<Coordinate *> &getDirections() const;

private:
    int x;
    int y;
    vector <Coordinate*> directions;

};


#endif //EX2_COORDINATE_H
