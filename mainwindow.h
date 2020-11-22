#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <authwindow.h>
#include <QMainWindow>
#include <user.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool MainWindowClosed = true;
    bool authWindowClosed = false;

private:
    // Текущий пользователь
    User currentUser;

    // Окно авторизации
    AuthWindow authWindow;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
