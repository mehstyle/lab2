#include "val_name.h"
#include "QValidator"
#include <QObject>

val_name::val_name()
{

}

QValidator::State val_name::validate (QString & input, int & pos ) const
{
QChar a;

if(pos>41)
{
    return QValidator::Invalid;
}

if (pos>0)
{
    a=input[pos-1];
    if(pos>1)
        {
            if(a.isLetter() || a.isSpace())
            {
                return QValidator::Acceptable;
            }
            else
            {
                return QValidator::Invalid;
            }

        }
        else
        {
            if(a.isUpper())
            {
               return QValidator::Intermediate;
            }
            else
            {
               return QValidator::Invalid;
            }

        }
}
    else
    {
        return QValidator::Intermediate;
    }

}
