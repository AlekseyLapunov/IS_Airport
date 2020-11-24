#include "registrywindow.h"
#include "ui_registrywindow.h"

#include <QMessageBox>
#include <QString>
#include <QRegularExpression>

RegistryWindow::RegistryWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistryWindow)
{
    ui->setupUi(this);
}

RegistryWindow::~RegistryWindow()
{
    delete ui;
}

void RegistryWindow::beginRegistry()
{
    if(!checkFields())
    {
        warnBox();
    }
    else
    {
        gracBox();

        QDialog::accept();
    }
}

void RegistryWindow::gracBox()
{
    QMessageBox mBox;
    mBox.setWindowTitle(tr("Congratulations!"));
    mBox.setIcon(QMessageBox::Information);
    mBox.setText(tr("Registry Complete"));
    mBox.exec();
}

void RegistryWindow::warnBox()
{
    QMessageBox mBox;
    mBox.setWindowTitle(tr("Warning"));
    mBox.setIcon(QMessageBox::Warning);
    mBox.setText(tr("Check if entered data is valid, please"));
    mBox.exec();
}

bool RegistryWindow::checkFields()
{
    if(anyEmpty()) return false;
    if(checkLoginField() &&
    checkPasswordField() &&
    checkPasswords()     &&
    checkFullNameField() &&
    checkPassportField())
    return true; else return false;
}

bool RegistryWindow::anyEmpty()
{
    if(getLoginFF().length() <= 0 ||
       getPasswordFF().length() <= 0 ||
       getPasswordACKFF().length() <= 0 ||
       getFullNameFF().length() <=0 ||
       getPassportFF().length() <= 0) return true;
    else return false;
}

bool RegistryWindow::checkLoginField()
{
    string login = getLoginFF();
    if(login.length() < 4 || login.length() > 10) return false;
    else
    {
        // Посимвольная проверка
        for(int i = 0; i < login.length(); i++)
        {
            int charToInt = login[i];
            if((charToInt < 65 || charToInt > 90) && (charToInt < 97 || charToInt > 122) && (charToInt < 48 || charToInt > 57))
                return false;
        }
        return true;
    }
}

bool RegistryWindow::checkPasswordField()
{
    string password = getPasswordFF();
    if(password.length() < 4 || password.length() > 18) return false;
    else
    {
        // Посимвольная проверка
        for(int i = 0; i < password.length(); i++)
        {
            int charToInt = password[i];
            if((charToInt < 65 || charToInt > 90)
               && (charToInt < 97 || charToInt > 122)
               && (charToInt < 48 || charToInt > 57)
               && (charToInt < 35 || charToInt > 38)
               && (charToInt != 42) && (charToInt != 32)
               && (charToInt != 38))
                return false;
        }
        return true;
    }
}

bool RegistryWindow::checkFullNameField()
{
    QString fullName = getFullNameFF();
    if(fullName.size() < 6 || fullName.size() > 40) return false;
    // Если ФИО содержит буквы кроме русских
    if(fullName.contains(QRegularExpression("[^А-Я а-я]")))
        {
            return false;
        }
    if(fullName.count(" ") != 2) return false;
    if(fullName.count("  ") != 0) return false;
    return true;
}

bool RegistryWindow::checkPassportField()
{
    QString passInfo = getPassportFF();
    int length = passInfo.length();
    if(passInfo.length() != 11) return false;
    // Если паспортная информация содержит что-то кроме цифр и пробела
    if(passInfo.contains(QRegularExpression("[^0-9 ]")))
        {
            return false;
        }
    if(passInfo.count(" ") != 1) return false;
    return true;
}

bool RegistryWindow::checkPasswords()
{
    if(getPasswordFF() == getPasswordACKFF())
    return true; else return false;
}

string RegistryWindow::getLoginFF()
{
    return this->ui->loginField->text().toStdString();
}

string RegistryWindow::getPasswordFF()
{
    return this->ui->passwordField->text().toStdString();
}

string RegistryWindow::getPasswordACKFF()
{
    return this->ui->passwordField_2->text().toStdString();
}

QString RegistryWindow::getFullNameFF()
{
    return this->ui->fullNameField->text();
}

QString RegistryWindow::getPassportFF()
{
    return this->ui->passportField->text();
}
