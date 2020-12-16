#include "../../data_structures/iterable/queue/p_priority_queue.h"
#include "../../data_structures/iterable/vector/vector.h"

#include <list>

#include "date_range.h"
#include "entry.h"

#ifndef NOTEBOOK_H
#define NOTEBOOK_H

class Notebook: public PriorityQueue<Entry *>
{
public:
    Notebook();
    Notebook(size_t size);
    Notebook(const Notebook &n);

    void remove(size_t index);

    Date get_first_date();
    Date get_last_date();

    std::list<Entry *> list(Date date);
    std::list<Entry *> list(DateRange range);

    Notebook &operator=(const Notebook &n);

    friend Notebook &operator<<(Notebook &n, Entry &e);
    friend std::ostream &operator<<(std::ostream &out, Notebook &n);
};

#endif