#ifndef USERSBASE_H
#define USERSBASE_H

#include <user.h>
#include <string>

class UsersBase
{
public:
    UsersBase();
    // Функция находит пользователя в базе данных; возвращает true, если находит
    bool find(string login, string password, User *user);
};

#endif // USERSBASE_H
