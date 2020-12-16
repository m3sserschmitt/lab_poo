#include "../data_structures/iterable/vector/vector.h"

#include "./include/date.h"
#include "../util/include/time.h"
#include "../util/include/mem.h"
#include "../util/include/util.h"
#include "./exceptions/include/invalid_date.h"

#include <vector>

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

Date::Date(const char *date)
{
    this->setup();

    this->set_date(date);
}

Date::Date(int day, int month, int year)
{
    this->setup();

    this->set_date(day, month, year);
}

Date::~Date()
{
    delete[] this->wday;
    delete[] this->ymonth;
}

int Date::compare(Date *d)
{
    Vector<bool> u = {this->year < d->year, this->month < d->month, this->day < d->day};
    Vector<bool> v = {this->year > d->year, this->month > d->month, this->day > d->day};

    return u < v ? 1 : -1 * (v < u);
}

void Date::setup()
{
    this->wday = new char[4];
    this->ymonth = new char[4];

    this->day = 1;
    this->month = 1;
    this->year = 1900;
}

void Date::set_day(int day)
{
    if(not check_date(day, this->month, this->year))
    {
        throw InvalidDateError(DATE_OUT_OF_RANGE);
    }

    this->day = day;

    get_wday(this->day, this->month, this->year, this->wday);
    // get_ymonth(this->month, this->ymonth);
}

void Date::set_month(int month)
{
    if(not check_date(this->day, month, this->year))
    {
        throw InvalidDateError(DATE_OUT_OF_RANGE);
    }

    this->month = month;

    get_wday(this->day, this->month, this->year, this->wday);
    get_ymonth(this->month, this->ymonth);
}

void Date::set_year(int year)
{
    if(not check_date(this->day, this->month, year))
    {
        throw InvalidDateError(DATE_OUT_OF_RANGE);
    }

    this->year = year;

    get_wday(this->day, this->month, this->year, this->wday);
    get_ymonth(this->month, this->ymonth);
}

void Date::set_date(int day, int month, int year)
{
    if (not check_date(day, month, year))
    {
        throw InvalidDateError(DATE_OUT_OF_RANGE);
    }

    this->day = day;
    this->month = month;
    this->year = year;

    get_wday(this->day, this->month, this->year, this->wday);
    get_ymonth(this->month, this->ymonth);
}

void Date::set_date(const char *date)
{
    vector<string> tokens = split(date, ".", 2);

    if (tokens.size() != 3)
    {
        throw InvalidDateError(WRONG_DATE_FORMAT);
    }

    for(int i = 0; i < 3; i ++)
    {
        if(not is_number(tokens[i]))
        {
            throw InvalidDateError(BAD_DATE_INPUT);
        }
    }

    if (not check_date(date))
    {
        throw InvalidDateError(DATE_OUT_OF_RANGE);
    }

    this->day = atoi(tokens[0].c_str());
    this->month = atoi(tokens[1].c_str());
    this->year = atoi(tokens[2].c_str());
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
    return not((*this) > d);
}

bool Date::operator>=(Date &d)
{
    return not((*this) < d);
}

bool Date::operator==(Date &d)
{
    return not this->compare(&d);
}

bool Date::operator!=(Date &d)
{
    return this->compare(&d);
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

    date.set_date(input.c_str());

    return in;
}