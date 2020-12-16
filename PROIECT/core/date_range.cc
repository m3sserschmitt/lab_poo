#include "./include/date_range.h"

DateRange::DateRange() {}

DateRange::DateRange(Date date)
{
    this->begin = date;
    this->end = date;
}

DateRange::DateRange(Date begin, Date end)
{
    this->begin = begin;
    this->end = end;
}

DateRange::DateRange(const DateRange &range)
{
    this->begin = range.begin;
    this->end = range.end;
}

void DateRange::set_begin(Date begin)
{
    this->begin = begin;
}

void DateRange::set_end(Date end)
{
    this->end = end;
}

Date DateRange::get_begin()
{
    return this->begin;
}

Date DateRange::get_end()
{
    return this->end;
}

DateRange &DateRange::operator=(const DateRange &range)
{
    if(this != &range)
    {
        this->begin = range.begin;
        this->end = range.end;
    }

    return *this;
}

ostream &operator<<(ostream &out, DateRange &range)
{
    if(range.begin == range.end)
    {
        out << range.begin;
    }
    else
    {
        out << "from " << range.begin << " to " << range.end;
    }

    return out;
}
