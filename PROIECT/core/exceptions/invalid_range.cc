#include "./include/invalid_range.h"

InvalidDateRange::InvalidDateRange(): Exception("Invalid date range", UNKNOWN_ERROR)
{
    this->reason = this->get_reason();

    this->get_error();
}

InvalidDateRange::InvalidDateRange(err_code code): Exception("Invalid date range", code)
{
    this->reason = this->get_reason();

    this->get_error();
}

std::string InvalidDateRange::get_reason() const noexcept
{
    switch (this->error_code)
    {
    case BAD_RANGE_LIMITS:
        return "starting date after ending date";
        break;
    
    default:
        return Exception::get_reason();
        break;
    }
}