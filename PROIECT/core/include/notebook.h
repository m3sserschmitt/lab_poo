#include "../../data_structures/iterable/queue/p_priority_queue.h"
#include "../../data_structures/iterable/vector/vector.h"

#include "event.h"

#ifndef NOTEBOOK_H
#define NOTEBOOK_H

class Notebook: public PriorityQueue<Event *>
{
public:
    Notebook();
    Notebook(size_t size);
    Notebook(const Notebook &n);

    void remove(size_t index);
    Vector<Event *> list(Date d);

    friend Notebook &operator<<(Notebook &n, Event &e);
    friend std::ostream &operator<<(std::ostream &out, Notebook &n);
};

#endif