#include <iostream>
#include <cstdlib>
#include "person-customer-teller.h"
#include "ArrayQueue.h"

using namespace std;

float getRand();

int main()
{
    // seed random number generator
    srand(time(NULL));

    // program time
    int programTimer = 0;

    Teller teller;
    ArrayQueue<Customer> line;

    // TO BE INPUT
    //============

    // no. of tellers
    // dist. of arrival
    // expected service time
    // length of sim.

    int arrivalDist = 5;
    int expectedServiceTime = 6;
    float arrivalProb = 1/float(arrivalDist);
    int simLength = 100;


    while(programTimer < simLength)
    {
        // If the random number is between 0 and the arrival probability
        // then a customer arrives, otherwise no customer arrives.
        if(getRand() <= arrivalProb)
        {
            Customer *c = new Customer;

            // set arrival time
            c->setArrivalTime(programTimer);

            line.enqueue(*c);
        }

        programTimer++;
    }

    return 0;
}

float getRand()
{
    return float(rand( ))/float(RAND_MAX);
}
