#ifndef TICKETSBASE_H
#define TICKETSBASE_H

#include <QString>
#include <Ticket.h>
#include <QDataStream>
#include <QList>
#include "QFile"

/*!
 * \brief Класс базы данных билетов
 *
 * Обеспечивает взаимодействие с внешней памятью
 * Файл Tickets_Base.bin
 */
class TicketsBase
{
public:
    TicketsBase();
    /*!
     * \brief Функция поиска по заданным параметрам
     * \param fRouteID Номер рейса
     * \param fPassID Номер пассажира
     * \param fStatus Статус билета
     * \param fTicket Ссылка на найденный билет
     */
    static bool find(int fRouteID, int fPassID,
                     int fStatus, Ticket &fTicket);
    /*!
     * \brief Функция поиска по заданным параметрам
     * \param fRouteID Номер рейса
     * \param fPassID Номер пассажира
     * \param fTicket Ссылка на найденный билет
     */
    static bool find(int fRouteID, int fPassID, Ticket &fTicket);
    /*!
     * \brief Функция перезаписи файла БД
     * \param pTicketList Ссылка на список билетов
     */
    static void refreshBase(QList<Ticket> &pTicketList);
    /*!
     * \brief Функция загрузки данных из файла БД
     * \param pTicketList Ссылка на список билетов
     */
    static void loadBase(QList<Ticket> &pTicketList);
private:
    /*!
     * \brief Функция внесения рейса в файл БД
     * \param routeID Номер рейса
     * \param passID Номер пассажира
     * \param status Статус билета
     * \param qstream Поток QDataStream для осуществления записи в двоичный файл
     */
    static void createTicketNote(int routeID, int passID,
                                 int status, QDataStream &qstream);
};

#endif // TICKETSBASE_H
