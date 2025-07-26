/*
Using the digitSum function from the section entitled “The while statement” 
as a model, write a program that reads in an integer and then displays the 
number that has the same digits in the reverse order, as illustrated by this 
sample run: 
*/

#include<iostream>
using namespace std;

int main() {
    int x;
    cout<<"enter a positive integer : ";
    cin>>x;
    int rev=0;
    int digit = x%10;
    x /=10;
    rev +=digit;
    while(x){
        int digit = x%10;
        x /=10;
        rev *=10;
        rev +=digit;
    }
    cout<< "the reversed integer is : "<<rev;
    return 0;
}