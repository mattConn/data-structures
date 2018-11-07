#include <iostream>
#include <fstream>
#include <iomanip>
#include "addressItem.h"
#include "LinkedList.h"

using namespace std;


int main()
{
    fstream inFile;
    inFile.open("addresses.txt");

    LinkedList<AddressItem> list;

    // copy addresses to list
    while(!inFile.eof())
    {
        // store address, tally address
        AddressItem a;
        inFile >> a;
        a.Tally();

        bool dup = false; // flag for duplicate entries

        // search for duplicate in list
        if(list.getLength() != 0)
        {
            for(int i = 1; i < list.getLength()+1; i++)
            {
                if(list.getEntry(i) == a) // duplicate found
                {
                    // tally (copy count of existing address)
                    for(int j = 0; j < list.getEntry(i).getCount(); j++)
                        a.Tally();

                    // replace existing address with current address (save count)
                    // note: using replace because getEntry returns a value (deref. nodePtr)
                    list.replace(i,a);
                    dup = true; // set duplicate flag
                    break; // exit for loop
                }
            }
        }

        // if not a duplicate, insert (new entry)
        if(!dup)
            list.insert(list.getLength()+1,a);
    }

    // list header for display
    string printHeader = "IP Address : Occurrences"; // string obj. for length
    cout << printHeader << endl;
    cout << string(printHeader.length(),'=') << endl; // using string length here

    // print list
    for(int i = 1; i < list.getLength(); i++)
        cout << list.getEntry(i);

    inFile.close();

    return 0;
}
