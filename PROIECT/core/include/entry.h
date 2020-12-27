#include "../../data_structures/abstract/comparable.h"
#include "date_range.h"
#include "date.h"

#include <map>

#ifndef ENTRY_H
#define ENTRY_H

class Entry : public Comparable<Entry>
{
protected:
    Date date;
    std::string name;

    virtual std::istream &read(std::istream &) = 0;
    virtual std::ifstream &read2(std::ifstream &) = 0;

public:
    Entry();
    Entry(std::string name);
    Entry(const Entry &entry);

    virtual ~Entry() = 0;

    void set_name(std::string name);
    std::string get_name() const;

    void set_date(Date date);
    void set_date(int day, int month, int year);

    Date get_date() const;
    bool in_range(const DateRange &range) const;

    virtual std::string to_string() const = 0;
    virtual std::string to_string2() const = 0;

    static void read_map(std::ifstream &in, std::map<std::string, std::string> &m);

    friend bool operator==(const Entry &, const Entry &);
    friend bool operator!=(const Entry &, const Entry &);

    friend std::ostream &operator<<(std::ostream &, const Entry &);
    friend std::ofstream &operator<<(std::ofstream &out, const Entry &entry)
    {
        out << entry.to_string2();

        return out;
    }

    friend std::istream &operator>>(std::istream &, Entry &);
    friend std::ifstream &operator>>(std::ifstream &, Entry &);
};

#endif