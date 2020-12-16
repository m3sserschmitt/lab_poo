#include "exception.h"

#ifndef INVALID_TIME_H
#define INVALID_TIME_H

class InvalidTimeError : public Exception
{
public:
    InvalidTimeError();
    InvalidTimeError(err_code code);

    std::string get_reason() const noexcept;
};

#endif