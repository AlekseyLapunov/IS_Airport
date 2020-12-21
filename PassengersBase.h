#ifndef PASSENGERSBASE_H
#define PASSENGERSBASE_H

#include <Passenger.h>
#include <QList>
#include <QDataStream>

class PassengersBase
{
public:
    PassengersBase();
    static void createPassNote(QString fullName, QString passport, int ID, QDataStream &qstream);
    static bool find(QString fullName, QString passport, Passenger &fPassenger);
    static bool find(int id, Passenger &ptr);
    static bool find(string passportCombination);
    static void refreshBase(QList<Passenger> &pPassList);
    static void loadBase(QList<Passenger> &pPassList);
};

#endif // PASSENGERSBASE_H
