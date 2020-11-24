#include "passenger.h"

Passenger::Passenger()
{
    fullName = "UNDEF UNDEF UNDEF";
    passportInfo = "XXXX YYYYYY";
}

Passenger::Passenger(QString sFullName, string sPassportInfo)
{
    fullName = sFullName;
    passportInfo = sPassportInfo;
}
