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

    cout << "Reading users list..." << endl;
    while(inFile >> userName >> userPassword)
    {
        userInfo *user = new userInfo(userName, userPassword);

        users.insert(*user);
    }
    cout << "Done reading users list." << endl;
    cout << endl;

    //=========================
    // end file reading routine

    // user input while loop
    //======================
    while(true)
    {
        cout << "<Type QUIT to quit and see all users.>" << endl;
        cout << endl;

        // get input, check for quit command
        cout << "Username: ";
        cin >> userName;

        if(userName == "QUIT")
            break;

        cout << "Password: ";
        cin >> userPassword;

        if(userPassword == "QUIT")
            break;

        // search for user
        userInfo *user = new userInfo(userName, userPassword);

        if(users.search(*user)) // if correct credentials
            cout << "\tUsername and password are correct." << endl;
        else
            cout << "\tUsername or password was incorrect." << endl;
        cout << endl;

    }

    // display all users
    cout << "\nUsernames and passwords:\n" << endl;
    users.inorder(cout);

    return 0;
}
