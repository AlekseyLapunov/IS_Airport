#ifndef EDITUSERWINDOW_H
#define EDITUSERWINDOW_H

#include <QDialog>
#include <user.h>
#include <databases.h>

namespace Ui {
class EditUserWindow;
}

class EditUserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditUserWindow(QWidget *parent = nullptr);
    ~EditUserWindow();

    void giveUserPtr(User*);
    void giveDBManagerPtr(DataBases*);
    void giveBoolPtr(bool *boolPtr);
    void setFields();

private slots:

    void accept() override;

private:
    bool checkFields();

    bool *userChanged;
    DataBases *DBManagerPtr;
    User *userPtr;
    Ui::EditUserWindow *ui;
};

#endif // EDITUSERWINDOW_H
