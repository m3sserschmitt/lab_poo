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

    void set_begin(Date d);
    void set_end(Date d);

    Date get_begin();
    Date get_end();

    DateRange &operator=(const DateRange &range);

    friend ostream &operator<<(ostream &out, DateRange &range);
};

#endif