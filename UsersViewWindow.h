#ifndef USERSVIEWWINDOW_H
#define USERSVIEWWINDOW_H

#include <QDialog>
#include <QStandardItemModel>
#include <DataBases.h>
#include <User.h>
#include <string>
#include <QString>
#include <QList>
#include <QMessageBox>
#include <EditUserWindow.h>

namespace Ui {
class UsersViewWindow;
}

/*!
 * \brief Класс окна просмотров пользователей
 *
 * Окно позволяет администраторам просматривать
 * текущих участников информационной системы
 * Администратор может редактировать информацию выбранного
 * пользователя, активируя строку в таблице
 */
class UsersViewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UsersViewWindow(QWidget *parent = nullptr);
    ~UsersViewWindow();

    /*!
     * \brief Функция получения указателя на объект взаимодействия с базами данных
     * \param DBPointer Указатель на объект взаимодействия с базами данных
     */
    void giveDBManagerPtr(DataBases *DBPointer);
    /*!
     * \brief Функция получения указателя на список билетов
     * \param sUserListPtr Указатель на список пользователей
     */
    void giveListPtr(QList<User> *sUserListPtr);
    /*!
     * \brief Функция заполнения таблицы пользователей
     * \param def Логический флаг, отвечающий за применение фильтра при заполнении таблицы
     */
    void fillTable(bool def = 1);
    /*!
     * \brief Функция получает указатель на текущего пользователя
     * \param curUser Указатель на текущего пользователя
     */
    void giveCurUserPtr(User *curUser);

private slots:
    /*!
     * \brief Слот вызова окна редактирования выделенного пользователя
     *
     * С помощью QModelIndex определяется выделенный объект для дальнейшей работы с ним
     */
    void editUser(QModelIndex);
    //! Слот применения фильтра
    void startFilter(QString);

private:
    //! Функция обновляет указатель на список пользователей
    void refreshListPtr();
    //! Указатель на объект взаимодействия с базами данных
    DataBases *DBManagerPtr;
    //! Список пользователей на отображение
    QList<User> usersToShow;
    //! Указатель на список пользователей
    QList<User> *userListPtr;
    //! Найденный пользователь
    User userFound;
    //! Указатель на текущего пользователя
    User *curUserPtr;
    //! Логическая переменная, сигнализирующая о том, изменился ли пользователь
    bool userChanged;
    //! Окно редактирования информации пользователя
    EditUserWindow editUserWindow;
    Ui::UsersViewWindow *ui;
    QStandardItemModel *table;
};

#endif // USERSVIEWWINDOW_H
