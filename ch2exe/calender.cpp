#include<iostream>
#include"calender.h"

int daysInMonth(Month month){
    if(month==JANUARY || month == MARCH || month==MAY||month==JULY||
        month==AUGUST || month==OCTOBER || month==DECEMEBER) {
            return 31;
        }
    if(month==FEBRUARY){
        std::cout<<"enter year :";
        int year;
        std::cin>>year;
        if(isLeapYear(year)){
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


