#include "./include/index_error.h"

IndexError::IndexError() : Exception("Index Error", INDEX_OUT_OF_RANGE) {}

std::string IndexError::get_reason() const noexcept
{
    return "index out of range";
}