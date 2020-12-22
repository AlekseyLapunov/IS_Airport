#ifndef USERSBASE_H
#define USERSBASE_H

#include <User.h>
#include <string>
#include <QString>
#include <QList>

/*!
 * \brief Класс базы данных пользователей
 *
 * Обеспечивает взаимодействие с внешней памятью
 * Файл Users_Base.bin
 */
class UsersBase
{
public:
    UsersBase();
    /*!
     * \brief Функция поиска по заданным параметрам
     * \param login Логин пользователя
     * \param password Пароль пользователя
     * \param fUser Найденный пользователь
     */
    static bool find(string login, string password, User &fUser);
    /*!
     * \brief Функция поиска по заданным параметрам
     * \param id ID пользователя
     * \param login Логин пользователя
     * \param fUser Найденный пользователь
     */
    static bool find(int id, string login, User &fUser);
    /*!
     * \brief Функция поиска по заданным параметрам
     * \param login Логин пользователя
     * \param fUser Найденный пользователь
     */
    static bool find(string login, User &fUser);
    /*!
     * \brief Функция поиска заданного логина в базе данных
     * \param login Логин пользователя
     */
    static bool find(string login);
    /*!
     * \brief Функция перезаписи файла БД
     * \param pUserList Ссылка на список пользователей
     */
    static void refreshBase(QList<User> &pUserList);
    /*!
     * \brief Функция загрузки информации из файла БД
     * \param pUserList Ссылка на список пользователей
     */
    static void loadBase(QList<User> &pUserList);

private:
    /*!
     * \brief Функция внесения пользователя в файл БД
     * \param login Логин пользователя
     * \param password Пароль пользователя
     * \param ID Номер пользователя
     * \param type Тип пользователя
     * \param qstream Поток QDataStream для осуществления записи в двоичный файл
     */
    static void createUserNote(QString login, QString password,
                               int ID, int type, QDataStream &qstream);
};

#endif // USERSBASE_H
