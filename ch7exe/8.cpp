/*Write a function digitalRoot(n) that returns the digital root of its 
argument.  
Although it is easy to implement digitalRoot using the 
digitSum function from exercise 6 and a while loop, part of the challenge of 
this problem is to write the function recursively without using any explicit loop 
constructs. */

#include<iostream>

int digitSum(int n);
int digitSumHelper(int n ,int &sum);
int digitalRootHelper(int n,int &steps);
int digitalRoot(int n);

int main() {

    std::cout<<digitalRoot(20);
    return 0;
}

int digitSum(int n){
    int sum=0;
    digitSumHelper(n,sum);
    return sum; 
}

int digitSumHelper(int n ,int &sum){
    if(n==0) return 0;
    int r = n%10;
    sum+=r;
    digitSumHelper(n/10,sum);
}

int digitalRootHelper(int n,int &steps){
    if(n<=9) return steps;

    int sum=digitSum(n);
    steps++;
    

    
    digitalRootHelper(sum,steps);
}

int digitalRoot(int n){
    int step=0;
    digitalRootHelper(n,step);
    return step;
}