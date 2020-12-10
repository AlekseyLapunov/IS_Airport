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

bool DataBases::find(int id, string login, User &ptr)
{
    if(UsersBase::find(id, login, ptr)) return true;
    else return false;
}

bool DataBases::passFound(QString passInfo)
{
    if(PassengersBase::find(passInfo.toStdString())) return true;
    else return false;
}

bool DataBases::changeUserInfo(int cID, string cLogin, string cPassword, int cType)
{
    for(int i = 0; i < (int)pUserList->size(); i++)
    {
        User temp = pUserList->at(i);
        if(temp.getID() == cID && temp.getLogin() == cLogin)
        {
            User changeBy(cLogin, cPassword, cID, cType);
            pUserList->removeAt(i);
            pUserList->insert(i, changeBy);
            UsersBase::refreshBase(*pUserList);
            return true;
        }
    }
    return false;
}

bool DataBases::changePassInfo(int cID, QString cFullName, string cPassport)
{
    for(int i = 0; i < (int)pPassList->size(); i++)
    {
        Passenger temp = pPassList->at(i);
        if(temp.getID() == cID)
        {
            Passenger changeBy(cFullName, cPassport, cID);
            pPassList->removeAt(i);
            pPassList->insert(i, changeBy);
            PassengersBase::refreshBase(*pPassList);
            return true;
        }
    }
    return false;
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














