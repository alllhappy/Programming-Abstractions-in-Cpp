/*
• If n is equal to 1, you’ve reached the end of the sequence and can stop. 
• If n is even, divide it by two. 
• If n is odd, multiply it by three and add one. 
Although it also goes by several other names, this sequence is often called the 
hailstone sequence because the values tend to go up and down before coming 
back to 1, much as hailstones do in the clouds in which they form. 
Write a program that reads in a number from the user and then generates the 
hailstone sequence from that point, as in the following sample run: 
*/
#include<iostream>
using namespace std;

int main() {
    cout<<"enter number to generate its hailstone sequence ";
    int x;
    cin>>x;
    while(true){
        if(x==1){
            break;
        }
        else if(x%2==0){
            cout<< x <<" is Even so divide by 2 to get " ;
            x /= 2;
            cout<< x <<endl;
        }
        else{
            cout<< x <<" is Odd so mulitply by 3 and add 1 to get ";
            x *= 3;
            x+= 1;
            cout<< x <<endl;
        }
    }
    return 0;
}