#ifndef PASSESVIEWWINDOW_H
#define PASSESVIEWWINDOW_H

#include <QDialog>
#include <QStandardItemModel>
#include <DataBases.h>
#include <Passenger.h>
#include <string>
#include <QString>
#include <QList>
#include <QMessageBox>
#include <EditPassWindow.h>

namespace Ui {
class PassesViewWindow;
}

class PassesViewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PassesViewWindow(QWidget *parent = nullptr);
    ~PassesViewWindow();

    void giveDBManagerPtr(DataBases *DBPointer);
    void giveListPtr(QList<Passenger> *sPassListPtr);
    void fillTable();

private slots:
    void editPass(QModelIndex);

private:
    DataBases *DBManagerPtr;

    QList<Passenger> passesToShow;
    QList<Passenger> *passesListPtr;

    void refreshListPtr();

    Passenger passFound;
    bool passChanged;

    EditPassWindow editPassWindow;
    QStandardItemModel *table;

    Ui::PassesViewWindow *ui;

};

#endif // PASSESVIEWWINDOW_H
