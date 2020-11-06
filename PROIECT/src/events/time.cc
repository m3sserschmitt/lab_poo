#include "events/time.h"
#include "util/time.h"

#include "data_structures/vector/vector.h"

#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

Time::Time()
{
    allocate_memory(&this->timezone, 8);

    this->set_time(0, 0, 0);
    get_system_timezone(this->timezone);

}

Time::Time(const Time &time)
{
    allocate_memory(&this->timezone, 8);

    this->hours = time.hours;
    this->minutes = time.minutes;
    this->seconds = time.seconds;

    get_system_timezone(this->timezone);
}

Time::Time(int hours, int minutes, int seconds)
{
    allocate_memory(&this->timezone, 8);

    this->set_time(hours, minutes, seconds);
    get_system_timezone(this->timezone);
}

void Time::set_seconds(int seconds)
{
    this->seconds = seconds;
}

void Time::set_minutes(int minutes)
{
    this->minutes = minutes;
}

void Time::set_hours(int hours)
{
    this->hours = hours;
}

void Time::set_time(int hours, int minutes, int seconds)
{
    this->set_hours(hours);
    this->set_minutes(minutes);
    this->set_seconds(seconds);
}

int Time::get_seconds()
{
    return this->seconds;
}

int Time::get_minutes()
{
    return this->minutes;
}

int Time::get_hours()
{
    return this->hours;
}

void Time::now()
{
    tm now = get_system_time();
    this->set_time(now.tm_hour, now.tm_min, now.tm_sec);
}

bool Time::operator<(Time other)
{
    Vector<bool> u = {this->hours < other.get_hours(), this->minutes < other.get_minutes(), this->seconds < other.get_seconds()};
    Vector<bool> v = {this->hours > other.get_hours(), this->minutes > other.get_minutes(), this->seconds > other.get_seconds()};

    return u > v;
}

bool Time::operator>(Time other)
{
    Vector<bool> u = {this->hours > other.get_hours(), this->minutes > other.get_minutes(), this->seconds > other.get_seconds()};
    Vector<bool> v = {this->hours < other.get_hours(), this->minutes < other.get_minutes(), this->seconds < other.get_seconds()};

    return u > v;
}

bool Time::operator<=(Time other)
{
    return not((*this) > other);
}

bool Time::operator>=(Time other)
{
    return not((*this) < other);
}

bool Time::operator==(Time other)
{
    return ((*this) <= other) and ((*this) >= other);
}

ostream &operator<<(ostream &out, Time t)
{
    out << setfill('0');

    out << setw(2) << t.get_hours();
    out << ":";
    out << setw(2) << t.get_minutes();
    out << ":";
    out << setw(2) << t.get_seconds();
    out << " " << t.timezone;

    return out;
}