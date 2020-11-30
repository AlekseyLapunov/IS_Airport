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

bool DataBases::find(string login, string password, User *user)
{
    return true;
}

bool DataBases::passFound(QString passInfo)
{
    return 0;
}

bool DataBases::loginFound(string login)
{
    return 0;
}

void DataBases::pushUser(string sLogin, string sPassword)
{
    UsersBase::loadBase(*pUserList);

    int sID = UsersBase::getLastID();

    User transmitter(sLogin, sPassword, sID);
    pUserList->push_back(transmitter);

    UsersBase::refreshBase(*pUserList);
}

void DataBases::pushPassenger(QString sFullName, QString sPassportInfo)
{
    //PassengersBase::loadBase(*pPassList);

    Passenger transmitter(sFullName, sPassportInfo.toStdString());
    pPassList->push_back(transmitter);

    PassengersBase::refreshBase(*pPassList);
}

void DataBases::loadAllBase()
{
    UsersBase::loadBase(*pUserList);
}

void DataBases::setListPointers(QList<User> *users, QList<Passenger> *passes, QList<Route> *routes, QList<Ticket> *tickets)
{
    pUserList = users;
    pPassList = passes;
    pRoutesList = routes;
    pTicketsList = tickets;
}














