#include "data_structures/container/collection.h"

#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue : public Collection<T>
{
public:
    Queue();
    Queue(size_t size);
    Queue(const Queue<T> &q);
    Queue(std::initializer_list<T> l);

    ~Queue();

    T remove();

    template <class t>
    friend Queue<t> &operator>>(Queue<t> &, t &);

    template <class t>
    friend Queue<t> &operator<<(t &, Queue<t> &);
};

template <class T>
Queue<T>::Queue()
{
    this->reserve(0);
    this->current_size = 0;
}

template <class T>
Queue<T>::Queue(size_t size)
{
    this->reserve(size);
    this->current_size = 0;
}

template <class T>
Queue<T>::Queue(const Queue<T> &q)
{
    if (this != &q)
    {
        this->reserve(q.size);
        this->set_data(q.data, q.current_size);
    }
}

template <class T>
Queue<T>::Queue(std::initializer_list<T> l)
{
    this->reserve(l.size());
    this->set_data(l);
}

template <class T>
Queue<T>::~Queue()
{
    
}

template <class T>
T Queue<T>::remove()
{
    T elem = this->data[0];

    this->memory_shift_left(this->data + 1);
    memset(this->data + this->current_size - 1, 0, sizeof(T));
    this->current_size--;

    return elem;
}

template <class t>
Queue<t> &operator>>(Queue<t> &q, t &elem)
{
    elem = q.remove();
    return q;
}

template <class t>
Queue<t> &operator<<(t &elem, Queue<t> &q)
{
    elem = q.remove();
    return q;
}

#endif