#include "../../collection/subscriptable_collection.h"
#include "../../abstract/comparable.h"

#include "../../../util/include/mem.h"

#include <initializer_list>
#include <math.h>

using namespace std;

#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector : public SubscriptableCollection<T>, public Comparable<Vector<T>>
{
    int compare(const Vector<T> &v, size_t k) const;

public:
    Vector();
    Vector(size_t size);
    Vector(const char *s);
    Vector(const Vector<T> &v);
    Vector(const std::initializer_list<T> &l);

    ~Vector(){};

    int compare(const Vector<T> &v) const;

    void extend(const Vector<T> &v);

    Vector<char> &operator=(const char *s);
    Vector<T> &operator=(Vector<T> &v);
    Vector<T> &operator=(const std::initializer_list<T> &l);

    Vector<T> operator+(Vector<T>);

    // bool operator<(Vector<T> &v);
    // bool operator<=(Vector<T> &v);
    // bool operator>(Vector<T> &v);
    // bool operator>=(Vector<T> &v);

    friend std::ostream &operator<<(ostream &out, Vector<char> &v);
};

template <class T>
Vector<T>::Vector() : SubscriptableCollection<T>() {}

template <class T>
Vector<T>::Vector(const Vector<T> &v) : SubscriptableCollection<T>(v) {}

template <class T>
Vector<T>::Vector(size_t size) : SubscriptableCollection<T>(size) {}

template <class T>
Vector<T>::Vector(const std::initializer_list<T> &l) : SubscriptableCollection<T>(l) {}

template <class T>
int Vector<T>::compare(const Vector<T> &v) const
{
    return this->compare(v, 0);
}

template <class T>
void Vector<T>::extend(const Vector<T> &v)
{
    long delta = this->current_size + v.get_size() - this->size;
    if (delta > 0)
    {
        this->resize(this->size + delta);
    }

    for (size_t i = 0; i < v.get_size(); i++)
    {
        this->data[i + this->current_size] = v[i];
    }

    this->current_size += v.get_size();
}

template <class T>
Vector<T> &Vector<T>::operator=(Vector<T> &v)
{
    if (this != &v)
    {
        if (this->size < v.size)
        {
            this->resize(v.size);
        }

        this->set_data(v.data, v.size);
    }
    return *this;
}

template <class T>
Vector<T> Vector<T>::operator+(Vector<T> v)
{
    Vector<int> new_vector = *this;
    new_vector.extend(v);

    return new_vector;
}

template <class T>
Vector<T> &Vector<T>::operator=(const std::initializer_list<T> &l)
{
    if (l.size() > this->size)
    {
        this->resize(l.size());
    }

    this->set_data(l);
    return *this;
}

template <class T>
int Vector<T>::compare(const Vector<T> &v, size_t k) const
{
    size_t min_size = min(this->get_size(), v.get_size());

    if(min_size <= k)
    {
        return 0;
    }
    else if (this->data[k] < v.data[k])
    {
        return -1;
    }
    else if (this->data[k] > v.data[k])
    {
        return 1;
    }
    else
    {
        return compare(v, k + 1);
    }

    return 0;
}

#endif