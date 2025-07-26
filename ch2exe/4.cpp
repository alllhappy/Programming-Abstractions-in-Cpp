/*Write a function windChill that takes the values of t and v and returns the 
wind chill.  In doing so, your function should take account of two special cases: 
• If there is no wind, windChill should return the original temperature t. 
• If the temperature is greater than 40° F, the wind chill is undefined, and 
your function should call error with an appropriate message.
35.74 + 0.6215 t – 35.75 v^0.16 + 0.4275 t v^0.16 
where t is the Fahrenheit temperature and v is the wind speed in miles per hour.
*/

#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include"3.h"

using namespace std;

int windChill(double t, double v); 
void error(string msg);
// commenting since this file is also being used directly in ch4exe qs-2 so for there.
/*
int main() {

    while(true){
     double t;
     cout<<"enter temp in F :";
     cin>>t;
        if(t==-1){
            break;
        }

    double v;
    cout<<"enter wind speed in mph :";
    cin>>v;
    cout<<windChill(t,v)<<endl;
    }
}
    */


int windChill(double t, double v){
    if(v==0){
        return t;
    }
    else if(t>40) {
        error("Temp is greater than 40F");
    }
    else{
        double t1=pow(v,0.16);
        double wf= 35.74 + (0.6215 * t) - 35.75 *t1 +(0.4275*t*t1);
        int rounded=a::roundFloatToInt(wf);
        return rounded;
    }
}

void error(string msg){
    cerr<<msg<<endl;
    exit(EXIT_FAILURE);
}
