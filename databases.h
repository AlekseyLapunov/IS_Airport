#ifndef DATABASES_H
#define DATABASES_H

#include <user.h>
#include <QDir>
#include <string>
#include <usersbase.h>
#include <passengersbase.h>
#include <routesbase.h>
#include <ticketsbase.h>


class DataBases
{
public:
    DataBases();
    // Проверяет наличие папки базы данных
    void checkForDir();

    bool find(string login, string password, User *user);

private:
    // Создание папки для баз данных
    void makeDir();
    // Папка с базами данных
    QDir dataBasesFolder;

    // База данных пользователей
    UsersBase users;
    // База данных пассажиров
    PassengersBase passengers;
    // База данных рейсов
    RoutesBase routes;
    // База данных билетов
    TicketsBase tickets;
};

#endif // DATABASES_H
