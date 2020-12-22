#ifndef MANAGEROUTESWINDOW_H
#define MANAGEROUTESWINDOW_H

#include <QWidget>
#include <DataBases.h>
#include <QString>
#include <QMessageBox>
#include <QDialog>

namespace Ui {
class ManageRoutesWindow;
}

/*!
 * \brief Класс окна создания/удаления рейса
 *
 * Отвечает за создание и удаление рейсов
 */
class ManageRoutesWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ManageRoutesWindow(QWidget *parent = nullptr);
    ~ManageRoutesWindow();
    /*!
     * \brief Функция получения указателя на объект взаимодействия с базами данных
     * \param DBPtr Указатель на объект взаимодействия с базами данных
     */
    void giveDBPtr(DataBases *DBPtr);

private slots:
    //! Слот удаления рейса
    void deleteRoute();
    //! Слот создания рейса
    void createRoute();
    //! Слот "реагирования" на изменение блока с галочкой
    void reactToCheck();

private:
    //! Перечисление флагов: режимы создание, удаление
    enum{creating, deleting};
    /*!
     * \brief Функция активирует, либо деактивирует элементы интерфейса в зависимости от флага
     * \param flag Флаг режима: создание, удаление
     */
    void setShowMode(bool flag);
    /*!
     * \brief Функция вызывает сообщение, сигнализирующее об успехе
     * \param flag Флаг режима: создание, удаление
     */
    void gracBox(int flag);
    /*!
     * \brief Функция вызывает сообщение, сигнализирующее о присутствии или отсутствии искомого рейса
     * \param flag Флаг режима: создание, удаление
     */
    void existensBox(int flag);
    //! Функция вызывает предупреждающее сообщение
    void warnBox();
    //! Функция вызывает критическое сообщение
    void critBox();
    /*!
     * \brief Функция проверяет поля ввода на правильность
     * \param flag Флаг режима: создание, удаление
     */
    bool checkFields(int flag);
    //! Вспомогательная функция проверки поля ID рейса
    bool checkIDEdit();
    //! Вспомогательная функция проверки полей пунктов отправления и назначения
    bool checkDepDesEdits();
    //! Вспомогательная функция проверки поля марки судна
    bool checkMarkEdit();
    //! Вспомогательная функция проверки поля количества свободных мест
    bool checkSeatsEdit();
    //! Указатель на объект взаимодействия с базами данных
    DataBases *DBManagePtr;
    //! Указатель на найденный рейс
    Route foundRoute;
    Ui::ManageRoutesWindow *ui;
};

#endif // MANAGEROUTESWINDOW_H
