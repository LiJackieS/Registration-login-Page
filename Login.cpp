#include <iostream>
#include "Login.h"
#include <fstream>

using namespace std;

void Login::SetUserName(string userName) {
    this->userName = userName;
}
void Login::SetPassword(string password) {
    this->password = password;
}
void Login::FileStorage(string userName, string password) {
    ofstream file ("userInfo.txt", ios::app);
    
    if (!file.is_open()) {
        cout << "ERROR: File cannot be opened" << endl;
    }
    else {
        file << userName << " ";
        file << password << endl;
        file.close();
    }
    cout << "Registration is succeessful" << endl;
}
void Login::Verification(string userName, string password) {
    fstream myFile;
    
    string combinationString;
    string data;
    bool boolPassword = false;
    
    combinationString = userName + " " + password;
    
    myFile.open("userInfo.txt");
    
    if (!myFile.is_open()) {
        cout << "ERROR: File cannot be opened" << endl;
    }
    else {
        while(!myFile.eof()) {
            getline(myFile, data);
            if (combinationString == data) {
                boolPassword = true;
                break;
            }
        }
        if (boolPassword == true) {
            cout << "Login successful" << endl;
        }
        else {
            cout << "ERROR: Either the username or password is incorrect please restart the program" << endl;
        }
    }
}

