/* Write an iterative implementation of the function fib(n)*/
#include<iostream>

int fib(int n);
int main() {
    int x;
    int sentinal=-1;
    // while(true){
    //     std::cout<<"enter term :";
    //     std::cin>>x;
    //     if(x==sentinal){
    //         break;
    //     }
    // std::cout<<fib(x)<<std::endl;
    // }
    
    // first 100 terms of fib seq
    for(int i=0;i<20;i++){
        std::cout<<fib(i)<<std::endl;
    }
    
    return 0;
}

int fib(int n){
    if(n<=1){
        return n;
    }
    int term=1;
    int prev=0;
    for(int i=2;i<=n;i++){
        int temp=term;
        term+=prev;
        prev=temp;
    }
    return term;
}