#include "util/time.h"
#include "util/mem.h"

#include <time.h>
#include <string.h>
#include <sstream>
#include <iomanip>

const char *WDAYS[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
const char *YMONTHS[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

tm get_system_time()
{
    time_t epoch_time = time(NULL);
    return *localtime(&epoch_time);
}

tm create_time_from_date(int day, int month, int year)
{
    tm time_in = {0, 0, 0,                      // second, minute, hour
                  day, month - 1, year - 1900}; // 1-based day, 0-based month, year since 1900
    time_t time_temp = mktime(&time_in);

    return *localtime(&time_temp);
}

void get_wday(int day, int month, int year, char *wday)
{
    if (day > 0 and month > 0 and year > 0)
    {
        tm time_out = create_time_from_date(day, month, year);

        strcpy(wday, WDAYS[time_out.tm_wday]);
    }
}

void get_ymonth(int month, char *ymonth)
{
    if (month > 0)
    {
        strcpy(ymonth, YMONTHS[month - 1]);
    }
}

void get_system_timezone(char *timezone)
{
    tm system_time = get_system_time();
    std::stringstream ss;
    ss << std::put_time(&system_time, "%Z");

    strcpy(timezone, ss.str().c_str());
}