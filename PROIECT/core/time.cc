#include "./include/time.h"
#include "../util/include/time.h"
#include "../util/include/util.h"
#include "./exceptions/include/invalid_time.h"

#include "../data_structures/iterable/vector/vector.h"

#include <vector>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <map>

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

Time::Time(const string &time)
{
    this->set_time(time);
    get_system_timezone(timezone);
}

Time::Time(int hours, int minutes, int seconds)
{
    this->set_time(hours, minutes, seconds);
    get_system_timezone(timezone);
}

Time::~Time() {}

int Time::compare(const Time &t) const
{
    Vector<bool> u = {this->hours < t.hours, this->minutes < t.minutes, this->seconds < t.hours};
    Vector<bool> v = {this->hours > t.hours, this->minutes > t.minutes, this->seconds > t.hours};

    return u < v ? 1 : -1 * (v < u);
}

void Time::set_seconds(int seconds)
{
    if (seconds < 0 or seconds > 59)
    {
        throw InvalidTimeError(TIME_OUT_OF_RANGE);
    }

    this->seconds = seconds;
}

void Time::set_minutes(int minutes)
{
    if (minutes < 0 or minutes > 59)
    {
        throw InvalidTimeError(TIME_OUT_OF_RANGE);
    }

    this->minutes = minutes;
}

void Time::set_hours(int hours)
{
    if (hours < 0 or hours > 23)
    {
        throw InvalidTimeError(TIME_OUT_OF_RANGE);
    }

    this->hours = hours;
}

void Time::set_time(int hours, int minutes, int seconds)
{
    if (not check_time(hours, minutes, seconds))
    {
        throw InvalidTimeError(TIME_OUT_OF_RANGE);
    }

    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

void Time::set_time(const string &time)
{
    vector<string> tokens = split(time, " ", 1);
    tokens = split(tokens[0], ":", 2);
    
    size_t n = tokens.size();

    if (n != 3 and n != 2)
    {
        throw InvalidTimeError(WRONG_TIME_FORMAT);
    }

    map<int, int> m;
    m[2] = 0;

    for (size_t i = 0; i < n; i++)
    {
        if (not is_number(tokens[i], m[i]))
        {
            throw InvalidTimeError(BAD_TIME_INPUT);
        }
    }

    if (not check_time(m[0], m[1], m[2]))
    {
        throw InvalidTimeError(TIME_OUT_OF_RANGE);
    }

    this->hours = m[0];
    this->minutes = m[1];
    this->seconds = m[2];
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

string Time::to_string() const
{
    stringstream ss;

    ss << setfill('0');

    ss << setw(2) << this->get_hours();
    ss << ":";
    ss << setw(2) << this->get_minutes();
    ss << ":";
    ss << setw(2) << this->get_seconds();
    ss << " " << this->timezone;

    return ss.str();
}

Time &Time::operator=(const Time &time)
{
    if (this != &time)
    {
        this->hours = time.hours;
        this->minutes = time.minutes;
        this->seconds = time.seconds;
    }

    return *this;
}

ostream &operator<<(ostream &out, const Time &time)
{
    out << time.to_string();

    return out;
}

/*
ofstream &operator<<(ofstream &out, const Time &time)
{
    out << time.to_string();

    return out;
}
*/

istream &operator>>(istream &in, Time &time)
{
    string input;
    getline(in, input);

    time.set_time(input);

    return in;
}

ifstream &operator>>(ifstream &in, Time &time)
{
    string input;
    getline(in, input);

    time.set_time(input);

    return in;
}
