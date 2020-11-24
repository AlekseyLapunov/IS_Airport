#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User
{
protected:
    // Поле логина
    string login;
    // Поле пароля
    string password;
    // Поле уникального идентификатора
    int ID;
    // Поле типа: не изв., пассажир, кассир, администратор
    int type;

public:
    // Перечисление ID
    enum {idUndefined, idPassenger, idCashier, idAdministrator};

    // Функция возвращает ID
    int getID();
    // Функция возвращает логин
    string getLogin();
    // Функция возвращает пароль
    string getPassword();

    // Функция изменяет данные пользователя на передаваемые password и type
    void changeAuthInfo(string password, int type);

    User();
    User(string sLogin, string sPassword, int sID);
};

#endif // USER_H
