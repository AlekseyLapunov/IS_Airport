#ifndef TICKETREQUESTWINDOW_H
#define TICKETREQUESTWINDOW_H

#include <QDialog>
#include <DataBases.h>

namespace Ui {
class TicketRequestWindow;
}

/*!
 * \brief Класс окна запроса билета
 *
 * Обеспечивает возможность заказа билета пассажиром
 */
class TicketRequestWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TicketRequestWindow(QWidget *parent = nullptr);
    ~TicketRequestWindow();
    /*!
     * \brief Функция получения указателя на объект взаимодействия с базами данных
     * \param DBPtr Указатель на объект взаимодействия с базами данных
     */
    void giveDBManagePtr(DataBases *DBPtr);
    /*!
     * \brief Функция получения указателя на пользователя
     * \param userPtr Указатель на пользователя
     */
    void giveUserPtr(User *userPtr);

private slots:
    //! Слот создания запроса билета
    void doRequest();

private:
    //! Перечисление флагов: режимы добавить, изменить
    enum {push, change};
    //! Перечисление флагов: режимы возврат, запрос, удаление
    enum {ret, req, del};
    //! Функция создаёт запрос для покупки билета
    void ticketToBuy(int);
    //! Функция создаёт запрос для возврата билета
    void ticketToReturn();
    //! Функция создаёт запрос для удаления билета
    void ticketToDelete();
    //! Функция вызывает предупреждающее сообщение о нехватке свободных мест
    void warnBoxSeats();
    //! Функция вызывает предупреждающее сообщение
    void warnBox();
    //! Функция вызывает сообщение об успехе
    void gracBox(int);
    //! Указатель на объект взаимодействия с базами данных
    DataBases *DBManagePtr;
    //! Указатель на текущего пользователя
    User *curUserPtr;
    //! Билет
    Ticket ticket;
    //! Рейс
    Route route;
    Ui::TicketRequestWindow *ui;
};

#endif // TICKETREQUESTWINDOW_H
