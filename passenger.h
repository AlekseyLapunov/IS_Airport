#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include <user.h>
#include <QString>

class Passenger : public User
{
private:

QString fullName;
string passportInfo;

public:


    Passenger();
    Passenger(QString sFullName, string sPassportInfo);
};

#endif // PASSENGER_H
