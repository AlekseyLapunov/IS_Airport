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
    static void checkForDir();

    bool find(string login, string password, User &ptr);

    bool loginFound(string login);
    bool passFound(QString passInfo);

    void createAdmin(string sLogin, string sPassword);
    void pushUser(string sLogin, string sPassword);
    void pushPassenger(QString fullName, QString passInfo);

    void loadAllBase();

    void setListPointers(QList<User> *users, QList<Passenger> *passes, QList<Route> *routes, QList<Ticket> *tickets);
private:

    QList<User> *pUserList;
    QList<Passenger> *pPassList;
    QList<Route> *pRoutesList;
    QList<Ticket> *pTicketsList;
};

#endif // DATABASES_H
