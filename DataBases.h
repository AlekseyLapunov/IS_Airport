#ifndef DATABASES_H
#define DATABASES_H

#include <User.h>
#include <Passenger.h>
#include <Route.h>
#include <Ticket.h>
#include <QDir>
#include <string>
#include <UsersBase.h>
#include <PassengersBase.h>
#include <RoutesBase.h>
#include <TicketsBase.h>
#include <QList>

/*!
 * \brief Класс объекта взаимодействия с базами данных.
 */
class DataBases
{
public:
    DataBases();
    //! Функция проверяет наличие папки Data_Bases
    static void checkForDir();
    /*!
     * \brief Функция поиска по заданным параметрам.
     * \param login Логин пользователя.
     * \param password Пароль пользователя.
     * \param ptr Указатель, по которому передастся найденный пользователь.
     *
     * Возвращает true в случае успеха.
     */
    bool find(string login, string password, User &ptr);
    /*!
     * \brief Функция поиска по заданным параметрам.
     * \param id ID пользователя/пассажира.
     * \param ptr Указатель, по которому передастся найденный пассажир.
     *
     * Возвращает true в случае успеха.
     */
    bool find(int id, Passenger &ptr);
    /*!
     * \brief Функция поиска по заданным параметрам.
     * \param login Логин пользователя.
     * \param id ID пользователя.
     * \param ptr Указатель, по которому передастся найденный пользователь.
     *
     * Возвращает true в случае успеха.
     */
    bool find(int id, string login, User &ptr);
    /*!
     * \brief Функция поиска по заданным параметрам.
     * \param routeID ID рейса.
     * \param passID ID пассажира.
     * \param status Статус билета
     * \param ptr Указатель, по которому передастся найденный билет
     *
     * Возвращает true в случае успеха.
     */
    bool find(int routeID, int passID, int status, Ticket &ptr);
    /*!
     * \brief Функция поиска по заданным параметрам.
     * \param routeID ID рейса.
     * \param passID ID пассажира.
     * \param ptr Указатель, по которому передастся найденный билет
     *
     * Возвращает true в случае успеха.
     */
    bool find(int routeID, int passID, Ticket &ptr);
    /*!
     * \brief Функция поиска по заданным параметрам.
     * \param ID ID рейса.
     * \param dep Пункт отправления.
     * \param des Пункт назначения
     * \param mark Марка самолёта
     * \param seats Количество свободных мест
     * \param ptr Указатель, по которому передастся найденный рейс
     *
     * Возвращает true в случае успеха.
     */
    bool find(int ID, QString dep, QString des,
              QString mark, int seats, Route &ptr);
    /*!
     * \brief Функция поиска по заданным параметрам.
     * \param ID ID рейса.
     * \param ptr Указатель, по которому передастся найденный рейс
     *
     * Возвращает true в случае успеха.
     */
    bool find(int ID, Route &ptr);
    /*!
     * \brief Функция поиска по заданным параметрам.
     * \param login Логин пользователя.
     * \param ptr Указатель, по которому передастся найденный пользователь
     *
     * Возвращает true в случае успеха.
     */
    bool find(string login, User &ptr);
    /*!
     * \brief Функция специального поиска.
     * \param login Логин пользователя.
     *
     * Возвращает true в случае успеха.
     */
    bool loginFound(string login);
    /*!
     * \brief Функция специального поиска.
     * \param passInfo Паспортные данные пассажира.
     *
     * Возвращает true в случае успеха.
     */
    bool passFound(QString passInfo);
    /*!
     * \brief Функция изменения данных пользователя на те, что подаются в качестве аргументов.
     * \param cID ID пользователя (для определения).
     * \param cLogin Логин пользователя (для определения).
     * \param cPassword Новый пароль пользователя.
     * \param cType Новый тип пользователя.
     *
     * Возвращает true в случае успеха.
     */
    bool changeUserInfo(int cID, string cLogin,
                        string cPassword, int cType);
    /*!
     * \brief Функция изменения данных пассажира на те, что подаются в качестве аргументов.
     * \param cID ID пользователя/пассажира (для определения).
     * \param cFullName Новое ФИО пассажира.
     * \param cPassport Новые данные паспорта пассажира.
     *
     * Возвращает true в случае успеха.
     */
    bool changePassInfo(int cID, QString cFullName,
                        string cPassport);
    /*!
     * \brief Функция создания корневого администратора.
     * \param sLogin Логин администратора (по ум. root).
     * \param sPassword Пароль администратора (по ум. standart#).
     */
    void createAdmin(string sLogin, string sPassword);
    /*!
     * \brief Функция создания пользователя.
     * \param sLogin Логин пользователя.
     * \param sPassword Пароль пользователя.
     */
    void pushUser(string sLogin, string sPassword);
    /*!
     * \brief Функция создания пассажира.
     * \param fullName ФИО пассажира.
     * \param passInfo Паспортные данные пассажира.
     * \param ifDefault Дополнительная логическая переменная, отвечающая за то, будет ли установлен ID пассажира "вручную".
     * \param uID Дополнительная целочисленаня переменная, отвечающая за то, каким будет ID пассажира.
     */
    void pushPassenger(QString fullName, QString passInfo,
                       bool ifDefault = true, int uID = -1);
    /*!
     * \brief Функция создания билета.
     * \param routeID ID рейса.
     * \param passID ID пассажира.
     * \param status Статус билета.
     */
    void pushTicket(int routeID, int passID, int status);
    /*!
     * \brief Функция создания маршрута.
     * \param ID ID рейса.
     * \param dep Пункт отправления.
     * \param des Пункт назначения.
     * \param mark Марка самолёта.
     * \param seats Количество свободных мест.
     */
    void pushRoute(int ID, QString dep, QString des,
                   QString mark, int seats);
    /*!
     * \brief Функция изменения количества свободных мест в рейсе.
     * \param routeID Номер рейса.
     * \param nSeats Значение изменения.
     */
    void changeRouteSeats(int routeID, int nSeats);
    /*!
     * \brief Функция удаления рейса.
     * \param rID Номер рейса для удаления.
     *
     * Возвращает true в случае успеха.
     */
    bool deleteRoute(int rID);
    /*!
     * \brief Функция удаления билета.
     * \param routeID ID рейса.
     * \param passID ID пассажира.
     *
     * Возвращает true в случае успеха.
     */
    bool deleteTicket(int routeID, int passID);
    /*!
     * \brief Функция удаления всей информации касательно определённого пассажира.
     * \param pID ID пассажира.
     */
    void destroyPassAndTickets(int pID);
    /*!
     * \brief Функция загрузки всех данных из баз данных
     */
    void loadAllBase();
    /*!
     * \brief Функция изменения данных билета на те, что указаны в качестве аргументов.
     * \param cRouteID ID рейса.
     * \param cPassID ID пассажира.
     * \param cStatus Новый статус билета.
     *
     * Возвращает true в случае успеха.
     */
    bool changeTicket(int cRouteID, int cPassID, int cStatus);
    /*!
     * \brief Функция установки указателей на текущие списки объектов ИС.
     * \param users Указатель на список пользователей.
     * \param passes Указатель на список пассажиров.
     * \param routes Указатель на список рейсов.
     * \param tickets Указатель на список билетов.
     */
    void setListPointers(QList<User> *users, QList<Passenger> *passes,
                         QList<Route> *routes, QList<Ticket> *tickets);
    /*!
     * \brief Функция установки логина и пароля для текущего пассажира.
     * \param userID ID пользователя/пассажира.
     * \param pass Ссылка на пассажира.
     */
    void setPassData(int userID, Passenger &pass);

private:
    //! Функция создаёт файл-подсказку, рассказывающий о том, как создать корневого администратора.
    static void createHintFile();
    //! Указатель на список пользователей.
    QList<User> *pUserList;
    //! Указатель на список пассажиров.
    QList<Passenger> *pPassList;
    //! Указатель на список рейсов.
    QList<Route> *pRoutesList;
    //! Указатель на список билетов.
    QList<Ticket> *pTicketsList;
};

#endif // DATABASES_H
