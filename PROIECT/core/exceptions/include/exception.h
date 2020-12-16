#include <exception>
#include <string>

#ifndef EXCEPTION_H
#define EXCEPTION_H

enum err_code
{
    UNKNOWN_ERROR = -0x01,

    BAD_DATE_INPUT = 0x01,
    WRONG_DATE_FORMAT = 0x02,
    DATE_OUT_OF_RANGE = 0x03,

    BAD_TIME_INPUT = 0x04,
    WRONG_TIME_FORMAT = 0x05,
    TIME_OUT_OF_RANGE = 0x06,

    INDEX_OUT_OF_RANGE = 0x10
};

class Exception : public std::exception
{
protected:
    std::string error_message;

    err_code error_code;
    std::string type;
    std::string reason;

    void get_error();

public:
    Exception();
    Exception(std::string type);
    Exception(std::string type, err_code code);

    virtual const char *what() const noexcept;
    virtual std::string get_reason() const noexcept;

    err_code get_error_code() const noexcept;
    std::string get_error_message() const noexcept;
    std::string get_type() const noexcept;
};

#endif