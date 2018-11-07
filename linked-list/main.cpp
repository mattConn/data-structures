#include <iostream>
#include <fstream>
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
        AddressItem a;
        inFile >> a;
        a.Tally();

        bool dup = false;
        // search for duplicate in list
        if(list.getLength() != 0)
        {
            for(int i = 1; i < list.getLength()+1; i++)
            {
                if(list.getEntry(i) == a)
                {
                    // tally
                    for(int j = 0; j < list.getEntry(i).getCount(); j++)
                        a.Tally();

                    // using replace because getEntry returns a value (deref. nodePtr)
                    list.replace(i,a);
                    dup = true;
                    break;
                }
            }
        }

        // if not a duplicate, insert
        if(!dup)
            list.insert(list.getLength()+1,a);
    }

    // print list
    for(int i = 1; i < list.getLength(); i++)
    {
        cout << list.getEntry(i);
    }

    inFile.close();

    return 0;
}
