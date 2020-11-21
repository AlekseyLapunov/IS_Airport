#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QApplication"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    authWindow.giveFlag(authWindowClosed);
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


