#ifndef PASSESVIEWWINDOW_H
#define PASSESVIEWWINDOW_H

#include <QDialog>
#include <QStandardItemModel>
#include <DataBases.h>
#include <Passenger.h>
#include <string>
#include <QString>
#include <QList>
#include <QMessageBox>
#include <EditPassWindow.h>

namespace Ui {
class PassesViewWindow;
}

/*!
 * \brief Класс окна просмотра пассажиров
 *
 * Отображает всех пассажиров ИС
 */
class PassesViewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PassesViewWindow(QWidget *parent = nullptr);
    ~PassesViewWindow();

    /*!
     * \brief Функция получения указателя на объект взаимодействия с базами данных
     * \param DBPointer Указатель на объект взаимодействия с базами данных
     */
    void giveDBManagerPtr(DataBases *DBPointer);
    /*!
     * \brief Функция получения указателя список пассажиров
     * \param sPassListPtr Указатель на список пассажиров
     */
    void giveListPtr(QList<Passenger> *sPassListPtr);
    /*!
     * \brief Функция заполнения таблицы пассажиров
     * \param def Логический флаг, отвечающий за применение фильтра при заполнении таблицы
     */
    void fillTable(bool def = 1);

private slots:
    //! Слот редактирования выделенного пассажира
    void editPass(QModelIndex);
    //! Слот применения фильтра
    void startFilter();

private:
    //! Функция обновляет список пассажиров на отображение
    void refreshListPtr();
    //! Указатель на объект взаимодействия с базами данных
    DataBases *DBManagerPtr;
    //! Указатель на список пассажиров для отображения
    QList<Passenger> passesToShow;
    //! Указатель на список пассажиров (от главного окна)
    QList<Passenger> *passesListPtr;
    //! Указатель на найденного пассажира
    Passenger passFound;
    //! Флаг, сигнализирующий о том, изменился ли пассажир
    bool passChanged;
    //! Окно редактирования информации пассажира
    EditPassWindow editPassWindow;
    QStandardItemModel *table;
    Ui::PassesViewWindow *ui;

};

#endif // PASSESVIEWWINDOW_H
