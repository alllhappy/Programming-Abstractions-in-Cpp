/*Write a program that reads a file and reports how many lines, words, and 
characters appear in it.  For the purposes of this program, a word consists of a 
consecutive sequence of any characters except whitespace characters.*/
#include<iostream>
#include<fstream>
#include"input.h"


int main() {
    std::ifstream infile;
    promptUserForFile(infile); // from input.h
    //process char by char , if encounter whitespace character then count+=1 and
    // isspace() functions// return true for ' ' , /n and all whitespaces
    //character io
    int wordCount=0;
    int lineCount=0;
    int charCount=0; // also inlcuding spaces as characters
    char ch;
    while(infile.get(ch)){
        charCount++;
        if(isspace(ch)){
            wordCount++;
            if(ch=='\n') lineCount++;
        }
    }
    lineCount++; // as last line will not be counted
    std::cout<<"Chars: "<<charCount<<std::endl;
    std::cout<<"Words: "<<wordCount<<std::endl;
    std::cout<<"Lines: "<<lineCount<<std::endl;
    infile.close();
    return 0;
}