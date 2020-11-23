#ifndef REGISTRYWINDOW_H
#define REGISTRYWINDOW_H

#include <QDialog>
#include <string>
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
    string getFullNameFF();
    string getPassportFF();

    Ui::RegistryWindow *ui;
};

#endif // REGISTRYWINDOW_H
