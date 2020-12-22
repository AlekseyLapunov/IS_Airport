#ifndef TICKET_H
#define TICKET_H

#include "QString"

/*!
 * \brief Класс Билета
 *
 * Содержит информацию: ID Рейса, ID Пассажира, Статус
 */
class Ticket
{
private:
    //! ID Рейса
    int routeID;
    //! ID Пассажира
    int passID;
    //! Статус
    int status;
public:
    //! Перечисление ID статусов билета
    enum {stUndef, stReq, stReqAns, stRet, stRetAns};
    //! Функция возвращает ID рейса
    int getRouteID();
    //! Функция возвращает ID пассажира
    int getPassID();
    //! Функция возвращает статус билета
    int getStatus();
    //! Функция возвращает статус билета в строковом виде
    QString getStatusStr();
    Ticket();
    //! Специализированный конструктор
    Ticket(int sRouteID, int sPassID, int sStatus = stReq);
};

#endif // TICKET_H
