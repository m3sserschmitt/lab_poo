#include "entry.h"
#include "time.h"

#include <string>

#ifndef EVENT_H
#define EVENT_H

class Event: public Entry
{
protected:
    Time time;

    istream &read(istream &in);
    ostream &show(ostream &out) const;

public:
    Event();
    Event(std::string name);
    Event(const Event &event);

    int compare(const Entry &e) const;

    void set_time(Time time);
    void set_time(int hours, int minute, int seconds = 0);

    Time get_time() const;

    Event &operator=(const Event &);
};

#endif