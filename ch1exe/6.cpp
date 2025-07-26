/*
For a slightly more interesting challenge, write a program that finds both the 
largest and the second-largest number in a list, prior to the entry of a sentinel.  
Once again using 0 as the sentinel, a sample run of this program might look like 
this
*/
#include<iostream>
#include<limits>
using namespace std;

int main() {
    int max=INT32_MIN ;
    int secondMax=INT32_MIN;
    int senitnal =0;
    int curr;
    cout<<"entert 0 to mark the end of list" <<endl;
    while(true){
        cin>>curr;
        if(curr==senitnal){
            cout<<"The largest Value is : "<< max <<endl;
            cout<<"The second largest Value is : "<< secondMax ;
            break;
        }
    
        else if(curr>max){
            secondMax=max;
            max=curr;
        }
    }
    return 0;
}