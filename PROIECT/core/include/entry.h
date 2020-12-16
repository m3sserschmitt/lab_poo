#include "../../data_structures/abstract/comparable.h"

#include "date.h"

#ifndef ENTRY_H
#define ENTRY_H

class Entry : public Comparable<Entry>
{
protected:
    Date date;

    std::string name;

    virtual istream &read(istream &in) = 0;
    virtual ostream &show(ostream &out) = 0;

public:
    Entry();
    Entry(std::string name);
    Entry(const Entry &e);

    void set_name(std::string name);
    std::string get_name();

    void set_date(Date date);
    void set_date(int day, int month, int year);

    Date get_date();

    bool operator<(Entry &);
    bool operator>(Entry &);
    bool operator<=(Entry &);
    bool operator>=(Entry &);
    bool operator==(Entry &);
    bool operator!=(Entry &);

    friend ostream &operator<<(ostream &, Entry &);
    friend istream &operator>>(istream &, Entry &);
};

#endif