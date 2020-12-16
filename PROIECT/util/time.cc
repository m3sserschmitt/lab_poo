#include "./include/time.h"
#include "./include/mem.h"

#include <time.h>
#include <string.h>
#include <sstream>
#include <iomanip>

const char *WDAYS[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
const char *YMONTHS[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

bool check_time(int hours, int minutes, int seconds)
{
    if (hours < 0 or hours > 23)
    {
        return false;
    }

    if(minutes < 0 or minutes > 59)
    {
        return false;
    }

    if(seconds < 0 or seconds > 59)
    {
        return false;
    }

    return true;
}

bool check_date(const char *date)
{
    struct tm tm;
    return strptime(date, "%d.%m.%Y", &tm) == NULL ? false : true;
}

bool check_date(int day, int month, int year)
{
    std::stringstream ss;

    ss << day << "." << month << "." << year;
    std::string date = ss.str();

    return check_date(date.c_str());
}

tm get_system_time()
{
    time_t epoch_time = time(NULL);
    return *localtime(&epoch_time);
}

time_t create_time_from_date(int day, int month, int year)
{
    tm time_in = {0, 0, 0,                      // second, minute, hour
                  day, month - 1, year - 1900}; // 1-based day, 0-based month, year since 1900
    
    return mktime(&time_in);
}

void get_wday(int day, int month, int year, char *wday)
{
    if (day > 0 and month > 0 and year > 0)
    {
        time_t time_out = create_time_from_date(day, month, year);
        tm ltime = *localtime(&time_out);

        strcpy(wday, WDAYS[ltime.tm_wday]);
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