#include "date.h"
#include "time.h"

#include <string>

#ifndef EVENT_H
#define EVENT_H

class Event
{
    Date date;
    Time time;

    std::string name;

public:
    Event();
    Event(std::string name);
    Event(const Event &e);

    void set_date(Date date);
    void set_date(int day, int month, int year);

    void set_time(Time time);
    void set_time(int hours, int minute, int seconds = 0);

    void set_name(std::string name);
    std::string get_name();

    Date get_date();
    Time get_time();

    bool operator<(Event);
    bool operator>(Event);
    bool operator<=(Event);
    bool operator>=(Event);
    bool operator==(Event);

    friend ostream &operator<<(ostream &, Event);
    friend istream &operator>>(istream &, Event&);
};

#endif