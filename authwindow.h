#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <databases.h>
#include <user.h>

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

private slots:
    void accept() override;
    void reject() override;
    void registry();

private:

    // Возвращает строку логина из поля
    QString getLoginString();
    // Возвращает строку пароля из поля
    QString getPasswordString();
    // Проверяет поля ввода на правильность
    bool checkFields();

    User *userPtr;
    bool *authWindowClosed;
    Ui::AuthWindow *ui;

    DataBases ManageDataBase;

};

#endif // AUTHWINDOW_H
