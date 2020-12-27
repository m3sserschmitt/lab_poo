#include "./include/notebook.h"

#include "./exceptions/include/index_error.h"
#include "./exceptions/include/invalid_range.h"


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
    this->reserve(n.size);
    this->set_data(n.data, n.current_size);
}

void Notebook::add(Entry *entry)
{
    if (not this->current_size)
    {
        SubscriptableCollection<Entry *>::insert(entry, 0);
        return;
    }

    ssize_t l;
    if(this->search(entry, 0, this->current_size - 1, &l) < 0)
    {
        SubscriptableCollection<Entry *>::insert(entry, l);
    }
}

void Notebook::remove(size_t index)
{
    if(index >= this->current_size)
    {
        throw IndexError();
    }    
    
    PriorityQueue<Entry *>::remove(index);
    // SubscriptableCollection::remove(index);
}

Date Notebook::get_first_date() const
{
    return this->data[0]->get_date();
}

Date Notebook::get_last_date() const
{
    return this->data[this->current_size - 1]->get_date();
}

std::list<Entry *> Notebook::list(Date date) const
{
    return this->list(DateRange(date));
}

std::list<Entry *> Notebook::list(DateRange range) const
{
    Date begin = range.get_begin();
    Date end = range.get_end();

    if(begin > end)
    {
        throw InvalidDateRange(BAD_RANGE_LIMITS);
    }

    Iterator<Entry *> it = this->begin();
    std::list<Entry *> entries;

    for (; not it.out_of_range(); it.next())
    {
        Date current_date = it.value()->get_date();

        if (begin <= current_date and current_date <= end)
        {
            entries.push_back(it.value());
        }
    }

    return entries;
}

std::ostream &operator<<(std::ostream &out, const Notebook &notebook)
{

    out << "[Notebook: ";

    if (not notebook.get_size())
    {
        out << "no entries]";
    }
    else if (notebook.get_size() == 1)
    {
        out << 1 << " entry]";
    }
    else
    {
        out << notebook.get_size() << " entries]";
    }

    return out;
}

Notebook &operator<<(Notebook &notebook, Entry &entry)
{
    notebook.add(&entry);
    return notebook;
}

Notebook &Notebook::operator=(const Notebook &notebook)
{
    if (this != &notebook)
    {
        if (this->size < notebook.size)
        {
            this->resize(notebook.size);
        }

        this->set_data(notebook.data, notebook.current_size);
    }

    return *this;
}