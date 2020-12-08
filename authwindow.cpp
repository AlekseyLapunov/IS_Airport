#include "authwindow.h"
#include "ui_authwindow.h"
#include <QRegularExpression>
#include "registrywindow.h"

AuthWindow::AuthWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Авторизация");
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

void AuthWindow::givePassPtr(Passenger &pass)
{
    passPtr = &pass;
}

void AuthWindow::giveDBManagerPtr(DataBases *DBPointer)
{
    DBManagerPtr = DBPointer;
}

bool AuthWindow::checkFields()
{
    QMessageBox mBox;
    mBox.setWindowTitle(tr("Внимание"));
    mBox.setIcon(QMessageBox::Warning);
    mBox.setText(tr("Проверьте введённые данные, пожалуйста"));
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
    if(getLoginString().contains(QRegularExpression("[^a-z0-9]")))
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
        if(getLoginString() == "admintools" && getPasswordString() == "30112020")
        {
           if(DBManagerPtr->loginFound("root"))
           {
               QMessageBox mBox;
               mBox.setWindowTitle(tr("Ошибка"));
               mBox.setIcon(QMessageBox::Critical);
               mBox.setText(tr("Корневой администратор уже создан"));
               mBox.exec();
           }
           else
           {
            DBManagerPtr->createAdmin("root", "standart#");
            AuthWindow::adminCreatedBox();
           }
        }
        else
        if(DBManagerPtr->find(getLoginString().toStdString(), getPasswordString().toStdString(), *userPtr))
        {
            DBManagerPtr->find(userPtr->getID(), *passPtr);
            QDialog::accept();
        }
        else
        {
            QMessageBox warning;
            warning.setWindowTitle("Ошибка");
            warning.setText("Не удалось найти пользователя с такой<br> комбинацией логина и пароля");
            warning.setIcon(QMessageBox::Critical);
            warning.exec();
        }
    }
    else return;
}

void AuthWindow::adminCreatedBox()
{
    QMessageBox mBox;
    mBox.setWindowTitle(tr("Успех"));
    mBox.setIcon(QMessageBox::Information);
    mBox.setText(tr("Корневой администратор был создан: root, standart_#"));
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
