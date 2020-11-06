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
};

template <class T>
PriorityQueue<T>::PriorityQueue()
{
    this->reserve(0);
    this->current_size = 0;
}

template <class T>
PriorityQueue<T>::PriorityQueue(size_t size)
{
    this->reserve(size);
    this->current_size = 0;
}

template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T> &q)
{
    if (this != &q)
    {
        this->reserve(q.size);
        this->set_data(q.data, q.current_size);
    }
}

template <class T>
PriorityQueue<T>::~PriorityQueue()
{
    
}

template <class T>
ssize_t PriorityQueue<T>::search(T elem, ssize_t i, ssize_t j, ssize_t *l)
{
    ssize_t k = (i + j) / 2;

    // if (k >= (ssize_t)this->current_size or k < 0)
    // {
    //     return -1;
    // }

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

        while (k > 0 and this->data[k] == elem and this->data[k-1] == elem)
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
        this->insert(elem, 0);
        return;
    }

    ssize_t l;
    this->search(elem, 0, this->current_size - 1, &l);
    // cout << "l = " << l << endl;
    this->insert(elem, l);
}

#endif