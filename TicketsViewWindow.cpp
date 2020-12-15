#include "TicketsViewWindow.h"
#include "ui_ticketsviewwindow.h"
#include <QMessageBox>

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

void TicketsViewWindow::answerToReq(QModelIndex index)
{
    int curRowNumber = index.row();
    QModelIndex temp = table->index(curRowNumber, 0);
    int routeID = table->data(temp).toInt();
    temp = table->index(curRowNumber, 1);
    int passID = table->data(temp).toInt();
    temp = table->index(curRowNumber, 2);
    QString status = table->data(temp).toString();
    int statusInt = defineStatus(status);
    Ticket ticketFound;
    DBManagerPtr->find(routeID, passID, ticketFound);

    QMessageBox quitBox(this);
    quitBox.setIcon(QMessageBox::Question);
    if(statusInt == Ticket::stReqAns || statusInt == Ticket::stRetAns)
    {
        quitBox.setWindowTitle("Ответ");
        quitBox.setText(tr("Вы уверены, что хотите<br> подтвердить запрос?"));
    }
    else
    {
        quitBox.setWindowTitle("Отклонение");
        quitBox.setText(tr("Вы уверены, что хотите<br> вернуть запрос?"));
    }
    if(statusInt)
    quitBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
    quitBox.setDefaultButton(QMessageBox::Yes);
    if(quitBox.exec() == QMessageBox::Yes)
    {
        if(DBManagerPtr->changeTicket(routeID, passID, statusInt))
        {
            fillTable();
            gracBox();
        }
        else critBox();
    }
}

void TicketsViewWindow::gracBox()
{
    QMessageBox mBox;
    mBox.setWindowTitle(tr("Успех"));
    mBox.setIcon(QMessageBox::Information);
    mBox.setText(tr("Запрос был обработан успешно"));
    mBox.exec();
}

void TicketsViewWindow::critBox()
{
    QMessageBox mBox;
    mBox.setWindowTitle(tr("Ошибка"));
    mBox.setIcon(QMessageBox::Critical);
    mBox.setText(tr("Запрос не был обработан<br> по непредвиденной причине"));
    mBox.exec();
}

int TicketsViewWindow::defineStatus(QString ticketStatus)
{
    if(ticketStatus == "Покупка") return Ticket::stReqAns;
    else if(ticketStatus == "Возврат") return Ticket::stRetAns;
    else if (ticketStatus == "Куплен") return Ticket::stReq;
    else if (ticketStatus == "Возвращён") return Ticket::stRet;
    else return 0;
}





