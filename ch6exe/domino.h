#ifndef DOMINO_H
#define DOMINO_H

#include<iostream>
#include<string>
class Domino{

    private:
    int left,right;

    
    public:
    //constructors
    Domino();
    Domino(int l,int r);

    //methods
    std::string toString();
    int getLeftDots();
    int getRightDots();

    //we will need the equality operator to check the equality of 2 . in client program we will use this operator to remove the same elements
    //from a all ordered combinations

    

};

std::ostream & operator<<(std::ostream &os,Domino d);
#endif