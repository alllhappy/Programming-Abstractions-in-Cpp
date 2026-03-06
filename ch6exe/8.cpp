/*
9. 
The Rational class presented in the text defines the operators +, –, *, / but 
needs several other operators for completeness.  Add the following operators 
to both the interface and implementation.: 
• The relational operators ==, !=, <, <=, >, and >= 
• The shorthand assignment operators +=, -=, *=, and /= 
• The ++ and -- operators in both their prefix and suffix form.
*/

#include<iostream>
#include"rational.h"

// command to compile : g++ 8.cpp rational.cpp error.cpp
int main() {
    Rational a(5,2);
    std::cout<<(a<Rational(3,2))<<"\n";    
    std::cout<<(a>Rational(6))<<"\n";    
    std::cout<<(a++)<<"\n";    
    std::cout<<(a)<<"\n";    
    std::cout<<(--a)<<"\n";
    std::cout<<(a)<<"\n";    
    std::cout<<(a==Rational(5,2))<<"\n";
    (a+=3);
    std::cout<<a<<"\n";
    a*=3;
    std::cout<<(a)<<"\n";
    a/=3;
    std::cout<<(a)<<"\n";
    return 0;
}