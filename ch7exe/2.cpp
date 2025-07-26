/*Unlike many programming languages, C++ does not include a predefined 
operator that raises a number to a power.  As a partial remedy for this 
deficiency, write a recursive implementation of a function 
int raiseToPower(int n, int k)*/
#include<iostream>

int raiseTOPower(int n,int k);
int main() {
    int x=raiseTOPower(2,3);
    std::cout<<x;
    return 0;
}

int raiseTOPower(int n,int k){
    if(k==1){
        return n;
    }
    return n*raiseTOPower(n,k-1);
}