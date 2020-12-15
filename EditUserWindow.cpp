#include "EditUserWindow.h"
#include "ui_edituserwindow.h"

#include <QMessageBox>

EditUserWindow::EditUserWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditUserWindow)
{
    ui->setupUi(this);

}

EditUserWindow::~EditUserWindow()
{
    delete ui;
}

void EditUserWindow::giveUserPtr(User *sPtr)
{
    userPtr = sPtr;
}

void EditUserWindow::giveDBManagerPtr(DataBases *sPtr)
{
    DBManagerPtr = sPtr;
}

void EditUserWindow::giveBoolPtr(bool *sBoolPtr)
{
    userChanged = sBoolPtr;
}

void EditUserWindow::accept()
{
    if(checkFields())
    {
        *userChanged = true;
        User transmitter(ui->loginEdit->text().toStdString(), ui->passwordEdit->text().toStdString(),
                     userPtr->getID(), ui->typeEdit->currentIndex());
        *userPtr = transmitter;
        QDialog::accept();
    }
}

void EditUserWindow::setFields()
{
    if(userPtr)
    {
        ui->loginEdit->setText(QString::fromStdString(userPtr->getLogin()));
        ui->loginEdit->setDisabled(true);
        ui->passwordEdit->setText(QString::fromStdString(userPtr->getPassword()));
        ui->typeEdit->setCurrentIndex(userPtr->getType());
    }
}

bool EditUserWindow::checkFields()
{
    QMessageBox mBox;
    mBox.setWindowTitle(tr("Внимание"));
    mBox.setIcon(QMessageBox::Warning);
    mBox.setText(tr("Проверьте введённые данные, пожалуйста"));
    if(ui->loginEdit->text().isEmpty() || ui->passwordEdit->text().isEmpty())
    {
        mBox.exec();
        return false;
    }
    if(ui->loginEdit->text().length() < 4 || ui->loginEdit->text().length() > 12
    || ui->passwordEdit->text().length() < 4 || ui->passwordEdit->text().length() > 18)
    {
        mBox.exec();
        return false;
    }
    if(ui->loginEdit->text().contains(QRegularExpression("[^a-z0-9]")))
    {
        mBox.exec();
        return false;
    }
    if(ui->typeEdit->currentIndex() == 0)
    {
        mBox.exec();
        return false;
    }
    return true;
}
