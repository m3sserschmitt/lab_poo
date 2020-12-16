#include "iterator.h"

#ifndef COMPARABLE_H
#define COMPARABLE_H

template <class T>
class Comparable
{
public:
    virtual int compare(const T &) const = 0;

    template <class t> friend bool operator<(const t &, const t &);
    template <class t> friend bool operator>(const t &, const t &);
    template <class t> friend bool operator<=(const t &, const t &);
    template <class t> friend bool operator>=(const t &, const t &);
    template <class t> friend bool operator==(const t &, const t &);
    template <class t> friend bool operator!=(const t &, const t &);
};

template <class t>
bool operator<(const t &c1, const t &c2)
{
    return c1.compare(c2) < 0;
}

template <class t>
bool operator>(const t &c1, const t &c2)
{
    return c1.compare(c2) > 0;
}

template <class t>
bool operator<=(const t &c1, const t &c2)
{
    return not (c1 > c2);
}

template <class t>
bool operator>=(const t &c1, const t &c2)
{
    return not (c1 < c2);
}

template <class t>
bool operator==(const t &c1, const t &c2)
{
    return not c1.compare(c2);
}

template <class t>
bool operator!=(const t &c1, const t &c2)
{
    return not (c1 == c2);
}

#endif