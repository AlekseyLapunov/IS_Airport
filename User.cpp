#include "User.h"

// Конструктор
User::User()
{
    login = "Login_Undefined";
    password = "Password_Undefined";
    type = idUndefined;
    ID = -1;
    return;
}

User::User(string sLogin, string sPassword, int sID, int sType)
{
    login = sLogin;
    password = sPassword;
    ID = sID;
    type = sType;
    return;
}

int User::getID()
{
    return this->ID;
}

int User::getType()
{
    return this->type;
}

QString User::getTypeString()
{
    if(this->type == idPassenger) return "Passenger";
    if(this->type == idCashier) return "Cashier";
    if(this->type == idAdministrator) return "Administrator";
    return "Undefined";
}

string User::getLogin()
{
    return this->login;
}

string User::getPassword()
{
    return this->password;
}

void User::changeAuthInfo(string password, int type)
{
    this->password = password;
    this->type = type;
}




