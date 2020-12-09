#include "passesviewwindow.h"
#include "ui_passesviewwindow.h"

PassesViewWindow::PassesViewWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PassesViewWindow)
{
    ui->setupUi(this);table = new QStandardItemModel(this);
    ui->passesView->setModel(table);
}

PassesViewWindow::~PassesViewWindow()
{
    DBManagerPtr = nullptr;
    passesListPtr = nullptr;
    passesToShow.clear();
    delete ui;
}

void PassesViewWindow::giveDBManagerPtr(DataBases *DBPointer)
{
    DBManagerPtr = DBPointer;
}

void PassesViewWindow::giveListPtr(QList<Passenger> *sPassesListPtr)
{
    passesListPtr = sPassesListPtr;
}

void PassesViewWindow::refreshListPtr()
{
    passesToShow = *passesListPtr;
}

void PassesViewWindow::fillTable()
{
    refreshListPtr();
    table->setColumnCount(3);
    table->setRowCount(passesToShow.size());
    QModelIndex index;
    QStringList collsName = {"ID", "ФИО", "Серия Номер"};
    table->setHorizontalHeaderLabels(collsName);
    for(int row = 0; row < table->rowCount(); row++)
    {
        index = table->index(row, 0);
        table->setData(index, passesToShow[row].getID());
        index = table->index(row, 1);
        table->setData(index, passesToShow[row].getFullName());
        index = table->index(row, 2);
        table->setData(index, passesToShow[row].getPassport());
    }
}

void PassesViewWindow::editPass(QModelIndex index)
{
    /*
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
    */
}
