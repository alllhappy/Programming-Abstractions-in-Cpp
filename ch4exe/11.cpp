/*Using the functions stringToInteger and integerToString as a model, 
write the code necessary to implement stringToReal and realToString. */
#include<iostream>
#include<sstream>
#include<string>
#include"../daily/error.h"

// command to compile:  g++ 11.cpp ../daily/error.cpp -o 11

double stringToReal(std::string str);
std::string realToString(double n);

int main() {
    std::string str="2.344";
    double number=stringToReal(str);
    std::cout<<number+10.00<<std::endl;
    std::string num=realToString(number+10.00);
    std::cout<<num+" hi"<<std::endl;
    return 0;
}
double stringToReal(std::string str){
    std::istringstream stream(str);
    double val;
    stream>>val>>std::ws;
    if(stream.fail() ||!stream.eof()){
        error("Illegal integer format");
    }
    return val;
}
std::string realToString(double n){
    std::ostringstream stream;
    stream<<n;
    return stream.str();
}