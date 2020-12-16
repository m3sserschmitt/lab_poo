#include "../../data_structures/abstract/comparable.h"

#include "time.h"

#ifndef DATE_H
#define DATE_H

class Date: public Comparable<Date> {
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
    void set_date(const char *date);

    int get_day() const;
    int get_month() const;
    int get_year() const;

    const char *get_weekday() const;
    const char *get_year_month() const;

    void today();

    Date &operator=(const Date &);

    friend ostream &operator<<(ostream &, const Date &);
    friend istream &operator>>(istream &, Date &);
};

#endif