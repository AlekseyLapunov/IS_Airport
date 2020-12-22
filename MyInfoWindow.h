#ifndef MYINFOWINDOW_H
#define MYINFOWINDOW_H

#include <QDialog>
#include <DataBases.h>
#include <QStandardItemModel>

namespace Ui {
class MyInfoWindow;
}

/*!
 * \brief Класс окна "Мои данные"
 *
 * Показывает пассажиру все его данные (за исключением пароля и ID)
 */
class MyInfoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MyInfoWindow(QWidget *parent = nullptr);
    ~MyInfoWindow();
    /*!
     * \brief Функция получает указатель на текущего пассажира
     * \param passPtr Указатель на текущего пассажира
     */
    void givePassPtr(Passenger *passPtr);
    /*!
     * \brief Функция получает указатель на список билетов
     * \param ticketsList Указатель на список билетов
     */
    void giveTicketsListPtr(QList<Ticket> *ticketList);
    //! Функция заполняет таблицу запросов текущего пользователя
    void fillTable();

private:
    //! Функция формирует список билетов для выведения его на экран
    void getListToShow();
    //! Список билетов для выведения на экран
    QList<Ticket> ticketsToShow;
    //! Указатель на список билетов (от главного окна)
    QList<Ticket> *ticketsListPtr;
    //! Указатель на текущего пользователя
    Passenger *curPassPtr;
    Ui::MyInfoWindow *ui;
    QStandardItemModel *table;
};

#endif // MYINFOWINDOW_H
