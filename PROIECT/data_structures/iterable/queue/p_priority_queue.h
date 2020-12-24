#include "priority_queue.h"

#ifndef P_PRIORITY_QUEUE_H
#define P_PRIORITY_QUEUE_H

template <typename T>
class PriorityQueue<T *> : public Queue<T *>
{
protected:
    ssize_t search(T *elem, ssize_t i, ssize_t j, ssize_t *l) const;
public:
    PriorityQueue();
    PriorityQueue(size_t size);
    PriorityQueue(const PriorityQueue<T *> &q);

    ~PriorityQueue(){};

    ssize_t search(T *elem) const;
    void add(T *elem);
    void remove(size_t index);

    const T *operator[](size_t index);
    PriorityQueue<T *> &operator=(const PriorityQueue<T *> &q);

    template <class t>
    friend ostream &operator<<(ostream &out, const PriorityQueue<t *> &q);
};

template <typename T>
PriorityQueue<T *>::PriorityQueue() : Queue<T *>() {}

template <typename T>
PriorityQueue<T *>::PriorityQueue(size_t size) : Queue<T *>(size) {}

template <typename T>
PriorityQueue<T *>::PriorityQueue(const PriorityQueue<T *> &q) : Queue<T *>(q) {}

template <typename T>
ssize_t PriorityQueue<T *>::search(T *elem, ssize_t i, ssize_t j, ssize_t *l) const
{
    ssize_t k = (i + j) / 2;

    if (i >= j)
    {
        if (l)
        {
            // *l = k + (elem->compare(this->data[k]) > 0);
            // cout << *elem << " > " << *this->data[k] << ": " << (*elem > *this->data[k]) << endl;
            *l = k + (*elem > *this->data[k]);
        }

        // return not elem->compare(this->data[k]) ? k : -1;
        return *elem == *this->data[k] ? k : -1;
    }
    else if (*elem < *this->data[k])
    // else if (elem->compare(this->data[k]) < 0)
    {
        return this->search(elem, i, k, l);
    }
    else if (*elem > *this->data[k])
    // else if (elem->compare(this->data[k]) > 0)
    {
        return this->search(elem, k + 1, j, l);
    }
    else
    {
        while (k > 0 and *this->data[k - 1] >= *elem)
        // while (k > 0 and not elem->compare(this->data[k]) and not elem->compare(this->data[k - 1]))
        {
            k--;
        }

        if (l)
        {
            *l = k;
        }

        return k;
    }
}

template <typename T>
ssize_t PriorityQueue<T *>::search(T *elem) const
{
    return this->search(elem, 0, this->current_size - 1, NULL);
}

template <typename T>
void PriorityQueue<T *>::add(T *elem)
{
    if (not this->current_size)
    {
        SubscriptableCollection<T *>::insert(elem, 0);
        return;
    }

    ssize_t l;
    this->search(elem, 0, this->current_size - 1, &l);
    // cout << "current size: " << this->current_size << " insert at index " << l << " element: " << *elem << "\n";
    SubscriptableCollection<T *>::insert(elem, l);
}

template <typename T>
void PriorityQueue<T *>::remove(size_t index)
{
    delete this->data[index];
    SubscriptableCollection<T *>::remove(index);
}

template <typename T>
const T *PriorityQueue<T *>::operator[](size_t index)
{
    return this->data[index];
}

template <typename T>
PriorityQueue<T *> &PriorityQueue<T *>::operator=(const PriorityQueue<T *> &q)
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

template <typename t>
ostream &operator<<(ostream &out, const PriorityQueue<t *> &q)
{
    Iterator<t *> it = q.begin();
    Iterator<t *> it_end = q.end();

    out << "{";
    for (it_end.previous(); it < it_end; it.next())
    {
        out << *it.value() << ", ";
    }

    if (not q.is_empty())
    {
        out << *it_end.value();
    }

    out << "}";

    return out;
}

#endif