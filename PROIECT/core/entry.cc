#include "./include/entry.h"
#include "../util/include/util.h"

#include <vector>

using namespace std;

Entry::Entry() {}

Entry::Entry(string name)
{
    this->name = name;
}

Entry::Entry(const Entry &e)
{
    this->name = e.name;
    this->date = e.date;
}

Entry::~Entry() {}

void Entry::set_date(Date date)
{
    this->date = date;
}

void Entry::set_date(int day, int month, int year)
{
    this->set_date(Date(day, month, year));
}

void Entry::set_name(string name)
{
    this->name = name;
}

string Entry::get_name() const
{
    return this->name;
}

Date Entry::get_date() const
{
    return this->date;
}

void Entry::read_map(ifstream &in, map<string, string> &m)
{
    string data;
    vector<string> tokens;
    
    do
    {
        getline(in, data);
        tokens = split(data, ":", 1);

        if (tokens.size() == 2)
        {
            strip(tokens[0], " ");
            strip(tokens[1], " ");

            m[tokens[0]] = tokens[1];
        }
    } while (data.size());
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
    return not(e1 == e2);
}

ostream &operator<<(ostream &out, const Entry &entry)
{
    out << entry.to_string();

    return out;
}

ofstream &operator<<(ofstream &out, const Entry &entry)
{
    out << entry.to_string2();

    return out;
}

istream &operator>>(istream &in, Entry &entry)
{
    return entry.read(in);
}

ifstream &operator>>(ifstream &in, Entry &entry)
{
    return entry.read2(in);
}
