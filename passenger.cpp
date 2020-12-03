#include "passenger.h"

Passenger::Passenger()
{
    fullName = "UNDEF UNDEF UNDEF";
    passportInfo = "XXXX YYYYYY";
}

Passenger::Passenger(QString sFullName, string sPassportInfo, int sID)
{
    fullName = sFullName;
    passportInfo = sPassportInfo;
    ID = sID;
    type = idPassenger;
}

QString Passenger::getFullName()
{
    return this->fullName;
}

QString Passenger::getPassport()
{
    return QString::fromStdString(passportInfo);
}
