#include<iostream>
#include"tokenScanner.h"
#include<limits.h>
#include<unordered_map>


void scanCalculatorTokens(TokenScanner &calc);
void calculate(std::string &curr, std::string &op, double &val,std::unordered_map<std::string,double> &mp);
double mixCalculate2(TokenScanner &calc,std::unordered_map<std::string,double> &mp,std::string tk1,std::string tk2);

int main() {
    TokenScanner calc=TokenScanner();
    scanCalculatorTokens(calc);
    std::string ip="";
    std::unordered_map<std::string,double> mp;
    while(getline(std::cin,ip)){
        if(ip.size()==0) break;
        // std::cout<<ip<<"\n";
        //LTR evaluations of string
        calc.setInput(ip);
        std::string prev=calc.nextToken();
        std::string op=calc.nextToken();
        if(isalnum(prev[0])){
            if(isalpha(prev[0])){
                //either assingment , or value printing or using it in calculation
                /* 3possiblites
                area = RHS --> assigns rhs to lhs
                area  --> prints the value of variable directly
                area*34+44 -->caluclation like
                */
               if(op=="="){
                //assginment
                // process rhs mix of variable and
                double rhs=mixCalculate(calc,mp);
                mp[prev]=rhs;
               }
               else if(op==""){
                    if(mp.find(prev)!=mp.end()) {
                        std::cout<<mp[prev]<<"\n";
                    }
                    else{
                        std::cout<<"Variable DNE"<<"\n";
                    }
               }
               else if(isOperator(op[0])){
                    std::cout<<mixCalculate2(calc,mp,prev,op)<<"\n";
               }
               else{
                std::cout<<"INVALID exp"<<"\n";
               }

            }
            else{
                //its a number expression try to calculate and print the value
                std::cout<<mixCalculate2(calc,mp,prev,op)<<"\n";
            }

        }
        else{
            //surely invalid input
            std::cout<<"invalid input"<<"\n";
            continue;
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
    calc.addOperator("=");
}

void calculate(std::string &curr, std::string &op, double &val,std::unordered_map<std::string,double> &mp){

    double currNum;
    if(isdigit(curr[0])){
        currNum=std::stod(curr);
    }
    else{
        if(mp.find(curr)!=mp.end()) currNum=mp[curr];
        else{std::cout<<"variable DNE"<<"\n";
        return ;
        }
    }

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

//for expressions where no token is missed
double mixCalculate(TokenScanner &calc,std::unordered_map<std::string,double> &mp){
    //error CODE is INT_MAX
    //checking 1st token
    std::string token1=calc.nextToken();
    double val;
    if(isalpha(token1[0])){
        if(mp.find(token1)!=mp.end()) val= mp[token1];
        else{std::cout<<"Variable DNE"<<"\n"; return INT_MAX;}
    }
    else if(isdigit(token1[0])){
        val=std::stod(token1);
    }
    if(calc.hasMoreTokens()==false) return val;

    std::string prevOp=calc.nextToken();
    if(calc.hasMoreTokens()==false) return INT_MAX;

    std::string prevN=calc.nextToken();
    calculate(prevN,prevOp,val,mp);
    bool prevNum=true;
    while(calc.hasMoreTokens()){
        std::string tk=calc.nextToken();
        if(isOperator(tk[0]) && prevNum){
            //valid
            prevOp=tk;
            prevNum=false;
        }
        else if(isalnum(tk[0])) {
            if(prevNum==true){
                std::cout<<"invalid expression"<<"\n";
                return INT_MAX;
            }
            calculate(tk,prevOp,val,mp);
            prevNum=true;
        }
        else{
            std::cout<<"invalid expression"<<"\n";
            return INT_MAX;
        }
    }
    return val;
}


// for expressions which have intital 2 tokens used in main function
double mixCalculate2(TokenScanner &calc,std::unordered_map<std::string,double> &mp,std::string tk1,std::string tk2){
    //error CODE is INT_MAX
    //checking 1st token
    double val;
    if(mp.find(tk1)!=mp.end()) val=mp[tk1];
    else{
        std::cout<<"Variable DNE"<<"\n";
        return INT_MAX;
    }
    std::string prevN=calc.nextToken();
    bool prevNum=true;
    calculate(prevN,tk2,val,mp);
    bool prevNum=true;
    std::string prevOp=tk2;
    while(calc.hasMoreTokens()){
        std::string tk=calc.nextToken();
        if(isOperator(tk[0]) && prevNum){
            //valid
            prevOp=tk;
            prevNum=false;
        }
        else if(isalnum(tk[0])) {
            if(prevNum==true){
                std::cout<<"invalid expression"<<"\n";
                return INT_MAX;
            }
            calculate(tk,prevOp,val,mp);
            prevNum=true;
        }
        else{
            std::cout<<"invalid expression"<<"\n";
            return INT_MAX;
        }
    }
    return val;
}
bool isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' ||ch=='/') return true;
    return false;
}