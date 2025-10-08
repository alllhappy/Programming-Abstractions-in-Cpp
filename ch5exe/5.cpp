/*Extend the flexibility of the previous exercise by defining a hist.h interface 
that gives clients more control over the format of the histogram. At a 
minimum, your interface should allow clients to specify the minimum and 
maximum values along with the size of each histogram range, but you should 
feel free to provide other capabilities as well.  Use your imagination!*/

#include<iostream>
#include<vector>
#include<iomanip>
#include<fstream>
#include"hist.h"

//TODO - check everything. make displaying general
int rangeMax=100;
int rangeMin=0;
int size=10;
void setRange(int min ,int max); //set min and max value for observations
void setSize(int s); // set size for Range of if 0-9 then range is 10
void showHistogram(std::vector<int> &freq); // displays histogram sideways
void showHistogramVertical(std::vector<int> &freq); //show histogram like traditional histogram
std::vector<int> prepareFreq(std::ifstream &infile){
    int n= (rangeMax/size) +1;
   std::vector<int> freq(n);
    int curr;
    while(infile>>curr){
        // std::cout<<curr;
        int rangeIndex=(curr/size); // no need to find the startRange and endRange. we finally want the index to update the value
        freq[rangeIndex]++; 
    }
    return freq;
}
int main() {
    std::ifstream infile;
    infile.open("4_ip.txt");
    setSize(5);
    std::vector<int> freq=prepareFreq(infile);
    showHistogramVertical(freq);
    infile.close();
    return 0;
}

void setSize(int s){
    size=s;
}
void setRange(int min,int max){
    rangeMax=max;
    rangeMin=min;
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
void showHistogramVertical(std::vector<int> &freq){
    int maxPossible=-1;
    for(int i=0;i<freq.size();i++){
        if(maxPossible<freq[i]) maxPossible=freq[i];
    }
    while(maxPossible){
    for(int i=0;i<freq.size();i++){
        if(freq[i]==maxPossible){
            std::cout<<std::left<<"   *  ";
            freq[i]--;
        }
        else{std::cout<<std::left<<"     ";};
    }
    std::cout<<std::endl;
    maxPossible--;
}
int start=0;
for(int i=0;i<freq.size();i++){
    std::cout<<start<<"-"<<start+size<<" ";
    start+=size+1;
}
}