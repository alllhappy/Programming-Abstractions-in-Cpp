#include<iostream>
#include"calender.h"
int main() {
    Month month=FEBRUARY;
    std::cout<<daysInMonth(month)<<std::endl;
    std::cout<<isLeapYear(2016)<<std::endl;
    std::cout<<isLeapYear(1900)<<std::endl;
    std::cout<<monthToString(month)<<std::endl;

    return 0;
}