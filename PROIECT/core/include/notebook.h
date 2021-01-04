#include "../../data_structures/iterable/queue/p_priority_queue.h"
#include "../../data_structures/iterable/vector/vector.h"

#include <list>

#include "date_range.h"
#include "entry.h"

#ifndef NOTEBOOK_H
#define NOTEBOOK_H

class Notebook: public PriorityQueue<Entry *>
{
    Notebook();
    Notebook(size_t size);
    Notebook(const Notebook &notebook);

    Notebook &operator=(const Notebook &);

public:
    static Notebook &getHandle();
    
    void add(Entry *entry);
    void remove(size_t index);

    Date get_first_date() const;
    Date get_last_date() const;

    std::list<Entry *> list(Date date) const;
    std::list<Entry *> list(DateRange range) const;

    friend Notebook &operator<<(Notebook &, Entry &);
    friend std::ostream &operator<<(std::ostream &, const Notebook &);
};

#endif