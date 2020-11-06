#include "data_structures/container/collection.h"
#include "util/mem.h"

#include <initializer_list>
#include <math.h>

using namespace std;

#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector : public Collection<T>
{
    int compare(Vector<T> u, Vector<T> v, size_t k);
public:
    Vector();
    Vector(size_t size);
    Vector(const Vector<T> &);

    Vector(const char *);
    Vector(T *s, size_t size);
    Vector(std::initializer_list<T> v);

    ~Vector();

    void extend(Vector<T> v);

    T &operator[](long);
    void operator=(const T *);
    void operator=(std::initializer_list<T>);
    Vector<T> operator+(Vector<T>);

    bool operator<(Vector<T>);
    bool operator<=(Vector<T>);
    bool operator>(Vector<T>);
    bool operator>=(Vector<T>);
    bool operator==(Vector<T>);
    bool operator!=(Vector<T>);

    template <class t>
    friend void operator>>(t, Vector<t> &);

    friend std::ostream &operator<<(ostream &, Vector<char>);
};

template <class T>
Vector<T>::Vector()
{
    this->reserve(0);
    this->current_size = 0;
}

template <class T>
Vector<T>::Vector(const Vector<T> &v)
{
    if (this != &v)
    {
        this->reserve(v.size);
        this->set_data(v.data, v.current_size);
    }
}

template <class T>
Vector<T>::Vector(size_t size)
{
    this->reserve(size);
    this->current_size = 0;
}

template <class T>
Vector<T>::Vector(T *s, size_t size)
{
    this->reserve(size);
    (*this) = s;
}

template <class T>
Vector<T>::Vector(std::initializer_list<T> s)
{
    this->reserve(s.size());
    (*this) = s;
}

template <class T>
Vector<T>::~Vector()
{

}

template <class T>
void Vector<T>::extend(Vector<T> v)
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
T &Vector<T>::operator[](long i)
{
    if (i < 0)
    {
        if ((unsigned)(-1 * i) > this->current_size)
        {
            throw "Error: vector index out of range.";
        }

        i = this->current_size + i;
    }

    this->current_size = max(this->current_size, (size_t)i + 1);

    return this->data[i];
}

template <class T>
void Vector<T>::operator=(const T *s)
{
    this->set_data((T *)s, this->size);
}

template <class T>
Vector<T> Vector<T>::operator+(Vector<T> v)
{
    Vector<int> new_vector = v;
    new_vector.extend(*this);

    return new_vector;
}

template <class T>
void Vector<T>::operator=(std::initializer_list<T> s)
{
    long delta = s.size() - this->get_size();

    if (delta > 0)
    {
        this->resize(this->size + delta);
    }
    
    this->set_data(s);
}

template <class T>
int Vector<T>::compare(Vector<T> v1, Vector<T> v2, size_t k)
{
    size_t min_size = min(v1.get_size(), v2.get_size());

    if (v1[k] < v2[k])
    {
        return -1;
    }
    else if (v1[k] > v2[k])
    {
        return 1;
    }
    else
    {
        return min_size == k ? 0 : compare(v1, v2, k + 1);
    }
}

template <class T>
bool Vector<T>::operator<(Vector<T> v)
{
    return this->compare(*this, v, 0) < 0;
}

template <class T>
bool Vector<T>::operator<=(Vector<T> v)
{
    return not(*this > v);
}

template <class T>
bool Vector<T>::operator>(Vector<T> v)
{
    return this->compare(*this, v, 0) > 0;
}

template <class T>
bool Vector<T>::operator>=(Vector<T> v)
{
    return not(*this < v);
}

template <class T>
bool Vector<T>::operator==(Vector<T> v)
{
    if (this->get_size() != v.get_size())
    {
        return false;
    }

    Iterator<T> this_it = this->begin();
    Iterator<T> v_it = v.begin();

    for (; not this_it.out_of_range(); this_it.next())
    {
        if (this_it.value() != v_it.value())
        {
            return false;
        }
    }

    return true;
}

template <class T>
bool Vector<T>::operator!=(Vector<T> v)
{
    return not(*this == v);
}

template <class t>
void operator>>(t elem, Vector<t> &v)
{
    v.insert(elem, 0);
}


#endif