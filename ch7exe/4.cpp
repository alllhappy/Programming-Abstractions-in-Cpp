/*Use Euclid’s insight to write a recursive function gcd(x, y) that computes the 
greatest common divisor of x and y. */
#include<iostream>

int gcd(int x,int y);
int main() {
    int x=gcd(28,16);
    std::cout<<x;
    return 0;
}
int gcd(int x,int y){
    int r= x%y;
    if(r==0){
        return y;
    }
    return gcd(y,r);
}