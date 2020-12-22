#ifndef REGISTRYWINDOW_H
#define REGISTRYWINDOW_H

#include <QDialog>
#include <string>
#include <DataBases.h>

using namespace std;

namespace Ui {
class RegistryWindow;
}

/*!
 * \brief Класс окна регистрации
 *
 * Регистрирует новых пользователей ИС
 */
class RegistryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegistryWindow(QWidget *parent = nullptr);
    ~RegistryWindow();
    /*!
     * \brief Функция получает указатель на объект управления базами данных
     * \param DBPtr Указатель на объект управления базами данных
     */
    void giveDBPtr(DataBases *DBPtr);

private slots:
    //! Слот начала регистрации. Здесь начинается данный процесс
    void beginRegistry();

private:
    //! Функция проверяет поля для заполнения на правильность
    bool checkFields();
    //! Всп. функция проверки поля паролей
    bool checkPasswords();
    //! Всп. функция проверки поля логина
    bool checkLoginField();
    //! Всп. функция проверки поля пароля
    bool checkPasswordField();
    //! Всп. функция проверки поля ФИО
    bool checkFullNameField();
    //! Всп. функция проверки поля паспортных данных
    bool checkPassportField();
    //! Всп. функция проверки полей на пустоту ("какой-либо пустой?")
    bool anyEmpty();
    //! Функция вызывает сообщение, сигнализирующее об успехе
    void gracBox();
    //! Функция вызывает предупреждающее сообщение
    void warnBox();
    //! Функция вызывает сообщение, сигнализирующее о том, что такой пользователь уже существует
    void existensBox();
    //! Функция возвращает значение поля логина
    string getLoginFF();
    //! Функция возвращает значение поля пароля
    string getPasswordFF();
    //! Функция возвращает значение поля повтора пароля
    string getPasswordACKFF();
    //! Функция возвращает значение поля ФИО
    QString getFullNameFF();
    //! Функция возвращает значение поля паспортных данных
    QString getPassportFF();
    //! Указатель на объект управления базами данных
    DataBases *DBManagePtr;
    Ui::RegistryWindow *ui;
};

#endif // REGISTRYWINDOW_H
