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
    // Проверяет наличие двоичных файлов базы данных
    void checkForBinFiles();

    bool find(string login, string password, User *user);

    void createUserNote(string login, string password, QString fullName, QString passportInfo);
};

#endif // DATABASES_H
