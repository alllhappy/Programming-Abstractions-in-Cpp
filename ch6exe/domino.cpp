#include<iostream>
#include"domino.h"

/*implementation file for domino.h*/

//default constructor
Domino :: Domino(){
    left=0;right=0;
}

//2nd constructor
Domino :: Domino(int l,int r){
    left=l;
    right=r;
}

std::string Domino :: toString(){
    return (std::to_string(left)+'-'+std::to_string(right));
}

//getters
int Domino::getLeftDots(){
    return left;
}

int Domino::getRightDots(){
    return right;
}

std::ostream & operator<<(std::ostream &os,Domino d){
    return os<<d.toString();
}


