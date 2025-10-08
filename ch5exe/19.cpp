/*
Morse code translator in , english to morse code and vice versa
*/
#include<iostream>
#include<string>
#include<unordered_map>
void englishToMorse(std::string &st,std::unordered_map<char,std::string> &mp);
void morseToEnglish(std::string &st,std::unordered_map<std::string,char> &mp);


int main() {
       std::unordered_map<char,std::string> charToCode={
    {'A',".-"},
    {'B',"-..."},
    {'C',"-.-."},
    {'D',"-.."},
    {'E',"."},
    {'F',"..-."},
    {'G',"--."},
    {'H',"...."},
    {'I',".."},
    {'J',".---"},
    {'K',"-.-"},
    {'L',".-.."},
    {'M',"--"},
    {'N',"-."},
    {'O',"---"},
    {'P',".--."},
    {'Q',"--.-"},
    {'R',".-."},
    {'S',"..."},
    {'T',"-"},
    {'U',"..-"},
    {'V',"...-"},
    {'W',".--"},
    {'X',"-..-"},
    {'Y',"-.--"},
    {'Z',"--.."},
};
    std::unordered_map<std::string,char> codeToChar;
    for(auto it=charToCode.begin();it!=charToCode.end();it++){
        char letter=it->first;
        std::string code=it->second;
        codeToChar[code]=letter;
        // std::cout<<code<<":"<<codeToChar[code]<<std::endl;
    }
    std::string currInput="";
    while(true){
        std::cout<<"enter blank to exit : ";
        getline(std::cin,currInput);
        if(currInput=="") break;
        if(isalnum(currInput[0])){
            englishToMorse(currInput,charToCode);
        }
        else{
            morseToEnglish(currInput,codeToChar);
        }
    }
    return 0;
}

void englishToMorse(std::string &currInput,std::unordered_map<char,std::string> &charToCode){
    std::string coding = "";
    for(int i=0;i<currInput.size();i++){
        if(isalpha(currInput[i])){
            std::string encoding= charToCode[toupper(currInput[i])];
            encoding+=" ";
            coding+=encoding;
        }
    }
   std::cout<<coding<<std::endl;
}

void morseToEnglish(std::string &currInput,std::unordered_map<std::string,char> &codeToChar){
    std::string coding = "";
    int i=0;
    std::string currMorse="";
    for(int i=0;i<currInput.size();i++){
        if(currInput[i]!=' ') currMorse.push_back(currInput[i]);
        if(currInput[i]==' ' || i==currInput.size()-1){
            char trans= codeToChar[currMorse];
            coding.push_back(trans);
            currMorse="";
        }
    }
    std::cout<<coding<<std::endl;
}