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

    int numTellers = 2;
    Teller tellers[numTellers];

    int arrivalDist = 5;
    int expectedServiceTime = 6;
    float arrivalProb = 1/float(arrivalDist);
    int simLength = 100;


    int serviceTime = 0;
    int totalWaitTime = 0;
    int numCustomers = 0;

    while(programTimer < simLength)
    {
        // If the random number is between 0 and the arrival probability
        // then a customer arrives, otherwise no customer arrives.
        if(getRand() <= arrivalProb)
        {
            Customer *c = new Customer;

            // count customer
            numCustomers++;

            // set arrival time
            c->setArrivalTime(programTimer);

            line.enqueue(*c);
        }

        if(serviceTime > 0)
            serviceTime--;
        else
            teller.isBusy(false);

        // check if teller is free
        for(int i = 0; i < numTellers; i++)
        {
            if(!tellers[i].isBusy())
            {
                line.dequeue();

                tellers[i].isBusy(true);
                serviceTime = expectedServiceTime;

                totalWaitTime += serviceTime;
            }
        }

        programTimer++;
    }

    // TEST
    cout << "Num. of customers: " << numCustomers << endl;
    cout << "Total wait time: " << totalWaitTime << "\n" << endl;
    cout << "Avg. wait time: " << float(totalWaitTime)/float(numCustomers)  << endl;

    return 0;
}

float getRand()
{
    return float(rand( ))/float(RAND_MAX);
}
