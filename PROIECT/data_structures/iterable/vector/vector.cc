#include "vector.h"

template <>
Vector<char>::Vector(const char *s)
{
    this->reserve(strlen(s) + 1);
    strcpy(this->data, s);
}

std::ostream &operator<<(std::ostream &out, Vector<char> &v)
{
    out << v.data;
    return out;
}

template <>
Vector<char> &Vector<char>::operator=(const char *s)
{
    size_t len = strlen(s);
    if(len > this->size)
    {
        this->resize(len);
    }

    strcpy(this->data, s);

    return *this;
}