#include <ctime>

bool check_time(int hours, int minutes, int seconds);

bool check_date(const char *date);
bool check_date(int day, int month, int year);

tm get_system_time();
time_t create_time_from_date(int day, int month, int year);

void get_wday(int day, int month, int year, char *wday);
void get_ymonth(int month, char *ymonth);
void get_system_timezone(char *timezone);
