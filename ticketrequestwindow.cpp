#include "ticketrequestwindow.h"
#include "ui_ticketrequestwindow.h"

#include <QMessageBox>

TicketRequestWindow::TicketRequestWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TicketRequestWindow)
{
    ui->setupUi(this);
}

TicketRequestWindow::~TicketRequestWindow()
{
    delete ui;
}

void TicketRequestWindow::giveDBManagePtr(DataBases *DBPtr)
{
    DBManagePtr = DBPtr;
}

void TicketRequestWindow::giveUserPtr(User *userPtr)
{
    curUserPtr = userPtr;
}

void TicketRequestWindow::doRequest()
{
    if(DBManagePtr->find(ui->routeIDEdit->value(), route))
    {
        if(DBManagePtr->find(ui->routeIDEdit->value(), curUserPtr->getID(), Ticket::stReq, ticket) ||
           DBManagePtr->find(ui->routeIDEdit->value(), curUserPtr->getID(), Ticket::stReqAns, ticket))
        {
            this->ticketToReturn();
        }
        else if(DBManagePtr->find(ui->routeIDEdit->value(), curUserPtr->getID(), Ticket::stRet, ticket)
                || DBManagePtr->find(ui->routeIDEdit->value(), curUserPtr->getID(), Ticket::stRetAns, ticket))
        {
            this->ticketToBuy(change);
        }
        else this->ticketToBuy(push);
    }
    else warnBox();
}

void TicketRequestWindow::ticketToBuy(int flag)
{
    if(flag == push)
    DBManagePtr->pushTicket(ui->routeIDEdit->value(), curUserPtr->getID(), Ticket::stReq);
    else
    DBManagePtr->changeTicket(ui->routeIDEdit->value(), curUserPtr->getID(), Ticket::stReq);
    gracBox(req);
}

void TicketRequestWindow::ticketToReturn()
{
    DBManagePtr->changeTicket(ui->routeIDEdit->value(), curUserPtr->getID(), Ticket::stRet);
    gracBox(ret);
}

void TicketRequestWindow::warnBox()
{
    QMessageBox mBox;
    mBox.setWindowTitle(tr("Внимание"));
    mBox.setIcon(QMessageBox::Warning);
    mBox.setText(tr("Такого маршрута не существует"));
    mBox.exec();
}

void TicketRequestWindow::gracBox(int flag)
{
    QMessageBox mBox;
    mBox.setWindowTitle(tr("Успех"));
    mBox.setIcon(QMessageBox::Information);
    if(flag == req) mBox.setText(tr("Запрос билета со статусом \"Покупка\" создан"));
    if(flag == ret) mBox.setText(tr("Запрос билета со статусом \"Возврат\" создан"));
    mBox.exec();
}

