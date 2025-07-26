/* Write a recursive function digitSum(n) that takes a nonnegative integer and 
returns the sum of its digits.  For example, calling digitSum(1729) should 
return 1 + 7 + 2 + 9, which is 19 */
#include<iostream>

int digitSum(int n);
int digitSumHelper(int n ,int &sum);

int main() {
    std::cout<<digitSum(1729);
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