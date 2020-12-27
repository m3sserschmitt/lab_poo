#include "date.h"

#ifndef DATE_RANGE_H
#define DATE_RANGE_H

class DateRange
{
    Date begin;
    Date end;

public:
    DateRange();
    DateRange(const Date &date);
    DateRange(const Date &begin, const Date &end);
    DateRange(const DateRange &range);

    void set_begin(const Date &date);
    void set_end(const Date &date);
    void set(const Date &begin, const Date &end);

    Date get_begin() const;
    Date get_end() const;

    DateRange &operator=(const DateRange &);

    friend std::ostream &operator<<(std::ostream &, const DateRange &);
};

#endif