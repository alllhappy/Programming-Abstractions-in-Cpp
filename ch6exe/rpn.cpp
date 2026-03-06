#include<iostream>
#include<sstream>
#include"rpn.h"

RPN::RPN(){
    clearStack();
}
std::pair<int,int> stringToInteger(std::string str){ 
    std::istringstream stream(str); 
    int value; 
    stream >> value >> std::ws; 
    if(stream.fail() || !stream.eof()) { 
        return {0,0};
    } 
    // std::cout<<"enterd number is "<<value;
    return {1,value}; 
} 
void RPN::printHelp(){
        std::cout<<"\n"<<"Enter expressions in Reverse Polish Notation, in which operators follow \n the operands to which they apply.";
        std::cout<<" Each line consists of a numbers, an \n  operator, or one of the following commands: \n";
        std::cout<<"Q --- Quit the program \n H --- Display this help message \n C --- Clear the calculator stack\n";
}

void RPN::clearStack(){
        st = std::stack<Rational>();  // replaces with a new empty stack
}

void RPN::calculations(){
    while(true){
        std::cout<<"enter rational number in format like a/b : ";
        std::string ip;std::cin>>ip;
        if(ip=="Q") break;
        else if(ip=="H"){
            printHelp();
        }
        else if(ip=="C"){
            std::cout<<"Cleared the stack \n";
            clearStack();
        }
        else if(ip=="+" || ip=="-" || ip=="*"|| ip=="/"){
            //perform operation
            if(st.size()<=1) {
                std::cout<<"not enough elements \n";
                continue;
            }
            Rational a=st.top();
            st.pop();
            Rational b=st.top();
            st.pop();
            Rational ans;
            if(ip=="+"){
                ans= a+b;
            }
            else if(ip=="-"){
                ans= a-b;
            }
            else if(ip=="*"){
                ans= a*b;
            }
            else if(ip=="/"){
                ans= a/b;
            }
            std::cout<<ans<<"\n";
            st.push(ans);   
        }
        else{
            //push on stack the number
            std::pair<int,Rational> a=stringToRational(ip);
            if(a.first==1) st.push(a.second);
            else std::cout<<"invalid input \n";
        }
    }
}

std::pair<int,Rational> RPN::stringToRational(std::string &s){
    //check validity of input
    int indexOfSlash=-1;
    bool invalid=false;
    for(int i=0;i<s.size();i++){
        if(!isdigit(s[i]) && s[i]!='/'){
            invalid=true;
            break;
        }
        if(s[i]=='/' && indexOfSlash==-1){
            indexOfSlash=i;
        }
        else if(s[i]=='/' && indexOfSlash!=-1){
            invalid=true;
            break;
        }
    }

    if(invalid){
        return {0,Rational()};
    }
    // std::cout<<"num :"<<s.substr(0,indexOfSlash)<<" ";
    std::pair<int,int>  num=stringToInteger(s.substr(0,indexOfSlash));
    std::pair<int,int> den= (indexOfSlash==-1) ? std::make_pair(1,1) : stringToInteger(s.substr(indexOfSlash+1));

    if(num.first==0 || den.first==0){
        return {0,Rational()};
    }
    return {1,Rational(num.second,den.second)};
}