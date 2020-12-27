#include "exception.h"

#ifndef INVALID_RANGE_H
#define INVALID_RANGE_H

class InvalidDateRange: public Exception
{
public:
    InvalidDateRange();
    InvalidDateRange(err_code code);

    std::string get_reason() const noexcept;
};

#endif