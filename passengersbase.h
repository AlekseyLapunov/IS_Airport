#ifndef PASSENGERSBASE_H
#define PASSENGERSBASE_H

#include <passenger.h>
#include <QList>

class PassengersBase
{
public:
    PassengersBase();

    static void refreshBase(QList<Passenger> &pPassList);
};

#endif // PASSENGERSBASE_H
