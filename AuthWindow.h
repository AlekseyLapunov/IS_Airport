#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <DataBases.h>
#include <User.h>

namespace Ui {
class AuthWindow;
}

class AuthWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AuthWindow(QWidget *parent = nullptr);
    ~AuthWindow();
    void giveFlag(bool &flag);
    void giveUserPtr(User &user);
    void givePassPtr(Passenger &pass);
    void giveDBManagerPtr(DataBases *DBPointer);

private slots:
    void accept() override;
    void reject() override;
    void registry();

private:
    QString getLoginString();
    QString getPasswordString();
    bool checkFields();
    void creatingRoot();
    void doRootReboot();
    void adminCreatedBox();
    void rootRebootBox();
    DataBases *DBManagerPtr;
    User *userPtr;
    Passenger *passPtr;
    bool *authWindowClosed;
    Ui::AuthWindow *ui;
};

#endif // AUTHWINDOW_H
