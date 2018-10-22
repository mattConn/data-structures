#ifndef Garage_H
#define Garage_H

#include <iostream>
#include "ArrayStack.h"
#include "Car.h"

class Garage
{
    // 2 lanesStack, 3rd lane street
    ArrayStack<Car> lanesStack[3];

public:
    Garage(); //default constructor

    void arrive(Car &c); //push
    void depart(Car &c); //pop
};

#endif // Garage_H

Garage::Garage()
{}

// try to push car
// ===============
void Garage::arrive(Car &c)
{
    int laneAvailable = -1;

    cout << c.getPlate(); // begin message

    // try first lane
    if(lanesStack[0].push(c))
        laneAvailable = 1;

    // try second lane
    if(laneAvailable < 0 && lanesStack[1].push(c))
        laneAvailable = 2;

    // no room in either lane
    if(laneAvailable < 0)
    {
        // end message
        cout << " being turned away. No room in lanes." << endl;
        return;
    }

    // end message
    cout << " arriving in lane " << laneAvailable << "." << endl;
}

// pop car and display car details
// ===============================
void Garage::depart(Car &c)
{
    // index of lane car is in & index of lane cars will be moved to
    int laneIndex = lanesStack[0].search(c) > -1 ? 0 : 1;

    if( lanesStack[laneIndex].search(c) < 0) // if car was not found
    {
        cout << c.getPlate() << " not found in garage." << endl;
        return;
    }

    int otherLaneIndex = -1*(laneIndex-1); // index of lane car is not in
    ArrayStack<int> swapIndexStack; // keep track of location of cars as they are moved
    Car topCar = lanesStack[laneIndex].peek(); // car on top of stack


    // While top car is not desired car
    while( !(topCar == c) )
    {
        // record move
        topCar.incMoves();

        // try to push to other lane; push to street if unsucessful
        if( !(lanesStack[otherLaneIndex].push(topCar)) )
        {
            // push to street and record
            swapIndexStack.push(2); // street index
            lanesStack[2].push(topCar);
        }
        else // pushed to lane; record
            swapIndexStack.push(otherLaneIndex); // other lane

        lanesStack[laneIndex].pop(); // pop car just pushed

        topCar = lanesStack[laneIndex].peek(); // get next car (new top)
    }

    // departure routine: display plate no., number of moves, then pop.
    cout << topCar.getPlate() << " departing from lane " << laneIndex+1 << "."<< endl;
    cout << "\tMoved " << topCar.getMoves() << " times." << endl;
    lanesStack[laneIndex].pop();

    // If no cars needed to be moved back, exit function
    if(swapIndexStack.isEmpty())
        return;

    // Move cars back:
    // Cars may have been moved to street after being moved to other lane.
    while(!swapIndexStack.isEmpty())
    {
        int swp = swapIndexStack.peek(); // index of swap stack (other lane or street)

        lanesStack[laneIndex].push( lanesStack[swp].peek() );// move back to original lane
        lanesStack[swp].pop(); // pop other lane or street
        swapIndexStack.pop(); // pop swapIndexStack
    }

}
