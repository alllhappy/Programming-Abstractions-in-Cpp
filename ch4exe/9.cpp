/*Write a program 
that asks the user for an input file, an output file, and a string of letters to be 
eliminated.  The program should then copy the input file to the output file, 
deleting any of the letters that appear in the string of censored letters, no 
matter whether they appear in uppercase or lowercase form. */

#include<iostream>
#include<fstream>
#include"input.h"
#include<string>


bool find(char ch,std::string ref);
int main() {
    std::ifstream infile;
    std::ofstream outfile;
    promptUserForFile(infile);
    promptUserForOutFile(outfile);

    // taking input for banned letters
    std::string banned;
    std::cout<<"enter banned letters : ";
    getline(std::cin,banned);
    
    char ch;
    while(infile.get(ch)){
        // ch is in banned string then don't put in outstream
        if(find(ch,banned)) continue;
        outfile.put(ch);
    }


    infile.close();
    outfile.close();
    return 0;
}

bool find(char ch,std::string ref){
    for(int i=0;i<ref.length();i++){
        if(ch==ref[i]) return true;
    }
    return false;
}
