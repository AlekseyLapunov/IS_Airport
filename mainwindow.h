#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <authwindow.h>
#include <QMainWindow>
#include <user.h>
#include <databases.h>
#include <QMessageBox>
#include <usersviewwindow.h>
#include <passesviewwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showCurrent();
    bool MainWindowClosed = true;
    bool authWindowClosed = false;

    void setNulls();

private slots:

    void viewUsers();
    void viewPasses();

private:
    // Текущий пользователь
    User currentUser;
    // Текущий пассажир
    Passenger currentPass;

    // Список пользователей
    QList<User> UsersList;
    // Список пассажиров
    QList<Passenger> PassesList;
    // Список билетов
    QList<Ticket> TicketsList;
    // Список рейсов
    QList<Route> RoutesList;

    void manageWidgets();
    void giveAllPtrs();

    // Взаимодействие с базами данных
    DataBases DBManager;

    // Окно авторизации
    AuthWindow authWindow;
    // Просмотр пользователей
    UsersViewWindow usersWindow;
    // Просмотр пассажиров
    PassesViewWindow passesWindow;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
