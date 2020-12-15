#include "UsersViewWindow.h"
#include "ui_usersviewwindow.h"

UsersViewWindow::UsersViewWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsersViewWindow)
{
    ui->setupUi(this);
    table = new QStandardItemModel(this);
    ui->usersView->setModel(table);
}

UsersViewWindow::~UsersViewWindow()
{
    DBManagerPtr = nullptr;
    userListPtr = nullptr;
    usersToShow.clear();
    delete ui;
}

void UsersViewWindow::giveDBManagerPtr(DataBases *DBPointer)
{
    DBManagerPtr = DBPointer;
}

void UsersViewWindow::giveListPtr(QList<User> *sUserListPtr)
{
    userListPtr = sUserListPtr;
}

void UsersViewWindow::refreshListPtr()
{
    usersToShow = *userListPtr;
}

void UsersViewWindow::fillTable()
{
    refreshListPtr();
    table->setColumnCount(3);
    table->setRowCount(usersToShow.size());
    QModelIndex index;
    QStringList collsName = {"ID", "Login", "Type"};
    table->setHorizontalHeaderLabels(collsName);
    for(int row = 0; row < table->rowCount(); row++)
    {
        index = table->index(row, 0);
        table->setData(index, usersToShow[row].getID());
        index = table->index(row, 1);
        table->setData(index, QString::fromStdString(usersToShow[row].getLogin()));
        index = table->index(row, 2);
        table->setData(index, usersToShow[row].getTypeString());
    }
}

void UsersViewWindow::editUser(QModelIndex index)
{
    int curRowNumber = index.row();
    userChanged = false;
    QModelIndex temp = table->index(curRowNumber, 0);
    int ID = table->data(temp).toInt();
    temp = table->index(curRowNumber, 1);
    QString login = table->data(temp).toString();
    DBManagerPtr->find(ID, login.toStdString(), userFound);
    editUserWindow.giveUserPtr(&userFound);
    editUserWindow.giveDBManagerPtr(DBManagerPtr);
    editUserWindow.giveBoolPtr(&userChanged);
    editUserWindow.setFields();
    editUserWindow.exec();
    if(userChanged)
    {
        string sPassword = userFound.getPassword();
        int sType = userFound.getType();
        DBManagerPtr->changeUserInfo(ID, login.toStdString(), sPassword, sType);
        fillTable();
    }
}












