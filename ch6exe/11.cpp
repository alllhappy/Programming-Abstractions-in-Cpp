/*
Write a program that implements a simple arithmetic calculator. Input to the 
calculator consists of lines composed of numbers (either integers or reals) 
combined together using the arithmetic operators +, -, *, and /. For each line 
of input, your program should display the result of applying the operators from 
left to right. You should use the token scanner to read the terms and operators 
and set up the scanner so that it ignores any whitespace characters. Your 
program should exit when the user enters a blank line.
*/

#include<iostream>
#include<string>
#include<limits.h>
#include"tokenScanner.h"


void scanCalculatorTokens(TokenScanner &calc);
void calculate(std::string &curr, std::string &op, double &val);
int main() {
    TokenScanner calc=TokenScanner();
    scanCalculatorTokens(calc);
    std::string ip="";
    while(getline(std::cin,ip)){
        if(ip.size()==0) break;
        // std::cout<<ip<<"\n";

        //LTR evaluations of string
        calc.setInput(ip);
        std::string prev=calc.nextToken();
        std::string op=calc.nextToken();
       
        if(!isdigit(prev[0]) || !(op=="+"||op=="-"|| op=="*"|| op=="/")){
            std::cout<<"invalid input"<<"\n";
            continue;
        }
        double val=std::stod(prev);
        bool prevCheck=1; //0means previous was a number, 1 means previous was operator
        while(calc.hasMoreTokens()){ 
            std::string tk=calc.nextToken();
            if(isdigit(tk[0])){
                //its a number
                //perfrome operation
                if(prevCheck==0){
                    std::cout<<"invalid Input"<<"\n";
                    break;
                }
                calculate(tk,op,val);
                prevCheck=0;
            }
            else{
                if(prevCheck==1){
                    std::cout<<"invalid Input"<<"\n";
                    break;
                }
                op=tk;
                prevCheck=1;
            } 
        }

    }

    return 0;
}

void scanCalculatorTokens(TokenScanner &calc){
    calc.ignoreWhitespace();
    calc.scanNumbers();
    calc.addOperator("+");
    calc.addOperator("-");
    calc.addOperator("*");
    calc.addOperator("/");
}

void calculate(std::string &curr, std::string &op, double &val){
    double currNum=std::stod(curr);

    if(op=="+"){
        val+=currNum;
    }
    else if(op=="-"){
        val-=currNum;
    }
    else if(op=="*"){
        val*=currNum;
    }
    else if(op=="/"){
        val/=currNum;
    }
}
