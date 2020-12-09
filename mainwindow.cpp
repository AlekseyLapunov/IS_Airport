#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QApplication"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::setNulls();
    MainWindow::giveAllPtrs();
    DBManager.loadAllBase();

    // Вызов окна авторизации
    authWindow.exec();
   if(!authWindowClosed)
   {
       MainWindowClosed = false;
       MainWindow::manageWidgets();
       this->show();
       MainWindow::showCurrent();
   }
}

MainWindow::~MainWindow()
{
    MainWindow::setNulls();
    delete ui;
}

void MainWindow::giveAllPtrs()
{
    DBManager.setListPointers(&UsersList, &PassesList,
                              &RoutesList, &TicketsList);
    authWindow.giveDBManagerPtr(&DBManager);
    authWindow.giveFlag(authWindowClosed);
    authWindow.giveUserPtr(currentUser);
    authWindow.givePassPtr(currentPass);
}

void MainWindow::setNulls()
{
    UsersList.clear();
    PassesList.clear();
    TicketsList.clear();
    RoutesList.clear();
}

void MainWindow::viewUsers()
{
    usersWindow.giveDBManagerPtr(&DBManager);
    usersWindow.giveListPtr(&UsersList);
    usersWindow.fillTable();
    usersWindow.exec();
}

void MainWindow::viewPasses()
{
    passesWindow.giveDBManagerPtr(&DBManager);
    passesWindow.giveListPtr(&PassesList);
    passesWindow.fillTable();
    passesWindow.exec();
}

void MainWindow::manageWidgets()
{
    setWindowTitle(tr("ИС Аэропорт"));
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
    QString typeName = currentUser.getTypeString();
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










