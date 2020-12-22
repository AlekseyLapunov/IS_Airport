#ifndef ROUTESVIEWWINDOW_H
#define ROUTESVIEWWINDOW_H

#include <QDialog>
#include <DataBases.h>
#include <Route.h>
#include <QStandardItemModel>

namespace Ui {
class RoutesViewWindow;
}

/*!
 * \brief Класс окна просмотра рейсов
 *
 * Отображает все доступные рейсы ИС
 */
class RoutesViewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RoutesViewWindow(QWidget *parent = nullptr);
    ~RoutesViewWindow();
    /*!
     * \brief Функция получения указателя на объект взаимодействия с базами данных
     * \param DBPointer Указатель на объект взаимодействия с базами данных
     */
    void giveDBManagerPtr(DataBases *DBPointer);
    /*!
     * \brief Функция получения указателя список рейсов
     * \param sRouteListPtr Указатель на список рейсов
     */
    void giveListPtr(QList<Route> *sRouteListPtr);
    /*!
     * \brief Функция заполнения таблицы рейсов
     * \param def Логический флаг, отвечающий за применение фильтра при заполнении таблицы
     */
    void fillTable(bool def = true);

private slots:
    //! Слот применения фильтра
    void startFilter();

private:
    //! Функция обновляет список рейсов на отображение
    void refreshListPtr();
    //! Указатель на объект взаимодействия с базами данных
    DataBases *DBManagerPtr;
    //! Список рейсов на отображение
    QList<Route> routesToShow;
    //! Указатель на список рейсов (От главного окна)
    QList<Route> *routesListPtr;
    QStandardItemModel *table;
    Ui::RoutesViewWindow *ui;
};

#endif // ROUTESVIEWWINDOW_H
