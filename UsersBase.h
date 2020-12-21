#ifndef USERSBASE_H
#define USERSBASE_H

#include <User.h>
#include <string>
#include <QString>
#include <QList>

class UsersBase
{
public:
    UsersBase();
    static bool find(string login, string password, User &fUser);
    static bool find(int id, string login, User &fUser);
    static bool find(string login, User &fUser);
    static bool find(string login);
    static void refreshBase(QList<User> &pUserList);
    static void loadBase(QList<User> &pUserList);

private:
    static void createUserNote(QString login, QString password,
                               int ID, int type, QDataStream &qstream);
};

#endif // USERSBASE_H
