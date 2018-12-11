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

        // line of customers
        ArrayQueue<Customer> line;

        // teller to serve customers
        Teller teller;

        cout << "<Ctrl-c to quit.>\n" << endl;

        // Data prompts
        // ============
        cout << "Enter distribution of arrival times: \n> ";
        cin >> arrivalDist;

        cout << "Enter expected service time: \n> ";
        cin >> expectedServiceTime;

        cout << "Enter length of simulation: \n> ";
        cin >> simLength;
        //=================
        // End data prompts

        system(CLEAR_SCREEN);

        // calculate probability of customer arrival
        float arrivalProb = 1/float(arrivalDist);

        // variables updated throughout simulation
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

                // enqueue customer in line
                line.enqueue(*c);
            }


            // check if teller is free
            // by checking their service time
            if(teller.getTime() == 0)
            {
                if(!line.isEmpty()) // make sure line has customers in it
                {
                    // add user's wait time to total wait time
                    totalWaitTime += ( programTimer - line.peekFront().getArrivalTime());

                    line.dequeue();

                    // teller is now servicing customer
                    teller.setTime(expectedServiceTime);
                }
            }
            else
                teller.decTime(); // teller is busy, decrement their time


            programTimer++; // increment simulation clock

        } // end sim. while loop

        // Display data and results
        //=========================

        // display user inputs
        printf("Dist. = %d, service time = %d, sim. length = %d\n", arrivalDist, expectedServiceTime, simLength);
        cout << "~~~~~~" << endl;

        // display simulation results
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
