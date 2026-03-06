#include<iostream>
#include"labelgen.h"

labelGenerator::labelGenerator(std::string st,int i){
    prefix=st;
    index=i;
}   

std::string labelGenerator::nextLabel(){
    std::string s=toString();
    index++;
    return s;
}

std::string labelGenerator::toString(){
    return prefix+std::to_string(index);
}

std::ostream& operator<<(std::ostream &os,labelGenerator l){
    return os<<l.toString();
}