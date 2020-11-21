#include "authwindow.h"
#include "ui_authwindow.h"

AuthWindow::AuthWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Auth. Window");
}

AuthWindow::~AuthWindow()
{
    delete ui;
}

void AuthWindow::giveFlag(bool &flag)
{
    authWindowClosed = &flag;
}

void AuthWindow::reject()
{
    *authWindowClosed = true;
    QDialog::reject();
}


