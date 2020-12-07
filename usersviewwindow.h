#ifndef USERSVIEWWINDOW_H
#define USERSVIEWWINDOW_H

#include <QDialog>
#include <QStandardItemModel>
#include <databases.h>
#include <user.h>
#include <string>
#include <QString>
#include <QList>

namespace Ui {
class UsersViewWindow;
}

class UsersViewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UsersViewWindow(QWidget *parent = nullptr);
    ~UsersViewWindow();

    void giveDBManagerPtr(DataBases *DBPointer);
    void giveListPtr(QList<User> *userListPtr);
    void fillTable();

private:
    DataBases *DBManagerPtr;

    QList<User> usersToShow;

    Ui::UsersViewWindow *ui;
    QStandardItemModel *table;
};

#endif // USERSVIEWWINDOW_H
