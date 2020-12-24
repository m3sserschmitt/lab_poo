#include "./include/index_error.h"

IndexError::IndexError() : Exception("Index Error", INDEX_OUT_OF_RANGE)
{
    this->reason = this->get_reason();

    this->get_error();
}

std::string IndexError::get_reason() const noexcept
{
    return "index out of range";
}