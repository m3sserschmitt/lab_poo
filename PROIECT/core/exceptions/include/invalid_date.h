#include "exception.h"

#ifndef INVALID_DATE_H
#define INVALID_DATE_H

class InvalidDateError : public Exception
{
public:
    InvalidDateError();
    InvalidDateError(err_code code);

    std::string get_reason() const noexcept;
};

#endif