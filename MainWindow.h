#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <AuthWindow.h>
#include <QMainWindow>
#include <User.h>
#include <DataBases.h>
#include <QMessageBox>
#include <UsersViewWindow.h>
#include <PassesViewWindow.h>
#include <RoutesViewWindow.h>
#include <ManageRoutesWindow.h>
#include <TicketRequestWindow.h>
#include <TicketsViewWindow.h>
#include <MyInfoWindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \brief Класс главного окна ИС Аэропорт
 *
 * Отвечает за осуществление основного взаимодействия пользователя
 * с информационной системой
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //! Логическая переменная, сигнализирующая о том, закрылось ли главное окно
    bool MainWindowClosed = true;
    //! Логическая переменная, сигнализирующая о том, закрылось ли окно авторизации
    bool authWindowClosed = false;
    //! Функция очищает списки объектов ИС
    void setNulls();

private slots:
    //! Слот открытия окна просмотра пользователей
    void viewUsers();
    //! Слот открытия окна просмотра пассажиров
    void viewPasses();
    //! Слот открытия окна просмотра своей информации
    void viewMyInfo();
    //! Слот открытия окна создания/удаления маршрута
    void manageRoutes();
    //! Слот открытия окна просмотра рейсов
    void viewRoutes();
    //! Слот открытия окна просмотра запросов билетов
    void viewTickets();
    //! Слот открытия окна запроса билета
    void doRequest();
    //! Слот выхода из программы
    void quit();
    //! Слот вызова окна информации о программе ИС Аэропорт
    void tellAbout();

private:
    //! Текущий пользователь
    User currentUser;
    //! Текущий пассажир
    Passenger currentPass;
    //! Список пользователей
    QList<User> UsersList;
    //! Список пассажиров
    QList<Passenger> PassesList;
    //! Список билетов
    QList<Ticket> TicketsList;
    //! Список рейсов
    QList<Route> RoutesList;
    //! Функция устанавливает видимость элементов интерфейса в зависимости от типа текущего пользователя
    void manageWidgets();
    //! Функция "раздаёт" указатели на списки объектов ИС и некоторые другие элементы другим классам
    void giveAllPtrs();
    //! Объект взаимодействия с базами данных
    DataBases DBManager;
    //! Окно авторизации
    AuthWindow authWindow;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
