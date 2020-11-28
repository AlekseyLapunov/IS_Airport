#ifndef USERSBASE_H
#define USERSBASE_H

#include <user.h>
#include <string>
#include <QString>
#include <QList>

class UsersBase
{
public:
    UsersBase();
    // Создаёт запись в двоичном файле
    static void createUserNote(QString login, QString password);
    // Функция находит пользователя в базе данных; возвращает true, если находит
    static bool find(string login, string password, User *user);

    static void refreshBase(QList<User> &pUserList);
};

#endif // USERSBASE_H
