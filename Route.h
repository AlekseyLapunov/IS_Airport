#ifndef ROUTE_H
#define ROUTE_H

#include <QString>

/*!
 * \brief Класс Рейса
 *
 * Содержит информацию: ID рейса, п. отправления, п. назначения, марка судна, кол-во свободных мест
 */
class Route
{
private:
    //! ID Рейса
    int ID;
    //! Пункт отправления
    QString departure;
    //! Пункт назначения
    QString destination;
    //! Марка судна
    QString mark;
    //! Количество свободных мест
    int seats;
public:
    Route();
    //! Специализированный конструктор класса
    Route(int sID, QString sDep, QString sDes,
          QString sMark, int sSeats);
    //! Функция возвращает ID рейса
    int getID();
    //! Функция возвращает пункт отправления
    QString getDepart();
    //! Функция возвращает пункт назначения
    QString getDest();
    //! Функция возвращает марку судна
    QString getMark();
    //! Функция возвращает количество свободных мест
    int getSeats();
};

#endif // ROUTE_H
