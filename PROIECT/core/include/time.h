#ifndef TIME_H
#define TIME_H

#include "../../data_structures/abstract/comparable.h"

#include <iostream>

using namespace std;

class Time : public Comparable<Time>
{
    int seconds;
    int minutes;
    int hours;

    static char timezone[];

public:
    Time();
    Time(const Time &t);
    Time(const char *time);
    Time(int hours, int minutes, int seconds = 0);

    ~Time();

    int compare(Time *t);

    void set_seconds(int seconds);
    void set_minutes(int minutes);
    void set_hours(int hours);

    void set_time(int hours, int minutes, int seconds = 0);
    void set_time(const char *time);

    int get_seconds() const;
    int get_minutes() const;
    int get_hours() const;
    static const char *get_timezone();

    void now();

    bool operator<(Time &);
    bool operator>(Time &);
    bool operator<=(Time &);
    bool operator>=(Time &);
    bool operator==(Time &);

    friend ostream &operator<<(ostream &out, const Time &t);
    friend istream &operator>>(istream &in, Time &t);
};

#endif