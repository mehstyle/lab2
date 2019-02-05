#ifndef COUNTRY_H
#define COUNTRY_H
#include "qdatetime.h"
#include "qstring.h"

class Country
{
public:
    Country();
    int id;
    QString NameOfCountry;
    QString NameOfCapital;
    int Population;
    int Area;
    enum World {Europe, Asia, Africa, Australia, North_America, South_America, undefined};
    World continents;
    bool isUN;
    QDate MembershipDate;
    bool isConstUN;

    bool operator==(const Country& right);
    bool operator!=(const Country& right);
    bool operator>(const Country& right);
    bool operator<(const Country& right);
    bool operator>=(const Country& right);
    bool operator<=(const Country& right);
    bool operator=(const Country& right);


};

#endif // COUNTRY_H
