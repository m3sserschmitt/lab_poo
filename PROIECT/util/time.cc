#include "./include/time.h"
#include "./include/mem.h"
#include "./include/util.h"

#include <time.h>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

static const char *WDAYS[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
static const char *YMONTHS[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
static const int daysc[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check_time(int hours, int minutes, int seconds)
{
    if (hours < 0 or hours > 23)
    {
        return false;
    }

    if (minutes < 0 or minutes > 59)
    {
        return false;
    }

    if (seconds < 0 or seconds > 59)
    {
        return false;
    }

    return true;
}

bool check_date(int day, int month, int year)
{
    if (1900 > year or year > 3000)
    {
        return false;
    }

    if (month > 12 or month < 1)
    {
        return false;
    }

    int days = daysc[month - 1];

    if (month == 2)
    {
        if (year % 4)
        {
            days = 28;
        }
        else if (year % 100)
        {
            days = 29;
        }
        else if (year % 400)
        {
            days = 28;
        }else 
        {
            days = 29;
        }
    }

    if(day < 1 or day > days)
    {
        return false;
    }

    return true;
}

bool check_date(const char *date)
{
    vector<string> tokens = split(date, ".", 2);

    if (tokens.size() != 3)
    {
        return false;
    }

    int day;
    int month;
    int year;

    if (not is_number(tokens[0], day) or not is_number(tokens[1], month) or not is_number(tokens[2], year))
    {
        return false;
    }

    return check_date(day, month, year);
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

bool get_ymonth(string ymonth, int &month)
{
    for (int i = 0; i < 12; i++)
    {
        int c = (int)ymonth[i];

        if (i == 0 and c >= 97 and c <= 122)
        {
            c -= 32;
            ymonth[i] = (char)c;
        }
        else if (i >= 1 and c >= 65 and c <= 90)
        {
            c += 32;
            ymonth[i] = (char)c;
        }

        if (not strcmp(YMONTHS[i], ymonth.c_str()))
        {
            month = i + 1;
            return true;
        }
    }

    month = 0;
    return false;
}

void get_system_timezone(char *timezone)
{
    tm system_time = get_system_time();
    std::stringstream ss;
    ss << std::put_time(&system_time, "%Z");

    strcpy(timezone, ss.str().c_str());
}