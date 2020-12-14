#ifndef TICKETSVIEWWINDOW_H
#define TICKETSVIEWWINDOW_H

#include <QDialog>
#include <databases.h>
#include <QStandardItemModel>

namespace Ui {
class TicketsViewWindow;
}

class TicketsViewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TicketsViewWindow(QWidget *parent = nullptr);
    ~TicketsViewWindow();

    void giveDBManagerPtr(DataBases *DBPointer);
    void giveListPtr(QList<Ticket> *sTicketListPtr);
    void fillTable();

private slots:
    void answerToReq(QModelIndex);

private:
    DataBases *DBManagerPtr;

    QList<Ticket> ticketsToShow;
    QList<Ticket> *ticketsListPtr;

    void refreshListPtr();
    int defineStatus(QString ticketStatus);
    void gracBox();
    void critBox();

    QStandardItemModel *table;

    Ui::TicketsViewWindow *ui;
};

#endif // TICKETSVIEWWINDOW_H
