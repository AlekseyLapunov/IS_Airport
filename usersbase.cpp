#include "usersbase.h"
#include "QFile"
#include "QDataStream"

UsersBase::UsersBase()
{

}

void UsersBase::createUserNote(QString login, QString password, int lastID, int type, QDataStream &qstream)
{
    qstream << login << password << lastID << type;
}

int UsersBase::getLastID()
{
    int lastID = -1;
    QFile usersBase("Data_Bases/Users_Base.bin");
    if(usersBase.open(QIODevice::ReadOnly))
    {
        QDataStream qstream(&usersBase);
        qstream >> lastID;
        return lastID;
    }
    else
    return -1;
}

void UsersBase::refreshBase(QList<User> &pUserList)
{
    QFile usersBase("Data_Bases/Users_Base.bin");
    if(usersBase.open(QIODevice::WriteOnly))
    {
        QDataStream qstream(&usersBase);
        for(int i = 0; i < pUserList.size(); i++)
        {
            int lastID = pUserList[i].getID();
            if(lastID != -1)
            {
                QString login = QString::fromStdString(pUserList[i].getLogin());
                QString password = QString::fromStdString(pUserList[i].getPassword());
                createUserNote(login, password, lastID + 1, User::idPassenger, qstream);
            }
        }
        usersBase.close();
    }
}

void UsersBase::loadBase(QList<User> &pUserList)
{
    QFile usersBase("Data_Bases/Users_Base.bin");
    if(usersBase.open(QIODevice::ReadOnly))
    {
        QDataStream qstream(&usersBase);
        while(!qstream.atEnd())
        {
            int id, type; QString login; QString password;
            qstream >> login >> password >> id >> type;
            User transmitter(login.toStdString(), password.toStdString(), id, type);
            pUserList.push_back(transmitter);
        }
        usersBase.close();
    }
}










