#include "./include/exception.h"

#include <sstream>
#include <iostream>
#include <iomanip>

Exception::Exception() : std::exception()
{
    this->error_code = UNKNOWN_ERROR;
    this->type = "Exception";
    this->reason = this->get_reason();

    this->get_error();
}

Exception::Exception(std::string type) : std::exception()
{
    this->error_code = UNKNOWN_ERROR;
    this->type = type;
    this->reason = this->get_reason();

    this->get_error();
}

Exception::Exception(std::string type, err_code code) : std::exception()
{
    this->error_code = code;
    this->type = type;
    this->reason = this->get_reason();

    this->get_error();
}

/*
Exception::Exception(std::string type, std::string reason)
{

}
*/

void Exception::get_error()
{
    std::stringstream ss;

    ss << this->type << ": "
       << this->reason
       << " (error code: " 
       << std::showbase
       << std::internal
       << std::setfill('0')
       << std::setw(4)
       << std::hex 
       << this->error_code << ").";

    this->error_message = ss.str();
}

const char *Exception::what() const noexcept
{
    return this->error_message.c_str();
}

std::string Exception::get_error_message() const noexcept
{
    return this->error_message;
}

err_code Exception::get_error_code() const noexcept
{
    return this->error_code;
}

std::string Exception::get_reason() const noexcept
{
    return "unknown";
}

std::string Exception::get_type() const noexcept
{
    return this->type;
}
