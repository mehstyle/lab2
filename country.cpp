#include "country.h"
#include "qstring.h"


Country::Country()
{
    NameOfCountry="Название страны";
    NameOfCapital="Название столицы";
    Population=0;
    Area=0;
    continents=undefined;
    isUN=false;
    MembershipDate.setDate(1945,5,9);
    isConstUN=false;
}


bool Country::operator==(const Country& right) {
   if(this->continents==right.continents && this->NameOfCountry == right.NameOfCountry)
   {
       return true;
   }
   else
   {
       return false;
   }

}

bool Country::operator!=(const Country& right) {
   if(this->continents==right.continents && this->NameOfCountry == right.NameOfCountry)
   {
       return false;
   }
   else
   {
       return true;
   }

}

bool Country::operator>(const Country& right){
    int tmp1;
    int tmp2;
    switch ( this->continents )
         {
            case Country::Europe:
               tmp1=0;
               break;
            case Country::Asia:
               tmp1=1;
               break;
            case Country::Africa:
               tmp1=2;
               break;
            case Country::Australia:
               tmp1=3;
               break;
            case Country::North_America:
               tmp1=4;
               break;
            case Country::South_America:
               tmp1=5;
               break;
            case Country::undefined:
               tmp1=7;
               break;
        }
    switch ( right.continents )
         {
            case Country::Europe:
               tmp2=0;
               break;
            case Country::Asia:
               tmp2=1;
               break;
            case Country::Africa:
               tmp2=2;
               break;
            case Country::Australia:
               tmp2=3;
               break;
            case Country::North_America:
               tmp2=4;
               break;
            case Country::South_America:
               tmp2=5;
               break;
            case Country::undefined:
               tmp2=7;
               break;
        }
    if(tmp1 == tmp2)
    {
        QString asd=right.NameOfCountry;
        if(QString::localeAwareCompare(this->NameOfCountry, &right.NameOfCountry)<0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(tmp1 < tmp2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Country::operator<(const Country& right){
    int tmp1;
    int tmp2;
    switch ( this->continents )
         {
            case Country::Europe:
               tmp1=0;
               break;
            case Country::Asia:
               tmp1=1;
               break;
            case Country::Africa:
               tmp1=2;
               break;
            case Country::Australia:
               tmp1=3;
               break;
            case Country::North_America:
               tmp1=4;
               break;
            case Country::South_America:
               tmp1=5;
               break;
            case Country::undefined:
               tmp1=7;
               break;
        }
    switch ( right.continents )
         {
            case Country::Europe:
               tmp2=0;
               break;
            case Country::Asia:
               tmp2=1;
               break;
            case Country::Africa:
               tmp2=2;
               break;
            case Country::Australia:
               tmp2=3;
               break;
            case Country::North_America:
               tmp2=4;
               break;
            case Country::South_America:
               tmp2=5;
               break;
            case Country::undefined:
               tmp2=7;
               break;
        }
    if(tmp1 == tmp2)
    {
        QString asd=right.NameOfCountry;
        if(QString::localeAwareCompare(this->NameOfCountry, &right.NameOfCountry)>0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(tmp1 > tmp2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Country::operator<=(const Country& right){
    int tmp1;
    int tmp2;
    switch ( this->continents )
         {
            case Country::Europe:
               tmp1=0;
               break;
            case Country::Asia:
               tmp1=1;
               break;
            case Country::Africa:
               tmp1=2;
               break;
            case Country::Australia:
               tmp1=3;
               break;
            case Country::North_America:
               tmp1=4;
               break;
            case Country::South_America:
               tmp1=5;
               break;
            case Country::undefined:
               tmp1=7;
               break;
        }
    switch ( right.continents )
         {
            case Country::Europe:
               tmp2=0;
               break;
            case Country::Asia:
               tmp2=1;
               break;
            case Country::Africa:
               tmp2=2;
               break;
            case Country::Australia:
               tmp2=3;
               break;
            case Country::North_America:
               tmp2=4;
               break;
            case Country::South_America:
               tmp2=5;
               break;
            case Country::undefined:
               tmp2=7;
               break;
        }
    if(tmp1 == tmp2)
    {
        QString asd=right.NameOfCountry;
        if(QString::localeAwareCompare(this->NameOfCountry, &right.NameOfCountry)<0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(tmp1 < tmp2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Country::operator>=(const Country& right){
    int tmp1;
    int tmp2;
    switch ( this->continents )
         {
            case Country::Europe:
               tmp1=0;
               break;
            case Country::Asia:
               tmp1=1;
               break;
            case Country::Africa:
               tmp1=2;
               break;
            case Country::Australia:
               tmp1=3;
               break;
            case Country::North_America:
               tmp1=4;
               break;
            case Country::South_America:
               tmp1=5;
               break;
            case Country::undefined:
               tmp1=7;
               break;
        }
    switch ( right.continents )
         {
            case Country::Europe:
               tmp2=0;
               break;
            case Country::Asia:
               tmp2=1;
               break;
            case Country::Africa:
               tmp2=2;
               break;
            case Country::Australia:
               tmp2=3;
               break;
            case Country::North_America:
               tmp2=4;
               break;
            case Country::South_America:
               tmp2=5;
               break;
            case Country::undefined:
               tmp2=7;
               break;
        }
    if(tmp1 == tmp2)
    {
        QString asd=right.NameOfCountry;
        if(QString::localeAwareCompare(this->NameOfCountry, &right.NameOfCountry)<0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(tmp1 < tmp2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Country::operator=(const Country& right){
    this->NameOfCountry=right.NameOfCountry;
    this->NameOfCapital=right.NameOfCapital;
    this->Population=right.Population;
    this->Area=right.Area;
    this->continents=right.continents;
    this->isUN=right.isUN;
    this->MembershipDate=right.MembershipDate;
    this->isConstUN=right.isConstUN;

}

