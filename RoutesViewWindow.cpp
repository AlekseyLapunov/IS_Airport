#include "RoutesViewWindow.h"
#include "ui_routesviewwindow.h"

RoutesViewWindow::RoutesViewWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoutesViewWindow)
{
    ui->setupUi(this);
    table = new QStandardItemModel(this);
    ui->routesView->setModel(table);
}

RoutesViewWindow::~RoutesViewWindow()
{
    DBManagerPtr = nullptr;
    routesListPtr = nullptr;
    routesToShow.clear();
    delete ui;
}

void RoutesViewWindow::giveDBManagerPtr(DataBases *DBPointer)
{
    DBManagerPtr = DBPointer;
}

void RoutesViewWindow::giveListPtr(QList<Route> *sRouteListPtr)
{
    routesListPtr = sRouteListPtr;
}

void RoutesViewWindow::refreshListPtr()
{
    routesToShow = *routesListPtr;
}

void RoutesViewWindow::fillTable()
{
    refreshListPtr();
    table->setColumnCount(5);
    table->setRowCount(routesToShow.size());
    QModelIndex index;
    QStringList collsName = {"ID", "П. отправления", "П. назначения",
                             "Марка с.", "Кол-во св. мест"};
    table->setHorizontalHeaderLabels(collsName);
    for(int row = 0; row < table->rowCount(); row++)
    {
        index = table->index(row, 0);
        table->setData(index, routesToShow[row].getID());
        index = table->index(row, 1);
        table->setData(index, routesToShow[row].getDepart());
        index = table->index(row, 2);
        table->setData(index, routesToShow[row].getDest());
        index = table->index(row, 3);
        table->setData(index, routesToShow[row].getMark());
        index = table->index(row, 4);
        table->setData(index, routesToShow[row].getSeats());
    }
}
