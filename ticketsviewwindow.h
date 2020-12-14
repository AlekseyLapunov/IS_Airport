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

private:
    DataBases *DBManagerPtr;

    QList<Ticket> ticketsToShow;
    QList<Ticket> *ticketsListPtr;

    void refreshListPtr();

    QStandardItemModel *table;

    Ui::TicketsViewWindow *ui;
};

#endif // TICKETSVIEWWINDOW_H
