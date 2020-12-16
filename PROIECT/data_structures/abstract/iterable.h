#include "iterator.h"

#ifndef ITERABLE_H
#define ITERABLE_H

template <class T>
class Iterable
{
public:
    virtual Iterator<T> begin() const = 0;
    virtual Iterator<T> end() const = 0;
};

#endif