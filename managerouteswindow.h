#ifndef MANAGEROUTESWINDOW_H
#define MANAGEROUTESWINDOW_H

#include <QWidget>
#include <databases.h>
#include <QString>
#include <QMessageBox>

namespace Ui {
class ManageRoutesWindow;
}

class ManageRoutesWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ManageRoutesWindow(QWidget *parent = nullptr);
    ~ManageRoutesWindow();

    void giveDBPtr(DataBases *DBPtr);

private slots:

    void deleteRoute();
    void createRoute();
    void reactToCheck();

private:
    enum{creating, deleting};

    void setShowMode(bool);
    void gracBox();
    void warnBox();
    bool checkFields(int);

    bool checkIDEdit();
    bool checkDepDesEdits();
    bool checkMarkEdit();
    bool checkSeatsEdit();
    DataBases *DBManagePtr;

    Ui::ManageRoutesWindow *ui;
};

#endif // MANAGEROUTESWINDOW_H
