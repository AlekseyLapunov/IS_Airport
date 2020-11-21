#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User
{
private:
    // Логин
    string login;
    // Пароль
    string password;
    // Уникальный идентификатор
    int ID;
    // Тип: не изв., пассажир, кассир, администратор
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
    // Функция изменяет данные пользователя
    void changeAuthInfo(string password, int type);

    User();

};

#endif // USER_H
