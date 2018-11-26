#include <iostream>
#include <cstdlib>
#include "person-customer-teller.h"
#include "ArrayQueue.h"

using namespace std;

float getRand();

int main()
{
    // program time
    int programTimer = 0;

    Teller teller;
    ArrayQueue<Customer> line;
    int arrivalDist = 5;
    int expectedServiceTime = 6;

    while(programTimer < 100)
    {
        Customer *c = new Customer;

        // set arrival time
        c->setArrivalTime(programTimer);

        line.enqueue(*c);

        programTimer++;
    }

    return 0;
}

float getRand()
{
    return float(rand( ))/float(RAND_MAX);
}
