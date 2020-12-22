#ifndef TICKETSVIEWWINDOW_H
#define TICKETSVIEWWINDOW_H

#include <QDialog>
#include <DataBases.h>
#include <QStandardItemModel>

namespace Ui {
class TicketsViewWindow;
}

/*!
 * \brief Класс окна просмотров билетов
 *
 * Окно позволяет кассирам и администраторам просматривать
 * текущие запросы касательно билетов от пассажиров
 * Ответ на запрос также формируется здесь, с помощью активации
 * выделенного билета из списка в таблице
 */
class TicketsViewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TicketsViewWindow(QWidget *parent = nullptr);
    ~TicketsViewWindow();

    /*!
     * \brief Функция получения указателя на объект взаимодействия с базами данных
     * \param DBPointer Указатель на объект взаимодействия с базами данных
     */
    void giveDBManagerPtr(DataBases *DBPointer);
    /*!
     * \brief Функция получения указателя на список билетов
     * \param sTicketListPtr Указатель на список билетов
     */
    void giveListPtr(QList<Ticket> *sTicketListPtr);
    /*!
     * \brief Функция заполнения таблицы билетов
     * \param def Логический флаг, отвечающий за применение фильтра при заполнении таблицы
     */
    void fillTable(bool def = 1);

private slots:
    /*!
     * \brief Слот ответа на запрос
     *
     * С помощью QModelIndex определяется выделенный объект для дальнейшей работы с ним
     */
    void answerToReq(QModelIndex);
    /*!
     * \brief Слот применения фильтра
     */
    void startFilter(QString);

private:
    //! Функция обновляет список билетов на отображение
    void refreshListPtr();
    /*!
    * \brief Функция определяет статус билета, принимая строковое значение и возвращая целочисленное
    * \param ticketStatus Строкове название статуса билета
    */
    int defineStatus(QString ticketStatus);
    //! Функция вызывает сообщение об успехе
    void gracBox();
    //! Функция вызывает критическое сообщение
    void critBox();
    //! Указатель на объект взаимодействия с базами данных
    DataBases *DBManagerPtr;
    //! Список билетов на отображение
    QList<Ticket> ticketsToShow;
    //! Указатель на список билтов (от главного окна)
    QList<Ticket> *ticketsListPtr;
    QStandardItemModel *table;
    Ui::TicketsViewWindow *ui;
};

#endif // TICKETSVIEWWINDOW_H
