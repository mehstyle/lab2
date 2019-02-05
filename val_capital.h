#ifndef VAL_CAPITAL_H
#define VAL_CAPITAL_H
#include "QValidator"
#include <QObject>


class val_capital : public QValidator
{
public:
    val_capital();
    QValidator::State validate(QString & input, int & pos ) const;
};

#endif // VAL_CAPITAL_H
