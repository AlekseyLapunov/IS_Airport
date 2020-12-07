#ifndef EDITUSERWINDOW_H
#define EDITUSERWINDOW_H

#include <QDialog>

namespace Ui {
class EditUserWindow;
}

class EditUserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditUserWindow(QWidget *parent = nullptr);
    ~EditUserWindow();

private:
    Ui::EditUserWindow *ui;
};

#endif // EDITUSERWINDOW_H
