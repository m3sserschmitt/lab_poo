#include "../container/collection.h"

#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue : public Collection<T>
{
protected:
    void extend(Queue<T> q);
public:
    Queue();
    Queue(size_t size);
    Queue(const Queue<T> &q);
    Queue(std::initializer_list<T> l);

    ~Queue();

    void enqueue(T elem);
    T dequeue();

    // T remove();

    bool operator==(Queue<T>);
    bool operator!=(Queue<T>);

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
/*
template <class T>
void Queue<T>::extend(Queue<T> q)
{
    long delta = this->current_size + q.get_size() - this->size;
    if (delta > 0)
    {
        this->resize(this->size + delta);
    }

    for(size_t i = 0; i < q.get_size(); i ++)
    {
        this->data[i + this->current_size] = q[i];
    }

    this->current_size += q.get_size();
}
*/
template <class T>
T Queue<T>::dequeue()
{

    T elem = this->data[0];

    this->remove(0);
    // this->memory_shift_left(this->data + 1);
    // this->current_size--;

    return elem;
}

/*
template <class T>
Queue<T> Queue<T>::operator+(T elem)
{
    Queue<T> new_queue = *this;
    new_queue.add(elem);

    return new_queue;
}
*/

template <class T>
bool Queue<T>::operator==(Queue<T> q)
{
    if(this->get_size() != q.get_size())
    {
        return false;
    }

    Iterator<T> u = this->begin();
    Iterator<T> v = q.begin();

    for(; not u.out_of_range(); u.next())
    {
        if(u.value() != v.value())
        {
            return false;
        }
    }

    return true;
}

template <class T>
bool Queue<T>::operator!=(Queue<T> q)
{
    return not ((*this) == q);
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