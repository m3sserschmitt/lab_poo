#include "time.h"

#ifndef DATE_H
#define DATE_H

class Date {
    int day;
    int month;
    int year;

    char *wday;
    char *ymonth;

    void setup();
public:
    Date();
    Date(const Date &date);
    Date(int day, int month, int year);
    ~Date();

    void set_day(int day);
    void set_month(int month);
    void set_year(int year);

    void set_date(int day, int month, int year);

    int get_day();
    int get_month();
    int get_year();

    char *get_weekday();
    char *get_year_month();

    void today();

    bool operator<(Date);
    bool operator>(Date);
    bool operator<=(Date);
    bool operator>=(Date);
    bool operator==(Date);

    friend ostream &operator<<(ostream &, Date);
};

#endif