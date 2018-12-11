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

    // program loop - get user input
    while(true)
    {
        // variables receiving user input
        int arrivalDist = 0;
        int expectedServiceTime = 0;
        int simLength = 0;

        // program time
        int programTimer = 0;

        ArrayQueue<Customer> line;

        // Data prompts
        // ============
        cout << "<Ctrl-c to quit.>\n" << endl;

        cout << "Enter distribution of arrival times: " << endl;
        cin >> arrivalDist;

        cout << "Enter expected service time: " << endl;
        cin >> expectedServiceTime;

        cout << "Enter length of simulation: " << endl;
        cin >> simLength;
        //=================
        // End data prompts

        system(CLEAR_SCREEN);

        float arrivalProb = 1/float(arrivalDist);

        Teller teller;

        int totalWaitTime = 0;
        int numCustomers = 0;

        // simulation while loop
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


            // check if teller is free
            if(teller.getTime() == 0)
            {
                if(!line.isEmpty())
                {
                    // add user's wait time to total wait time
                    totalWaitTime += ( programTimer - line.peekFront().getArrivalTime());

                    line.dequeue();

                    teller.setTime(expectedServiceTime);
                }
            }
            else
                teller.decTime();


            programTimer++;
        } // end sim. while loop

        // Display data and results
        //=========================
        printf("Dist. = %d, service time = %d, sim. length = %d\n", arrivalDist, expectedServiceTime, simLength);
        cout << "~~~~~~" << endl;

        cout << "Num. of customers: " << numCustomers << endl;
        cout << "Total wait time: " << totalWaitTime << endl;
        cout << "Avg. wait time: " << float(totalWaitTime)/float(numCustomers == 0 ? 1 : numCustomers)  << endl;

        cout << "~~~~~~" << endl;
        cout << endl;

    } // end program while loop


    return 0;
} // end main

float getRand()
{
    return float(rand( ))/float(RAND_MAX);
}
