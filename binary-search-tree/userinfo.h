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

    // overloaded operators
    //=====================
    bool operator >(const userInfo &user) const;
    bool operator <(const userInfo &user) const;
    bool operator ==(const userInfo &user) const;
    friend ostream & operator <<(ostream &out, const userInfo &user);
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
//=====================

bool userInfo::operator >(const userInfo &user) const
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
        {
            //            if(name[i] != user.name[i] && name[i] > user.name[i])
            if(name[i] != user.name[i])
            {
                if(name[i] > user.name[i])
                    return true;
                else
                    return false;
            }
        }

    }

    return false;
}

bool userInfo::operator <(const userInfo &user) const
{
    if(user > *this)
        return true;

    return false;
}

bool userInfo::operator ==(const userInfo &user) const
{
    if(name == user.name && password == user.password)
        return true;

    return false;
}

ostream & operator <<(ostream &out, const userInfo &user)
{
    out << user.name << ", " << user.password << endl;
    return out;
}

#define USERINFO_H

#endif // USERINFO_H
