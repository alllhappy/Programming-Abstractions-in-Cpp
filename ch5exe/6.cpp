/*
The circled numbers are the primes; the crossed-out numbers are composites.  
This algorithm is called the sieve of Eratosthenes.
*/
#include<iostream>
#include<vector>


std::vector<int> sieve(int n);
int main() {
    int n=1000;
    std::vector<int> primes=sieve(n);
    for( int i=0 ; i< primes.size(); i++){
       std::cout<< primes[i]<<std::endl;
    }
    return 0;
}

std::vector<int> sieve(int n){
    //n size bool array
    std::vector<bool> isPrime(n,true);
    isPrime[0]=false;
    isPrime[1]=false;
    std::vector<int> primes;
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            primes.push_back(i);
            //now also mark all its multiple as false;
            for(int j=i*i;j<=n;j+=i){isPrime[j]=false;}
        }
    }
    return primes;
}