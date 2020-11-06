#include "data_structures/queue/priority_queue.h"

#include "notebook_entry.h"

#ifndef NOTEBOOK_H
#define NOTEBOOK_H

class Notebook: public PriorityQueue<NotebookEntry>
{
public:
    Notebook();
    Notebook(size_t size);
    Notebook(const Notebook &n);

    void add_event(Event *e);

    friend Notebook &operator<<(Notebook &, Event &);
    friend std::ostream &operator<<(std::ostream &, Notebook);
};

#endif