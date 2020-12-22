#ifndef USER_H
#define USER_H

#include <string>
#include <QString>
using namespace std;

/*!
 * \brief Класс Пользователя
 *
 * Содержит информацию: Логин, Пароль, ID (номер), Тип пользователя
 */
class User
{
protected:
    //! Поле логина
    string login;
    //! Поле пароля
    string password;
    //! Поле ID
    int ID;
    //! Поле типа пользователя
    int type;

public:
    //! Перечисление номеров типов пользователей
    enum {idUndefined, idPassenger, idCashier, idAdministrator};
    //! Функция возвращает ID пользователя
    int getID();
    //! Функция возвращает тип пользователя в целочисленном формате
    int getType();
    //! Функция возвращает тип пользователя в строковом формате, на английском языке
    QString getTypeString();
    //! Функция возвращает тип пользователя в строковом формате, на русском языке
    QString getTypeStringRus();
    //! Функция возвращает логин пользователя
    string getLogin();
    //! Функция возвращает пароль пользователя
    string getPassword();
    /*!
     * \brief Функция изменения пароля и типа пользователя на предлагаемые в аргументах
     * \param password Новый пароль пользователя
     * \param type Новый тип пользователя
     */
    void changeAuthInfo(string password, int type);
    User();
    //! Специализированный конструктор
    User(string sLogin, string sPassword, int sID, int sType = idPassenger);
};

#endif // USER_H
