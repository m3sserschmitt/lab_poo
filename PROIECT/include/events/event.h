#include "date.h"
#include "time.h"

#include <string>

#ifndef EVENT_H
#define EVENT_H

class Event {
    Date date;
    Time time;

    std::string name;

public:
    Event();
    Event(std::string name);
    Event(const Event &date);

    void set_date(Date date);
    void set_time(Time time);

    Date get_date();
    Time get_time();

    bool operator<(Event);
    bool operator>(Event);
    bool operator<=(Event);
    bool operator>=(Event);
    bool operator==(Event);

    friend ostream &operator<<(ostream &, Event);
};

#endif