/*
Using the AirportCodes program as a model, write the code necessary to 
read this file into a Map<int,string>, where the key is the area code and the 
value is the location. Once you’ve read in the data, write a main program that 
repeatedly asks the user for an area code and then looks up the corresponding 
location, as illustrated in the following sample run
As the prompt suggests, however, your program should also allow users to 
enter the name of a state or province and have the program list all the area 
codes that serve that area
*/

#include<iostream>
#include<unordered_map>
#include<fstream>
#include<sstream>
#include<set>
#include<string>

std::unordered_map<int,std::string> readFile();
std::unordered_map<std::string,std::set<int>> areaToCode(std::unordered_map<int,std::string> &mp);
int main() {
    std::unordered_map<int,std::string> mp=readFile();
    std::unordered_map<std::string,std::set<int>> mp2=areaToCode(mp);
    std::string currInput="";
    while(true){
        std::cout<<"enter code number ,blank to exit :";
        getline(std::cin,currInput);
        if(currInput=="") break;
        if(isdigit(currInput[0])){
            //its area code so return area name
            std::string code=currInput;
            std::istringstream stream(code);
            int codeI;
            stream>>codeI;
            if(stream.fail() ||!stream.eof()) continue;
            std::cout<<mp[codeI]<<std::endl;
        }
        else{
            //its input is area so list all codes
            if(mp2.find(currInput)!= mp2.end()){
                std::set<int> s=mp2[currInput];
                for(auto it=s.begin();it != s.end();it++){
                    std::cout<< *it<<std::endl;
                }
            }
        }
    }
    return 0;
}

std::unordered_map<int,std::string> readFile(){
    std::ifstream infile;
    infile.open("AreaCodes.txt");
    std::string currLine="";
    std::unordered_map<int,std::string> mp;
    while(getline(infile,currLine)){
        if(currLine[3]=='-'){
            std::string code=currLine.substr(0,3);
            std::istringstream stream(code);
            int codeI;
            stream>>codeI;
            std::cout<<codeI<<std::endl;
            if(stream.fail() ||!stream.eof()) continue;
            std::string area=currLine.substr(4);
            mp[codeI]=area;
        }
    }
    infile.close();
    return mp;
}

std::unordered_map<std::string,std::set<int>> areaToCode(std::unordered_map<int,std::string> &mp){
    std::unordered_map<std::string,std::set<int>> aToC;
    for(auto it=mp.begin();it!=mp.end();it++){
        int code=it->first;
        std::string area=it->second;
        aToC[area].insert(it->first);
    }
    return aToC;
}