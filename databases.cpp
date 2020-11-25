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

void DataBases::pushUser()
{

    DataBases::refreshUsersBase();
}

void DataBases::pushPassenger()
{

    DataBases::refreshPassengersBase();
}

void DataBases::refreshUsersBase()
{

}

void DataBases::refreshPassengersBase()
{

}

void DataBases::setListPointers(QList<User> &users, QList<Passenger> &passes, QList<Route> &routes, QList<Ticket> &tickets)
{
    pUserList = &users;
    pPassList = &passes;
    pRoutesList = &routes;
    pTicketsList = &tickets;
}












