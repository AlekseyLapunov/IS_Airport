#ifndef PASSENGERSBASE_H
#define PASSENGERSBASE_H

#include <Passenger.h>
#include <QList>
#include <QDataStream>

/*!
 * \brief Класс базы данных пассажиров
 *
 * Обеспечивает взаимодействие с внешней памятью
 * Файл Passengers_Base.bin
 */
class PassengersBase
{
public:
    PassengersBase();
    /*!
     * \brief Функция поиска по заданным параметрам
     * \param fullName ФИО пассажира.
     * \param passport Паспортные данные пассажира.
     * \param fPassenger Ссылка на найденного пассажира.
     */
    static bool find(QString fullName, QString passport, Passenger &fPassenger);
    /*!
     * \brief Функция поиска по заданным параметрам
     * \param id ID Пассажира
     * \param ptr Ссылка на найденного пассажира.
     */
    static bool find(int id, Passenger &ptr);
    /*!
     * \brief Функция нахождения комбинации серии и номера паспорта
     * \param passportCombination Серия номер паспорта
     */
    static bool find(string passportCombination);
    /*!
     * \brief Функция перезаписи файла БД
     * \param pPassList Ссылка на список пользователей
     */
    static void refreshBase(QList<Passenger> &pPassList);
    /*!
     * \brief Функция загрузки данных из файла БД
     * \param pPassList Ссылка на список пассажиров
     */
    static void loadBase(QList<Passenger> &pPassList);

private:
    /*!
     * \brief Функция внесения пассажира в файл БД
     * \param fullName ФИО пассажира.
     * \param passport Паспортные данные пассажира.
     * \param ID ID Пассажира
     * \param qstream Поток QDataStream для осуществления записи в двоичный файл
     */
    static void createPassNote(QString fullName, QString passport,
                               int ID, QDataStream &qstream);
};

#endif // PASSENGERSBASE_H
