#ifndef NAMEVALIDATOR_H
#define NAMEVALIDATOR_H
#include"QValidator"

class NameValidator : public QValidator
{
public:
    NameValidator();
    QValidator::State validate(QString & input, int & pos ) const;
};

#endif // NAMEVALIDATOR_H
