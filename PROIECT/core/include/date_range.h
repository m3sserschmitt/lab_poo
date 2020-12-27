#include "date.h"

#ifndef DATE_RANGE_H
#define DATE_RANGE_H

class DateRange
{
    Date begin;
    Date end;

public:
    DateRange();
    DateRange(Date date);
    DateRange(Date begin, Date end);
    DateRange(const DateRange &range);

    void set_begin(Date date);
    void set_end(Date date);

    Date get_begin() const;
    Date get_end() const;

    DateRange &operator=(const DateRange &);

    friend std::ostream &operator<<(std::ostream &, const DateRange &);
};

#endif