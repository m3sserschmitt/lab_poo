#include "event.h"

#include <iostream>

#ifndef ENTRY_H
#define ENTRY_H

class NotebookEntry
{
    Event *event;
public:
    NotebookEntry();
    NotebookEntry(Event *event);
    NotebookEntry(const NotebookEntry &e);

    Event get_event();
    void set_event(Event *event);

    bool operator<(NotebookEntry);
    bool operator>(NotebookEntry);
    bool operator<=(NotebookEntry);
    bool operator>=(NotebookEntry);
    bool operator==(NotebookEntry);

    friend std::ostream &operator<<(std::ostream &, NotebookEntry &);
};

#endif