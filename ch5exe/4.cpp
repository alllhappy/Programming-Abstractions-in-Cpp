/*A histogram is a graphical way of displaying data by dividing the data into 
separate ranges and then indicating how many data values fall into each range.  
For example, given the set of exam scores 
Write a program that reads in a vector of integers from a data file and then 
displays a histogram of those numbers, divided into the ranges 0–9, 10–19, 
20–29, and so forth, up to the range containing only the value 100.  Your 
program should generate output that looks as much like the sample run as 
possible
*/

#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include"../ch4exe/input.h"

void showHistogram(std::vector<int> &freq);

//counting the freq of data for the ranges and then display it in the for form of historgram
int main() {
    std::ifstream infile;
    promptUserForFile(infile);
    

    // preparing the freq vector
    int n=11;
    std::vector<int> freq(n);
    int curr;
    while(infile>>curr){
        // std::cout<<curr;
        int rangeIndex=(curr/10); // no need to find the startRange and endRange. we finally want the index to update the value
        freq[rangeIndex]++; 
    }
    
    //displaying the output
    showHistogram(freq);
    return 0;
}

void showHistogram(std::vector<int> &freq){
    //displays histogram sideways
    for(int i=0;i<freq.size();i++){
        std::cout<<std::setw(3)<<i<<"0s: "; //will make them align otherwise 100s is appearing in front
        for(int j=1;j<=freq[i];j++){
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
}