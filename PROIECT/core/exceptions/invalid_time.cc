#include "./include/invalid_time.h"

InvalidTimeError::InvalidTimeError() : Exception("Invalid Time", UNKNOWN_ERROR) 
{
    this->reason = this->get_reason();

    this->get_error();
}

InvalidTimeError::InvalidTimeError(err_code code) : Exception("Invalid Time", code) 
{
    this->reason = this->get_reason();

    this->get_error();
}

std::string InvalidTimeError::get_reason() const noexcept
{
    switch (this->error_code)
    {
    case BAD_TIME_INPUT:
        return "bad time input";
        break;

    case WRONG_TIME_FORMAT:
        return "wrong time format";
        break;
    
    case TIME_OUT_OF_RANGE:
        return "time out of range";
        break;

    default:
        return Exception::get_reason();
    }
}
