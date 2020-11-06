#include <cstddef>
#include <iostream>

using namespace std;

#ifndef ITERATOR_H
#define ITERATOR_H

template <class T>
class Iterator
{
    T *begin;
    T *end;
    T *pos;

public:
    Iterator(T *begin, T *end, T *pos);

    void next();
    void previous();
    bool out_of_range();

    T &value();
    size_t index();

    bool operator==(Iterator<T>);
    bool operator!=(Iterator<T>);

    bool operator<(Iterator<T>);
    bool operator<=(Iterator<T>);

    bool operator>(Iterator<T>);
    bool operator>=(Iterator<T>);
};

template <class T>
Iterator<T>::Iterator(T *begin, T *end, T *pos)
{
    this->begin = begin;
    this->pos = pos;

    this->end = end;
}

template <class T>
void Iterator<T>::previous()
{
    this->pos--;
}

template <class T>
bool Iterator<T>::out_of_range()
{
    // cout << "this->pos - this->begin" << this->pos - this->begin << endl;
    // cout << "this->pos - this->end" << this->pos - this->end << endl;
    return this->pos < this->begin or this->pos >= this->end;
}

template <class T>
T &Iterator<T>::value()
{
    return *this->pos;
}

template <class T>
size_t Iterator<T>::index()
{
    return this->pos - this->begin;
}

template <class T>
bool Iterator<T>::operator==(Iterator<T> other)
{
    return this->pos == (T *)(&other.value());
}

template <class T>
bool Iterator<T>::operator!=(Iterator<T> other)
{
    return not(*this == other);
}

template <class T>
bool Iterator<T>::operator<(Iterator<T> other)
{
    return this->pos < (T *)(&other.value());
}

template <class T>
bool Iterator<T>::operator<=(Iterator<T> other)
{
    return not(*this > other);
}

template <class T>
bool Iterator<T>::operator>(Iterator<T> other)
{
    return this->pos > (T *)(&other.value());
}

template <class T>
bool Iterator<T>::operator>=(Iterator<T> other)
{
    return not(*this < other);
}

template <class T>
void Iterator<T>::next()
{
    this->pos++;
}

#endif
