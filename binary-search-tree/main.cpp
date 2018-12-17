#include <iostream>
#include <fstream>
#include <string>

#include "BST.h"
#include "userinfo.h"

using namespace std;



int main()
{

    // user tree
    BST<userInfo> users;

    // file reading routine
    //=====================

    fstream inFile;

    inFile.open("./users.txt");
    if(!inFile)
    {
        cout << "File not found." << endl;
        return 0;
    }

    // temp strings to receive fstream
    string userName, userPassword;

    while(inFile >> userName >> userPassword)
    {
        userInfo *user = new userInfo(userName, userPassword);

        users.insert(*user);
    }

    //=========================
    // end file reading routine

    cout << "TEST" << endl;
    // user input while loop
    bool looping = true;
    while(looping)
    {
        cout << "\n<Ctrl-c to quit.>\n" << endl;

        cout << "Username: ";
        cin >> userName;

        cout << "Password: ";
        cin >> userPassword;

        userInfo *user = new userInfo(userName, userPassword);

        if(users.search(*user)) // if correct credentials
            cout << "\tUsername and password are correct." << endl;
        else
            cout << "\tUsername or password was incorrect." << endl;

    }

    //    users.inorder(cout);

    return 0;
}
