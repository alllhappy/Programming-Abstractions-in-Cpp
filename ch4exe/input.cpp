#include<iostream>
#include<fstream>
#include"input.h"

//pg 181
void promptUserForFile(std::ifstream &infile){
    while(true){
        std::cout<<"Input file : ";
        std::string fileName;
        getline(std::cin,fileName);
        infile.open(fileName);
        if(!infile.fail()) return ;
        infile.clear();
        std::cout<<"File does not exist"<<std::endl;
    }
}

void promptUserForOutFile(std::ofstream &outfile){
    while(true){
        std::cout<<"Output file : ";
        std::string fileName;
        getline(std::cin,fileName);
        outfile.open(fileName);
        if(!outfile.fail()) return ;
        outfile.clear();
        std::cout<<"file does not exist"<<std::endl;
    }
}