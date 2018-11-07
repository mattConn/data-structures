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

    while(!inFile.eof())
    {
        AddressItem a;
        inFile >> a;
        list.insert(list.getLength()+1,a);
    }
    for(int i = 0; i < list.getLength(); i++)
        cout << list.getEntry(i+1).getAddress() << endl;

    AddressItem a;

    inFile.close();

    return 0;
}
