#ifndef REGISTRYWINDOW_H
#define REGISTRYWINDOW_H

#include <QDialog>
#include <string>
#include <databases.h>

using namespace std;

namespace Ui {
class RegistryWindow;
}

class RegistryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegistryWindow(QWidget *parent = nullptr);
    ~RegistryWindow();



private slots:
    void beginRegistry();
    void gracBox();
    void warnBox();

private:
    bool checkFields();
    bool checkPasswords();
    bool checkLoginField();
    bool checkPasswordField();
    bool checkFullNameField();
    bool checkPassportField();

    bool anyEmpty();

    string getLoginFF();
    string getPasswordFF();
    string getPasswordACKFF();
    QString getFullNameFF();
    QString getPassportFF();

    DataBases dataBaseManager;

    Ui::RegistryWindow *ui;
};

#endif // REGISTRYWINDOW_H
