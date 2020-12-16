#include "./include/time.h"
#include "../util/include/time.h"
#include "../util/include/util.h"
#include "./exceptions/include/invalid_time.h"

#include "../data_structures/iterable/vector/vector.h"

#include <vector>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

char Time::timezone[8];

Time::Time()
{
    this->set_time(0, 0, 0);
    get_system_timezone(timezone);
}

Time::Time(const Time &time)
{
    this->hours = time.hours;
    this->minutes = time.minutes;
    this->seconds = time.seconds;

    get_system_timezone(timezone);
}

Time::Time(const char *time)
{
    this->set_time(time);
    get_system_timezone(timezone);
}

Time::Time(int hours, int minutes, int seconds)
{
    this->set_time(hours, minutes, seconds);
    get_system_timezone(timezone);
}

Time::~Time(){}

int Time::compare(Time *t)
{
    Vector<bool> u = {this->hours < t->hours, this->minutes < t->minutes, this->seconds < t->hours};
    Vector<bool> v = {this->hours > t->hours, this->minutes > t->minutes, this->seconds > t->hours};

    return u < v ? 1 : -1 * (v < u);
}

void Time::set_seconds(int seconds)
{
    if(seconds < 0 or seconds > 59)
    {
        throw InvalidTimeError(TIME_OUT_OF_RANGE);
    }

    this->seconds = seconds;
}

void Time::set_minutes(int minutes)
{
    if(minutes < 0 or minutes > 59)
    {
        throw InvalidTimeError(TIME_OUT_OF_RANGE);
    }

    this->minutes = minutes;
}

void Time::set_hours(int hours)
{
    if(hours < 0 or hours > 23)
    {
        throw InvalidTimeError(TIME_OUT_OF_RANGE);
    }

    this->hours = hours;
}

void Time::set_time(int hours, int minutes, int seconds)
{
    if(not check_time(hours, minutes, seconds))
    {
        throw InvalidTimeError(TIME_OUT_OF_RANGE);
    }

    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

void Time::set_time(const char *time)
{
    vector<string> tokens = split(time, ":", 2);
    size_t n = tokens.size();

    if (n != 3 and n != 2)
    {
        throw InvalidTimeError(WRONG_TIME_FORMAT);
    }

    for (size_t i = 0; i < n; i++)
    {
        if (not is_number(tokens[i]))
        {
            throw InvalidTimeError(BAD_TIME_INPUT);
        }
    }

    int h = atoi(tokens[0].c_str());
    int m = atoi(tokens[1].c_str());
    int s = 0;

    if (n == 3)
    {
        s = atoi(tokens[2].c_str());
    }

    if (not check_time(h, m, s))
    {
        throw InvalidTimeError(TIME_OUT_OF_RANGE);
    }

    this->hours = h;
    this->minutes = m;
    this->seconds = s;
}

int Time::get_seconds() const
{
    return this->seconds;
}

int Time::get_minutes() const
{
    return this->minutes;
}

int Time::get_hours() const
{
    return this->hours;
}

const char *Time::get_timezone()
{
    return timezone;
}

void Time::now()
{
    tm now = get_system_time();
    this->set_time(now.tm_hour, now.tm_min, now.tm_sec);
}

bool Time::operator<(Time &other)
{
    return this->compare(&other) < 0;
}

bool Time::operator>(Time &other)
{
    return this->compare(&other) > 0;
}

bool Time::operator<=(Time &other)
{
    return not((*this) > other);
}

bool Time::operator>=(Time &other)
{
    return not((*this) < other);
}

bool Time::operator==(Time &other)
{
    return not this->compare(&other) and not strcmp(this->timezone, other.get_timezone());
}

ostream &operator<<(ostream &out, const Time &t)
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

istream &operator>>(istream &in, Time &t)
{
    string input;
    getline(in, input);

    t.set_time(input.c_str());

    return in;
}