#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <DataBases.h>
#include <User.h>

namespace Ui {
class AuthWindow;
}
/*!
 * \brief Класс окна авторизации.
 *
 * Отвечает за вход пользователя в систему
 */
class AuthWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AuthWindow(QWidget *parent = nullptr);
    ~AuthWindow();
    /*!
     * \brief Получение флага закрытия окна.
     * \param flag Ссылка на логическую переменную, ответственную за то, закрылось ли окно авторизации.
    */
    void giveFlag(bool &flag);
    /*!
     * \brief Получение ссылки на пользователя.
     * \param user Ссылка на пользователя, для того, чтобы после авторизации определить текущего пользователя.
    */
    void giveUserPtr(User &user);
    /*!
     * \brief Получение ссылки на пассажира.
     * \param pass Ссылка на пассажира, для того, чтобы после авторизации определить текущего пассажира.
    */
    void givePassPtr(Passenger &pass);
    /*!
     * \brief Получение ссылки на управляющего базами данных.
     * \param DBPointer Ссылка на упраляющего базами данных.
    */
    void giveDBManagerPtr(DataBases *DBPointer);

private slots:
    //! Перегруженный слот QDialog::accept(), расширяющий функционал
    void accept() override;
    //! Перегруженный слот QDialog::reject(), расширяющий функционал
    void reject() override;
    //! Слот регистрации, вызывающий окно RegistryWindow
    void registry();

private:
    //! Функция возвращает значения поля логина в форме
    QString getLoginString();
    //! Функция возвращает значения поля пароля в форме
    QString getPasswordString();
    //! Функция проверяет поля на правильность
    bool checkFields();
    //! Функция отвечает за создание корневого администратора
    void creatingRoot();
    //! Функция отвечает за сброс параметров корневого администратора
    void doRootReboot();
    //! Вызываемое всплывающее окно, говорящее пользователю об успешном создании администратора
    void adminCreatedBox();
    //! Вызываемое всплывающее окно, говорящее пользователю об успешном сбросе параметров администратора
    void rootRebootBox();
    //! Указатель на управляющего базами данных
    DataBases *DBManagerPtr;
    //! Указатель на пользователя
    User *userPtr;
    //! Указатель на пассажира
    Passenger *passPtr;
    //! Указатель на флаг закрытия окна авторизации
    bool *authWindowClosed;
    Ui::AuthWindow *ui;
};

#endif // AUTHWINDOW_H
