#ifndef USER_H
#define USER_H

#include <string>
#include <QString>
using namespace std;

class User
{
protected:
    string login;
    string password;
    int ID;
    int type;

public:
    enum {idUndefined, idPassenger, idCashier, idAdministrator};
    int getID();
    int getType();
    QString getTypeString();
    QString getTypeStringRus();
    string getLogin();
    string getPassword();
    void changeAuthInfo(string password, int type);
    User();
    User(string sLogin, string sPassword, int sID, int sType = idPassenger);
};

#endif // USER_H
