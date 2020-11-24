#ifndef USERSBASE_H
#define USERSBASE_H

#include <user.h>
#include <string>
#include <QString>

class UsersBase
{
public:
    UsersBase();
    // Создаёт запись в двоичном файле
    static void createUserNote(QString login, QString password, QString fullName, QString passport);
    // Функция находит пользователя в базе данных; возвращает true, если находит
    static bool find(string login, string password, User *user);
};

#endif // USERSBASE_H
