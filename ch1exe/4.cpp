/*
Write a program that reads in a positive integer N and then calculates and 
displays the sum of the first N odd integers.  For example, if N is 4, your 
program should display the value 16, which is 1 + 3 + 5 + 7.
*/
#include<iostream>
using namespace std;
int main() {
    int n;
    cout<<"enter n for first number";
    cin>>n;
    int sum=0;
    int currOdd=1;
    for(int i=0; i<n;i++){
        sum+=currOdd;
        currOdd+=2;
    }

    cout<< sum<<endl;
    return 0;
}