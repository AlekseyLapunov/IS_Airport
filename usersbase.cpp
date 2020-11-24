#include "usersbase.h"
#include "QFile"
#include "QDataStream"

UsersBase::UsersBase()
{

}

void UsersBase::createUserNote(QString login, QString password, QString fullName, QString passport)
{
    QFile usersBase("Data_Bases/Users_Base.bin");
    if(usersBase.open(QIODevice::WriteOnly))
    {
        QDataStream qstream(&usersBase);
        qstream << login << password << fullName << passport;
    }

    usersBase.close();
}
