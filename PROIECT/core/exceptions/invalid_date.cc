#include "./include/invalid_date.h"

InvalidDateError::InvalidDateError() : Exception("Invalid date", UNKNOWN_ERROR)
{
    this->reason = this->get_reason();

    this->get_error();
}

InvalidDateError::InvalidDateError(err_code code) : Exception("Invalid date", code)
{
    this->reason = this->get_reason();

    this->get_error();
}

std::string InvalidDateError::get_reason() const noexcept
{
    switch (this->error_code)
    {
    case BAD_DATE_INPUT:
        return "bad date input";
        break;

    case WRONG_DATE_FORMAT:
        return "wrong date format";
        break;

    case DATE_OUT_OF_RANGE:
        return "date out of range";
        break;
        
    default:
        return "unknown";
        break;
    }
}
