#include<iostream>
#include<map>
#include<fstream>

void fillLenghts(std::map<int,int> &mp);
int main() {
    std::map<int,int> lengths;
    fillLenghts(lengths);
    for(auto it=lengths.begin();it!=lengths.end();it++){
        std::cout<<it->first<<" : " <<it->second<<std::endl;
    }
    return 0;
}

void fillLenghts(std::map<int,int> &mp){
    std::ifstream infile;
    infile.open("EnglishWords.txt");
    std::string curr="";
    while(getline(infile,curr)){
        int len=curr.length();
        mp[len]++;
    }
}