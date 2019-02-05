#include "val_capital.h"
#include "QValidator"
#include <QObject>

val_capital::val_capital()
{

}

QValidator::State val_capital::validate (QString & input, int & pos ) const
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
                if(a.isLetter())
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
