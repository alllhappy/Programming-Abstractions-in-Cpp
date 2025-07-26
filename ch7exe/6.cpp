/*For each of the two recursive implementations of the function fib(n) 
presented in this chapter, write a recursive function (you can call these 
countFib1 and countFib2 for the two algorithms) that counts the number of 
function calls made during the evaluation of the corresponding Fibonacci 
calculation.  Write a main program that uses these functions to display a table 
showing the number of calls made by each algorithm for various values of n, as 
shown in the following sample run: 
*/

#include<iostream>

int countFib1(int n);
int fib1(int n,int &count);
int countFib2(int n);
int fib2(int n,int &count);
int additiveSequence(int n , int t0 ,int t1,int &count);

int main() {
   std::cout<<"n"<<" "<<"fib1"<<" "<<"fib2"<<std::endl;
   for(int i=0;i<13;i++){
      std::cout<<i<<" "<<countFib1(i)<<" "<<countFib2(i)<<std::endl;
   }
    return 0;
}

int countFib1(int n){
   int cnt=0;
   fib1(n,cnt);
   return cnt;
}
int fib1(int n,int &count){
   count++;
   if(n<2) return n;
   return fib1(n-1,count)+fib1(n-2,count);
}

int countFib2(int n){
   int cnt=1;
   fib2(n,cnt);
   return cnt;
}
int fib2(int n,int &count){
   return additiveSequence(n,0,1,count);
}

int additiveSequence(int n , int t0 ,int t1,int &count){
   count++;
   if (n==0) return t0;
   if(n==1) return t1;
   return additiveSequence(n-1,t1,t0+t1,count);
}