#include "databases.h"

DataBases::DataBases()
{

}

void DataBases::checkForDir()
{
    QDir dataBasesFolder;
    if(!dataBasesFolder.exists("Data_Bases"))
    {
        dataBasesFolder.mkdir("Data_Bases");
        return;
    }
    else return;
}

void DataBases::checkForBinFiles()
{
    QFile temp;
    if(!temp.exists("Users_Base.bin"))
    {
        QFile usersBase("Data_Bases/Users_Base.bin");
        usersBase.open(QIODevice::WriteOnly);
        usersBase.close();
    }
    if(!temp.exists("Passengers_Base.bin"))
    {
        QFile usersBase("Data_Bases/Passengers_Base.bin");
        usersBase.open(QIODevice::WriteOnly);
        usersBase.close();
    }
    if(!temp.exists("Routes_Base.bin"))
    {
        QFile usersBase("Data_Bases/Routes_Base.bin");
        usersBase.open(QIODevice::WriteOnly);
        usersBase.close();
    }
    if(!temp.exists("Tickets_Base.bin"))
    {
        QFile usersBase("Data_Bases/Tickets_Base.bin");
        usersBase.open(QIODevice::WriteOnly);
        usersBase.close();
    }
}

bool DataBases::find(string login, string password, User *user)
{
    return true;
}

void DataBases::createUserNote(string login, string password, QString fullName, QString passportInfo)
{

}
