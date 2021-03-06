#include <iostream>
#include <string>

using namespace std;

class AddressItem{

public:

    AddressItem ( ) {count = 0;}
    friend istream & operator>>(istream & in, AddressItem & a); //inputs one ip address into a
    friend ostream & operator<<(ostream & out, const AddressItem & a);// outputs ip and count
    void Tally( ); // add one to address item’s count
    string getAddress()const;
    int getCount()const;
    bool operator==(const AddressItem & addr2)const; //compare address values only

private:

    string address;
    int count;

};

// member definitions
//===================

// Tally
void AddressItem::Tally(){count++;};

//getCount
int AddressItem::getCount() const {return count;};

// getAddress
string AddressItem::getAddress() const {return address;};

bool AddressItem::operator==(const AddressItem & addr2) const
{
    return address == addr2.address;
}

// friend definitions
//===================

istream & operator>>(istream & in, AddressItem & a)
{
    in >> a.address;
    return in;
}

ostream & operator<<(ostream & out, const AddressItem & a)
{
    out << a.address << " : " << a.count << endl;
    return out;
}
