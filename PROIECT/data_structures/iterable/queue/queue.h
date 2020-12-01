#include "../../collection/subscriptable_collection.h"

#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue : public SubscriptableCollection<T>
{
protected:
    void extend(Queue<T> q);

public:
    Queue();
    Queue(size_t size);
    Queue(const Queue<T> &q);
    Queue(const std::initializer_list<T> &l);

    ~Queue();

    size_t enqueue(T elem);
    T dequeue();

    void insert(T elem);
    void remove();

    Queue<T> &operator=(Queue<T> &q);
};

template <class T>
Queue<T>::Queue() : SubscriptableCollection<T>() {}

template <class T>
Queue<T>::Queue(size_t size) : SubscriptableCollection<T>(size) {}

template <class T>
Queue<T>::Queue(const Queue<T> &q) : SubscriptableCollection<T>(q) {}

template <class T>
Queue<T>::Queue(const std::initializer_list<T> &l) : SubscriptableCollection<T>(l) {}

template <class T>
Queue<T>::~Queue() {}

template <class T>
size_t Queue<T>::enqueue(T elem)
{
    this->add(elem);
    return this->get_size();
}

template <class T>
T Queue<T>::dequeue()
{
    T elem = this->data[0];
    this->remove(0);

    return elem;
}

template <class T>
void Queue<T>::insert(T elem)
{
    this->add(elem);
}

template<class T>
void Queue<T>::remove()
{
    SubscriptableCollection<T>::remove(0);
}

template <class T>
Queue<T> &Queue<T>::operator=(Queue<T> &q)
{
    if(this != &q)
    {
        if(q.size > this->size)
        {
            this->resize(q.size);
        }

        this->set_data(q.data, q.size);
    }

    return *this;
}

#endif