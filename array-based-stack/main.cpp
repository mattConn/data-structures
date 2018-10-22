#include <iostream>
#include <string>
#include <fstream>
#include "Car.h"
#include "garage.h"
#include "ArrayStack.h"

using namespace std;

int main()
{
    // get input.txt
    ifstream inFile;
    inFile.open("input.txt");

    // check if file exists
    if (!inFile)
    {
        cout << "File not found. Exiting." << endl;
        exit(EXIT_FAILURE);
    }

    Garage garage; // create garage object

    string tmp[2];
    Car *tmpCar = nullptr;

    while (inFile >> tmp[0] >> tmp[1])
    {
        tmpCar = new Car(tmp[1]);

        if(tmp[0] == "A")
            garage.arrive(*tmpCar);
        else if(tmp[0] == "D")
            garage.depart(*tmpCar);
        else
            cout << "Invalid instruction <" << tmp[0] << ">. Continuing..." << endl;
    }

    inFile.close();

    delete tmpCar;

    return 0;
}
