using namespace std; 
#include <iostream>
#include "sequence.h"
#include <string>

// print string with border
void printBorder(const string &msg)
{
    cout << msg << endl;
    for (int i = 0; i < msg.size(); i++)
        cout << "=";
    cout << endl;

}

// clear screen
void clearScreen()
{
    for (int i = 0; i < 50; i++)
        cout << endl;
}

// menu/user options display function
template<class T>
void displayMenu(T &seqObj)
{

    printBorder("Integer Sequence Testing Program");
    cout << endl;

    printBorder("Sequence Status:");
    cout << endl;

    // summarize status

    printBorder("Summary:");
    cout << "Full Sequence: ";
    if (seqObj.isFull())
        cout << "TRUE";
    else
        cout << "FALSE";
    cout << endl;


    cout << "Empty Sequence: ";
    if (seqObj.isEmpty())
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;

    cout << endl;
    // end summarize status

    // details
    printBorder("Details:");
    cout << "Capacity: " << seqObj.getCapacity() << endl;
    cout << "No. Spaces Used: " << seqObj.getNumUsed() << endl;
    cout << "No. Spaces Available: " << seqObj.getCapacity() - seqObj.getNumUsed() << endl;
    cout << endl;
    // end details

    // user options
    printBorder("Options:");
    cout << "d - display sequence contents" << endl;
    cout << "p - get position of element" << endl;
    cout << "o - overwrite element" << endl;
    cout << "a - add element" << endl;
    cout << "g - get element" << endl;
    cout << "q - quit" << endl;
    cout << endl;
    // end user options
}

int main()
{
    // initial construction
    sequence<int> s1(5);
    s1.push(3);
    s1.push(5);
    s1.push(9);

    // User response types: character and integer
    char cResponse = '\0';
    int iResponse = 0;

    // interactive menu loop (exited via return)
    while (true)
    {
        clearScreen();
        displayMenu(s1);

        // user response parsing
        switch (cResponse)
        {

        // display sequence
        // ================
        case 'd':
            int i;
            cout << "Sequence = [";
            for (i = 0; i < s1.getNumUsed()-1; i++)
            {
                cout << s1.getByPos(i + 1) << ", ";
            }
            cout << s1.getByPos(i + 1) << "]";
            cout << endl;
            break;

            // get position of element
            // =======================
        case 'p':
            cout << "Enter element to get its position. \n> ";
            cin >> iResponse;

            int position;
            position = s1.getPos(iResponse);

            clearScreen();
            displayMenu(s1);

            // check if out of bounds
            if (position > 0)
                cout << "Element: " << iResponse << " Position: " << position << endl;
            else
                cout << "Element " << iResponse << " not found." << endl;

            break;

            // overwrite/replace element
            // =========================
        case 'o':
            int p, e; // position and new element

            cout << "Enter position of element to overwrite. \n> ";
            cin >> p;

            // check if out of range
            if( p < 1 || p > s1.getNumUsed() )
            {
                clearScreen();
                displayMenu(s1);
                cout << "Position is out of range." << endl;
                break;
            }

            clearScreen();
            displayMenu(s1);

            cout << "Enter value of new element to write to position " << p << ". \n> ";
            cin >> e;

            s1.replaceByPos(p,e);

            clearScreen();
            displayMenu(s1);

            cout << "Done." << endl;
            break;

            // add new element
            // ===============
        case 'a':
            clearScreen();
            displayMenu(s1);

            cout << "Enter value of element to add to sequence. \n> ";
            cin >> iResponse;
            s1.push(iResponse);

            clearScreen();
            displayMenu(s1);

            cout << "Done." << endl;

            break;

            // get element by position
            // =======================
        case 'g':
            cout << "Enter position of element. \n> ";
            cin >> iResponse;

            clearScreen();
            displayMenu(s1);

            // check if out of range
            if(iResponse < 1 || iResponse > s1.getNumUsed())
            {
                cout << "Position out of range." << endl;
                break;
            }
            else
            {
                cout << "Element at position " << iResponse << ": " << s1.getByPos(iResponse) << endl;
            }

            break;

            // quit
            // ====
        case 'q':
            clearScreen();
            cout << "Goodbye." << endl;
            return 0;
            break;

        default:
            cout << "Enter an option from the list." << endl;
        }


        // prompt
        cout << "> ";
        cin >> cResponse;
    }
    /* For Windows OS */
    //system("pause");

    return 0;
    //end main
}
