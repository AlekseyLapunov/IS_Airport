#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QApplication"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::setNulls();
    DBManager.setListPointers(&UsersList, &PassengerList,
                              &RoutesList, &TicketsList);
    DBManager.loadAllBase();
    authWindow.giveDBManagerPtr(&DBManager);
    authWindow.giveFlag(authWindowClosed);
    authWindow.giveUserPtr(currentUser);
    authWindow.givePassPtr(currentPass);
    // Вызов окна авторизации
    authWindow.exec();
   if(!authWindowClosed)
   {
       MainWindowClosed = false;
       this->show();
   }
   MainWindow::showCurrent();
   MainWindow::disableForType();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setNulls()
{
    UsersList.clear();
    PassengerList.clear();
    TicketsList.clear();
    RoutesList.clear();
}

void MainWindow::viewUsers()
{

}

void MainWindow::disableForType()
{
    if(this->currentUser.getType() == User::idAdministrator)
    {
        ui->myInfoButton->setHidden(true);
        ui->makeRequestButton->setHidden(true);
    }
    else if (this->currentUser.getType() == User::idCashier)
    {
        ui->myInfoButton->setHidden(true);
        ui->makeRequestButton->setHidden(true);
        ui->viewUsersButton->setHidden(true);
        ui->viewPassesButton->setHidden(true);
    }
    else if (this->currentUser.getType() == User::idPassenger)
    {
        ui->viewUsersButton->setHidden(true);
        ui->viewPassesButton->setHidden(true);
        ui->manageRoutesButton->setHidden(true);
        ui->viewRequestsButton->setHidden(true);
    }
}

void MainWindow::showCurrent()
{
    QMessageBox mBox;
    mBox.setWindowTitle("This user info");
    QString login = QString::fromStdString(currentUser.getLogin());
    QString password = QString::fromStdString(currentUser.getPassword());
    int ID = currentUser.getID();
    int type = currentUser.getType();
    QString typeName;
    if(type == User::idAdministrator) typeName = "Admin";
    if(type == User::idPassenger) typeName = "Passenger";
    mBox.setText(tr("Login: %1 <br>"
                    "Password: %2 <br>"
                    "ID: %3 <br>"
                    "Type: %4").arg(login).arg(password).arg(ID).arg(typeName));
    mBox.exec();
    QMessageBox mBox2;
    mBox2.setWindowTitle("This pass info");
    QString fullName = currentPass.getFullName();
    QString passport = currentPass.getPassport();
    int ID2 = currentPass.getID();
    mBox2.setText(tr("Full Name: %1 <br>"
                    "Passport: %2 <br>"
                    "ID: %3").arg(fullName).arg(passport).arg(ID2));
    mBox2.exec();
}










