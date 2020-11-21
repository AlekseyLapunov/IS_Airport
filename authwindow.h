#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QDialog>

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

private slots:
    void reject() override;



private:
    bool *authWindowClosed;
    Ui::AuthWindow *ui;
};

#endif // AUTHWINDOW_H
