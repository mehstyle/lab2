#ifndef VAL_NAME_H
#define VAL_NAME_H
#include "QValidator"
#include <QObject>

class val_name : public QValidator
{
public:
    val_name();
    QValidator::State validate(QString & input, int & pos ) const;
};

#endif // VAL_NAME_H
