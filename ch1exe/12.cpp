/*
Write a program to compute the area of the quarter circle by dividing it into 
10,000 rectangles. 
*/
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    const double radius= 2; // inches
    double area=0;
    const int rectangles=10000;
    const double width = radius/rectangles ;

    // 10000 rectangles
    for(int i=1; i<=rectangles;i++){
        // double x= i*width; 
        double x= (i-0.5)*width;  // 0.5 for midpoint

         double  height = sqrt(radius*radius -x*x);
        //  cout<< height;
         double rectArea = height * width ;
         area += rectArea;
    }

    cout<<"Are of quarter circle is " << area<<endl;
    cout<<"correct ans is"<<3.14*radius*radius/4;


    return 0;
}