/*
Reimplement the RPN calculator from Figure 5-4 so that it performs its 
internal calculations using rational instead of floating-point numbers.  For 
example, your program should be able to produce the following sample run 
(which demonstrates that rational arithmetic is always exact):
*/
#include<iostream>
#include"rpn.h"

int main() {
    RPN calc1= RPN();
    calc1.calculations();
    return 0;
}