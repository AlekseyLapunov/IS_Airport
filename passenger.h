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
    Passenger(QString sFullName, string sPassportInfo, int ID);

    static QString fixFullName(QString sFullName);

    QString getFullName();
    QString getPassport();
};

#endif // PASSENGER_H
