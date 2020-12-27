#ifndef TIME_H
#define TIME_H

#include "../../data_structures/abstract/comparable.h"

#include <fstream>
#include <iostream>
#include <string>

class Time : public Comparable<Time>
{
    int seconds;
    int minutes;
    int hours;

    static char timezone[];

public:
    Time();
    Time(const Time &t);
    Time(const std::string &time);
    Time(int hours, int minutes, int seconds = 0);

    ~Time();

    int compare(const Time &t) const;

    void set_seconds(int seconds);
    void set_minutes(int minutes);
    void set_hours(int hours);

    void set_time(int hours, int minutes, int seconds = 0);
    void set_time(const std::string &time);

    int get_seconds() const;
    int get_minutes() const;
    int get_hours() const;
    static const char *get_timezone();

    void now();
    std::string to_string() const;

    Time &operator=(const Time &);

    friend std::ostream &operator<<(std::ostream &, const Time &);
    friend std::ofstream &operator<<(std::ofstream &out, const Time &time)
    {
        out << time.to_string();

        return out;
    }

    friend std::istream &operator>>(std::istream &, Time &);
    friend std::ifstream &operator>>(std::ifstream &, Time &);
};

#endif