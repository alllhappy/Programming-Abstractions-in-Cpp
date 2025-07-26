/*
Every positive integer greater than 1 can be expressed as a product of prime 
numbers.  This factorization is unique and is called the prime factorization.  
For example, the number 60 can be decomposed into the factors 2 x 2 x 3 x 5, 
each of which is prime.  Note that the same prime can appear more than once in 
the factorization. 
Write a program to display the prime factorization of a number n, 
*/

#include<iostream>
#include<string>
using namespace std;

bool isPrime(int x);

int main() {
    int x;
    string ans;
    cout<<"enter  number to be factored : ";
    cin>>x;
    int curr=2;
    int prime=2;
    while(x){
        if(x%prime==0){
            // curr is a prime factor
            cout<<prime<<" x ";
            
            x= x/prime;

        }
        else{
            // change curr to next prime
            curr++;
            // cout<<curr;
            // check is now curr a prime number
            if(isPrime(curr)){
                prime = curr;
            }
            if(curr > x){
                break;
            }


        }
    }
    cout<< ans ;
    return 0;
}

bool isPrime(int x){
    for(int i=2; i<x; i++){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}