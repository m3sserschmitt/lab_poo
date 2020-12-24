#include "comparable.h"

#include <cstddef>
#include <iostream>

using namespace std;

#ifndef ITERATOR_H
#define ITERATOR_H

template <class T>
class Iterator : public Comparable<Iterator<T>>
{
    T *begin;
    T *end;
    T *pos;

public:
    Iterator(T *begin, T *end, T *pos);
    ~Iterator();

    int compare(const Iterator<T> &) const;

    Iterator<T> &next();
    Iterator<T> &previous();
    bool out_of_range() const;

    T &value() const;
    size_t index() const;

    Iterator<T> get_begin() const;
    Iterator<T> get_end() const;

    Iterator<T> &operator=(const Iterator<T> &);
};

template <class T>
Iterator<T>::~Iterator() {}

template <class T>
Iterator<T>::Iterator(T *begin, T *end, T *pos)
{
    this->begin = begin;
    this->pos = pos;

    this->end = end;
}

template <class T>
int Iterator<T>::compare(const Iterator<T> &other) const
{
    return this->pos - other.pos;
}

template <class T>
Iterator<T> &Iterator<T>::next()
{
    this->pos++;
    return *this;
}

template <class T>
Iterator<T> &Iterator<T>::previous()
{
    this->pos--;
    return *this;
}

template <class T>
bool Iterator<T>::out_of_range() const
{
    return this->pos < this->begin or this->pos >= this->end;
}

template <class T>
T &Iterator<T>::value() const
{
    return *this->pos;
}

template <class T>
size_t Iterator<T>::index() const
{
    return this->pos - this->begin;
}

template <class T>
Iterator<T> Iterator<T>::get_begin() const
{
    return Iterator<T>(begin, end, begin);
}

template <class T>
Iterator<T> Iterator<T>::get_end() const
{
    return Iterator<T>(begin, end, end);
}

template <class T>
Iterator<T> &Iterator<T>::operator=(const Iterator<T> &it)
{
    if (this != &it)
    {
        this->begin = it.begin;
        this->end = it.end;
        this->pos = it.pos;
    }

    return *this;
}

#endif
