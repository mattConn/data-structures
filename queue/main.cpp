#include <iostream>
#include <cstdlib>
#include "person-customer-teller.h"
#include "ArrayQueue.h"

#ifdef WIN32 // Windows
#define CLEAR_SCREEN "cls"
#else // Linux, Mac
#define CLEAR_SCREEN "clear"
#endif

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

    while(true)
    {
        int numTellers = 0;
        int arrivalDist = 0;
        int expectedServiceTime = 0;
        int simLength = 0;

        // Data prompts
        // ============
        cout << "<Ctrl-c to quit.>\n" << endl;
        cout << "Enter no. of tellers: " << endl;
        cin >> numTellers;
        cout << "Enter distribution of arrival times: " << endl;
        cin >> arrivalDist;
        cout << "Enter expected service time: " << endl;
        cin >> expectedServiceTime;
        cout << "Enter length of simulation: " << endl;
        cin >> simLength;

        system(CLEAR_SCREEN);

        float arrivalProb = 1/float(arrivalDist);

        Teller tellers[numTellers];

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
        } // end sim. while loop

        // Display data and results
        printf("Tellers = %d, Dist. = %d, service time = %d, sim. length = %d\n",numTellers, arrivalDist, expectedServiceTime, simLength);
        cout << "~~~~~~" << endl;

        cout << "Num. of customers: " << numCustomers << endl;
        cout << "Total wait time: " << totalWaitTime << endl;
        cout << "Avg. wait time: " << float(totalWaitTime)/float(numCustomers == 0 ? 1 : numCustomers)  << endl;
        cout << "~~~~~~" << endl;
        cout << endl;

    } // end program while loop


    return 0;
}

float getRand()
{
    return float(rand( ))/float(RAND_MAX);
}
