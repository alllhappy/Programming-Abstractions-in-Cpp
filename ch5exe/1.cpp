/*Write the overloaded functions 
void readVector(istream & is, Vector<int> & vec); 
void readVector(istream & is, Vector<double> & vec); 
void readVector(istream & is, Vector<string> & vec); 
each of which reads lines from the input stream specified by is into the vector 
vec.  In the input stream, each element of the vector appears on a line of its 
own.  The function should read elements until it encounters a blank line or the 
end of the file.*/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"..\ch4exe\input.h"

// command to compile : g++ 1.cpp ..\ch4exe\input.cpp -o 1.exe
void readVector(std::istream & is, std::vector<int> & vec);
void readVector(std::istream & is, std::vector<double> & vec);
void readVector(std::istream & is, std::vector<std::string> & vec);



int main() {
    std::ifstream infile;
    promptUserForFile(infile);
    // line oriented io
    std::vector<double> roots;
    readVector(infile,roots);

    for( int i=0 ; i< roots.size(); i++){
       std::cout<< roots[i]<<" ";
    }
    std::cout<<std::endl;
    readVector(infile,roots);
    for( int i=0 ; i< roots.size(); i++){
       std::cout<< roots[i]<<" ";
    }
    std::cout<<std::endl;
    readVector(infile,roots);
    for( int i=0 ; i< roots.size(); i++){
       std::cout<< roots[i]<<" ";
    }
    return 0;
}

void readVector(std::istream &is, std::vector<int> &vec){
    int x;
    std::string line;
    vec.clear();
    while(getline(is,line)){ // it will automatically detect line to start from in 2nd call as stream is pass by reference
        if(line=="") break;// means blank line, blank line will be stored as empty as, \n is not demiliter and not stores
        x=std::stoi(line);
        vec.push_back(x);
    }
}

void readVector(std::istream &is, std::vector<double> &vec){
    double x;
    std::string line;
    vec.clear();
    while(getline(is,line)){
        if(line=="") break;// means blank line, blank line will be stored as empty as, \n is not demiliter and not stores
        x=std::stod(line);
        vec.push_back(x);
    }
}

void readVector(std::istream &is, std::vector<std::string> &vec){
    std::string line;
    vec.clear();
    while(getline(is,line)){
        if(line=="") break;// means blank line, blank line will be stored as empty as, \n is not demiliter and not stores
        vec.push_back(line);
    }
}