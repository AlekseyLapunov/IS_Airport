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

    // Создаёт запись в двоичном файле потока qstream
    static void createUserNote(QString login, QString password, int ID, int type, QDataStream &qstream);

    // Функция находит пользователя в базе данных; возвращает true, если находит
    static bool find(string login, string password, User *user);

    static void refreshBase(QList<User> &pUserList);

    static void loadBase(QList<User> &pUserList);

    static int getLastID();

private:

};

#endif // USERSBASE_H
