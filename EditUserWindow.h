#ifndef EDITUSERWINDOW_H
#define EDITUSERWINDOW_H

#include <QDialog>
#include <User.h>
#include <DataBases.h>

namespace Ui {
class EditUserWindow;
}

/*!
 * \brief Класс окна редактирования информации пользователя
 *
 * Отвечает за изменение информации выбранного пользователя из таблицы
 */
class EditUserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditUserWindow(QWidget *parent = nullptr);
    ~EditUserWindow();
    /*!
     * \brief Функция получения указателя на пользователя ("которого" изменяют)
     * \param user Указатель на пользователя
     */
    void giveUserPtr(User *user);
    /*!
     * \brief Функция получения указателя на текущего пользователя
     * \param curUser Указатель на текущего пользователя
     */
    void giveCurUserPtr(User *curUser);
    /*!
     * \brief Функция получения указателя на объект взаимодействия с базами данных
     * \param db Указатель на объект взаимодействия с базами данных
     */
    void giveDBManagerPtr(DataBases*);
    /*!
     * \brief Функция получения указателя на логическую переменную, сигнализирующую о том, изменился ли пользователь
     * \param boolPtr Указатель на логическую переменную, сигнализирующую о том, изменился ли пользователь
     */
    void giveBoolPtr(bool *boolPtr);
    //! Функция устанавливает поля в окне редактирования по известным из указателя на пользователя данным
    void setFields();

private slots:
    //! Перегруженный слот QDialog::accept(), расширяющий функциональность
    void accept() override;

private:
    //! Функция выдаёт предупреждающее сообщение в том случае, когда пользователь меняет свою же информацию
    void checkWarn();
    //! Функция проверяет поля на правильность заполнения (возвращает true, если всё заполнено правильно)
    bool checkFields();
    //! Функция возвращает true, если изменяется тип пользователя следующим образом: из пассажира делают кассира или администратора
    bool passToOther();
    //! Функция возвращает true, если изменяется тип пользователя следующим образом: из кассира или администратора делают пассажира
    bool otherToPass();
    //! Функция возвращает true, если пользователь изменился
    bool doesUserChange();
    //! Указатель на логическую переменную, сигнализирующую о том, изменился ли пользователь
    bool *userChanged;
    //! Указатель на объект взаимодействия с базами данных
    DataBases *DBManagerPtr;
    //! Указатель на пользователя
    User *userPtr;
    //! Указатель на текущего пользователя
    User *curUserPtr;
    Ui::EditUserWindow *ui;
};

#endif // EDITUSERWINDOW_H
