#include "./include/date_range.h"
#include "./exceptions/include/invalid_range.h"
#include <iostream>
DateRange::DateRange() {}

DateRange::DateRange(const Date &date)
{
    this->begin = date;
    this->end = date;
}

DateRange::DateRange(const Date &begin, const Date &end)
{
    if (begin > end)
    {
        throw InvalidDateRange(BAD_RANGE_LIMITS);
    }

    this->begin = begin;
    this->end = end;
}

DateRange::DateRange(const DateRange &range)
{
    this->begin = range.begin;
    this->end = range.end;
}

void DateRange::set_begin(const Date &begin)
{
    this->begin = begin;
}

void DateRange::set_end(const Date &end)
{
    this->end = end;
}

void DateRange::set(const Date &begin, const Date &end)
{
    if (begin > end)
    {
        throw InvalidDateRange(BAD_RANGE_LIMITS);
    }

    this->begin = begin;
    this->end = end;
}

Date DateRange::get_begin() const
{
    return this->begin;
}

Date DateRange::get_end() const
{
    return this->end;
}

DateRange &DateRange::operator=(const DateRange &range)
{
    if (this != &range)
    {
        this->begin = range.begin;
        this->end = range.end;
    }

    return *this;
}

std::ostream &operator<<(std::ostream &out, const DateRange &range)
{
    if (range.begin == Date(1, 1, 1900) and range.end == Date(31, 12, 3000))
    {
        out << "all";
    }
    else if (range.begin == range.end)
    {
        out << range.begin;
    }
    else
    {
        out << "from " << range.begin << " to " << range.end;
    }

    return out;
}
