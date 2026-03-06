/*
Extend the calendar.h interface still further by adding overloaded versions 
of the following operators: 
• The insertion operator <<. 
• The relational operators ==, !=, <, <=, >, and >= 
• The expression date + n, which returns the date n days after date 
• The expression date - n, which returns the date n days before date 
• The expression d1 - d2, which returns how many days separate d1 and d2 
• The shorthand assignment operators += and -= with an integer on the right 
• The ++ and -- operators in both their prefix and suffix form. 
*/

#include<iostream>
#include"calender.h"

int main() {
    Date birthday=Date(28,MAY,2005);

    std::cout<<birthday<<"\n";

    std::cout<<birthday+1<<"\n";
    std::cout<<birthday+45<<"\n";
    std::cout<<birthday+365<<"\n";
    std::cout<<birthday+435<<"\n";
    std::cout<<birthday+1000<<"\n";
    std::cout<<birthday+454652<<"\n";
    std::cout<<birthday+237<<"\n";

    std::cout<<"Subractions"<<"\n";

    std::cout<<(birthday+1)-1<<"\n";
    std::cout<<(birthday+45)-45<<"\n";
    std::cout<<(birthday+365)-365<<"\n";
    std::cout<<(birthday+435)-435<<"\n";
    std::cout<<(birthday+1000)-1000<<"\n";
    std::cout<<(birthday+454652)-454652<<"\n";
    std::cout<<(birthday+237)-237<<"\n";

    std::cout<< (birthday+23) - (birthday)<<"\n";
    std::cout<< (birthday) - (birthday)<<"\n";
    std::cout<< Date(23,JANUARY,2026)-birthday<<"\n";

    birthday+=5;
    std::cout<<birthday<<"\n";
    birthday-=5;
    std::cout<<birthday<<"\n";

    std::cout<<"unitary"<<"\n";
    std::cout<<++birthday<<"\n";
    std::cout<<birthday++<<"\n";
    std::cout<<birthday<<"\n";
    std::cout<<--birthday<<"\n";
    std::cout<<birthday--<<"\n";
    std::cout<<birthday<<"\n";
    
 
    return 0;
}