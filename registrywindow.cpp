#include "registrywindow.h"
#include "ui_registrywindow.h"

#include <QMessageBox>

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
        QMessageBox mBox;
        mBox.setWindowTitle(tr("Warning"));
        mBox.setIcon(QMessageBox::Warning);
        mBox.setText(tr("Check if entered data is valid, please"));
        mBox.exec();
    } else
    QDialog::accept();
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
    return true;
}

bool RegistryWindow::checkFullNameField()
{
    return true;
}

bool RegistryWindow::checkPassportField()
{
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

string RegistryWindow::getFullNameFF()
{
    return this->ui->fullNameField->text().toStdString();
}

string RegistryWindow::getPassportFF()
{
    return this->ui->passportField->text().toStdString();
}
