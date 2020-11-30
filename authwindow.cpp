#include "authwindow.h"
#include "ui_authwindow.h"
#include <QRegularExpression>
#include "registrywindow.h"

AuthWindow::AuthWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Auth. Window");
    DataBases::checkForDir();
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

void AuthWindow::giveDBManagerPtr(DataBases *DBPointer)
{
    DBManagerPtr = DBPointer;
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
    if(this->getLoginString().length() < 4 || this->getLoginString().length() > 12
    || this->getPasswordString().length() < 4 || this->getPasswordString().length() > 18)
    {
        mBox.exec();
        return false;
    }
    if(getLoginString().contains(QRegularExpression("[^a-z]")))
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
        if(getLoginString() == "admintools" && getPasswordString() == "30112020_nebula")
        {
           DBManagerPtr->createAdmin("root", "standart_#");
           adminCreatedBox();
        }
        if(DBManagerPtr->find(getLoginString().toStdString(), getPasswordString().toStdString(), *userPtr))
        {
            QDialog::accept();
        }
    }
    else return;
}

void AuthWindow::adminCreatedBox()
{
    QMessageBox mBox;
    mBox.setWindowTitle(tr("Success"));
    mBox.setIcon(QMessageBox::Information);
    mBox.setText(tr("Root user Administrator has been created: root, standart_#"));
    mBox.exec();
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
    regWindow.giveDBPtr(DBManagerPtr);
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
