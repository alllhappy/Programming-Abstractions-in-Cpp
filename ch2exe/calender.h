#ifndef _calender_h
#define _calender_h

enum Month {
JANUARY,
FEBRUARY,
MARCH,
APRIL,
MAY,
JUNE,
JULY,
AUGUST,
SEPTEMBER,
OCTOBER,
NOVEMBER,
DECEMEBER
};

int daysInMonth(Month month);
bool isLeapYear(int year);
std::string monthToString(Month month);
#endif