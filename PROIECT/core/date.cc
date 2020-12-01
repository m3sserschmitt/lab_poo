#include "../data_structures/iterable/vector/vector.h"

#include "./include/date.h"
#include "../util/include/time.h"
#include "../util/include/mem.h"

Date::Date()
{
    this->setup();
    this->today();
}

Date::Date(const Date &date)
{
    this->setup();
    this->year = date.year;
    this->month = date.month;
    this->day = date.day;

    strcpy(this->wday, date.wday);
    strcpy(this->ymonth, date.ymonth);
}

Date::Date(int day, int month, int year)
{
    this->setup();
    this->set_date(day, month, year);
}

Date::~Date()
{
}

int Date::compare(Date *d)
{
    Vector<bool> u = {this->year < d->year, this->month < d->month, this->day < d->day};
    Vector<bool> v = {this->year > d->year, this->month > d->month, this->day > d->day};
    
    return u < v ? 1 : -1 * (v < u);
}

void Date::setup()
{
    allocate_memory(&this->wday, 4);
    allocate_memory(&this->ymonth, 16);

    this->day = 1;
    this->month = 1;
    this->year = 1900;
}

void Date::set_day(int day)
{
    this->day = day;
    get_wday(this->day, this->month, this->year, this->wday);
    get_ymonth(this->month, this->ymonth);
}

void Date::set_month(int month)
{
    this->month = month;
    get_wday(this->day, this->month, this->year, this->wday);
    get_ymonth(this->month, this->ymonth);
}

void Date::set_year(int year)
{
    this->year = year;
    get_wday(this->day, this->month, this->year, this->wday);
    get_ymonth(this->month, this->ymonth);
}

void Date::set_date(int day, int month, int year)
{
    this->set_day(day);
    this->set_month(month);
    this->set_year(year);
}

int Date::get_day()
{
    return this->day;
}

int Date::get_month()
{
    return this->month;
}

int Date::get_year()
{
    return this->year;
}

char *Date::get_weekday()
{
    return this->wday;
}

char *Date::get_year_month()
{
    return this->ymonth;
}

void Date::today()
{
    tm today = get_system_time();
    this->set_date(today.tm_mday, today.tm_mon + 1, today.tm_year + 1900);
}

bool Date::operator<(Date &d)
{
    return this->compare(&d) < 0;
}

bool Date::operator>(Date &d)
{
    return this->compare(&d) > 0;
}

bool Date::operator<=(Date &d)
{
    return not ((*this) > d);
}

bool Date::operator>=(Date &d)
{
    return not ((*this) < d);
}

bool Date::operator==(Date &d)
{
    return not this->compare(&d);
}

ostream &operator<<(ostream &out, Date &date)
{
    out << date.get_weekday() << ", " << date.get_day() << " " << date.get_year_month() << " ";
    out << date.get_year();

    return out;
}

istream &operator>>(istream &in, Date &date)
{
    string input;
    getline(in, input);

    date.set_day(atoi(strtok((char *)input.c_str(), ".")));
    date.set_month(atoi(strtok(NULL, ".")));
    date.set_year(atoi(strtok(NULL, ".")));

    return in;
}