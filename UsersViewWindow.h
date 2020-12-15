#ifndef USERSVIEWWINDOW_H
#define USERSVIEWWINDOW_H

#include <QDialog>
#include <QStandardItemModel>
#include <DataBases.h>
#include <User.h>
#include <string>
#include <QString>
#include <QList>
#include <QMessageBox>
#include <EditUserWindow.h>

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
    void giveListPtr(QList<User> *sUserListPtr);
    void fillTable();

private slots:
    void editUser(QModelIndex);

private:
    DataBases *DBManagerPtr;

    QList<User> usersToShow;
    QList<User> *userListPtr;

    void refreshListPtr();

    User userFound;
    bool userChanged;

    EditUserWindow editUserWindow;

    Ui::UsersViewWindow *ui;
    QStandardItemModel *table;
};

#endif // USERSVIEWWINDOW_H
