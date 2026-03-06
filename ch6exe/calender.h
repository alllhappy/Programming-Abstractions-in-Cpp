#ifndef _calender_h
#define _calender_h
#include<string>
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

class Date{

    //private variables
    private:
    Month mon;
    int date;
    int year;

    public:
    //constructors
    Date();
    Date(Month m,int d,int y);
    Date(int d,Month m,int y);

    //getters
    int getDay();
    int getYear();
    Month getMonth();

    std::string toString();
    
    //relational operators
    friend bool operator==(Date a,Date b);
    friend bool operator!=(Date a,Date b);
    friend bool operator<(Date a, Date b);
    friend bool operator<=(Date a,Date b);
    friend bool operator>(Date a,Date b);
    friend bool operator>=(Date a,Date b);

    //operators
    friend Date operator+(Date a,int n);
    friend Date operator-(Date a, int n);
    friend int operator-(Date a,Date b); //operator oveloading
    friend void operator+=(Date &a,int i);
    friend void operator-=(Date &a,int i);
    
    //unitary operators
    friend Date operator++(Date &a); //prefix form
    friend Date operator++(Date &a,int); //suffix form

    friend Date operator--(Date &a);
    friend Date operator--(Date &a,int);

    //operators
};

bool isLeapYear(int y);
std::string monthToString(Month m);
bool isValidDay(int d,Month m,int year);
std::ostream &operator<<(std::ostream &os,Date d);
int daysInMonth(Month month,int y);

bool operator==(Date a,Date b);
bool operator!=(Date a,Date b);
bool operator<(Date a, Date b);
bool operator<=(Date a,Date b);
bool operator>(Date a,Date b);
bool operator>=(Date a,Date b);


Date operator+(Date a,int n);
Date operator-(Date a, int n);
int operator-(Date a,Date b); //operator oveloading
void operator+=(Date &a,int i);
void operator-=(Date &a,int i);

Date operator++(Date &a); //prefix form
Date operator++(Date &a,int); //suffix form

Date operator--(Date &a);
Date operator--(Date &a,int);



#endif