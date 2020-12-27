#include "../data_structures/iterable/vector/vector.h"

#include "./include/date.h"
#include "../util/include/time.h"
#include "../util/include/mem.h"
#include "../util/include/util.h"
#include "./exceptions/include/invalid_date.h"

#include <map>
#include <vector>
#include <sstream>

using namespace std;

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

Date::Date(const string &date)
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

int Date::compare(const Date &d) const
{
    Vector<bool> u = {this->year < d.year, this->month < d.month, this->day < d.day};
    Vector<bool> v = {this->year > d.year, this->month > d.month, this->day > d.day};

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
    if (not check_date(day, this->month, this->year))
    {
        throw InvalidDateError(DATE_OUT_OF_RANGE);
    }

    this->day = day;

    get_wday(this->day, this->month, this->year, this->wday);
    // get_ymonth(this->month, this->ymonth);
}

void Date::set_month(int month)
{
    if (not check_date(this->day, month, this->year))
    {
        throw InvalidDateError(DATE_OUT_OF_RANGE);
    }

    this->month = month;

    get_wday(this->day, this->month, this->year, this->wday);
    get_ymonth(this->month, this->ymonth);
}

void Date::set_year(int year)
{
    if (not check_date(this->day, this->month, year))
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

void Date::set_date(const string &date)
{
    vector<string> tokens = split(date, ".", 2);

    if (tokens.size() != 3)
    {
        tokens = split(date, " ", -1);
        size_t sz = tokens.size();

        if (sz < 3)
        {
            throw InvalidDateError(WRONG_DATE_FORMAT);
        }
        else if (sz > 3)
        {
            for (int i = 0; i < 3; i++)
            {
                tokens[i] = tokens[sz - 3 + i];
            }

            tokens.resize(3);
        }
    }

    map<int, int> m;
    for (int i = 0; i < 3; i++)
    {
        if (not is_number(tokens[i], m[i]))
        {
            if (i == 1 and get_ymonth(tokens[i], m[i]))
            {
                continue;
            }

            throw InvalidDateError(BAD_DATE_INPUT);
        }
    }

    if (not check_date(m[0], m[1], m[2]))
    {
        throw InvalidDateError(DATE_OUT_OF_RANGE);
    }

    this->day = m[0];
    this->month = m[1];
    this->year = m[2];

    get_wday(this->day, this->month, this->year, this->wday);
    get_ymonth(this->month, this->ymonth);
}

int Date::get_day() const
{
    return this->day;
}

int Date::get_month() const
{
    return this->month;
}

int Date::get_year() const
{
    return this->year;
}

const char *Date::get_weekday() const
{
    return this->wday;
}

const char *Date::get_year_month() const
{
    return this->ymonth;
}

void Date::today()
{
    tm today = get_system_time();

    this->set_date(today.tm_mday, today.tm_mon + 1, today.tm_year + 1900);
}

string Date::to_string() const
{
    stringstream ss;

    ss << this->wday << ", " << this->day << " " << this->ymonth << " " << this->year;

    return ss.str();
}

Date &Date::operator=(const Date &date)
{
    if (this != &date)
    {
        this->day = date.day;
        this->month = date.month;
        this->year = date.year;

        strcpy(this->wday, date.wday);
        strcpy(this->ymonth, date.ymonth);
    }

    return *this;
}

ostream &operator<<(ostream &out, const Date &date)
{
    out << date.to_string();

    return out;
}
/*
ofstream &operator<<(ofstream &out, const Date &date)
{
    out << date.to_string();

    return out;
}
*/
istream &operator>>(istream &in, Date &date)
{
    string input;
    getline(in, input);

    date.set_date(input);

    return in;
}

ifstream &operator>>(ifstream &in, Date &date)
{
    string input;
    getline(in, input);

    date.set_date(input);

    return in;
}
