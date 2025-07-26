/*Write a predicate function isPerfect that takes an integer n and returns 
true if n is perfect, and false otherwise.  Test your implementation by 
writing a main program that uses the isPerfect function to check for perfect 
numbers in the range 1 to 9999 by testing each number in turn.  When a perfect 
number is found, your program should display it on the screen.  The first two 
lines of output should be 6 and 28.  Your program should find two other perfect 
numbers in the range as well. */

#include<iostream>
bool isPerfect(int n);

int main() {
    
    for(int i=1; i<10000;i++){
        if(isPerfect(i)){
            std::cout<<i<<std::endl;
        }
    }

    return 0;
}

bool isPerfect(int n){
    int sum=0;
    for(int i=1;i<n;i++){ // division int i=1 as no divison by 0
        int x= n%i;
        if(x==0){
            sum+=i;
        }
    }

    if(sum==n){
        return true;
    }
    return false;
}