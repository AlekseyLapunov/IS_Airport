#include "ticketsviewwindow.h"
#include "ui_ticketsviewwindow.h"

TicketsViewWindow::TicketsViewWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TicketsViewWindow)
{
    ui->setupUi(this);table = new QStandardItemModel(this);
    ui->ticketsView->setModel(table);
}

TicketsViewWindow::~TicketsViewWindow()
{
    DBManagerPtr = nullptr;
    ticketsListPtr = nullptr;
    ticketsToShow.clear();
    delete ui;
}

void TicketsViewWindow::giveDBManagerPtr(DataBases *DBPointer)
{
    DBManagerPtr = DBPointer;
}

void TicketsViewWindow::giveListPtr(QList<Ticket> *sTicketListPtr)
{
    ticketsListPtr = sTicketListPtr;
}

void TicketsViewWindow::refreshListPtr()
{
    ticketsToShow = *ticketsListPtr;
}

void TicketsViewWindow::fillTable()
{
    refreshListPtr();
    table->setColumnCount(3);
    table->setRowCount(ticketsToShow.size());
    QModelIndex index;
    QStringList collsName = {"ID рейса", "ID пассажира", "Статус"};
    table->setHorizontalHeaderLabels(collsName);
    for(int row = 0; row < table->rowCount(); row++)
    {
        index = table->index(row, 0);
        table->setData(index, ticketsToShow[row].getRouteID());
        index = table->index(row, 1);
        table->setData(index, ticketsToShow[row].getPassID());
        index = table->index(row, 2);
        table->setData(index, ticketsToShow[row].getStatusStr());
    }
}
