#include<iostream>
#include"calender.h"
#include<vector>
/*
in this implementation I have taken into account leap where its implementation is easy.
The final results after operators may not be 100%accurate but are easy to implement by this simplicity and are good round off or estimates

*/
int daysInMonth(Month month,int y){
    if(month==JANUARY || month == MARCH || month==MAY||month==JULY||
        month==AUGUST || month==OCTOBER || month==DECEMEBER) {
            return 31;
        }
    if(month==FEBRUARY){
        if(isLeapYear(y)){
            return 29;
        }
        else{
            return 28;
        }
    }
    else{
        return 30;
    }
}
bool isLeapYear(int year){
    if(year%4==0 ){
        if(year%100==0){ // century year
            if(year%400==0) return true;
            else {return false;}
        }
        return true;
    }
    return false;
}
std::string monthToString(Month month){
    switch (month)
    {
    case JANUARY:
    return "January";
    break;
    case FEBRUARY:
    return "February";
    break;
    case MARCH:
    return "March";
    break;
    case APRIL:
    return "April";
    break;
    case MAY:
    return "May";
    break;
    case JUNE:
    return "June";
    break;
    case JULY:
    return "July";
    break;
    case AUGUST:
    return "August";
    break;
    case SEPTEMBER:
    return "September";
    break;
    case OCTOBER:
    return "October";
    break;
    case NOVEMBER:
    return "November";
    break;
    case DECEMEBER:
    return "December";
    break;
    
 
    }
}
bool isValidDay(int d,Month m, int y){
    if(d>=1 && d<=daysInMonth(m,y)) return true;
    return false;
}

Date::Date(){
    year=1900;
    date=1;
    mon=JANUARY;
}

Date::Date(Month m,int d,int y){
    //only valid dates should be allowed
    if(isValidDay(d,m,y)){
        mon=m;date=d;year=y;
    }
    else{
        year=1900;
        date=1;
        mon=JANUARY;
    }
    
}
/*
Calling a constructor like a function never initializes this.
It only creates a temporary object

This is invalid. 
gpt- https://chatgpt.com/s/t_6972f541697081919a108c59e110335f
Date::Date(int d,Month m, int y){
    Date(m,d,y);
}
*/

Date::Date(int d,Month m, int y){
    if(isValidDay(d,m,y)){
        mon=m;date=d;year=y;
    }
    else{
        year=1900;
        date=1;
        mon=JANUARY;
    }
}
int Date::getDay(){
    return date;
}

int Date::getYear(){
    return year;
}


Month Date::getMonth(){
    return mon;
}
std::string Date::toString(){
    std::string monStr=monthToString(mon);
    return std::to_string(date)+"-"+monStr.substr(0,3)+"-"+std::to_string(year);
}

std::ostream &operator<<(std::ostream &os,Date d){
    return os<<d.toString();
}
bool operator==(Date a,Date b){
    if(a.year==b.year && a.mon==b.mon && a.date==b.date){
        return true;
    }
    return false;
}

bool operator!=(Date a,Date b){
    return !(a==b);
}

bool operator<(Date a, Date b){
      //start checking from year
    if(a.year==b.year){
        if(a.mon==b.mon){
            if(a.date==b.date) return false;
            return a.date<b.date;
        }
        return a.mon<b.mon;
    }
    return a.year<b.year;
}

bool operator<=(Date a,Date b){
        if(a.year==b.year){
        if(a.mon==b.mon){
            if(a.date==b.date) return true;
            return a.date<b.date;
        }
        return a.mon<b.mon;
    }
    return a.year<b.year;
}

bool operator>(Date a,Date b){
    return !(a<b);
}

bool operator>=(Date a,Date b){
    if(a==b) return true;
    return a>b;
}

Date operator+(Date a,int n){
    
    //in constant time it is possible but harder implementation
    // in linear time it is easier to implement although it can be constant as O(365)
    a.year+=(n/365);
    n= n%365;
    while(n){ //contsn
        if(a.date+1>daysInMonth(a.mon,a.year)){
            a.date=1;
            a.mon=Month((int(a.mon)+1)%12);
            if(a.mon==0) a.year++;
        }
        else{
            a.date++;
        }
        n--;
    }
    return a;
}

Date operator-(Date a, int n){
    a.year-=(n/365);
    n= n%365;
    while(n){
        if(a.date==1){
            //change month
            //TODO
            int m=(int(a.mon)-1);
            if(m<0) m=(m+12);
            m%=12;
            a.mon=Month(m);
            if(a.mon==11) a.year--;
            a.date=daysInMonth(a.mon,a.year);
        }
        else{
            a.date--;
        }
        n--;
    }
    return a;
}

int operator-(Date a,Date b){
    //prefix sum for days in months till covered in year
    std::vector<int> prefix(13,0); // 0,31,31+28,
    prefix[0]=0;
    prefix[1]=31;
    for(int i=2;i<=12;i++){
        prefix[i]= prefix[i-1]+daysInMonth(Month(i-1),a.year);
    }
    long long d1=a.date+ prefix[a.mon] + 365*(a.year);
    // std::cout<<a.date<<" "<<prefix[a.mon]<<" "<<365*(a.year)<<"\n";

    //for b, as might be leap year
    for(int i=2;i<=12;i++){
        prefix[i]= prefix[i-1]+daysInMonth(Month(i-1),b.year);
    }
    long long d2=b.date+prefix[b.mon]+365*(b.year);

    return  abs(d1-d2);
}
void operator+=(Date &a,int i){
    a=a+i;
}

void operator-=(Date &a,int i){
    a=a-i;
}

Date operator++(Date &a){//prefix form
    a=a+1;
    return a;
}
Date operator++(Date &a,int){//suffix form

    a=a+1;
    return a-1;
}
Date operator--(Date &a){
    a=a-1;
    return a;
}
Date operator--(Date &a,int){
    a=a-1;
    return a+1;
}