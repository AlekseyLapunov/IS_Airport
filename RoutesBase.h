#ifndef ROUTESBASE_H
#define ROUTESBASE_H

#include <QString>
#include <Route.h>
#include <QDataStream>
#include <QList>
#include "QFile"
/*!
 * \brief Класс базы данных рейсов
 *
 * Обеспечивает взаимодействие с внешней памятью
 * Файл Routes_Base.bin
 */
class RoutesBase
{
public:
    RoutesBase();
    /*!
     * \brief Функция поиска по заданным параметрам
     * \param ID Номер рейса
     * \param fDep Пункт отправления
     * \param fDes Пункт назначения
     * \param fMark Марка судна
     * \param fSeats Количество свободных мест
     * \param fRoute Ссылка на найденный рейс
     */
    static bool find(int ID, QString fDep, QString fDes,
                     QString fMark, int fSeats, Route &fRoute);
    /*!
     * \brief Функция поиска по заданным параметрам
     * \param fID Номер рейса
     * \param fRoute Ссылка на найденный рейс
     */
    static bool find(int fID, Route &fRoute);
    /*!
     * \brief Функция перезаписи файла БД
     * \param pRoutesList Ссылка на список рейсов
     */
    static void refreshBase(QList<Route> &pRoutesList);
    /*!
     * \brief Функция загрузки данных из файла БД
     * \param pRoutesList Ссылка на список рейсов
     */
    static void loadBase(QList<Route> &pRoutesList);
private:
    /*!
     * \brief Функция внесения рейса в файл БД
     * \param ID Номер рейса
     * \param dep Пункт отправления
     * \param des Пункт назначения
     * \param mark Марка судна
     * \param seats Количество свободных мест
     * \param qstream Поток QDataStream для осуществления записи в двоичный файл
     */
    static void createRouteNote(int ID, QString dep, QString des,
                                QString mark, int seats, QDataStream &qstream);
};

#endif // ROUTESBASE_H
