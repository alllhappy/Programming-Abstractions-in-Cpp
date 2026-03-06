#include<iostream>
#include"GRectangle.h"

//command to compile= g++ 3.cpp GRectangle.cpp
int main() {
    Gpoint g= Gpoint(5,6);
    std::cout<<g.toString()<<std::endl;

    Gpoint origin=Gpoint();
    std::cout<<origin.getX()<<std::endl;

    GRectangle rect1= GRectangle(g.getX(),g.getY(),2,3);
    std::cout<<rect1.toString()<<std::endl;

    std::cout<<"contains 0,0 =>"<<rect1.contains(origin)<<std::endl;
    std::cout<<"contains 6,5=>"<<rect1.contains(6,5)<<std::endl;

    return 0;
}