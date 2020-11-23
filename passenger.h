#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include <user.h>

class Passenger : public User
{
private:

string fullName;
string passportInfo;

public:


    Passenger();
};

#endif // PASSENGER_H
