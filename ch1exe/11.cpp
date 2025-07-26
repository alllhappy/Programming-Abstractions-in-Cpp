/*
Write a program that calculates an approximation of ! consisting of the first 
10,000 terms in Leibniz’s series. 
*/

#include<iostream>
using namespace std;

int main() {
    long double sum=1;
    for(int i=1 ; i<=10000; i++){
        if(i%2==0){
            sum+= (1.0/(2*i+1));  // concept integer division pg37
            
        }
        else{
            sum-= (1.0/(2*i+1));
        }
        // cout<< sum<<endl;
    }
    double pi = 4*sum;
    cout<< " pi :" << pi;
    return 0;
}