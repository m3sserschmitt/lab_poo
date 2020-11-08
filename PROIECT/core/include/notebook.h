#include "../../data_structures/include/queue/priority_queue.h"
#include "event.h"

#ifndef NOTEBOOK_H
#define NOTEBOOK_H

class Notebook: public PriorityQueue<Event>
{
public:
    Notebook();
    Notebook(size_t size);
    Notebook(const Notebook &n);

    friend Notebook &operator<<(Notebook &, Event);
    friend std::ostream &operator<<(std::ostream &, Notebook);
};

#endif