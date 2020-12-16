#include "exception.h"

#ifndef INDEX_ERROR_H
#define INDEX_ERROR_H

class IndexError: public Exception
{
public:
    IndexError();

    std::string get_reason() const noexcept;
};

#endif