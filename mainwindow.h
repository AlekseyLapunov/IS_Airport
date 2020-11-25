#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <authwindow.h>
#include <QMainWindow>
#include <user.h>
#include <databases.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool MainWindowClosed = true;
    bool authWindowClosed = false;

private:
    // Текущий пользователь
    User currentUser;

    // Список пользователей
    QList<User> UsersList;
    // Список пассажиров
    QList<Passenger> PassengerList;
    // Список билетов
    QList<Ticket> TicketsList;
    // Список рейсов
    QList<Route> RoutesList;

    // Взаимодействие с базами данных
    DataBases DBManager;

    // Окно авторизации
    AuthWindow authWindow;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
