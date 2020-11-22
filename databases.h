#ifndef DATABASES_H
#define DATABASES_H

#include <user.h>
#include <QDir>
#include <string>

class DataBases
{
public:
    DataBases();
    // Проверяет наличие папки базы данных
    void checkForDir();
    // Функция находит пользователя в базе данных; возвращает true, если находит
    bool findUser(string login, string password, User *user);
private:
    void makeDir();
    QDir dataBasesFolder;
};

#endif // DATABASES_H
