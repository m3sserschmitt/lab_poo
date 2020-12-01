#include "iterator.h"

#ifndef COMPARABLE_H
#define COMPARABLE_H

template <class T>
class Comparable
{
public:
    virtual int compare(T *) = 0;
};

#endif