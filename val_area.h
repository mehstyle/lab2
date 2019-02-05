#ifndef VAL_AREA_H
#define VAL_AREA_H
#include "QValidator"
#include <QObject>

class val_area : public QValidator
{
public:
    val_area();
    QValidator::State validate(QString & input, int & pos ) const;
};

#endif // VAL_AREA_H
