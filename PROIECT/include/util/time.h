#include <ctime>

tm get_system_time();
tm create_time_from_date(int day, int month, int year);

void get_wday(int day, int month, int year, char *wday);
void get_ymonth(int month, char *ymonth);
void get_system_timezone(char *timezone);
