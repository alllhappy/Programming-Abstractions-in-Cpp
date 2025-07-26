/*Write a program that prints the longest line in a file chosen by the user.  If 
several lines are all equally long, your program should print the first such line.*/
#include<iostream>
#include<fstream>
#include"input.h"

// compile using command g++ 3.cpp input.cpp -o 3
int main() {
    std::ifstream infile;
    //ask user for file prompt user for file
    
    promptUserForFile(infile);

    std::string longest="";
    std::string curr;
    while(getline(infile,curr)){
        if(curr.length()>longest.length()) {
            longest=curr;
        }
    }

    std::cout<<longest<<std::endl;

    infile.close();

    return 0;
}


