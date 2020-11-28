#include "usersbase.h"
#include "QFile"
#include "QDataStream"

UsersBase::UsersBase()
{

}

void UsersBase::createUserNote(QString login, QString password)
{
    QFile usersBase("Data_Bases/Users_Base.bin");
    if(usersBase.open(QIODevice::WriteOnly))
    {
        QDataStream qstream(&usersBase);
        qstream << login << password;
    }

    usersBase.close();
}

void UsersBase::refreshBase(QList<User> &pUserList)
{
    for(int i = 0; i < pUserList.size(); i++)
    {
        QString login = QString::fromStdString(pUserList[i].getLogin());
        QString password = QString::fromStdString(pUserList[i].getPassword());
        createUserNote(login, password);
    }
}
