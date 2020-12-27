#include "../../data_structures/abstract/comparable.h"

#include <fstream>
#include <iostream>

#ifndef DATE_H
#define DATE_H

class Date : public Comparable<Date>
{
    int day;
    int month;
    int year;

    char *wday;
    char *ymonth;

    void setup();

public:
    Date();
    Date(const Date &date);
    Date(const char *date);
    Date(int day, int month, int year);

    ~Date();

    int compare(const Date &date) const;

    void set_day(int day);
    void set_month(int month);
    void set_year(int year);

    void set_date(int day, int month, int year);
    void set_date(std::string date);

    int get_day() const;
    int get_month() const;
    int get_year() const;

    const char *get_weekday() const;
    const char *get_year_month() const;

    void today();
    std::string to_string() const;

    Date &operator=(const Date &);

    friend std::ostream &operator<<(std::ostream &, const Date &);
    friend std::ofstream &operator<<(std::ofstream &, const Date &);

    friend std::istream &operator>>(std::istream &, Date &);
    friend std::ifstream &operator>>(std::ifstream &, Date &);
};

#endif