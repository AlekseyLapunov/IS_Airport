#include "usersviewwindow.h"
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
    delete ui;
}

void UsersViewWindow::giveDBManagerPtr(DataBases *DBPointer)
{
    DBManagerPtr = DBPointer;
}

void UsersViewWindow::giveListPtr(QList<User> *sUserListPtr)
{
    usersToShow = *sUserListPtr;
}

void UsersViewWindow::fillTable()
{
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
