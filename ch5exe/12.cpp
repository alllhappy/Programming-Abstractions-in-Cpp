/*
Write a program that uses a stack to reverse a sequence of integers read from 
the console one number per line
*/

#include<iostream>
#include<stack>

void showStack(std::stack<int> &st);
int main() {
    std::stack<int> st;
    int n;
    while(true){
        std::cin>>n;
        if(n==0) break;
        st.push(n);
    }
    showStack(st);
    return 0;
}

void showStack(std::stack<int> &st){
    while(!st.empty()){
       std::cout<<st.top()<<std::endl;
       st.pop();
    }
}