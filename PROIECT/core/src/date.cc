#include "../../data_structures/include/vector/vector.h"

#include "../include/date.h"
#include "../../util/include/time.h"
#include "../../util/include/mem.h"

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

void Date::setup()
{
    allocate_memory(&this->wday, 4);
    allocate_memory(&this->ymonth, 16);

    this->day = 0;
    this->month = 0;
    this->year = 0;
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

bool Date::operator<(Date other)
{
    Vector<bool> u = {this->year < other.get_year(), this->month < other.get_month(), this->day < other.get_day()};
    Vector<bool> v = {this->year > other.get_year(), this->month > other.get_month(), this->day > other.get_day()};
    
    return u > v;
}

bool Date::operator>(Date other)
{
    Vector<bool> u = {this->year > other.get_year(), this->month > other.get_month(), this->day > other.get_day()};
    Vector<bool> v = {this->year < other.get_year(), this->month < other.get_month(), this->day < other.get_day()};

    return u > v;
}

bool Date::operator<=(Date other)
{
    return not ((*this) > other);
}

bool Date::operator>=(Date other)
{
    return not ((*this) < other);
}

bool Date::operator==(Date other)
{
    return ((*this) >= other) and ((*this) <= other);
}

ostream &operator<<(ostream &out, Date date)
{
    out << date.get_weekday() << ", " << date.get_day() << " " << date.get_year_month() << " ";
    out << date.get_year();

    return out;
}

istream &operator>>(istream &in, Date &date)
{
    // cout << "enter date (dd.mm.yyyy): ";
    char input[16] = {0};

    in >> input;

    date.set_day(atoi(strtok(input, ".")));
    date.set_month(atoi(strtok(NULL, ".")));
    date.set_year(atoi(strtok(NULL, ".")));

    return in;
}