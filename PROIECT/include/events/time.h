#ifndef TIME_H
#define TIME_H

#include <iostream>

using namespace std;

class Time {
    int seconds;
    int minutes;
    int hours;

    char *timezone;
public:
    Time();
    Time(const Time &time);
    Time(int hours, int minutes, int seconds);

    void set_seconds(int seconds);
    void set_minutes(int minutes);
    void set_hours(int hours);

    void set_time(int hours, int minutes, int seconds);

    int get_seconds();
    int get_minutes();
    int get_hours();
    char *get_timezone();

    void now();

    bool operator<(Time);
    bool operator>(Time);
    bool operator<=(Time);
    bool operator>=(Time);
    bool operator==(Time);

    friend ostream &operator<<(ostream &out, Time t);
};

#endif