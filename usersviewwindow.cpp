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
    QStringList qstringlist = {"ID", "Login", "Type"};
    for(int row = 0; row < table->rowCount(); row++)
    {

        table->setHorizontalHeaderLabels(qstringlist);
        index = table->index(row, 1);
        table->setData(index, QString::fromStdString(usersToShow[row].getLogin()));
    }
}
