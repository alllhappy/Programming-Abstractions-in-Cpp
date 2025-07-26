/*
Using the AddIntegerList program from Figure 1-5 as a model, write a 
program AverageList that reads in a list of integers representing exam scores 
and then prints out the average. Because some unprepared student might 
actually get a score of 0, your program should use !1 as the sentinel to mark the 
end of the input.
*/
#include<iostream>
using namespace std;

int main() {

    int sentinal= -1;
    int curr;
    int sum=0;
    int cnt=0;
    cout<<"entert -1 to mark the end of list" <<endl;
    while(true){
        cin>>curr;
        if(curr == sentinal){
            if(cnt==0){
                // no entry
                cout<< "average : "<<0<<endl;
            }
            else{
                 int average = sum/cnt;
                 cout<< "average : "<<average<<endl;
            }
            break;
        }
        sum+=curr;
        cnt++;
    }
    return 0;
}