#include "../abstract/collection.h"

#ifndef SUBSCRIPTABLE_COLLECTION
#define SUBSCRIPTABLE_COLLECTION

template <class T>
class SubscriptableCollection : public Collection<T>
{
public:
    SubscriptableCollection();
    SubscriptableCollection(size_t size);
    SubscriptableCollection(const SubscriptableCollection<T> &c);
    SubscriptableCollection(const std::initializer_list<T> &l);

    ~SubscriptableCollection() {}

    T get(size_t i);
    virtual ssize_t search(T);
    
    void insert(T elem, size_t i);
    void remove(size_t i);

    T &operator[](size_t i);

    SubscriptableCollection<T> &operator=(SubscriptableCollection<T> &c);
    SubscriptableCollection<T> &operator=(const std::initializer_list<T> &l);

    bool operator==(SubscriptableCollection &c);
    bool operator!=(SubscriptableCollection &c);

    template <class t>
    friend std::ostream &operator<<(std::ostream &out, SubscriptableCollection<t> &c);

    template <class t>
    friend SubscriptableCollection<t> &operator>>(t elem, SubscriptableCollection<t> &c);

    template <class t>
    friend SubscriptableCollection<t> &operator<<(SubscriptableCollection<t> &c, t elem);
};

template <class T>
SubscriptableCollection<T>::SubscriptableCollection() : Collection<T>() {}

template <class T>
SubscriptableCollection<T>::SubscriptableCollection(size_t size) : Collection<T>(size) {}

template <class T>
SubscriptableCollection<T>::SubscriptableCollection(const SubscriptableCollection<T> &c) : Collection<T>(c) {}

template <class T>
SubscriptableCollection<T>::SubscriptableCollection(const std::initializer_list<T> &l) : Collection<T>(l) {}

template <class T>
T SubscriptableCollection<T>::get(size_t i)
{
    return this->data[i];
}

template <class T>
ssize_t SubscriptableCollection<T>::search(T elem)
{
    Iterator<T> it = this->begin();

    for (; not it.out_of_range(); it.next())
    {
        if (it.value() == elem)
        {
            return it.index();
        }
    }

    return -1;
}

template <class T>
void SubscriptableCollection<T>::insert(T elem, size_t i)
{
    long delta = this->current_size + 1 - this->size;
    if (delta > 0)
    {
        this->resize(this->size + delta);
    }

    this->memory_shift_right(this->data + i);
    this->data[i] = elem;
    this->current_size++;
}

template <class T>
void SubscriptableCollection<T>::remove(size_t i)
{
    this->memory_shift_left(this->data + i + 1);
    this->current_size--;
}

template <class T>
T &SubscriptableCollection<T>::operator[](size_t i)
{
    return this->data[i];
}

template <class T>
SubscriptableCollection<T> &SubscriptableCollection<T>::operator=(SubscriptableCollection<T> &c)
{
    if (this != &c)
    {
        if (this->size < c.size)
        {
            this->resize(c.size);
        }

        this->set_data(c.data, c.size);
    }

    return *this;
}

template <class T>
SubscriptableCollection<T> &SubscriptableCollection<T>::operator=(const std::initializer_list<T> &l)
{
    if (this->size < l.size())
    {
        this->resize(l.size());
    }

    this->set_data(l);

    return *this;
}

template <class T>
bool SubscriptableCollection<T>::operator==(SubscriptableCollection<T> &q)
{
    if (this->get_size() != q.get_size())
    {
        return false;
    }

    Iterator<T> u = this->begin();
    Iterator<T> v = q.begin();

    for (; not u.out_of_range(); u.next(), v.next())
    {
        if (u.value() != v.value())
        {
            return false;
        }
    }

    return true;
}

template <class T>
bool SubscriptableCollection<T>::operator!=(SubscriptableCollection<T> &q)
{
    return not((*this) == q);
}

template <class t>
std::ostream &operator<<(std::ostream &out, SubscriptableCollection<t> &c)
{
    Iterator<t> it = c.begin();
    Iterator<t> it_end = c.end();

    out << "{";
    for (it_end.previous(); it < it_end; it.next())
    {
        out << it.value() << ", ";
    }

    if (not c.is_empty())
    {
        out << it_end.value();
    }

    out << "}";

    return out;
}

template <class t>
SubscriptableCollection<t> &operator>>(t elem, SubscriptableCollection<t> &c)
{
    c.insert(elem, 0);
    return c;
}

template <class t>
SubscriptableCollection<t> &operator<<(SubscriptableCollection<t> &c, t elem)
{
    c.add(elem);
    return c;
}

#endif