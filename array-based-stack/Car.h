#ifndef Car_H
#define Car_H

#include <string>

#include <iostream>

using namespace std;

class Car
{
    string plateNo;
    int moves;

public:
    Car(); //default
    Car(const string &num); // custom plate no. constructor

    void incMoves(); // increment car moves
    int getMoves(); // no. of times car has been moved
    string getPlate(); // get plate number
    void setPlate(const string &plate); // set plate number

    // car comparison
    bool operator==(const Car &c);
};

Car::Car(): moves(0), plateNo("00000") {}; //default constructor
Car::Car(const string &num): moves(0), plateNo(num){}; // custom constructor

int Car::getMoves(){ return moves; }

void Car::incMoves(){ moves++; }

string Car::getPlate(){ return plateNo; }

void Car::setPlate(const string &plate){ plateNo = plate; }

bool Car::operator==(const Car &c)
{
   if(plateNo == c.plateNo)
       return true;

    return false;
}

#endif
