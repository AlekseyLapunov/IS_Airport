#ifndef ROUTESBASE_H
#define ROUTESBASE_H

#include <QString>
#include <Route.h>
#include <QDataStream>
#include <QList>
#include "QFile"

class RoutesBase
{
public:
    RoutesBase();
    static bool find(int ID, QString fDep, QString fDes,
                     QString fMark, int fSeats, Route &fRoute);
    static bool find(int fID, Route &fRoute);
    static void refreshBase(QList<Route> &pRoutesList);
    static void loadBase(QList<Route> &pRoutesList);
private:
    static void createRouteNote(int ID, QString dep, QString des,
                                QString mark, int seats, QDataStream &qstream);
};

#endif // ROUTESBASE_H
