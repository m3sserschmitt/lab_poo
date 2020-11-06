#include "events/notebook_entry.h"

NotebookEntry::NotebookEntry()
{
    this->event = NULL;
}

NotebookEntry::NotebookEntry(Event *event)
{
    this->event = event;
}

NotebookEntry::NotebookEntry(const NotebookEntry &e)
{
    this->event = e.event;
}

Event NotebookEntry::get_event()
{
    return *this->event;
}

void NotebookEntry::set_event(Event *event)
{
    this->event = event;
}

bool NotebookEntry::operator<(NotebookEntry e)
{
    return *this->event < e.get_event();
}

bool NotebookEntry::operator>(NotebookEntry e)
{
    return *this->event > e.get_event();
}

bool NotebookEntry::operator<=(NotebookEntry e)
{
    return *this->event <= e.get_event();
}

bool NotebookEntry::operator>=(NotebookEntry e)
{
    return *this->event >= e.get_event();
}

bool NotebookEntry::operator==(NotebookEntry e)
{
    return *this->event == e.get_event();
}

std::ostream &operator<<(std::ostream &out, NotebookEntry &e)
{
    out << "[Event entry: " << e.get_event() << "]";
    return out;
}