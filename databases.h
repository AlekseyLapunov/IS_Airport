#ifndef DATABASES_H
#define DATABASES_H

#include <user.h>
#include <passenger.h>
#include <route.h>
#include <ticket.h>
#include <QDir>
#include <string>
#include <usersbase.h>
#include <passengersbase.h>
#include <routesbase.h>
#include <ticketsbase.h>
#include <QList>

class DataBases
{
public:
    DataBases();
    // Проверяет наличие папки базы данных
    void checkForDir();
    // Проверяет наличие двоичных файлов баз данных
    void checkForBinFiles();

    bool find(string login, string password, User *user);

    void refreshUsersBase(QString login, QString password);
    void refreshPassengersBase(QString fullName, QString passport);

private:
    QList<User> UsersList;
    QList<Passenger> PassengerList;
    QList<Ticket> TicketsList;
    QList<Route> RoutesList;
};

#endif // DATABASES_H
