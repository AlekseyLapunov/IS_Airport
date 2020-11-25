#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QApplication"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DBManager.setListPointers(UsersList, PassengerList, RoutesList, TicketsList);
    authWindow.giveFlag(authWindowClosed);
    authWindow.giveUserPtr(currentUser);
    // Вызов окна авторизации
    authWindow.exec();
   if(!authWindowClosed)
   {
       MainWindowClosed = false;
       this->show();
   }
}

MainWindow::~MainWindow()
{
    delete ui;
}


