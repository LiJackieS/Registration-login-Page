#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstring>
#include "Login.h"

using namespace std;

int main() {
    Login LoginPage;

    string userName;
    string password;
    string confirmPassword;
    int input;
    bool upper = false;
    bool number = false;

    cout << "0 for registeration." << endl;
    cout << "1 for login." << endl;

    cin >> input;

    if (input == 0) {
            cout << "Type in your userName." << endl;
            cin >> userName;
            LoginPage.SetUserName(userName);
            
            cout << "Password must contain at least: \n6 characters, 1 number, and 1 uppercase character" << endl;
            cout << "Type in your password." << endl;

            cin >> password;
            if (password.size() < 6) {
                cout << "Password must contain at least 6 characters" << endl;
                return 1;
            }
            for (int i = 0; i < password.size(); i++) {
                if (isupper(password.at(i))) {
                    upper = true;
                }
                if (isdigit(password.at(i))) {
                    number = true;
                }
            }
            if (upper == false) {
                cout << "Password must contain at least 1 uppercase character" << endl;
                return 1;
            }
            if (number == false) {
                cout << "Password must contain at least 1 number" << endl;
                return 1;
            }
            
            cout << "Type password again to confirm." << endl;
            cin >> confirmPassword;
            try {
                if (password != confirmPassword) {
                    throw runtime_error("Passwords do not match");
                }
            }
                catch (runtime_error &excpt) {
                    cout << "ERROR: "<< excpt.what() << endl;
                    cout << "Please try again" << endl;
                }
            LoginPage.SetPassword(password);
            
            LoginPage.FileStorage(userName, password);
            
    }
    else if (input == 1) {
        cout << "Please enter your userName" << endl;
        cin >> userName;
        cout << "Please enter your password" << endl;
        cin >> password;
        
        LoginPage.Verification(userName, password);
        
    }
    else {
        try {
            throw runtime_error("Invalid Input");
        }
        catch (runtime_error &excpt) {
        cout << "ERROR: " << excpt.what() << endl;
        cout << "Please try again" << endl;
    }
    }
    
    return 0;
}

