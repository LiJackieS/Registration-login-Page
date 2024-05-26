#ifndef LOGIN_H
#define LOGIN_H
using namespace std;

class Login {
    public:
        void SetUserName(string userName);
        void SetPassword(string password);
        string GetUserName();
        string GetPassword();

        void FileStorage(string userName, string password);
        void Verification(string username, string password);

    private:
        string userName;
        string password;
};

#endif