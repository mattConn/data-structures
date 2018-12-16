#include <string>
#include <iostream>

using namespace std;

#ifndef USERINFO_H

class userInfo
{
    string name, password;


public:
    userInfo(); // default constructor
    userInfo(const string &n, const string &pw); // custom constructor

    // getters
    string getName();
    string getPassword();

    // overloaded greater than operator
    bool operator >(const userInfo);
};

// constructors
//=============

// default constructor (leaves data members as empty Strings)
inline userInfo::userInfo(){};

// custom constructor (define data members)
inline userInfo::userInfo(const string &n, const string &pw) : name(n), password(pw){}

// getters
//========

inline string userInfo::getName()
{
    return name;
}

inline string userInfo::getPassword(){
    return password;
};

// overloaded operators
bool userInfo::operator >(const userInfo user)
{
    // names are equal
    if(user.name == name)
        return false;
    else
    {
        // check characters
        //=================

        // get length of shorter string
        int length = name.length() <= user.name.length() ? name.length() : user.name.length();

        // compare character by character
        for(int i = 0; i < length; i++)
            if(tolower(name[i]) > tolower(user.name[i]))
                return true;

        return false;
    }

    return true;
}

#define USERINFO_H

#endif // USERINFO_H
