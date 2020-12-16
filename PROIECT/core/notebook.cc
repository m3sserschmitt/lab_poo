#include "./include/notebook.h"

#include "./exceptions/include/index_error.h"


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

void Notebook::remove(size_t index)
{
    if(index >= this->current_size)
    {
        throw IndexError();
    }    
    
    SubscriptableCollection::remove(index);
}

Date Notebook::get_first_date()
{
    return this->data[0]->get_date();
}

Date Notebook::get_last_date()
{
    return this->data[this->size - 1]->get_date();
}

std::list<Entry *> Notebook::list(Date date)
{
    return this->list(DateRange(date));
}

std::list<Entry *> Notebook::list(DateRange range)
{
    Date begin = range.get_begin();
    Date end = range.get_end();

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

std::ostream &operator<<(std::ostream &out, Notebook &n)
{

    out << "[Notebook: ";

    if (not n.get_size())
    {
        out << "no entries]";
    }
    else if (n.get_size() == 1)
    {
        out << 1 << " entry]";
    }
    else
    {
        out << n.get_size() << " entries]";
    }

    return out;
}

Notebook &operator<<(Notebook &n, Entry &e)
{
    n.add(&e);
    return n;
}

Notebook &Notebook::operator=(const Notebook &n)
{
    if (this != &n)
    {
        if (this->size < n.size)
        {
            this->resize(n.size);
        }

        this->set_data(n.data, n.current_size);
    }

    return *this;
}