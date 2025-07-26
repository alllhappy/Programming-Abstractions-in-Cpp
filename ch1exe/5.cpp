/*
Write a program that reads in a list of integers from the user until the user 
enters the value 0 as a sentinel.  When the sentinel appears, your program 
should display the largest value in the list, as illustrated in the following sample 
run:
*/

#include<iostream>
#include<limits>
using namespace std;

int main() {
    int max=INT32_MIN ;
    int senitnal =0;
    int curr;
    cout<<"entert 0 to mark the end of list" <<endl;
    while(true){
        cin>>curr;
        if(curr==senitnal){
            
            cout<<"The largest Value is : "<< max ;
            break;
        }
    
        else if(curr>max){
            max=curr;
        }
    }
    return 0;
}