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

bool DataBases::find(string login, string password, User &ptr)
{
    if(UsersBase::find(login, password, ptr)) return true;
    else return false;
}

bool DataBases::find(int id, Passenger &ptr)
{
    if(PassengersBase::find(id, ptr)) return true;
    else return false;
}

bool DataBases::passFound(QString passInfo)
{
    if(PassengersBase::find(passInfo.toStdString())) return true;
    else return false;
}

void DataBases::createAdmin(string sLogin, string sPassword)
{
    UsersBase::loadBase(*pUserList);

    int sID = pUserList->size() + 1;

    User transmitter(sLogin, sPassword, sID, User::idAdministrator);
    pUserList->push_back(transmitter);

    UsersBase::refreshBase(*pUserList);
}

bool DataBases::loginFound(string login)
{
    if(UsersBase::find(login)) return true; else return false;
}

void DataBases::pushUser(string sLogin, string sPassword)
{
    UsersBase::loadBase(*pUserList);

    int sID = pUserList->size() + 1;

    User transmitter(sLogin, sPassword, sID);
    pUserList->push_back(transmitter);

    UsersBase::refreshBase(*pUserList);
}

void DataBases::pushPassenger(QString sFullName, QString sPassportInfo)
{
    PassengersBase::loadBase(*pPassList);

    int sID = pUserList->size();

    sFullName = Passenger::fixFullName(sFullName);

    Passenger transmitter(sFullName, sPassportInfo.toStdString(), sID);
    pPassList->push_back(transmitter);

    PassengersBase::refreshBase(*pPassList);
}

void DataBases::loadAllBase()
{
    UsersBase::loadBase(*pUserList);
    PassengersBase::loadBase(*pPassList);
}

void DataBases::setListPointers(QList<User> *users, QList<Passenger> *passes, QList<Route> *routes, QList<Ticket> *tickets)
{
    pUserList = users;
    pPassList = passes;
    pRoutesList = routes;
    pTicketsList = tickets;
}














