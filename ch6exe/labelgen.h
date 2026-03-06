#ifndef label_generator
#define label_generator

#include<string>
#include<iostream>
class labelGenerator{

    private:
    std::string prefix;
    int index;

    public:
    //constructors
    labelGenerator(std::string st,int i);

    //method
    std::string nextLabel();
    std::string toString();
};
std::ostream & operator<<(std::ostream &os,labelGenerator l);
#endif