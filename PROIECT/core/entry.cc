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
    // cout << "name set ";
    this->name = name;
    // cout << this->name << "\n";
}

std::string Entry::get_name()
{
    return this->name;
}

Date Entry::get_date()
{
    return this->date;
}

bool Entry::operator<(Entry &e)
{
    return this->compare(&e) < 0;
}

bool Entry::operator>(Entry &e)
{
    return this->compare(&e) > 0;
}

bool Entry::operator<=(Entry &e)
{
    return not((*this) > e);
}

bool Entry::operator>=(Entry &e)
{
    return not((*this) < e);
}

bool Entry::operator==(Entry &e)
{
    if (typeid(e) == typeid(*this))
    {
        return this->name == e.name and not this->compare(&e);
    }

    Entry *entry = dynamic_cast<Entry *>(&e);

    if (entry)
    {
        return not this->compare(&e);
    }

    return false;
}

bool Entry::operator!=(Entry &e)
{
    return not(*this == e);
}

ostream &operator<<(ostream &out, Entry &entry)
{
    return entry.show(out);
}

istream &operator>>(istream &in, Entry &entry)
{
    return entry.read(in);
}