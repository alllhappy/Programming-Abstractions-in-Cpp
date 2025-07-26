/*The numeric columns should all be aligned on the right, and the columns 
containing the trigonometric functions (which are listed here for angles at 
15-degree intervals) should all have seven digits after the decimal point.*/

#include<iostream>
#include<iomanip>
#include<cmath>

// reference program is on pg164
double degreeToRad(double d);
int main() {
    
    // sin takes argument in radians
    // will use defualt format only
    std::cout<<std::setprecision(7);
    std::cout<<std::fixed;
    std::cout<<" theta | sin(theta) | cost(theta) |"<<std::endl;
    std::cout<<"-------+------------+--------------"<<std::endl; // 7dash+12 dash+14dast
    for(int st=0; st<=360; st=st+15){
        // inset spaces to align it within same column
        double radAngle=degreeToRad(st);
        std::cout<<"  "<<std::setw(3)<<st<<"  |"; // max 3 charcter ( - X X) rest for alignment do apply spaces
        std::cout<<" "<<std::setw(10)<<sin(radAngle)<<" |"; // max 10 characters (- x . X X X X X X X)
        std::cout<<" "<<std::setw(10)<<cos(radAngle)<<"  |"<<std::endl; 
    }
    

    return 0;
}
double degreeToRad(double d){
    double mul= M_PI/double(180);
    return mul*d;
}