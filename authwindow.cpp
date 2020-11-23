#include "authwindow.h"
#include "ui_authwindow.h"

#include "registrywindow.h"

AuthWindow::AuthWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Auth. Window");
    ManageDataBase.checkForDir();
}

AuthWindow::~AuthWindow()
{
    delete ui;
}

void AuthWindow::giveFlag(bool &flag)
{
    authWindowClosed = &flag;
}

void AuthWindow::giveUserPtr(User &user)
{
    userPtr = &user;
}

bool AuthWindow::checkFields()
{
    QMessageBox mBox;
    mBox.setWindowTitle(tr("Warning"));
    mBox.setIcon(QMessageBox::Warning);
    mBox.setText(tr("Check if entered data is valid, please"));
    if(this->getLoginString().isEmpty() || this->getPasswordString().isEmpty())
    {
        mBox.exec();
        return false;
    }
    if(this->getLoginString().length() < 5 || this->getLoginString().length() > 12
    || this->getPasswordString().length() < 5 || this->getPasswordString().length() > 20)
    {
        mBox.exec();
        return false;
    }
    return true;
}

void AuthWindow::accept()
{
    *authWindowClosed = false;
    // Проверка полей на правильность ввода
    if(this->checkFields())
    {
        if(ManageDataBase.find(getLoginString().toStdString(), getPasswordString().toStdString(), userPtr))
        {
        QDialog::accept();
        }
    }
    else return;
}

void AuthWindow::reject()
{
    *authWindowClosed = true;
    QDialog::reject();
}

void AuthWindow::registry()
{
    RegistryWindow regWindow;
    regWindow.setWindowTitle(tr("Регистрация"));
    regWindow.exec();
}

QString AuthWindow::getLoginString()
{
    return this->ui->loginField->text();
}

QString AuthWindow::getPasswordString()
{
    return this->ui->passwordField->text();
}
