/*
Write a program that reads characters from an input file and displays them 
on the console after making the appropriate random substitutions.  Your 
program should replace every uppercase character in the input by a random 
uppercase character and every lowercase character by a random lowercase 
one.  Nonalphabetic characters should remain unchanged.
*/
#include<iostream>
#include<fstream>
#include"input.h"
#include"../daily/random.h" // from chapter 2

// command to compile:  g++ 7.cpp input.cpp ../daily/random.cpp -o 7

int main() {
    std::ifstream infile;
    promptUserForFile(infile);
    char ch;
    while(infile.get(ch)){
        
        if(isalpha(ch)){
            int random=randomInteger(0,25);
            if(isupper(ch)) {
                char sub='A'+random;
                std::cout<<sub;
            }
            else{
                char sub='a'+random;
                std::cout<<sub;
            }
            continue;
        }
        std::cout<<ch;
    }
    
    return 0;
}