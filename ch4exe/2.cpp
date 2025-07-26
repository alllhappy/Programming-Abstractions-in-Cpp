/*
In exercise 4 in Chapter 2, you wrote a function windChill that calculated 
the wind chill for a given temperature and wind velocity.  Write a program that 
uses this function to display these values in tabular form, as illustrated by the 
table from the National Weather service
*/

#include<iostream>
#include"../ch2exe/4.h"
#include<iomanip>
// windChill function in this file to calulate values

// g++ 2.cpp ../ch2exe/4.cpp ../ch2exe/3.cpp -o 2 
// command to build the file dependency 2.cpp --> ch2exe 4.cpp ---> ch2exe 3.cpp
int main() {

    std::cout<<" Calm "<<"|";
    for(int j=40;j>=-45;j-=5){
        std::cout<<" "<<std::setw(3)<<j<<" ";
    }
    std::cout<<std::endl;
    // std::cout<<std::setw(5)<<std::setfill('-')<<std::endl;
    // std::setfill(' ');
    std::cout<<"------+------------------------------------------------------------------------------------------"<<std::endl;
   
   for(int i=5;i<=60;i=i+5){
    std::cout<<"  "<<std::setw(2)<<i<<"  |";
    for(int j=40;j>=-45;j-=5){
        std::cout<<" "<<std::setw(3)<<windChill(j,i)<<" ";
    }
    std::cout<<std::endl;
   }
    return 0;
}