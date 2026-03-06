#ifndef RPN_CALCULATOR
#define RPN_CALCULATOR


#include<stack>
#include<iostream>
#include<string>
#include"rational.h"
class RPN{
   private:
   std::stack<Rational> st;
   std::pair<int,Rational> stringToRational(std::string &s);

   public:
   //constructor
   RPN();
   void calculations();
   void printHelp();
   void clearStack();
};

#endif