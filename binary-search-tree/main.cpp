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

   return 0;
}
