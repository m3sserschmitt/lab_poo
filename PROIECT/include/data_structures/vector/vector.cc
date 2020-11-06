#include "vector.h"

template <>
Vector<char>::Vector(const char *s)
{
    this->reserve(strlen(s));
    (*this) = s;
}

std::ostream &operator<<(std::ostream &out, Vector<char> s)
{
    Iterator<char> it = s.begin();
    for (; not it.out_of_range(); it.next())
    {
        out << it.value();
    }

    return out;
}