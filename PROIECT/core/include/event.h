#include "entry.h"
#include "time.h"

#include <string>
#include <fstream>

#ifndef EVENT_H
#define EVENT_H

class Event : public Entry
{
    Time time;

    std::istream &read(std::istream &in);
    std::ifstream &read2(std::ifstream &in);

public:
    Event();
    Event(std::string name);
    Event(const Event &event);

    int compare(const Entry &e) const;

    void set_time(Time time);
    void set_time(int hours, int minute, int seconds = 0);

    Time get_time() const;

    std::string to_string() const;
    std::string to_string2() const;

    Event &operator=(const Event &);
};

#endif