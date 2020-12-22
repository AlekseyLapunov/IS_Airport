#ifndef EDITPASSWINDOW_H
#define EDITPASSWINDOW_H

#include <QDialog>
#include <Passenger.h>
#include <DataBases.h>

namespace Ui {
class EditPassWindow;
}
/*!
 * \brief Класс окна редактирования информации пассажира
 *
 * Отвечает за изменение информации выбранного пассажира из таблицы
 */
class EditPassWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditPassWindow(QWidget *parent = nullptr);
    ~EditPassWindow();

    /*!
     * \brief Функция получения указателя на пассажира ("которого" изменяют)
     * \param pass Указатель на пассажира
     */
    void givePassPtr(Passenger *pass);
    /*!
     * \brief Функция получения указателя на объект взаимодействия с базами данных
     * \param db Указатель на объект взаимодействия с базами данных
     */
    void giveDBManagerPtr(DataBases *db);
    /*!
     * \brief Функция получения указателя на логическую переменную, сигнализирующую о том, изменился ли пассажир
     * \param boolPtr Указатель на логическую переменную, сигнализирующую о том, изменился ли пассажир
     */
    void giveBoolPtr(bool *boolPtr);
    //! Функция устанавливает поля в окне редактирования по известным из указателя на пассажира данным
    void setFields();

private slots:
    //! Перегруженный слот QDialog::accept(), расширяющий функциональность
    void accept() override;

private:
    //! Функция проверяет поля на правильность заполнения (возвращает true, если всё заполнено правильно)
    bool checkFields();
    //! Указатель на логическую переменную, сигнализирующую о том, изменился ли пассажир
    bool *passChanged;
    //! Указатель на объект взаимодействия с базами данных
    DataBases *DBManagerPtr;
    //! Указатель на пассажира
    Passenger *passPtr;
    Ui::EditPassWindow *ui;
};

#endif // EDITPASSWINDOW_H
