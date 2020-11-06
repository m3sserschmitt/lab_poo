#include "events/notebook.h"

Notebook::Notebook()
{
    this->reserve(0);
    this->current_size = 0;
}

Notebook::Notebook(size_t size)
{
    this->reserve(size);
    this->current_size = 0;
}

Notebook::Notebook(const Notebook &n)
{
    if(this != &n)
    {
        this->reserve(n.size);
        this->set_data(n.data, n.current_size);
    }
}

void Notebook::add_event(Event *e)
{
    NotebookEntry new_entry;

    new_entry.set_event(e);
    this->add(new_entry);
}

std::ostream &operator<<(std::ostream &out, Notebook n)
{

    out << "[Notebook: ";

    if (not n.get_size())
    {
        out << "no events]";
    }
    else if (n.get_size() == 1)
    {
        out << 1 << " event]";
    }
    else
    {
        out << n.get_size() << " events]";
    }

    return out;
}

Notebook &operator<<(Notebook &n, Event &e)
{
    n.add_event(&e);
    return n;
}