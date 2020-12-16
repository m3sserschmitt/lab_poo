#include "../../abstract/comparable.h"
#include "queue.h"

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

template <class T>
class PriorityQueue : public Queue<T>
{
protected:
    ssize_t search(T elem, ssize_t i, ssize_t j, ssize_t *l);

public:
    PriorityQueue();
    PriorityQueue(size_t size);
    PriorityQueue(const PriorityQueue<T> &q);

    ~PriorityQueue();

    ssize_t search(T elem);

    void add(T elem);
    // size_t enqueue(T elem);

    const T &operator[](size_t index);

    PriorityQueue<T> &operator=(PriorityQueue<T> &q);

    template <class t>
    friend SubscriptableCollection<t> &operator>>(t elem, SubscriptableCollection<t> &c);

    template <class t>
    friend SubscriptableCollection<t> &operator<<(SubscriptableCollection<t> &c, t elem);
};

template <class T>
PriorityQueue<T>::PriorityQueue() : Queue<T>() {}

template <class T>
PriorityQueue<T>::PriorityQueue(size_t size) : Queue<T>(size) {}

template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T> &q) : Queue<T>(q) {}

template <class T>
PriorityQueue<T>::~PriorityQueue() {}

template <class T>
ssize_t PriorityQueue<T>::search(T elem, ssize_t i, ssize_t j, ssize_t *l)
{
    ssize_t k = (i + j) / 2;

    if (i >= j)
    {
        if (l)
        {
            *l = k + (elem > this->data[k]);
        }

        return elem == this->data[k] ? k : -1;
    }
    else if (elem < this->data[k])
    {
        return this->search(elem, i, k, l);
    }
    else if (elem > this->data[k])
    {
        return this->search(elem, k + 1, j, l);
    }
    else
    {
        if (l)
        {
            *l = k + 1;
        }

        while (k > 0 and this->data[k] == elem and this->data[k - 1] == elem)
        {
            k--;
        }

        return k;
    }
}

template <class T>
ssize_t PriorityQueue<T>::search(T elem)
{
    return this->search(elem, 0, this->current_size - 1, NULL);
}

template <class T>
void PriorityQueue<T>::add(T elem)
{
    if (not this->current_size)
    {
        SubscriptableCollection<T>::insert(elem, 0);
        return;
    }

    ssize_t l;
    this->search(elem, 0, this->current_size - 1, &l);
    SubscriptableCollection<T>::insert(elem, l);
}

// template <class T>
// size_t PriorityQueue<T>::enqueue(T elem)
// {
//     this->add(elem);
//     return this->get_size();
// }

template <class T>
const T &PriorityQueue<T>::operator[](size_t index)
{
    return this->data[index];
}

template <class T>
PriorityQueue<T> &PriorityQueue<T>::operator=(PriorityQueue<T> &q)
{
    if (this != &q)
    {
        if (q.size > this->size)
        {
            this->resize(q.size);
        }

        this->set_data(q.data, q.size);
    }

    return *this;
}

template <class t>
PriorityQueue<t> &operator>>(t elem, PriorityQueue<t> &c)
{
    c.add(elem);
    return c;
}

template <class t>
PriorityQueue<t> &operator<<(PriorityQueue<t> &c, t elem)
{
    c.add(elem);
    return c;
}


#endif