#include "./include/entry.h"

Entry::Entry(){}

Entry::Entry(std::string name)
{
    this->name = name;
}

Entry::Entry(const Entry &e)
{
    this->name = e.name;
    this->date = e.date;
}

void Entry::set_date(Date date)
{
    this->date = date;
}

void Entry::set_date(int day, int month, int year)
{
    this->set_date(Date(day, month, year));
}

void Entry::set_name(std::string name)
{
    this->name = name;
}

std::string Entry::get_name() const
{
    return this->name;
}

Date Entry::get_date() const
{
    return this->date;
}

bool operator==(const Entry &e1, const Entry &e2)
{
    if (typeid(e1) == typeid(e2))
    {
        return e1.name == e2.name and not e1.compare(e2);
    }

    Entry *entry = dynamic_cast<Entry *>(&(Entry &)e2);

    if (entry)
    {
        return not e1.compare(*entry);
    }

    return false;
}


bool operator!=(const Entry &e1, const Entry &e2)
{
    return not (e1 == e2);
}

ostream &operator<<(ostream &out, const Entry &entry)
{
    return entry.show(out);
}

istream &operator>>(istream &in, Entry &entry)
{
    return entry.read(in);
}